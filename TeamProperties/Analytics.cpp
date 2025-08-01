#include "Analytics.h"
vector<shared_ptr<Application>> Analytics::analyticsAppVec;

void Analytics::addAssets() {
  TeamController::addAsset("Analytics", this);
  AssetController::writeAppToTxt(fileName, analyticsAppVec);
}

void Analytics::listDataAssets() {
  AssetManager::listApplications(analyticsAppVec);
}

void Analytics::updateAssets() {
  TeamController::updateTeamMenu("analytics", this);
}

void Analytics::deleteAssets() {cout << "Analytics::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Analytics::getAnalyticsAppVecW(){
  return analyticsAppVec;
}

const vector<shared_ptr<Application>>& Analytics::getAnalyticsAppVecR(){
  return analyticsAppVec;
}

vector<shared_ptr<Application>>& Analytics::getTeamApps(){
  return analyticsAppVec;
}

const string& Analytics::getTeamFileName(){
  return fileName;
}

const string& Analytics::getTeamName(){
  static string name = "Analytics";
  return name;
}