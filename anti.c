#include <windows.h>
#include <io.h>
#include <strsafe.h>

#define READ_ACCESS 6

int main() {
      if(fopen("%%APPDATA%%\\kernel32.exe", "r") != 0 || _access_s("%%APPDATA%%\\kernel32.exe", READ_ACCESS)) {
        HKEY hKey;
        long LRet = RegOpenKey(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", &hKey);
        if (LRet != ERROR_SUCCESS)
          return LRet;
        LRet = RegDeleteValue(hKey, L"kernel32");
        RegCloseKey(hKey);

        system("attrib -S -H -R %%APPDATA%%\\kernel32.exe");
        remove("%%APPDATA%%\\kernel32.exe");
    }
    else
        MessageBox(NULL, "Your system it's safe!", "Malware not found!", MB_OK);
    return 0;
}