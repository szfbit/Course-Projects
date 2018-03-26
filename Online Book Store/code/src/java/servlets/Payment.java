/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package servlets;

import beanClass.Cart;
import beanClass.PurRecord;
import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class Payment extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        String action=request.getParameter("action");
        HttpSession session=request.getSession();
        if(session.getAttribute("login").equals("false"))
            response.sendRedirect("login.jsp");
        else
        {
            Cart newCart=new Cart();
            newCart.setEmail(((User)session.getAttribute("account")).getEmail());
            session.setAttribute("cart", newCart);
            if(action==null)
            {
                RequestDispatcher dsp= request.getRequestDispatcher("payment.jsp");
                dsp.forward(request, response);
            }
            else
            {
                User account=(User)session.getAttribute("account");
                int level=account.getLevel();
                double disRatio=0.05*(level-1);
                double total=0;
                double dis;
                double actTotal;
                for(int i=0;i<=newCart.getCount()-1;i++)
                    total+=newCart.getLists().get(i).getCurrent_price()*newCart.getNum().get(i);
                dis=total*disRatio;                
                total=Math.round(total*100)*1.0/100;
                double checkActTotal=Double.parseDouble(request.getParameter("total"));
                if(dis>account.getPoint())
                    response.sendRedirect("pay.do?error=1");//not enough money
                else if(total!=checkActTotal)
                    response.sendRedirect("pay.do");
                else
                {
                    PurRecord rec=new PurRecord();
                    rec.addList((Cart)session.getAttribute("cart"),(User)session.getAttribute("account"));
                    request.setAttribute("record", rec);
                    RequestDispatcher dsp;
                    dsp=request.getRequestDispatcher("payment.jsp");
                    dsp.forward(request, response);
                }
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
