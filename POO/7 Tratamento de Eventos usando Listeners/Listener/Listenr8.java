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

    bt1.addActionListener(new ActionListener() {    //classe interna listener sem nome
      public void actionPerformed(ActionEvent e) {
        System.out.println("Botao 1");
      }
    });

    bt2.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        System.out.println("Botao 2");
      }
    });

    pack();
    setVisible(true);
  }
}

class Listenr8 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
