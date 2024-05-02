#include "MainFrame.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	//if frame has one child, this child fill all space
	wxPanel* panel = new wxPanel(this);
	wxButton* buuton = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 35));

	wxCheckBox* chekcBox = new wxCheckBox(panel, wxID_ANY, "CheckBox", wxPoint(250, 50));

	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "sometext sdoifsdoifj", wxPoint(250, 70));

	//-1 default
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable", wxPoint(270, 70), wxSize(200, -1));

	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100, wxPoint(270, 100), wxSize(200, -1));

	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(270, 120), wxSize(200, -1));
	gauge->SetValue(50);


	wxArrayString choices;
	choices.Add("Item A");
	choices.Add("Item B");
	choices.Add("Item C");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(270, 140), wxSize(200, -1), choices);
	choice->Select(0);
	
}
