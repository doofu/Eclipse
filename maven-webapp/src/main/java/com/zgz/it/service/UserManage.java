package com.zgz.it.service;

import org.hibernate.Session;
import org.hibernate.Transaction;

import com.zgz.it.domain.Nametable;
import com.zgz.it.util.MySessionFactory;

/**
 * 用户管理的业务逻辑层程序
 * 使用Hibernate访问数据库
 */
public class UserManage {
	public String getPhoneNumber(String username) {
		// 获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		String phoneNumber = "";
		try {
			Nametable nametable = (Nametable) session.load(Nametable.class, username);
			phoneNumber = nametable.getPhonenumber();
		} catch (Exception e) {
			phoneNumber = "电话号码未找到";
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			session.close();
		}
		return phoneNumber;
	}
	
	public boolean addUser(Nametable nametable) {
		
		boolean success = true;
		
		// 1、获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		// 2、开始事务处理，对于增删改操作，必须开启事物
		Transaction ts = session.beginTransaction();
		try {
			// 3、将用户信息增加到数据库表中
			session.save(nametable);
			
			// 4、提交事务
			ts.commit();
		} catch (Exception e) {
			success = false;
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			// 5、关闭会话
			session.close();
		}

		return success;
	}
}
