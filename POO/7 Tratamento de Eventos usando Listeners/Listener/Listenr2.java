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

    EscutadorDoBotao l = new EscutadorDoBotao();
    bt1.addActionListener(l);
    bt2.addActionListener(l);

    pack();
    setVisible(true);
  }
}

class EscutadorDoBotao implements ActionListener {
  public void actionPerformed(ActionEvent e) {
    if (((JButton)e.getSource()).getText().equals("Botao 1")) {
      System.out.println("Botao 1");
    } else {
      System.out.println("Botao 2");
    }
  }
}

class Listenr2 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
