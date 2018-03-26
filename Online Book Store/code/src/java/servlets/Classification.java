package servlets;

import beanClass.Book;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Classification extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");

        Book [] c1 = new Book[2];
        Book [] c2 = new Book[2];
        Book [] c3 = new Book[2];
        Book [] c4 = new Book[2];
        Book [] c5 = new Book[2];
        Book [] c6 = new Book[2];
        Book [] c7 = new Book[2];
        Book [] c8 = new Book[2];
        Book [] c9 = new Book[2];
        Book [] c10 = new Book[2];
        
        try
        {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
            
            PreparedStatement stmt;
            ResultSet rs;
            PrintWriter out =  response.getWriter();
            
            //c1
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Arts & Photography");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c1[i] = new Book();
                c1[i].setId(rs.getString("BookID"));
            }
            
            //c2
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Business & Money");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c2[i] = new Book();
                c2[i].setId(rs.getString("BookID"));
            }
            
            //c3
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Children's Books");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c3[i] = new Book();
                c3[i].setId(rs.getString("BookID"));
            }
            
            //c4
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Computer & Technology Books");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c4[i] = new Book();
                c4[i].setId(rs.getString("BookID"));
            }

            //c5
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Cookbooks, Food & Wine");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c5[i] = new Book();
                c5[i].setId(rs.getString("BookID"));
            }
            
            //c6
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Travel");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c6[i] = new Book();
                c6[i].setId(rs.getString("BookID"));
            }
            
            //c7
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Sports & Outdoors");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c7[i] = new Book();
                c7[i].setId(rs.getString("BookID"));
            }
            
            //c8
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Science Fiction & Fantasy");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c8[i] = new Book();
                c8[i].setId(rs.getString("BookID"));
            }
            
            //c9
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Romance");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c9[i] = new Book();
                c9[i].setId(rs.getString("BookID"));
            }
            
            //c10
            stmt = con.prepareStatement("SELECT * FROM [Book] WHERE [Category]=?");
            stmt.setString(1, "Politics & Social Sciences");
            rs = stmt.executeQuery();
            
            for(int i = 0; i < 2; i++)
            {   
                rs.next();
                c10[i] = new Book();
                c10[i].setId(rs.getString("BookID"));
            }
            
            request.setAttribute("c1f", c1[0]);
            request.setAttribute("c1s", c1[1]);
            
            request.setAttribute("c2f", c2[0]);
            request.setAttribute("c2s", c2[1]);
            
            request.setAttribute("c3f", c3[0]);
            request.setAttribute("c3s", c3[1]);
            
            request.setAttribute("c4f", c4[0]);
            request.setAttribute("c4s", c4[1]);
            
            request.setAttribute("c5f", c5[0]);
            request.setAttribute("c5s", c5[1]);
            
            request.setAttribute("c6f", c6[0]);
            request.setAttribute("c6s", c6[1]);
            
            request.setAttribute("c7f", c7[0]);
            request.setAttribute("c7s", c7[1]);
            
            request.setAttribute("c8f", c8[0]);
            request.setAttribute("c8s", c8[1]);
            
            request.setAttribute("c9f", c9[0]);
            request.setAttribute("c9s", c9[1]);
            
            request.setAttribute("c10f", c10[0]);
            request.setAttribute("c10s", c10[1]);
            
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
        RequestDispatcher dsp= request.getRequestDispatcher("classification.jsp");
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
