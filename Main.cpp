#include "iostream"
#include "EmotionService.h"
#include "GameCapture.h"

using namespace std;
using namespace GameEmoRec;

int main(int argc, char* argv[]) {
    cout<<"Starting Game emotion recognition";

    EmotionService* emotionService = new EmotionService();
    GameCapture* gameCapture = new GameCapture();
}