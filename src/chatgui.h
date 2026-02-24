/**
 * @file chatgui.h
 * @brief Defines the wxWidgets GUI components for the chatbot application.
 */

#ifndef CHATGUI_H_
#define CHATGUI_H_
#include <memory>
#include <wx/wx.h>

class ChatLogic; // forward declaration

/**
 * @class ChatBotPanelDialog
 * @brief Middle part of the window containing the dialog between user and chatbot.
 *
 * Displays the conversation history and owns the ChatLogic instance.
 * Inherits from wxScrolledWindow for scrollable content.
 */
class ChatBotPanelDialog : public wxScrolledWindow
{
private:
    /** @brief Sizer for dialog items. */
    wxBoxSizer *_dialogSizer;
    /** @brief Placeholder/cached image for display. */
    wxBitmap _image;

    //// STUDENT CODE
    ////

    /** @brief Owned ChatLogic controller. */
    std::unique_ptr<ChatLogic> _chatLogic;

    ////
    //// EOF STUDENT CODE

public:
    /**
     * @brief Constructs the dialog panel.
     * @param parent Parent window.
     * @param id Window ID.
     */
    ChatBotPanelDialog(wxWindow *parent, wxWindowID id);
    /** @brief Destructor. */
    ~ChatBotPanelDialog();

    /** @brief Returns the ChatLogic pointer (from unique_ptr). */
    ChatLogic *GetChatLogicHandle() { return _chatLogic.get(); }

    /** @brief Paint event handler. */
    void paintEvent(wxPaintEvent &evt);
    /** @brief Triggers a repaint. */
    void paintNow();
    /** @brief Renders content to the device context. */
    void render(wxDC &dc);

    /**
     * @brief Adds a dialog line (user or chatbot message).
     * @param text Message text.
     * @param isFromUser True if from user, false if from chatbot.
     */
    void AddDialogItem(wxString text, bool isFromUser = true);
    /**
     * @brief Prints a chatbot response in the dialog.
     * @param response Response string.
     */
    void PrintChatbotResponse(std::string response);

    DECLARE_EVENT_TABLE()
};

/**
 * @class ChatBotPanelDialogItem
 * @brief A single dialog item (message bubble) shown in ChatBotPanelDialog.
 *
 * Displays one message with optional chatbot image and text.
 */
class ChatBotPanelDialogItem : public wxPanel
{
private:
    /** @brief Optional chatbot avatar image. */
    wxStaticBitmap *_chatBotImg;
    /** @brief Message text. */
    wxStaticText *_chatBotTxt;

public:
    /**
     * @brief Constructs a dialog item.
     * @param parent Parent panel.
     * @param text Message text.
     * @param isFromUser True if user message, false if chatbot.
     */
    ChatBotPanelDialogItem(wxPanel *parent, wxString text, bool isFromUser);
};

/**
 * @class ChatBotFrame
 * @brief Main frame containing the dialog panel and text input.
 */
class ChatBotFrame : public wxFrame
{
private:
    /** @brief The dialog panel. */
    ChatBotPanelDialog *_panelDialog;
    /** @brief Text control for user input. */
    wxTextCtrl *_userTextCtrl;

    /** @brief Handles Enter key to send message. */
    void OnEnter(wxCommandEvent &WXUNUSED(event));

public:
    /**
     * @brief Constructs the main frame.
     * @param title Window title.
     */
    ChatBotFrame(const wxString &title);
};

/**
 * @class ChatBotFrameImagePanel
 * @brief Panel for displaying the background image in the frame.
 */
class ChatBotFrameImagePanel : public wxPanel
{
    /** @brief Background image. */
    wxBitmap _image;

public:
    /**
     * @brief Constructs the image panel.
     * @param parent Parent frame.
     */
    ChatBotFrameImagePanel(wxFrame *parent);

    /** @brief Paint event handler. */
    void paintEvent(wxPaintEvent &evt);
    /** @brief Triggers a repaint. */
    void paintNow();
    /** @brief Renders the image to the device context. */
    void render(wxDC &dc);

    DECLARE_EVENT_TABLE()
};

/**
 * @class ChatBotApp
 * @brief wxWidgets application class; provides OnInit() instead of main().
 */
class ChatBotApp : public wxApp
{
public:
    /** @brief Initializes the application and shows the main frame. */
    virtual bool OnInit();
};

#endif /* CHATGUI_H_ */
