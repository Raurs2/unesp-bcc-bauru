unit unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, ComCtrls, StdCtrls,
  Buttons, Grids, Math;

type

  { TForm1 }

  TForm1 = class(TForm)
    Edit1: TEdit;
    Edit10: TEdit;
    Edit11: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Edit8: TEdit;
    Edit9: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    Label1: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    PageControl1: TPageControl;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    SpeedButton7: TSpeedButton;
    SpeedButton8: TSpeedButton;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    StringGrid3: TStringGrid;
    StringGrid4: TStringGrid;
    StringGrid5: TStringGrid;
    StringGrid6: TStringGrid;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    procedure FormShow(Sender: TObject);
    procedure PageControl1Change(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpeedButton7Click(Sender: TObject);
    procedure SpeedButton8Click(Sender: TObject);
  private

  public

  end;

var
  Form1: TForm1;

implementation

{$R *.lfm}

{ TForm1 }
uses
    Windows;
var
  ScrollBarAltura, ScrollBarLargura: Integer; // Altura e largura da barra de rolagem
  m, n: Integer;
  RepassaErro: Boolean; // Informa erro entre diferentes rotinas
type
  Vetor = array of Extended;
  Matriz = array of array of Extended;

  function FxR1(f: String; x: Extended; var y: Extended): Word; stdcall; external 'Interpretador.dll';
  function FxRn(f: String; x: Vetor; colchetes: Boolean; var y: Extended): Word; stdcall;
  external 'Interpretador.dll';

procedure CopiaVetor(V1, V2: Vetor);
var
   i: Integer;
begin
     for i := 1 to n do
     V1[i] := V2[i];
end;
    // Nas rotinas que seguem, var d, G ou H devolvem os valores de Derivada, Gradiente ou Hessiana
    // Se não houver erro ao avaliar f(x), o valor da rotina (Word) será 0
    // Se houver erro, o valor da rotina (Word) será 1
function DerivadaPrimeira(f: string; x, Epsilon: Extended; var d: Extended): Word;
var
h, p, q, erro, f1, f2: Extended;
maxIt, it: Integer;
e1, e2: Word;
begin
     maxIt := 10;
     erro := 10000000000000.0;
     h := 1000*Epsilon;
     e1 := FxR1(f, (x+h), f1);
     e2 := FxR1(f, (x-h), f2);
     if(e1<>0) or (e2<>0) then
     begin
      Result:=1;
      Exit;
     end;
     p := (f1 - f2)/(2*h);
     it := 0;
     while true do
     begin
      h := h/2;
      it := it+1;
      q := p;
      e1 := FxR1(f, (x+h), f1);
      e2 := FxR1(f, (x-h), f2);
      if(e1<>0) or (e2<>0) then
      begin
       Result:=1;
       Exit;
      end;
      p := (f1 - f2)/(2*h);
      if(abs(p-q) < erro) then
      begin
       erro := abs(p-q);
      end
      else
      begin
       d := q;
       break;
      end;
      if(abs(p-q) < Epsilon) or (it > maxIt) then
      begin
      d := p;
      break;
      end;
     end;
     Result := 0;
end;
function DerivadaSegunda(f: string; x, Epsilon: Extended; var d: Extended): Word;
var
h,p,q,f1,f2,f3,erro: Extended;
maxIt, it: Integer;
e1, e2, e3: Word;
begin
     maxIt := 10;
     erro := 10000000000000.0;
     h := 1000*Epsilon;
     e1 := FxR1(f, (x+2*h), f1);
     e2 := FxR1(f, (x-2*h), f2);
     e3 := FxR1(f, x, f3);
     if(e1<>0) or (e2<>0) or (e3<>0) then
     begin
      Result:=1;
      Exit;
     end;
     p := (f1 - 2*f3 + f2)/(4*h*h);
     for it:=1 to maxIt do
     begin
      h := h/2;
      q := p;
      e1 := FxR1(f, (x+2*h), f1);
      e2 := FxR1(f, (x-2*h), f2);
      e3 := FxR1(f, x, f3);
      if(e1<>0) or (e2<>0) or (e3<>0)then
      begin
       Result:=1;
       Exit;
      end;
      p := (f1 -2*f3 + f2)/(4*h*h);
      if(abs(p-q) < Epsilon) then
      begin
       break;
      end;
     end;
     d := p;
     Result:=0;
end;
function DerivadaParcialPrimeira(f: string; var x: Vetor; i: Byte; Epsilon: Extended; var d: Extended): Word;
var
h, xi, f2, f1, p, q: Extended;
cont, maxIt: Integer;
e1, e2: Word;
begin
   maxIt := 10;
   h := 1000*Epsilon;
   xi := x[i];
   x[i] := xi + h;
   e1 := FxRn(f, x, true, f1);
   x[i] := xi - h;
   e2 := FxRn(f, x, true, f2);
   if(e1 <> 0) or (e2 <> 0) then
   begin
        Result:=1;
        Exit;
   end;
   p := (f1 - f2)/(2*h);
   for cont:=1 to maxIt do
   begin
    q := p;
    h := h/2;
    x[i] := xi + h;
    e1 := FxRn(f, x, true, f1);
    x[i] := xi - h;
    e2 := FxRn(f, x, true, f2);
    if(e1 <> 0) or (e2 <> 0) then
    begin
        Result:=1;
        Exit;
    end;
    p := (f1 - f2)/(2*h);
    if(abs(p-q)<Epsilon) then
        break;
   end;
   d := p;
   x[i] := xi;
   Result:=0;
end;
function DerivadaParcialSegunda(f: string; var x: Vetor; i, j: Byte; Epsilon: Extended; var d: Extended): Word;
var
cont, maxIt: Integer;
e1, e2, e3, e4: Word;
p, h, q, f1, f2, f3, f4, xi, xj: Extended;
begin
   h := 1000*Epsilon;
   maxIt := 10;
   xi := x[i];
   xj := x[j];
   if(i<>j) then
       begin
           x[i] := xi+h; x[j] := xj+h; e1 := FxRn(f, x, true, f1);
           x[j] := xj-h; e2 := FxRn(f, x, true, f2);
           x[i] := xi-h; e4 := FxRn(f, x, true, f4);
           x[j] := xj+h; e3 := FxRn(f, x, true, f3);
           if(e1<>0) or(e2<>0) or (e3<>0) or (e4<>0) then
           begin
               Result := 1;
               Exit;
           end;
           p := (f1-f2-f3+f4)/(4*h*h);
           end
       else
       begin
           x[i] := xi + 2*h;  e1 := FxRn(f, x, true, f1);
           x[i] := xi -2*h;   e3 := FxRn(f, x, true, f3);
           x[i] := xi;        e2 := FxRn(f, x, true, f2);
           if(e1<>0) or(e2<>0) or (e3<>0) then
           begin
               Result := 1;
               Exit;
           end;
           p := (f1 -2*f2 + f3)/(4*h*h)
       end;
       for cont:=1 to maxIt do
       begin
          q := p;
          h := h/2;
          if(i<>j) then
          begin
              x[i] := xi+h; x[j] := xj+h; e1 := FxRn(f, x, true, f1);
              x[j] := xj-h; e2 := FxRn(f, x, true, f2);
              x[i] := xi-h; e4 := FxRn(f, x, true, f4);
              x[j] := xj+h; e3 := FxRn(f, x, true, f3);
              if(e1<>0) or(e2<>0) or (e3<>0) or (e4<>0) then
              begin
                  Result := 1;
                  Exit;
              end;
          p := (f1-f2-f3+f4)/(4*h*h);
          end
          else
          begin
              x[i] := xi + 2*h;  e1 := FxRn(f, x, true, f1);
              x[i] := xi -2*h;   e3 := FxRn(f, x, true, f3);
              x[i] := xi;        e2 := FxRn(f, x, true, f2);
              if(e1<>0) or(e2<>0) or (e3<>0) then
              begin
                  Result := 1;
                  Exit;
              end;
          p := (f1 -2*f2 + f3)/(4*h*h)
          end;
          if(abs(p-q) < Epsilon) then
              break;
     end;
     Result := 0;
     d := p;
     x[i] := xi;
     x[j] := xj;
end;
function Gradiente(f: string; x: Vetor; Epsilon, d: Extended; var G: Vetor): Word;
var
i:Integer;
e:Word;
begin
   SetLength(G, n+1);
   for i:=1 to n do
   begin
       e := DerivadaParcialPrimeira(f, x, i, Epsilon, d);
       if(e<>0) then
       begin
           Result:=1;
           Exit;
       end;
   G[i] := d;
   end;
Result:=0;
end;
function Hessiana(f: string; x: Vetor; Epsilon, d: Extended; var H: Matriz): Word;
var
i, j: Integer;
e: Word;
begin
    SetLength(H, n+1);
    for i:=1 to n do
    begin
      SetLength(H[i], n+1);
      for j:=i to n do
      begin
         e := DerivadaParcialSegunda(f, x, i, j, Epsilon, d);
         if(e<>0) then
         begin
             Result:=1;
             Exit;
         end;
         H[i][j] := d;

      end;
   end;
   for i:=1 to n do
     for j:=i+1 to n do
        H[j][i] := H[i][j];

Result := 0;
end;
procedure TForm1.PageControl1Change(Sender: TObject);
begin

end;
procedure TForm1.FormShow(Sender: TObject);
begin
  // Medir largura e altura das barras de rolagem
  // Dimensionar StringGrid1, StringGrid2 e StringGrid3 e colocar foco em Edit1
  // Dimensionar StringGrid4, StringGrid5 e StringGrid6
  ScrollBarAltura := GetSystemMetrics(SM_CYHSCROLL);
  ScrollBarLargura := GetSystemMetrics(SM_CXVSCROLL);
  PageControl1.ActivePage := TabSheet1;
  SpeedButton3.Click;
  Edit1.SetFocus;
  SpeedButton6.Click;
end;

procedure TForm1.SpeedButton1Click(Sender: TObject);
var
  f: string;
  x, Epsilon, d: Extended;
begin
  // Calcular derivada primeira e derivada segunda de f: R -> R
  f := Trim(Edit1.Text);
  if f = '' then
  begin
    ShowMessage('Por favor, informe a função.');
    Edit1.SetFocus;
    Exit;
  end;
  try
     x := Strtofloat(Edit2.Text)
  except
    ShowMessage('Valor inválido para x.');
    Edit2.SetFocus;
    Exit;
  end;
  try
     Epsilon := StrToFloat(Edit3.Text)
  except
    ShowMessage('Valor inválido para Epsilon.');
    Edit3.SetFocus;
    Exit;
  end;
  if (Epsilon > 0.001+10E-10) or (Epsilon < 0.0000001-10E-10) then
  begin
    ShowMessage('Querido usuário.'+#10+'A precisão deve estar entre 1E-3 e 1E-7.');
    Edit3.SetFocus;
    Exit;
  end;
  if DerivadaPrimeira(f, x, Epsilon, d) <> 0 then
  begin
    Edit4.Text := '';
    ShowMessage('Alguma coisa saiu errada no cálculo da derivada primeira.');
  end
  else
    Edit4.Text := FloatToStr(d);
  if DerivadaSegunda(f, x, Epsilon, d) <> 0 then
  begin
    Edit5.Text := '';
    ShowMessage('Alguma coisa saiu errada no cálculo da derivada segunda.');
  end
  else
    Edit5.Text := FloatToStr(d);
end;

procedure TForm1.SpeedButton2Click(Sender: TObject);
begin
  // Limpa tudo ( f: R --> R )
  Edit1.Text := '';
  Edit2.Text := '';
  Edit3.Text := '';
  Edit4.Text := '';
  Edit5.Text := '';
  Edit1.SetFocus;
end;

procedure TForm1.SpeedButton3Click(Sender: TObject);
var
  i : Integer;
begin
  // Ler n em Edit6 e, se houver erro, informar, colocar foco em Edit6 e sair
  // Dimensionar StringGrid1, StringGrid2 e StringGrid3 e colocar foco em Edit7
  // FormShow ativa TabSheet1 e executa SpeedButton3Click pela primeira vez e,
  // portanto, pode-se colocar o foco em Edit7
  try
    n := StrToInt(Edit6.Text);
  except
    ShowMessage('Numero de componentes de x inválido.');
    Edit6.SetFocus;
    RepassaErro := True;
    Exit;
  end;
  if n < 1 then
  begin
    ShowMessage('Querido usuário.'+#10+'Leia com atenção:'+#10+
                'Funções ortodoxas possuem ao menos uma variável.'+#10+
                'Se você quiser utilizar funções heterodoxas, nirvânicas '+
                'ou do além, este programa não é o recomendado.');
    Edit6.SetFocus;
    RepassaErro := True;
    Exit;
  end;
  if n < 2 then
  begin
    ShowMessage('Querido usuário.'+#10+'Leia com atenção:'+#10+
    'Para funções de uma variável, utilize a parte superior deste programa.');
    Edit6.SetFocus;
    RepassaErro := True;
    Exit;
  end;
  if n > 20 then
    begin
    ShowMessage('Meu querido.'+#10+'Leia com atenção:'+#10+
    'Sinto muito, mas este programa só resolve problemas com vetores com, no máximo, 20 componentes.');
    Edit6.SetFocus;
    RepassaErro := True;
    Exit;
  end;
  //Grade do vetor x (transposto)
  StringGrid1.ColCount := n+1;
  StringGrid1.Cells[0, 0] := 'i';
  StringGrid1.Cells[0, 1] := 'x[i]';
  for i := 1 to n do
      StringGrid1.Cells[i, 0] := IntToStr(i);
  if n <= 6 then
  begin
    StringGrid1.Height := 46;
    StringGrid1.Width := 68+n*64;
  end
  else
  begin
    StringGrid1.Height := 46+ScrollBarAltura;
    StringGrid1.Width := 68+6*64;
  end;
  //Grade do vetor Gradiente (transposto)
  StringGrid2.ColCount := n+1;
  StringGrid2.Cells[0, 0] := 'i';
  StringGrid2.Cells[0, 1] := 'G[i]';
  for i := 1 to n do
      StringGrid2.Cells[i, 0] := IntToStr(i);
  if n <= 6 then
  begin
    StringGrid2.Height := 46;
    StringGrid2.Width := 68+n*64;
  end
  else
  begin
    StringGrid2.Height := 46+ScrollBarAltura;
    StringGrid2.Width := 68+6*64;
  end;
  //Grade da matriz Hessiana
  StringGrid3.ColCount := n+1;
  StringGrid3.RowCount := n+1;
  StringGrid3.Cells[0, 0] := 'H[i,j]';
  for i := 1 to n do
  begin
    StringGrid3.Cells[i, 0] := IntToStr(i);
    StringGrid3.Cells[0, i] := IntToStr(i);
  end;
  if n <= 6 then
  begin
    StringGrid3.Height := 25+n*21;
    StringGrid3.Width := 68+n*64;
  end
  else
  begin
    StringGrid3.Height := 151+ScrollBarAltura;
    StringGrid3.Width := 452+ScrollBarLargura;
  end;
  Edit7.SetFocus;
end;

procedure TForm1.SpeedButton4Click(Sender: TObject);
var
  f: string;
  x, G: Vetor;
  H: Matriz;
  Epsilon, d: Extended;
  i, j: Integer;
begin
  // Calcular derivada primeira e derivada segunda de f: Rn -> R (gradiente e hessiana)
  // Rever entrada de dados n caso o usuário tenha feito a gracinha de modificar n
  RepassaErro := False;
  SpeedButton3.Click;
  if RepassaErro then
  begin
    RepassaErro := False;
    Exit;
  end;
  f := Trim(Edit7.Text);
  if f = '' then
  begin
    ShowMessage('Por favor informe uma função.');
    Edit7.SetFocus;
    Exit;
  end;
  try
     Epsilon := StrToFloat(Edit8.Text)
  except
    ShowMessage('Valor inválido para Epsilon.');
    Edit8.SetFocus;
    Exit;
  end;
  if (Epsilon > 0.001+10E-10) or (Epsilon < 0.0000001-10E-10) then
  begin
    ShowMessage('Meu querido.'+#10+'A precisão deve estar entre 1E-3 e 1E-7.');
    Edit8.SetFocus;
    Exit;
  end;
  SetLength(x, n+1);
  for i := 1 to n do
      try
         x[i] := StrToFloat(StringGrid1.Cells[i,1]);
      except
        ShowMessage('Valor inválido para x['+IntToStr(i)+'].');
        StringGrid1.Col := i;
        StringGrid1.Row := 1;
        StringGrid1.SetFocus;
        Exit;
      end;
  if Gradiente(f, x, Epsilon, d, G) <> 0 then
  begin
    for i := 1 to n do
        StringGrid2.Cells[i,1] := '';
    ShowMessage('Alguma coisa saiu errada no cálculo do Gradiente.');
  end
  else
      for i := 1 to n do
          StringGrid2.Cells[i,1] := FloatToStr(G[i]);
      if Hessiana(f, x, Epsilon, d, H) <> 0 then
      begin
        for i := 1 to n do
            for j := 1 to n do
                StringGrid3.Cells[j,i] := '';
        ShowMessage('Alguma coisa saiu errada no cálculo da Hessiana.');
      end
      else
      for i := 1 to n do
          for j := 1 to n do
              StringGrid3.Cells[j,i] := FloatToStr(H[i,j]);
end;

procedure TForm1.SpeedButton5Click(Sender: TObject);
var
   i, j: Integer;
begin
  // Limpa tudo ( f: Rn --> R )
  Edit6.Text := '3';
  Edit7.Text := '';
  Edit8.Text := '';
  SpeedButton3.Click; // Restaura StringGrid 1, 2 e 3 ao padrão inicial com n = 3
  for j := 1 to n do
    begin
      StringGrid1.Cells[j, 1] := '';
      StringGrid2.Cells[j, 1] := '';
      for i := 1 to n do
          StringGrid3.Cells[j, i] := '';
    end;
    // Apenas para deixar a casela (1,1) marcada (não é necessário)
    StringGrid1.Col := 1; StringGrid1.Row := 1;
    StringGrid2.Col := 1; StringGrid2.Row := 1;
    StringGrid3.Col := 1; StringGrid3.Row := 1;
end;

procedure TForm1.SpeedButton6Click(Sender: TObject);
  var
     i : Integer;
  begin
    // Ler m em Edit9 e, se houver erro, informar, colocar foco em Edit9 e sair
    // Ler n em Edit10 e, se houver erro, informar, colocar foco em Edit10 e sair
    // Dimensionar StringGrid4, StringGrid5 e StringGrid6 e colocar foco em StringGrid5
    // FormShow ativa TabSheet1 e executa SpeedButton6Click pela primeira vez, mas
    // só pode-se colocar foco em StringGrid5, se ActivePage = TabSheet2
    try
       m := StrToInt(Edit9.Text);
    except
      ShowMessage('Numero de funções inválido.');
      Edit9.SetFocus;
      RepassaErro := True;
      Exit;
    end;
    if m < 2 then
    begin
      ShowMessage('Meu querido.'+#10+'Leia com atenção:'+#10+
      'O menor número de funções para cálculo'+#10+
      'do Jacobiano, neste programa, é 2.');
      Edit9.SetFocus;
      RepassaErro := True;
      Exit;
    end;
    if m > 20 then
    begin
      ShowMessage('Meu querido.'+#10+'Leia com atenção:'+#10+
      'Sinto muito, mas o programa só resolve problemas com, no máximo, 20 funções.');
      Edit9.SetFocus;
      RepassaErro := True;
      Exit;
    end;
    try
       n := StrToInt(Edit10.Text);
    except
      ShowMessage('Numero de componentes de x inválido.');
      Edit10.SetFocus;
      RepassaErro := True;
      Exit;
    end;
    if n < 2 then
    begin
      ShowMessage('Meu querido.'+#10+'Leia com atenção:'+#10+
      'O menor número de variáveis para cálculo'+#10+
      'do Jacobiano, neste programa, é 2.');
      RepassaErro := True;
      Edit10.SetFocus;
      Exit;
    end;
    if n > 20 then
    begin
      ShowMessage('Meu querido.'+#10+'Leia com atenção:'+#10+
      'Sinto muito, mas o programa só resolve problemas com vetores com, no máximo, 20 componentes.');
      Edit10.SetFocus;
      RepassaErro := True;
      Exit;
    end;
    //Grade do vetor x (transposto)
    StringGrid4.ColCount := n+1;
    StringGrid4.Cells[0, 0] := 'i';
    StringGrid4.Cells[0, 1] := 'x[i]';
    for i := 1 to n do
      StringGrid4.Cells[i, 0] := IntToStr(i);
    if n <= 6 then
      begin
        StringGrid4.Height := 46;
        StringGrid4.Width := 68+n*64;
      end
    else
      begin
        StringGrid4.Height := 46+ScrollBarAltura;
        StringGrid4.Width := 68+6*64;
      end;
    //Grade das m funções
    StringGrid5.ColWidths[1] := 384;
    StringGrid5.RowCount := m+1;
    StringGrid5.Cells[0, 0] := 'i';
    StringGrid5.Cells[1, 0] := 'f[i]';
    for i := 1 to m do
        StringGrid5.Cells[0, i] := IntToStr(i);
    if m <= 6 then
    begin
      StringGrid5.Height := 25+m*21;
      StringGrid5.Width := 452;
    end
    else
    begin
      StringGrid5.Height := 151;
      StringGrid5.Width := 452+ScrollBarLargura;
    end;
    //Grade da matriz Jacobiana
    StringGrid6.ColCount := n+1;
    StringGrid6.RowCount := m+1;
    StringGrid6.Cells[0, 0] := 'J[i,j]';
    for i := 1 to m do
        StringGrid6.Cells[0, i] := IntToStr(i);
    for i := 1 to n do
        StringGrid6.Cells[i, 0] := IntToStr(i);
    if (m <= 6) and (n <= 6) then
    begin
      StringGrid6.Height := 25+m*21;
      StringGrid6.Width := 68+n*64;
    end;
    if (m <= 6) and (n > 6) then
    begin
      StringGrid6.Height := 25+m*21+ScrollBarAltura;
      StringGrid6.Width := 452;
    end;
    if (m > 6) and (n <= 6) then
    begin
      StringGrid6.Height := 151;
      StringGrid6.Width := 68+n*64+ScrollBarLargura;
    end;
    if (m > 6) and (n > 6) then
    begin
      StringGrid6.Height := 151+ScrollBarAltura;
      StringGrid6.Width := 452+ScrollBarLargura;
    end;
    if PageControl1.ActivePage = TabSheet2 then // Veja comentário no início da rotina
       StringGrid5.SetFocus;
end;

procedure TForm1.SpeedButton7Click(Sender: TObject);
var
  f: string;
  x, G: Vetor;
  Epsilon, d: Extended;
  i, j: Integer;
begin
  // Calcular derivada primeira de cada f[i]: Rn -> R (linhas do jacobiano)
  // Rever entrada de dados n caso o usuário tenha feito a gracinha de modificar m ou n
  RepassaErro := False;
  SpeedButton6.Click;
  if RepassaErro then
  begin
    RepassaErro := False;
    Exit;
  end;
  try
     Epsilon := StrToFloat(Edit11.Text)
  except
    ShowMessage('Valor inválido para Epsilon.');
    Edit11.SetFocus;
    Exit;
  end;
  if (Epsilon > 0.001+10E-10) or (Epsilon < 0.0000001-10E-10) then
  begin
    ShowMessage('Meu querido.'+#10+'A precisão deve estar entre 1E-3 e 1E-7.');
    Edit11.SetFocus;
    Exit;
  end;
  SetLength(x, n+1);
  for i := 1 to n do
  // Ler vetor x
  try
     x[i] := StrToFloat(StringGrid4.Cells[i,1]);
  except
    ShowMessage('Valor inválido para x['+IntToStr(i)+'].');
    StringGrid4.Col := i;
    StringGrid4.Row := 1;
    StringGrid4.SetFocus;
    Exit;
  end;
  for i := 1 to m do
  begin
    f := Trim(StringGrid5.Cells[1,i]);
    if f = '' then
    begin
      ShowMessage('Por favor, informe uma função.');
      StringGrid5.Row := i;
      StringGrid5.SetFocus;
      Exit;
    end;
    if Gradiente(f, x, Epsilon, d, G) <> 0 then
    begin
      for j := 1 to n do
      StringGrid6.Cells[j,i] := '';
      ShowMessage('Alguma coisa saiu errada no cálculo do Jacobiano, na linha ' + IntToStr(i) + '.')
    end
    else
        for j := 1 to n do
            StringGrid6.Cells[j,i] := FloatToStr(G[j]);
  end;
end;

procedure TForm1.SpeedButton8Click(Sender: TObject);
var
  i, j: Integer;
begin
  // Limpa tudo ( f: Rn --> Rm )
  Edit9.Text := '3';
  Edit10.Text := '3';
  Edit11.Text := '';
  SpeedButton6.Click; // Restaura StringGrid 4, 5 e 6 ao padrão inicial com m = 3 e n = 3
  for j := 1 to n do
  begin
    StringGrid4.Cells[j, 1] := '';
    for i := 1 to m do
        StringGrid6.Cells[j, i] := '';
  end;
  for i := 1 to m do
      StringGrid5.Cells[1, i] := '';
  // Apenas para deixar a casela (1,1) marcada (não é necessário)
  StringGrid4.Col := 1; StringGrid4.Row := 1;
  StringGrid5.Col := 1; StringGrid5.Row := 1;
  StringGrid6.Col := 1; StringGrid6.Row := 1;
end;
end.
