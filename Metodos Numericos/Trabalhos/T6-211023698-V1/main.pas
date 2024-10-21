unit main;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Spin,
  Buttons, ExtCtrls, Grids, TAGraph, TASeries;

type

  { TForm1 }

  TForm1 = class(TForm)
    Bevel1: TBevel;
    Chart1: TChart;
    Chart1AreaSeries1: TAreaSeries;
    Chart1LineSeries1: TLineSeries;
    Chart1LineSeries2: TLineSeries;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    GroupBox3: TGroupBox;
    GroupBox4: TGroupBox;
    GroupBox5: TGroupBox;
    GroupBox6: TGroupBox;
    Image1: TImage;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    OpenDialog1: TOpenDialog;
    RadioButton1: TRadioButton;
    RadioButton2: TRadioButton;
    RadioButton3: TRadioButton;
    RadioButton4: TRadioButton;
    RadioButton5: TRadioButton;
    RadioButton6: TRadioButton;
    RadioButton7: TRadioButton;
    RadioButton8: TRadioButton;
    RadioButton9: TRadioButton;
    SaveDialog1: TSaveDialog;
    SpeedButton1: TSpeedButton;
    SpeedButton2: TSpeedButton;
    SpeedButton3: TSpeedButton;
    SpeedButton4: TSpeedButton;
    SpeedButton5: TSpeedButton;
    SpeedButton6: TSpeedButton;
    SpeedButton7: TSpeedButton;
    SpeedButton8: TSpeedButton;
    SpinEdit1: TSpinEdit;
    SpinEdit2: TSpinEdit;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
    procedure FormCreate(Sender: TObject);
    procedure RadioButton1Click(Sender: TObject);
    procedure RadioButton2Click(Sender: TObject);
    procedure SpeedButton1Click(Sender: TObject);
    procedure SpeedButton2Click(Sender: TObject);
    procedure SpeedButton3Click(Sender: TObject);
    procedure SpeedButton4Click(Sender: TObject);
    procedure SpeedButton5Click(Sender: TObject);
    procedure SpeedButton6Click(Sender: TObject);
    procedure SpeedButton7Click(Sender: TObject);
    procedure SpeedButton8Click(Sender: TObject);
    procedure SpinEdit1Exit(Sender: TObject);
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
  about, LCLIntf;
  var
  // Para o caso de Pontos conhecidos
  n: Integer;
  // Para o caso de Funções conhecidas
  a, b, h, Integral: Extended;
  f: string;
  p, fp: Extended;
  Erro: Word;
  w, t: array[0..99] of Extended;
  nGauss: Integer;
  // Para os dois casos
  x, y: array[0..1000] of Extended;
  // LCLIntf para usar OpenDocument
  // Número de intervalos = n e número de pontos = n+1
  // Limites a, b, passo ou largura das faixas h, valor da Integral
  // Função
  // Ponto p e valor de f(p)
  // Erro ao avaliar a função com Interpretador.dll (0 = sem erro)
  // Pesos e pontos de Gauss
  // Número de pontos de Gauss
  // Pontos x e y = f(x) para calcular Integral e desenhar Gráfico
  function FxR1(f: String; x: Extended; var y: Extended): Word; stdcall; external 'Interpretador.dll';
  procedure PontosPesosGauss(nGauss: Integer);
  (*$I twConst.pas *)
  // Inclui arquivo twConst.pas com tabelas de (w, t) para Gauss
  var
  k: Integer;
  begin
  FillChar(w, SizeOf(w), 0);
  FillChar(t, SizeOf(t), 0);
  case nGauss of
  2: for k := 0 to 1 do
  begin
  w[k] := wConst2[k];
  t[k] := tConst2[k];
  end;
  4: for k := 0 to 3 do
  begin
  w[k] := wConst4[k];
  t[k] := tConst4[k];
  end;
  // Limpa vetores w, t
  // Carrega w, t da tabela de constantes para nGauss pontos
  8: for k := 0 to 7 do
  begin
  w[k] := wConst8[k];
  t[k] := tConst8[k];
  end;
  16: for k := 0 to 15 do
  begin
  w[k] := wConst16[k];
  t[k] := tConst16[k];
  end;
  32: for k := 0 to 31 do
  begin
  w[k] := wConst32[k];
  t[k] := tConst32[k];
  end;
  64: for k := 0 to 63 do
  begin
  w[k] := wConst64[k];
  t[k] := tConst64[k];
  end;
  100: for k := 0 to 99 do
  begin
  w[k] := wConst100[k];
  t[k] := tConst100[k];
  end;
  end;
  end;
  function DadosRepetidos(var r, s: Integer): Boolean;
  var
  i, j: Integer;
  begin
  Result := False;
  for i := 0 to n-1 do
  for j := i+1 to n do
  if x[i] = x[j] then
  begin
  r := i;
  s := j;
  Result := True;
  Exit;
  end;
  end;
  procedure OrdenarDados;
  var
  Trocou: Boolean;
  Auxiliar: Extended;
  i, j: Integer;
  begin
  // Ordena valores de forma crescente nos vetores x e y, mantendo os dados da grade como estão
  Trocou := True;
  j := n-1;
  while Trocou do
  begin
  Trocou := False;
  for i := 0 to j do
  if x[i] > x[i+1] then
  begin
  Auxiliar := x[i]; x[i] := x[i+1]; x[i+1] := Auxiliar;
  Auxiliar := y[i]; y[i] := y[i+1]; y[i+1] := Auxiliar;
  Trocou := True;
  end;
  j := j-1;
  end;
  end;
  function EspacamentoConstante: Boolean;
  var
  i: Integer;
  begin
  // Verifica se o espaçamentos dos valores x digitados, são constantes, com erro máximo de 1E-5
  Result := True;

  for i := 1 to n do
  if Abs( x[i]-x[i-1] - h ) / h > 1E-5 then
  begin
  Result := False;
  Break;
  end;
  end;
  // Funções para cálculo das Integrais
  // São chamadas pela rotina SpeedButton5Click
  // Só são chamadas se os dados de Pontos conhecidos ou Funções conhecidas foram testados
  function RetangulosE: Extended;
  var
     i:Integer;
     Erro, Soma, k, fx: Extended;
  begin
       Soma:=0;
       for i:=0 to n-1 do
       begin
            {k := x[0] + i*h;
            FxR1(f, k, fx);}
            Soma := Soma + y[i];
       end;
       Result := Soma*h;

  end;
  function RetangulosD: Extended;
  var
     i:Integer;
     Erro, Soma, k, fx: Extended;
  begin
       Soma:=0;
       for i:=1 to n do
       begin
            {k := x[0] + i*h;
            FxR1(f, k, fx);}
            Soma := Soma + y[i];
       end;
       Result := Soma*h;

  end;
  function Trapezios: Extended;
  var
     i:Integer;
     Erro, Area, k, ra, rb, fx: Extended;
  begin
       {FxR1(f, x[0], ra);
       FxR1(f, x[n], rb); }
       Area:=(y[0]+y[n])/2;
       for i:=1 to n-1 do
       begin
            {k := x[0] + i*h;
            FxR1(f, k, fx);}
            Area := Area + y[i];
       end;
       Result := Area*h;

  end;
  function Simpson13: Extended;
  var
     i:Integer;
     num: LongInt;
     Erro, k, ra, rb, fx, A4, A2: Extended;
  begin
     A4 := 0;
     A2 := 0;
     for i:=1 to n-1 do
     begin
        if((i mod 2) <> 0) then
        begin
              A4 := A4 + y[i];
        end
        else
        begin
             A2 := A2 + y[i];
        end;
     end;
     Result := h*(y[0]+y[n]+4*A4+2*A2)/3;

  end;
  function Simpson1_3: Extended;
  var
     i:Integer;
     num: LongInt;
     Erro, k, ra, rb, fx, A4, A2: Extended;
  begin
       FxR1(f, x[0], ra);
       FxR1(f, x[n], rb);
       A4 := 0;
       A2 := 0;
       num := Round(n/2);
       for i:=1 to num do
       begin
            k := x[0] + (2*i-1)*h;
            FxR1(f, k, fx);
            A4 := A4 + fx;
       end;
       for i:=1 to num - 1 do
       begin
            k := x[0] + (2*i)*h;
            FxR1(f, k, fx);
            A2 := A2 + fx;
       end;
       Result := h*(ra+rb+4*A4+2*A2)/3;

  end;
  function Simpson38: Extended;
  var
     i:Integer;
     Erro, k, ra, rb, fx, A3, A2: Extended;
  begin

       A3 := 0;
       A2 := 0;
       for i:=1 to n-1 do
       begin
            if((i mod 3) <> 0) then
            begin
                  A3 := A3 + y[i];
            end
            else
            begin
                 A2 := A2 + y[i];
            end;
       end;

       Result := 3*h*(y[0]+y[n]+3*A3+2*A2)/8;
  end;
  function Simpson3_8: Extended;
  var
     i:Integer;
     Erro, k, ra, rb, fx, A3, A2: Extended;
  begin
       FxR1(f, x[0], ra);
       FxR1(f, x[n], rb);
       A3 := 0;
       A2 := 0;
       for i:=1 to Round(n/3) do
       begin
            k := x[0] + (3*i-2)*h;
            FxR1(f, k, fx);
            A3 := A3 + fx;

            k := x[0] + (3*i-1)*h;
            FxR1(f, k, fx);
            A3 := A3 + fx;
       end;
       for i:=1 to Round(n/3) - 1 do
       begin
            k := x[0] + (3*i)*h;
            FxR1(f, k, fx);
            A2 := A2 + fx;
       end;
       Result := 3*h*(ra+rb+3*A3+2*A2)/8;
  end;
  function Gauss: Extended;
  var
     i:Integer;
     Erro, k, fx, Soma: Extended;
  begin
       Soma:=0;
       for i:=0 to nGauss-1 do
       begin
            k := (x[0]*(1-t[i]) + x[n]*(1+t[i]))/2;
            FxR1(f, k, fx);
            Soma := Soma + w[i]*fx;
       end;
       Soma := Soma/2;
       Result := (x[n] - x[0])*Soma;

  end;
  procedure TForm1.FormCreate(Sender: TObject);
  var
  i: Integer;
  begin
  // Tempo de hint de 20 segundos = 20000 ms
  Application.HintHidePause := 20000;
  // Textos para Informações (Hint) de alguns componentes
  // No GroupBox1
  RadioButton1.Hint := 'Integral numérica para pontos conhecidos:'#10#10+
  'Utilize esta opção para entrar com os'#10+
  'pontos conhecidos na tabela abaixo.'#10;
  SpinEdit1.Hint := 'Número de intervalos ( n ):'#10#10+
  'Para a seqüência de pontos ( x[i], y[i] ),'#10+
  'i = 0, ..., n, o total de pontos é n+1.'#10#10+
  'Entendeu, ou preciso fazer um desenho?'#10;
  // No GroupBox2
  RadioButton2.Hint := 'Integral numérica para função conhecida:'#10#10+
  'Utilize esta opção para entrar com'#10+
  'f, a, b e n, nos campos abaixo.'#10;
  Edit1.Hint := 'Função a ser integrada:'#10#10+
  'Escreva a expressão de f(x).'#10+
  'Os pontos ( x[i], y[i] ) serão calculados'#10+
  'considerando os valores de a, b e n.'#10;
  Edit2.Hint := 'Limite inferior de integração:'#10#10+
  'O valor de x[0] é o limite inferior da integração.'#10;
  Edit3.Hint := 'Limite superior de integração:'#10#10+
  'O valor de x[n] é o limite superior da integração.'#10;
  SpinEdit2.Hint := 'Número de intervalos entre os pontos:'#10#10+
  'O número de intervalos é n.'#10+
  'O tamanho de cada intervalo é h = (x[n]-x[0])/n.'#10;
  CheckBox1.Hint := 'Preencher tabela:'#10#10+
  'Habilite para ver os pontos calculados'#10+
  'na tabela Pontos dados ou calculados.'#10;
  // No GroupBox3
  SpeedButton1.Hint := 'Abrir:'#10#10+
  'Permite selecionar arquivo de dados'#10+
  'para preencher a grade dos pontos ou'#10+
  'para preencher informações de função.'#10;
  SpeedButton2.Hint := 'Salvar:'#10#10+
  'Permite salvar arquivo com dados'#10+
  'da grade dos pontos ou dados de'#10+
  'informação de função de um problema.'#10#10+
  'Os dados salvos são relativos aos'#10+
  'pontos ou função, conforme o tipo'#10+
  'de problema em uso.'#10;
  SpeedButton3.Hint := 'Habilitar tabela de entrada de dados:'#10#10+
  'Deve-se habilitar a entrada de dados quando'#10+
  '- o número n+1 de pontos for alterado;'#10+
  '- mudar da opção Função conhecida para Pontos conhecidos.'#10;
  SpeedButton4.Hint := 'Limpar dados de cálculos anteriores:'#10#10+
  'Limpa todos os dados entrados pelo usuário'#10+
  'e todos os valores e gráficos calculados.'#10;
  SpeedButton5.Hint := 'Calcular integral e desenha gráficos:'#10#10+
  'Para Pontos conhecidos, desenha os pontos e trapézios para representar a área aproximada.'#10+
  'Para Função conhecida, desenha os pontos, os trapézios e a função dada.'#10;
  SpeedButton6.Hint := 'Ampliar gráfico:'#10#10+
  'Apresenta apenas a região do gráfico ampliada.'#10+
  'Cutuque e veja a coisa funcionando.'#10+
  'E se não quiser ver, não cutuque.'#10#10+
  'Mas é interessante.'#10+
  'Acho que você deveria cutucar.'#10#10+
  'Patricinha e Joãozinho unissonamente:'#10+
  'Mas como fazer isto?'#10#10+
  'Isto não faz parte de MNC.'#10+
  'Mas poderão aprender a fazer isto em PAW. :-)'#10#10+
  'Patricinha:'#10+
  'Vou me matricular na disciplina. ;-)'#10#10+
  'Joãozinho:'#10+
  'Vou aprender sozinho consultando o Gúgou. :-0'#10#10+
  'Patricinha:'#10+
  'Se é com o Gúgou, não é sozinho.'#10#10+
  'Joãozinho:'#10+
  'Tá bom, vou encontrar 15 bilhões de informações, mas farei isto sozinho.'#10#10+
  'Patricinha:'#10+
  'Quer saber de uma coisa?'#10#10+
  'Joãozinho:'#10+
  'Quero. Fale se for mulher.'#10#10+
  'Patricinha:'#10+
  'Você é um ...'#10#10+
  'Cartão vermelho para a Patricinha, novamente.'#10+
  'Fim da aula.'#10+
  'O que aconteceu depois, não sei.'#10+
  'Mas curse PAW, é muito LEGAW.'#10+
  '__________________________________________________________'#10#10+
  'Se você não sabe quem são MNC, Patricinha, Joãozinho ou PAW, então:'#10+
  '- você é um aluno que nunca leu MNC-MARS.pdf;'#10+
  '- você é um pirata que está utilizando o programa indevidamente.'#10;
  SpeedButton7.Hint := 'Ajuda:'#10#10+
  'Apresenta o arquivo de ajuda, caso exista.'#10#10+
  'Pois é, se não existir, não apresenta. :-)'#10;
  SpeedButton8.Hint := 'Informação:'#10#10+
  'Apresenta informações sobre autoria e direitos.'#10#10+
  'Cuidado: Pirataria é crime. :-('#10;
  CheckBox2.Hint := 'Apresentar os pontos:'#10#10+
  'Habilite para ver os pontos no gráfico.'#10#10+
  'Se a quantidade de pontos for muito grande será,'#10+
  'visto um traço grosso vermelho dos pontos justapostos.'#10#10+
  'Portanto, use esta opção de forma adequada.'#10;

  // No GroupBox4
  Label8.Hint := 'Certamente é o seu texto preferido.'#10#10+
  'E se não for, não me deixe saber disto. :-)'#10;
  // No GroupBox5
  StringGrid1.Hint := 'Pontos dados ou calculados:'#10#10+
  'Para pontos dados, o espaçamento deve ser constante.'#10+
  'Não há necessidade de entrar com os dados ordenados.'#10#10+
  'Para função dada, os valores serão apresentados'#10+
  'se a opção Preencher tabela estiver habilitada.'#10;
  // No GroupBox6
  StringGrid2.Hint := 'Solução numérica:'#10#10+
  'Apresenta solução para cada método.'#10#10+
  'Se houver erro, a mensagem será'#10+
  'apresentada na coluna Resultado.'#10;
  Image1.Hint := 'Homenagem ao Toninho:'#10#10+
  'Viva o Toninho!'#10+
  'Viva!'#10#10+
  'Se você não entendeu, deve ser um desses'#10+
  'piratas que usam programas indevidamente.'#10;
  // Botão Zoom out escondido
  //SpeedButton6B.Visible := False; ----------------------------------------------------------------
  // Diferentes versões do Windows tem diferentes tamanhos para elementos de grade
  // Este programa foi desenvolvido e compilado com Windows XP
  // No Windows XP DefaultRowHeight = 20, mas no Windows 10, por exemplo, é maior
  // Para ficar correto, seguem as linhas que forçam DefaultRowHeight = 20 para todas as versões
  // Se o programa for executado apenas em Windows XP estas linhas são absolutamente desnecessárias
  StringGrid1.DefaultRowHeight := 20;
  StringGrid2.DefaultRowHeight := 20;
  // Tamanho e texto da Grade 1
  with StringGrid1 do
  begin
  ColWidths[0] := 30;
  ColWidths[1] := 84;
  ColWidths[2] := 84;
  Width := 220;
  // Projetado com Windows XP, mas deve funcionar em outras versões
  Height := 22*20+4;
  Cells[0,0] := 'i';
  Cells[1,0] := 'x[i]';
  Cells[2,0] := 'y[i]';
  for i := 1 to 1001 do
  Cells[0,i] := IntToStr(i-1);
  end;
  RadioButton1.Checked := True;
  // Texto da Grade 2
  with StringGrid2 do
  begin
  Cells[0,0] := 'Método';
  Cells[1,0] := 'Resultado';
  Cells[0,1] := 'Retângulos à Esquerda';
  Cells[0,2] := 'Retângulos à Direita';
  Cells[0,3] := 'Regra dos Trapézios';
  Cells[0,4] := 'Regra 1/3 de Simpson';
  Cells[0,5] := 'Regra 3/8 de Simpson';
  Cells[0,6] := 'Regra Gauss';
  end;
  // A fôrma é criada com RadioButton1 marcado e, então, n inicial é o valor de SpinEdit1
  n := SpinEdit1.Value;
  end;
  procedure TForm1.RadioButton1Click(Sender: TObject);
  begin
  // Entrada de dados para Pontos conhecidos
  SpinEdit1.Enabled := True;
  Edit1.Enabled := False;
  Edit2.Enabled := False;
  Edit3.Enabled := False;
  SpinEdit2.Enabled := False;
  CheckBox1.Enabled := False;
  StringGrid1.Options := StringGrid1.Options+[goEditing];
  if StringGrid1.CanSetFocus then
  SpinEdit1Exit(Self);
  end;
  procedure TForm1.RadioButton2Click(Sender: TObject);
  begin
  // Entrada de dados para Funções conhecidas
  SpinEdit1.Enabled := False;
  Edit1.Enabled := True;
  Edit2.Enabled := True;
  Edit3.Enabled := True;
  SpinEdit2.Enabled := True;
  CheckBox1.Enabled := True;
  StringGrid1.Options := StringGrid1.Options-[goEditing];
  end;
  procedure TForm1.SpeedButton1Click(Sender: TObject);
  var
  Lista: TStringList;
  // Lista de cadeias de caracteres dos dados, para ler em arquivos
  i: Integer;
  begin
  // Abrir arquivo, ler dados e preencher campos
  if not OpenDialog1.Execute then // Se não informou arquivo, cai fora
  Exit;
  Lista := TStringList.Create;
  // Cria Lista
  Lista.LoadFromFile(OpenDialog1.FileName);
  if Lista[0] = 'Pontos' then
  // Pontos dados
  begin
  RadioButton1.Checked := True;
  SpinEdit1.Value := StrToInt(Lista[1]);
  StringGrid1.Clean([gzNormal]); // Limpar grade de Pontos dados ou calculados
  StringGrid1.TopRow := 1;
  // Rolar grade para ficar com a linha 1 no topo
  for i := 0 to SpinEdit1.Value do
  StringGrid1.Cells[1,i+1] := Lista[i+2];
  for i := 0 to SpinEdit1.Value do
  StringGrid1.Cells[2,i+1] := Lista[SpinEdit1.Value+i+3];
  SpeedButton3.Click;
  Lista.Free;
  Exit;
  end;
  if Lista[0] = 'Função' then
  // Ajustar grade (cores e células editáveis)
  // Libera e destroi Lista para reduzir uso de memória
  // Função dada
  begin
  RadioButton2.Checked := True;
  Edit1.Text := Lista[1];
  Edit2.Text := Lista[2];
  Edit3.Text := Lista[3];
  SpinEdit2.Value := StrToInt(Lista[4]);
  CheckBox1.Checked := Lista[5] = '1';
  RadioButton3.Checked := Lista[6] = '2';
  RadioButton4.Checked := Lista[6] = '4';
  RadioButton5.Checked := Lista[6] = '8';
  RadioButton6.Checked := Lista[6] = '16';
  RadioButton7.Checked := Lista[6] = '32';
  RadioButton8.Checked := Lista[6] = '64';
  RadioButton9.Checked := Lista[6] = '100';
  Lista.Free;
  // Libera e destroi Lista para reduzir uso de memória
  Exit;
  end;
  end;
  procedure TForm1.SpeedButton2Click(Sender: TObject);
  var
  Lista: TStringList;
  // Lista de cadeias de caracteres dos dados, para salvar em arquivos
  i: Integer;
  begin
  // Salvar arquivo com dados dos campos preenchidos
  Lista := TStringList.Create;
  // Cria Lista
  if RadioButton1.Checked then
  // Pontos dados
  begin
  Lista.Add('Pontos');
  Lista.Add(IntToStr(SpinEdit1.Value));

  for i := 1 to SpinEdit1.Value+1 do
  Lista.Add(StringGrid1.Cells[1,i]);
  for i := 1 to SpinEdit1.Value+1 do
  Lista.Add(StringGrid1.Cells[2,i]);
  if SaveDialog1.Execute then
  Lista.SaveToFile(SaveDialog1.FileName);
  Lista.Free;
  Exit;
  end;
  if RadioButton2.Checked then
  // Libera e destroi Lista para reduzir uso de memória
  // Função dada
  begin
  Lista.Add('Função');
  Lista.Add(Edit1.Text);
  Lista.Add(Edit2.Text);
  Lista.Add(Edit3.Text);
  Lista.Add(IntToStr(SpinEdit2.Value));
  if CheckBox1.Checked then Lista.Add('1') else Lista.Add('0');
  if RadioButton3.Checked then Lista.Add('2');
  if RadioButton4.Checked then Lista.Add('4');
  if RadioButton5.Checked then Lista.Add('8');
  if RadioButton6.Checked then Lista.Add('16');
  if RadioButton7.Checked then Lista.Add('32');
  if RadioButton8.Checked then Lista.Add('64');
  if RadioButton9.Checked then Lista.Add('100');
  if SaveDialog1.Execute then
  Lista.SaveToFile(SaveDialog1.FileName);
  Lista.Free;
  Exit;
  end;
  end;

  procedure TForm1.SpeedButton3Click(Sender: TObject);
  begin
  // Habilitar grade para a quantidade de pontos estabelecidos
  if RadioButton2.Checked then
  // Libera e destroi Lista para reduzir uso de memória
  // Se Função conhecida, não habilita
  begin
  ShowMessage('Habilitar Tabela de entrada de dados é uma opção para Pontos conhecidos.'#10+
  'Para Função conhecida, os pontos serão calculados e poderão ser apresentados.'#10+
  'Para apresentá-los, marque a opção Preencher tabela.');
  Exit
  end;
  n := SpinEdit1.Value;
  StringGrid1.SetFocus;
  StringGrid1.Refresh;
  end;
  procedure TForm1.SpeedButton4Click(Sender: TObject);
  begin
  // Limpar grades, dados e gráficos
  with StringGrid1 do
  begin
  SpinEdit1.Value := 20;
  Edit1.Text := '';
  Edit2.Text := '';
  Edit3.Text := '';
  SpinEdit2.Value := 20;
  CheckBox1.Checked := False;
  CheckBox2.Checked := False;
  RadioButton5.Checked := True;
  StringGrid1.Clean([gzNormal]);
  StringGrid2.Clean([gzNormal]);
  Chart1LineSeries1.Clear;
  Chart1LineSeries2.Clear;
  Chart1AreaSeries1.Clear;
  n := 20;
  end;
  end;
  // Se Pontos conhecidos, habilita

  procedure TForm1.SpeedButton5Click(Sender: TObject);
  var
  i: Integer;
  r, s: Integer;
  begin
  // Resolver os problemas para ▌1 Pontos dados▐ e ▌2 Função dada▐
  // ▌1 Pontos dados▐
  if RadioButton1.Checked then
  begin
  n := SpinEdit1.Value;
  with StringGrid1 do
  begin
  // Ler coluna x da grade e armazenar no vetor x
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
  // Ler coluna y da grade e armazenar no vetor y
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
  // Verificar se há valores de x repetidos
  if DadosRepetidos(r, s) then
  begin
  ShowMessage('Os valores de x['+IntToStr(r)+'] e de x['+IntToStr(s)+'] são iguais.'#10+
  'Remova ou altere os dados repetidos para valores de x.');
  Exit;
  end;
  // Ordenar os dados com x crescente
  OrdenarDados;
  // Calcular espaçamento constante h para comparações dos espaçamentos de x e para utilizar nos métodos
  h := (x[n]-x[0])/n;
  // Verificar se espaçamento é constante
  if not EspacamentoConstante then
  begin
  ShowMessage('Os valores de x, já ordenados, não apresentam espaçamento constante.'#10+
  'A tolerância utilizada foi 1E-5 para calcular o erro relativo.'#10+
  'Este método requer espaçamento constante para valores de x.');
  Exit;
  end;
  // Executar cada Método (RetangulosE, RetangulosD, Trapezios, Simpson13, Simpson38)
  try
  StringGrid2.Cells[1,1] := FloatToStr(RetangulosE);
  except
  StringGrid2.Cells[1,1] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,2] := FloatToStr(RetangulosD);
  except
  StringGrid2.Cells[1,2] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,3] := FloatToStr(Trapezios);
  except
  StringGrid2.Cells[1,3] := 'Erro ao calcular a integral';
  end;

  try
  StringGrid2.Cells[1,4] := FloatToStr(Simpson13);
  except
  StringGrid2.Cells[1,4] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,5] := FloatToStr(Simpson38);
  except
  StringGrid2.Cells[1,5] := 'Erro ao calcular a integral';
  end;
  // Não se calcula Integral de Gaus com Pontos Dados
  StringGrid2.Cells[1,6] := 'Não se aplica a pontos';
  // Desenhar pontos dados e trapézios representativos de áreas aproximadas
  Chart1LineSeries1.Clear;
  Chart1LineSeries2.Clear;
  Chart1AreaSeries1.Clear;
  for i := 0 to n do
  begin
  if CheckBox2.Checked then
  Chart1LineSeries1.AddXY(x[i],y[i]);
  Chart1LineSeries2.AddXY(x[i],y[i]);
  Chart1AreaSeries1.AddXY(x[i],y[i]);
  end;
  end;
  // ▌2 Função dada▐
  if RadioButton2.Checked then
  begin
  f := Trim(Edit1.Text);
  if f = '' then
  begin
  ShowMessage('Informe a função.');
  Edit1.SetFocus;
  Exit;
  end;
  try
  a := StrToFloat(Edit2.Text);
  except
  ShowMessage('Valor de a incorreto.');
  Edit2.SetFocus;
  Exit;
  end;
  try
  b := StrToFloat(Edit3.Text);
  except
  ShowMessage('Valor de b incorreto.');
  Edit3.SetFocus;
  Exit;
  end;
  if b <= a then
  begin
  ShowMessage('b deve ser maior que a.');
  Edit3.SetFocus;
  Exit;
  end;
  n := SpinEdit2.Value;
  // Calcular espaçamento constante h para calcular os pontos e utilizar nos métodos
  h := (b-a)/n;
  for i := 0 to n do
  begin
  p := a+i*h;
  Erro := FxR1(f, p, fp);
  if Erro <> 0 then
  begin
  ShowMessage('Erro ao avaliar f(x) no ponto '+FloatToStr(p)+'.');
  Exit;
  end;
  x[i] := p;
  y[i] := fp;
  end;

  if CheckBox1.Checked then
  begin
  StringGrid1.Clean([gzNormal]);
  StringGrid1.TopRow := 1;
  // Apresenta pontos calculados da função dada
  // Limpar grade de Pontos dados ou calculados
  // Rolar grade para ficar com a linha 1 no topo
  // Habilitar grade para a quantidade de pontos estabelecidos
  SpinEdit1.Value := SpinEdit2.Value;
  StringGrid1.SetFocus;
  StringGrid1.Refresh;
  for i := 0 to n do
  begin
  StringGrid1.Cells[1,i+1] := FloatToStr(x[i]);
  StringGrid1.Cells[2,i+1] := FloatToStr(y[i]);
  end;
  end;
  // Definir número de pontos para Método de Gauss (nGauss)
  if RadioButton3.Checked then
  nGauss := 2;
  if RadioButton4.Checked then
  nGauss := 4;
  if RadioButton5.Checked then
  nGauss := 8;
  if RadioButton6.Checked then
  nGauss := 16;
  if RadioButton7.Checked then
  nGauss := 32;
  if RadioButton8.Checked then
  nGauss := 64;
  if RadioButton9.Checked then
  nGauss := 100;
  // Carregar vetores w, t para número de pontos definido
  PontosPesosGauss(nGauss);
  // Executar cada Método (RetangulosE, RetangulosD, Trapezios, Simpson13, Simpson38, Gauss)
  try
  StringGrid2.Cells[1,1] := FloatToStr(RetangulosE);
  except
  StringGrid2.Cells[1,1] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,2] := FloatToStr(RetangulosD);
  except
  StringGrid2.Cells[1,2] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,3] := FloatToStr(Trapezios);
  except
  StringGrid2.Cells[1,3] := 'Erro ao calcular a integral';
  end;

  try
  StringGrid2.Cells[1,4] := FloatToStr(Simpson1_3);
  except
  StringGrid2.Cells[1,4] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,5] := FloatToStr(Simpson3_8);
  except
  StringGrid2.Cells[1,5] := 'Erro ao calcular a integral';
  end;
  try
  StringGrid2.Cells[1,6] := FloatToStr(Gauss);
  except
  StringGrid2.Cells[1,6] := 'Erro ao calcular a integral';
  end;
  // Desenhar pontos dados e trapézios representativos de áreas aproximadas
  Chart1LineSeries1.Clear;
  Chart1LineSeries2.Clear;
  Chart1AreaSeries1.Clear;
  for i := 0 to n do
  begin
  if CheckBox2.Checked then
  Chart1LineSeries1.AddXY(x[i],y[i]);
  Chart1LineSeries2.AddXY(x[i],y[i]);
  Chart1AreaSeries1.AddXY(x[i],y[i]);
  end;
  end;
  end;
procedure TForm1.SpeedButton6Click(Sender: TObject);
begin
// Zoom
{Aqui foi feita a rotina que destaca o
gráfico, colocando o componente
em uma fôrma redimensionável.
Assunto para PAW.}
end;
{procedure TForm1.SpeedButton6BClick(Sender: TObject);
begin
// Zoom out
{Aqui foi feita a rotina que recoloca
o gráfico na fôrma principal não
redimensionável.
Assunto para PAW.}
end; }
procedure TForm1.SpeedButton7Click(Sender: TObject);
begin
// Ajuda
// Você pode fazer um arquivo Integrais.chm ou um arquivo Integrais.pdf ou um simples arquivo Integrais.txt
// Escreva o nome do seu arquivo de ajuda na função OpenDocument
if not OpenDocument('IntegraisNumericas.chm') then
MessageDlg('Informação','Arquivo de Ajuda'+#10+'IntegraisNumericas.chm'+#10+'não foi encontrado.',
mtInformation, [mbOk], 0);
end;
procedure TForm1.SpeedButton8Click(Sender: TObject);
begin
// Informa
Form2.ShowModal;
end;
{No programa exemplo, há um
About box com uma fôrma
irregular arrastável com som e
outras coisa bregas. Use e
descubra as várias habilidades
disponíveis.
Assunto para PAW. }
procedure TForm1.SpinEdit1Exit(Sender: TObject);
begin
// Ao sair do campo SpinEdit1, executar automaticamente SpeedButton3Click para redimensionar a grade
SpeedButton3.Click;
end;

procedure TForm1.StringGrid1PrepareCanvas(sender: TObject; aCol, aRow: Integer;
aState: TGridDrawState);
begin
// Ao desenhar a grade, deixar células editáveis brancas e não editáveis cinzas
with StringGrid1 do
if (aCol > 0) and (aRow > n+1) then
Canvas.Brush.Color := $00F0F0F0;
end;
procedure TForm1.StringGrid1SelectCell(Sender: TObject; aCol, aRow: Integer;
var CanSelect: Boolean);
begin
// Não permitir edição nas células não editáveis cinzas
if RadioButton2.Checked then
Exit;
if ARow > n+1 then
CanSelect := False;
end;
end.

