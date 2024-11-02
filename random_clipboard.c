
#include <Windows.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OUTPUT_LENGTH 16



void rand_str(char* dest, size_t length) {
    char charset[] = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "-_";
    
    while (length-- > 0) {

        
        size_t index = rand() %  (sizeof(charset) -1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}


int main()
{
    
    FILETIME ft;
    ULARGE_INTEGER ui;
    GetSystemTimePreciseAsFileTime(&ft);
    ui.LowPart = ft.dwLowDateTime;
    ui.HighPart = ft.dwHighDateTime;
    unsigned long long micros = ui.QuadPart / 10;
    srand((unsigned int) (micros & 0xFFFFFFFF));

    char random_string[OUTPUT_LENGTH +1] = { [OUTPUT_LENGTH] = '\1' }; // make the last character non-zero so we can test based on it later
    rand_str(random_string, sizeof random_string - 1);
    assert(random_string[OUTPUT_LENGTH] == '\0');      // test the correct insertion of string terminator


    const size_t random_string_len = strlen(random_string) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, random_string_len);

    if (hMem == NULL)
    {
        fprintf(stderr, "GlobalAlloc failed \n");
        return 1;
    }


    char* memPtr = (char*)GlobalLock(hMem);

    if (memPtr != NULL) {
        memcpy(memPtr, random_string, random_string_len);
    }
    else {
        fprintf(stderr, "GlobalLock failed\n");
        GlobalFree(hMem); // Free allocated memory on failure 
        return 1;

    }


    
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

}