#include "Application.h"
Application::Application(){}
Application::Application(string owner, assetsEnvirontment env, shared_ptr<Server> server, const string& newAppName, const string& newComment)
            : Assets(owner, env, newComment), serverRef(server), appName(newAppName){
            if (!server) {
                throw std::runtime_error("Application must be associated with a valid server.");}
            }
void Application::display(){}