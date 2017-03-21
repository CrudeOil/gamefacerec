#include "cstdio"
#include "cstring"
#include "GameCapture.h"

using namespace std;
using namespace GameEmoRec;

GameCapture::GameCapture(const char* execName) {
    printf("Attempting to find window %s\n", execName);
    pid = this->getProcessID(execName);
    if (pid == 0L) {
        printf("Process not found: %s\n\n", execName);
    }
}

long unsigned int GameCapture::getProcessID(const char* execName) {
    long unsigned int processIds[MAX_PROCESS_ID];
    long unsigned int rn;
    char *pName;

    if (EnumProcesses(processIds, MAX_PROCESS_ID, &rn)) {
        for(int i = 0; i < MAX_PROCESS_ID; i++) {
            pName = this->getProcessName(processIds[i]);
            
            if (strcmp(pName, execName) == 0) {
                printf("Found process %s with pid %lu\n", pName, processIds[i]);
                delete[] pName;
                return processIds[i];
            }
        }
    }
    return 0L;
}

char* GameCapture::getProcessName(long unsigned int processId) {
    char* processName = new char[MAX_PROCESS_NAME_LEN];


    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);

    if (NULL != hProcess) {
        HMODULE hMod;
        DWORD cbNeeded;
        
        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
            GetModuleBaseName(hProcess, hMod, processName, MAX_PROCESS_NAME_LEN);
        }
        CloseHandle(hProcess);

        return processName;
    }else{
        char* ch = new char[10];
        strcpy_s(ch, 10, "<UNKNOWN>");
        return ch;
    }
}