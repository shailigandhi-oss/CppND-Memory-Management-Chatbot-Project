#include "graphedge.h"
#include "graphnode.h"
#include "chatlogic.h"
GraphNode::GraphNode(int id)
{
    _id = id;
    _chatBot = nullptr;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot&& chatbot)
{
    _chatBot = std::make_unique<ChatBot>(std::move(chatbot));
    ChatLogic *logic = _chatBot->GetChatLogicHandle();
    if (logic)
    logic->SetChatbotHandle(_chatBot.get());
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotHere(std::unique_ptr<ChatBot> chatbot)
{
    _chatBot = std::move(chatbot);
    if (_chatBot != nullptr) {
        _chatBot->SetCurrentNode(this);
    }
}
ChatBot* GraphNode::GetChatBot()
{
    return _chatBot.get();
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}