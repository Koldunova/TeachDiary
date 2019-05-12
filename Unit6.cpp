//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Image2Click(TObject *Sender)
{
	Form6->Hide();
	Form1->Show();
   	Edit1->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TForm6::Image1Click(TObject *Sender)
{
	if (CalendarPicker1->Date!="0:00:00") {
        Form1->ADOTable1->Append();
		Form1->ADOTable1->FieldByName("name_event")->AsString=Edit1->Text;
		Form1->ADOTable1->FieldByName("day_event")->AsString=CalendarPicker1-> Date;
		Form1->ADOTable1->Post();
		Panel2->Visible=true;
		Form1->ADOTable1->Refresh();
		Panel2->Caption=" Событие сохранено, нажмите для продолжения";
	}
	else
	{
		Panel2->Caption=" Выберите день, нажмите для продолжения";
        Panel2->Visible=true;
	}
	Image3->Visible=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm6::Panel2Click(TObject *Sender)
{
	Edit1->Clear();
	Panel2->Visible=false;
	Image3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormCreate(TObject *Sender)
{
Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

