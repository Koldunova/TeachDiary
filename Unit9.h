//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button1;
	TImage *Image1;
	TLabel *Label7;
	TEdit *Edit7;
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
