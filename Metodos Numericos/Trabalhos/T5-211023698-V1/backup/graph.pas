unit graph;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, TAGraph, TASeries;

type

  { TForm2 }

  TForm2 = class(TForm)
    Chart1: TChart;
    Chart1LineSeries0: TLineSeries;
    Chart1LineSeries1: TLineSeries;
    Chart1LineSeries10: TLineSeries;
    Chart1LineSeries11: TLineSeries;
    Chart1LineSeries12: TLineSeries;
    Chart1LineSeries13: TLineSeries;
    Chart1LineSeries14: TLineSeries;
    Chart1LineSeries15: TLineSeries;
    Chart1LineSeries2: TLineSeries;
    Chart1LineSeries3: TLineSeries;
    Chart1LineSeries4: TLineSeries;
    Chart1LineSeries5: TLineSeries;
    Chart1LineSeries6: TLineSeries;
    Chart1LineSeries7: TLineSeries;
    Chart1LineSeries8: TLineSeries;
    Chart1LineSeries9: TLineSeries;
    procedure FormClose(Sender: TObject; var CloseAction: TCloseAction);
    procedure FormCloseQuery(Sender: TObject; var CanClose: boolean);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private

  public

  end;

var
  Form2: TForm2;

implementation
{$R *.lfm}
{ TForm2 }
var
PrimeiraVez: Boolean; // Primeira vez que a fôma é aberta
F2L, F2T: Integer;
// Left e Top da fôrma 2, para abrir na mesma posição em que foi fechada
procedure TForm2.FormCreate(Sender: TObject);
begin
// Controle do local onde a fôrma se localiza
PrimeiraVez := True;
// Atribuir cores para as séries (mais fácil fazer no programa do que no componente)
{
// Escolhidas pela ordem, na palheta de 16 cores, sem considerar se são ou não simpáticas
Chart1LineSeries1.SeriesColor := clMaroon;
Chart1LineSeries3.SeriesColor := clOlive;
Chart1LineSeries5.SeriesColor := clPurple;
Chart1LineSeries7.SeriesColor := clGray;
Chart1LineSeries9.SeriesColor := clRed;
Chart1LineSeries11.SeriesColor := clYellow;
Chart1LineSeries2.SeriesColor := clGreen;
Chart1LineSeries4.SeriesColor := clNavy;
Chart1LineSeries6.SeriesColor := clTeal;
Chart1LineSeries8.SeriesColor := clSilver;
Chart1LineSeries10.SeriesColor := clLime;
Chart1LineSeries12.SeriesColor := clBlue;
Chart1LineSeries13.SeriesColor := clFuchsia; Chart1LineSeries14.SeriesColor := clAqua;
Chart1LineSeries15.SeriesColor := clWhite;
}
// Escolhidas no cubo de cores de http://sacoman.dco.fc.unesp.br/aulas/html/07b.html
Chart1LineSeries1.SeriesColor := $00FFFF00; Chart1LineSeries1.LinePen.Style := psDash;
Chart1LineSeries2.SeriesColor := $00FFCC00;
Chart1LineSeries3.SeriesColor := $00FF9900; Chart1LineSeries3.LinePen.Style := psDash;
Chart1LineSeries4.SeriesColor := $00FF3300;
Chart1LineSeries5.SeriesColor := $003300FF; Chart1LineSeries5.LinePen.Style := psDash;
Chart1LineSeries6.SeriesColor := $009900FF;
Chart1LineSeries7.SeriesColor := $00FF00FF; Chart1LineSeries7.LinePen.Style := psDash;
Chart1LineSeries8.SeriesColor := $00FF0099;
Chart1LineSeries9.SeriesColor := $00FF0033; Chart1LineSeries9.LinePen.Style := psDash;
Chart1LineSeries10.SeriesColor := $00FF3300;
Chart1LineSeries11.SeriesColor := $00FF9900; Chart1LineSeries11.LinePen.Style := psDash;
Chart1LineSeries12.SeriesColor := $00FFFF00;
Chart1LineSeries13.SeriesColor := $0099FF00; Chart1LineSeries13.LinePen.Style := psDash;
Chart1LineSeries14.SeriesColor := $0033FF00;
Chart1LineSeries15.SeriesColor := $0000FF33; Chart1LineSeries15.LinePen.Style := psDash;
// Tamanho da pena
Chart1LineSeries1.LinePen.Width := 2; Chart1LineSeries2.LinePen.Width := 2;
Chart1LineSeries3.LinePen.Width := 2; Chart1LineSeries4.LinePen.Width := 2;
Chart1LineSeries5.LinePen.Width := 2; Chart1LineSeries6.LinePen.Width := 2;
Chart1LineSeries7.LinePen.Width := 2; Chart1LineSeries8.LinePen.Width := 2;
Chart1LineSeries9.LinePen.Width := 2; Chart1LineSeries10.LinePen.Width := 2;
Chart1LineSeries11.LinePen.Width := 2; Chart1LineSeries12.LinePen.Width := 2;
Chart1LineSeries13.LinePen.Width := 2; Chart1LineSeries14.LinePen.Width := 2;
Chart1LineSeries15.LinePen.Width := 2;
// Limpar legendas com traço colorido
Chart1LineSeries1.Legend.Visible := False; Chart1LineSeries2.Legend.Visible := False;
Chart1LineSeries3.Legend.Visible := False; Chart1LineSeries4.Legend.Visible := False;
Chart1LineSeries5.Legend.Visible := False; Chart1LineSeries6.Legend.Visible := False;
Chart1LineSeries7.Legend.Visible := False; Chart1LineSeries8.Legend.Visible := False;
Chart1LineSeries9.Legend.Visible := False; Chart1LineSeries10.Legend.Visible := False;
Chart1LineSeries11.Legend.Visible := False; Chart1LineSeries12.Legend.Visible := False;
Chart1LineSeries13.Legend.Visible := False; Chart1LineSeries14.Legend.Visible := False;
Chart1LineSeries15.Legend.Visible := False;
end;
procedure TForm2.FormShow(Sender: TObject);
begin
if PrimeiraVez then
Exit;
Left := F2L;
Top := F2T;
end;

procedure TForm2.FormCloseQuery(Sender: TObject; var CanClose: boolean);
begin
PrimeiraVez := False;
F2L := Left;
F2T := Top;
CanClose := True;
end;
procedure TForm2.FormClose(Sender: TObject; var CloseAction: TCloseAction);
begin
// Limpar gráficos anteriores
Chart1LineSeries0.Clear; // Pontos
Chart1LineSeries1.Clear; Chart1LineSeries2.Clear; Chart1LineSeries3.Clear; // Curvas
Chart1LineSeries4.Clear; Chart1LineSeries5.Clear; Chart1LineSeries6.Clear;
Chart1LineSeries7.Clear; Chart1LineSeries8.Clear; Chart1LineSeries9.Clear;
Chart1LineSeries10.Clear; Chart1LineSeries11.Clear; Chart1LineSeries12.Clear;
Chart1LineSeries13.Clear; Chart1LineSeries14.Clear; Chart1LineSeries15.Clear;
// Limpar legendas com traço colorido e funções anteriores
Chart1LineSeries1.Legend.Visible := False; Chart1LineSeries2.Legend.Visible := False;
Chart1LineSeries3.Legend.Visible := False; Chart1LineSeries4.Legend.Visible := False;
Chart1LineSeries5.Legend.Visible := False; Chart1LineSeries6.Legend.Visible := False;
Chart1LineSeries7.Legend.Visible := False; Chart1LineSeries8.Legend.Visible := False;
Chart1LineSeries9.Legend.Visible := False; Chart1LineSeries10.Legend.Visible := False;
Chart1LineSeries11.Legend.Visible := False; Chart1LineSeries12.Legend.Visible := False;
Chart1LineSeries13.Legend.Visible := False; Chart1LineSeries14.Legend.Visible := False;
Chart1LineSeries15.Legend.Visible := False;
end;
end.
