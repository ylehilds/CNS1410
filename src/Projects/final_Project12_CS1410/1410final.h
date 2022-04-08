#include "proj12.h"
class FinalApplication : public wxApp
{
public:
	bool OnInit();
};
class FinalFrame : public wxFrame
{
	DECLARE_EVENT_TABLE()
	wxTextCtrl* txtName;
	wxTextCtrl* txtAddress;
	wxTextCtrl* txtPhone;
	wxTextCtrl* txtTitle;
	wxTextCtrl* txtEmpNumber;
	wxTextCtrl* txtSalary;
	wxTextCtrl* txtWage;
	wxTextCtrl* txtCommission;
	wxListBox* employeeListBox;
	wxArrayString employeeArray;
	vector<Employee*> group;
public:
	FinalFrame(const wxChar *title, int xpos, int ypos, int width, int heigth);
	void on_btnPayroll(wxCommandEvent& event);
	void on_btnLoad(wxCommandEvent &event);
	void on_about(wxCommandEvent& event);
	void on_quit(wxCommandEvent& event);
	void list_select(wxCommandEvent& event);
};
