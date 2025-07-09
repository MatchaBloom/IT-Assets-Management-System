#ifndef ANALYTICS_H
#define ANALYTICS_H
#include <algorithm>
#include <iostream>
#include <sstream>
#include "TeamMenu.h"
using namespace std;

class Analytics: public TeamMenu {
public:
    void addAssets() override;
    void listDataAssets() override;
    void updateAssets() override;
    void deleteAssets() override;
    void exit() override;
};

#endif //ANALYTICS_H
