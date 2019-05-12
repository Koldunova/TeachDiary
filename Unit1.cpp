//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
	ADOConnection1->Connected = false;
	String Path = ExtractFilePath(ParamStr(0)) + "Baze1.mdb";
	ADOConnection1->ConnectionString = String().sprintf(L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=%s;Persist Security Info=False;", Path);
	ADOConnection1->Connected = true;
	ADOTable1->Active=true;

    //события
	Label1->Caption=Date();
	ADOTable1->Filtered=false;
   ADOTable1->Filter="day_event LIKE "  + Label1->Caption   ;
   ADOTable1->Filtered=true;
	 //расписание

	Label3->Caption="День недели";

	int Day = DayOfWeek(Date());
	switch (Day) {
		case 2:
			Label3->Caption="Понедельник";
				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("monday")->AsString);
			break;
		case 3:
			Label3->Caption="Вторник";
			ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thuesday")->AsString);
			break;
		case 4:
			Label3->Caption="Среда";
			ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("wednesday")->AsString);
			break;
		case 6:
			Label3->Caption="Пятница";
				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("friday")->AsString);
			break;
		case 5:
			Label3->Caption="Четверг";
			ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thursday")->AsString);
			break;
		case 7:
			Label3->Caption="Суббота";

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("suturday")->AsString);

			break;

	default:
        Label3->Caption="Воскресенье";
		;
	}
//Дундук найди вариант проще!
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image11Click(TObject *Sender)
{
	Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
	Form1->Hide();
	Form6->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image2Click(TObject *Sender)
{


	ListBox3->Clear();
	String da=Label3->Caption ;
	if (da=="Понедельник")      {
			Label3->Caption= "Вторник";
		   ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thuesday")->AsString);

	}
	if (da=="Вторник"){
			Label3->Caption= "Среда";
			ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("wednesday")->AsString);
			}
	if (da=="Среда"){
			Label3->Caption= "Четверг";
            	Label3->Caption="Четверг";
			ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thursday")->AsString);
			}
	if (da=="Четверг") {
			Label3->Caption= "Пятница";
	 ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("friday")->AsString);

	}
	if (da=="Пятница") {
			Label3->Caption= "Суббота";
			ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("suturday")->AsString);

	}
	if (da=="Суббота"){
			Label3->Caption= "Воскресенье";


	}


	if (da=="Воскресенье") {
			Label3->Caption= "Понедельник";
			ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("monday")->AsString);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)

{



ListBox3->Clear();
	String da=Label3->Caption ;
	if (da=="Среда")      {
			Label3->Caption= "Вторник";
		   ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thuesday")->AsString);

				ADOQuery1->SQL->Text="Select thuesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thuesday")->AsString);

	}
	if (da=="Четверг"){
			Label3->Caption= "Среда";
			ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("wednesday")->AsString);

				ADOQuery1->SQL->Text="Select wednesday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("wednesday")->AsString);
			}
	if (da=="Пятница"){
			Label3->Caption= "Четверг";
            	Label3->Caption="Четверг";
			ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("thursday")->AsString);

				ADOQuery1->SQL->Text="Select thursday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("thursday")->AsString);
			}
	if (da=="Суббота") {
			Label3->Caption= "Пятница";
	 ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("friday")->AsString);

				ADOQuery1->SQL->Text="Select friday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("friday")->AsString);

	}
	if (da=="Воскресенье") {
			Label3->Caption= "Суббота";
			ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("suturday")->AsString);

				ADOQuery1->SQL->Text="Select suturday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("suturday")->AsString);

	}
	if (da=="Понедельник"){
			Label3->Caption= "Воскресенье";


	}


	if (da=="Вторник") {
			Label3->Caption= "Понедельник";
			ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=1" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(0,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=2" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(1,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=3" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(2,ADOQuery1->FieldByName("monday")->AsString);

				ADOQuery1->SQL->Text="Select monday FROM [timetable] where lesson=4" ;
				ADOQuery1->Active=true;
				ListBox3->Items->Insert(3,ADOQuery1->FieldByName("monday")->AsString);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Label4->Caption = Date();
Label5->Caption =Time();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image7Click(TObject *Sender)
{
	Memo1->Clear();
	Memo1->Lines->LoadFromFile("all_pack\\pers_inf.txt");
	String l= Memo1->Lines->Text;
	if (l[1]=='0') {
		Form4->Show();
		Form4->MaskEdit2->Clear();
		Form1->Hide();
	}else
	{
		Form3->Show();
		Form3->MaskEdit1->Clear();
		Form3->MaskEdit2->Clear();
		Form1->Hide();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
	Form5->Show();
	Form1->Hide();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image5Click(TObject *Sender)
{
	Label1->Caption=Date()+1;
	ADOTable1->Filtered=false;
   ADOTable1->Filter="day_event LIKE "  + Label1->Caption   ;
   ADOTable1->Filtered=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12Click(TObject *Sender)
{
	Label1->Caption=Label1->Caption.ToInt()-1;
	ADOTable1->Filtered=false;
   ADOTable1->Filter="day_event LIKE "  + Label1->Caption   ;
   ADOTable1->Filtered=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CalendarPicker1Change(TObject *Sender)
{
ADOTable1->Filtered=false;
   ADOTable1->Filter="day_event LIKE "  + CalendarPicker1-> Date ;
   ADOTable1->Filtered=true;
   Label1->Caption=CalendarPicker1-> Date;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
	Form7->Show();
    Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
	Form8->Show();
	Form1->Hide();

    Form8->ComboBox1->Clear();
	Form8->ADOQuery1->SQL->Text="Select name_group from [groups]";
	Form8->ADOQuery1->ExecSQL();
	Form8->ADOQuery1->Active=true;
	for (int i = 1; i <= Form8->ADOQuery1->RecordCount; i++) {
		Form8->ComboBox1->Items->Add(Form8->ADOQuery1->FieldByName("name_group")->AsString);
		Form8->ADOQuery1->Next();
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
    Form9->Show();
}
//---------------------------------------------------------------------------

