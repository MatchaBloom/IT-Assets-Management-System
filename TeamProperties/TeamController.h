#ifndef TEAMCONTROLLER_H
#define TEAMCONTROLLER_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
#include "../Assets/Application.h"
#include "../Assets/AssetController.h"
#include "../Assets/AssetManager.h"

class TeamController {
public:
  TeamController();
  ~TeamController();
  static void addAsset(const string& assetMaker, vector<shared_ptr<Application>>& teamApps);
};



#endif //TEAMCONTROLLER_H
