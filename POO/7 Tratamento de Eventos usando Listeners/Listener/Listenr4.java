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

    bt1.addActionListener(new ListenerBotao1());  //dois listeners para um unico botao
    bt1.addActionListener(new ListenerBotao2());
    bt2.addActionListener(new ListenerBotao2());

    pack();
    setVisible(true);
  }
}

class ListenerBotao1 implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    System.out.println("Botao 1(a)");
  }
}

class ListenerBotao2 implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    System.out.println("Botao 1(b) ou Botao 2");
  }
}

class Listenr4 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
