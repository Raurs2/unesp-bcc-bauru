unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Buttons,
  Spin, Grids, Menus, LazUTF8;

type

  { TForm1 }

  TForm1 = class(TForm)
    CBP0: TCheckBox;
    CBP1: TCheckBox;
    CBP2: TCheckBox;
    CBP3: TCheckBox;
    CBP4: TCheckBox;
    CBP5: TCheckBox;
    CBF1: TCheckBox;
    CBF10: TCheckBox;
    CBF11: TCheckBox;
    CBF12: TCheckBox;
    CBF13: TCheckBox;
    CBF14: TCheckBox;
    CBF15: TCheckBox;
    CBF0: TCheckBox;
    CBF2: TCheckBox;
    CBF3: TCheckBox;
    CBF4: TCheckBox;
    CBF5: TCheckBox;
    CBF6: TCheckBox;
    CBF7: TCheckBox;
    CBF8: TCheckBox;
    CBF9: TCheckBox;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    GroupBox5: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    MenuItem1: TMenuItem;
    MenuItem2: TMenuItem;
    OpenDialog1: TOpenDialog;
    PopupMenu1: TPopupMenu;
    SaveDialog1: TSaveDialog;
    SpeedButton1: TSpeedButton;
    SpeedButton10: TSpeedButton;
    SpeedButton11: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    SpeedButton7: TSpeedButton;
    SpeedButton8: TSpeedButton;
    SpeedButton9: TSpeedButton;
    SpinEdit1: TSpinEdit;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    procedure CBF0Click(Sender: TObject);
    procedure CBFTodosClick(Sender: TObject);
    procedure CBP0Click(Sender: TObject);
    procedure CBPTodosClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure MenuItem1Click(Sender: TObject);
    procedure MenuItem2Click(Sender: TObject);
    procedure SpeedButton10Click(Sender: TObject);
    procedure SpeedButton11Click(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpeedButton7Click(Sender: TObject);
    procedure SpeedButton8Click(Sender: TObject);
    procedure SpeedButton9Click(Sender: TObject);
    procedure SpinEdit1Exit(Sender: TObject);
    procedure StringGrid1Click(Sender: TObject);
    procedure StringGrid1PrepareCanvas(sender: TObject; aCol, aRow: Integer;
      aState: TGridDrawState);
    procedure StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
      var CanSelect: Boolean);

    private
      { private declarations }
      function LerDadosXYGrade: Boolean;
      procedure AjustePoli(m: Integer);
      procedure Ajuste1;
      procedure Ajuste2;
      procedure Ajuste3;
      procedure Ajuste4;
      procedure Ajuste5;
      procedure Ajuste6;
      procedure Ajuste7;
      procedure Ajuste8;
      procedure Ajuste9;
      procedure Ajuste10;
      procedure Ajuste11;
      procedure Ajuste12;
      procedure Ajuste13;
      procedure Ajuste14;
      procedure Ajuste15;
  public
        { public declarations }
end;

var
  Form1: TForm1;

implementation
{$R *.lfm}
{ TForm1 }
uses
graph, about,
Math, Windows, LCLIntf; // Math, Windows e LCLIntf para usar Power, GetSystemMetrics e OpenDocument
var
EFH, EFV, ESH, ESV: Byte; // Valores para Grade que são diferentes em diferentes versões do Windows
DRH, DCW: Integer;
n: Integer; // Número de pontos dados para Ajustes
aj1, aj2, aj3, aj4, aj5, aj6, aj7, aj8, aj9,
aj10, aj11, aj12, aj13, aj14, aj15: Boolean; // Tipos de Ajustes (Form2)
xGrade, yGrade: array[1..100] of Real;
// Salva Grade em arquivo (somente linhas e colunas selecionadas)
procedure SalvaGrade(Grade: TStringGrid; Linhas, Colunas: Integer; const NomeArquivo: TFileName);
var
f:
TextFile;
i, j: Integer;
begin
AssignFile(f, UTF8ToSys(NomeArquivo));
Rewrite(f);
with Grade do
begin
// Número de Colunas e Linhas
Writeln(f, Colunas);
Writeln(f, Linhas);
// Valores das Caselas
for i := 0 to Colunas-1 do
for j := 0 to Linhas-1 do
Writeln(f, Cells[i, j]);
end;
CloseFile(f);
end;
// Carrega Grade de arquivo (somente linhas e colunas selecionadas)
procedure CarregaGrade(Grade: TStringGrid; var Linhas, Colunas: Integer; const NomeArquivo: TFileName);
var
f: TextFile;
iTmp, i, j: Integer;
strTemp: String;

begin
AssignFile(f, UTF8ToSys(NomeArquivo));
Reset(f);
with Grade do
begin
// Número de Colunas
Readln(f, iTmp);
Colunas := iTmp;
// Número de Linhas
Readln(f, iTmp);
Linhas := iTmp;
// Valores das Caselas
for i := 0 to Colunas-1 do
for j := 0 to Linhas-1 do
begin
Readln(f, strTemp);
Cells[i, j] := strTemp;
end;
end;
CloseFile(f);
end;
procedure TForm1.FormCreate(Sender: TObject);
begin
SpeedButton1.Hint := 'Novo'+#10#10+
'Apaga todos os dados e resultados'+#10+
'para iniciar novo problema de ajuste.';
SpeedButton2.Hint := 'Abrir'+#10#10+
'Permite selecionar arquivo de dados'+#10+
'para preencher a grade dos pontos.';
SpeedButton3.Hint := 'Salvar'+#10#10+
'Permite salvar dados da grade'+#10+
'dos pontos de um problema.';
SpeedButton4.Hint := 'Imprimir'+#10#10+
'Aprenda como imprimir cursando PAW'+#10+
'Programação Avançada para Windows.';
SpeedButton5.Hint := 'Ajuda'+#10#10+
'Apresenta a ajuda do programa'+#10+
'e informações sobre o programa.';
SpeedButton6.Hint := 'Calculadora'+#10#10+
'Precisando de uma calculadora para'+#10+
'ajudar no preenchimento dos dados'+#10+
'ou para conferir os resultados?'+#10#10+
'Cutuque e execute a calculadora do Windows.';
SpeedButton7.Hint := 'Prepara a grade para entrada de dados'+#10#10+
'A grade tem tamanho fixo de 100 linhas.'+#10+
'Cutuque este botão para delimitar a'+#10+
'região da grade para entrada de n pontos.';
SpeedButton8.Hint := 'Ajuste polinomial'+#10#10+
'Calcula os coeficientes dos polinômios'+#10+
'selecionados utilizando os dados da'+#10+
'grade de entrada.';
SpeedButton9.Hint := 'Ajuste polinomial'+#10#10+
'Desenha os gráficos dos polinômios'+#10+
'selecionados e os dados da grade'+#10+
'de entrada.'+#10#10+
'É necessário calcular os coeficientes'+#10+
'dos polinômios antes de desenhar o'+#10+
'gráfico.';
SpeedButton10.Hint := 'Ajuste de funções'+#10#10+
'Calcula os coeficientes das funções'+#10+
'selecionadas utilizando os dados da'+#10+
'grade de entrada.';
SpeedButton11.Hint := 'Ajuste de funções'+#10#10+
'Desenha os gráficos das funções'+#10+
'selecionadas e os dados da grade'+#10+
'de entrada.'+#10#10+
'É necessário calcular os coeficientes'+#10+
'das funções antes de desenhar o'+#10+
'gráfico.';
end;
procedure TForm1.FormShow(Sender: TObject);
var
i: Byte;
begin
//StringGrid1.Visible := False;
//StringGrid1.ColWidths[0] := 32;
// Medidas para moldura e scrollbar da Grade (são diferentes para cada versão do Windows)
EFH := GetSystemMetrics(SM_CYBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME); // Espessura Frame Horizontal
EFV := GetSystemMetrics(SM_CXBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME); // Espessura Frame Vertical
ESH := GetSystemMetrics(SM_CYHSCROLL); // Espessura Scroll Horizontal
ESV := GetSystemMetrics(SM_CXVSCROLL); // Espessura Scroll Vertical
// Medidas da altura da linha e comprimento da coluna de cada casela
// Mesmo definindo os valores no projeto, eles mudam de acordo com a versão do Windows
// Forçar altura da casela ser a mesma em diferentes versões do Windows
StringGrid1.DefaultRowHeight := 20;;
StringGrid2.DefaultRowHeight := 20;;
StringGrid3.DefaultRowHeight := 20;;
DRH := StringGrid1.DefaultRowHeight; // Default Row Height
DCW := StringGrid1.DefaultColWidth;
// Default Col Width
with StringGrid1 do
begin
RowCount := 101;
DefaultColWidth := 80;
ColWidths[0] := 32;
Width := 192+EFH+ESH;
Cells[0,0] := 'i'; Cells[1,0] := 'x(i)'; Cells[2,0] := 'y(i)';
for i := 1 to RowCount-1 do
Cells[0,i] := IntToStr(i);
Visible := True;
end;
with StringGrid2 do
begin
DefaultColWidth := 136;
ColWidths[0] := 52;
ColWidths[1] := 32;
ColWidths[2] := 26;
Width := 518+EFH;
Cells[0,0] := 'Polinômio';
Cells[0,1] := '1';
Cells[0,2] := '2';
Cells[0,3] := '3';
Cells[0,4] := '4';
Cells[0,5] := '5';
Cells[1,0] := 'Grau';
Cells[1,1] := '2';
Cells[1,2] := '3';
Cells[1,3] := '4';
Cells[1,4] := '5';
Cells[1,5] := '6';
Cells[3,0] := 'a[0]';
Cells[4,0] := 'a[1]';

Cells[5,0] := 'a[2]';
Cells[6,0] := 'a[3]';
Cells[7,0] := 'a[4]';
Cells[8,0] := 'a[5]';
Cells[9,0] := 'a[6]';
Cells[10,0] := 'R';
end;
with StringGrid3 do
begin
DefaultColWidth := 136;
ColWidths[0] := 110;
Width := 518+EFH;
Cells[0,0] := 'Equação';
Cells[1,0] := 'a';
Cells[2,0] := 'b';
Cells[3,0] := 'R';
Cells[0,1] := 'y = a+b.x';
Cells[0,2] := 'y = a.b^x';
Cells[0,3] := 'y = a.x^b';
Cells[0,4] := 'y = a.b^(e.x)';
Cells[0,5] := 'y = a.e^(b.x)';
Cells[0,6] := 'y = e^(a+b.x)';
Cells[0,7] := 'y = 1/(a+b.x)';
Cells[0,8] := 'y = x/(a+b.x)';
Cells[0,9] := 'y = 1/(1+e^(a+b.x))';
Cells[0,10] := 'y = 1+a.e^(b.x)';
Cells[0,11] := 'y = a+b.ln(x)';
Cells[0,12] := 'y = a+b/x';
Cells[0,13] := 'y = a/(b+x)';
Cells[0,14] := 'y = a.b/(b+x)';
Cells[0,15] := 'y = a.x/(b+x)';
end;
// Ajustar a grade
SpeedButton7.Click;
end;
procedure SetCheckedState(const CheckBox: TCheckBox; const Check: Boolean) ;
var
onClickHandler: TNotifyEvent;
begin

with CheckBox do
begin
onClickHandler := onClick;
onClick := nil;
Checked := Check;
onClick := onClickHandler;
end;
end;
procedure TForm1.CBP0Click(Sender: TObject);
begin
// Se CBP0 estiver marcado, marcar todos; se estiver desmarcado, desmarcar todos
if CBP0.Checked then
begin
SetCheckedState(CBP1, True); SetCheckedState(CBP2, True); SetCheckedState(CBP3, True);
SetCheckedState(CBP4, True); SetCheckedState(CBP5, True);
end
else
begin
SetCheckedState(CBP1, False); SetCheckedState(CBP2, False); SetCheckedState(CBP3, False);
SetCheckedState(CBP4, False); SetCheckedState(CBP5, False);
end;
end;
procedure TForm1.CBPTodosClick(Sender: TObject);
begin
// Marcar CBP0 se todos estiverem marcados e desmarcar se todos estiverem desmarcados
// Desnecessário - Foi feito só para dar um ar profissional na coisa
if CBP1.Checked and CBP2.Checked and CBP3.Checked and CBP4.Checked and CBP5.Checked then
SetCheckedState(CBP0, True)
else
SetCheckedState(CBP0, False);
end;


procedure TForm1.CBF0Click(Sender: TObject);
begin
// Se CBF0 estiver marcado, marcar todos; se estiver desmarcado, desmarcar todos
if CBF0.Checked then
begin
SetCheckedState(CBF1, True); SetCheckedState(CBF2, True); SetCheckedState(CBF3, True);
SetCheckedState(CBF4, True); SetCheckedState(CBF5, True); SetCheckedState(CBF6, True);
SetCheckedState(CBF7, True); SetCheckedState(CBF8, True); SetCheckedState(CBF9, True);
SetCheckedState(CBF10, True); SetCheckedState(CBF11, True); SetCheckedState(CBF12, True);
SetCheckedState(CBF13, True); SetCheckedState(CBF14, True); SetCheckedState(CBF15, True);
end
else
begin
SetCheckedState(CBF1, False); SetCheckedState(CBF2, False); SetCheckedState(CBF3, False);
SetCheckedState(CBF4, False); SetCheckedState(CBF5, False); SetCheckedState(CBF6, False);
SetCheckedState(CBF7, False); SetCheckedState(CBF8, False); SetCheckedState(CBF9, False);
SetCheckedState(CBF10, False); SetCheckedState(CBF11, False); SetCheckedState(CBF12, False);
SetCheckedState(CBF13, False); SetCheckedState(CBF14, False); SetCheckedState(CBF15, False);
end;
end;
procedure TForm1.CBFTodosClick(Sender: TObject);
begin
// Marcar CBP0 se todos estiverem marcados e desmarcar se todos estiverem desmarcados
// Desnecessário - Foi feito só para dar um ar profissional na coisa
if CBF1.Checked and CBF2.Checked and CBF3.Checked and CBF4.Checked and CBF5.Checked and
CBF6.Checked and CBF7.Checked and CBF8.Checked and CBF9.Checked and CBF10.Checked and
CBF11.Checked and CBF12.Checked and CBF13.Checked and CBF14.Checked and CBF15.Checked then
SetCheckedState(CBF0, True)
else
SetCheckedState(CBF0, False);
end;
procedure TForm1.MenuItem1Click(Sender: TObject);
begin
// Ajuda
if not OpenDocument('AjustesCurvas.chm') then
MessageDlg('Informação','Arquivo de Ajuda'+#10+'AjustesCurvas.chm'+#10+'não foi encontrado',
mtInformation, [mbOk], 0);
end;
procedure TForm1.MenuItem2Click(Sender: TObject);
begin
// Sobre
Form3.ShowModal;
end;
procedure TForm1.SpeedButton1Click(Sender: TObject);
begin
// Novo
// Limpa Grade de pontos dados
StringGrid1.Clean(1,1,2,100,[gzNormal]);
SpinEdit1.Value := 5;
SpeedButton7.Click;
// Limpa Grade de coeficientes dos polinômios
StringGrid2.Clean(3,1,10,5,[gzNormal]);
// Limpa CheckBox de Ajustes Polinimiais;
CBP0.State := cbUnchecked; // Desmarca CBPO
CBP0Click(Self);
// Limpa Grade de coeficientes dos ajustes
StringGrid3.Clean(1,1,3,15,[gzNormal]);
// Limpa CheckBox de Ajustes não Polinomiais;
CBF0.State := cbUnchecked; // Desmarca CBFO
CBF0Click(Self);
end;
procedure TForm1.SpeedButton2Click(Sender: TObject);
var
Linhas, Colunas: Integer;
begin
// Abrir
if OpenDialog1.Execute then
begin
// Limpa Grades e CheckBox acionando o botão Novo
SpeedButton1.Click;
CarregaGrade(StringGrid1, Linhas, Colunas, OpenDialog1.FileName);
n := Linhas-1;
SpinEdit1.Value := n;
SpeedButton7.Click;
end;
end;
// Executa rotina CBP0Click que desmarcará todos
// Executa rotina CBF0Click que desmarcará todos

procedure TForm1.SpeedButton3Click(Sender: TObject);
begin
// Salvar
if SaveDialog1.Execute then
SalvaGrade(StringGrid1, n+1, 3, SaveDialog1.FileName);
end;
procedure TForm1.SpeedButton4Click(Sender: TObject);
begin
// Imprimir
{  
Possibilidades:
- Aprender como imprimir e fazer a rotina;
- Executar uma rotina informando que não foi implementada (ShowMessage, MessageDlg, ...);
- Tirar o botão Imprimir do programa.
Veja o meu programa.
Fiz uma rotina só para você.
  }
end;
procedure TForm1.SpeedButton5Click(Sender: TObject);
begin
// Abrir menu Popup
PopupMenu1.PopUp;
end;
procedure TForm1.SpeedButton6Click(Sender: TObject);
begin
// Calculadora
OpenDocument('Calc.exe');
end;
procedure TForm1.SpeedButton7Click(Sender: TObject);
begin
n := SpinEdit1.Value;
StringGrid1.SetFocus;
StringGrid1.Refresh;
end;
{  
A próxima rotina verifica quais são os polinômios selecionados na grade e executa a rotina necessária para as soluções.
Para cada polinômio selecionado,a rotina de solução é executada, passando como parâmetro o grau do polinômio.
A rotina de solução está no final do programa.
  }
procedure TForm1.SpeedButton8Click(Sender: TObject);
begin
// Ler dados (x,y) da grade, verificar ajustes selecionados e efetuar ajustes
// Verificar se dados de StringGrig1 são válidos
if not LerDadosXYGrade then
Exit;
// Tipos de Ajustes
aj1 := CBP1.Checked; aj2 := CBP2.Checked; aj3 := CBP3.Checked;
aj4 := CBP4.Checked; aj5 := CBP5.Checked;
// Tem ajuste selecionado?
if not aj1 and not aj2 and not aj3 and not aj4 and not aj5 then
begin
MessageDlg('Advertência','Selecione ao menos um tipo de ajuste', mtWarning, [mbOk], 0);
Exit;
end;
// Limpa Grade de coeficientes dos ajustes;
StringGrid2.Clean(3,1,10,5,[gzNormal]);
// Efetua ajustes selecionados
if aj1 then try AjustePoli(2) except StringGrid2.Cells[3,1] := 'Exceção' end;
if aj2 then try AjustePoli(3) except StringGrid2.Cells[3,2] := 'Exceção' end;
if aj3 then try AjustePoli(4) except StringGrid2.Cells[3,3] := 'Exceção' end;
if aj4 then try AjustePoli(5) except StringGrid2.Cells[3,4] := 'Exceção' end;
if aj5 then try AjustePoli(6) except StringGrid2.Cells[3,5] := 'Exceção' end;
end;
{
  
A próxima rotina verifica, na grade, quais são os polinômios que foram calculados e cria o gráfico correspondente.
É longa, mas não passa de repetição para cada polinômio que deve ser desenhado.
            }
procedure TForm1.SpeedButton9Click(Sender: TObject);
var
i: Integer;
TemAjuste: array[0..5] of Boolean;
x, y: array[1..100] of Real;
Xmin, Xmax, DeltaX: Real;
novoX: array[1..101] of Real;
novoN: Integer;
a: array[0..6] of Real;
begin
// Gráficos das funções polinomiais
// Se fôrma de gráficos estiver aberta, fechar
Form2.Close;
// Tem alguma função ajustada? E quais são?
FillChar(TemAjuste,SizeOf(TemAjuste),False);
for i := 1 to 5 do
if (StringGrid2.Cells[3,i] <> '') and (StringGrid3.Cells[3,i] <> 'Exceção') then
begin
TemAjuste[0] := True;
TemAjuste[i] := True;
end;
if not TemAjuste[0] then
begin
MessageDlg('Advertência','Não há curvas ajustadas para desenhar gráficos', mtWarning, [mbOk], 0);
Exit;
end;
// Se tem ajuste, tem dados em xGrade e yGrade
for i := 1 to n do
begin
x[i] := xGrade[i];
y[i] := yGrade[i];
end;
// Traçar gráficos para os ajustes existentes
with Form2 do
begin
// Atribuir cores para as séries (feito na Unit Grafico)
// Limpar gráficos anteriores
// Limpar títulos anteriores
{(feito na Unit Grafico)
(feito na Unit Grafico)}
// (x,y)
with Chart1LineSeries0 do
for i := 1 to n do
AddXY(x[i], y[i]);
// Cálculo de 101 pontos ordenados para desenhar as curvas
Xmin := x[1];
for i := 1 to n do
if x[i] < Xmin then
Xmin := x[i];
Xmax := x[1];
for i := 1 to n do
if x[i] > Xmax then
Xmax := x[i];
DeltaX := (Xmax-Xmin)/100;
for i := 1 to 101 do
novoX[i] := Xmin+(i-1)*DeltaX;
novoN := 101;

// p2(x) = a0 + a1.x + a2.x^2
if TemAjuste[1] then
begin
a[0] := StrToFloat(StringGrid2.Cells[3,1]);
a[1] := StrToFloat(StringGrid2.Cells[4,1]);
a[2] := StrToFloat(StringGrid2.Cells[5,1]);
with Chart1LineSeries1 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a[0]+a[1]*novoX[i]+a[2]*Sqr(novoX[i]));
Title := 'p2(x)';
except
Title := 'p2(x) (Erro)';
end;
end;
// p3(x) = a0 + a1.x + a2.x^2 + a3.x^3
if TemAjuste[2] then
begin
a[0] := StrToFloat(StringGrid2.Cells[3,2]);
a[1] := StrToFloat(StringGrid2.Cells[4,2]);
a[2] := StrToFloat(StringGrid2.Cells[5,2]);
a[3] := StrToFloat(StringGrid2.Cells[6,2]);
with Chart1LineSeries2 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a[0]+a[1]*novoX[i]+a[2]*Sqr(novoX[i])+a[3]*Power(novoX[i],3));
Title := 'p3(x)';
except
Title := 'p3(x) (Erro)';
end;
end;
// p4(x) = a0 + a1.x + a2.x^2 + a3.x^3 + a4.x^4
if TemAjuste[3] then
begin
a[0] := StrToFloat(StringGrid2.Cells[3,3]);
a[1] := StrToFloat(StringGrid2.Cells[4,3]);
a[2] := StrToFloat(StringGrid2.Cells[5,3]);
a[3] := StrToFloat(StringGrid2.Cells[6,3]);
a[4] := StrToFloat(StringGrid2.Cells[7,3]);
with Chart1LineSeries3 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a[0]+a[1]*novoX[i]+a[2]*Sqr(novoX[i])+a[3]*Power(novoX[i],3)+
a[4]*Power(novoX[i],4));
Title := 'p4(x)';
except
Title := 'p4(x) (Erro)';
end;
end;
// p5(x) = a0 + a1.x + a2.x^2 + a3.x^3 + a4.x^4 + a5.x^5
if TemAjuste[4] then
begin
a[0] := StrToFloat(StringGrid2.Cells[3,4]);
a[1] := StrToFloat(StringGrid2.Cells[4,4]);
a[2] := StrToFloat(StringGrid2.Cells[5,4]);
a[3] := StrToFloat(StringGrid2.Cells[6,4]);
a[4] := StrToFloat(StringGrid2.Cells[7,4]);
a[5] := StrToFloat(StringGrid2.Cells[8,4]);
with Chart1LineSeries4 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a[0]+a[1]*novoX[i]+a[2]*Sqr(novoX[i])+a[3]*Power(novoX[i],3)+
a[4]*Power(novoX[i],4)+a[5]*Power(novoX[i],5));
Title := 'p5(x)';
except
Title := 'p5(x) (Erro)';
end;
end;
// p6(x) = a0 + a1.x + a2.x^2 + a3.x^3 + a4.x^4 + a5.x^5 + a6.x^6
if TemAjuste[5] then
begin
a[0] := StrToFloat(StringGrid2.Cells[3,5]);
a[1] := StrToFloat(StringGrid2.Cells[4,5]);
a[2] := StrToFloat(StringGrid2.Cells[5,5]);
a[3] := StrToFloat(StringGrid2.Cells[6,5]);
a[4] := StrToFloat(StringGrid2.Cells[7,5]);
a[5] := StrToFloat(StringGrid2.Cells[8,5]);
a[6] := StrToFloat(StringGrid2.Cells[9,5]);
with Chart1LineSeries5 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a[0]+a[1]*novoX[i]+a[2]*Sqr(novoX[i])+a[3]*Power(novoX[i],3)+
a[4]*Power(novoX[i],4)+a[5]*Power(novoX[i],5)+
a[6]*Power(novoX[i],6));
Title := 'p6(x)';
except
Title := 'p6(x) (Erro)';
end;
end;
Show; // Form2.Show;
end;
end;
{
  
A próxima rotina verifica quais são as funções selecionados na grade e executa as rotinas necessárias para as soluções.
A rotina de solução está no final do programa.
  
}
procedure TForm1.SpeedButton10Click(Sender: TObject);
begin
// Ler dados (x,y) da grade, verificar ajustes selecionados e efetuar ajustes
// Verificar se dados de StringGrig1 são válidos
if not LerDadosXYGrade then
Exit;
// Tipos de Ajustes
aj1 := CBF1.Checked; aj2 := CBF2.Checked; aj3 := CBF3.Checked;
aj4 := CBF4.Checked; aj5 := CBF5.Checked; aj6 := CBF6.Checked;
aj7 := CBF7.Checked; aj8 := CBF8.Checked; aj9 := CBF9.Checked;
aj10 := CBF10.Checked; aj11 := CBF11.Checked; aj12 := CBF12.Checked;
aj13 := CBF13.Checked; aj14 := CBF14.Checked; aj15 := CBF15.Checked;
// Tem ajuste selecionado?
if not aj1 and not aj2 and not aj3 and not aj4 and not aj5 and
not aj6 and not aj7 and not aj8 and not aj9 and not aj10 and
not aj11 and not aj12 and not aj13 and not aj14 and not aj15 then
begin
MessageDlg('Advertência','Selecione ao menos um tipo de ajuste', mtWarning, [mbOk], 0);
Exit;
end;
// Limpa Grade de coeficientes dos ajustes;
StringGrid3.Clean(1,1,3,15,[gzNormal]);
// Efetua ajustes selecionados
if aj1 then try Ajuste1 except StringGrid3.Cells[1,1] := 'Exceção' end;
if aj2 then try Ajuste2 except StringGrid3.Cells[1,2] := 'Exceção' end;
if aj3 then try Ajuste3 except StringGrid3.Cells[1,3] := 'Exceção' end;
if aj4 then try Ajuste4 except StringGrid3.Cells[1,4] := 'Exceção' end;
if aj5 then try Ajuste5 except StringGrid3.Cells[1,5] := 'Exceção' end;
if aj6 then try Ajuste6 except StringGrid3.Cells[1,6] := 'Exceção' end;
if aj7 then try Ajuste7 except StringGrid3.Cells[1,7] := 'Exceção' end;
if aj8 then try Ajuste8 except StringGrid3.Cells[1,8] := 'Exceção' end;
if aj9 then try Ajuste9 except StringGrid3.Cells[1,9] := 'Exceção' end;
if aj10 then try Ajuste10 except StringGrid3.Cells[1,10] := 'Exceção' end;
if aj11 then try Ajuste11 except StringGrid3.Cells[1,11] := 'Exceção' end;
if aj12 then try Ajuste12 except StringGrid3.Cells[1,12] := 'Exceção' end;
if aj13 then try Ajuste13 except StringGrid3.Cells[1,13] := 'Exceção' end;
if aj14 then try Ajuste14 except StringGrid3.Cells[1,14] := 'Exceção' end;
if aj15 then try Ajuste15 except StringGrid3.Cells[1,15] := 'Exceção' end;
end;
{
  
A próxima rotina verifica, na grade, quais são as funções que foram calculadas e cria o gráfico correspondente.
É longa, mas não passa de repetição para cada função que deve ser desenhada.
  
}
procedure TForm1.SpeedButton11Click(Sender: TObject);
var
i: Integer;
TemAjuste: array[0..15] of Boolean;
x, y: array[1..100] of Real;
Xmin, Xmax, DeltaX: Real;
novoX: array[1..101] of Real;
novoN: Integer;
a, b: Real;
begin
// Gráficos das funções não polinomiais
// Se fôrma de gráficos estiver aberta, fechar
Form2.Close;
// Tem alguma função ajustada? E quais são?
FillChar(TemAjuste,SizeOf(TemAjuste),False);
for i := 1 to 15 do
if (StringGrid3.Cells[1,i] <> '') and (StringGrid3.Cells[1,i] <> 'Exceção') then
begin
TemAjuste[0] := True;
TemAjuste[i] := True;
end;
if not TemAjuste[0] then
begin
MessageDlg('Advertência','Não há curvas ajustadas para desenhar gráficos', mtWarning, [mbOk], 0);
Exit;
end;
// Se tem ajuste, tem dados em xGrade e yGrade
for i := 1 to n do
begin
x[i] := xGrade[i];
y[i] := yGrade[i];
end;
// Traçar gráficos para os ajustes existentes
with Form2 do
begin
// Atribuir cores para as séries (feito na Unit Grafico)
// Limpar gráficos anteriores
// Limpar títulos anteriores
{(feito na Unit Grafico)
(feito na Unit Grafico)}
// (x,y)
with Chart1LineSeries0 do
for i := 1 to n do
AddXY(x[i], y[i]);
// Cálculo de 101 pontos ordenados para desenhar as curvas
Xmin := x[1];
for i := 1 to n do
if x[i] < Xmin then
Xmin := x[i];
Xmax := x[1];
for i := 1 to n do
if x[i] > Xmax then
Xmax := x[i];
DeltaX := (Xmax-Xmin)/100;
for i := 1 to 101 do
novoX[i] := Xmin+(i-1)*DeltaX;
novoN := 101;
// y = a + b.x
{(dizem por aí que para reta bastam 2 pontos)}
if TemAjuste[1] then
begin
a := StrToFloat(StringGrid3.Cells[1,1]);
b := StrToFloat(StringGrid3.Cells[2,1]);

with Chart1LineSeries1 do
begin
AddXY(novoX[1], a+b*novoX[1]);
AddXY(novoX[100], a+b*novoX[100]);
Title := 'y = a + b.x';
Legend.Visible := True;
end;
end;
// y = a.b^x
if TemAjuste[2] then
begin
a := StrToFloat(StringGrid3.Cells[1,2]);
b := StrToFloat(StringGrid3.Cells[2,2]);
with Chart1LineSeries2 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*Math.Power(b,novoX[i]));
Title := 'y = a.b^x';
except
Title := 'y = a.b^x (Erro)';
end;
end;
// y = a.x^b
if TemAjuste[3] then
begin
a := StrToFloat(StringGrid3.Cells[1,3]);
b := StrToFloat(StringGrid3.Cells[2,3]);
with Chart1LineSeries3 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*Math.Power(novoX[i],b));
Title := 'y = a.x^b';
except
Title := 'y = a.x^b (Erro)';
end;
end;
// y = a.b^(e.x)
if TemAjuste[4] then
begin
a := StrToFloat(StringGrid3.Cells[1,4]);
b := StrToFloat(StringGrid3.Cells[2,4]);
with Chart1LineSeries4 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*Math.Power(b,(Exp(1)*novoX[i])));
Title := 'y = a.b^(e.x)';
except
Title := 'y = a.b^(e.x) (Erro)';
end;
end;
// y = a.e^(b.x)
if TemAjuste[5] then
begin
a := StrToFloat(StringGrid3.Cells[1,5]);
b := StrToFloat(StringGrid3.Cells[2,5]);
with Chart1LineSeries5 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*Math.Power(Exp(1),(b*novoX[i])));
Title := 'y = a.e^(b.x)';
except
Title := 'y = a.e^(b.x) (Erro)';
end;
end;

// y = e^(a+b.x)
if TemAjuste[6] then
begin
a := StrToFloat(StringGrid3.Cells[1,6]);
b := StrToFloat(StringGrid3.Cells[2,6]);
with Chart1LineSeries6 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], Math.Power(Exp(1),(a+b*novoX[i])));
Title := 'y = e^(a+b.x)';
except
Title := 'y = e^(a+b.x) (Erro)';
end;
end;
// y = 1/(a+b.x)
if TemAjuste[7] then
begin
a := StrToFloat(StringGrid3.Cells[1,7]);
b := StrToFloat(StringGrid3.Cells[2,7]);
with Chart1LineSeries7 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], 1/(a+b*novoX[i]));
Title := 'y = 1/(a+b.x)';
except
Title := 'y = 1/(a+b.x) (Erro)';
end;
end;
// y = x/(a+b.x)
if TemAjuste[8] then
begin
a := StrToFloat(StringGrid3.Cells[1,8]);
b := StrToFloat(StringGrid3.Cells[2,8]);
with Chart1LineSeries8 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], novoX[i]/(a+b*novoX[i]));
Title := 'y = x/(a+b.x)';
except
Title := 'y = x/(a+b.x) (Erro)';
end;
end;
// y = 1/(1+e^(a+b.x))
if TemAjuste[9] then
begin
a := StrToFloat(StringGrid3.Cells[1,9]);
b := StrToFloat(StringGrid3.Cells[2,9]);
with Chart1LineSeries9 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], 1/(1+Math.Power(Exp(1),(a+b*novoX[i]))));
Title := 'y = 1/(1+e^(a+b.x))';
except
Title := 'y = 1/(1+e^(a+b.x)) (Erro)';
end;
end;
// y = 1+a.e^(b.x)
if TemAjuste[10] then
begin
a := StrToFloat(StringGrid3.Cells[1,10]);
b := StrToFloat(StringGrid3.Cells[2,10]);
with Chart1LineSeries10 do
try

Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], 1+a*Math.Power(Exp(1),(b*novoX[i])));
Title := 'y = 1+a.e^(b.x)';
except
Title := 'y = 1+a.e^(b.x) (Erro)';
end;
end;
// y = a+b.ln(x)
if TemAjuste[11] then
begin
a := StrToFloat(StringGrid3.Cells[1,11]);
b := StrToFloat(StringGrid3.Cells[2,11]);
with Chart1LineSeries11 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a+b*Ln(novoX[i]));
Title := 'y = a+b.ln(x)';
except
Title := 'y = a+b.ln(x) (Erro)';
end;
end;
// y = a+b/x
if TemAjuste[12] then
begin
a := StrToFloat(StringGrid3.Cells[1,12]);
b := StrToFloat(StringGrid3.Cells[2,12]);
with Chart1LineSeries12 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a+b/novoX[i]);
Title := 'y = a+b/x';
except
Title := 'y = a+b/x (Erro)';
end;
end;
// y = a/(b+x)
if TemAjuste[13] then
begin
a := StrToFloat(StringGrid3.Cells[1,13]);
b := StrToFloat(StringGrid3.Cells[2,13]);
with Chart1LineSeries13 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a/(b+novoX[i]));
Title := 'y = a/(b+x)';
except
Title := 'y = a/(b+x) (Erro)';
end;
end;
// y = a.b/(b+x)
if TemAjuste[14] then
begin
a := StrToFloat(StringGrid3.Cells[1,14]);
b := StrToFloat(StringGrid3.Cells[2,14]);
with Chart1LineSeries14 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*b/(b+novoX[i]));
Title := 'y = a.b/(b+x)';
except
Title := 'y = a.b/(b+x) (Erro)';
end;
end;

// y = a.x/(b+x)
if TemAjuste[15] then
begin
a := StrToFloat(StringGrid3.Cells[1,15]);
b := StrToFloat(StringGrid3.Cells[2,15]);
with Chart1LineSeries15 do
try
Legend.Visible := True;
for i := 1 to novoN do
AddXY(novoX[i], a*novoX[i]/(b+novoX[i]));
Title := 'y = a.x/(b+x)';
except
Title := 'y = a.x/(b+x) (Erro)';
end;
end;
Show; // Form2.Show;
end;
end;
procedure TForm1.SpinEdit1Exit(Sender: TObject);
begin
SpeedButton7.Click;
end;
procedure TForm1.StringGrid1Click(Sender: TObject);
begin
with StringGrid1 do
begin
if Row > n then
Row := n;
//Refresh;
end;
end;
procedure TForm1.StringGrid1PrepareCanvas(Sender: TObject; aCol, aRow: Integer;
aState: TGridDrawState);
begin
with StringGrid1 do
if (aCol > 0) and (aRow > n) then
Canvas.Brush.Color := $00F0F0F0;
end;
procedure TForm1.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
var CanSelect: Boolean);
begin
if aRow > n then
CanSelect := False;
end;

//Rotinas para solução dos ajustes
function TForm1.LerDadosXYGrade: Boolean;
var
i: Integer;
begin
Result := False;
for i := 1 to n do
try
xGrade[i] := StrToFloat(StringGrid1.Cells[1,i]);
except
MessageDlg('Erro na entrada de dados','Dado inválido para x['+IntToStr(i)+']', mtError, [mbOk], 0);
StringGrid1.Col := 1;
StringGrid1.Row := i;
StringGrid1.SetFocus;
Exit;
end;
for i := 1 to n do
try
yGrade[i] := StrToFloat(StringGrid1.Cells[2,i]);
except
MessageDlg('Erro na entrada de dados','Dado inválido para y['+IntToStr(i)+']', mtError, [mbOk], 0);
StringGrid1.Col := 2;
StringGrid1.Row := i;
StringGrid1.SetFocus;
Exit;
end;
Result := True;
end;
procedure TForm1.AjustePoli(m: Integer);
var
A: array[1..7,1..7] of Real; // Polinômios de no máximo ordem 6
x, b, sy: array[1..7] of Real;
sx: array[1..15] of Real;
i, j, k, nLocal: Integer;
soma, pivo, s: Real;
SomaY, SomaY2, SomaE2, YChapeu, R2: Real;
begin
// Lembre-se que a rotina é chamada com m = grau do polinômio
// Montar matriz A de ordem m+1xm+1 e vetor b de ordem m+1 (nLocal=m+1)
// Resolver sistema A.x = b
// A solução x1, x2, ..., xm+1 são os coeficientes a0, a1, ..., am do polinômio
FillChar(A, SizeOf(A), 0);
FillChar(b, SizeOf(b), 0);
nLocal := m+1;
SomaY2 := 0;
for i:= 0 to 2*m do
begin
     sx[i+1] := 0;
    for j:= 1 to n do
        sx[i+1] := sx[i+1] + Power(xGrade[j], i);
end;
for i := 1 to nLocal do
    for j := 1 to nLocal do
        A[i,j] :=  sx[j+i-1];


for i:= 1 to nLocal do
begin
     sy[i] := 0;
    for j:= 1 to n do
    begin
        if (i=1) then
           SomaY2 := SomaY2 + Power(yGrade[j], 2);
        sy[i] := sy[i] + Power(xGrade[j], i-1)*yGrade[j];
    end;
    b[i] := sy[i];
end;

// Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Montar a matriz A com os somatórios de x (xGrade).
Montar o vetor b com os somatórios de y (yGrade).
Resolver o sistema A.x=b.
A solução x fornece os cosficientes do polinômio.
No meu programa, montei a matriz A triangular superior e copiei os valores para a triangular inferior, já que A é simétrica.
   }
// Matriz simétrica - copiar triangular inferior da superior

// Solução de A.x=b
// Solução por Gauss (triangular superior)
// Triangularização
{  
Calcular a triangularização por Gaus ou efetuar decomposição L.U.
  
// Retrosubstituição
  
Resolver o sistema por retrosubstituição se usou triangularização de Gauss.
Resolver o sistema por substituição e retrosubstituição se usou decomposição L.U.
  
  
A solução x fornece os cosficientes do polinômio.
Armazenar estes valores na grade dos coeficientes do polinômio correspondente.
   }
for i := 1 to nLocal do
StringGrid2.Cells[i+2, m-1] := FloatToStr(x[i]);
// Coeficiente de Determinação
SomaY := 0; SomaE2 := 0;
SomaY := sy[1];

{  
Calcular R2.
Lembre-se de usar os valores xGrade e yGrade.
Armazenar R2 na grade, na linha do polinômio correspondente.
  }
for i:= 1 to n do
begin
    s:= x[1];
    for j:= 1 to m do
        s := s + x[j+1]*Power(xGrade[i], j);
    SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;
R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
StringGrid2.Cells[10, m-1] := FloatToStr(R2);
end;
// Para montar A, usar xGrade e yGrade
// nLocal que é ordem do sistema (m+1)

procedure TForm1.Ajuste1;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
     SomaY2 := 0;
     SomaE2 := 0;
     SomaY := 0;
     nLocal := 2;
   for i:= 1 to nLocal do
    begin
         sy[i] := 0;
        for j:= 1 to n do
        begin
            if (i=1) then
           begin
              SomaY2 := SomaY2 + Power(yGrade[j], 2);
              SomaY := SomaY + yGrade[j];
           end;
              sy[i] := sy[i] + Power(xGrade[j], i-1)*yGrade[j];
        end;
        b[i] := sy[i];
    end;


   for i:= 1 to nLocal+1 do
    begin
         sx[i] := 0;
        for j:= 1 to n do
            sx[i] := sx[i] + Power(xGrade[j], i-1);
    end;
    for i := 1 to nLocal do
        for j := 1 to nLocal do
            A[i,j] :=  sx[j+i-1];
    // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
for i:= 1 to n do
begin
    s:= x[1];
    s := s + x[2]*xGrade[i];
    SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,1] := FloattoStr(x[1]);
Cells[2,1] := FloattoStr(x[2]);
Cells[3,1] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste2;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
     SomaY2 := 0;
     SomaE2 := 0;
     SomaY := 0;
     nLocal := 2;

for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*Ln(yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
x[1] := Exp(x[1]);
x[2] := Exp(x[2]);
SomaE2 := 0;
for i:= 1 to n do
begin
 s:= 0;
 s := s + x[1]*Power(x[2],xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Power(SomaY,2)));

with StringGrid3 do
begin
Cells[1,2] := FloattoStr(x[1]);
Cells[2,2] := FloattoStr(x[2]);
Cells[3,2] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste3;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
 SomaY2 := 0;
 SomaE2 := 0;
 SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(Ln(xGrade[j]), i-1)*Ln(yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(Ln(xGrade[j]), i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
x[1] := Exp(x[1]);

for i:= 1 to n do
begin
 s:= 0;
 s := s + x[1]*Power(xGrade[i], x[2]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,3] := FloattoStr(x[1]);
Cells[2,3] := FloattoStr(x[2]);
Cells[3,3] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste4;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*Ln(yGrade[j]);
     end;
     b[i] := sy[i];
 end;


for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
x[1] := Exp(x[1]);
x[2] := Exp(x[2]/Exp(1));
for i:= 1 to n do
begin
 s := x[1]*Power(x[2],Exp(1)*xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,4] := FloattoStr(x[1]);
Cells[2,4] := FloattoStr(x[2]);
Cells[3,4] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste5;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*Ln(yGrade[j]);
     end;
     b[i] := sy[i];
 end;


for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
x[1] := Exp(x[1]);

for i:= 1 to n do
begin
 s := x[1]*Exp(x[2]*xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,5] := FloattoStr(x[1]);
Cells[2,5] := FloattoStr(x[2]);
Cells[3,5] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste6;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*Ln(yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;
{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }

for i:= 1 to n do
begin
 s := Exp(x[1] + x[2]*xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,6] := FloattoStr(x[1]);
Cells[2,6] := FloattoStr(x[2]);
Cells[3,6] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste7;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2, YMED, res: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
YMED := 0;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*(1/yGrade[j]);
     end;
     b[i] := sy[i];
 end;

YMED := SomaY/n;

for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)

for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }

res := 0;
for i:= 1 to n do
begin
 s := 1/(x[1] + x[2]*xGrade[i]);
 SomaE2 := SomaE2 + Power((s - yGrade[i]), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));


with StringGrid3 do
begin
Cells[1,7] := FloattoStr(x[1]);
Cells[2,7] := FloattoStr(x[2]);
Cells[3,7] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste8;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2, YMED, res: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
YMED := 0;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(1/xGrade[j], i-1)*(1/yGrade[j]);
     end;
     b[i] := sy[i];
 end;

 YMED := SomaY/n;

for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(1/xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
res := 0;

for i:= 1 to n do
begin
 s := xGrade[i]/(x[2] + x[1]*xGrade[i]);
 SomaE2 := SomaE2 + Power((s - yGrade[i]), 2);

end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));


with StringGrid3 do
begin
Cells[1,8] := FloattoStr(x[2]);
Cells[2,8] := FloattoStr(x[1]);
Cells[3,8] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste9;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2, YMED, res: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
YMED := 0;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*(Ln((1/yGrade[j]) - 1));
     end;
     b[i] := sy[i];
 end;


for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
res := 0;
for i:= 1 to n do
begin
 s := 1/(1 + Exp(x[1] + x[2]*xGrade[i]));
 SomaE2 := SomaE2 + Power((s - yGrade[i]), 2);
 //res := res + Power(yGrade[i] - YMED);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,9] := FloattoStr(x[1]);
Cells[2,9] := FloattoStr(x[2]);
Cells[3,9] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste10;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2, YMED, res: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
YMED := 0;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + (yGrade[j]);
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*(Ln(yGrade[j] - 1));
     end;
     b[i] := sy[i];
 end;


for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
res := 0;
x[1] := Ln(x[1]);
for i:= 1 to n do
begin
 s :=  1 + x[1]*Exp(x[2]*xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[j] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));

with StringGrid3 do
begin
Cells[1,10] := FloattoStr(x[1]);
Cells[2,10] := FloattoStr(x[2]);
Cells[3,10] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste11;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(Ln(xGrade[j]), i-1)*(yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(Ln(xGrade[j]), i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;
{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }

for i:= 1 to n do
begin
 s := x[1] + x[2]*Ln(xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,11] := FloattoStr(x[1]);
Cells[2,11] := FloattoStr(x[2]);
Cells[3,11] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste12;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power((1/xGrade[j]), i-1)*(yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(1/xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizar Matriz
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }

for i:= 1 to n do
begin
 s := x[1] + x[2]/xGrade[i];
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
// Ajuste Hiperbólico y = a+b/x
// Ajuste Exponencial y = a+b.ln(x)
// Ajuste Exponencial y = 1+a.e^(b.x)
// Ajuste Hiperbólico y = 1/(1+e^(a+b.x))

Cells[1,12] := FloattoStr(x[1]);
Cells[2,12] := FloattoStr(x[2]);
Cells[3,12] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste13;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2, YMED, res, aux: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
YMED := 0;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*(1/yGrade[j]);
     end;
     b[i] := sy[i];
 end;


for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }
res := 0;
aux := x[1];
x[1] := 1/x[2];
x[2] := aux*x[1];

for i:= 1 to n do
begin
 s := x[1]/(x[2]+xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[j]) - s, 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));

with StringGrid3 do
begin
Cells[1,13] := FloattoStr(x[1]);
Cells[2,13] := FloattoStr(x[2]);
Cells[3,13] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste14;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(xGrade[j], i-1)*(1/yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

x[1] := 1/x[1];
x[2] := x[2]/x[1];

for i:= 1 to n do
begin
 s := (x[1]*x[2])/(x[2]+xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));


with StringGrid3 do
begin
Cells[1,14] := FloattoStr(x[1]);
Cells[2,14] := FloattoStr(x[2]);
Cells[3,14] := FloattoStr(R2);
end;
end;
procedure TForm1.Ajuste15;
var
   A: array[1..3,1..3] of Real;
   x, b, sy: array[1..3] of Real;
   sx: array[1..7] of Real;
   nLocal, i, j, k: Integer;
   SomaY2, SomaE2, SomaY, pivo, soma, s, R2: Real;
begin
SomaY2 := 0;
SomaE2 := 0;
SomaY := 0;
nLocal := 2;
for i:= 1 to nLocal do
 begin
      sy[i] := 0;
     for j:= 1 to n do
     begin
         if (i=1) then
         begin
            SomaY2 := SomaY2 + Power(yGrade[j], 2);
            SomaY := SomaY + yGrade[j];
         end;
         sy[i] := sy[i] + Power(1/xGrade[j], i-1)*(1/yGrade[j]);
     end;
     b[i] := sy[i];
 end;



for i:= 1 to nLocal+1 do
 begin
      sx[i] := 0;
     for j:= 1 to n do
         sx[i] := sx[i] + Power(1/xGrade[j], i-1);
 end;
 for i := 1 to nLocal do
     for j := 1 to nLocal do
         A[i,j] :=  sx[j+i-1];
 // Triangularizando a matriz (Gauss)
for j:=1 to nLocal-1 do
begin
    for i:= j+1 to nLocal do
    begin
       try
         pivo := A[i,j]/A[j,j];
       except
         begin
            MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to nLocal do
       begin
          A[i,k] := A[i,k] - A[j,k]*pivo;
          if(abs(A[i,k]) < 0.000000000000001) then
              A[i,k] := 0;
       end;
       b[i] := b[i] - pivo*b[j];
    end;
end;
//Solução Sistema
    try
       x[nLocal] := b[nLocal]/A[nLocal,nLocal];
    except
    begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := nLocal-1 downto 1 do
    begin
       soma := 0;
       for j := i+1 to nLocal do
       begin
            soma := soma + A[i,j]*x[j];
       end;
       try
         x[i] := (b[i]-soma)/A[i,i];
       except
       begin
         MessageDlg('A matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;

{  
Efetuar o ajuste, calculando a, b e R2.
Armazenar estes valores na grade dos coeficientes da função correspondente.
  }

x[1] := 1/x[1];
x[2] := x[2]*x[1];

for i:= 1 to n do
begin
 s := x[1]*xGrade[i]/(x[2]+xGrade[i]);
 SomaE2 := SomaE2 + Power((yGrade[i] - s), 2);
end;

R2 := 1-(n*SomaE2/(n*SomaY2-Sqr(SomaY)));
with StringGrid3 do
begin
Cells[1,15] := FloattoStr(x[1]);
Cells[2,15] := FloattoStr(x[2]);
Cells[3,15] := FloattoStr(R2);
end;
end;
end.

