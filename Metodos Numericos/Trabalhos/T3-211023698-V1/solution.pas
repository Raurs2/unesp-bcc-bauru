unit solution;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Grids;

type

  { TForm2 }

  TForm2 = class(TForm)
    GroupBox1: TGroupBox;
    GroupBox2: TGroupBox;
    Label1: TLabel;
    StringGrid1: TStringGrid;
    StringGrid2: TStringGrid;
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
  firstTime: Boolean;
  F2L, F2T: Integer;
procedure TForm2.FormCreate(Sender: TObject);
begin
  Left := (Screen.Width-Width) div 2;
  Top := (Screen.Height-Height) div 2;
  firstTime := True;
end;
procedure TForm2.FormShow(Sender: TObject);
begin
  if firstTime then
  Exit;
  Left := F2L;
  Top := F2T;
end;
procedure TForm2.FormCloseQuery(Sender: TObject; var CanClose: boolean);
begin
  firstTime := False;
  F2L := Left;
  F2T := Top;
  CanClose := True;
end;

end.

