
#include <windows.h>
#include <iostream>
#include <string>
#include <Rpc.h>

#include "xorstr.hh"

#pragma comment(lib, "Rpcrt4.lib")

std::string getMotherboardSerial(const char* filename) {
    std::string uuid;

    // get the system UUID
    UUID sysUUID;
    if (UuidCreateSequential(&sysUUID) == RPC_S_OK)
    {
        RPC_CSTR strUUID = NULL;
        if (UuidToStringA(&sysUUID, &strUUID) == RPC_S_OK)
        {
            uuid = std::string(reinterpret_cast<char*>(strUUID));
            RpcStringFreeA(&strUUID);
        }
        else
        {
            std::cerr << xorstr("error code: 1.11 - contact staff") << std::endl; //  failed to convert motherboard serial number to string
        }
    }
    else
    {
        std::cerr << xorstr("error code: 1.22 - contact staff") << std::endl; // failed to create system uuid
    }

    return uuid;
}