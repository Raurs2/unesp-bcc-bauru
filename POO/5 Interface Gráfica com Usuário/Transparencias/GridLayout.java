import java.awt.*; //importa awt
class LayoutGrade extends Frame { //cria classe herdando Frame
 LayoutGrade( ) { //construtor da classe
 super("GridLayout"); // titulo da janela
 setLayout(new GridLayout(3, 2)); // faz o layout ser do tipo grade de 3 linhas e 2 coluna
 add(new Button("Botao 1")); //adiciona instancia de Button escrito Botao 1 na janela
 add(new Button("2")); //adiciona instancia de Button escrito 2 na janela
 add(new Button("Botao 3")); //adiciona instancia de Button escrito Botao 3 na janela
 add(new Button("4")); //adiciona instancia de Button escrito 4 na janela
 add(new Button("Botao 5")); //adiciona Button escrito Botao 5 na janela
 pack( ); //dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais
 setVisible(true); //deixa janela visivel
 }
 static public void main(String[] args) { //cria metodo principal
 new LayoutGrade( );// instancia classe LayoutGrade
 }
} 