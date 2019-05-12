//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
Form2->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Image2Click(TObject *Sender)
{
	Form5->Hide();
    Form1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Image1Click(TObject *Sender)
{
    ADOTable1->Edit();
	ADOTable1->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender)
{
	ADOTable1->Active=true;
	Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

