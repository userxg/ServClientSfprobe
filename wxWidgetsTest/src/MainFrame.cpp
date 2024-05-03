#include "MainFrame.h"

/* 
1. must be positive
2. not 0 or 1
3. not from 4999 to 5999
*/


//define it for mainFrame




MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS);															
	wxButton* btn2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 100));
	
	panel->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyEvent, this);
	//panel->Bind(wxEVT_KEY_UP, &MainFrame::OnKeyEvent, this);

	//for upper down keys
	//panel->Bind(wxEVT_CHAR, &MainFrame::OnKeyEvent, this);
	
	CreateStatusBar();
}

						//contains 2 methods to get key
void MainFrame::OnKeyEvent(wxKeyEvent& evt)
{
	if (evt.GetKeyCode() == WXK_TAB)
	{
		wxWindow* window = (wxWindow*)evt.GetEventObject();
		window->Navigate();
	}
	//if (evt.GetUnicodeKey() == 'A')
	//	wxLogStatus("A was pressed!");
	//else if (evt.GetUnicodeKey() == '\n')
	//	wxLogStatus("enter was pressed!");

	//return;
	////it returns wxK_NONE if key is not in unicode
	//wxChar key_char = evt.GetUnicodeKey();

	wxLogStatus("key event");
	evt.Skip();

	/*if (key_char == wxKEY_NONE)
	{
		int key_code = evt.GetKeyCode();
		wxLogStatus("key event special: %d", key_code);
	}
	else
	{
		wxLogStatus("key event: %c", key_char);
	}*/
}




 
