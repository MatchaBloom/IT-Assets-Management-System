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
  shared_ptr<Server> serverRef;

public:
  Application();
  Application(string owner, shared_ptr<Server> server, const string& newAppName, const string& newComment);
  void display(ostream& out) override;
};



#endif //APPLICATION_H
