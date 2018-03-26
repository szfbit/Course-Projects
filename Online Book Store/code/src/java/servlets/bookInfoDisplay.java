package servlets;

import beanClass.Book;
import beanClass.Remark;
import beanClass.bookDesc;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class bookInfoDisplay extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        //bookinfo
        Book b = new Book();
        String bookID = request.getParameter("bookID");
        b.setId(bookID);
        HttpSession session = request.getSession();
        session.setAttribute("bookSelected", b);
        
        //bookDesc
        bookDesc bd = new bookDesc();
        ServletContext context = getServletContext();
        String path = "/bookDesc/"+bookID+".txt";
        InputStream is = context.getResourceAsStream(path);
        if (is != null) {
            InputStreamReader isr = new InputStreamReader(is);
            BufferedReader reader = new BufferedReader(isr);
            String text = "";

            while ((text = reader.readLine()) != null) {
                 bd.setDes(text);
            }
        }
        
        session.setAttribute("bookDes", bd);
        
        //remark
        try
        {
            int count = 0;
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");

            PreparedStatement stmt;
            stmt = con.prepareStatement("SELECT COUNT(*) as 'rowCount' FROM [remark] WHERE [BookID]=?");
            stmt.setString(1, bookID);
            
            ResultSet rs = stmt.executeQuery();
            rs.next();
            count = rs.getInt("rowCount");
//            out.print(count);
            if(count >= 5)
            {
                count = 5;
            }
           
            
            stmt = con.prepareStatement("SELECT * FROM [remark] WHERE [BookID]=? ORDER BY [RemarkID] DESC");
            stmt.setString(1, bookID);
            rs = stmt.executeQuery();
            
            Remark rmk = new Remark();
            rmk.setNum(count);
            for(int i = 0; i < count; i++)
            {
                rs.next();
                rmk.setEmail(i, rs.getString("email"));
                rmk.setStar(i, rs.getInt("Score"));
                rmk.setRemark(i, rs.getString("Context"));
            }
            
            session.setAttribute("rmk", rmk);
        }
        catch(ClassNotFoundException | SQLException e)
        {
        }
        RequestDispatcher dsp= request.getRequestDispatcher("bookInfo.jsp");
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
