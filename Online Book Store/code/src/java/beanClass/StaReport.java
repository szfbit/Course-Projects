package beanClass;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class StaReport {
    //book
    private int book;
    private int remark;

    //user
    private int user;
    private int bannedUser;
    
    //purchase
    private int salesVolume;
    private double income;
    private int refund;
    
    private Connection con;
    private ResultSet rs;
    public StaReport()
    {
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            
            PreparedStatement stmt;

            stmt = con.prepareStatement("SELECT COUNT(*) as 'bookC' FROM [book]");
            rs = stmt.executeQuery();
            rs.next();
            this.book = rs.getInt("bookC");
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'remarkC' FROM [remark]");
            rs = stmt.executeQuery();
            rs.next();
            this.remark = rs.getInt("remarkC");
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'userC' FROM [account]");
            rs = stmt.executeQuery();
            rs.next();
            this.user = rs.getInt("userC");
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'buserC' FROM [account] WHERE [avail] != 1b");
            rs = stmt.executeQuery();
            rs.next();
            this.bannedUser = rs.getInt("userC");
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'salesVC' FROM [purchase]");
            rs = stmt.executeQuery();
            rs.next();
            this.salesVolume = rs.getInt("salesVC");
            
            stmt = con.prepareStatement("SELECT SUM(Refund) as 'incomeC' FROM [purchase] WHERE [Refund] != 2");
            rs = stmt.executeQuery();
            rs.next();
            this.income = rs.getDouble("incomeC");
            
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'refundC' FROM [refund]");
            rs = stmt.executeQuery();
            rs.next();
            this.refund = rs.getInt("refundC");
            
        }
        catch(ClassNotFoundException | SQLException e)
        {
            
        }
    }
    public int getBook() {
        return book;
    }

    public void setBook(int book) {
        this.book = book;
    }

  
    public int getRemark() {
        return remark;
    }

    public void setRemark(int remark) {
        this.remark = remark;
    }
    
    public int getUser() {
        return user;
    }

    public void setUser(int user) {
        this.user = user;
    }

    public int getBannedUser() {
        return bannedUser;
    }

    public void setBannedUser(int bannedUser) {
        this.bannedUser = bannedUser;
    }

    public int getSalesVolume() {
        return salesVolume;
    }

    public void setSalesVolume(int salesVolume) {
        this.salesVolume = salesVolume;
    }

    public double getIncome() {
        return income;
    }

    public void setIncome(double income) {
        this.income = income;
    }

    public int getRefund() {
        return refund;
    }

    public void setRefund(int refund) {
        this.refund = refund;
    }
    
}
