package servlets;

import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.Integer.parseInt;
import static java.lang.Integer.parseInt;
import static java.lang.Integer.parseInt;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Register extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        String userName = request.getParameter("username");
        String psw = request.getParameter("possword");
        int level = 1;
        double point = 10000;
        String email = request.getParameter("email");
        String phone = request.getParameter("phone");
        int gender = parseInt(request.getParameter("gender"));
        String bir = request.getParameter("year") +"-" + request.getParameter("month") +"-" + request.getParameter("day");
        
        PrintWriter out =  response.getWriter();

        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            
            PreparedStatement stmt;
     
            stmt = con.prepareStatement("INSERT INTO [account] VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
            stmt.setString(1, userName);
            stmt.setString(2, psw);
            stmt.setInt(3, level);
            stmt.setDouble(4, point);
            stmt.setString(5, email);
            stmt.setString(6, phone);
            stmt.setInt(7, gender);
            stmt.setString(8, bir);
            stmt.setInt(9, 0);
            
            int row = stmt.executeUpdate();
            if(row < 0)
            {
                //
            }
            
            User u = new User();
            u.setEmail(email);
            
            HttpSession session = request.getSession();
            session.setAttribute("account", u);  
            session.setAttribute("login", "true");
        }
        catch(ClassNotFoundException | SQLException e)
        {
            
        }
        RequestDispatcher dsp= request.getRequestDispatcher("redirect.jsp");
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
