import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;

public class MDI extends JFrame implements ActionListener {
  Connection con;
  Statement stmt;
  JDesktopPane desktop;

  JMenuItem menuCreate;
  JMenuItem menuInsert;
  JMenuItem menuConsult;
  JMenuItem menuRemove;
  JMenuItem menuExit;

  WindowConsult WindowConsult;

  public MDI() {
    super("Multiple Document Interface");

    setExtendedState(JFrame.MAXIMIZED_BOTH);
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    desktop = new JDesktopPane();
    add(desktop);

    setJMenuBar(createMenu());

    initBD();

    WindowConsult = new WindowConsult(desktop, con);
    desktop.add(WindowConsult);
    WindowConsult.setVisible(false);

    setVisible(true);
  }

  JMenuBar createMenu() {
    JMenuBar menuBar = new JMenuBar();

    menuCreate = new JMenuItem("Criar Tabela");
    menuBar.add(menuCreate);
    menuCreate.addActionListener(this);

    menuInsert = new JMenuItem("Inserir Dados");
    menuBar.add(menuInsert);
    menuInsert.addActionListener(this);

    menuConsult = new JMenuItem("Consultar Tabela");
    menuBar.add(menuConsult);
    menuConsult.addActionListener(this);

    menuRemove = new JMenuItem("Remover Dados");
    menuBar.add(menuRemove);
    menuRemove.addActionListener(this);

    menuExit = new JMenuItem("Termina");
    menuBar.add(menuExit);
    menuExit.addActionListener(this);

    return menuBar;
  }

  public void actionPerformed(ActionEvent e) {
    if (e.getSource() == menuCreate) {
      try {
        stmt.executeUpdate(
            "CREATE TABLE ANIMES (NAME VARCHAR(30), RELEASEDATE VARCHAR(30), SCORE INTEGER, WATCHED VARCHAR(30))");
        JOptionPane.showMessageDialog(null, "Tabela criada com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);

      } catch (SQLException erro) {
        JOptionPane.showMessageDialog(desktop, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
      } catch (NullPointerException erro) {
        JOptionPane.showMessageDialog(desktop, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
      }
    } else if (e.getSource() == menuInsert) {
      new WindowInsert(desktop, con);
    } else if (e.getSource() == menuConsult) {
      WindowConsult.setVisible(true);
    } else if (e.getSource() == menuRemove) {
      new WindowRemove(desktop, con);
    } else if (e.getSource() == menuExit) {
      System.exit(0);
    }
  }
  void initBD() {
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
  public void terminate() {
    try {
      stmt.close();
      con.close();
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(desktop, "Error: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
  public static void main(String[] args) {
    try {
      UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
    } catch (Exception erro) {
    }
    new MDI();
  }
}
class WindowInsert extends JInternalFrame {
  PreparedStatement pStmt;
  JDesktopPane desktop;
  JButton bt1;
  JTextField tf1, tf2, tf3, tf4;
  public WindowInsert(JDesktopPane d, Connection con) {
    super("Inserir dados na tabela Anime", true, true, false, true);
    desktop = d;
    try {
      pStmt = con.prepareStatement("INSERT INTO ANIMES VALUES (?, ?, ?, ?)");

      JPanel panel = new JPanel(new GridLayout(4, 2));

      panel.add(new JLabel("Nome: "));
      panel.add(tf1 = new JTextField(30));

      panel.add(new JLabel("data de lançamento: "));
      panel.add(tf2 = new JTextField(10));

      panel.add(new JLabel("Nota: "));
      panel.add(tf3 = new JTextField(5));

      panel.add(new JLabel("Assistiu? (sim/nao)"));
      panel.add(tf4 = new JTextField(5));

      add(panel, BorderLayout.NORTH);
      add(bt1 = new JButton("inserir"), BorderLayout.SOUTH);

      pack();
      setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      setVisible(true);
      desktop.add(this);

      bt1.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          try {
            pStmt.setString(1, tf1.getText());
            pStmt.setString(2, tf2.getText());
            pStmt.setInt(3, Integer.parseInt(tf3.getText()));
            pStmt.setString(4, tf4.getText());

            tf1.setText("");
            tf2.setText("");
            tf3.setText("");
            tf4.setText("");

            pStmt.executeUpdate();
            JOptionPane.showMessageDialog(null, "Dado inserido com sucesso!", "Sucesso",
                JOptionPane.INFORMATION_MESSAGE);
          } catch (Exception erro) {
            JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
          }
        }
      });

    } catch (Exception erro) {
      JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public void terminate() {
    try {
      pStmt.close();
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(null, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
}

class WindowRemove extends JInternalFrame {
  PreparedStatement pStmt;
  JDesktopPane desktop;
  JButton bt1;
  JTextField tf1, tf2, tf3, tf4;

  public WindowRemove(JDesktopPane d, Connection con) {
    super("Remover dados da tabela Anime", true, true, false, true);
    desktop = d;

    try {
      pStmt = con.prepareStatement("DELETE FROM ANIMES WHERE NAME = ?");

      JPanel panel = new JPanel(new FlowLayout());
      panel.add(new JLabel("Nome: "));
      panel.add(tf1 = new JTextField(30));

      setLayout(new GridLayout(2, 1));
      add(panel);
      add(bt1 = new JButton("Remover"));

      pack();
      setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      setVisible(true);
      desktop.add(this);

      bt1.addActionListener(new ActionListener() {
        public void actionPerformed(ActionEvent e) {
          try {
            pStmt.setString(1, tf1.getText());

            tf1.setText("");

            pStmt.executeUpdate();
            JOptionPane.showMessageDialog(null, "Dado removido com sucesso!", "Sucesso",
                JOptionPane.INFORMATION_MESSAGE);
          } catch (Exception erro) {
            JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
          }
        }
      });

    } catch (Exception erro) {
      JOptionPane.showMessageDialog(desktop, "erro; " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public void terminate() {
    try {
      pStmt.close();
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(null, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
}

class WindowConsult extends JInternalFrame implements ActionListener {
  PreparedStatement pStmt;
  JDesktopPane desktop;
  JButton bt1;
  JTextField tf1;
  JTextArea ta1;
  Connection test;

  public WindowConsult(JDesktopPane d, Connection con) {
    super("Consultando dados da tabela Animes", true, true, false, true);
    desktop = d;

    try {
      test = con;

      JPanel p1 = new JPanel(new GridLayout(1, 3));
      p1.add(new JLabel("Nome (digite 'tudo' para consultar todos os dados): "));
      p1.add(tf1 = new JTextField(30));
      p1.add(bt1 = new JButton("Pesquisar"));
      add(p1, BorderLayout.NORTH);

      add(new JLabel(
          "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"),
          BorderLayout.CENTER);

      JScrollPane scrollPane = new JScrollPane(ta1 = new JTextArea(5, 30));
      add(scrollPane, BorderLayout.SOUTH);

      bt1.addActionListener(this);

      pack();
      setDefaultCloseOperation(HIDE_ON_CLOSE);
    } catch (Exception erro) {
      JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public void actionPerformed(ActionEvent e) {
    try {
      ta1.setText("");

      if (tf1.getText().toString().equals("tudo") == true) {
        pStmt = test.prepareStatement("SELECT * FROM ANIMES");
      } else {
        pStmt = test.prepareStatement("SELECT * FROM ANIMES WHERE NAME LIKE ?");
        pStmt.setString(1, tf1.getText());
      }

      ResultSet rs = pStmt.executeQuery();
      while (rs.next()) {
        String s1 = rs.getString(1);
        String s2 = rs.getString(2);
        String s3 = rs.getString(3);
        String s4 = rs.getString(4);

        ta1.append(
            "|Nome: " + s1 + "|   |Data de lançamento: " + s2 + "|   |Nota: " + s3 + "|   |Assistiu? " + s4 + "|\n");
      }

      tf1.selectAll();
    } catch (Exception erro) {
      JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }

  public void terminate() {
    try {
      pStmt.close();
    } catch (SQLException erro) {
      JOptionPane.showMessageDialog(desktop, "erro: " + erro, "Erro", JOptionPane.ERROR_MESSAGE);
    }
  }
}