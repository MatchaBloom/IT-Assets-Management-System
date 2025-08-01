#include "AssetManager.h"

// static member definitions
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

bool AssetManager::updateServerName(const string& oldName, const string& newName){
  return AssetUpdate::updateServerName(oldName, newName, globalServerNames, globalServers);
}

bool AssetManager::updateServerEnvironment(const string& serverName, assetsEnvirontment newEnv){
  return AssetUpdate::updateServerEnvironment(serverName, newEnv, globalServers);
}

bool AssetManager::updateServerComment(const string& serverName, const string& newComment){
  return AssetUpdate::updateServerComment(serverName, newComment, globalServers);
}

bool AssetManager::updateApplicationName(const string& oldName, const string& newName, vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  return AssetUpdate::updateApplicationName(oldName, newName, globalAppNames, appObjectVec, txtFileName);
}

bool AssetManager::updateApplicationComment(const string& appName, const string& newComment, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  return AssetUpdate::updateApplicationComment(appName, newComment, appObjectVec, txtFileName);
}

bool AssetManager::moveApplicationToOtherServer(const string& appName, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  return AssetUpdate::moveApplicationToOtherServer(appName, appObjectVec, txtFileName);
}

void AssetManager::removeApplication(const string& appName){
  return AssetController::removeApplication(globalAppNames, appName);
}

void AssetManager::removeServer(const string& serverName){
  return AssetController::removeServer(globalServers, globalServerNames, serverName);
}