#include "AssetManager.h"

// Static member definitions
vector<shared_ptr<Server>> AssetManager::globalServers;
vector<string> AssetManager::globalServerNames;
vector<string> AssetManager::globalAppNames;

void AssetManager::createServer(const string& serverMaker){
    AssetController::createServer(serverMaker, globalServerNames, globalServers);
}

void AssetManager::createApplication(const string& teamOwner, vector<shared_ptr<Application>>& teamApps){
  auto addToGlobal = [](const string& appName) {addAppName(appName);};
  AssetController::createApplication(teamOwner, globalServers, teamApps, globalAppNames, addToGlobal);
}

void AssetManager::addAppName(const string& appName){
  globalAppNames.push_back(appName);
}

void AssetManager::listServers(){
  AssetController::listServer(globalServers);
}

void AssetManager::listApplications(const vector<shared_ptr<Application>>& apps){
  AssetController::listApplication(const_cast<vector<shared_ptr<Application>>&>(apps));
}

shared_ptr<Server> AssetManager::findServerByName(const string& name) {
  return AssetController::findServerName(globalServers, name);
}

shared_ptr<Server> AssetManager::askForServerSelection() {
  return AssetController::askServerName(globalServers);
}
