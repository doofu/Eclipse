package com.zgz.it.study_java;

import java.io.*;
import java.net.*;

/**
 * <b>自己写最简单的http server<br>
 * 用以演示，为何需要Web服务器？</b><br>
 */

public class MyHttpServer {
	public static void main(String[] args) throws Exception {
		ServerSocket serverSocket = new ServerSocket(9999);
		System.out.println("在9999端口上等待连接......");
		Socket socket = serverSocket.accept();
		
		OutputStream outputStream = (OutputStream) socket.getOutputStream();
		BufferedReader bufferReader = new BufferedReader(new FileReader("c:\\temp\\hello.html"));
		String buf = "";
		while ((buf = bufferReader.readLine()) != null) {
			System.out.println(buf);
			outputStream.write(buf.getBytes());
		}
		
		//关闭流
		bufferReader.close();
		outputStream.close();
		socket.close();
	}
}
