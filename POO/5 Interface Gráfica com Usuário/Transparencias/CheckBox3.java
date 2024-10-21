import java.awt.*; //importa awt
class CaixaVerif2 extends Frame { // cria classe herdando Frame
 Checkbox cb1 = new Checkbox("Verificação UM"); //cria instancia de Checkbox cb1 escrito Verificação UM
 Checkbox cb2 = new Checkbox("Verificação DOIS"); //cria instancia de Checkbox cb2 escrito Verificação DOIS
 CaixaVerif2( ) { //construtor da classe
 super("Checkbox"); // titulo da janela
 setLayout(new GridLayout(2, 1)); // faz o layout ser do tipo grid de 2 linhas e 1 coluna
 add(cb1); //adiciona cb1 na janela
 add(cb2); //adiciona cb2 na janela
 pack( ); //dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais
 setVisible(true); //deixa janela visivel
 }
 static public void main(String[] args) { //cria metodo principal
 new CaixaVerif2( ); // instancia classe CaixaVerif2
 }
}