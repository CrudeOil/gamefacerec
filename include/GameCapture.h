#include "d3d9.h"
#include "windows.h"
#include "d3d9.h"
#include "Psapi.h"

#define MAX_PROCESS_NAME_LEN 64
#define MAX_PROCESS_ID 1024

namespace GameEmoRec {
    class GameCapture {
        public:
            // TODO: make private
            long unsigned int pid;
            
            GameCapture(const char*);
            long unsigned int getProcessID(const char*);
            char* getProcessName(long unsigned int);
    };
}