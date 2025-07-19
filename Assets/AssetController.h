#ifndef ASSETCONTROLLER_H
#define ASSETCONTROLLER_H
#include <algorithm>
#include <iostream>
using namespace std;
#include "Assets.h"
#include "Application.h"
#include "Server.h"


class AssetController {
public:
  AssetController();
  ~AssetController();
  static void createApplication(string teamOwner, const vector<shared_ptr<Server>>& serverVec, vector<shared_ptr<Application>>& appObjectVec, vector<string>& appNameOnlyVec);
  static shared_ptr<Server> findServerName(const vector<shared_ptr<Server>>& serverNameVec, const string& name);
  static shared_ptr<Server> askServerName(const vector<shared_ptr<Server>>& serverNameVec);
};



#endif //ASSETCONTROLLER_H
