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
java.util.Date currentTime = new java.util.Date();		//�õ���ǰϵͳʱ�� 
String str_date1 = formatter.format(currentTime); 		//������ʱ���ʽ�� 
String str_date2 = currentTime.toString(); 				//��Date������ʱ��ת�����ַ�����ʽ 
%>
<%= str_date2 %><br>
<% out.println(str_date2); %><br>
�ҵĵ�һ��JSP��Ŀ<br><br>
<b><big>��Eclipse��Ŀ�Զ�����Tomcat��webappsĿ¼��</big></b><br><br>
��eclipse���½���Dynamic Web Project��д�ô����ѡ��Run on Server����ȻServer����ΪTomcat),�������к����Ƿ�����Tomcat�İ�װĿ¼�²�û�г��������������Ĺ������֡������ԣ���Ŀ��û���Զ�����Tomcat��Webapps�С�<br>
�������ǵ�eclipse�е�tomcat�����Ժ���eclipse���õ������������http://localhost:8080/webDemo/login.jsp(����webDemoΪ��������)�����������򿪡������������ⲿ��������ϴ�http://localhost:8080ʱȷû�г�����������Сè���档Ҳ����˵��tomcat��û���������������������Ƕ�����binĿ¼�µ��startup.bat��������http://localhost:8080�Ϳ��Կ���������Сè�ˣ�<br>
Ϊ��ʹ���ǵ���Ŀ����myelipse�����Զ�����webappsĿ¼������ʹ�ò��,����eclipse���������ô���ã��������ǲ�ϲ������������Ҫ��������������tomcat Server��һЩ�򵥵��޸ġ�<br>
����Ŀ¼��d:\apache-tomcat-7.0.52\webapps\web\index.jsp<br>
1����eclipse�ڵ�Tomcat������ֹͣ��Stop<br>
2��ɾ��֮ǰrun on server�е���Ŀ<br>
�����ߵ����Ǻ�չ����Ŀ�顣��ϣ���������Ŀ�ϵ���Ҽ���ѡ��Remove.<br>
3����servers����ѡ��Tomcat���������Ҽ������ѡ��Open<br>
�޸�Server Locations��Ĭ����ѡ��ĵ�һ�������û�н���1,2������ʱ����ѡ���ǻ�ɫ���޷��༭��<br>
ѡ��ڶ��Use Tomcat installation(takes......)<br>
4:�������Deploy path �ĳ� webapps,Ĭ����wptwebapps�������Server Path��Ӧ�����ϵ�Tomcat��װĿ¼<br>
5���������á��˳�<br>
6�����web��Ŀ��Run as --&gt; Run on Server--.....<br>
��ʱ����Ŀ���Զ�����tomcat��webapps���档������������������<br>
ע���ʱtomcat--confĿ¼�µ�server.xml�ļ��иı䣨eclipse�Զ��޸ġ�ע���޸ĵ����ݣ�<br><br>

<b><big>ʹ��Eclipse����һ��JSP��վ</big></b><br><br>
1: ���ļ���/���½���/Dynamic Web Project�˵���<br>
2: ��Eclipse�ġ���Ŀ��Դ���������У�ѡ��firstProject�ڵ��µ�WebContent�ڵ㣬����������Ҽ����ڴ򿪵Ŀ�ݲ˵��У�ѡ���½���/ JSP File�˵����New JSP File�Ի����ڸöԻ���ġ��ļ������ı����������ļ���index.jsp����������Ĭ������<br>
3: �޸�index.jsp����<br>
4: �����з�ʽ��/���ڷ����������С�<br><br>

<b><big>���JSPҳ�涥�˳��֡���ɫ���ı�����Ϣ:</big></b><br><br>
The superclass "javax.servlet.http.HttpServlet" was not found on the Java Build Path<br>
����Ϊû�����Tomcat����ʱ����ർ��<br>
�����Ǿ���Ľ��������<br>
�һ�web����-&gt;����-&gt;Java Build Path-&gt;Libraries-&gt;Add Libray...-&gt;Server Runtime-&gt;Tomcat Server-&gt;Finish<br><br><br>

<a href="html/MyPage1.html">MyPage1</a><br><br>
<a href="html/MyFormPage.html">MyFormPage</a><br>
</body>
</html>