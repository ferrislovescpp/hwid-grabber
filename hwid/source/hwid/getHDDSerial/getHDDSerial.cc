
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "xorstr.hh"
#include "gethddserial.hh"

#pragma comment(lib, "Kernel32.lib")

std::string getHDDSerial(const char* drive) {
    DWORD VSN[4];
    char vol_name[MAX_PATH + 1] = { 0 };
    std::string serial_str;

    // get the volume name of the given drive
    if (!GetVolumeInformationA(drive, vol_name, ARRAYSIZE(vol_name), VSN, 0, 0, 0, 0))
    {
        std::cout << xorstr("error getting volume information for drive ") << drive << std::endl;
        return "";
    }

    // convert the volume serial number to a string
    std::ostringstream oss;
    oss << std::hex << std::uppercase << VSN[1] << VSN[0];
    serial_str = oss.str();

    return serial_str;
}

std::string getAllHDDSerials() {
    DWORD drivesBitMask = GetLogicalDrives();
    char driveLetter = 'A';
    std::string serials;

    while (drivesBitMask) {
        // check if the drive is a fixed drive
        if (drivesBitMask & 1) {
            char drive[4];
            sprintf_s(drive, xorstr("%c:\\"), driveLetter);
            std::string hddSerial = getHDDSerial(drive);
            if (!hddSerial.empty()) {
                // add the hard drive serial number to the list
                if (serials.length() > 0) {
                    serials += ",";
                }
                serials += hddSerial;
            }
        }
        drivesBitMask >>= 1;
        ++driveLetter;
    }

    return serials;
}