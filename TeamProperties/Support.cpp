#include "Support.h"
vector<shared_ptr<Application>> Support::supportAppVec;

void Support::addAssets() {
  TeamController::addAsset("Support", supportAppVec);
}
void Support::listDataAssets() {cout << "Support::listDataAssets" << endl;}
void Support::updateAssets() {cout << "Support::updateAssets" << endl;}
void Support::deleteAssets() {cout << "Support::deleteAssets" << endl;}

vector<shared_ptr<Application>>& Support::getSupportAppVecW(){
  return supportAppVec;
}
const vector<shared_ptr<Application>>& Support::getSupportAppVecR(){
  return supportAppVec;
}
