
#include<iostream>
#include<intrin.h>
#include<fstream>
#include<string>

#include"getProcessorID.hh"
#include"xorstr.hh"

std::string getProcessorID(const char* filename) {
    int cpu_info[4] = { 0 };
    __cpuid(cpu_info, 1);
    char cpu_id_str[17] = { 0 };
    sprintf_s(cpu_id_str, xorstr("%08X%08X"), cpu_info[3], cpu_info[0]);
    std::ofstream outfile(filename, std::ios::out | std::ios::app); // append data to file
    if (!outfile) {
        throw std::runtime_error(xorstr("error code: 3.11"));
    }
    outfile << xorstr("processor iD: ") << cpu_id_str << std::endl;
    outfile.close();

    return cpu_id_str;
}