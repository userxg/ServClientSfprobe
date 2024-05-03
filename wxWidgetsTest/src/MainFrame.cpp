#include "MainFrame.h"

/* 
1. must be positive
2. not 0 or 1
3. not from 4999 to 5999
*/


//define it for mainFrame




MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

	//fix flickering
	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true);

	//mouse movement
	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	
	
}

							//contains info about event, including position
							//it's not a command event it doens't have propogation
void MainFrame::OnMouseEvent(wxMouseEvent& evt)
{
	//wxPoint mousePos = evt.GetPosition();//relative to client
	wxPoint mousePos = wxGetMousePosition();//relative to screen
	mousePos = this->ScreenToClient(mousePos);//relative to obj
	wxString message = wxString::Format("Mouse position: (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}



 
