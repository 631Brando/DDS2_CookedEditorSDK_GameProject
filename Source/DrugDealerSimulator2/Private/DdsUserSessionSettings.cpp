#include "DdsUserSessionSettings.h"

FDdsUserSessionSettings::FDdsUserSessionSettings() {
    this->NumPublicConnections = 0;
    this->NumPrivateConnections = 0;
    this->bUseLAN = false;
    this->bAllowInvites = false;
    this->bDedicatedServer = false;
    this->bUsePresence = false;
    this->bUseLobbiesIfAvailable = false;
    this->bAllowJoinViaPresence = false;
    this->bAllowJoinViaPresenceFriendsOnly = false;
    this->bAntiCheatProtected = false;
    this->bUsesStats = false;
    this->bShouldAdvertise = false;
    this->bUseLobbiesVoiceChatIfAvailable = false;
    this->bStartAfterCreate = false;
}

