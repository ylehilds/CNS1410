#include <wx/wx.h>
#include "1410final.h"
#include <vector>
#include <iostream>
#include <string>
#include "proj12.h"
using std::string;

void loadArray(vector<Employee*>, wxArrayString);

enum{ID_btnPayroll, ID_btnLoad, ID_about, ID_quit, ID_listSelect};

BEGIN_EVENT_TABLE(FinalFrame, wxFrame)
	EVT_MENU(ID_about, FinalFrame::on_about)
	EVT_MENU(ID_quit, FinalFrame::on_quit)
	EVT_BUTTON(ID_btnPayroll, FinalFrame::on_btnPayroll)
	EVT_BUTTON(ID_btnLoad, FinalFrame::on_btnLoad)
	EVT_LISTBOX(ID_listSelect, FinalFrame::list_select)
END_EVENT_TABLE()

IMPLEMENT_APP(FinalApplication)

bool FinalApplication::OnInit()
{
	FinalFrame *frame = new FinalFrame("Ziggy's Payroll Application", 0, 50, 0, 340);
	frame->Show(true);
	SetTopWindow(frame);
	return TRUE;
}
FinalFrame::FinalFrame(const wxChar *title, int xpos, int ypos, int width, int heigth)
	: wxFrame( ( wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(500, 500))
	{
		wxMenu* menuFile = new wxMenu;
		menuFile->Append(ID_about, "&About...");
		menuFile->AppendSeparator();
		menuFile->Append(ID_quit, "E&xit");
		
		wxMenuBar* menuBar = new wxMenuBar;
		menuBar->Append(menuFile, "&File");
		SetMenuBar(menuBar);
		
		wxPanel* aPanel = new wxPanel(this);
		new wxStaticText(aPanel, wxID_ANY, "Name:", wxPoint(10, 70), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Address:", wxPoint(10, 100), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Phone No:", wxPoint(10, 130), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Job Title:", wxPoint(10, 160), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Emp No:", wxPoint(10, 190), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Salary:", wxPoint(10, 220), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Wage:", wxPoint(10, 250), wxSize(wxDefaultSize));
		new wxStaticText(aPanel, wxID_ANY, "Comm Rate:", wxPoint(10, 280), wxSize(wxDefaultSize));
		
		txtName = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 70), wxSize(150, 20));
		txtAddress = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 100), wxSize(150, 20));
		txtPhone = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 130), wxSize(150, 20));
		txtTitle = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 160), wxSize(150, 20));
		txtEmpNumber = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 190), wxSize(150, 20));
		txtSalary = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 220), wxSize(150, 20));
		txtWage = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 250), wxSize(150, 20));
		txtCommission = new wxTextCtrl(aPanel, wxID_ANY, "", wxPoint(80, 280), wxSize(150, 20));
		
		new wxButton(aPanel, ID_btnPayroll, "Payroll", wxPoint(120, 350), wxSize(50, 30));
		new wxButton(aPanel, ID_btnLoad, "Load", wxPoint(340, 350), wxSize(50, 30));
		
		employeeListBox = new wxListBox(aPanel, ID_listSelect, wxPoint(280,70), wxSize(180, 250),
		0, NULL, wxLB_SINGLE | wxLB_NEEDED_SB);
		CreateStatusBar(3);
		
		ifstream empReader("test.txt");
		while(empReader.good())
		{
			Employee* emp = readEmp(empReader);
			group.push_back(emp);
		}
		empReader.close();
		ifstream hourReader("hoursfile.txt");
		while(hourReader.good())
		{
			assignHours(hourReader, group);
		}
		hourReader.close();
		
		ifstream saleReader("salesfile.txt");
		while(saleReader.good())
		{
			assignAmount(saleReader, group);
		}
		saleReader.close();
		
		wxString anEmployee;
		int size = group.size( );
		for (int i = 0; i < size; i++)
		{
			anEmployee = (group[i]->getName().c_str());
			employeeArray.Add(anEmployee);
		}
	}
void FinalFrame::on_quit(wxCommandEvent& event)
{
	Close(TRUE);
}
void FinalFrame::on_about(wxCommandEvent& event)
{
	wxMessageBox("\nCNS 1400-002\nProgramming Project #12", "About", wxOK | wxICON_INFORMATION);
}
void FinalFrame::on_btnLoad(wxCommandEvent& event)
{
    employeeListBox->Set(employeeArray);
}
void FinalFrame::list_select(wxCommandEvent& event)
{
	wxString na = "Not Applicable";
	txtName->Clear();
	txtAddress->Clear();
	txtPhone->Clear();
	txtTitle->Clear();
	txtEmpNumber->Clear();
	txtSalary->Clear();
	txtWage->Clear();
	txtCommission->Clear();
	wxString textCtrlData;
	textCtrlData.Clear();
    int selectionIndex = employeeListBox->GetSelection( );
	if(dynamic_cast<Sales*>(group[selectionIndex]))
	{
		Sales* salePtr = dynamic_cast<Sales*>(group[selectionIndex]);
		(*txtName) << salePtr->getName().c_str();
		(*txtAddress) << salePtr->getAddress().c_str();
		(*txtPhone) << salePtr->getPhoneNumber().c_str();
		(*txtTitle) << salePtr->getTitle().c_str();
		(*txtEmpNumber) << salePtr->getEmpNumber();
		(*txtSalary) << salePtr->getSalary();
		(*txtWage) << na;
		(*txtCommission) << salePtr->getCommission();
	}
	else if(dynamic_cast<Salaried*>(group[selectionIndex]))
	{
		Salaried* salPtr = dynamic_cast<Salaried*>(group[selectionIndex]);
		(*txtName) << salPtr->getName().c_str();
		(*txtAddress) << salPtr->getAddress().c_str();
		(*txtPhone) << salPtr->getPhoneNumber().c_str();
		(*txtTitle) << salPtr->getTitle().c_str();
		(*txtEmpNumber) << salPtr->getEmpNumber();
		(*txtSalary) << salPtr->getSalary();
		(*txtWage) << na;
		(*txtCommission) << na;
	}
	else if(dynamic_cast<Hourly*>(group[selectionIndex]))
	{
		Hourly* hourPtr = dynamic_cast<Hourly*>(group[selectionIndex]);
		(*txtName) << hourPtr->getName().c_str();
		(*txtAddress) << hourPtr->getAddress().c_str();
		(*txtPhone) << hourPtr->getPhoneNumber().c_str();
		(*txtTitle) << hourPtr->getTitle().c_str();
		(*txtEmpNumber) << hourPtr->getEmpNumber();
		(*txtSalary) << na;
		(*txtCommission) << na;
		(*txtWage) << hourPtr->getHourlyRate();		
	}
}
void FinalFrame::on_btnPayroll(wxCommandEvent& event)
{
	ofstream empWriter;
	empWriter.open("checks.txt");
	for(int i = 0; i < static_cast<int>(group.size()); ++i)
	{
		printEmp(empWriter, group[i]);
	}
	empWriter.close();
	wxMessageBox("Employee's paychecks have been saved to checks.txt", "Payroll", wxOK | wxICON_INFORMATION);
}
