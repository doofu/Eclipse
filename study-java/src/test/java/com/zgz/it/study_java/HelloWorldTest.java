package com.zgz.it.study_java;

import static org.junit.Assert.*;
import org.junit.Test;

import org.junit.After;
import org.junit.Before;

public class HelloWorldTest {

	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void test() {
		HelloWorld helloWorld = new HelloWorld();
		
		assertEquals("你好，世界！（UTF-8)", helloWorld.sayHello());
	}

}
