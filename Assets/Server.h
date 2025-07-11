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
      //static bool uniqueNameServer(const vector<string>& serverNames, const string& nameToCheck);
      //static string getServerName(const vector<string>& serverNames);
      void display() override;
};



#endif //SERVER_H
