//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TADOQuery *ADOQuery1;
	TLabel *Label1;
	TDataSource *DataSource1;
	TImage *Image1;
	TImage *Image2;
	TLabel *Label2;
	TEdit *Edit2;
	TDBGrid *DBGrid1;
	TMemo *Memo1;
	TImage *Image3;
	TMaskEdit *Edit1;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Edit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
