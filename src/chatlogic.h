/**
 * @file chatlogic.h
 * @brief Defines the ChatLogic controller that loads the answer graph and coordinates the chatbot.
 */

#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_
#include <memory>
#include <vector>
#include <string>
#include "chatgui.h"

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

/**
 * @class ChatLogic
 * @brief Central controller for the answer graph and chatbot behavior.
 *
 * Owns the graph nodes, holds non-owned pointers to the current node,
 * the ChatBot, and the UI panel. Loads the graph from a file, routes
 * user messages to the chatbot, and sends responses and images to the UI.
 */
class ChatLogic
{
private:
    //// STUDENT CODE
    ////

    /** @brief Owned graph nodes. */
    std::vector<std::unique_ptr<GraphNode>> _nodes;


    ////
    //// EOF STUDENT CODE

    /** @brief Current node in the conversation. Not owned. */
    GraphNode *_currentNode;
    /** @brief ChatBot instance. Not owned. */
    ChatBot *_chatBot;
    /** @brief UI panel for dialog. Not owned. */
    ChatBotPanelDialog *_panelDialog;

    /** @brief Type for token pairs (e.g. ID, value) when parsing graph file. */
    typedef std::vector<std::pair<std::string, std::string>> tokenlist;

    /**
     * @brief Adds all tokens with given ID to the element.
     * @tparam T Element type with AddToken(string).
     * @param tokenID Token identifier to match.
     * @param tokens List of (id, value) pairs.
     * @param element Target element to add tokens to.
     */
    template <typename T>
    void AddAllTokensToElement(std::string tokenID, tokenlist &tokens, T &element);

public:
    /** @brief Default constructor. */
    ChatLogic();
    /** @brief Destructor. */
    ~ChatLogic();

    /** @brief Sets the UI panel handle for sending messages and images. */
    void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
    /** @brief Sets the ChatBot handle. */
    void SetChatbotHandle(ChatBot *chatbot);

    /**
     * @brief Loads the answer graph from a file.
     * @param filename Path to the graph definition file.
     */
    void LoadAnswerGraphFromFile(std::string filename);
    /**
     * @brief Sends a message to the chatbot (user input).
     * @param message User message string.
     */
    void SendMessageToChatbot(std::string message);
    /**
     * @brief Sends a message to the user (chatbot response).
     * @param message Response string to display.
     */
    void SendMessageToUser(std::string message);
    /** @brief Returns the current chatbot avatar image for the UI. */
    wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */
