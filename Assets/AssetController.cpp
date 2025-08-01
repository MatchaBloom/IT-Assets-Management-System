#include "AssetController.h"
AssetController::AssetController(){}
AssetController::~AssetController(){}

void AssetController::createServer(string serverMaker,
                                   vector<string>& createdServerNamesVec,
                                   vector<shared_ptr<Server>>& serverObjectVec)
{
  string newServerName = Assets::getAssetsName("server", createdServerNamesVec);
  serverMaker = serverMaker;
  assetsEnvirontment env = Assets::getEnvironment();
  string serverLastComment = Assets::getAssetLastComment();

  auto newServer = make_shared<Server>(serverMaker, env, newServerName, serverLastComment);
  serverObjectVec.push_back(newServer);
  writeServerToTxt(serverObjectVec);
  string lowerServerName = Additional::lowerCaseMode(newServerName);
  createdServerNamesVec.push_back(lowerServerName);
  cout << "\nServer '" << newServerName << "' created successfully!\n";
}

shared_ptr<Server> AssetController::findServerName(const vector<shared_ptr<Server>>& serverNameVec, const string& name){
  for (const auto& srvName : serverNameVec){
    if(srvName && Additional::lowerCaseMode(srvName->getServerName()) == Additional::lowerCaseMode(name)){
      return srvName;
    }
  }
  return nullptr;
}

shared_ptr<Server> AssetController::askServerName(const vector<shared_ptr<Server>>& serverNameVec){
  string name;
  while (true){
    cout << "\nAvailable servers:";
    listServer(serverNameVec);
    cout << "Enter the existing server name: ";
    getline(cin, name);

    auto chosenServer = findServerName(serverNameVec, name);
    if (chosenServer){return chosenServer;}
    else{cout << "\nServer '" << name << "' not found!\n\n";}
  }
  return nullptr; //dummy
}

void AssetController::createApplication(string teamOwner,
                                        const vector<shared_ptr<Server>>& serverVec,
                                        vector<shared_ptr<Application>>& appObjectVec,
                                        const vector<string>& appNameOnlyVec,
                                        function<void(const string&)> addToGlobalAppNames)
{
  string teamNameOwner = teamOwner;
  if (serverVec.empty()) {
    cout << "\nNo servers available! Please create a server first.\n";
    return;}

  shared_ptr<Server> server = askServerName(serverVec);
  if (!server) {return;}

  string appName = Assets::getAssetsName("application", appNameOnlyVec);
  string appLastComment = Assets::getAssetLastComment();

  auto newApp = make_shared<Application>(teamNameOwner, server, appName, appLastComment);
  appObjectVec.push_back(newApp);
  addToGlobalAppNames(appName); //pushing the application name to the globsl vector

  cout << "\nApplication '" << appName << "' created successfully in " << server->getServerName() << " (" << Assets::environmentToString(server->getServerEnvironment()) << ")!\n";
  cout << "This application own by " << teamNameOwner << " team!\n";
  cout << "Total applications in team: " << appObjectVec.size() << "\n";
}

void AssetController::listServer(const vector<shared_ptr<Server>>& serverObjectVec) {
  cout << "\n=== List of Servers ===" << endl;
  if (serverObjectVec.empty()) {
    cout << "No servers have been created yet." << endl;}
  else {
    for (const auto& serverPtr : serverObjectVec) {
      if (serverPtr) {
        serverPtr->display(cout);
      }
    }
  }
}

void AssetController::listApplication(const vector<shared_ptr<Application>>& appObjectVec) {
  cout << "=== List of Application ===" << endl;
  if (appObjectVec.empty()) {
    cout << "No application have been created yet." << endl;}
  else {
    for (const auto& appPtr : appObjectVec) {
      if (appPtr) {
        appPtr->display(cout);
      }
    }
  }
}

void AssetController::writeServerToTxt(const vector<shared_ptr<Server>>& serverObjectVec){
  ofstream serverFile;
  serverFile.open("../txtFileHolder/globalServer.txt");
  if (serverFile.is_open()) {
    for (const auto& serverPtr : serverObjectVec) {
      serverPtr->display(serverFile);
    }
  }
  else{
    cerr << "Error: Could not open globalServer.txt for writing\n";
  }
  serverFile.close();
}

void AssetController::writeAppToTxt(string txtFileName, const vector<shared_ptr<Application>>& appObjectVec){
  ofstream appFile;
  appFile.open(txtFileName);
  if (appFile.is_open()) {
    for (const auto& appPtr : appObjectVec) {
      appPtr->display(appFile);
    }
  }
  else{
    cerr << "Error: Could not open " << txtFileName << " for writing\n";
  }
  appFile.close();
}

void AssetController::removeApplication(vector<string>& appNameVec, const string& appName){
  for (const auto& app: appNameVec) {
    if (Additional::lowerCaseMode(app) == Additional::lowerCaseMode(appName)) {
      appNameVec.erase(remove_if(appNameVec.begin(), appNameVec.end(), [&appName](const string& app){
                return Additional::lowerCaseMode(app) == Additional::lowerCaseMode(appName);
                }),
      appNameVec.end());
    }
  }
}

void AssetController::removeServer(vector<shared_ptr<Server>>& serverObjectVec, vector<string>& globalServerNames, const string& serverName){
  // Remove from serverObjectVec
  serverObjectVec.erase(remove_if(serverObjectVec.begin(), serverObjectVec.end(),
    [&serverName](const std::shared_ptr<Server>& server) {
      return server && Additional::lowerCaseMode(server->getServerName()) == Additional::lowerCaseMode(serverName);
      }),
    serverObjectVec.end());

    // Remove from globalServerNames
    globalServerNames.erase(remove_if(globalServerNames.begin(), globalServerNames.end(),
    [&serverName](const std::string& name) {
      return Additional::lowerCaseMode(name) == Additional::lowerCaseMode(serverName);
      }),
    globalServerNames.end());
}