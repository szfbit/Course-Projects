package servlets;

import beanClass.Fav;
import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class FavController extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        HttpSession session=request.getSession();
        if(session.getAttribute("login").equals("false"))
            response.sendRedirect("login.jsp");
        else{
            String action=request.getParameter("action");
            if(action==null)
            {
                RequestDispatcher dsp;
                dsp=request.getRequestDispatcher("favorite.jsp");
                dsp.forward(request, response);
            }
            else if(action.equals("add"))
            {
                String bid=request.getParameter("bid");
                boolean suc=((Fav)session.getAttribute("fav")).AddBook(bid);
                String url=request.getHeader("REFERER");                
                if(!suc)
                {
                    Fav toChange=new Fav();
                    String email=((User)session.getAttribute("account")).getEmail();
                    toChange.setEmail(email);
                    session.setAttribute("fav", toChange);
                    if(url.contains("?"))
                        url+="&error=f1";//has been added
                    else
                        url+="?error=f1";
                }
                response.sendRedirect(url);
            }
            else{
                String bid=request.getParameter("bid");
                boolean suc=((Fav)session.getAttribute("fav")).deleteItem(bid);
                String url=request.getHeader("REFERER");                
                if(!suc)
                {
                    Fav toChange=new Fav();
                    String email=((User)session.getAttribute("account")).getEmail();
                    toChange.setEmail(email);
                    session.setAttribute("fav", toChange);
                    if(url.contains("?"))
                        url+="&error=f2";//not in the database
                    else
                        url+="?error=f2";
                }
                response.sendRedirect(url);                
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
        processRequest(request, response);
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
