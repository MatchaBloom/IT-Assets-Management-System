#include "AssetRemove.h"
vector<shared_ptr<Application>> AssetRemove::findAppOnServer(const vector<shared_ptr<Application>>& appObjectVec, const string& serverName){
  //vector initialazation
  vector<shared_ptr<Application>> appOnServerVec;
  for (const auto& app: appObjectVec) {
    if (app && app->getServer() && Additional::lowerCaseMode(app->getServer()->getServerName()) == Additional::lowerCaseMode(serverName)){
      appOnServerVec.push_back(app);
    }
  }
  return appOnServerVec;
}

vector<pair<shared_ptr<Application>, string>> AssetRemove::findAllApplicationsOnServer(const string& serverName){
  //note: pair<> is a template from <utility>. store exactly two values of potentially different types together.
  vector<pair<shared_ptr<Application>, string>> appTeamOnServerVec;
  // Check Infrastructure team
  Infrastructure infrastructure;
  auto infraApps = findAppOnServer(infrastructure.getTeamApps(), serverName);
  for (const auto& app : infraApps) {
    appTeamOnServerVec.push_back({app, "Infrastructure"});
  }

  // Check Analytics team
  Analytics analytics;
  auto analyticsApps = findAppOnServer(analytics.getTeamApps(), serverName);
  for (const auto& app : analyticsApps) {
    appTeamOnServerVec.push_back({app, "Analytics"});
  }

  // Check Cybersecurity team
  Cybersecurity cybersecurity;
  auto cyberApps = findAppOnServer(cybersecurity.getTeamApps(), serverName);
  for (const auto& app : cyberApps) {
    appTeamOnServerVec.push_back({app, "Cybersecurity"});
  }

  // Check Engineering team
  Engineering engineering;
  auto engApps = findAppOnServer(engineering.getTeamApps(), serverName);
  for (const auto& app : engApps) {
     appTeamOnServerVec.push_back({app, "Engineering"});
  }

  // Check Support team
  Support support;
  auto supportApps = findAppOnServer(support.getTeamApps(), serverName);
  for (const auto& app : supportApps) {
    appTeamOnServerVec.push_back({app, "Support"});
  }

  return appTeamOnServerVec;
}

bool AssetRemove::removeApplication(vector<shared_ptr<Application>>& teamAppVec, const string& appName, const string& txtFileName){
  //lambda implementation
  auto it = find_if(teamAppVec.begin(), teamAppVec.end(),
                    [&appName](const shared_ptr<Application>& app) {
                    return app && Additional::lowerCaseMode(app->getApplicationName()) == Additional::lowerCaseMode(appName);}
                    );
  if (it != teamAppVec.end()) {
    cout << "Application '" << appName << "' has been deleted successfully!" << endl;
    teamAppVec.erase(it);
    AssetController::writeAppToTxt(txtFileName, teamAppVec);

    AssetManager::removeApplication(appName);
    return true;
  }

  cout << "Application '" << appName << "' not found!" << endl;
  return false;
}

bool AssetRemove::removeServer(const string& serverName) {
        shared_ptr<Server> server = AssetManager::findServerByName(serverName);
        if (!server) {
            cout << "Server '" << serverName << "' not found!" << endl;
            return false;
        }

        // Check for applications on this server across ALL teams
        auto appsOnServer = findAllApplicationsOnServer(serverName);

        if (appsOnServer.empty()) {
            // Safe to delete - no applications on this server
            cout << "Server '" << serverName << "' has no applications. Deleting server..." << endl;
            AssetManager::removeServer(serverName);
            return true;
        } else {
            // Server has applications - show them and ask user what to do
            cout << "\nWARNING: Server '" << serverName << "' has the following applications:" << endl;
            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;

            for (size_t i = 0; i < appsOnServer.size(); ++i) {
                cout << (i + 1) << ". " << appsOnServer[i].first->getApplicationName()
                     << " (owned by " << appsOnServer[i].second << " team)" << endl;
            }

            cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
            cout << "\nWhat would you like to do?" << endl;
            cout << "1. Move all applications to other servers first, then delete server" << endl;
            cout << "2. Delete server AND all applications on it (⚠️  DESTRUCTIVE!)" << endl;
            cout << "3. Cancel deletion" << endl;
            cout << "Enter your choice (1-3): ";

            string choice;
            getline(cin, choice);

            if (choice == "1") {
                return handleMoveApplicationsAndDeleteServer(serverName, appsOnServer);
            } else if (choice == "2") {
                return handleDeleteServerAndApplications(serverName, appsOnServer);
            } else {
                cout << "Server deletion cancelled." << endl;
                return false;
            }
        }
    }

bool handleMoveApplicationsAndDeleteServer(
const string& serverName,
const vector<pair<shared_ptr<Application>, string>>& appsOnServer) {

cout << "\n=== Moving Applications to Other Servers ===" << endl;

for (const auto& appPair : appsOnServer) {
  shared_ptr<Application> app = appPair.first;
  string teamName = appPair.second;

  cout << "\nMoving application: " << app->getApplicationName() << " (from " << teamName << " team)" << endl;

  shared_ptr<Server> newServer = AssetManager::askForServerSelection();
  if (newServer) {
    app->setServer(newServer);
    cout << "Moved '" << app->getApplicationName() << "' to server '" << newServer->getServerName() << "'" << endl;
    // Update the appropriate team's file
    updateTeamFile(teamName);}

  else {
    cout << "Failed to move application. Server deletion cancelled." << endl;
    return false;
  }
}

cout << "\n✅ All applications moved successfully!" << endl;
cout << "Now deleting server '" << serverName << "'..." << endl;
return AssetManager::removeServerFromSystem(serverName);
}

    bool handleDeleteServerAndApplications(
        const string& serverName,
        const vector<pair<shared_ptr<Application>, string>>& appsOnServer) {

        cout << "\n⚠️  DESTRUCTIVE OPERATION WARNING ⚠️" << endl;
        cout << "This will permanently delete:" << endl;
        cout << "- Server: " << serverName << endl;
        cout << "- " << appsOnServer.size() << " applications:" << endl;

        for (const auto& appPair : appsOnServer) {
            cout << "  • " << appPair.first->getApplicationName()
                 << " (" << appPair.second << " team)" << endl;
        }

        cout << "\nType 'DELETE EVERYTHING' to confirm: ";
        string confirmation;
        getline(cin, confirmation);

        if (confirmation == "DELETE EVERYTHING") {
            cout << "\nDeleting applications..." << endl;

            // Delete applications from each team
            for (const auto& appPair : appsOnServer) {
                string appName = appPair.first->getApplicationName();
                string teamName = appPair.second;

                deleteApplicationFromTeam(appName, teamName);
                cout << "🗑️ Deleted application: " << appName << " (" << teamName << ")" << endl;
            }

            cout << "\nDeleting server..." << endl;
            bool serverDeleted = AssetManager::removeServerFromSystem(serverName);

            if (serverDeleted) {
                cout << "🗑️ Server '" << serverName << "' and all its applications have been deleted!" << endl;
                return true;
            } else {
                cout << "❌ Failed to delete server!" << endl;
                return false;
            }
        } else {
            cout << "Deletion cancelled - confirmation text didn't match." << endl;
            return false;
        }
    }
void updateTeamFile(const string& teamName) {
        if (teamName == "Infrastructure") {
            Infrastructure infra;
            AssetController::writeAppToTxt(infra.getTeamFileName(), infra.getTeamApps());
        } else if (teamName == "Analytics") {
            Analytics analytics;
            AssetController::writeAppToTxt(analytics.getTeamFileName(), analytics.getTeamApps());
        } else if (teamName == "Cybersecurity") {
            Cybersecurity cyber;
            AssetController::writeAppToTxt(cyber.getTeamFileName(), cyber.getTeamApps());
        } else if (teamName == "Engineering") {
            Engineering eng;
            AssetController::writeAppToTxt(eng.getTeamFileName(), eng.getTeamApps());
        } else if (teamName == "Support") {
            Support support;
            AssetController::writeAppToTxt(support.getTeamFileName(), support.getTeamApps());
        }
    }
    bool deleteApplicationFromTeam(const string& appName, const string& teamName) {
        if (teamName == "Infrastructure") {
            Infrastructure infra;
            return removeApplication(appName, infra.getTeamApps(), infra.getTeamFileName());
        } else if (teamName == "Analytics") {
            Analytics analytics;
            return removeApplication(appName, analytics.getTeamApps(), analytics.getTeamFileName());
        } else if (teamName == "Cybersecurity") {
            Cybersecurity cyber;
            return removeApplication(appName, cyber.getTeamApps(), cyber.getTeamFileName());
        } else if (teamName == "Engineering") {
            Engineering eng;
            return removeApplication(appName, eng.getTeamApps(), eng.getTeamFileName());
        } else if (teamName == "Support") {
            Support support;
            return removeApplication(appName, support.getTeamApps(), support.getTeamFileName());
        }
        return false;
    }