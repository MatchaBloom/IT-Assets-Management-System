#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
#include "TeamController.h"
#include "../Assets/Application.h"
using namespace std;

class Analytics: public TeamMenu {
  private:
    static vector<shared_ptr<Application>> analyticsAppVec;
  public:
    Analytics() = default;
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;

    static vector<shared_ptr<Application>>& getAnalyticsAppVecW();
    const vector<shared_ptr<Application>>& getAnalyticsAppVecR();

};

#endif //ANALYTICS_H
