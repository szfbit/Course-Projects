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
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class ReviseUserInfo extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException, ClassNotFoundException, SQLException {
        response.setContentType("text/html;charset=UTF-8");
        String name = request.getParameter("usrname");
        int gender = parseInt(request.getParameter("gender"));
        String birth = request.getParameter("year")+"-"+request.getParameter("month")+"-"+request.getParameter("day");
        String phone = request.getParameter("phone");
        String id = request.getParameter("usrid");
        String email = request.getParameter("usremail");
        PrintWriter out = response.getWriter();
        
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");

            PreparedStatement stmt;
            stmt = con.prepareStatement("UPDATE [account] SET [Username] = ?, [gender] = ?, [birthday] = ?, [phone] = ? WHERE [AccountID] = ?");
            stmt.setString(1, name);
            stmt.setInt(2, gender);
            stmt.setString(3, birth);
            stmt.setString(4, phone);
            stmt.setString(5, id);
            int row = stmt.executeUpdate();
            if(row < 0)
            {
                //
            }
        }
        catch(ClassNotFoundException | SQLException e)
        {
            
        }
        User account = new User();
        account.setEmail(email);

        HttpSession session = request.getSession();
        session.setAttribute("account", account);
        response.sendRedirect("userInfo.jsp");
           
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
        try {
            processRequest(request, response);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ReviseUserInfo.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(ReviseUserInfo.class.getName()).log(Level.SEVERE, null, ex);
        }
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
        try {
            processRequest(request, response);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ReviseUserInfo.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(ReviseUserInfo.class.getName()).log(Level.SEVERE, null, ex);
        }
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
