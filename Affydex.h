#include "EmotionService.h"
#include "typedefs.h"
#include "AffdexException.h"
#include "Detector.h"
#include "PhotoDetector.h"
#include "Face.h"
#include "FaceListener.h"
#include "ProcessStatusListener.h"

#define MAX_NUM_FACES 1

namespace GameEmoRec {
    class Affydex : public EmotionService {
        private:
			affdex::PhotoDetector detector;
    };
}