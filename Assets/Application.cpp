#include "Application.h"
Application::Application(){}
Application::Application(string owner, shared_ptr<Server> server, const string& newAppName, const string& newComment)
            : Assets(owner, server->getServerEnvironment(), newComment){
  			appName = newAppName;
            serverRef = server;}

void Application::display(ostream& out){
  out << "Application name: " << appName << " in server " << serverRef->getServerName() << endl;
  out << "This application was made by: " << teamNameOwner << endl;
  out << "Environment name: " << Assets::environmentToString(environment) << endl;
  out << "Last comment: " << assetLastComment << endl;
  out << "Time added: " << Additional::dateTimeFormat() << endl;
  out << "----------------------------------------------" << endl;
}