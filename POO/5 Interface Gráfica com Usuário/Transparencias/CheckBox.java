import java.awt.*; //importa awt
class CaixaVerif extends Frame { // cria classe herdando Frame
 Checkbox cb = new Checkbox("Caixa de Verificação"); // cria instancia de Checkbox cb escrito Caixa de Verificação
 CaixaVerif( ) { //construtor da classe
 super("Checkbox"); // titulo da janela
 add(cb); // adiciona cb na janela
 pack( ); //dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais
 setVisible(true); //deixa janela visivel
 }
 static public void main(String[] args) { //cria metodo principal
 new CaixaVerif( ); // Cria objeto da classe CaixaVerif
 }
}
