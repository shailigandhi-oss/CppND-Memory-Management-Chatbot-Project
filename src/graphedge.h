/**
 * @file graphedge.h
 * @brief Defines a directed edge in the chatbot answer graph.
 */

#ifndef GRAPHEDGE_H_
#define GRAPHEDGE_H_

#include <vector>
#include <string>

class GraphNode; // forward declaration

/**
 * @class GraphEdge
 * @brief Represents a directed edge connecting two nodes in the answer graph.
 *
 * Each edge links a parent node to a child node and carries keywords used
 * to match user input and select the next node in the conversation flow.
 */
class GraphEdge
{
private:
    /** @brief Pointer to the child (destination) node. Not owned. */
    GraphNode *_childNode;
    /** @brief Pointer to the parent (source) node. Not owned. */
    GraphNode *_parentNode;

    /** @brief Unique identifier for this edge. */
    int _id;
    /** @brief Keywords associated with this edge for matching user input. */
    std::vector<std::string> _keywords;


public:
    /**
     * @brief Constructs an edge with the given ID.
     * @param id Unique identifier for the edge.
     */
    GraphEdge(int id);

    /** @brief Returns the edge ID. */
    int GetID() { return _id; }
    /** @brief Sets the child node this edge points to. */
    void SetChildNode(GraphNode *childNode);
    /** @brief Sets the parent node this edge originates from. */
    void SetParentNode(GraphNode *parentNode);
    /** @brief Returns the child node. */
    GraphNode *GetChildNode() { return _childNode; }
    /** @brief Returns the list of keywords for this edge. */
    std::vector<std::string> GetKeywords() { return _keywords; }

    /**
     * @brief Adds a keyword/token to this edge.
     * @param token Keyword to add for matching user input.
     */
    void AddToken(std::string token);
};

#endif /* GRAPHEDGE_H_ */
