#include "Server.h"
Server::Server(){}

Server::Server (string owner, assetsEnvirontment env, const string& newServer, const string& newComment)
        : Assets(owner, env, newComment) {
         serverName = newServer;}

Server::~Server(){}

string Server::getServerName() const {
  return serverName;
}

void Server::createServer(string serverMaker, vector<string>& createdServerNamesVec, vector<shared_ptr<Server>>& serverObjectVec) {
    string newServerName = Assets::getAssetsName("server", createdServerNamesVec);
    serverMaker = serverMaker;
    assetsEnvirontment env = Assets::getEnvironment();
    string serverLastComment = Assets::getAssetLastComment();

    auto newServer = make_shared<Server>(serverMaker, env, newServerName, serverLastComment);
    serverObjectVec.push_back(newServer);
    string lowerServerName = Additional::lowerCaseMode(newServerName);
    createdServerNamesVec.push_back(lowerServerName);
    cout << "Server " << newServerName << " created successfully!\n";
}

void Server::display(){
  cout << "Server name: " << serverName << endl;
  cout << "This server was made by: " << teamNameOwner << endl;
  cout << "Environment name: " << Assets::environmentToString(environment) << endl;
  cout << "Last comment: " << assetLastComment << endl;
  cout << "Time added: " << Additional::dateTimeFormat() << endl;
  cout << "----------------------------------------------" << endl;
}

void Server::listDataAssets(vector<shared_ptr<Server>>& serverObjectVec) {
    cout << "=== List of Servers ===" << endl;
    if (serverObjectVec.empty()) {
        cout << "No servers have been created yet." << endl;}
    else {
        for (const auto& serverPtr : serverObjectVec) {
            if (serverPtr) {
                serverPtr->display();}
        }
    }
}