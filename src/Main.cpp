#include "iostream"
#include "EmotionService.h"
#include "GameCapture.h"

using namespace std;
using namespace GameEmoRec;

int main(int argc, char* argv[]) {
    char* procname = new char[64];

    cout<<"Starting Game emotion recognition"<<endl;
    cout<<"Enter process name:"<<endl;
    cout<<"> ";
    cin>>procname;
    cout<<endl;

    GameCapture* pGameCapture = new GameCapture(procname);
    EmotionService* pEmotionService = new EmotionService();
    pEmotionService->start();
    delete pGameCapture;
    delete pEmotionService;
	system("pause");
}