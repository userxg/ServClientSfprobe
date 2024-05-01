#include "Application.h"
#include "MainFrame.h"


/*which class represents our app
    wx will generate appropriate main function
    create instance of Application
    call OnInit method
*/
wxIMPLEMENT_APP(Application);



bool Application::OnInit()
{
    MainFrame* mainFrame = new MainFrame("C++ GUI");

    mainFrame->SetClientSize(500, 500);
    mainFrame->Center();

    mainFrame->Show();

    //true tells that process should continue
    return true;
}
