unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Buttons,
  Spin, Grids, TAGraph, TASeries;

type

  { TForm1 }

  TForm1 = class(TForm)
    Chart1: TChart;
    Chart1LineSeries1: TLineSeries;
    Chart1LineSeries2: TLineSeries;
    Chart1LineSeries3: TLineSeries;
    Edit1: TEdit;
    Edit2: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    RadioButton3: TRadioButton;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    StringGrid1: TStringGrid;
    procedure FormShow(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpinEdit1EditingDone(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation
{$R *.lfm}
{ TForm1 }
uses
  about,
  Math, Windows, LCLIntf;
var
  EFH, EFV, ESH, ESV: Byte;
  DRH, DCW: Integer;
  n, m, k: Integer;
  z: Real;
  x, y, c, Delta0y: array[0..20] of Real;
  xAll, yAll: array[0..20] of Real;
  fat: array[0..21] of Integer;
function Fatorial(n: Integer) : Integer;
begin
     if(fat[n] <> 0) then
     begin
          Result := fat[n];
     end
     else Result := n*Fatorial(n-1);
end;
procedure OrdenarDados(n: Integer);
var
  changed: Boolean;
  aux: Real;
  i, j: Integer;
begin
  changed := True;
  j := n-1;
  while changed do
  begin
    changed := False;
    for i := 0 to j do
    if x[i] > x[i+1] then
    begin
      aux := x[i]; x[i] := x[i+1]; x[i+1] := aux;
      aux := y[i]; y[i] := y[i+1]; y[i+1] := aux;
      changed := True;
    end;
    j := j-1;
  end;
end;
function DadosRepetidos(var p, q: Integer): Boolean;
var
   i, j: Integer;
begin
  Result := False;
  for i := 0 to n-1 do
  for j := i+1 to n do
  if x[i] = x[j] then
  begin
    p := i;
    q := j;
    Result := True;
    Exit;
  end;
end;

procedure PontosProximos;
var
  indicies: array[0..20] of Byte;
  distancias: array[0..20] of Real;
  i, j: Integer;
  changed: Boolean;
  auxD: Real;
  auxI: Byte;
begin
  for i := 0 to n do
  begin
    distancias[i] := Abs(z-x[i]);
    indicies[i] := i;
  end;
  changed := True;
  j := n-1;
  while changed do
  begin
    changed := False;
    for i := 0 to j do
    if distancias[i] > distancias[i+1] then
    begin
      auxD := distancias[i]; distancias[i] := distancias[i+1]; distancias[i+1] := auxD;
      auxI:= indicies[i]; indicies[i] := indicies[i+1]; indicies[i+1] := auxI;
      changed := True;
    end;
    j := j-1;
  end;
  FillChar(x, SizeOf(x), 0);
  FillChar(y, SizeOf(y), 0);
  for i := 0 to k do
  begin
    x[i] := xAll[indicies[i]];
    y[i] := yAll[indicies[i]];
  end;
end;
procedure SistemaLinear(Ordem: Integer);
var
  a: array[1..21,1..21] of Real;
  b: array[1..21] of Real;
  xLocal: array[1..21] of Real;
  i, j, k, n: Integer;
  pivo, sum, m: Real;
begin
  n := Ordem+1;
  FillChar(a, SizeOf(a), 0);
  FillChar(b, SizeOf(b), 0);
  FillChar(xLocal, SizeOf(xLocal), 0);
  FillChar(c, SizeOf(c), 0);

  for i := 1 to n do
  begin
    for j:= 1 to n do
    begin
        a[i,j] := Power(x[i-1],(j-1));
    end;
    b[i] := y[i-1];
  end;
for j:=1 to n-1 do
begin
    for i:= j+1 to n do
    begin
       try
         m := a[i,j]/a[j,j];
       except
         begin
            MessageDlg('a matriz tem determinante nulo!',mtInformation, [mbOk], 0);
            Exit;
         end;
       end;
       for k:= j to n do
       begin
          a[i,k] := a[i,k] - a[j,k]*m;
          if(abs(a[i,k]) < 0.000000000000001) then
              a[i,k] := 0;
       end;
       b[i] := b[i] - m*b[j];
    end;
end;
    try
       xLocal[n] := b[n]/a[n,n];
    except
    begin
         MessageDlg('a matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
    end;
    end;
    for i := n-1 downto 1 do
    begin
       sum := 0;
       for j := i+1 to n do
       begin
            sum := sum + a[i,j]*xLocal[j];
       end;
       try
         xLocal[i] := (b[i]-sum)/a[i,i];
       except
       begin
         MessageDlg('a matriz tem determinante nulo!',mtInformation, [mbOk], 0);
         Exit;
       end;
       end;
    end;
  for i := 1 to n+1 do
      c[i-1] := xLocal[i];
end;
procedure Newton(Ordem: Integer);
var
i, j, n: Integer;
Deltay: array[0..21, 0..21] of Real;
begin
n := Ordem;
  for j:=0 to n do
  begin
    for i:= 0 to n-j do
    begin
      if (j=0) then
      begin
      Deltay[i][j] := y[i];
      end
      else
      begin
         Deltay[i][j] := (Deltay[i+1][j-1] - Deltay[i][j-1]) / (x[i+j] - x[i]);
      end;
    end;
  end;

FillChar(Delta0y, SizeOf(Delta0y), 0);
for i := 0 to n do
Delta0y[i] := Deltay[0][i];
end;
procedure NewtonGregory(Ordem: Integer);
var
i, j, n: Integer;
Deltay: array[0..21, 0..21] of Real;
r, h: Real;
begin
n := Ordem;
h := x[1] - x[0];
for j:=0 to n do
  begin
    for i:= 0 to n-j do
    begin
      if (j=0) then
      begin
      Deltay[i][j] := y[i];
      end
      else
      begin
         Deltay[i][j] := Deltay[i+1][j-1] - Deltay[i][j-1];
      end;
    end;
  end;
FillChar(Delta0y, SizeOf(Delta0y), 0);
Delta0y[0] := Deltay[0][0];
for i := 1 to n do
begin
     Delta0y[i] := Deltay[0][i]/Real((Fatorial(i)*Power(h,i)));
end;
end;
procedure TForm1.FormShow(Sender: TObject);
var
i: Integer;
begin
for i := 0 to 21 do
    fat[i] := 0;
fat[1] := 1;
fat[2] := 2;
Application.HintHidePause := 20000;
RadioButton1.Hint := 'Interpolação com Sistema Linear:'#10#10+
'Calcula os coeficientes do polinômio'#10+
'através de solução de sistema linear.'#10;
RadioButton2.Hint := 'Interpolação por Newton:'#10#10+
'Calcula os coeficientes do polinômio'#10+
'através de diferenças finitas.'#10;
RadioButton3.Hint := 'Interpolação por Newton-Gregory:'#10#10+
'Calcula os coeficientes do polinômio'#10+
'através de diferenças finitas com'#10+
'espaçamentos constantes.'#10;
SpinEdit1.Hint := 'Número de pontos ( n+1 ):'#10#10+
'Para a seqüência de pontos ( x[i], y[i] ),'#10+
'i = 0, ..., n, o total de pontos é n+1.'#10#10+
'Entendeu, ou preciso fazer um desenho?'#10;

SpinEdit2.Hint := 'Grau do polinômio ( k<n+1 ):'#10#10+
'Para n+1 pontos, o grau máximo'#10+
'do polinômio é n.'#10;
Edit1.Hint := 'Ponto de referência z ( k<n ):'#10#10+
'Se o grau determinado para o polinômio for menor que n,'#10+
'deve-se fornecer um valor de referência entre x[0] e x[n].'#10#10+
'O Polinômio será calculado para as proximidades do valor de z.'#10;
SpeedButton1.Hint := 'Cria ou ajusta grade:'#10#10+
'Cria grade para entrada dos dados'#10+
'( x[i], y[i] ), i = 0, ..., n, ou seja,'#10+
'grade com n+1 caselas para x e para y.'#10;
SpeedButton2.Hint := 'Limpa a grade:'#10#10+
'Os dados não são apagados quando se altera seu tamanho'#10+
'para permitir ao usuário aproveitar dados já digitados.'#10;
SpeedButton3.Hint := 'Calcula polinômio interpolador:'#10#10+
'Resolve o problema, através do método'#10+
'determinado, com os dados oferecidos.'#10;
SpeedButton4.Hint := 'Ajuda:'#10#10+
'Apresenta o arquivo de ajuda, caso exista.'#10#10+
'Pois é, se não existir, não apresenta. :-)'#10;
SpeedButton5.Hint := 'Informação:'#10#10+
'Apresenta informações sobre autoria e direitos.'#10#10+
'Cuidado: Pirataria é crime. :-('#10;
SpeedButton6.Hint := 'Iú Tube:'#10#10+
'Veja no YouTube.'#10+
'Veja em tela cheia.'#10+
'Veja em tela vazia.'#10+
'Não veja.'#10#10+
'a Internet virou uma palhaçada.'#10+
'Os programas de MNC, também. :-)'#10;
EFH := GetSystemMetrics(SM_CYBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME);
EFV := GetSystemMetrics(SM_CXBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME);
ESH := GetSystemMetrics(SM_CYHSCROLL);
ESV := GetSystemMetrics(SM_CXVSCROLL);
StringGrid1.DefaultRowHeight := 20;;
DRH := StringGrid1.DefaultRowHeight;
DCW := StringGrid1.DefaultColWidth;
SpeedButton1.Click;
end;
procedure TForm1.SpinEdit1EditingDone(Sender: TObject);
begin
SpinEdit2.Value := SpinEdit1.Value-1;
SpeedButton1.Click;
end;
procedure TForm1.SpeedButton1Click(Sender: TObject);
var
i: Integer;
begin
m := SpinEdit1.Value;
n := m-1;
with StringGrid1 do
begin
RowCount := m+1;
if RowCount > 7 then
begin
Width := DCW*3 + EFH + ESH;
Height := DRH*7 + EFV;
end
else
begin
Width := DCW*3 + EFH + ESH;
Height := DRH*(m+1) + EFV;
end;
Cells[0,0] := 'i';
Cells[1,0] := 'x[i]';
Cells[2,0] := 'f(x[i])';
for i := 0 to n do
Cells[0,i+1] := IntToStr(i);
end;
end;
procedure TForm1.SpeedButton2Click(Sender: TObject);
var
i, j: Byte;
begin
for i := 1 to StringGrid1.RowCount-1 do
for j := 1 to 2 do
StringGrid1.Cells[j,i] := '';
Chart1LineSeries1.Clear;
Chart1LineSeries2.Clear;
Chart1LineSeries3.Clear;
Edit2.Clear;
end;
procedure TForm1.SpeedButton3Click(Sender: TObject);
var
i, j, p, q: Integer;
passo: Real;
xGrafico, yGrafico: Real;
begin
k := SpinEdit2.Value;
if (k < 1) or (k >= m) then
begin
ShowMessage('a ordem do polinômio deve ser entre 1 e n.');
SpinEdit2.SetFocus;
Exit;
end;
if k < n then
try
z := StrToFloat(Edit1.Text);
except
ShowMessage('Verifique o valor de z.');
Edit1.SetFocus;
Exit;
end;
with StringGrid1 do
begin
for i := 0 to n do
begin
try
x[i] := StrToFloat(Cells[1,i+1]);
except
ShowMessage('Verifique o valor de x['+IntToStr(i)+'].');
Col := 1;
Row := i+1;
SetFocus;
Exit;
end
end;
for i := 0 to n do
begin
try
y[i] := StrToFloat(Cells[2,i+1]);
except
ShowMessage('Verifique o valor de y['+IntToStr(i)+'].');
Col := 2;
Row := i+1;
SetFocus;
Exit;
end
end;
end;
if DadosRepetidos(p, q) then
begin
ShowMessage('Os valores de x['+IntToStr(p)+'] e de x['+IntToStr(q)+'] são iguais.'#10+
'Remova ou altere os dados repetidos para valores de x.');
Exit;
end;
OrdenarDados(n);
if k < n then
if (z < x[0]) or (z > x[n]) then
begin
ShowMessage('z deve estar entre '+FloatToStr(x[0])+' e '+FloatToStr(x[n])+'.');
Edit1.SetFocus;
Exit;
end;
for i := 0 to n do
begin
  xAll[i] := x[i];
  yAll[i] := y[i];
end;
PontosProximos;
OrdenarDados(k);
if RadioButton1.Checked then
begin
if k < n then
SistemaLinear(k)
else
SistemaLinear(n);
Edit2.Text := 'p'+IntToStr(n)+'(x) = ';
for i := 0 to n do
if c[i] < 0 then
Edit2.Text := Edit2.Text + FloatToStr(c[i]) + '*x^' + IntToStr(i)
else
Edit2.Text := Edit2.Text + '+' + FloatToStr(c[i]) + '*x^' + IntToStr(i);
Chart1LineSeries1.Clear;
Chart1LineSeries2.Clear;
Chart1LineSeries3.Clear;
passo := (xAll[n]-xAll[0])/100;
for i := 0 to 100 do
begin
xGrafico := xAll[0]+i*passo;
yGrafico := 0;
for j := 0 to n do
yGrafico := yGrafico + c[j]*Power(xGrafico,j);
Chart1LineSeries3.AddXY(xGrafico,yGrafico);
end;
for i := 0 to n do
Chart1LineSeries1.AddXY(xAll[i],yAll[i]);
for i := 0 to k do
Chart1LineSeries2.AddXY(x[i],y[i]);    {-----------------}
end;
if RadioButton2.Checked then
begin
if k < n then
Newton(k)
else
Newton(n);
Edit2.Text := 'p'+IntToStr(n)+'(x) = '+FloatToStr(Delta0y[0]);
for i := 0 to n-1 do
if x[i] < 0 then
Edit2.Text := Edit2.Text + '+(x+' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1])
else
if x[i] = 0 then
Edit2.Text := Edit2.Text + '+(x-' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1])
else
Edit2.Text := Edit2.Text + '+(x' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1]);
for i := 0 to n-1 do
Edit2.Text := Edit2.Text + ')';
Chart1LineSeries1.Clear;
Chart1LineSeries2.Clear;
Chart1LineSeries3.Clear;
passo := (xAll[n]-xAll[0])/100;
for i := 0 to 100 do
begin
xGrafico := xAll[0]+i*passo;
yGrafico := Delta0y[k];
for j := k-1 downto 0 do
yGrafico := yGrafico * (xGrafico-x[j]) + Delta0y[j];
Chart1LineSeries3.AddXY(xGrafico,yGrafico);
end;
for i := 0 to k do
Chart1LineSeries2.AddXY(x[i],y[i]);
for i := 0 to n do
Chart1LineSeries1.AddXY(xAll[i],yAll[i]);
end;
if RadioButton3.Checked then
begin
passo := x[1]-x[0];
for i := 2 to n do
if (x[i]-x[i-1]-passo)/passo > 1E-7 then
begin
ShowMessage('Com o vetor x já ordenado, os valores de x['+IntToStr(i-1)+'] e de x['+IntToStr(i)+'] não'#10+
'tem o mesmo espaçamento existente entre x[0] e x[1].');
Exit;
end;
if k < n then
NewtonGregory(k)
else
NewtonGregory(n);
Edit2.Text := 'p'+IntToStr(n)+'(x) = '+FloatToStr(Delta0y[0]);
for i := 0 to n-1 do
if x[i] < 0 then
Edit2.Text := Edit2.Text + '+(x+' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1])
else
if x[i] = 0 then
Edit2.Text := Edit2.Text + '+(x-' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1])
else
Edit2.Text := Edit2.Text + '+(x' +FloatToStr(-x[i]) + ')*('+FloatToStr(Delta0y[i+1]);
for i := 0 to n-1 do
Edit2.Text := Edit2.Text + ')';
Chart1LineSeries1.Clear;
Chart1LineSeries2.Clear;
Chart1LineSeries3.Clear;
passo := (xAll[n]-xAll[0])/100;
for i := 0 to 100 do
begin
xGrafico := xAll[0]+i*passo;
yGrafico := Delta0y[k];
for j := k-1 downto 0 do
yGrafico := yGrafico * (xGrafico-x[j]) + Delta0y[j];
Chart1LineSeries3.AddXY(xGrafico,yGrafico);
end;
for i := 0 to n do
Chart1LineSeries1.AddXY(xAll[i],yAll[i]);
for i := 0 to k do
Chart1LineSeries2.AddXY(x[i],y[i]);
end;
end;
procedure TForm1.SpeedButton4Click(Sender: TObject);
begin
if not OpenDocument('Interpola.chm') then
MessageDlg('Informação', 'O arquivo de ajuda'#10'Interpola.chm'#10'não foi encontrado.', mtInformation, [mbOk], 0);
end;
procedure TForm1.SpeedButton5Click(Sender: TObject);
begin
Form2.ShowModal;
end;
procedure TForm1.SpeedButton6Click(Sender: TObject);
begin
end;
end.

