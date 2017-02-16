#include "iostream"
#include "EmotionService.h"
#include "GameCapture.h"

using namespace std;
using namespace GameEmoRec;

int main(int argc, char* argv[]) {
    cout<<"Starting Game emotion recognition"<<endl;

    EmotionService* pEmotionService = new EmotionService();
    pEmotionService->start();
    cout<<pEmotionService->toString();
    GameCapture* pGameCapture = new GameCapture("chrome.exe");
}