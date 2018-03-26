package beanClass;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class Book {
    private String cat;
    private String id;
    private String name;
    private String author;
    private String lauguage;
    private String publisher;
    private String publish_time;
    private String ISBN;
    private int paperback;
    private int fav_num;
    private int pur_num;
    private int score_time;
    private double score_value;
    private double last_price;
    private double current_price;
    private int qty;
    private Connection con;
    
    public Book()
    {
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        
    } 
  
    public String getCat() {
        return cat;
    }

    public void setCat(String cat) {
        this.cat = cat;
        try
        {
            String sql = "UPDATE [Book] SET Category = " + this.cat + "WHERE [BookID] = " + this.id;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        } 
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
        try
        {
            String sql = "SELECT * FROM Book WHERE BookID='" + this.id +"'";
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            rs.next();
            this.cat = rs.getString("Category"); 
            this.last_price = rs.getDouble("Last_price");
            this.current_price = rs.getDouble("Current_price");
            this.name = rs.getString("Name");
            this.author = rs.getString("Author");
            this.lauguage = rs.getString("Lauguage");
            this.publisher = rs.getString("Publisher");
            this.publish_time = rs.getString("Publish_time");
            this.ISBN = rs.getString("ISBN");
            this.paperback = rs.getInt("Paperback");
            this.fav_num = rs.getInt("Fav_num");
            this.pur_num = rs.getInt("Pur_num");
            this.score_value = rs.getDouble("score_value");
            this.score_time = rs.getInt("score_time");
            this.qty=rs.getInt("Qty");
            
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }   
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
        try
        {
            String sql = "UPDATE [Book] SET Name = '" + this.name +"'"+ "WHERE [BookID] = '" + this.id +"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }   
    }

    public double getLast_price() {
        return last_price;
    }

    public void setLast_price(double last_price) {
        this.last_price = last_price;
        try
        {
            String sql = "UPDATE [Book] SET Last_price = '" + this.last_price + "'"+ "WHERE [BookID] = '" + this.id + "'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public double getCurrent_price() {
        return current_price;
    }

    public void setCurrent_price(double current_price) {
        this.current_price = current_price;
        try
        {
            String sql = "UPDATE [Book] SET Current_price = '" + this.current_price +"'"+ "WHERE [BookID] ='" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
        try
        {
            String sql = "UPDATE [Book] SET Author = '" + this.author +"'"+ "WHERE [BookID] = '" + this.id +"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public String getLauguage() {
        return lauguage;
    }

    public void setLauguage(String lauguage) {
        this.lauguage = lauguage;
        try
        {
            String sql = "UPDATE [Book] SET Language = '" + this.lauguage +"'"+ "WHERE [BookID] = '" + this.id +"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
        try
        {
            String sql = "UPDATE [Book] SET Publisher = '" + this.publisher +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public String getPublish_time() {
        return publish_time;
    }

    public void setPublish_time(String publish_time) {
        this.publish_time = publish_time;
        try
        {
            String sql = "UPDATE [Book] SET Publish_time = '" + this.publish_time +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
        try
        {
            String sql = "UPDATE [Book] SET ISBN = '" + this.ISBN +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public int getPaperback() {
        return paperback;
    }

    public void setPaperback(int paperback) {
        this.paperback = paperback;
        try
        {
            String sql = "UPDATE [Book] SET Paperback = '" + this.paperback +"'"+ "WHERE [BookID] = " + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public int getFav_num() {
        return fav_num;
    }

    public void setFav_num(int fav_num) {
        this.fav_num = fav_num;
        try
        {
            String sql = "UPDATE [Book] SET Fav_num = '" + this.fav_num +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public int getPur_num() {
        return pur_num;
    }

    public void setPur_num(int pur_num) {
        this.pur_num = pur_num;
        try
        {
            String sql = "UPDATE [Book] SET Pur_num = '" + this.pur_num +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public double getScore_value() {
        return score_value;
    }

    public void setScore_value(double score_value) {
        this.score_value = score_value;
        try
        {
            String sql = "UPDATE [Book] SET score_value = '" + this.score_value +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public int getScore_time() {
        return score_time;
    }

    public void setScore_time(int score_time) {
        this.score_time = score_time;
        try
        {
            String sql = "UPDATE [Book] SET score_time = '" + this.score_time +"'"+ "WHERE [BookID] = '" + this.id+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }
    }

    public int getQty() {
        return qty;
    }

    public void setQty(int qty) {
        this.qty = qty;
        try
        {
            String sql = "UPDATE [Book] SET qty = ? WHERE [BookID] = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1,this.qty);
            stmt.setString(2, this.id);
            int row = stmt.executeUpdate();
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }        
    }
    
}
