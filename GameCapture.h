#include "d3d9.h"
#include "windows.h"
#include "d3d9.h"
#include "Psapi.h"

#define MAX_PROCESS_NAME_LEN 64
#define MAX_PROCESS_ID 1024

namespace GameEmoRec {
    class GameCapture {
        int pid;
        public:
            GameCapture(const char*);
            int getProcess(const char*);
            char* getProcessName(long unsigned int);
    };
}