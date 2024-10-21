import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.InvocationTargetException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;

public class TestaThreadWait extends JFrame implements Runnable, ActionListener {
  JProgressBar pBar = new JProgressBar(JProgressBar.HORIZONTAL, 0, 10);
  JButton b = new JButton("Inicia");
  int cont = 0;

  TestaThreadWait( ) {
    super("Thread com Swing");
    setLayout(new FlowLayout());
    add(b);
    add(pBar);
    b.addActionListener(this);
    pack( );
    setVisible(true);
  }

  public void actionPerformed(ActionEvent e) {
    cont = 0;
    pBar.setValue(cont);
    new Thread(this).start();
  }

  public void run() {
    try {
      while (cont <= 10) {
        SwingUtilities.invokeAndWait(new Runnable() {
          public void run() {
            pBar.setValue(cont++);
          }
        });
        Thread.sleep(1000);
      }
    } catch (InterruptedException e) {}
      catch (InvocationTargetException er) {}
  }

  static public void main(String[] args) {
    new TestaThreadWait( );
  }

}
