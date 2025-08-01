#ifndef ASSETUPDATE_H
#define ASSETUPDATE_H
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

class AssetUpdate {
  public:
    static bool updateServerName(const string& oldName, const string& newName, vector<string>& serverNamesVec, vector<shared_ptr<Server>>& serverObjectVec);
    static bool updateServerEnvironment(const string& serverName, assetsEnvirontment newEnv, const vector<shared_ptr<Server>>& serverObjectVec);
    static bool updateServerComment(const string& serverName, const string& newComment, const vector<shared_ptr<Server>>& serverObjectVec);
    static void updateAllApplicationsServerName(const string& oldServerName, const string& newServerName);
    static void updateTeamServerName(const string& oldServerName, const string& newServerName, vector<shared_ptr<Application>>& appObjectVec);

    static bool updateApplicationName(const string& oldName, const string& newName, const vector<string>& appNamesVec, vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);
    static bool updateApplicationComment(const string& appName, const string& newComment, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);
    static bool moveApplicationToOtherServer(const string& appName, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);
};



#endif //ASSETUPDATE_H
