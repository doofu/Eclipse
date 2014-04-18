package com.zgz.it.study_java;

public class HelloWorld {
	private String s;

	HelloWorld() {
		s = "你好，世界！（UTF-8)";
	}

	HelloWorld(String s) {
		this.s = s;
	}

	String sayHello() {
		System.out.println(s);
		
		return s;
	}
}
