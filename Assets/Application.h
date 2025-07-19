#ifndef APPLICATION_H
#define APPLICATION_H
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include "Assets.h"
#include "Server.h"
using namespace std;

class Application: public Assets {
protected:
  string appName;
  string appLastComment;
  vector<string> createdAppNames;
  shared_ptr<Server> serverRef;

public:
  Application();
  Application(string owner, shared_ptr<Server> server, const string& newAppName, const string& newComment);
  void createApplication(string teamOwner, vector<shared_ptr<Server>>& appObjectVec, const vector<string>& appNameOnlyVec);
  void display() override;
  shared_ptr<Server> findServerName(const vector<shared_ptr<Server>>& serverNameVec, const string& name);
  shared_ptr<Server> askServerName(const vector<shared_ptr<Server>>& serverNameVec);
};



#endif //APPLICATION_H
