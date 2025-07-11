#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
using namespace std;

class Infrastructure: public TeamMenu {
  protected:
    vector<shared_ptr<Server>> serversObject;
    vector <string> createdServerNames;
    string newServerName, serverLastComment, serverMaker;
    string infraAppName, infraAppLastComment, infraAppMaker;
  public:
    Infrastructure() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;
    void exit() override;
    void createServer();
    void createApplication();
};



#endif //INFRASTRUCTURE_H
