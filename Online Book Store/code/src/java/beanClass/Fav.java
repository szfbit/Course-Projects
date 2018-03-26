package beanClass;
import java.util.ArrayList;
import beanClass.Book;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.sql.DataSource;

public class Fav {
    private String email;
    private ArrayList<Book> lists;
    private int count;
    private Connection con;
    
    public Fav() {
        count=0;
        lists=new ArrayList<Book>();
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
    
    public String getEmail() {
        return email;
        
    }

    public void setEmail(String email) {
        this.email = email;
        try
        {
            String sql = "SELECT * FROM [Favorite] WHERE [email] = ?";
            PreparedStatement stmt = con.prepareStatement(sql);
            stmt.setString(1, email);
            ResultSet rs = stmt.executeQuery();
            while(rs.next())
            {
                count++;
                String book=rs.getString("BookID");
                Book toAdd=new Book();
                toAdd.setId(book);
                lists.add(toAdd);             
            }
            
        }
        catch(SQLException e)
        {
            e.toString();
        }       
    }

    public ArrayList<Book> getLists() {
        return lists;
    }
    
    public void setLists(ArrayList<Book> lists) {
        ;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        ;
    }

    public boolean deleteItem(String bookid)
    {
        int ind=-1;
        for(int i=0;i<=lists.size()-1;i++)
            if(lists.get(i).getId().equals(bookid))
                ind=i;
        if(ind==-1)
            return false;

        try {
            PreparedStatement pstmt=con.prepareStatement("DELETE FROM [Favorite] WHERE [BookID]=? AND [email]=?");
            pstmt.setString(1, bookid);
            pstmt.setString(2, email);
            int row=pstmt.executeUpdate();
            if(row==0)
                return false;
            else
            {
                lists.remove(ind);
                count--;
                return true;
            }
        } catch (SQLException e) {
            e.toString();
            return false;
        }
    }
    public boolean AddBook(String bookID)
    {
        for(int i=0;i<=lists.size()-1;i++)
            if(lists.get(i).getId().equals(bookID))
                return false;
        Book toAdd=new Book();
        toAdd.setId(bookID);
        try {
            PreparedStatement pstmt=con.prepareStatement("INSERT INTO Favorite VALUES (?,?)");
            pstmt.setString(1, email);
            pstmt.setString(2, bookID);
            int row=pstmt.executeUpdate();
            if(row==0)
                return false;
            lists.add(lists.size(), toAdd);
            count++;
            return true;
        } catch (SQLException ex) {
            ex.toString();
            return false;
        }
           
    }
    public boolean find(String bookID)
    {
        for(int i=0;i<=this.count-1;i++)
            if(this.getLists().get(i).getId().equals(bookID))
                return true;
        return false;
    }
}
