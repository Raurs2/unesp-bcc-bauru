import java.awt.*;
import javax.swing.*;

class Ex02 extends JFrame {
    JButton sum = new JButton("Soma");
    JButton sub = new JButton("Subtrai");
    JButton multi = new JButton("Multiplica");
    JButton div = new JButton("Divide");

    JTextField n1 = new JTextField(10);
    JTextField n2 = new JTextField(10);

    JLabel eq = new JLabel("=");
    JLabel res = new JLabel("0");
    
    Ex02() {
        super("Calculadora");

        JPanel p = new JPanel(new GridLayout(4, 1));
        p.add(sum);
        p.add(sub);
        p.add(multi);
        p.add(div);

        setLayout(new FlowLayout());

        add(n1);
        add(p);
        add(n2);
        add(eq);
        add(res);

        pack();
        setVisible(true);
    }
    
    public static void main(String s[]) {
        new Ex02();
    }
}
