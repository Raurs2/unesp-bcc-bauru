import java.awt.*;
import javax.swing.*;
class Ex01 extends JFrame {
    JButton bAbrir = new JButton("Abrir");
    JButton bSalva = new JButton("Salvar");
    JButton bSComo = new JButton("Salvar Como");
    JButton bFecha = new JButton("Fechar");
    JTextArea texto = new JTextArea("Digite texto nesta área\n                          com\n                             várias\n                                  linhas.", 10, 40);
    
    Ex01() {
        super("Editor de Texto");

        JPanel p = new JPanel(new GridLayout(4, 1));
        p.add(bAbrir);
        p.add(bSalva);
        p.add(bSComo);
        p.add(bFecha);

        JPanel r = new JPanel(new GridLayout(2, 2));
        r.add(p, BorderLayout.WEST);
        
        add(r, BorderLayout.WEST);
        add(texto, BorderLayout.EAST);

        pack();
        setVisible(true);
    }
    
    public static void main(String s[]) {
        new Ex01();
    }
}
