//---------------------------------------------------------------------------

#include <stdlib.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::Edit2Change(TObject *Sender)
{
if (Edit2->Text!="" && Edit1->Text!="") {
	Edit3->Text=StrToInt(Edit1->Text)-StrToInt(Edit2->Text);
}

}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button1Click(TObject *Sender)
{
	Form2->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Edit1Change(TObject *Sender)
{
    if (Edit2->Text!="" && Edit1->Text!="") {
	Edit3->Text=StrToInt(Edit1->Text)-StrToInt(Edit2->Text);
}
}
//---------------------------------------------------------------------------


void __fastcall TForm9::Image1Click(TObject *Sender)
{
int ch=0;

if (StrToInt(Edit6->Text)<=StrToInt(Edit2->Text)) {

	for (int i = 1; i <= StrToInt(Edit2->Text); i+=StrToInt(Edit4->Text)) {
		ch++;
	}
}
else
{
	ShowMessage("2Семестр");
	for (int i = 1; i <= StrToInt(Edit3->Text)-StrToInt(Edit2->Text); i+=StrToInt(Edit4->Text)) {
		ch++;
	}
	ShowMessage(ch);
}
//второй семестр каникулы
}
//---------------------------------------------------------------------------

