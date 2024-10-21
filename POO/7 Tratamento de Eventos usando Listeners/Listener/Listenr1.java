import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Janela extends JFrame implements ActionListener {
  JButton bt1, bt2;

  Janela() {
    super("Action Listener");
    setLayout(new FlowLayout( ));
    add(bt1 = new JButton("Botao 1"));
    add(bt2 = new JButton("Botao 2"));

    bt1.addActionListener(this);
    bt2.addActionListener(this);

    pack();
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == bt1) {
      System.out.println("Botao 1");
    } else {
      System.out.println("Botao 2");
    }
  }

};

class Listenr1 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
