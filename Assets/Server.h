#ifndef SERVER_H
#define SERVER_H
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include "Assets.h"
using namespace std;

class Server: public Assets {
    private:
      string serverName;
      string serverLastComment;
    public:
      Server();
      Server (teamNameEnum owner, assetsEnvirontment env, const string& newServer, const string& newServerComment);
      ~Server();
};



#endif //SERVER_H
