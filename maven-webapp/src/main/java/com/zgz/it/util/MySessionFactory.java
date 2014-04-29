package com.zgz.it.util;

import org.hibernate.SessionFactory;
import org.hibernate.boot.registry.StandardServiceRegistryBuilder;
import org.hibernate.cfg.Configuration;
import org.hibernate.service.ServiceRegistry;

// 在使用hibernate开发项目，请一定保证只有一个SessionFactory
final public class MySessionFactory {
	private static SessionFactory sessionFactory = null;
	
	private MySessionFactory() {
	}
	
	// 静态块，优先于构造函数执行，且执行一次，以保证类为单态
	static {
		// 1、创建Configuration，configure()不带参数，默认找"hibernate.cfg.xml"文件
		// 2、创建会话工程SessionFactory，这是一个重量级对象，因此MySessionFactory类设计为单态
		// Hibernate 3.X版本
		// sessionFactory = new Configuration().configure().buildSessionFactory();

		// Hibernate 4.X版本
		Configuration configuration = new Configuration().configure();
	    ServiceRegistry serviceRegistry = new StandardServiceRegistryBuilder().applySettings(configuration.getProperties()).build();
	    sessionFactory = configuration.buildSessionFactory(serviceRegistry);
	}
	
	public static SessionFactory getSessionFactory() {
		return sessionFactory;
	}
}
