#include <wx/wx.h>  // Main header of wxWidgets
#include <wx/textctrl.h>  // For text control
#include <wx/menu.h>  // For menu bar
#include <wx/frame.h>  // For main application window
#include <wx/filedlg.h>  // For file open/save dialog window


// Declaration of the main application class
class MyNotepadApp : public wxApp {
public:
    virtual bool OnInit();
};

// Implementation of the application initialization function
bool MyNotepadApp::OnInit() {
    // Creation of the main window
    wxFrame *frame = new wxFrame(NULL, wxID_ANY, "My Notepad", wxDefaultPosition, wxSize(800, 600));

    // Creation of the text control
    wxTextCtrl *textCtrl = new wxTextCtrl(frame, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    // Creation of the menu bar
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open...\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt+X");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    // Associating the menu bar with the window
    frame->SetMenuBar(menuBar);

    // Display the window
    frame->Show(true);

    return true;
}

// Entry point of the application
wxIMPLEMENT_APP(MyNotepadApp);
