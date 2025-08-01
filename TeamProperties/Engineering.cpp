#include "Engineering.h"
vector<shared_ptr<Application>> Engineering::engineeringAppVec;

void Engineering::addAssets() {
  TeamController::addAsset("Engineering", this);
  AssetController::writeAppToTxt(fileName, engineeringAppVec);
}

void Engineering::listDataAssets() {
  AssetManager::listApplications(engineeringAppVec);
}
void Engineering::updateAssets() {
  TeamController::updateTeamMenu("engineering", this);
}

void Engineering::deleteAssets() {cout << "Engineering::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Engineering::getEngAppVecW(){
  return engineeringAppVec;
}
const vector<shared_ptr<Application>>& Engineering::getEngAppVecR(){
  return engineeringAppVec;
}

vector<shared_ptr<Application>>& Engineering::getTeamApps(){
  return engineeringAppVec;
}

const string& Engineering::getTeamFileName(){
  return fileName;
}

const string& Engineering::getTeamName(){
  static string name = "Engineering";
  return name;
}