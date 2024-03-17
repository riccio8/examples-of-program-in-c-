// the code isn't finish yet





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

// Declaration of the main window class
class MyNotepadFrame : public wxFrame {
public:
    MyNotepadFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    // Event handlers
    void OnOpen(wxCommandEvent& event);

    // Other member variables
    wxTextCtrl* textCtrl;
};

// Implementation of the application initialization function
bool MyNotepadApp::OnInit() {
    // Creation of the main window
    MyNotepadFrame* frame = new MyNotepadFrame("My Notepad", wxDefaultPosition, wxSize(800, 600));

    // Display the window
    frame->Show(true);

    return true;
}

// Implementation of the main window constructor
MyNotepadFrame::MyNotepadFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // Creation of the text control
    textCtrl = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

    // Creation of the menu bar
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_OPEN, "&Open...\tCtrl+O");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");

    // Associating the menu bar with the window
    SetMenuBar(menuBar);

    // Event handling for menu items
    Bind(wxEVT_MENU, &MyNotepadFrame::OnOpen, this, wxID_OPEN);
}

// Implementation of the event handler for opening a file
void MyNotepadFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, _("Open File"), "", "", "Text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString filePath = openFileDialog.GetPath();
    wxFile file(filePath);
    if (!file.Open(filePath)) {
        wxLogError("Cannot open file '%s'.", filePath);
        return;
    }

    wxString fileContent;
    if (file.ReadAll(&fileContent)) {
        textCtrl->SetValue(fileContent);
    } else {
        wxLogError("Cannot read file '%s'.", filePath);
    }
}

// Entry point of the application
wxIMPLEMENT_APP(MyNotepadApp);
