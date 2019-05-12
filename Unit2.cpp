//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1Click(TObject *Sender)
{
if (Image3->Visible==false) {
	if (Form2->Height==200)
	{
        MaskEdit1->Enabled=true;
		Timer1->Enabled=true;
		Image1->Visible=false;
        Image3->Visible=true;

	}
}

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
while (Form2->Height<284)
{
	Form2->Height+=1;
}
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::MaskEdit1Click(TObject *Sender)
{
	MaskEdit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image3Click(TObject *Sender)
{
	Memo1->Clear();
	String pas=MaskEdit1->Text;
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
	Form1->Show();
    Form2->Height=1;
	Form2->Width=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image2Click(TObject *Sender)
{
	Memo1->Clear();
	Memo1->Lines->Add('0');
	Memo1->Lines->SaveToFile("all_pack\\pers_inf.txt");
   //	Form2->Hide();
	Form1->Show();
	Form2->Height=1;
	Form2->Width=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
	Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;


	Memo1->Clear();
	Memo1->Lines->LoadFromFile("all_pack\\pers_inf.txt");    //debug
	String l= Memo1->Lines->Text;

	int f=0;
	if (l[1]=='-') { //первый запуск
		Label1->Visible=true;
		Label2->Visible=true;
		Label3->Visible=true;
		Label4->Visible=true;
		Label5->Visible=true;
		Image1->Visible=true;
		Image2->Visible=true;
		//Image3->Visible=true;
		f=1;
	}
	if (l[1]=='0') { //без пароля
    	Image6->Visible=true;
		Label1->Visible=true;
		Label1->Caption="Добро пожаловать!";
		Label2->Visible=false;
		Label3->Visible=false;
		Label4->Visible=false;
		Label5->Visible=false;
		Image1->Visible=false;
		Image2->Visible=false;
		Image3->Visible=false;
		Image5->Visible=false;
		Form2->Height=100;

		f=1;

	}
	if (f==0) {      //пароль
		Label1->Visible=true;
		Label1->Caption="Введите пароль";
		Label2->Visible=false;
		Label3->Visible=false;
		Label4->Visible=false;
		Label5->Visible=false;
		Image1->Visible=false;
		Image2->Visible=false;
		Image3->Visible=false;
		Image5->Visible=true;
		//сделать дата время на экране
		MaskEdit1->Top=57;
		MaskEdit1->Left=140;
		Form2->Height=150;
		MaskEdit1->Enabled=true;

	}


}
//---------------------------------------------------------------------------

void __fastcall TForm2::MaskEdit1Change(TObject *Sender)
{
	if (MaskEdit1->Text.Length()>9) {
	   String s=MaskEdit1->Text;

		for (int i = 1; i < 10; i++) {
			Label7->Caption=Label7->Caption+s[i];

		}
		MaskEdit1->Text=Label7->Caption;

		Label7->Caption="";
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image5Click(TObject *Sender)
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

	String rigth_pas;
	for (int i = 1; i < 9; i++) {
		if (pas[i]!='|') {
			rigth_pas+=pas[i];
		}
	}
	if (rigth_pas==MaskEdit1->Text)
	{
		Form1->Show();
	  Form2->Height=1;
	Form2->Width=1;
	}
	else {
		Label1->Caption="Вы неверно ввели пароль";
        Label1->Left=100;
	}
	}

//---------------------------------------------------------------------------

void __fastcall TForm2::Image6Click(TObject *Sender)
{
	Form1->Show();
	Form2->Height=1;
	Form2->Width=1;
}
//---------------------------------------------------------------------------

