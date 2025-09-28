#include "serial_UART.hpp"

// send vector<int> as comma-separated string
bool serial_UART::transmit_Vector(const std::vector<int>& data) {
    if (fd < 0) return false;

    std::ostringstream oss;
    for (size_t i = 0; i < data.size(); ++i) {
        oss << data[i];
        if (i != data.size() - 1) oss << ",";
    }
    oss << "\n";

    std::string s = oss.str();
    ssize_t written = write(fd, s.c_str(), s.size());
    return (written == (ssize_t)s.size());
}


// send single char
bool serial_UART::transmit_Serial(char c) {
    if (fd < 0) return false;
    ssize_t written = write(fd, &c, 1);
    return (written == 1);
}


// receive string (non-blocking)
std::string serial_UART::recieve_Serial() {
    if (fd < 0) return "";

    char buffer[64] = {0};
    int n = read(fd, buffer, sizeof(buffer)-1);
    if (n > 0) {
        return std::string(buffer, n);
    }
    return "";
}


// handshake check
bool serial_UART::checking_Serial() {
    if (!isOpen()) return false;

    if (!transmit_Serial('S')) {
        std::cerr << "Failed to send handshake" << std::endl;
        return false;
    }

    for (int i = 0; i < 20; i++) {   // try for ~2 sec
        std::string res = recieve_Serial();
        if (!res.empty()) {
            if (res.find('D') != std::string::npos) {
                std::cout << "✅ Connect to MCU successful!" << std::endl;
                return true;
            } else {
                std::cout << "⚠️ Unexpected response: " << res << std::endl;
            }
        }
        usleep(100000); // 100 ms
    }

    std::cerr << "❌ No response from MCU." << std::endl;
    return false;
}


void serial_UART::shutdown_Serial() {
    if (fd >= 0) {
        close(fd);
        fd = -1;
    }
}