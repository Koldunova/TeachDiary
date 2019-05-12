//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TDataSource *DataSource1;
	TADOQuery *ADOQuery1;
	TDBGrid *DBGrid1;
	TCalendarPicker *CalendarPicker1;
	TLabel *Label2;
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TComboBox *ComboBox1;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TImage *Image7;
	TLabel *Label4;
	TADOTable *ADOTable1;
	TLabel *Label5;
	TListBox *ListBox1;
	TLabel *Label11;
	TImage *Image12;
	TPanel *Panel2;
	TLabel *Label3;
	TEdit *Edit1;
	TPanel *Panel3;
	TPanel *Panel4;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TImage *Image8;
	TImage *Image9;
	TImage *Image10;
	TImage *Image11;
	TLabel *Label10;
	TMaskEdit *MaskEdit1;
	TImage *Image13;
	void __fastcall DBComboBox1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Panel3Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Image7Click(TObject *Sender);
	void __fastcall CalendarPicker1Change(TObject *Sender);
	void __fastcall Image4Click(TObject *Sender);
	void __fastcall Image9Click(TObject *Sender);
	void __fastcall Image10Click(TObject *Sender);
	void __fastcall Image8Click(TObject *Sender);
	void __fastcall Image11Click(TObject *Sender);
	void __fastcall ComboBox1Click(TObject *Sender);
	void __fastcall DBGrid1CellClick(TColumn *Column);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Image13Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
