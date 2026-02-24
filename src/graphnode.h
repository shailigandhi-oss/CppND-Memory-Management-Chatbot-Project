/**
 * @file graphnode.h
 * @brief Defines a node in the chatbot answer graph.
 */

#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_
#include <memory>
#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

/**
 * @class GraphNode
 * @brief Represents a node in the answer graph, holding possible answers and edges.
 *
 * Each node has a unique ID, a list of answer strings, child edges (owned),
 * parent edges (non-owned), and may hold the ChatBot when the conversation
 * is at this node. Uses unique_ptr for owned child edges and ChatBot.
 */
class GraphNode
{
private:
    //// STUDENT CODE
    ////

    /** @brief Owned edges from this node to subsequent (child) nodes. */
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;

    /** @brief Non-owned pointers to edges from preceding (parent) nodes. */
    std::vector<GraphEdge *> _parentEdges;
    /** @brief Owned ChatBot instance when present at this node. */
    std::unique_ptr<ChatBot> _chatBot;

    ////
    //// EOF STUDENT CODE

    /** @brief Unique identifier for this node. */
    int _id;
    /** @brief List of answer strings that may be shown at this node. */
    std::vector<std::string> _answers;

public:
    /**
     * @brief Constructs a node with the given ID.
     * @param id Unique identifier for the node.
     */
    GraphNode(int id);
    /** @brief Destructor. */
    ~GraphNode();

    /** @brief Returns the node ID. */
    int GetID() { return _id; }
    /** @brief Returns the number of child edges. */
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    /**
     * @brief Returns the child edge at the given index.
     * @param index Zero-based index.
     * @return Raw pointer to the edge, or nullptr if out of range.
     */
    GraphEdge *GetChildEdgeAtIndex(int index);
    /** @brief Returns the list of answer strings. */
    std::vector<std::string> GetAnswers() { return _answers; }
    /** @brief Returns the number of parent edges. */
    int GetNumberOfParents() { return _parentEdges.size(); }

    /**
     * @brief Adds an answer token to the node's answer list.
     * @param token Answer string to add.
     */
    void AddToken(std::string token);
    /** @brief Registers a non-owned edge from a parent node. */
    void AddEdgeToParentNode(GraphEdge *edge);
    /** @brief Adds an owned edge to a child node (takes ownership). */
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge>edge);

    //// STUDENT CODE
    ////

    /** @brief Moves the given ChatBot into this node (takes ownership). */
    void MoveChatbotHere(std::unique_ptr<ChatBot> chatbot);
    /** @brief Moves the given ChatBot rvalue into this node. */
    void MoveChatbotHere(ChatBot&& chatbot);
    /** @brief Returns raw pointer to the ChatBot at this node, or nullptr. */
    ChatBot* GetChatBot();

    ////
    //// EOF STUDENT CODE

    /**
     * @brief Moves the ChatBot from this node to another node.
     * @param newNode Destination node for the ChatBot.
     */
    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
