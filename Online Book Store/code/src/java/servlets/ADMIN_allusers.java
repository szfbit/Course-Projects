package servlets;

import beanClass.ADMIN_User;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ADMIN_allusers extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        Connection con;
        ResultSet rs;
        HttpSession session = request.getSession();
        int userN = 0;
        PrintWriter out = response.getWriter();
        ADMIN_User user = new ADMIN_User();
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            
            PreparedStatement stmt;

            stmt = con.prepareStatement("SELECT COUNT(*) as 'userCount' FROM [account] WHERE [Au] = '0'");
            rs = stmt.executeQuery();
            rs.next();
            userN = rs.getInt("userCount");
            out.print(userN);
            stmt = con.prepareStatement("SELECT * FROM [account] WHERE [Au] = '0'");
            rs = stmt.executeQuery();
            
            user.setNum(userN);
            for(int i = 0; i < userN; i++)
            {
                rs.next();
                user.setUser(i, rs.getString("email"));
                session.setAttribute("ADuser", user);
            }
            response.sendRedirect("ADMIN_Users.jsp");          
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
