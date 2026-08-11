#include "FGearSettings.h"

UFGearSettings::UFGearSettings() {
    this->mEnabled = true;
    this->mServerAuthority = true;
    this->mInputSendRate = 20;
    this->mStateSendRate = 20;
    this->mMinCollisionBlendSpeed = 10.00f;
    this->mForceSnapDistance = 15.00f;
}


