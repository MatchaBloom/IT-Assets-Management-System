#ifndef SERVER_H
#define SERVER_H
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Assets.h"
#include "../Additional.h"
using namespace std;

class Server: public Assets {
    private:
      string serverName;
    public:
      Server();
      Server (string owner, assetsEnvirontment env, const string& newServer, const string& newComment);
      ~Server();
      string getServerName() const;
      void setServerName(const string& newServerName);
      void display(ostream& out) override;
      static void listServer(vector<shared_ptr<Server>>& serverObjectVec);
      assetsEnvirontment getServerEnvironment() const;
};



#endif //SERVER_H
