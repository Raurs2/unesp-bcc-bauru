unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Spin,
  Buttons, Grids, ActnList;

type

  { TForm1 }

  TForm1 = class(TForm)
    ActionList1: TActionList;
    ActionList2: TActionList;
    ActionList3: TActionList;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    CheckBox3: TCheckBox;
    CheckBox4: TCheckBox;
    FloatSpinEdit1: TFloatSpinEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    RadioButtonMetodosDiretos: TRadioButton;
    RadioButton2: TRadioButton;
    RadioButton3: TRadioButton;
    RadioButton4: TRadioButton;
    RadioButton5: TRadioButton;
    RadioButton6: TRadioButton;
    RadioButtonMetodosIterativos: TRadioButton;
    RadioButton8: TRadioButton;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    StringGrid1: TStringGrid;
    procedure CheckBoxOpcoesClick(Sender: TObject);
    procedure FloatSpinEdit1Exit(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure GroupBox4Click(Sender: TObject);
    procedure RadioButton8Change(Sender: TObject);
    procedure RadioButtonMetodosIterativosClick(Sender: TObject);
    procedure RadioButtonMetodosDiretosClick(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpinEdit1Change(Sender: TObject);
    procedure SpinEdit1Exit(Sender: TObject);
    procedure SpinEdit1KeyPress(Sender: TObject; var Key: char);
    procedure SpinEdit2Exit(Sender: TObject);
    procedure StringGrid1PrepareCanvas(sender: TObject; aCol, aRow: Integer;
      aState: TGridDrawState);
    procedure StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
      var CanSelect: Boolean);
  private

  public

  end;

var
  Form1: TForm1;

implementation
  {$R *.lfm}
  { TForm1 }
  uses
  methods, solution, about, Windows, LCLIntf;
  var
  EFH, EFV, ESH, ESV: Byte;
  DRH, DCW: Integer;
  GLX: Boolean;
  n_atual: Integer;
  bCopia, xIniCopia: array[1..20] of string;

procedure TForm1.FormCreate(Sender: TObject);
  begin
    SpinEdit1.Hint := 'Entre com o número de variáveis ou'#13'cutuque para cima e para baixo para'#13+
    'definir o número de variáveis,'#13'que deve ser entre 3 e 20.';
    SpinEdit2.Hint := 'Entre o número máximo de iterações'#13'ou cutuque para cima e para baixo para'#13+
    'definir com o número máximo de iterações,'#13'que deve ser entre 10 e 100.';
    FloatSpinEdit1.Hint := 'Entre com a tolerância e ou'#13'cutuque para cima e para baixo para'#13+
    'definir a tolerância e, que deve'#13'ser entre 0,00001 e 0,001.';
    SpeedButton1.Hint := 'Cria grade para entrada de dados.';
    SpeedButton2.Hint := 'Limpa grade.';
    SpeedButton3.Hint := 'Resolve o sistema.';
    SpeedButton4.Hint := 'Apresenta o arquivio de ajuda.';
    SpeedButton5.Hint := 'Informações sobre direitos e autoria.';
    RadioButtonMetodosDiretos.Hint := 'Método de Gauss com escalonamento simples.';
    RadioButton2.Hint := 'Método de Gauss com pivotamento'#13'parcial: permutação entre linhas.';
    RadioButton3.Hint := 'Método de Gauss com pivotamento total:'#13'permutação entre linhas e entre colunas.';
    RadioButton4.Hint := 'Método de Gauss compacto.';
    RadioButton5.Hint := 'Método de Decomposição L.U.';
    RadioButton6.Hint := 'Método de Cholesky.';
    RadioButtonMetodosIterativos.Hint := 'Método de Jacobi-Richardson.';
    RadioButton8.Hint := 'Método de Gauss-Seidel.';
    CheckBox2.Hint := 'Com o Método escolhido,'#13'calcula o sistema.';
    CheckBox3.Hint := 'Com o Método escolhido,'#13'calcula o determinante.';
    CheckBox4.Hint := 'Com o Método escolhido,'#13'calcula a matriz inversa.';
    EFH := GetSystemMetrics(SM_CYBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME);
    EFV := GetSystemMetrics(SM_CXBORDER)+GetSystemMetrics(SM_CYFIXEDFRAME);
    ESH := GetSystemMetrics(SM_CYHSCROLL);
    ESV := GetSystemMetrics(SM_CXVSCROLL);
    StringGrid1.DefaultRowHeight := 20;
    DRH := StringGrid1.DefaultRowHeight;
    DCW := StringGrid1.DefaultColWidth;
end;

procedure TForm1.FormShow(Sender: TObject);
begin
  n_atual := 0;
  n := SpinEdit1.Value;
  ItMax := SpinEdit2.Value;
  Epsilon := FloatSpinEdit1.Value;
  SpeedButton1.Click;
  RadioButtonMetodosDiretosClick(Self);
  CheckBoxOpcoesClick(Self);
end;

procedure TForm1.GroupBox4Click(Sender: TObject);
begin

end;

procedure TForm1.RadioButton8Change(Sender: TObject);
begin

end;

procedure TForm1.SpinEdit1Exit(Sender: TObject);
begin
     n := SpinEdit1.Value;
     SpeedButton1.Click;
end;
procedure TForm1.SpinEdit1KeyPress(Sender: TObject; var Key: char);
begin
  if Key = #13 then
  begin
    Key := #0;
    SpeedButton1.Click;
  end;
end;
procedure TForm1.SpinEdit2Exit(Sender: TObject);
begin
  ItMax := SpinEdit2.Value;
end;

procedure TForm1.StringGrid1PrepareCanvas(sender: TObject; aCol, aRow: Integer;
  aState: TGridDrawState);
begin

end;

procedure TForm1.FloatSpinEdit1Exit(Sender: TObject);
begin
  Epsilon := FloatSpinEdit1.Value;
end;
procedure TForm1.RadioButtonMetodosDiretosClick(Sender: TObject);
begin
  CheckBox3.Enabled := True;
  CheckBox4.Enabled := RadioButton5.Checked;
  SpeedButton1.Click;
  CheckBoxOpcoesClick(Self);
end;
procedure TForm1.RadioButtonMetodosIterativosClick(Sender: TObject);
begin
  CheckBox2.Checked := True;
  CheckBox3.Enabled := False;
  CheckBox4.Enabled := False;
  SpeedButton1.Click;
  CheckBoxOpcoesClick(Self);
end;
procedure TForm1.CheckBoxOpcoesClick(Sender: TObject);
begin
  CalculaSistema := CheckBox2.Checked and CheckBox2.Enabled;
  CalculaDeterminante := CheckBox3.Checked and CheckBox3.Enabled;
  CalculaInversa := CheckBox4.Checked and CheckBox4.Enabled;
end;

procedure TForm1.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
  var CanSelect: Boolean);
begin
  if GLX then
  with StringGrid1 do
  if (aCol=RowCount-1) and (aRow=RowCount-1) then
  CanSelect := False;
end;

procedure TForm1.SpeedButton1Click(Sender: TObject);
  var
  k: Integer;
  begin
  GLX := RadioButtonMetodosIterativos.Checked or RadioButton8.Checked;
  with StringGrid1 do
  begin
  for k := 1 to n_atual do
  begin
  bCopia[k] := Cells[n_atual+1,k];
  Cells[n_atual+1,k] := '';
  end;
  if GLX and (RowCount = n_atual+2) then
  for k := 1 to n_atual do
  begin
  xIniCopia[k] := Cells[k,n_atual+1];
  Cells[k,n_atual+1] := '';
  end;
  end;
  n := SpinEdit1.Value;
  if n <> n_atual then
  with StringGrid1 do
  begin
  RowCount := n+1;
  ColCount := n+2;
  n_atual := n;
  Cells[0,0] := 'A';
  for k := 1 to n do
  begin
  Cells[k,0] := IntToStr(k);
  Cells[0,k] := IntToStr(k);
  end;
  Cells[n+1,0] := 'b';
  Width := DCW*(n+2) + EFV;
  Height := DRH*(n+1) + EFH;
  if n > 7 then begin Width := DCW*9 + EFV; Height := Height + ESH; end;
  if n > 8 then begin Width := DCW*9 + EFV + ESV; Height := DRH*9 + EFH + ESH; end;
  SetFocus;
  end;
  with StringGrid1 do
  if GLX then
  begin
  if RowCount = n+1 then
  begin
  RowCount := RowCount+1;
  if n < 8 then
  Height := Height+DRH;
  Cells[0,RowCount-1] := 'x inicial';
  if n > 7 then
  Width := DCW*9 + EFV + ESV;
  end;
  end
  else
  begin
  if RowCount = n+2 then
  begin
  RowCount := RowCount-1;
  Width := DCW*(n+2) + EFV;
  Height := DRH*(n+1) + EFH;
  if n > 7 then begin Width := DCW*9 + EFV; Height := Height + ESH; end;
  if n > 8 then begin Width := DCW*9 + EFV + ESV; Height := DRH*9 + EFH + ESH; end;
  end;
end;
for k := 1 to n do
begin
StringGrid1.Cells[n+1,k] := bCopia[k];
if GLX then
StringGrid1.Cells[k,n+1] := xIniCopia[k];
end;
end;

procedure TForm1.SpeedButton2Click(Sender: TObject);
var
i, j: Integer;
begin
for i := 1 to n do
for j := 1 to n+1 do
StringGrid1.Cells[j,i] := '';
end;
procedure TForm1.SpeedButton3Click(Sender: TObject);
var
i, j, k: Integer;
begin
ItMax := SpinEdit2.Value;
Epsilon := FloatSpinEdit1.Value;
if CheckBox1.Checked then
begin
for i := 1 to n do
for j := 1 to n do
if (Trim(StringGrid1.Cells[j,i])) = '' then
StringGrid1.Cells[j,i] := '0';
for i := 1 to n do
if (Trim(StringGrid1.Cells[n+1,i])) = '' then
StringGrid1.Cells[n+1,i] := '0';
if GLX then
for j := 1 to n do
if (Trim(StringGrid1.Cells[j,n+1])) = '' then
StringGrid1.Cells[j,n+1] := '0';
end;
for i := 1 to n do
begin
for j := 1 to n do
try
A[i,j] := StrToFloat(StringGrid1.Cells[j,i]);
except
  MessageDlg('O valor de A['+IntToStr(i)+','+IntToStr(j)+'] não é um número real válido', mtError, [mbOk], 0);
  StringGrid1.Col := j;
  StringGrid1.Row := i;
  StringGrid1.SetFocus;
  Exit;
  end;
  try
  b[i] := StrToFloat(StringGrid1.Cells[n+1,i]);
  except
  MessageDlg('O valor de b['+IntToStr(i)+'] não é um número real válido', mtError, [mbOk], 0);
  StringGrid1.Col := n+1;
  StringGrid1.Row := i;
  StringGrid1.SetFocus;
  Exit;
  end;
  end;
  if GLX then
  for j := 1 to n do
  try
  xIni[j] := StrToFloat(StringGrid1.Cells[j,n+1]);
  except
  MessageDlg('O valor de x['+IntToStr(j)+'] não é um número real válido', mtError, [mbOk], 0);
StringGrid1.Col := j;
StringGrid1.Row := n+1;
StringGrid1.SetFocus;
Exit;
end;
if not (CalculaSistema or CalculaDeterminante or CalculaInversa) then
begin
MessageDlg('Não foi solicitado resolver o sistema'+#10+'nem calcular o determinante'+#10+
'nem calcular a inversa.'+#10+'Então, nada será feito.', mtInformation, [mbOk], 0);
Exit;
end;
Form2.Close;
Erro := True;
if RadioButtonMetodosDiretos.Checked then Gauss;
if RadioButton2.Checked then GaussPivotamentoParcial;
if RadioButton3.Checked then GaussPivotamentoTotal;
if RadioButton4.Checked then GaussCompacto;
if RadioButton5.Checked then DecomposicaoLU;
if RadioButton6.Checked then Cholesky;
if RadioButtonMetodosIterativos.Checked then JacobiRichardson;
if RadioButton8.Checked then GaussSeidel;
if Erro then
Exit;
with Form2 do
begin
with StringGrid1 do
begin
RowCount := n+2;
ColCount := n+2;
for i := 1 to n do
for j := 1 to n+1 do
Cells[j,i] := '';
Cells[0,0] := 'A';
for k := 1 to n do
begin
Cells[k,0] := IntToStr(k);
Cells[0,k] := IntToStr(k);
end;
Cells[n+1,0] := 'b';
Cells[0,n+1] := 'x';
Width := DCW*(n+2) + EFV;
Height := DRH*(n+2) + EFH;
if n > 7 then begin Width := DCW*9 + EFV + ESV; Height := DRH*9 + EFH + ESH; end;
end;
with StringGrid2 do
begin
RowCount := n+1;
ColCount := n+1;
for i := 1 to n do
for j := 1 to n do
Cells[j,i] := '';
Cells[0,0] := 'A';
for k := 1 to n do
begin
Cells[k,0] := IntToStr(k);
Cells[0,k] := IntToStr(k);
end;
Width := DCW*(n+1) + EFV;
Height := DRH*(n+1) + EFH;
if n > 8 then begin Width := DCW*9 + EFV + ESV; Height := DRH*9 + EFH + ESH; end;
end;
if CalculaSistema then
begin
GroupBox1.Caption := 'Solução do sistema';
if GLX then
GroupBox1.Caption := 'Solução do sistema - Iterações = '+IntToStr(Iteracao);
with StringGrid1 do
begin
for i := 1 to n do
begin
for j := 1 to n do
Cells[j,i] := FloatToStr(A[i,j]);
Cells[j+1,i] := FloatToStr(b[i]);
end;
for j := 1 to n do
Cells[j,n+1] := FloatToStr(x[j]);
Cells[n+1,n+1] := '';
end;
end
else
begin
GroupBox1.Caption := 'Solução do sistema - Não foi solicitado';
for i := 1 to n+1 do
for j := 1 to n+1 do
StringGrid1.Cells[j,i] := '';
end;
if CalculaDeterminante then
Label1.Caption := 'Determinante = '+FloatToStr(Determinante)
else
Label1.Caption := 'Determinante - Não foi solicitado';
if CalculaInversa then
begin
GroupBox2.Caption := 'Matriz inversa';
with StringGrid2 do
for i := 1 to n do
for j := 1 to n do
Cells[j,i] := FloatToStr(AInv[i,j]);
end
else
begin
GroupBox2.Caption := 'Matriz inversa - Não foi solicitado';
for i := 1 to n do
for j := 1 to n do
          StringGrid2.Cells[j,i] := '';
    end;
Show;
end;
end;

procedure TForm1.SpeedButton4Click(Sender: TObject);
begin
if not OpenDocument('SistemasLineares.chm') then
MessageDlg('O arquivo de ajuda'#10'SistemasLineares.chm'#10'não foi encontrado.', mtInformation, [mbOk], 0);
end;

procedure TForm1.SpeedButton5Click(Sender: TObject);
begin
Form3.ShowModal;
end;

procedure TForm1.SpinEdit1Change(Sender: TObject);
begin

end;


end.

