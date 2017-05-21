#include <iostream>
#include <windows.h>
#include <cstdio>
#include <tchar.h>
#include <cstring>

int changeWindowName(LPCSTR msg)
{
    HWND steam;
    //char *msg = "hey fam"; //change this to your liking

                                    //any window name here, it's case sensitive and needs to be precise.
    steam = FindWindow(nullptr, _T("LtdBoomer™ - Chat"));//checks if chat is open with boomer

    if(!steam)//if window not found, keep checking until it opens.
    {
        std::cout << "could not find steam window\n";
        while(!steam)
        {                                   //any window name here, it's case sensitive and needs to be precise.
            steam = FindWindow(nullptr, _T("LtdBoomer™ - Chat"));//checks if chat is open with boomer
            if(steam)
            {
                //if we find the window
               printf("found the window. Its new name is: ");
               for(int i = 0; i < strlen(msg); i++)
               {
                   printf("msg");
               }
                break;
            }
        }
    }

    SetWindowTextA(steam , msg);//sets the windowname to msg;
    return 1;
}




int main()
{
    printf("name the application to your liking: ");
    char* message = nullptr;
    std::string text; std::cin >>text;

    strcpy(message, text.c_str());

    changeWindowName(message);
    //msg = nullptr;
    return 0;
}
