#include "agent.hpp"

//using namespace std;

typedef void (*AgentHandler)(JsonDocument &req, JsonDocument &resp);

class AgentNode
{
public:
  std::vector<AgentHandler> handlers;
  //AgentHandler _handler;
  std::map<String, AgentNode *> childrens;

public:
  void Route(String path, AgentHandler handler)
  {
    if (path == "")
    {
      handlers.push_back(handler);
      //_handler = handler;
      return;
    }

    int c = path.indexOf('/');
    String node = path.substring(0, c);
    String next = path.substring(c);
    if (childrens.find(node) == childrens.end())
    {
      childrens[node] = new AgentNode();
    }
    childrens[node]->Route(next, handler);
  }

  void Walk(String path, JsonDocument &req, JsonDocument &resp)
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

    int c = path.indexOf('/');
    String node = path.substring(0, c);
    String next = path.substring(c);
    auto iter = childrens.find(node);
    if (iter == childrens.end())
    {
      return;
    }
    iter->second->Walk(next, req, resp);
  }
};

AgentNode root;

void sysInfo(JsonDocument &req, JsonDocument &resp)
{
}

void Agent_Init()
{
  root.Route("sys/info", sysInfo);
}

void AgentHandle(Stream &stream)
{
  DynamicJsonDocument request(1024);
  StaticJsonDocument<200> response;
  deserializeJson(request, stream);
  String path = request["path"];
  response["path"] = path;
  root.Walk(path, request, response);
  String output;
  serializeJson(response, output);
  //return output;
}
