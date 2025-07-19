#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H
#include <algorithm>
#include <iostream>
#include "TeamMenu.h"
#include "../Assets/Server.h"
#include "../Assets/Assets.h"
#include "../Assets/Application.h"
#include "../Assets/AssetController.h"
using namespace std;

class Infrastructure: public TeamMenu {
  protected:
    vector<shared_ptr<Server>> serversObject;
    vector <string> createdServerNames;
    vector<shared_ptr<Application>> infraAppVec;
    vector <string> createdAppNames;
  public:
    Infrastructure() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;
    void exit() override;
    void createApplication();
    const vector<string>& getServerNameList() const;
};



#endif //INFRASTRUCTURE_H
