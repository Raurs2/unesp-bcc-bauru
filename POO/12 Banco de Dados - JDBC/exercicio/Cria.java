import java.sql.*;

class Cria {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();
      
      stmt.executeUpdate("CREATE TABLE ANIMES (NAME VARCHAR(30), RELEASEDATE VARCHAR(30), SCORE INTEGER, WATCHED VARCHAR(30))");

      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}