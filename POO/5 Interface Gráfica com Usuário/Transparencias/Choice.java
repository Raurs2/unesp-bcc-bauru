import java.awt.*; //importa awt
class Escolha extends Frame { // cria classe herdando Frame
 Escolha( ) { //construtor da classe
 super("Choice"); // titulo da janela
 Choice choice = new Choice(); //Cria instancia de Choice choice
 choice.addItem("Item 1"); //adiciona item 1 em choice
 choice.addItem("Item 2"); //adiciona item 2 em choice
 add(choice); // //adiciona choice na janela
 pack( ); // dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais
 setVisible(true); //deixa janela visivel
 }
 static public void main(String[] args) { //cria metodo principal
 new Escolha( ); // Cria objeto da classe Escolha
 }
}