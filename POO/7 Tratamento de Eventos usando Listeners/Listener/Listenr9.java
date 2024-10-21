import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Janela extends JFrame {
  JButton bt1, bt2;

  Janela() {
    super("Action Listener");
    setLayout(new FlowLayout( ));
    add(bt1 = new JButton("Botao 1"));
    add(bt2 = new JButton("Botao 2"));

    addWindowListener(new WindowAdapter() {    //classe interna listener sem nome
      public void windowClosing(WindowEvent e) {
		  int opc=JOptionPane.showConfirmDialog(null, "Vai fechar mesmo?", "Despedida",
                    JOptionPane.YES_NO_OPTION);
          if (opc == 0)
              System.exit(0);
      }
    });
    setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
    pack();
    setVisible(true);
  }
}

class Listenr9 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
