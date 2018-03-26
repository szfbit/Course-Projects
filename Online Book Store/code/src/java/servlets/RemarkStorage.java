package servlets;

import java.io.IOException;
import java.io.PrintWriter;
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

public class RemarkStorage extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        HttpSession session = request.getSession();
        
        if(session.getAttribute("login").equals("false"))
        {
            response.sendRedirect("login.jsp");
        }
        else{
        String remark = request.getParameter("comment");
        String email = request.getParameter("usremail");
        String id = request.getParameter("bookid");
        int star = parseInt(request.getParameter("star"));
//        PrintWriter out = response.getWriter();
//        out.print(star);
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");

            PreparedStatement stmt;
            stmt = con.prepareStatement("INSERT INTO [remark] VALUES (?, ?, ?, ?)");
            stmt.setString(1, email);
            stmt.setString(2, id);
            stmt.setString(3, remark);
            stmt.setInt(4, star);
            int row = stmt.executeUpdate();
            if(row < 0)
            {
                //
            }
            
             stmt = con.prepareStatement("SELECT * FROM [book] WHERE [BookID] = ?");
             stmt.setString(1, id);
             ResultSet rs = stmt.executeQuery();
             rs.next();
             
             double avg_score = rs.getDouble("score_value");
             int score_time = rs.getInt("score_time")+1;
             double new_avg_score = (avg_score+star*1.0*rs.getInt("score_time"))/score_time;
             
             stmt = con.prepareStatement("UPDATE [book] SET [score_value] = ?, [score_time] = ? WHERE [BookID] = ?");
             stmt.setDouble(1, new_avg_score);
             stmt.setInt(2, score_time);
             stmt.setString(3, id);
             
             row = stmt.executeUpdate();
             if(row < 0)
             {
                 //
             }
             
        }
        catch(ClassNotFoundException | SQLException e)
        {
            
        }
        
        response.sendRedirect("bookInfoDisplay?bookID="+id);
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
