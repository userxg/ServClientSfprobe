#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:

	//can be std::string or char array
	MainFrame(const wxString& title);

private:
					//info aboutu event
	void OnAnyButtonClicked(wxCommandEvent& evt);

	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	
	void OnClose(wxCloseEvent& evt);
	
};

