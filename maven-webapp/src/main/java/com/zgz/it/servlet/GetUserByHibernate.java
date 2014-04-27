package com.zgz.it.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLDecoder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.OutputFormat;
import org.dom4j.io.XMLWriter;

import com.zgz.it.domain.Nametable;
import com.zgz.it.service.UserManage;

/**
 * Servlet implementation class SayhiForHibernate
 */
@WebServlet("/GetUserByHibernate")
public class GetUserByHibernate extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public GetUserByHibernate() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	
		request.setCharacterEncoding("UTF-8");
		
		String username = request.getParameter("username");

		// 解决Get方式下中文乱码问题
		if (request.getMethod().equals("GET"))
			username = URLDecoder.decode(username,"UTF-8");
		
		// 访问业务逻辑层，查找用户信息 
		Nametable nametable = new UserManage().getUser(username);

		// 向客户端反馈信息
		PrintWriter out = response.getWriter();
		
		// 使用dom4j向客户端反馈XML格式的信息
		Document document = DocumentHelper.createDocument();
		
		Element rootElement = document.addElement("users");
		rootElement.addComment("This is a comment!");
		Element userElement = rootElement.addElement("user");
		
		if (nametable != null) {
			Element nameElement = userElement.addElement("name");
			Element ageElement = userElement.addElement("age");
			Element salaryElement = userElement.addElement("salary");
			Element phonenumberElement = userElement.addElement("phonenumber");
			Element emailElement = userElement.addElement("email");
			Element passwordElement = userElement.addElement("password");
			
			nameElement.setText(nametable.getName());
			ageElement.setText(nametable.getAge() + "");
			salaryElement.setText(nametable.getSalary() + "");
			phonenumberElement.setText(nametable.getPhonenumber());
			emailElement.setText(nametable.getEmail());
			passwordElement.setText(nametable.getPassword());
		} 
		
		response.setContentType("text/xml; charset=utf-8");
		response.setHeader("pragma", "no-cache");
		response.setHeader("cache-control", "no-cache");
		
		OutputFormat format = OutputFormat.createPrettyPrint();
		format.setEncoding("utf-8");
		
		XMLWriter xmlWriter = new XMLWriter(out, format);
		
		xmlWriter.write(document);
		
		out.flush();
		
//		out.close();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		
		doGet(request, response);
	}

}
