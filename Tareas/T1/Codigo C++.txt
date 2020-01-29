//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Tarea1.h"


#include <iostream>
#include<string>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLabel"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxTextEdit"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkroom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinOffice2019Colorful"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringtime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinTheBezier"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "cxClasses"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "dxDateRanges"
#pragma link "cxMemo"
#pragma link "cxCurrencyEdit"
#pragma link "cxImage"
#pragma link "dxGDIPlusClasses"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cxButton1Click(TObject *Sender)
{
	int Filas = 0;
	int Columnas = 0;
	AnsiString Linea = "";

	Filas = StrToInt(this -> TexteditA -> Text);
	Columnas = StrToInt(this -> TexteditL -> Text);
	int Matriz[Filas][Columnas];
	this -> Memo -> Clear();


	if(Filas > 0 && Filas <= 20) {
		if(Columnas > 0 && Columnas <= 20) {
				 this -> Memo -> Lines -> Add("Matriz " + IntToStr(Filas) + " X " + IntToStr(Columnas));

				 for(int i = 0;i<Filas;i++) {
					 for(int j = 0;j<Columnas;j++) {
						  if(i == 0 || i == Filas - 1 || j == 0 || j == Columnas - 1) {
							  Matriz[i][j] = 1;
						  } else {
							  Matriz[i][j] = 0;
						  }
					 }
				 }

				 for(int i = 0;i<Filas;i++) {
					 for(int j = 0;j<Columnas;j++) {
						   Linea = Linea + Matriz[i][j];
					 }
					 this -> Memo -> Lines -> Add(Linea);
					 Linea = "";
				 }



		} else {
			 ShowMessage("El Largo Tiene Que Ser Un Número Entre 1 Y 20");
		}
	} else {
		ShowMessage("El Ancho Tiene Que Ser Un Número Entre 1 Y 20");
	}


}
//---------------------------------------------------------------------------