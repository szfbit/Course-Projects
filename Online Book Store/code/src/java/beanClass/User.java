package beanClass;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class User {
    private int id;
    private String userName;
    private String psw;
    private int level;
    private double point;
    private String email;
    private String phone;
    private int gender;
    private String bir;
    private int au;
    private int avail;
    private Connection con;
    
    public User()
    {
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
        }
        catch(Exception e)
        {
            e.toString();
        }        
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
//        this.id = id;
        ;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
        try
        {
            String sql = "UPDATE [Account] SET Username = " + this.userName + "WHERE [email] = " + this.email;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public String getPsw() {
        return psw;
    }

    public void setPsw(String psw) {
        this.psw = psw;
        try
        {
            String sql = "UPDATE [Account] SET Password = " + this.psw + "WHERE [email] = '" + this.email+"'";
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public int getLevel() {
        return level;
    }

    public void setLevel(int level) {
        this.level = level;
        try
        {
            String sql = "UPDATE [Account] SET Level = " + this.level + "WHERE [email] = " + this.email;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public double getPoint() {
        return point;
    }

    public void setPoint(double point) {
        this.point = point;
        try
        {
            String sql = "UPDATE [Account] SET Point = ? WHERE [email] = ?";
            PreparedStatement pstmt =con.prepareStatement(sql);
            pstmt.setDouble(1, point);
            pstmt.setString(2, email);
            int row = pstmt.executeUpdate();
            int s=5;
            s+=1;
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
        try
        {
            String sql = "SELECT * FROM [Account] WHERE [email] = '" + this.email+"'";
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            rs.next();
            this.id=rs.getInt("AccountID");
            this.userName = rs.getString("Username");
            this.psw = rs.getString("Password");
            this.level = rs.getInt("Level");
            this.point = rs.getDouble("Point");
            this.phone = rs.getString("phone");
            this.gender = rs.getInt("gender");
            this.bir = rs.getString("birthday");
            this.au=rs.getInt("Au");
            this.avail=rs.getInt("Avail");
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }                
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
        try
        {
            String sql = "UPDATE [Account] SET phone = " + this.phone + "WHERE [email] = " + this.email;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }     
    }

    public int getGender() {
        return gender;
    }

    public void setGender(int gender) {
        this.gender = gender;
        try
        {
            String sql = "UPDATE [Account] SET gender = " + this.gender + "WHERE [email] = " + this.email;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public String getBir() {
        return bir;
    }

    public void setBir(String bir) {
        this.bir = bir;
        try
        {
            String sql = "UPDATE [Account] SET birthday = " + this.bir + "WHERE [email] = " + this.email;
            Statement stmt = con.createStatement();
            int row = stmt.executeUpdate(sql);
        }
        catch(SQLException e)
        {
            e.toString();
        }             
    }

    public int getAu() {
        return au;
    }

    public void setAu(int au) {
        this.au = au;
        try
        {
            String sql = "UPDATE [Account] SET Au = ? WHERE [email] = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1,this.au);
            stmt.setString(2, this.email);
            int row = stmt.executeUpdate();
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }          
    }

    public int getAvail() {
        return avail;
    }

    public void setAvail(int avail) {
        this.avail = avail;
        try
        {
            String sql = "UPDATE [Account] SET Au = ? WHERE [email] = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setInt(1,this.avail);
            stmt.setString(2, this.email);
            int row = stmt.executeUpdate();
        }
        catch(SQLException e)
        {
            e.printStackTrace();
        }          
    }            
}

