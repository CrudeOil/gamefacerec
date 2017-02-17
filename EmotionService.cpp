#include "cstdio"
#include "queue"
#include "EmotionService.h"

using namespace GameEmoRec;

EmotionService::EmotionService() {
    running = false;
}

void EmotionService::enqueue(short* bitmap) {
    q.push(bitmap);
}

short* EmotionService::dequeue() {
    short* r = q.front();
    q.pop();
    return r;
}

void EmotionService::onResults(double *results)
{
	
}

void EmotionService::setEmotionServiceProvider(EmotionServiceProvider *emotionServicePovider) {
	this->emotionServicePovider = emotionServicePovider;
}

void worker(EmotionService* pEmotionService) {
     short* bitmap;
     while (pEmotionService->isRunning()) {
         bitmap = pEmotionService->dequeue();
     }
	 if (NULL != bitmap) delete bitmap;
}

void EmotionService::start() {
    this->running = true;
}

void EmotionService::stop() {
    this->running = false;
}

char* EmotionService::toString() {
    char* buffer = new char[32];
    sprintf_s(buffer, 32, "Instance of EmotionService. %f bitmaps in queue\n", 0.0);
    return buffer;
}

bool EmotionService::isRunning() {
    return this->running;
}