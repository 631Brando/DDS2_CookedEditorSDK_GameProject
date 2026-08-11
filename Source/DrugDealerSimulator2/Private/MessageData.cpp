#include "MessageData.h"

FMessageData::FMessageData() {
    this->MessageSound = NULL;
    this->RewardRule = EMessageRewardRule::OnAccept;
    this->CanDecline = false;
}

