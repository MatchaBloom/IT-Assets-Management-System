#include "Engineering.h"
vector<shared_ptr<Application>> Engineering::engineeringAppVec;

void Engineering::addAssets() {
  TeamController::addAsset("Engineering", engineeringAppVec);
}
void Engineering::listDataAssets() {cout << "Engineering::listDataAssets" << endl;}
void Engineering::updateAssets() {cout << "Engineering::updateAssets" << endl;}
void Engineering::deleteAssets() {cout << "Engineering::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Engineering::getEngAppVecW(){
  return engineeringAppVec;
}
const vector<shared_ptr<Application>>& Engineering::getEngAppVecR(){
  return engineeringAppVec;
}
