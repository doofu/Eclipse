package com.zgz.it.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zgz.it.domain.Nametable;
import com.zgz.it.service.UserManage;

/**
 * Servlet implementation class DeleteUserByHibernate
 */
@WebServlet("/DeleteUserByHibernate")
public class DeleteUserByHibernate extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public DeleteUserByHibernate() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		request.setCharacterEncoding("UTF-8");
		
		String username = null;
		boolean b = false;
		
		// 取客户端上送信息
		username = request.getParameter("username");
		// 解决Get方式下中文乱码问题
		if (request.getMethod().equals("GET")) {
			username = URLDecoder.decode(username,"UTF-8");
		}		
			
		try {
			// 访问业务逻辑层，删除用户 
			b = new UserManage().deleteUser(username);
		} catch (Exception e) {
			b = false;
		}
		
		// 向客户端反馈信息
		
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		if (b == true) 
			out.println(username + "删除成功");
		else
			out.println(username + "删除失败");
		
		out.close();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}
}

