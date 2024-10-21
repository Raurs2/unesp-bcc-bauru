import java.awt.*;
import javax.swing.*;

class Ex03 extends JFrame {
    JButton calc = new JButton("Calcular");

    JComboBox<String> op = new JComboBox<String>();

    JTextField n1 = new JTextField(10);
    JTextField n2 = new JTextField(10);

    JLabel eq = new JLabel("=");
    JLabel res = new JLabel("0");
    
    Ex03() {
        super("Calculadora");
        
        op.addItem("Soma");
        op.addItem("Subtrai");
        op.addItem("Multiplica");
        op.addItem("Divide");

        JPanel p = new JPanel(new FlowLayout());
        p.add(n1);
        p.add(op);
        p.add(n2);
        p.add(eq);
        p.add(res);

        add(p, BorderLayout.NORTH);
        add(calc, BorderLayout.SOUTH);
        
        pack();
        setVisible(true);
    }
    
    public static void main(String s[]) {
        new Ex03();
    }
}
