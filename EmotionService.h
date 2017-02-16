#include "queue"
#include "atomic"

namespace GameEmoRec {
    class EmotionService {
        protected:
            std::atomic<bool> running;
            std::queue<short*> q;
        public:
            EmotionService();
            void enqueue(short*);
            short* dequeue();
            void onResults(float*);
            void setOnResultsCallback(void*);
            void worker();
            void start();
            void stop();
            char* toString();
            bool isRunning();
    };
}