// the code isn't finish yet


#include <wx/wx.h>
#include <wx/notebook.h>


class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY,"Notepad es", wxDefaultPosition, wxSize(400, 300))
    {
        // creare il notebook
        notebook = new wxNotebook(this, wxID_ANY);

        // aggiungiamo una pagina vuota
        notebook->AddPage(new wxPanel(notebook), "Page 1");

        notebook->AddPage(new wxPanel(notebook), "Page 2");

        // creaimo un box sizer per editare il layout
        wxBoxSizer* Sizer = new wxBoxSizer(wxVERTICAL);
        Sizer->Add(notebook, 1, wxEXPAND | wxALL, 5); //aggiungiamo la classe notebook al box sixer così queste impostazioni valgono per la finestra
        SetSizer(Sizer);
    }

private:
    wxNotebook* notebook;
};

class prova : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(prova);

