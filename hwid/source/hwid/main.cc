// basic windows includes
#include <windows.h>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <vector>

// hwid modules
#include "getMotherboardSerial.hh"
#include "getUSNJournalIDs.hh"
#include "getComputerUUID.hh"
#include "getProcessorID.hh"
#include "getHDDSerial.hh"
#include "getBootUUID.hh"

// security 
#include "xorstr.hh"

const int kSuccess = 0;
const int kError = 1;

int main(int argc, char* argv[]) {
    const char* filename = xorstr("hwid.txt");

    if (std::filesystem::exists(filename)) {
        std::cout << xorstr("output file already exists. do you want to overwrite it? (y/n): ");
        char choice;
        std::cin >> choice;

        if (tolower(choice) != 'y') {
            return kSuccess;
        }
    }

    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);

    if (!outFile) {
        std::cerr << xorstr("unable to open output file: ") << filename << std::endl;
        return kError;
    }

    std::vector<std::pair<std::string, std::string>> hwidResults;

    hwidResults.push_back({ xorstr("hard drive serial number(s)"), getAllHDDSerials() });
    hwidResults.push_back({ xorstr("motherboard serial number"), getMotherboardSerial(filename) });
    hwidResults.push_back({ xorstr("compiter uuid"), getComputerUUID(filename) });
    hwidResults.push_back({ xorstr("processor iD"), getProcessorID(filename) });
    hwidResults.push_back({ xorstr("boot uuid"), getBootUUID(filename) });

    for (const auto& result : hwidResults) {
        outFile << result.first << xorstr(": ") << result.second << std::endl;
    }

    return kSuccess;
}