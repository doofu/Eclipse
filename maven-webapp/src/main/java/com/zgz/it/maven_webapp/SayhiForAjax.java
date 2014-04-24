package com.zgz.it.maven_webapp;

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
 * Servlet implementation class SayhiForAjax
 */
@WebServlet("/SayhiForAjax")
public class SayhiForAjax extends HttpServlet {
	private static final long serialVersionUID = 2L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public SayhiForAjax() {
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
		String phoneNumber;
		phoneNumber="";
		try {
			phoneNumber = getPhoneNumber(username);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		out.println(username + "的电话号码："+ phoneNumber);
		out.close();
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
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
