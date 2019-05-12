//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::DBComboBox1Change(TObject *Sender)
{
	//ADOQuery1->SQL->Text="Select * FROM " + DBComboBox1->Text;
	//ADOQuery1->
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormCreate(TObject *Sender)
{
/*	ADOQuery1->SQL->Text="Select name_group from [groups]";
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	for (int i = 1; i <= ADOQuery1->RecordCount; i++) {
		ComboBox1->Items->Add(ADOQuery1->FieldByName("name_group")->AsString);
		ADOQuery1->Next();
	}
		*/
		Left=Screen->Width/2-ClientWidth/2;
	Top=Screen->Height/2-ClientHeight/2;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox1Change(TObject *Sender)
{
   // ComboBox1->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image1Click(TObject *Sender)
{
//перасно работает
try{
		String s;
		String ss= CalendarPicker1->Date.DateString();
		for (int i = 1; i <= ss.Length(); i++) {
		if (ss[i]=='.') {
			s+='_';
		}
		else
		{	s+=ss[i];  }
		}

		ADOQuery1->SQL->Text= "ALTER TABLE "+ ComboBox1->Text +" ADD " + s +" integer";
		ADOQuery1->ExecSQL();
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
		ADOQuery1->ExecSQL();
		ADOQuery1->Active=true;
		DBGrid1->Visible=true;
		DBGrid1->Columns->Items[0]->Width = 30;
		DBGrid1->Columns->Items[1]->Width = 70;
		for (int i = 2; i < DBGrid1->Columns->Count; i++) {
			DBGrid1->Columns->Items[i]->Width = 50;
		}
		Image1->Visible=false;
		Image2->Visible=true;
		Image3->Visible=true;
		Image4->Visible=true;
	}
 catch (...)
{
		Label3->Caption="Занятие на такую дату уже создано!";
		Label11->Visible=true;
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
		ADOQuery1->ExecSQL();
		ADOQuery1->Active=true;
		DBGrid1->Visible=true;
		DBGrid1->Columns->Items[0]->Width = 30;
		DBGrid1->Columns->Items[1]->Width = 70;
		for (int i = 2; i < DBGrid1->Columns->Count; i++) {
			DBGrid1->Columns->Items[i]->Width = 50;
		}
		Image2->Visible=false;
		Image1->Visible=true;
		Image3->Visible=true;
		Image4->Visible=true;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image2Click(TObject *Sender)
{
try {
	ADOQuery1->Edit();
	ADOQuery1->Post();
if (Label4->Caption=="okp") {

	// создание ОКР для группы

	ADOQuery1->SQL->Text="Select * FROM "+ ComboBox1->Text;
	ADOQuery1->ExecSQL();

	ADOQuery1->Active=false;
	ADOQuery1->Active = true;

	for (int i = 1 ; i<= ADOQuery1->RecordCount; i++) {
		if (ADOQuery1->FieldByName("ОКР№"+Edit1->Text)->AsInteger <4) {

			Form1->ADOTable1->Append();
			Form1->ADOTable1->FieldByName("name_event")->AsString="Для уч. № " + ADOQuery1->FieldByName("id")->AsString+" в гр. "+ComboBox1->Text+" последний день для ОКР";
			Form1->ADOTable1->FieldByName("day_event")->AsString=CalendarPicker1->Date+14;

			Form1->ADOTable1->Post();
			Form1->ADOTable1->Refresh();
			ADOQuery1->Next();
		}
		else
		{
			ADOQuery1->Next();
		}
	}
    Image3->Visible=true;
	//=============================

}
	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Visible=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[1]->Width = 70;
	for (int i = 2; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Image1->Visible=false;
	Image2->Visible=true;
	Edit1->Clear();
	ADOQuery1->Edit();
	ADOQuery1->Post();
	Image1->Visible=true;
	CalendarPicker1->Visible=true;
	Image2->Visible=false;
	CalendarPicker1->TextHint="выберите дату";
	Image4->Visible=true;
} catch (...) {
 	Label3->Caption="Произошла ошибка при сохранении";
		Label11->Visible=true;
		ADOQuery1->SQL->Text="Select * FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[0]->Width = 70;
	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Panel4->Visible=false;
	Image4->Visible=false;
	Image11->Visible=false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image3Click(TObject *Sender)
{
	Label3->Caption="Номер ОКР";
	Panel2->Visible=true;
	Image12->Visible=true;
	CalendarPicker1->Enabled=false;
    DBGrid1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Panel3Click(TObject *Sender)
{
try{
DBGrid1->Enabled=true;
	CalendarPicker1->Visible=false;
    Image12->Visible=false;
	if (Label3->Caption=="Номер ОКР") {
		ADOQuery1->SQL->Text= "ALTER TABLE "+ ComboBox1->Text +" ADD ОКР№" + Edit1->Text +" INTEGER";
		//тута мы добавляем столбец с окр для группы
		ADOQuery1->ExecSQL();
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
		ADOQuery1->ExecSQL();
		ADOQuery1->Active=true;
		DBGrid1->Visible=true;
		//тут мы добавляем дату в таблицу окр
		String date_of_okr="";
		//тута точечки меняем
		String date_of_okr_with_toch=CalendarPicker1->Date;
		for (int i =1; i <= date_of_okr_with_toch.Length(); i++) {
			if (date_of_okr_with_toch[i]=='.') {
				date_of_okr+='_';
			}
			else
			{
				date_of_okr+=date_of_okr_with_toch[i];
			}
		}
		Label5->Caption=date_of_okr_with_toch;

		//ЧТО БЫ У ВАС ОКР БЫЛИ ПО НОМЕРАМ НОРМАЛЬНО
		
		Image1->Visible=false;
		Panel2->Visible=false;
		Label4->Caption="okp";
		ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
		ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Visible=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[1]->Width = 70;
	for (int i = 2; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Image1->Visible=false;
	Image2->Visible=true;
	Image1->Visible=false;
	Image3->Visible=false;
	Image4->Visible=false;
	}
}
catch (...)
{
	Edit1->Text="Такая контрольная уже есть";
	ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Visible=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[1]->Width = 70;
	for (int i = 2; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}

}


}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit1Change(TObject *Sender)
{
	if (Edit1->Text.Length()>0 && Edit1->Text!="Такая контрольная уже есть") {
		Panel3->Visible=true;
	}
	else
	{
		Panel3->Visible=false;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Image7Click(TObject *Sender)
{
	Form8->Hide();
	Form1->Show();
	Image1->Visible=false;
	Image2->Visible=false;
	Image3->Visible=false;
	Image4->Visible=false;
	Image5->Visible=false;
	//Image6->Visible=false;
	CalendarPicker1->Visible=false;
	Label2->Visible=false;
    DBGrid1->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm8::CalendarPicker1Change(TObject *Sender)
{
	Label11->Visible=false;
	Image1->Visible=true;
	Image2->Visible=true;
	Image3->Visible=true;
	Image5->Visible=true;


}
//---------------------------------------------------------------------------




void __fastcall TForm8::Image4Click(TObject *Sender)
{
	Image12->Visible=true;
	Panel4->Visible=true;
    Panel4->Height=160;

}
//---------------------------------------------------------------------------


void __fastcall TForm8::Image9Click(TObject *Sender)
{
try {
Image3->Visible=false;
//s_mark
	//end_group
	//ADOConnection.GetTableNames(ListBox.Items);
	Form1->ADOConnection1->GetFieldNames(ComboBox1->Text,ListBox1->Items);

	int sum=0;
	int k=0;

	ADOQuery1->SQL->Text="ALTER TABLE " + ComboBox1->Text + " ADD sem_mark float ";
	ADOQuery1->ExecSQL();
	Image12->Visible=false;
		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();

	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="Select * FROM "+ ComboBox1->Text;
	ADOQuery1->Active=false;
	ADOQuery1->Active=true;


	Double sr[100];
	 ADOQuery1->First();

	for (int i = 1; i <= ADOQuery1->RecordCount; i++) {
		for (int j = 0; j < ListBox1->Items->Count; j++) {
			if (ListBox1->Items->Strings[j]!="id" && ListBox1->Items->Strings[j]!="ФИО" && ListBox1->Items->Strings[j]!="Ссылка" ) {
				if (ADOQuery1->FieldByName(ListBox1->Items->Strings[j])->AsString!="") {
					sum+=ADOQuery1->FieldByName(ListBox1->Items->Strings[j])->AsInteger;
					k++;
				}
			}
		}

		sr[i]=(sum*1.0)/k;

		k=0;
		sum=0;
		ADOQuery1->Next();
	}

	k= ADOQuery1->RecordCount;
	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="Select * FROM "+ComboBox1->Text;
	ADOQuery1->Active=false;
	ADOQuery1->Active = true;
	ADOTable1->Active=false;
	ADOTable1->TableName=ComboBox1->Text;
	ADOTable1->Active=true;
	for (int i = 1; i <= k; i++) {
		ADOTable1->Edit();
		ADOTable1->FieldByName("sem_mark")->AsFloat=int(sr[i]);
		ADOTable1->Post();
		ADOTable1->Next();
	}
	//====

	ADOQuery1->SQL->Text="Select * FROM end_group";
	ADOQuery1->Active=true;
	ADOQuery1->Insert();
	ADOQuery1->FieldByName("name_group")->AsString=ComboBox1->Text;
	ADOQuery1->Post();

	//====
	ADOQuery1->SQL->Text="Select * FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[0]->Width = 70;
	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Panel4->Visible=false;
	Image4->Visible=false;
	Image11->Visible=false;
} catch (...) {
Label3->Caption="Произошла ошибка при подсчете";
Label3->Visible=true;
ADOQuery1->SQL->Text="Select * FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[0]->Width = 70;
	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Panel4->Visible=false;
	Image4->Visible=false;
	Image11->Visible=false;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image10Click(TObject *Sender)
{
Image12->Visible=false;
	Panel4->Visible=false;
	Panel4->Height=160;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image8Click(TObject *Sender)
{
if (Panel4->Height==160) {
	Panel4->Height=200;
	MaskEdit1->Clear();
}



}
//---------------------------------------------------------------------------

void __fastcall TForm8::Image11Click(TObject *Sender)
{
try {
Image3->Visible=false;
//создать таблицу новую
	Image2->Visible=false;
	String str=MaskEdit1->Text;
	String str1="";
	if (str[5]!='_') {
		for (int i = 1; i <= MaskEdit1->Text.Length(); i++) {
		if (i==5) {
			str1+='_';
		}
		else
		{
			str1+=str[i];
        }
		}
	}


	ADOQuery1->Close();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="CREATE TABLE "+str1+" (id AutoIncrement PRIMARY KEY, ФИО varchar,Ссылка varchar)";
	ADOQuery1->ExecSQL();
	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Text="SELECT * FROM groups";
	ADOQuery1->Active=true;
	ADOQuery1->ExecSQL();
	ADOQuery1->Insert();
	ADOQuery1->FieldByName("name_group")->AsString=str1;
	ADOQuery1->Post();
	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="INSERT INTO "+str1+" (ФИО, Ссылка) SELECT ФИО, Ссылка FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
		//s_mark
	//end_group
	//ADOConnection.GetTableNames(ListBox.Items);
	Form1->ADOConnection1->GetFieldNames(ComboBox1->Text,ListBox1->Items);

	int sum=0;
	int k=0;

	ADOQuery1->SQL->Text="ALTER TABLE " + ComboBox1->Text + " ADD sem_mark float ";
	ADOQuery1->ExecSQL();

		ADOQuery1->Close();
		ADOQuery1->SQL->Clear();

	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="Select * FROM "+ ComboBox1->Text;
	ADOQuery1->Active=false;
	ADOQuery1->Active=true;


	Double sr[100];
	 ADOQuery1->First();

	for (int i = 1; i <= ADOQuery1->RecordCount; i++) {
		for (int j = 0; j < ListBox1->Items->Count; j++) {
			if (ListBox1->Items->Strings[j]!="id" && ListBox1->Items->Strings[j]!="ФИО" && ListBox1->Items->Strings[j]!="Ссылка" ) {
				if (ADOQuery1->FieldByName(ListBox1->Items->Strings[j])->AsString!="") {
					sum+=ADOQuery1->FieldByName(ListBox1->Items->Strings[j])->AsInteger;
					k++;
				}
			}
		}

		sr[i]=(sum*1.0)/k;

		k=0;
		sum=0;
		ADOQuery1->Next();
	}

	k= ADOQuery1->RecordCount;
	ADOQuery1->Active=false;
	ADOQuery1->SQL->Text="Select * FROM "+ComboBox1->Text;
	ADOQuery1->Active=false;
	ADOQuery1->Active = true;
	ADOTable1->Active=false;
	ADOTable1->TableName=ComboBox1->Text;
	ADOTable1->Active=true;
	for (int i = 1; i <= k; i++) {
		ADOTable1->Edit();
		ADOTable1->FieldByName("sem_mark")->AsFloat=int(sr[i]);
		ADOTable1->Post();
		ADOTable1->Next();
	}
	//====

	ADOQuery1->SQL->Text="Select * FROM end_group";
	ADOQuery1->Active=true;
	ADOQuery1->Insert();
	ADOQuery1->FieldByName("name_group")->AsString=ComboBox1->Text;
	ADOQuery1->Post();

	//====
	ADOQuery1->SQL->Text="Select * FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[0]->Width = 70;
	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Panel4->Visible=false;
	Image4->Visible=false;
	Image11->Visible=false;
} catch (...) {
Label1->Caption="Произошла ошибка при подсчете";
Label1->Visible=true;
ADOQuery1->SQL->Text="Select * FROM " + ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[0]->Width = 70;
	for (int i = 1; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}
	Panel4->Visible=false;
	Image4->Visible=false;
	Image11->Visible=false;

}

}
//---------------------------------------------------------------------------


void __fastcall TForm8::ComboBox1Click(TObject *Sender)
{

     	ADOQuery1->Close();
	ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
	ADOQuery1->ExecSQL();
	DBGrid1->Visible=true;
	ADOQuery1->SQL->Text="Select * from end_group";
	ADOQuery1->Active=true;
	int f=0;
	for (int i = 1; i <= ADOQuery1->RecordCount; i++) {
			if (ComboBox1->Text==ADOQuery1->FieldByName("name_group")->AsString) {
			f=1;


		}

		ADOQuery1->Next();
	}
	ADOQuery1->SQL->Text="Select * from "+ComboBox1->Text;
	ADOQuery1->ExecSQL();
	ADOQuery1->Active=true;
	DBGrid1->Columns->Items[0]->Width = 30;
	DBGrid1->Columns->Items[1]->Width = 70;
	for (int i = 2; i < DBGrid1->Columns->Count; i++) {
		DBGrid1->Columns->Items[i]->Width = 50;
	}

	Image4->Visible=true;

	Image7->Visible=true;
	CalendarPicker1->Visible=true;
	Label2->Visible=true;
	if (f==1) {
		Label2->Visible=false;
				Image1->Visible=false;
				Image2->Visible=false;
				Image3->Visible=false;
				Image4->Visible=false;
				CalendarPicker1->Visible=false;
	}
	else
		{
				Image4->Visible=true;
                 	Image3->Visible=true;
				Image7->Visible=true;
				CalendarPicker1->Visible=true;
				Label2->Visible=true;
		}

}
//---------------------------------------------------------------------------

void __fastcall TForm8::DBGrid1CellClick(TColumn *Column)
{
String put = "\"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe\"";
String link="";
	if (DBGrid1->SelectedIndex==2) {
		link=ADOQuery1->FieldByName("Ссылка")->AsString;
		ShellExecute(0, L"open", put.c_str(),link.c_str(), NULL, SW_SHOWNORMAL);

	}


}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit1Click(TObject *Sender)
{
	Edit1->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Image13Click(TObject *Sender)
{
	Image12->Visible=false;
	Panel2->Visible=false;
	CalendarPicker1->Enabled=true;
	DBGrid1->Enabled=true;
}
//---------------------------------------------------------------------------

