//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TImage *Image2;
	TTimer *Timer1;
	TLabel *Label6;
	TMaskEdit *MaskEdit1;
	TImage *Image1;
	TImage *Image3;
	TMemo *Memo1;
	TLabel *Label7;
	TImage *Image4;
	TImage *Image5;
	TImage *Image6;
	TLabel *Label1;
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall MaskEdit1Click(TObject *Sender);
	void __fastcall Image3Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall MaskEdit1Change(TObject *Sender);
	void __fastcall Image5Click(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
