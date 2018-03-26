package servlets;

import beanClass.ADMIN_Book;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.naming.spi.DirStateFactory.Result;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Search extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        
        Connection con;
        String type = request.getParameter("tp");
        String keyword = request.getParameter("keyWd");
        ResultSet rs;
        ADMIN_Book bk = new ADMIN_Book();
        
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            
            PreparedStatement stmt;
            
            stmt = con.prepareStatement("SELECT COUNT(*) as 'count' FROM [book] WHERE "+type+" LIKE ?");
            stmt.setString(1, "%"+keyword+"%");
            rs = stmt.executeQuery();
            rs.next();
            int count = rs.getInt("count");
            if(count == 0)
            {
                bk.setNum(count);
                request.setAttribute("searchResult", bk);
            }
            else
            {   
                stmt = con.prepareStatement("SELECT * FROM [book] WHERE "+type+" LIKE ?");
                stmt.setString(1, "%"+keyword+"%");
                rs = stmt.executeQuery();
                bk.setNum(count);
                
               
                for(int i = 0; i < count; i++)
                {
                    rs.next();
                    out.print(rs.getString("BookID"));
                    bk.setBook(i, rs.getString("BookID"));
                    
                    request.setAttribute("searchResult", bk);
                }
            }
            RequestDispatcher dsp= request.getRequestDispatcher("searchResult.jsp");
            dsp.forward(request, response);
        }
        catch(ClassNotFoundException | SQLException e)
        {
            
        }
                     
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
