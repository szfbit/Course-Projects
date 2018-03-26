
package beanClass;
import beanClass.PurRecord;
import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
public class RefRecord {
    int count;
    private ArrayList<Integer> ridList;
    private ArrayList<String> emailList;
    private ArrayList<Book> bList;
    private ArrayList<Integer> pidList;
    private ArrayList<Integer> num;
    private ArrayList<Double> charList;
    private ArrayList<Integer> staList;
    private Connection con;
    
    public RefRecord() {
        count=0;
        emailList=new ArrayList<String>();
        bList=new ArrayList<Book>();
        pidList=new ArrayList<Integer>();
        num=new ArrayList<Integer>();
        charList=new ArrayList<Double>();
        staList=new ArrayList<Integer>();
        ridList=new ArrayList<Integer>();
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            String sql="SELECT * FROM Refund ORDER BY status";
            Statement stmt=con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);
            while(rs.next())
            {
                ridList.add(new Integer(rs.getInt("RefID")));
                emailList.add(rs.getString("email"));
                Book toAdd=new Book();
                toAdd.setId(rs.getString("BookID"));
                bList.add(toAdd);
                pidList.add(new Integer(rs.getInt("PurID")));
                num.add(new Integer(rs.getInt("number")));
                charList.add(new Double(rs.getDouble("Charge")));
                staList.add(new Integer(rs.getInt("status")));
                count++;
            }
        }
        catch(Exception e)
        {
            e.toString();
        }  
        
        
    }              

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        ;
    }

    public ArrayList<String> getEmailList() {
        return emailList;
    }

    public void setEmailList(ArrayList<String> emailList) {
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

    public ArrayList<Integer> getStaList() {
        return staList;
    }

    public void setStaList(ArrayList<Integer> staList) {
        ;
    }

    public ArrayList<Integer> getRidList() {
        return ridList;
    }

    public void setRidList(ArrayList<Integer> ridList) {
        ;
    }
    public void acceptRefund(int rid,User ac)
    {
        int ind=0;
        for(int i=0;i<=count-1;i++)
            if(this.ridList.get(i)==rid)
            {
                ind=i;
                break;
            }
        if(ind<0)
            return;
        try {
            String test="SELECT status FROM Refund WHERE RefID=?";            
            PreparedStatement check;            
            check = con.prepareStatement(test);
            check.setInt(1, rid);
            ResultSet rs=check.executeQuery();
            rs.next();
            if(rs.getInt(1)!=0)
                return;
            double charge=this.charList.get(ind);
            int pid=this.pidList.get(ind);
            int number=this.num.get(ind);
            Book sel=this.bList.get(ind);
            String pSql;
            int refType;
            if(charge!=0)
            {
                ac.setPoint(ac.getPoint()+charge);
                sel.setQty(sel.getQty()+number);
                refType=2;                                
            }
            else
                refType=3;
            pSql="Update Purchase SET Refund ="+refType+" WHERE PurID= ?";
            PreparedStatement pstmt=con.prepareStatement(pSql);
            pstmt.setInt(1, pid);
            int row=pstmt.executeUpdate();
            pstmt=con.prepareStatement("Update Refund SET status=1 WHERE RefID=?");
            pstmt.setInt(1, rid);
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            ex.toString();
        }
       
    }
    public void rejectRefund(int rid)
    {
        int ind=0;
        for(int i=0;i<=count-1;i++)
            if(this.ridList.get(i)==rid)
            {
                ind=i;
                break;
            }
        if(ind<0)
            return;
        try {
            String test="SELECT status FROM Refund WHERE RefID=?";            
            PreparedStatement check;            
            check = con.prepareStatement(test);
            check.setInt(1, rid);
            ResultSet rs=check.executeQuery();
            rs.next();
            if(rs.getInt(1)!=0)
                return;
            int pid=this.pidList.get(ind);
            String pSql;
            pSql="Update Purchase SET Refund =4 WHERE PurID= ?";
            PreparedStatement pstmt=con.prepareStatement(pSql);
            pstmt.setInt(1, pid);
            int row=pstmt.executeUpdate(pSql);
            pstmt=con.prepareStatement("Update Refund SET status=2 WHERE RefID=?");
            pstmt.setInt(1, rid);
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            ex.toString();
        }        
    }
}
