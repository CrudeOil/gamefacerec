#include "queue"
#include "atomic"

namespace GameEmoRec {
	struct EmotionServiceProvider {
		void onResults();
	};
    class EmotionService {
        protected:
            std::atomic<bool> running;
            std::queue<short*> q;
			void* emotionServicePovider;
        public:
            EmotionService();
            void enqueue(short*);
            short* dequeue();
            void onResults(double*);
            void setEmotionServiceProvider(EmotionServiceProvider*);
            void worker();
            void start();
            void stop();
            char* toString();
            bool isRunning();
    };
}