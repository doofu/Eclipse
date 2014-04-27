package com.zgz.it.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLDecoder;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.zgz.it.domain.Nametable;
import com.zgz.it.service.UserManage;

/**
 * Servlet implementation class AddUsersByHibernate
 */
public class AddUsersByHibernate extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public AddUsersByHibernate() {
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
		
		Nametable nametable = new Nametable();
		boolean b = false;
		String username = null;
		
		try {
			username = request.getParameter("username2");
			// 解决Get方式下中文乱码问题
			if (request.getMethod().equals("GET")) {
				username = URLDecoder.decode(username,"UTF-8");
			}		
			nametable.setName(username);
			
			nametable.setAge(Integer.valueOf(request.getParameter("age2")).intValue());
			nametable.setSalary(Double.valueOf(request.getParameter("salary2")).doubleValue());
			nametable.setPhonenumber(request.getParameter("phonenumber2"));
			nametable.setEmail(request.getParameter("email2"));
			nametable.setPassword(request.getParameter("password2"));
			
			// 访问业务逻辑层，查找电话号码 
			b = new UserManage().addUser(nametable);
		} catch (Exception e) {
			username = "数据有误，";
			b = false;
		}
		
		// 向客户端反馈信息
		if (b == true) 
			out.println(username + "增加成功");
		else
			out.println(username + "增加失败");
		
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
