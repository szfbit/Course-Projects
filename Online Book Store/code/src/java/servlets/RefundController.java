
package servlets;

import beanClass.PurRecord;
import beanClass.RefRecord;
import beanClass.User;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class RefundController extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        HttpSession session=request.getSession();
        String action=request.getParameter("action");
        User ac=(User)session.getAttribute("account");
        RefRecord rR=new RefRecord();
        if(action==null)
        {
            request.setAttribute("record", rR);
            RequestDispatcher dsp;
            dsp=request.getRequestDispatcher("ADMIN_Refund.jsp");
            dsp.forward(request, response);
        }
        else if(action.equals("accept"))
        {
            int rid=Integer.parseInt(request.getParameter("rid"));
            String email=request.getParameter("email");
            User usr=new User();
            usr.setEmail(email);
            rR.acceptRefund(rid, usr);
            rR=new RefRecord();
            request.setAttribute("record", rR);
            RequestDispatcher dsp;
            dsp=request.getRequestDispatcher("ADMIN_Refund.jsp");
            dsp.forward(request, response);            
        }
        else{
            int rid=Integer.parseInt(request.getParameter("rid"));
            rR.rejectRefund(rid);
            rR=new RefRecord();
            request.setAttribute("record", rR);
            RequestDispatcher dsp;
            dsp=request.getRequestDispatcher("ADMIN_Refund.jsp");
            dsp.forward(request, response);            
            
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
