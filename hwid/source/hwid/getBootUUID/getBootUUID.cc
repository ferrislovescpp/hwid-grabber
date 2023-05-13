
#include <Wbemidl.h>
#include <iostream>
#include <comdef.h>
#include <fstream>

#include "xorstr.hh"
#include "getBootUUID.hh"

#pragma comment(lib, "wbemuuid.lib")

std::string getBootUUID(const char* filename) {
    HRESULT hres;

    // initialize COM
    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.11 - contact staff") << std::endl; // failed to initialize COM library
        return "";
    }

    // initialize security to default values
    hres = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_CONNECT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE,
        NULL
    );
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.22 - contact staff") << std::endl; // failed to initialize security
        CoUninitialize();
        return "";
    }

    // obtain the initial locator to the WMI object
    IWbemLocator* pLoc = NULL;
    hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator,
        (LPVOID*)&pLoc
    );
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.33 - contact staff") << std::endl; // failed to create IWbemLocator object
        CoUninitialize();
        return "";
    }

    // connect to the root\cimv2 namespace with the current user and obtain pointer to the WMI object
    IWbemServices* pSvc = NULL;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),
        NULL,
        NULL,
        0,
        NULL,
        0,
        0,
        &pSvc
    );
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.44 - contact staff") << std::endl; // failed to connect to WMI namespace
        pLoc->Release();
        CoUninitialize();
        return "";
    }

    // set the security levels on the proxy
    hres = CoSetProxyBlanket(
        pSvc,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        NULL,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE
    );
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.55 - contact staff") << std::endl; // failed to set proxy blanket
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return "";
    }

    // execute the query to obtain the UUID
    IEnumWbemClassObject* pEnumerator = NULL;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT UUID FROM Win32_ComputerSystemProduct"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumerator
    );
    if (FAILED(hres)) {
        std::cout << xorstr("error code: 6.66 - contact staff") << std::endl; // failed to execute query
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return "";
    }

    // retrieve the UUID from the query result
    IWbemClassObject* pclsObj = NULL;
    ULONG uReturn = 0;
    std::string uuid = "";
    while (pEnumerator) {
        hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
        if (uReturn == 0) {
            break;
        }

        VARIANT vtProp;
        hres = pclsObj->Get(xorstr(L"UUID"), 0, &vtProp, 0, 0);
        if (SUCCEEDED(hres)) {
            uuid = _bstr_t(vtProp.bstrVal, true);
            VariantClear(&vtProp);
        }

        pclsObj->Release();
    }

    // cleanup
    pEnumerator->Release();
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    return uuid;
}