#include "Infrastructure.h"
void Infrastructure::addAssets() {
  cout << "Infrastructure::addAssets" << endl;
  createServer();
}

//For option 1 (Add assets (Server))
void Infrastructure::createServer(){
  newServerName = Assets::getAssetsName(createdServerNames);
  serverMaker = "Infrastructure";
  assetsEnvirontment env = Assets::getEnvironment();
  serverLastComment = Assets::getAssetLastComment();

  auto newServer = make_shared<Server>(serverMaker, env, newServerName, serverLastComment);
  serversObject.push_back(newServer);
  createdServerNames.push_back(newServerName);

  cout << "Server " << newServerName << " created successfully!\n";
}

void Infrastructure::listDataAssets() {
  cout << "Infrastructure::listDataAssets" << endl;
  cout << "=== List of Servers ===" << endl;
  if (serversObject.empty()) {
    cout << "No servers have been created yet." << endl;}
  else {
    for (const auto& serverPtr : serversObject) {
      if (serverPtr) {
        serverPtr->display();}
    }
  }
}

void Infrastructure::createApplication(){
  cout << "Infrastructure::createApplication" << endl;

}
void Infrastructure::updateAssets() {cout << "Infrastructure::updateAssets" << endl;}
void Infrastructure::deleteAssets() {cout << "Infrastructure::deleteAssets" << endl;}
void Infrastructure::exit() {}

