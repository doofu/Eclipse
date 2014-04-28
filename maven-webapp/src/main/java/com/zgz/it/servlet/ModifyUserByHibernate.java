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
 * Servlet implementation class ModifyUserByHibernate
 */
@WebServlet("/ModifyUserByHibernate")
public class ModifyUserByHibernate extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ModifyUserByHibernate() {
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
		Nametable nametable = getRequestData(request);
		
		if (nametable != null) {
			username = nametable.getName();
			
			try {
				// 访问业务逻辑层，增加用户 
				b = new UserManage().modifyUser(nametable);
			} catch (Exception e) {
				username = "数据有误，";
				b = false;
			}
		} else {
			username = "数据有误，";
			b = false;
		}
		
		// 向客户端反馈信息
		response.setContentType("text/html;charset=UTF-8");
		PrintWriter out = response.getWriter();
		
		if (b == true) 
			out.println(username + "修改成功");
		else
			out.println(username + "修改失败");
		
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
	private Nametable getRequestData(HttpServletRequest request) throws UnsupportedEncodingException {
		Nametable nametable = new Nametable();
		String username;
				
		try {
			username = request.getParameter("username");
			// 解决Get方式下中文乱码问题
			if (request.getMethod().equals("GET")) {
				username = URLDecoder.decode(username,"UTF-8");
			}		
			nametable.setName(username);
			
			nametable.setAge(Integer.valueOf(request.getParameter("age")).intValue());
			nametable.setSalary(Double.valueOf(request.getParameter("salary")).doubleValue());
			nametable.setPhonenumber(request.getParameter("phonenumber"));
			nametable.setEmail(request.getParameter("email"));
			nametable.setPassword(request.getParameter("password"));
		} catch(Exception e) {
			nametable = null;
		}
		
		return nametable;
	}
}

