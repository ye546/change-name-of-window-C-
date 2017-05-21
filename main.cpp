#include <iostream>
#include <windows.h>
#include <cstdio>
#include <tchar.h>
#include <cstring>

int changeWindowName(const char* msg)
{
    HWND steam;
                                    //any window name here, it's case sensitive and needs to be precise.
    steam = FindWindow(nullptr, _T("LtdBoomer™ - Chat"));//checks if chat is open with boomer

    if(!steam)//if window not found, keep checking until it opens.
    {
        printf("could not find steam window\n");
        while(!steam)
        {                                   //any window name here, it's case sensitive and needs to be precise.
            steam = FindWindow(nullptr, _T("LtdBoomer™ - Chat"));//checks if chat is open with boomer
            if(steam)//window found
            {
                printf("found the window. Its new name is: ");
                printf("%s", msg);
                printf("\n");
                break;
            }
        }
    }

    SetWindowTextA(steam , msg);//sets the windowname to msg;
    msg = nullptr;
    return 1;
}




int main()
{
    printf("name the application to your liking: ");
    std::string text; getline(std::cin,text);

    changeWindowName(text.c_str());
    //message = nullptr;
    return 0;
}
