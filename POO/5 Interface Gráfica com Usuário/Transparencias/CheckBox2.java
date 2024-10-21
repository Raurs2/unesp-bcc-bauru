import java.awt.*; //importa awt
class CaixaVerif1 { // cria classe 
 static public void main(String[] args) { //cria metodo principal
 Checkbox cb = new Checkbox("Caixa de Verificação"); // cria instancia de Checkbox cb escrito Caixa de Verificação
 Frame f = new Frame("CheckBox"); //cria instancia de frame f com titulo CheckBox
 f.add(cb); //adiciona cb no f
 f.pack( );  //dimensiona a janela  para caber todos os componentes e layouts com seus tamanhos ideais
 f.setVisible(true); //deixa janela visivel
 }
}