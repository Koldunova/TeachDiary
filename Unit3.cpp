//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image6Click(TObject *Sender)
{

    Memo1->Clear();
	Memo1->Lines->Add('0');
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");

	Form1->Show();
	Form3->Hide();
	MaskEdit1->Clear();
	MaskEdit2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label4Click(TObject *Sender)
{
    Memo1->Clear();
	Memo1->Lines->Add('0');
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");

	Form1->Show();
	Form3->Hide();
	MaskEdit1->Clear();
	MaskEdit2->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Image2Click(TObject *Sender)
{
	char ary[3][3];
	Memo1->Clear();
	Memo1->Lines->LoadFromFile("all_pack\\pers_inf.txt");
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
	String pas=Memo1->Lines->Text;
	int k =1;
	for (int i = 0; i < 3; i++) {         //расшифрование
		for (int j=0; j < 3; j++) {
			ary[j][i]=pas[k];
			k++;
		}
	}
	pas="";
	for (int i = 0; i < 3; i++) {         //расшифрование
		for (int j=0; j < 3; j++) {
			pas+=ary[i][j];
		}
	}
	//ShowMessage(pas);
	String rigth_pas;
	for (int i = 1; i < 9; i++) {
		if (pas[i]!='|') {
			rigth_pas+=pas[i];
		}
	}
	if (rigth_pas==MaskEdit1->Text)
	{

		int k=1;
		pas=MaskEdit2->Text;
		if (pas.Length()<9) {
			while (pas.Length()<9)
			{
				pas+="|";
			}
		}
		for (int i = 0; i < 3; i++) {       //шифрование
			for (int j=0; j < 3; j++) {
				ary[i][j]=pas[k];
				k++;
			}
		}
		pas="";
		for (int i = 0; i < 3; i++) {
			//шифрование
			for (int j=0; j < 3; j++) {
				pas+=ary[j][i];
			}

		}
	Memo1->Clear();
	Memo1->Lines->Add(pas);
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
	MaskEdit2->Clear();
	MaskEdit1->Clear();
	}
	else
	{
	//ShowMessage("тут мы");


    Image3->Visible=true;
	Panel1->Visible=true;
	MaskEdit1->Clear();
	MaskEdit2->Clear();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Panel2Click(TObject *Sender)
{
	Image3->Visible=false;

	Panel1->Visible=false;
	Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label3Click(TObject *Sender)
{
	char ary[3][3];
	Memo1->Clear();
	Memo1->Lines->LoadFromFile("all_pack\\pers_inf.txt");
	String pas=Memo1->Lines->Text;
	int k =1;
	for (int i = 0; i < 3; i++) {         //расшифрование
		for (int j=0; j < 3; j++) {
			ary[j][i]=pas[k];
			k++;
		}
	}
	pas="";
	for (int i = 0; i < 3; i++) {         //расшифрование
		for (int j=0; j < 3; j++) {
			pas+=ary[i][j];
		}
	}
	//ShowMessage(pas);
	String rigth_pas;
	for (int i = 1; i < 9; i++) {
		if (pas[i]!='|') {
			rigth_pas+=pas[i];
		}
	}
	if (rigth_pas==MaskEdit1->Text)
	{

		int k=1;
		pas=MaskEdit2->Text;
		if (pas.Length()<9) {
		while (pas.Length()<9)
		{
			pas+="|";
		}
	}
		for (int i = 0; i < 3; i++) {       //шифрование
			for (int j=0; j < 3; j++) {
				ary[i][j]=pas[k];
				k++;
			}
	}
	pas="";
	for (int i = 0; i < 3; i++) {
			//шифрование
		for (int j=0; j < 3; j++) {
			pas+=ary[j][i];
		}

	}
	Memo1->Clear();
	Memo1->Lines->Add(pas);
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
	MaskEdit2->Clear();
	MaskEdit1->Clear();
	}
	else
	{
    Image3->Visible=true;
	Panel1->Visible=true;
    Image6->Visible=true;
	MaskEdit1->Clear();
	MaskEdit2->Clear();
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label5Click(TObject *Sender)
{
	Memo1->Clear();
	Memo1->Lines->Add('0');
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
   //	Form2->Hide();
	Form1->Show();
	Form3->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm3::FormCreate(TObject *Sender)
{
Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

