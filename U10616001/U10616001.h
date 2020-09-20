//---------------------------------------------------------------------------

#ifndef U10616001H
#define U10616001H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GLCtrl.h"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGLBox *GLBox1;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TScrollBar *ScrollBarrx;
        TScrollBar *ScrollBarry;
        TScrollBar *ScrollBarrz;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Labelrx;
        TLabel *Labelry;
        TLabel *Labelrz;
        TScrollBar *ScrollBartx;
        TScrollBar *ScrollBarty;
        TScrollBar *ScrollBartz;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Labeltx;
        TLabel *Labelty;
        TLabel *Labeltz;
        TButton *Buttonr;
        TButton *Buttont;
        TButton *Buttons;
        TScrollBar *ScrollBarsx;
        TScrollBar *ScrollBarsy;
        TScrollBar *ScrollBarsz;
        TLabel *Labelsx;
        TLabel *Labelsy;
        TLabel *Labelsz;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TCheckBox *CheckBoxs;
        TGroupBox *GroupBox4;
        TButton *Buttoni1;
        TButton *Buttoni2;
        TButton *Buttoni3;
        TButton *Buttoni4;
        TButton *Buttoni5;
        TButton *Buttoni6;
        TButton *Buttoni7;
        TButton *Buttoni8;
        TGroupBox *GroupBox5;
        TCheckBox *CheckBoxlr;
        TCheckBox *CheckBoxlg;
        TCheckBox *CheckBoxlb;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox6;
        TRadioButton *RadioBrass;
        TRadioButton *RadioGold;
        TRadioButton *RadioPewter;
        TGroupBox *GroupBox8;
        TRadioButton *RadioLine;
        TRadioButton *RadioFlat;
        TRadioButton *RadioSmooth;
        TButton *Buttoninput;
        TButton *Buttonobj1;
        TButton *Buttonobj2;
        TGroupBox *GroupBox9;
        TRadioButton *Radiovs;
        TRadioButton *Radiovm;
        TRadioButton *Radiodefault;
        TOpenDialog *OD;
        void __fastcall init(TObject *Sender);
        void __fastcall Draw(TObject *Sender);
        void __fastcall Scrollrx(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrollry(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrollrz(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
       
        void __fastcall Btnr(TObject *Sender);
        void __fastcall Scrolltx(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrollty(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrolltz(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Btnt(TObject *Sender);
        void __fastcall Scrollsx(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrollsy(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Scrollsz(TObject *Sender, TScrollCode ScrollCode,
          int &ScrollPos);
        void __fastcall Btns(TObject *Sender);
        void __fastcall Checks(TObject *Sender);
        void __fastcall Buttoni1Click(TObject *Sender);
        void __fastcall Buttoni2Click(TObject *Sender);
        void __fastcall Buttoni3Click(TObject *Sender);
        void __fastcall Buttoni4Click(TObject *Sender);
        void __fastcall Buttoni5Click(TObject *Sender);
        void __fastcall Buttoni6Click(TObject *Sender);
        void __fastcall Buttoni7Click(TObject *Sender);
        void __fastcall Buttoni8Click(TObject *Sender);
        void __fastcall CheckBoxlbClick(TObject *Sender);
        void __fastcall CheckBoxlgClick(TObject *Sender);
        void __fastcall CheckBoxlrClick(TObject *Sender);
        void __fastcall RadioBrassClick(TObject *Sender);
        void __fastcall RadioGoldClick(TObject *Sender);
        void __fastcall RadioPewterClick(TObject *Sender);
        void __fastcall RadiodefaultClick(TObject *Sender);
        void __fastcall RadioLineClick(TObject *Sender);
        void __fastcall RadioFlatClick(TObject *Sender);
        void __fastcall RadioSmoothClick(TObject *Sender);
        void __fastcall RadiovsClick(TObject *Sender);
        void __fastcall RadiovmClick(TObject *Sender);
        void __fastcall ButtoninputClick(TObject *Sender);
        void __fastcall Buttonobj1Click(TObject *Sender);
        void __fastcall Buttonobj2Click(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
