<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("yyyy-MM-dd HH:mm:ss"); 
java.util.Date currentTime = new java.util.Date();		//得到当前系统时间 
String str_date1 = formatter.format(currentTime); 		//将日期时间格式化 
String str_date2 = currentTime.toString(); 				//将Date型日期时间转换成字符串形式 
%>
<%= str_date2 %><br>
<% out.println(str_date2); %><br>
我的Maven骨架的Web项目<br><br>
本页面采用的是UTF-8字符编码<br>
<b><big>以下逐步演示各种技术的应用</big></b><br><br>

<a href="html/MyPage1.html">演示Javascript、Applet、Servlet等技术</a><br><br>
<a href="html/MyFormPage.html">演示表单提交，Servlet及数据库JDBC访问</a><br><br>
<a href="html/MyPageAjax.html">演示Ajax</a><br><br>
<a href="html/MyPageJQuery.html">演示JQuery，返回数据格式为文本</a><br><br>
<a href="html/MyPageJQueryHibernate.html">演示JQuery Hibernate，返回数据格式为文本</a><br><br>
<a href="html/MyPageJQueryXml.html">演示JQuery Hibernate，返回数据格式为XML</a><br><br>
</body>
</html>