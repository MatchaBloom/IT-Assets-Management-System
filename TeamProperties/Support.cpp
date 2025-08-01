#include "Support.h"
vector<shared_ptr<Application>> Support::supportAppVec;

void Support::addAssets() {
  TeamController::addAsset("Support", this);
  AssetController::writeAppToTxt(fileName, supportAppVec);
}

void Support::listDataAssets() {
  AssetManager::listApplications(supportAppVec);
}

void Support::updateAssets() {
  TeamController::updateTeamMenu("support", this);
}

void Support::deleteAssets() {

}

vector<shared_ptr<Application>>& Support::getSupportAppVecW(){
  return supportAppVec;
}
const vector<shared_ptr<Application>>& Support::getSupportAppVecR(){
  return supportAppVec;
}

vector<shared_ptr<Application>>& Support::getTeamApps(){
  return supportAppVec;
}

const string& Support::getTeamFileName(){
  return fileName;
}

const string& Support::getTeamName(){
  static string name = "Support";
  return name;
}