#include "AssetUpdate.h"

bool AssetUpdate::updateServerName(const string& oldName, const string& newName, vector<string>& serverNamesVec, vector<shared_ptr<Server>>& serverObjectVec){
  //Check if the new name exist or not.
  string lowerNewName = Additional::lowerCaseMode(newName);
  for (const auto& srvNameExist : serverNamesVec){
    if (Additional::lowerCaseMode(srvNameExist) == lowerNewName){
      cout << "Server '" << srvNameExist << "' already exists!\n";
      return false;
    }
  }
  shared_ptr<Server> serverToUpdate = AssetController::findServerName(serverObjectVec, oldName);
  if (!serverToUpdate){
    cout << "Server '" << oldName << "' does not exist!\n";
    return false;
  }
  serverToUpdate->setServerName(newName);
  string lowerOldName = Additional::lowerCaseMode(oldName);
  for (string& srvNameExist : serverNamesVec){
    if (Additional::lowerCaseMode(srvNameExist) == lowerOldName){
      srvNameExist = newName;
      cout << "Server '" << srvNameExist << "' name updated successfully to " << newName << "\n";
      break;
    }
  }
  AssetController::writeServerToTxt(serverObjectVec);
  return true;
}

bool AssetUpdate::updateServerEnvironment(const string& serverName, assetsEnvirontment newEnv, const vector<shared_ptr<Server>>& serverObjectVec){
  shared_ptr<Server> serverToUpdate = AssetController::findServerName(serverObjectVec, serverName);
  if (!serverToUpdate){
    cout << "Server '" << serverName << "' does not exist!\n";
    return false;
  }
  serverToUpdate->setEnvironment(newEnv);
  AssetController::writeServerToTxt(serverObjectVec);

  cout << "Server '" << serverName << "' environment updated to " << Assets::environmentToString(newEnv) << " successfully!" << endl;
  return true;
}

bool AssetUpdate::updateServerComment(const string& serverName, const string& newComment, const vector<shared_ptr<Server>>& serverObjectVec){
  shared_ptr<Server> serverToUpdate = AssetController::findServerName(serverObjectVec, serverName);
  if (!serverToUpdate){
    cout << "Server '" << serverName << "' does not exist!\n";
    return false;
  }
  serverToUpdate->setNewComment(newComment);
  AssetController::writeServerToTxt(serverObjectVec);

  cout << "Server '" << serverName << "' comment updated" << endl;
  return true;
}

void AssetUpdate::updateTeamServerName(const string& oldServerName, const string& newServerName, vector<shared_ptr<Application>>& appObjectVec){
  for (auto& teamApp : appObjectVec){
    if (teamApp && teamApp->getServer() &&
        Additional::lowerCaseMode(teamApp->getServer()->getServerName()) == Additional::lowerCaseMode(oldServerName)){
      teamApp->getServer()->getServerName() = newServerName;
      cout << "Updated application '" << teamApp->getApplicationName() << "' server reference from '" << oldServerName << "' to '" << newServerName << "'" << endl;
    }
  }
}

void AssetUpdate::updateAllApplicationsServerName(const string& oldServerName, const string& newServerName){
  Infrastructure infrastructure;
  updateTeamServerName(oldServerName, newServerName, infrastructure.getInfrastructureAppVecW());
  AssetController::writeAppToTxt("../txtFileHolder/infrastructureApp.txt", infrastructure.getInfrastructureAppVecR());

  updateTeamServerName(oldServerName, newServerName, Analytics::getAnalyticsAppVecW());
  AssetController::writeAppToTxt("../txtFileHolder/analyticsApp.txt", Analytics::getAnalyticsAppVecW());

  updateTeamServerName(oldServerName, newServerName, Cybersecurity::getCyberAppVecW());
  AssetController::writeAppToTxt("../txtFileHolder/cybersecurityApp.txt",Cybersecurity::getCyberAppVecW());

  updateTeamServerName(oldServerName, newServerName, Engineering::getEngAppVecW());
  AssetController::writeAppToTxt("../txtFileHolder/engineeringApp.txt", Engineering::getEngAppVecW());

  updateTeamServerName(oldServerName, newServerName, Support::getSupportAppVecW());
  AssetController::writeAppToTxt("../txtFileHolder/supportApp.txt", Support::getSupportAppVecW());
}

bool AssetUpdate::updateApplicationName(const string& oldName, const string& newName, const vector<string>& appNamesVec, vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  //check if applocation name exist or not
  for (const auto& appNameExist : appNamesVec){
    if (Additional::lowerCaseMode(appNameExist) == Additional::lowerCaseMode(newName)){
      cout << "The '" << newName << "' application already exists." << endl;
      return false;
    }
  }

  shared_ptr<Application> appToUpdate = nullptr;
  for (auto& app : appObjectVec){
    if (app && Additional::lowerCaseMode(app->getApplicationName()) == Additional::lowerCaseMode(oldName)) {
      appToUpdate = app;
      break;
    }
  }

  if(!appToUpdate){
    cout << "Application '" << oldName << "' is not available." << endl;
    return false;
  }

  appToUpdate->setApplicationName(newName);
  for (string app : appNamesVec) {
    if (Additional::lowerCaseMode(app) == Additional::lowerCaseMode(oldName)) {
      app = newName;
      cout << "Application '" << oldName << "' name updated successfully to '" << newName  << endl;
      break;
    }
  }
  AssetController::writeAppToTxt(txtFileName, appObjectVec);
  return true;
}

bool AssetUpdate::updateApplicationComment(const string& appName, const string& newComment, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  shared_ptr<Application> appToUpdate = nullptr;
  for (auto& app : appObjectVec){
    if (app && Additional::lowerCaseMode(app->getApplicationName()) == Additional::lowerCaseMode(appName)) {
      appToUpdate = app;
      break;
    }
  }

  if(!appToUpdate){
    cout << "Application '" << appName << "' is not available." << endl;
    return false;
  }

  appToUpdate->setNewComment(newComment);
  cout << "Application '" << appName << "' comment updated successfully!" << endl;
  AssetController::writeAppToTxt(txtFileName, appObjectVec);
  return true;
}

bool AssetUpdate::moveApplicationToOtherServer(const string& appName, const vector<shared_ptr<Application>>& appObjectVec, string& txtFileName){
  shared_ptr<Application> appToUpdate = nullptr;
  for (auto& app : appObjectVec){
    if (app && Additional::lowerCaseMode(app->getApplicationName()) == Additional::lowerCaseMode(appName)) {
      appToUpdate = app;
      break;
    }
  }

  if(!appToUpdate){
    cout << "Application '" << appName << "' is not available." << endl;
    return false;
  }

  shared_ptr<Server> newServer = AssetManager::askForServerSelection();
  if (newServer) {
    appToUpdate->setServer(newServer);
    cout << "Application moved to server '" << newServer->getServerName() << "' successfully!" << endl;
    AssetController::writeAppToTxt(txtFileName, appObjectVec);
    return true;
  }
  return false;
}
