<%@ page language="java" contentType="text/html; charset=GB18030"
    pageEncoding="GB18030"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=GB18030">
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
我的第一个JSP项目<br><br>
<b><big>将Eclipse项目自动部署到Tomcat的webapps目录下</big></b><br><br>
在eclipse中新建的Dynamic Web Project。写好代码后，选择Run on Server（当然Server配置为Tomcat),但是运行后我们发下在Tomcat的安装目录下并没有出现我们所建立的工程名字。很明显，项目并没有自动部署到Tomcat的Webapps中。<br>
不信我们等eclipse中的tomcat启动以后。在eclipse内置的浏览器中输入http://localhost:8080/webDemo/login.jsp(其中webDemo为工程名字)。可以正常打开。但是我们在外部的浏览器上打开http://localhost:8080时确没有出现所期望的小猫画面。也就是说，tomcat并没有正常启动。（经常我们都是在bin目录下点击startup.bat后。在输入http://localhost:8080就可以看到期望的小猫了）<br>
为了使我们的项目能像myelipse那样自动部署到webapps目录（可以使用插件,但是eclipse插件好像不怎么好用，反正我是不喜欢）。我们需要对我们所建立的tomcat Server做一些简单的修改。<br>
部署目录：d:\apache-tomcat-7.0.52\webapps\web\index.jsp<br>
1：将eclipse内的Tomcat服务器停止。Stop<br>
2：删除之前run on server中的项目<br>
点击左边的三角号展开项目组。在希望部署的项目上点击右键，选择Remove.<br>
3：在servers下面选择Tomcat服务器。右键点击后选择Open<br>
修改Server Locations（默认是选择的第一个。如果没有进行1,2步操作时。该选项是灰色的无法编辑）<br>
选择第二项（Use Tomcat installation(takes......)<br>
4:将下面的Deploy path 改成 webapps,默认是wptwebapps，上面的Server Path对应电脑上的Tomcat安装目录<br>
5：保存设置。退出<br>
6：点击web项目，Run as --&gt; Run on Server--.....<br>
这时。项目会自动部署到tomcat的webapps下面。启动后可以正常浏览。<br>
注意此时tomcat--conf目录下得server.xml文件有改变（eclipse自动修改。注意修改的内容）<br><br>

<b><big>使用Eclipse开发一个JSP网站</big></b><br><br>
1: “文件”/“新建”/Dynamic Web Project菜单项<br>
2: 在Eclipse的“项目资源管理器”中，选中firstProject节点下的WebContent节点，并单击鼠标右键，在打开的快捷菜单中，选择“新建”/ JSP File菜单项，打开New JSP File对话框，在该对话框的“文件名”文本框中输入文件名index.jsp，其他采用默认设置<br>
3: 修改index.jsp代码<br>
4: “运行方式”/“在服务器上运行”<br><br>

<b><big>如果JSP页面顶端出现“红色”的报错信息:</big></b><br><br>
The superclass "javax.servlet.http.HttpServlet" was not found on the Java Build Path<br>
是因为没有添加Tomcat运行时相关类导致<br>
下面是具体的解决方法：<br>
右击web工程-&gt;属性-&gt;Java Build Path-&gt;Libraries-&gt;Add Libray...-&gt;Server Runtime-&gt;Tomcat Server-&gt;Finish<br><br><br>

<a href="html/MyPage1.html">MyPage1</a><br><br>
<a href="html/MyFormPage.html">MyFormPage</a><br>
</body>
</html>