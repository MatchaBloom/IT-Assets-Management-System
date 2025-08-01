#ifndef TEAMCONTROLLER_H
#define TEAMCONTROLLER_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "ITeamAssetProvider.h"
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
#include "../Assets/Application.h"
#include "../Assets/AssetController.h"
#include "../Assets/AssetManager.h"


class TeamController {
public:
  TeamController();
  ~TeamController();

  //the function that has ITeamAssetProvider* teamProvider, basically will take
  static void addAsset(const string& assetMaker, ITeamAssetProvider* teamProvider);
  static void serverUpdateMenu();
  static void applicationUpdateMenu(ITeamAssetProvider* teamProvider);
  static void updateTeamMenu(const string& assetMaker, ITeamAssetProvider* teamProvider);
};



#endif //TEAMCONTROLLER_H
