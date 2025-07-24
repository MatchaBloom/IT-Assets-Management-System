#include <algorithm>
#include <iostream>
using namespace std;
#include "Assets.h"
#include "Application.h"
#include "Server.h"
#include "AssetController.h"

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H


class AssetManager {
  private:
    static vector<shared_ptr<Server>> globalServers;
    static vector<string> globalServerNames;
    static vector<string> globalAppNames;

    static shared_ptr<Server> findServerByName(const string& name);
    static shared_ptr<Server> askForServerSelection();

  public:
    static const vector<shared_ptr<Server>>& getServers() { return globalServers; }
    static const vector<string>& getServerNames() { return globalServerNames; }
    static const vector<string>& getAppNames() { return globalAppNames; }

    static void createServer(const string& serverMaker);
    static void createApplication(const string& teamOwner, vector<shared_ptr<Application>>& teamApps);
    static void addAppName(const string& appName);

    static void listServers();
    static void listApplications(const vector<shared_ptr<Application>>& apps);

};



#endif //ASSETMANAGER_H
