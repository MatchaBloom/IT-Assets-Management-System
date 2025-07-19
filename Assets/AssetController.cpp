#include "AssetController.h"
AssetController::AssetController(){}
AssetController::~AssetController(){}

shared_ptr<Server> AssetController::findServerName(const vector<shared_ptr<Server>>& serverNameVec, const string& name){
    for (const auto& srvName : serverNameVec){
        if(srvName && Additional::lowerCaseMode(srvName->getServerName()) == Additional::lowerCaseMode(name)){return srvName;}
    }
    return nullptr;
}

shared_ptr<Server> AssetController::askServerName(const vector<shared_ptr<Server>>& serverNameVec){
    if (serverNameVec.empty()) {
        cout << "No servers available! Please create a server first.\n";
        return nullptr;
    }
    cin.ignore();
    string name;
    while (true){
        cout << "Enter the existing server name: ";
        getline(cin, name);

        auto chosenServer = findServerName(serverNameVec, name);
        if (chosenServer){return chosenServer;}
        else{cout << "Server " << name << " not found!\n";}
    }
    return nullptr; //dummy
}
void AssetController::createApplication(string teamOwner, const vector<shared_ptr<Server>>& serverVec, vector<shared_ptr<Application>>& appObjectVec, vector<string>& appNameOnlyVec){
    string teamNameOwner = teamOwner;
    if (serverVec.empty()) {
        cout << "No servers available! Please create a server first.\n";
        return;}
    shared_ptr<Server> server = askServerName(serverVec);
    string appName = Assets::getAssetsName("application", appNameOnlyVec);
    string appLastComment = Assets::getAssetLastComment();

    auto newApp = make_shared<Application>(teamNameOwner, server, appName, appLastComment);
    appObjectVec.push_back(newApp);
    appNameOnlyVec.push_back(appName);

    cout << "Application " << appName << " created successfully!\n";
}
