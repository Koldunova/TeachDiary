//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label2;
	TMaskEdit *MaskEdit2;
	TImage *Image2;
	TLabel *Label3;
	TImage *Image6;
	TLabel *Label4;
	TMemo *Memo1;
	TLabel *Label7;
	void __fastcall Label3Click(TObject *Sender);
	void __fastcall MaskEdit2Change(TObject *Sender);
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Label4Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
