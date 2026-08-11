#include "FGearAeroDynamics.h"

UFGearAeroDynamics::UFGearAeroDynamics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->mDragCoefficient = 0.80f;
    this->mDownForceCoefficient = 0.20f;
    this->mDownForceXOffset = 0.00f;
}

void UFGearAeroDynamics::setDragCoefficient(float F) {
}

void UFGearAeroDynamics::setDownForceXOffset(float F) {
}

void UFGearAeroDynamics::setDownForceCoefficient(float F) {
}

float UFGearAeroDynamics::getDragCoefficient() const {
    return 0.0f;
}

float UFGearAeroDynamics::getDownForceXOffset() const {
    return 0.0f;
}

float UFGearAeroDynamics::getDownForceCoefficient() const {
    return 0.0f;
}


