
#include <windows.h>
#include <stdexcept>
#include <iostream>
#include <Rpc.h>

#include "xorstr.hh"
#include "getComputerUUID.hh"

#pragma comment(lib, "Rpcrt4.lib")

std::string getComputerUUID(const char* filename) {
    UUID uuid;
    RPC_STATUS status = UuidCreate(&uuid);
    if (status != RPC_S_OK && status != RPC_S_UUID_LOCAL_ONLY) {
        throw std::runtime_error(xorstr("failed to retrieve computer UUID."));
    }
    unsigned char* uuid_str;
    status = UuidToStringA(&uuid, &uuid_str);
    if (status != RPC_S_OK) {
        throw std::runtime_error(xorstr("failed to convert UUID to string."));
    }
    std::string uuid_str_std = std::string(reinterpret_cast<char*>(uuid_str));
    RpcStringFreeA(&uuid_str);
    return uuid_str_std;
}