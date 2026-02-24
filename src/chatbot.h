/**
 * @file chatbot.h
 * @brief Defines the ChatBot entity that processes user messages and moves through the graph.
 */

#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

/**
 * @class ChatBot
 * @brief Core chatbot entity with avatar image and conversation logic.
 *
 * The ChatBot owns its avatar image, holds non-owned pointers to the current
 * node, root node, and ChatLogic. It is non-copyable and uses move semantics
 * when transferred between graph nodes. Receives user messages and delegates
 * to ChatLogic for graph traversal and response selection.
 */
class ChatBot
{
private:
    /** @brief Owned avatar image. */
    wxBitmap *_image;

    /** @brief Current node in the graph. Not owned. */
    GraphNode *_currentNode;
    /** @brief Root node of the graph. Not owned. */
    GraphNode *_rootNode;
    /** @brief Chat logic controller. Not owned. */
    ChatLogic *_chatLogic;

    /**
     * @brief Computes Levenshtein distance between two strings.
     * @param s1 First string.
     * @param s2 Second string.
     * @return Edit distance between s1 and s2.
     */
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    /** @brief Default constructor; no image allocation. */
    ChatBot();
    /**
     * @brief Constructs ChatBot and loads avatar from file.
     * @param filename Path to the avatar image file.
     */
    ChatBot(std::string filename);
    /** @brief Destructor. */
    ~ChatBot();

    //// STUDENT CODE
    ////
    /** @brief Copy constructor deleted. */
    ChatBot(const ChatBot &other) = delete;
    /** @brief Copy assignment deleted. */
    ChatBot &operator=(const ChatBot &other) = delete;
    /** @brief Move constructor. */
    ChatBot(ChatBot &&other);
    /** @brief Move assignment operator. */
    ChatBot &operator=(ChatBot &&other );
    ////
    //// EOF STUDENT CODE

    /** @brief Sets the current graph node. */
    void SetCurrentNode(GraphNode *node);
    /** @brief Sets the root node of the graph. */
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    /** @brief Sets the ChatLogic handle. */
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    /** @brief Returns the ChatLogic handle. */
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    /** @brief Returns the avatar image handle. */
    wxBitmap *GetImageHandle() { return _image; }

    /**
     * @brief Processes a message from the user and triggers response logic.
     * @param message User input string.
     */
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
