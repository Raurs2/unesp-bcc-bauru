import java.awt.*;import java.awt.event.*;import java.io.*;import java.util.*;import javax.swing.*;
class Ex01V2 extends JFrame{
    JButton bAbrir = new JButton("Abrir");
    JButton bSalva = new JButton("Salvar");
    JButton bSComo = new JButton("Salvar Como");
    JButton bFecha = new JButton("Fechar");
    JTextArea texto = new JTextArea(10, 40);
    String nomeArq;
    Ex01V2() {
        super("Editor de Texto V2");
        JPanel p = new JPanel(new GridLayout(4, 1));
        p.add(bAbrir); p.add(bSalva); p.add(bSComo); p.add(bFecha); 
        JPanel r = new JPanel(new GridLayout(2, 2));
        r.add(p, BorderLayout.WEST);
        add(r, BorderLayout.WEST);
        add(texto, BorderLayout.EAST);
        bAbrir.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    StringBuffer txt = new StringBuffer();
                    nomeArq = JOptionPane.showInputDialog(null, "Informe o nome do arquivo.");
                    FileReader reader = new FileReader(nomeArq);
                    Scanner sin = new Scanner(reader);
                    while (sin.hasNextLine()) {
                        txt.append(sin.nextLine());
                        txt.append("\n");
                    sin.close();
                    reader.close();
                    texto.setText(txt.toString());
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");
                    try {
                        int op = JOptionPane.showConfirmDialog(null, "Deseja criar um novo arquivo?", "Novo arquivo", JOptionPane.YES_NO_OPTION);
                        if (op == 0) {
                            File newFile = new File(nomeArq);
                            if (newFile.createNewFile()) { JOptionPane.showMessageDialog(null, "Sucesso!");
                            } else { JOptionPane.showMessageDialog(null, "Fracasso!");
                    } catch (Exception err) {
                        JOptionPane.showMessageDialog(null, err);
        bSalva.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String txt;
                    FileWriter out = new FileWriter(nomeArq);
                    txt= texto.getText();
                    out.write(txt);
                    out.close();
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");
        bSComo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    String txt;
                    nomeArq = JOptionPane.showInputDialog(null, "Informe o nome do arquivo.");
                    File newFile = new File(nomeArq);
                    if (newFile.createNewFile()) { JOptionPane.showMessageDialog(null, "Sucesso!");   
                    } else { JOptionPane.showMessageDialog(null, "Fracasso!");
                    FileWriter out = new FileWriter(nomeArq);
                    txt= texto.getText();
                    out.write(txt);
                    out.close();
                } catch (Exception error) {
                    JOptionPane.showMessageDialog(null, "Arquivo não exite");
        bFecha.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                int opc = JOptionPane.showConfirmDialog(null, "Deseja fechar o programa?", "Sair", JOptionPane.YES_NO_OPTION);
                if (opc == 0) System.exit(0);
        pack();
        setVisible(true);
    public static void main(String s[]) {
        new Ex01V2();