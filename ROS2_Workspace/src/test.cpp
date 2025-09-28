#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>

int main() {
    const char *portname = "/dev/ttyUSB0";
    
    // Check if port exists first
    if (access(portname, F_OK) == -1) {
        std::cerr << "Port " << portname << " does not exist!" << std::endl;
        std::cerr << "Available ports: " << std::endl;
        system("ls /dev/ttyUSB* 2>/dev/null || echo 'No USB serial ports found'");
        system("ls /dev/ttyACM* 2>/dev/null || echo 'No ACM serial ports found'");
        return 1;
    }
    
    // Check permissions
    if (access(portname, R_OK | W_OK) == -1) {
        std::cerr << "No permission to access " << portname << std::endl;
        std::cerr << "Try: sudo chmod 666 " << portname << std::endl;
        std::cerr << "Or add your user to dialout group: sudo usermod -a -G dialout $USER" << std::endl;
        return 1;
    }

    std::cout << "Opening " << portname << "..." << std::endl;
    int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);

    if (fd < 0) {
        std::cerr << "Error opening " << portname << ": " << strerror(errno) << std::endl;
        return 1;
    }
    std::cout << "Port opened successfully!" << std::endl;

    // Configure serial
    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    
    if (tcgetattr(fd, &tty) != 0) {
        std::cerr << "Error from tcgetattr: " << strerror(errno) << std::endl;
        close(fd);
        return 1;
    }

    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_cflag |= (CLOCAL | CREAD);                // ignore modem controls, enable reading
    tty.c_cflag &= ~PARENB;                         // no parity
    tty.c_cflag &= ~CSTOPB;                         // one stop bit
    tty.c_cflag &= ~CRTSCTS;                        // no hardware flow control

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);         // shut off xon/xoff ctrl
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);

    tty.c_lflag = 0;                                // no signaling chars, no echo
    tty.c_oflag = 0;                                // no remapping, no delays

    tty.c_cc[VMIN]  = 1;                            // read blocks until 1 char
    tty.c_cc[VTIME] = 10;                           // 1.0s read timeout

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        std::cerr << "Error from tcsetattr: " << strerror(errno) << std::endl;
        close(fd);
        return 1;
    }

    std::cout << "Serial port configured. Waiting for data..." << std::endl;

    // Clear any existing data
    tcflush(fd, TCIOFLUSH);

    char buf[256];
    while (true) {
        int n = read(fd, buf, sizeof(buf) - 1);
        if (n > 0) {
            buf[n] = '\0';
            std::cout << "Received: " << buf;
        } else if (n == 0) {
            std::cout << "No data received (timeout)" << std::endl;
            usleep(100000); // wait 100ms
        } else {
            std::cerr << "Read error: " << strerror(errno) << std::endl;
            break;
        }
    }

    close(fd);
    return 0;
}