package com.zgz.it.study_java;

/**
 * 演示JUnit<br>
 * 用Maven的命令：cobertura:cobertura可以生成测试覆盖度报告<br>
 * @author user
 * @version 1.0
 */

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
