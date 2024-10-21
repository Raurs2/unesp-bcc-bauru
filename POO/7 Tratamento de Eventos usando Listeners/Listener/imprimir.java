import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Janela extends JFrame {
  JButton bt1, bt2;

  Janela() {
    super("Action Listener");
    setLayout(new FlowLayout( ));
    bt1 = new JButton("Passe o cursor do mouse neste Botao");
    bt2 = new JButton("Botao 2");
    add(bt1);
    add(bt2);

    bt1.addMouseMotionListener(new MouseMotionAdapter() {    //classe interna listener sem nome
      //public void mouseDragged(MouseEvent e) {
      public void mouseMoved(MouseEvent e) {
        Point p=bt1.getLocation();
        System.out.println(e.getX()+","+e.getY());
        bt1.setLocation(p.x+e.getX()-bt1.getSize().width/2, p.y+e.getY()-bt1.getSize().height/2);
      }
    });

    setSize(800, 600);
    setVisible(true);
  }
}

class Listenr10 {
  static public void main(String[] args) {
    Janela f = new Janela();
  }
}
