#include "Cybersecurity.h"
vector<shared_ptr<Application>> Cybersecurity::cyberAppVec;

void Cybersecurity::addAssets() {
  TeamController::addAsset("Cybersecurity", this);
  AssetController::writeAppToTxt(fileName, cyberAppVec);
}

void Cybersecurity::listDataAssets() {
  AssetManager::listApplications(cyberAppVec);
}

void Cybersecurity::updateAssets() {
  TeamController::updateTeamMenu("cybersecurity", this);
}

void Cybersecurity::deleteAssets() {cout << "CyberSecurity::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Cybersecurity::getCyberAppVecW(){
  return cyberAppVec;
}

const vector<shared_ptr<Application>>& Cybersecurity::getCyberAppVecR(){
  return cyberAppVec;
}

vector<shared_ptr<Application>>& Cybersecurity::getTeamApps(){
  return cyberAppVec;
}

const string& Cybersecurity::getTeamFileName(){
  return fileName;
}

const string& Cybersecurity::getTeamName(){
  static string name = "Cybersecurity";
  return name;
}
