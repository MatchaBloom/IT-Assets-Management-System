#ifndef CYBERSECURITY_H
#define CYBERSECURITY_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
#include "ITeamAssetProvider.h"
using namespace std;

class Cybersecurity: public TeamMenu, public ITeamAssetProvider {
  private:
    static vector<shared_ptr<Application>> cyberAppVec;
    string fileName = "../txtFileHolder/cybersecurityApp.txt";

  public:
    Cybersecurity() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getCyberAppVecW();
    const vector<shared_ptr<Application>>& getCyberAppVecR();

    vector<shared_ptr<Application>>& getTeamApps() override;
    const string& getTeamFileName() override;
    const string& getTeamName() override;

    bool canRemoveServer() override;
    bool canRemoveApplication() override;
};



#endif //CYBERSECURITY_H
