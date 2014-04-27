package com.zgz.it.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLDecoder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zgz.it.service.UserManage;

/**
 * Servlet implementation class SayhiForHibernate
 */
@WebServlet("/GetPhoneNubmerByHibernate")
public class GetPhoneNubmerByHibernate extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public GetPhoneNubmerByHibernate() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		
		request.setCharacterEncoding("UTF-8");
		
		String username = request.getParameter("username");

		// 解决Get方式下中文乱码问题
		if (request.getMethod().equals("GET"))
			username = URLDecoder.decode(username,"UTF-8");

		String phoneNumber = "";
		
		// 访问业务逻辑层，查找电话号码 
		phoneNumber = new UserManage().getPhoneNumber(username);
		
		// 向客户端反馈信息
		out.println(username + "的电话号码（by hibernate）："+ phoneNumber);
		
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
