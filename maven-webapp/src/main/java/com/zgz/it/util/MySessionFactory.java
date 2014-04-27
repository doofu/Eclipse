package com.zgz.it.util;

import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

// 在使用hibernate开发项目，请一定保证只有一个SessionFactory
final public class MySessionFactory {
	private static SessionFactory sessionFactory = null;
	
	private MySessionFactory() {
	}
	
	static {
		sessionFactory = new Configuration().configure().buildSessionFactory();
	}
	
	public static SessionFactory getSessionFactory() {
		return sessionFactory;
	}
}
