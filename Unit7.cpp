//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Image1Click(TObject *Sender)
{
if (Edit1->Text!="") {

try {
	String str=Edit1->Text;
	String str1="";
	if (str[5]!='_') {
		for (int i = 1; i <= Edit1->Text.Length(); i++) {
		if (i==5) {
			str1+='_';
		}
		else
		{
			str1+=str[i];
		}
		}
	}
	Edit1->Text=str1;
	Label4->Caption=str1;
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="CREATE TABLE "+str1+ " (id AutoIncrement PRIMARY KEY, ÔÈÎ varchar,Ññûëêà varchar)";
	ADOQuery1->ExecSQL();
	ADOQuery1->SQL->Clear();


	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="SELECT * FROM "+str1;
	ADOQuery1->Active=true;
	ADOQuery1->Insert();

   DBGrid1->Columns->Items[0]->Width = 30;
   DBGrid1->Columns->Items[1]->Width = 200;
   DBGrid1->Columns->Items[2]->Width = 200;
   Image2->Visible=true;
   Image1->Visible=false;
   Image3->Visible=false;
} catch (...) {

	Edit1->Clear();
    Label2->Visible=true;
}
}


}
//---------------------------------------------------------------------------
void __fastcall TForm7::Image2Click(TObject *Sender)
{
try{
	ADOQuery1->Edit();
	ADOQuery1->Post();

	Image1->Visible=true;
	Image2->Visible=false;

	ADOQuery1->SQL->Text="SELECT * FROM groups";
	ADOQuery1->Active=true;
	ADOQuery1->ExecSQL();
	ADOQuery1->Insert();
	ADOQuery1->FieldByName("name_group")->AsString=Label4->Caption;
	ADOQuery1->Post();
	Edit1->Clear();
	Edit2->Clear();
	ADOQuery1->Close();    }

catch (...)
{
    Label3->Visible=true;
}

}
//---------------------------------------------------------------------------
void __fastcall TForm7::Image3Click(TObject *Sender)
{
	Form7->Hide();
	Form1->Show();
	Label3->Visible=false;
	Label2->Visible=false;
	Edit1->Clear();
	Image1->Visible=True;
	Image1->Visible=False;


}
//---------------------------------------------------------------------------





void __fastcall TForm7::Edit1Change(TObject *Sender)
{
	Label2->Visible=false;
  	Label3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormCreate(TObject *Sender)
{
Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::Edit1Click(TObject *Sender)
{
	Label2->Visible=false;
}
//---------------------------------------------------------------------------

