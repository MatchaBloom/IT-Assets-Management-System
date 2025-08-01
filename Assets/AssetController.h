#ifndef ASSETCONTROLLER_H
#define ASSETCONTROLLER_H
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
#include "Assets.h"
#include "Application.h"
#include "Server.h"

//This class functionality:
// create server and application,
// find existing server name and logic to ask user server name,
// list, display, and write to txt file for server and application.
class AssetController {
public:
  AssetController();
  ~AssetController();
  static void createServer(string serverMaker, vector<string>& createdServerNamesVec, vector<shared_ptr<Server>>& serverObjectVec);
  static void createApplication(string teamOwner, const vector<shared_ptr<Server>>& serverVec, vector<shared_ptr<Application>>& appObjectVec, const vector<string>& appNameOnlyVec, function<void(const string&)> addToGlobalAppNames);
  static shared_ptr<Server> findServerName(const vector<shared_ptr<Server>>& serverNameVec, const string& name);
  static shared_ptr<Server> askServerName(const vector<shared_ptr<Server>>& serverNameVec);
  static void listServer(const vector<shared_ptr<Server>>& serverObjectVec);
  static void listApplication(const vector<shared_ptr<Application>>& appObjectVec);
  static void writeServerToTxt(const vector<shared_ptr<Server>>& serverObjectVec);
  static void writeAppToTxt(string txtFileName, const vector<shared_ptr<Application>>& appObjectVec);

  static void removeApplication(vector<string>& appNameVec, const string& appName);
  static void removeServer(vector<shared_ptr<Server>>& serverObjectVec, vector<string>& globalServerNames, const string& serverName)
//note: Static functions cannot call non-static member functions
};



#endif //ASSETCONTROLLER_H
