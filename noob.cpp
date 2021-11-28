#include "noob.hpp"

//using namespace std;

typedef void (*AgentHandler)(cJSON *req, cJSON *resp);

class AgentNode
{
public:
  std::vector<AgentHandler> handlers;
  //AgentHandler _handler;
  std::map<std::string, AgentNode *> childrens;

public:
  void Route(std::string path, AgentHandler handler)
  {
    if (path == "")
    {
      handlers.push_back(handler);
      //_handler = handler;
      return;
    }

    int c = path.find_first_of('/');
    std::string node = path.substr(0, c);
    std::string next = path.substr(c);
    if (childrens.find(node) == childrens.end())
    {
      childrens[node] = new AgentNode();
    }
    childrens[node]->Route(next, handler);
  }

  void Walk(std::string path, cJSON* req, cJSON* resp)
  {
    if (path == "")
    {
      //handlers.push_back(handler);
      for (auto iter = handlers.cbegin();
           iter != handlers.cend(); iter++)
      {
        (*iter)(req, resp);
      }
      return;
    }

    int c = path.find_first_of('/');
    std::string node = path.substr(0, c);
    std::string next = path.substr(c);
    auto iter = childrens.find(node);
    if (iter == childrens.end())
    {
      return;
    }
    iter->second->Walk(next, req, resp);
  }
};

AgentNode root;

void sysInfo(cJSON* req, cJSON* resp)
{
}

void Agent_Init()
{
  root.Route("sys/info", sysInfo);
}

void AgentHandle() //(Stream &stream)
{

  //return output;
}
