package com.zgz.it.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
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
		
		String username = null;
		boolean b = false;
		
		// 取客户端上送信息
		Nametable nametable = getUser(request);
		
		if (nametable != null) {
			username = nametable.getName();
			
			try {
				// 访问业务逻辑层，增加用户 
				b = new UserManage().addUser(nametable);
			} catch (Exception e) {
				username = "数据有误，";
				b = false;
			}
		} else {
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
	
	/**
	 * 取客户端上送的数据
	 * @param request
	 * @return Nametable
	 */
	private Nametable getUser(HttpServletRequest request) throws UnsupportedEncodingException {
		Nametable nametable = new Nametable();
		String username;
				
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
		} catch(Exception e) {
			nametable = null;
		}
		
		return nametable;
	}
}

