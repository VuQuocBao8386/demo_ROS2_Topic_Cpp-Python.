#ifndef SERIAL_UART_HPP
#define SERIAL_UART_HPP

#pragma once
#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <cstring>   // for memset

class serial_UART
{
private:
    int fd = -1;

public:
    serial_UART(const char* port, speed_t baud = B115200)
    {
        fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
        if (fd < 0) {
            std::cerr << "Failed to open port: " << port << std::endl;
            return;
        }

        termios tty{};
        if (tcgetattr(fd, &tty) != 0) {
            std::cerr << "Error getting attributes" << std::endl;
            close(fd);
            fd = -1;
            return;
        }

        cfsetospeed(&tty, baud);
        cfsetispeed(&tty, baud);

        tty.c_cflag |= (CLOCAL | CREAD);
        tty.c_cflag &= ~CSIZE;
        tty.c_cflag |= CS8;      // 8 data bits
        tty.c_cflag &= ~PARENB;  // no parity
        tty.c_cflag &= ~CSTOPB;  // 1 stop bit

        tty.c_iflag = IGNPAR;
        tty.c_oflag = 0;
        tty.c_lflag = 0;

        tcflush(fd, TCIFLUSH);
        if (tcsetattr(fd, TCSANOW, &tty) != 0) {
            std::cerr << "Error setting attributes" << std::endl;
            close(fd);
            fd = -1;
        }
    }

    ~serial_UART() {
        shutdown_Serial();
    }

    bool isOpen() const {
        return fd >= 0;
    }

    
    bool transmit_Serial(const std::string& data);
    bool transmit_Serial(char c);
    int recieve_Serial(char& outChar);
    bool checking_Serial();
    void shutdown_Serial();
};

#endif
