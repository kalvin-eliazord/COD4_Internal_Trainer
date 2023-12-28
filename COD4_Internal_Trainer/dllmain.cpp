#include "header.h"

DWORD WINAPI HackThread(HMODULE hModule)
{
    // setting console 
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);

    uintptr_t modBaseAddr{ (uintptr_t)GetModuleHandleW(0)};

    while (!GetAsyncKeyState(VK_DELETE) & 1)
    {
        Sleep(5);
    }
        *pitchPtr = 85.0f;

    if (f)
        fclose(f);

    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        HANDLE hThread{ CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)HackThread, hModule, NULL, nullptr) };
        
        if (hThread)
            CloseHandle(hThread);
    }
    return TRUE;
}

