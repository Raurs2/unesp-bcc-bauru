import java.awt.*; //importa awt
public class Botao extends Frame { // cria classe herdando Frame
 Button b = new Button("Aperte-me"); // cria instancia de Button escrito Aperte-me
 Botao( ) { //construtor da classe
 super("Botao"); // titulo da janela
 add(b); // adiciona botao na janela
 pack( ); //dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais 
 setVisible(true); //deixa janela visivel
 }
 
 static public void main(String[] args) { //cria metodo principal
 new Botao( ); // Cria objeto da classe Botao
 }
}
