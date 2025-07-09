#ifndef TEAMMENU_H
#define TEAMMENU_H
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

//This class will be parent's class of Infra, Eng, Analytic, Cyber, and Support.
class TeamMenu {
    public:
        virtual ~TeamMenu();
        virtual void addAssets() = 0;
        virtual void listDataAssets() = 0;
        virtual void updateAssets() = 0;
        virtual void deleteAssets() = 0;
        virtual void exit() = 0;

        string displayTeamOption();
        void handleTeamMenuInput();
};

#endif //TEAMMENU_H
