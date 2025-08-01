#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
#include "Assets.h"
#include "Application.h"
#include "Server.h"
#include "AssetController.h"
#include "../TeamProperties/Infrastructure.h"
#include "../TeamProperties/Analytics.h"
#include "../TeamProperties/Cybersecurity.h"
#include "../TeamProperties/Engineering.h"
#include "../TeamProperties/Support.h"
#ifndef ASSETREMOVE_H
#define ASSETREMOVE_H

class AssetRemove {
private:
  static bool handleMoveApplicationsAndDeleteServer;
  static bool handleDeleteServerAndApplications;
  static void updateTeamFile(const string& teamName);
  static bool deleteApplicationFromTeam;
public:
  static vector<shared_ptr<Application>> findAppOnServer(const vector<shared_ptr<Application>>& appObjectVec, const string& serverName);
  static vector<pair<shared_ptr<Application>, string>> findAllApplicationsOnServer(const string& serverName);
  static bool removeApplication(vector<shared_ptr<Application>>& teamAppVec, const string& appName, const string& txtFileName);
  static bool removeServer(const string& serverName);

};



#endif //ASSETREMOVE_H
