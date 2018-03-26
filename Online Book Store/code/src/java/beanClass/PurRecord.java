
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
import beanClass.Book;
import beanClass.Cart;
import beanClass.User;
public class PurRecord {
    int count;
    private String email;
    private ArrayList<Book> bList;
    private ArrayList<Integer> pidList;
    private ArrayList<Integer> num;
    private ArrayList<Double> charList;
    private ArrayList<Integer> refList;
    private Connection con;
    
    public PurRecord() {
        count=0;
        bList=new ArrayList<Book>();
        pidList=new ArrayList<Integer>();
        num=new ArrayList<Integer>();
        charList=new ArrayList<Double>();
        refList=new ArrayList<Integer>();
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
        try {
            String sql = "SELECT * FROM [Purchase] WHERE [email] = ?";            
            PreparedStatement stmt=con.prepareStatement(sql);
            stmt.setString(1, email);
            ResultSet rs=stmt.executeQuery();
            while(rs.next())
            {            
                int ordNum=rs.getInt("Ord_number");
                int actNum=rs.getInt("Act_number");
                double charge=rs.getDouble("Charge");
                int ref=rs.getInt("Refund");
                String bookid=rs.getString("BookID");
                int purId=rs.getInt("PurID");
                Book toAdd=new Book();
                toAdd.setId(bookid);
                if(actNum!=0)
                {
                    bList.add(toAdd);
                    pidList.add(new Integer(purId));
                    num.add(new Integer(ordNum));
                    charList.add(new Double(charge));
                    refList.add(new Integer(ref));
                    count++;
                }
                if(actNum!=ordNum)
                {
                    bList.add(toAdd);
                    pidList.add(new Integer(purId));
                    num.add(new Integer(ordNum-actNum));
                    charList.add(new Double(0));
                    refList.add(new Integer(ref));
                    count++;
                }
            }
        } catch (SQLException ex) {
            ex.toString();
        }
        
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        ;
    }

    public ArrayList<Book> getbList() {
        return bList;
    }

    public void setbList(ArrayList<Book> bList) {
        ;
    }

    public ArrayList<Integer> getPidList() {
        return pidList;
    }

    public void setPidList(ArrayList<Integer> pidList) {
        ;
    }

    public ArrayList<Integer> getNum() {
        return num;
    }

    public void setNum(ArrayList<Integer> num) {
        ;
    }

    public ArrayList<Double> getCharList() {
        return charList;
    }

    public void setCharList(ArrayList<Double> charList) {
        ;
    }

    public ArrayList<Integer> getRefList() {
        return refList;
    }

    public void setRefList(ArrayList<Integer> refList) {
        ;
    }
    public void addList(Cart c,User ac)
    {
        try {
            int l=c.getCount();
            for(int i=0;i<=l-1;i++)
            {
                String bookid=c.getLists().get(0).getId();
                int ordNum=c.getNum().get(0);
                int actNum=ordNum;
                int acNum=c.getLists().get(0).getQty();
                if(actNum>acNum)
                    actNum=acNum;
                String email=ac.getEmail();
                double disRatio=(ac.getLevel()-1)*0.05;
                double charge=actNum*c.getLists().get(0).getCurrent_price()*(1-disRatio);
                String sql="INSERT INTO Purchase VALUES (?,?,?,?,?,0)";
                PreparedStatement pstmt=con.prepareStatement(sql);
                pstmt.setString(1, email);
                pstmt.setString(2, bookid);
                pstmt.setInt(3, ordNum);
                pstmt.setInt(4, actNum);
                pstmt.setDouble(5,charge);
                int row=pstmt.executeUpdate();
                c.getLists().get(0).setQty(c.getLists().get(0).getQty()-actNum);
                double newValue=ac.getPoint()-charge;
                ac.setPoint(newValue);
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("SELECT @@IDENTITY AS [@@IDENTITY]");
                rs.next();
                int purId=rs.getInt(1);
                Book toAdd=c.getLists().get(0);
                c.deleteItem(bookid);
                if(actNum!=0)
                {
                    bList.add(toAdd);
                    pidList.add(new Integer(purId));
                    num.add(new Integer(actNum));
                    charList.add(new Double(charge));
                    refList.add(new Integer(0));
                    count++;
                }
                if(actNum!=ordNum)
                {
                    bList.add(toAdd);
                    pidList.add(new Integer(purId));
                    num.add(new Integer(ordNum-actNum));
                    charList.add(new Double(0));
                    refList.add(new Integer(0));
                    count++;
                }
            }   
        } catch (SQLException ex) {
            ex.toString();
        }        
    }
    public void applyRef(int pid,int type)//0 for real refund, 1 for giving up awaiting stock
    {
        int ind=-1;
        for(int i=0;i<=count-1;i++)
            if(this.pidList.get(i)==pid&&((type==0&&this.charList.get(i)!=0)||(type==1&&this.charList.get(i)==0)))
                ind=i;
        if(ind<0)
            return;
        String bookid=bList.get(ind).getId();
        int number=this.num.get(ind);
        double charge=this.charList.get(ind);
        try {
            String test="SELECT * FROM Refund WHERE PurID=?";
            PreparedStatement check=con.prepareStatement(test);
            check.setInt(1, pid);
            ResultSet rs=check.executeQuery();
            if(rs.next())
                return;
            String sql="INSERT INTO Refund VALUES (?,?,?,?,?,0)";
            PreparedStatement pstmt=con.prepareStatement(sql);            
            pstmt.setInt(1,pid);
            pstmt.setString(2,email);
            pstmt.setString(3,bookid);
            pstmt.setInt(4, number);
            pstmt.setDouble(5, charge);
            pstmt.executeUpdate();
            String update="UPDATE Purchase SET Refund=1 WHERE PurID= ?";
            pstmt=con.prepareStatement(update);
            pstmt.setInt(1, pid);
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            ex.toString();
        }
    }
}
