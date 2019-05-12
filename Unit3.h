//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image4;
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TMaskEdit *MaskEdit1;
	TMaskEdit *MaskEdit2;
	TImage *Image6;
	TLabel *Label4;
	TMemo *Memo1;
	TImage *Image2;
	TLabel *Label3;
	TImage *Image5;
	TLabel *Label5;
	TImage *Image3;
	TPanel *Panel1;
	TPanel *Panel2;
	void __fastcall Image6Click(TObject *Sender);
	void __fastcall Label4Click(TObject *Sender);
	void __fastcall Image2Click(TObject *Sender);
	void __fastcall Panel2Click(TObject *Sender);
	void __fastcall Label3Click(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
