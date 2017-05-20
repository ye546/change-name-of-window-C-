#include <iostream>
#include <windows.h>
#include <wchar.h>
#include <tchar.h>
#ifdef UNICODE
#define SetWindowText  SetWindowTextW
#else
#define SetWindowText  SetWindowTextA
#endif

//this is a global because I want to std::cout it in the changeWindowName function.
wchar_t *msg = L"hey fam"; //change this to your liking


int changeWindowName(wchar_t *msg = nullptr)
{
    typedef std::basic_string<wchar_t*> wstring;
    HWND steam;
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
                //if we find the window                                 //this needs fixing, only displays hex
                std::cout << "found the window. Its new name is: " << (wstring*)msg << std::endl;
                break;
            }
        }
    }

    SetWindowTextW(steam , msg);//sets the windowname to msg;
    return 1;
}




int main()
{
    changeWindowName(msg);
    //msg = nullptr;
    return 0;
}
