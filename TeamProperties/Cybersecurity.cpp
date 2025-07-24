#include "Cybersecurity.h"
vector<shared_ptr<Application>> Cybersecurity::cyberAppVec;

void Cybersecurity::addAssets() {
  TeamController::addAsset("Cybersecurity", cyberAppVec);
}
void Cybersecurity::listDataAssets() {cout << "CyberSecurity::listDataAssets" << endl;}
void Cybersecurity::updateAssets() {cout << "CyberSecurity::updateAssets" << endl;}
void Cybersecurity::deleteAssets() {cout << "CyberSecurity::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Cybersecurity::getCyberAppVecW(){
  return cyberAppVec;
}

const vector<shared_ptr<Application>>& Cybersecurity::getCyberAppVecR(){
  return cyberAppVec;
}
