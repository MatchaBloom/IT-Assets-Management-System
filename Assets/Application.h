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
private:
  string appName;
  string appLastComment;
  shared_ptr<Server> serverRef;

public:
  Application();
  Application(teamNameEnum owner, assetsEnvirontment env, shared_ptr<Server> server, const string& newAppName, const string& newAppComment);
  void display() override;
};



#endif //APPLICATION_H
