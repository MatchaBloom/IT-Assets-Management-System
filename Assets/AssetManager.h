#include <algorithm>
#include <iostream>
using namespace std;
#include "Assets.h"
#include "Application.h"
#include "Server.h"
#include "AssetController.h"
#include "AssetUpdate.h"

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H


class AssetManager {
  private:
    static vector<shared_ptr<Server>> globalServers;
    static vector<string> globalServerNames;
    static vector<string> globalAppNames;

  public:
    static shared_ptr<Server> findServerByName(const string& name);
    static shared_ptr<Server> askForServerSelection();

    static const vector<shared_ptr<Server>>& getServers() { return globalServers; }
    static const vector<string>& getServerNames() { return globalServerNames; }
    static const vector<string>& getAppNames() { return globalAppNames; }

    static void createServer(const string& serverMaker);
    static void createApplication(const string& teamOwner, vector<shared_ptr<Application>>& teamApps);
    static void addAppName(const string& appName);

    static void listServers();
    static void listApplications(const vector<shared_ptr<Application>>& apps);

    static bool updateServerName(const string& oldName, const string& newName);
    static bool updateServerEnvironment(const string& serverName, assetsEnvirontment newEnv);
    static bool updateServerComment(const string& serverName, const string& newComment);

    static bool updateApplicationName(const string& oldName, const string& newName, vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);
    static bool updateApplicationComment(const string& appName, const string& newComment, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);
    static bool moveApplicationToOtherServer(const string& appName, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName);

    static void removeApplication(const string& appName);
    static void removeServer(const string& serverName);



};



#endif //ASSETMANAGER_H
