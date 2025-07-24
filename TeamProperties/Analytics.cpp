#include "Analytics.h"
vector<shared_ptr<Application>> Analytics::analyticsAppVec;

void Analytics::addAssets() {
  TeamController::addAsset("Analytics", analyticsAppVec);
  AssetController::writeAppToTxt("../txtFileHolder/analyticsApp.txt", analyticsAppVec);
}

void Analytics::listDataAssets() {
  AssetManager::listApplications(analyticsAppVec);
}

void Analytics::updateAssets() {cout << "Analytics::updateAssets" << endl;}
void Analytics::deleteAssets() {cout << "Analytics::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Analytics::getAnalyticsAppVecW(){
  return analyticsAppVec;
}
const vector<shared_ptr<Application>>& Analytics::getAnalyticsAppVecR(){
  return analyticsAppVec;
}