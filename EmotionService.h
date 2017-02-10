#include "cstdio"

namespace GameEmoRec {
    class EmotionService {
        int x;
        public:
            EmotionService() {
                x = 0;
            }

            void setX(int newx) {
                this->x = newx;
            }

            char* toString() {
                char* buffer = new char[32];
                sprintf(buffer, "%d", this->x);
                return buffer;
            }
        
    };
}