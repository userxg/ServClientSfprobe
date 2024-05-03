#include "MainFrame.h"

/* 
1. must be positive
2. not 0 or 1
3. not from 4999 to 5999
*/


//define it for mainFrame




MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//if frame has one child, this child fill all space
	wxPanel* panel = new wxPanel(this);
	
	wxButton* button_1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50));
	wxButton* button_2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	//propogation goes up until reach handler,  childs emit event up to final parent who has handle
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

	button_1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button_2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
	CreateStatusBar();
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt)
{
	wxLogMessage("Button Clicked");
}

void MainFrame::OnButton1Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 1 Clicked");
	//propogation should continue going up 
	evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 2 Clicked");

	evt.Skip();
}

void MainFrame::OnClose(wxCloseEvent& evt)
{
	wxLogMessage("Frome Closed");
	evt.Skip();
}

 
