import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;
public class Prova extends JFrame {
  Connection con;
  Statement stmt;
  JButton bt1;
  JTextField tf1, tf2, tf3, tf4;
  PreparedStatement pStmt;
  public Prova() {
    super("Prova 2");
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    initBD();
    createTable();
    insertTable();
    pack();
    setVisible(true);
  }
  public void initBD() {
    try {
      Class.forName("org.hsql.jdbcDriver");
      con = DriverManager.getConnection("jdbc:HypersonicSQL:http://127.0.0.1", "sa", "");
      stmt = con.createStatement();
    } catch (ClassNotFoundException erro) {
      JOptionPane.showMessageDialog(null, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(null, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    }
  }
  public void createTable() {
    try {
      stmt.executeUpdate(
          "CREATE TABLE CLIENTES (NOME VARCHAR(30), ENDERECO VARCHAR(30), CPF VARCHAR(30), TELEFONE VARCHAR(30))");
      JOptionPane.showMessageDialog(null, "Tabela criada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(null, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    } catch (NullPointerException erro) {
      JOptionPane.showMessageDialog(null, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
  public void insertTable() {
    try {
      pStmt = con.prepareStatement("INSERT INTO CLIENTES VALUES (?, ?, ?, ?)");
      JPanel panel = new JPanel(new GridLayout(4, 2));
      panel.add(new JLabel("Nome: "));
      panel.add(tf1 = new JTextField(30));
      panel.add(new JLabel("ENDERECO: "));
      panel.add(tf2 = new JTextField(10));
      panel.add(new JLabel("CPF: "));
      panel.add(tf3 = new JTextField(5));
      panel.add(new JLabel("TELEFONE: "));
      panel.add(tf4 = new JTextField(5));
      add(panel, BorderLayout.NORTH);
      add(bt1 = new JButton("inserir"), BorderLayout.SOUTH);
      bt1.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          try {
            pStmt.setString(1, tf1.getText());
            pStmt.setString(2, tf2.getText());
            pStmt.setString(3, tf3.getText());
            pStmt.setString(4, tf4.getText());
            tf1.setText("");
            tf2.setText("");
            tf3.setText("");
            tf4.setText("");
            pStmt.executeUpdate();
            JOptionPane.showMessageDialog(null, "Dado inserido com sucesso!", "Sucesso",
                JOptionPane.INFORMATION_MESSAGE);
          } catch (Exception erro) {
            JOptionPane.showMessageDialog(null, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
          }
        }
      });
    } catch (Exception erro) {
      JOptionPane.showMessageDialog(null, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
  public void terminate() {
    try {
      stmt.close();
      con.close();
      pStmt.close();
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(null, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
  public static void main(String[] args) {
    new Prova();
  }
}