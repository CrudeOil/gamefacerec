#include "iostream"
#include "GameEmoRec.h"

using namespace std;
using namespace GameEmoRec;

int main(int argc, char* argv[]) {
    cout<<"Starting Game emotion recognition";

    EmotionService* pEmotionService = new EmotionService();
    pEmotionService->setX(123);
    cout<<pEmotionService->toString();
    GameCapture* pGameCapture = new GameCapture();
}