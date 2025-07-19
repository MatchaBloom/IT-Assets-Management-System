#include "Application.h"
Application::Application(){}
Application::Application(string owner, shared_ptr<Server> server, const string& newAppName, const string& newComment)
            : Assets(owner, server->getEnvironment(), newComment){
  			appName = newAppName;
            serverRef = server;}

void Application::display(){
  cout << "Application name: " << appName << "in server " << serverRef << endl;
  cout << "This server was made by: " << teamNameOwner << endl;
  cout << "Environment name: " << Assets::environmentToString(environment) << endl;
  cout << "Last comment: " << assetLastComment << endl;
  cout << "Time added: " << Additional::dateTimeFormat() << endl;
  cout << "----------------------------------------------" << endl;
}