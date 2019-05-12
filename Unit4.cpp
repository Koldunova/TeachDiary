//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Label3Click(TObject *Sender)
{
Memo1->Clear();
	String pas=MaskEdit2->Text;
	if (pas.Length()<9) {
		while (pas.Length()<9)
		{
			pas+="|";
		}
	}
	char ary[3][3];
	int k=1;
	for (int i = 0; i < 3; i++) {       //шифрование
		for (int j=0; j < 3; j++) {
			ary[i][j]=pas[k];
			k++;
		}
	}
	pas="";
	for (int i = 0; i < 3; i++) {         //шифрование
		for (int j=0; j < 3; j++) {
			pas+=ary[j][i];
		}
	}
	Memo1->Lines->Add(pas);
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
	MaskEdit2->Clear();
	Form1->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::MaskEdit2Change(TObject *Sender)
{
	if (MaskEdit2->Text.Length()>9) {
	   String s=MaskEdit2->Text;

		for (int i = 1; i < 10; i++) {
			Label7->Caption=Label7->Caption+s[i];

		}
		MaskEdit2->Text=Label7->Caption;

		Label7->Caption="";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image6Click(TObject *Sender)
{
	MaskEdit2->Clear();
	Form1->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Label4Click(TObject *Sender)
{
MaskEdit2->Clear();
	Form1->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Image2Click(TObject *Sender)
{

Memo1->Clear();
	String pas=MaskEdit2->Text;
	if (pas.Length()<9) {
		while (pas.Length()<9)
		{
			pas+="|";
		}
	}
	char ary[3][3];
	int k=1;
	for (int i = 0; i < 3; i++) {       //шифрование
		for (int j=0; j < 3; j++) {
			ary[i][j]=pas[k];
			k++;
		}
	}
	pas="";
	for (int i = 0; i < 3; i++) {         //шифрование
		for (int j=0; j < 3; j++) {
			pas+=ary[j][i];
		}
	}
	Memo1->Lines->Add(pas);
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
	MaskEdit2->Clear();
	Form1->Show();
	Form4->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

