#ifndef CYBERSECURITY_H
#define CYBERSECURITY_H
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
#include "TeamMenu.h"

class Cybersecurity: public TeamMenu {
    public:
        Cybersecurity() = default;
        void addAssets() override;
        void listDataAssets() override;
        void updateAssets() override;
        void deleteAssets() override;
        void exit() override;

};



#endif //CYBERSECURITY_H
