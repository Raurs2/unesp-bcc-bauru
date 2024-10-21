import java.awt.*;
import javax.swing.*;

class HelloWorld extends JFrame {
  public void paint(Graphics g) {
    g.drawString("Hello world!", 40, 100);
  }
  
  public static void main(String args[]) {
    HelloWorld hello=new HelloWorld();    
    hello.setSize(155, 150);
    hello.setDefaultCloseOperation(
                         JFrame.EXIT_ON_CLOSE);
    hello.setVisible(true);
  }
}
