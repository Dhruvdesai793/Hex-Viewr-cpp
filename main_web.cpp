#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <emscripten/emscripten.h>

const int BYTES_PER_LINE = 16;
const int LINES_PER_PAGE = 20;
const int BYTES_PER_PAGE = BYTES_PER_LINE * LINES_PER_PAGE;

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

extern "C" {
EMSCRIPTEN_KEEPALIVE
void processFileForHexView(const char* fileData, int fileSize, const char* fileName) {
    EM_ASM({
        console.clear();
    });

    std::cout << "--- Hex View of '" << fileName << "' (Size: " << fileSize << " bytes) ---" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    std::vector<char> buffer(BYTES_PER_LINE);
    long long currentOffset = 0;

    for (int i = 0; i < fileSize; i += BYTES_PER_LINE) {
        std::streamsize bytesToRead = BYTES_PER_LINE;
        if (i + bytesToRead > fileSize) {
            bytesToRead = fileSize - i;
        }

        std::copy(fileData + i, fileData + i + bytesToRead, buffer.begin());

        printHexAndAscii(buffer, bytesToRead, currentOffset);
        currentOffset += bytesToRead;

        std::fill(buffer.begin(), buffer.end(), 0);
    }

    std::cout << "--- End of File ---" << std::endl;
}

}

int main() {
    std::cout << "C++ WebAssembly Hex Viewer module loaded. Waiting for file input..." << std::endl;
    return 0;
}
