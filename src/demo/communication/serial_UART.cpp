#include "serial_UART.hpp"



bool serial_UART::transmit_Serial(const std::string& data) {
    if (fd < 0) return false;
    ssize_t written = write(fd, data.c_str(), data.size());
    return (written == (ssize_t)data.size());
}


bool serial_UART::transmit_Serial(char c) {
    if (fd < 0) return false;
    ssize_t written = write(fd, &c, 1);
    return (written == 1);
}


int serial_UART::recieve_Serial(char& outChar) {
    if (fd < 0) return -1;
    char buffer;
    int n = read(fd, &buffer, 1);
    if (n > 0) {
        outChar = buffer;
        return 1; // success
    }
    return 0; // no data
}


bool serial_UART::checking_Serial() {
    if (!isOpen()) return false;    // Try handshake: send 'S', wait for response
    
    if (!transmit_Serial('S')) {
        return false;
    } 
    
    char received;
    for (int i = 0; i < 10; i++) {  // try max 10 times
        int res = recieve_Serial(received);
        if (res > 0 && received == 'D') {
            std::cout << "Connect to MCU successful....!" << std::endl;
            return true;
        }
        usleep(100000); // wait 100ms
    }    
    
    std::cerr << "No response from MCU." << std::endl;
    return false;
}


void serial_UART::shutdown_Serial() {
    if (fd >= 0) {
        close(fd);
        fd = -1;
    }
}