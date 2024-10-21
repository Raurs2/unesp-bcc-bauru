import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;

//Raul Alexandre Gonzalez Augusto

class Ex01 extends JFrame{
    JButton bAbrir = new JButton("Abrir");
    JButton bSalva = new JButton("Salvar");
    JButton bSComo = new JButton("Salvar Como");
    JButton bFecha = new JButton("Fechar");

    JTextArea texto = new JTextArea(10, 40);
    
    String nomeArq;

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

        bAbrir.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    StringBuffer txt = new StringBuffer();
                    nomeArq = JOptionPane.showInputDialog(null, "Informe o nome do arquivo.");
                    FileInputStream in = new FileInputStream(nomeArq);
                    
                    Scanner sin = new Scanner(in);
                    
                    while (sin.hasNextLine()) {
                        txt.append(sin.nextLine());
                        txt.append("\n");
                    }

                    in.close();
                    sin.close();

                    texto.setText(txt.toString());
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");

                    try {
                        int op = JOptionPane.showConfirmDialog(null, "Deseja criar um novo arquivo?", "Novo arquivo", JOptionPane.YES_NO_OPTION);

                        if (op == 0) {
                            File newFile = new File(nomeArq);

                            if (newFile.createNewFile()) {
                                JOptionPane.showMessageDialog(null, "Sucesso!");
                            } else {
                                JOptionPane.showMessageDialog(null, "Fracasso!");
                            }

                        }
                    } catch (Exception err) {
                        JOptionPane.showMessageDialog(null, err);
                    }
                }
            }
        });

        bSalva.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String txt;
                    FileOutputStream out = new FileOutputStream(nomeArq);
                    txt= texto.getText();
                    out.write(txt.getBytes());
                    out.close();
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");
                }
            }
        });

        bSComo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                

                try {
                    String txt;
                    nomeArq = JOptionPane.showInputDialog(null, "Informe o nome do arquivo.");
                    File newFile = new File(nomeArq);

                    if (newFile.createNewFile()) {
                        JOptionPane.showMessageDialog(null, "Sucesso!");
                    } else {
                        JOptionPane.showMessageDialog(null, "Fracasso!");
                    }
                    
                    FileOutputStream out = new FileOutputStream(nomeArq);
                    txt= texto.getText();
                    out.write(txt.getBytes());
                    out.close();
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");
                }           
            }
        });

        bFecha.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int opc = JOptionPane.showConfirmDialog(null, "Deseja fechar o programa?", "Sair", JOptionPane.YES_NO_OPTION);

                if (opc == 0) System.exit(0);
            }
        });

        pack();
        setVisible(true);
    }
    
    public static void main(String s[]) {
        new Ex01();
    }
}
