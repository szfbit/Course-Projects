package servlets;

import beanClass.MyRemark;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class MyRemarkDisplay extends HttpServlet {
    private Connection con;
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException, ClassNotFoundException {
        
        response.setContentType("text/html;charset=UTF-8");
        String email = request.getParameter("email");
        ResultSet rs;
        PrintWriter out =  response.getWriter();
        if(request.getSession().getAttribute("login").equals("false"))
            response.sendRedirect("login.jsp");
        else{        
            //get number of remarks
            int rowN = 0;
            try
            {
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");

                PreparedStatement stmt;

                stmt = con.prepareStatement("SELECT COUNT(*) as 'rowCount' FROM [remark] WHERE [email] = ?");
                stmt.setString(1, email);

                rs = stmt.executeQuery();
                rs.next();
                rowN = rs.getInt("rowCount");  

                out.print(rowN);
                stmt = con.prepareStatement("SELECT * FROM [remark] WHERE [email] = ? ORDER BY [RemarkID] DESC");
                stmt.setString(1, email);

                rs = stmt.executeQuery();

                MyRemark mRmk = new MyRemark();
                mRmk.setN(rowN);
                for(int i = 0; i < rowN; i++)
                {
                       rs.next();
                       mRmk.setEmail(email);
                       mRmk.setBook(i, rs.getString("BookID"));
                       mRmk.setContext(i, rs.getString("Context"));
                       mRmk.setScore(i, rs.getInt("Score"));
                }

                HttpSession session= request.getSession();
                session.setAttribute("mRmk", mRmk);
            }
            catch(ClassNotFoundException | SQLException e)
            {

            }

            response.sendRedirect("myRemark.jsp");
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
        try {
            processRequest(request, response);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(MyRemarkDisplay.class.getName()).log(Level.SEVERE, null, ex);
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
            Logger.getLogger(MyRemarkDisplay.class.getName()).log(Level.SEVERE, null, ex);
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
