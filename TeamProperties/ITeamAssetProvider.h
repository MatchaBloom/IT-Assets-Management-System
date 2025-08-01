#ifndef ITEAMASSETPROVIDER_H
#define ITEAMASSETPROVIDER_H
#include <algorithm>
#include <iostream>
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
#include "../Assets/Application.h"

// Abstract interface that each team must implement
class ITeamAssetProvider {
public:
    virtual ~ITeamAssetProvider() = default;
    virtual vector<shared_ptr<Application>>& getTeamApps() = 0;
    virtual const string& getTeamFileName() = 0;
    virtual const string& getTeamName() = 0;
    virtual bool canRemoveServer() = 0;
    virtual bool canRemoveApplication() = 0;
};


#endif //ITEAMASSETPROVIDER_H
