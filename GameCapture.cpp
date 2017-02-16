#include "cstdio"
#include "GameCapture.h"

using namespace std;
using namespace GameEmoRec;

GameCapture::GameCapture(const char* execName) {
    printf("Attempting to find window %s\n", execName);
    this->getProcess(execName);
}

GameCapture::getProcess(const char* execName) {
    long unsigned int processIds[MAX_PROCESS_ID];
    long unsigned int rn;
    char *pName;

    if (EnumProcesses(processIds, MAX_PROCESS_ID, &rn)) {
        for(int i = 0; i < MAX_PROCESS_ID; i++) {
            pName = this->getProcessName(processIds[i]);
            if (pName == execName) {
                printf("Found process %s with pid %d\n", pName, processIds[i]);
                delete[] pName;
            }
        }
    }
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
        char* ch = new char[10] /* 11 = len of Hello Heap + 1 char for \0*/;
        strcpy(ch, "<UNKNOWN>");
        return ch;
    }
}