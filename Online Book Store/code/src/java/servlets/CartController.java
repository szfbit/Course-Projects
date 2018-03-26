package servlets;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import beanClass.Cart;
import beanClass.User;

public class CartController extends HttpServlet {
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String action=request.getParameter("action");
        String pre;
        if(request.getParameter("pre")==null)
            pre=request.getHeader("REFERER");
        else
            pre=request.getParameter("pre");
        if(action==null)
        {
            String url="cart.jsp?pre="+pre;
            RequestDispatcher dsp= request.getRequestDispatcher(url);
            dsp.forward(request, response);
        }
        else if(action.equals("update"))
        {
            int newNum=Integer.parseInt(request.getParameter("newNum"));
            String id=request.getParameter("id");
            Cart c=(Cart)request.getSession().getAttribute("cart");
            boolean suc=c.changeNum(id, newNum);
            RequestDispatcher dsp;
            if(suc)
                dsp= request.getRequestDispatcher("cart.jsp?suc="+id);
            else
            {
                if(!request.getSession().getAttribute("login").equals("false"))
                {   
                    Cart toAdd=new Cart();
                    toAdd.setEmail(((User)request.getSession().getAttribute("account")).getEmail());
                    request.setAttribute("cart", toAdd);
                }
                dsp= request.getRequestDispatcher("cart.jsp?error=c1");//no update possibility
            }
                
            dsp.forward(request, response);            
        }
        else if(action.equals("delete"))
        {
            String id=request.getParameter("id");
            Cart c=(Cart)request.getSession().getAttribute("cart");
            boolean suc=c.deleteItem(id);
            RequestDispatcher dsp;
            if(suc)
                dsp= request.getRequestDispatcher("cart.jsp");
            else{
                if(!request.getSession().getAttribute("login").equals("false"))
                {   
                    Cart toAdd=new Cart();
                    toAdd.setEmail(((User)request.getSession().getAttribute("account")).getEmail());
                    request.setAttribute("cart", toAdd);
                }                
                dsp= request.getRequestDispatcher("cart.jsp?error=c2");//no delete possibility
            }
            dsp.forward(request, response);                        
        }
        else if(action.equals("add"))
        {
            String bookID=request.getParameter("id");
            Cart c=(Cart)request.getSession().getAttribute("cart");
            boolean suc=c.AddBook(bookID,1);
            String url;
            if(!suc)
            {
                if(!request.getSession().getAttribute("login").equals("false"))
                {   
                    Cart toAdd=new Cart();
                    toAdd.setEmail(((User)request.getSession().getAttribute("account")).getEmail());
                    request.setAttribute("cart", toAdd);
                }
                url=request.getHeader("REFERER")+"&error=c3";
            }//duplict addition or other error
            else
                url="cart.jsp?pre="+pre;
            response.sendRedirect(url);
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
