package servlets;

import beanClass.Book;
import beanClass.Cart;
import beanClass.Fav;
import beanClass.User;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Welcome extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        if(request.getSession().getAttribute("login")==null)
        {
            User user=new User();
            request.getSession().setAttribute("account", user);
            request.getSession().setAttribute("login", "false");
        }
        if(request.getSession().getAttribute("cart")==null)
        {
            Cart ca=new Cart();
            ca.AddBook("0023",8);
//            Fav fav=new Fav();
            request.getSession().setAttribute("cart", ca);
//            request.getSession().setAttribute("fav", fav);
        }
        Book []h = new Book[4];
        
        Book []r = new Book[4];
        
        Book []n = new Book[4];
        
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            Statement stmt = con.createStatement();
            stmt.setMaxRows(4);
            
            //hot
            String sql1 = "SELECT * FROM [Book] ORDER BY [Pur_num] DESC";
            ResultSet rs = stmt.executeQuery(sql1);
            for(int i = 0; i < 4; i++)
            {   
                rs.next();
                h[i] = new Book();
                h[i].setId(rs.getString("BookID"));
                
            }
            //recommendation
            String sql2 = "SELECT * FROM [Book] ORDER BY [Fav_num] DESC";
            rs = stmt.executeQuery(sql2);
            for(int i = 0; i < 4; i++)
            {  
                rs.next();
                r[i] = new Book();
                r[i].setId(rs.getString("BookID"));
            }
            //new
            String sql3 = "SELECT * FROM [Book] ORDER BY [Publish_time] DESC";
            rs = stmt.executeQuery(sql3);
            for(int i = 0; i < 4; i++)
            {  
                rs.next();
                n[i] = new Book();
                n[i].setId(rs.getString("BookID"));
            }   
            
            for(int i = 1; i <= 4; i++)
            {
                request.setAttribute("h" + i, h[i-1]);
                request.setAttribute("r" + i, r[i-1]);
                request.setAttribute("n" + i, n[i-1]);
            }
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        
        
        RequestDispatcher dsp= request.getRequestDispatcher("index.jsp");
        dsp.forward(request, response);
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
