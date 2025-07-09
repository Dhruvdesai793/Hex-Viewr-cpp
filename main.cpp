#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>

const int BYTES_PER_LINE = 16;

void printHexAndAscii(const std::vector<char>& buffer, std::streamsize bytesRead, long long currentAddress) {
    std::cout << std::hex << std::setw(8) << std::setfill('0') << currentAddress << "  ";

    for (int i = 0; i < BYTES_PER_LINE; i++) {
        if (i< bytesRead) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)buffer[i] << " ";
        } else {
            std::cout << "  ";
        }

        if (i == BYTES_PER_LINE / 2 - 1) {
            std::cout << " ";
        }
    }

    std::cout << " |";

    for (int i=0; i < bytesRead; i++) {
        char byte = buffer[i];
        if (std::isprint(static_cast<unsigned char>(byte))) {
            std::cout << byte;
        } else {
            std::cout << ".";
        }
    }
    std::cout << "|" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filepath>" << std::endl;
    }
    std::string filePath = argv[1];
    std::ifstream file(filePath,std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file '" << filePath << "'" << std::endl;
        return 1;
    }
    std::vector<char> buffer(BYTES_PER_LINE);
    long long currentAddress = 0;

    while (file.read(buffer.data(), BYTES_PER_LINE) || file.gcount() > 0) {
        std::streamsize bytesRead = file.gcount();

        if (bytesRead == 0 && file.eof()) {
            break;
        }
        if (bytesRead == 0 && file.fail() && !file.eof()) {
            std::cerr << "Error: Failed to read from file." << std::endl;
            break;
        }

        printHexAndAscii(buffer, bytesRead,currentAddress);

        currentAddress += bytesRead;
        std::fill(buffer.begin(), buffer.end() , 0);
    }
    file.close();
    return 0;
}
