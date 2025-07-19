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
      static void createServer(string serverMaker, vector<string>& createdServerNamesVec, vector<shared_ptr<Server>>& serverObjectVec);
      void display() override;
      static void listDataAssets(vector<shared_ptr<Server>>& serverObjectVec);
};



#endif //SERVER_H
