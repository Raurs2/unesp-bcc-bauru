import java.sql.*;

class Insere {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();

      stmt.executeUpdate("INSERT INTO ANIMES " + "VALUES ('DANGANRONPA', '12/12/2012', 9, 'YES')");
      stmt.executeUpdate("INSERT INTO ANIMES " + "VALUES ('BERSERK', '11/11/2011', 10, 'YES')");
      stmt.executeUpdate("INSERT INTO ANIMES " + "VALUES ('SONNY BOY', '12/12/2020', 10, 'YES')");
      
      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}
