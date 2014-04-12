package com.zgz.it;


import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Sayhi
 */
@WebServlet("/Sayhi")
public class Sayhi extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Sayhi() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html;charset=GB2312");
		PrintWriter out = response.getWriter();
		
		request.setCharacterEncoding("GB2312");
		String Name = request.getParameter("Name");
		String phoneNumber;
		phoneNumber="";
		try {
			phoneNumber = getPhoneNumber(Name);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		out.println("<html>");
		out.println("<head><title>Sayhi</title></head>");
		out.println("<body>");
		out.println(Name + "的电话号码是" + phoneNumber + "，这是从数据库中查询到的  Maven");
		out.println("<br><br><br>为何要将c:/Program Files/MySQL/Connector J 5.1.28/mysql-connector-java-5.1.28-bin.jar拷贝到<br><br><br>");
		out.println("<br>c:/apache-tomcat-7.0.52/lib/<br>,");
		out.println("或c:/apache-tomcat-7.0.52/webapps/jspweb/WEB-INF/lib/目录下(会被自动删除)<br>");
		out.println("<br>否则就是java.lang.ClassNotFoundException: com.mysql.jdbc.Driver<br>");
		out.println("<br>但用Maven Project就不需要按以上方法做<br>");
		out.println("<br><br><br><a href='/testMavenWeb/html/MyFormPage.html'>返回</a>");
		out.println("</body>");
		out.println("</html>");
		out.close();
	}

	private String getPhoneNumber(String name) throws SQLException
	{
		String phonenumber = "'未找到号码'";
		Connection connection = null;
		
        try{
            Class.forName("com.mysql.jdbc.Driver");
        
            String url="jdbc:mysql://localhost:3306/test";
        
            connection = DriverManager.getConnection(url, "root", "root");
 
            Statement statement = connection.createStatement();
            ResultSet results = statement.executeQuery("select phonenumber from nametable where name ='" + name + "'");
            results.next();
            phonenumber = results.getString("phonenumber");
        }
        catch(ClassNotFoundException cfe)
        {
        	System.out.println(cfe);
        }
        catch(SQLException sqle)
        {
            System.out.println(sqle);
        }  
        finally
        {
        	connection.close();
        }		
		
		return phonenumber;
	}
	
	public String getServletInfo()
	{
		return "Sayhi Information";
	}
}

