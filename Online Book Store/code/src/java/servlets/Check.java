package servlets;

import beanClass.Cart;
import beanClass.Fav;
import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Check extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException, ClassNotFoundException, SQLException {
        response.setContentType("text/html;charset=UTF-8");
        String url;
        PrintWriter out = response.getWriter();
        url = request.getParameter("pre");
        
        if(request.getParameter("username").equals("Email")||request.getParameter("password").equals("Password"))
            response.sendRedirect("login.jsp?error=3&pre="+url);
        else
        {
            try{
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                Connection con = DriverManager.getConnection("jdbc:sqlserver://w2ksa.cs.cityu.edu.hk:1433;databaseName=aiad027_db", "aiad027", "aiad027");
                Statement stmt = con.createStatement();
                String sql="SELECT Password FROM [Account] WHERE [email] = "+"'"+request.getParameter("username")+"'";
                ResultSet rs = stmt.executeQuery(sql);
                if(!rs.next())
                    response.sendRedirect("login.jsp?error=1&pre="+url);
    //                out.println("No user");
                else
                {
                    String pwd=rs.getString("Password");
                    if(pwd.equals(request.getParameter("password")))
                    {          
                        ((User)request.getSession().getAttribute("account")).setEmail(request.getParameter("username"));

                        out.print(url);
                        if(((User)request.getSession().getAttribute("account")).getAvail() != 1)
                        {
                            url = "login.jsp?error=4&pre="+url;//banned user
                        }
                        else {
                            request.getSession().setAttribute("login", "true");
                            Cart tem=(Cart)request.getSession().getAttribute("cart");
                            Cart userCart=new Cart();
                            userCart.setEmail(request.getParameter("username"));
                            userCart.setLists(tem.getLists(),tem.getNum());
                            out.print(userCart);
                            request.getSession().setAttribute("cart", userCart);
                            Fav fav=new Fav();
                            fav.setEmail(request.getParameter("username"));
                            request.getSession().setAttribute("fav", fav);
                            if(((User)request.getSession().getAttribute("account")).getAu() == 1)
                            {
                                
                                url = "ADMIN_allbooks";
                            }
                        }
                        response.sendRedirect(url);

                    }
                    else
                        response.sendRedirect("login.jsp?error=2&pre="+url);
    //                    out.println("Wrong pwd");
                }
            }
            catch(ClassNotFoundException e)
            {
                out.println("<div style='color: red'>" + e.toString() + "</div>");
            }
            catch (SQLException e) {
                out.println("<div style='color: red'>" + e.toString() + "</div>");
            }
        } 
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP
     * <code>GET</code> method.
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
            ex.toString();
        } catch (SQLException ex) {
            ex.toString();
        }
    }

    /**
     * Handles the HTTP
     * <code>POST</code> method.
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
            ex.toString();;
        } catch (SQLException ex) {
            ex.toString();
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
