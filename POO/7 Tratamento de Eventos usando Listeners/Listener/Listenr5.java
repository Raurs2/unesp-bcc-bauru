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

    bt1.addActionListener(new Escutador());
    bt2.addActionListener(new Escutador());

    pack();
    setVisible(true);
  }

  class Escutador implements ActionListener {
    public void actionPerformed(ActionEvent e) {
      if (e.getSource() == bt1) {
        System.out.println("Botao 1");
      } else {
        System.out.println("Botao 2");
      }
    }
  }

}

class Listenr5 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
