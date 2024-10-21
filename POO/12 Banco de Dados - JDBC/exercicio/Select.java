import java.sql.*;

class Select {
  public static void main(String[] args) {
    try {
      Class.forName("org.hsql.jdbcDriver");
      Connection con = DriverManager.getConnection("jdbc:HypersonicSQL:hsql://localhost:8080", "sa", "");
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery("SELECT * FROM ANIMES WHERE SCORE BETWEEN 9 AND 10");
      
      while (rs.next())
      {
        String name = rs.getString("NAME");
        String release_date = rs.getString("RELEASEDATE");
        int score = rs.getInt("SCORE");
        String watched = rs.getString("WATCHED");
        System.out.println(name + "   " + release_date + "   " + score + "   " + watched);
      }

      stmt.close();
      con.close();
    } catch (Exception e) {
      System.out.println(e);
    }
  }
}