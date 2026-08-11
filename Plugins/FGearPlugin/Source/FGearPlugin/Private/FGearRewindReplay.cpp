#include "FGearRewindReplay.h"

AFGearRewindReplay::AFGearRewindReplay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mStateSize = 100;
    this->mRewindPause = true;
    this->mReplayPause = true;
}

void AFGearRewindReplay::setReplayFrames(int32 Count) {
}

void AFGearRewindReplay::Rewind(bool resetIndex) {
}

void AFGearRewindReplay::replay(bool resetIndex) {
}

void AFGearRewindReplay::Play() {
}

FGearRewindReplayState AFGearRewindReplay::GetState() {
    return FGearRewindReplayState::RS_PLAY;
}

float AFGearRewindReplay::getProgressValue() const {
    return 0.0f;
}


