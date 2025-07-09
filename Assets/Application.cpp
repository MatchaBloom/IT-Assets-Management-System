#include "Application.h"
Application::Application(){}
Application::Application(teamNameEnum owner, assetsEnvirontment env, shared_ptr<Server> server, const string& newAppName, const string& newAppComment)
            : Assets(owner, env), serverRef(server), appName(newAppName), appLastComment(newAppComment){
            if (!server) {
                throw std::runtime_error("Application must be associated with a valid server.");}
            }
void Application::display(){}