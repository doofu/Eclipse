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
	public Nametable getUser(String username) {
		// 获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		Nametable nametable = new Nametable();
		try {
			// get不支持延迟加载，而load支持。
			// 当查询特定的数据库中不存在的数据时，get会返回null，而load则抛出异常。
//			nametable = (Nametable)session.load(Nametable.class, username);
			nametable = (Nametable)session.get(Nametable.class, username);

// 解决load延迟加载问题：
// Nametable.hbm.xml中，如果lazy的属性值为true（缺省为true），那么在使用load方法加载数据时，
// 只有确实用到数据的时候才会发出sql语句；这样有可能减少系统的开销
// 因此，如果没有一下语句，load语句没有执行，return时返回值为null
// 解决方法：一、将lazy的属性值设为false
//			<class name="com.zgz.it.domain.Nametable" table="NAMETABLE" lazy="false">
//			二、在return之前，使用nametable数据，让sql执行
//			System.out.println("找到记录！" + nametable.getPhonenumber());
		} catch (Exception e) {
			nametable = null;
//			throw new RuntimeException(e.getMessage());
		} 
		
		finally {
			session.close();
		}
		
		return nametable;
	}
	
	public String getPhoneNumber(String username) {
		// 获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		String phoneNumber = "";
		try {
			// get不支持延迟加载，而load支持。
			// 当查询特定的数据库中不存在的数据时，get会返回null，而load则抛出异常。
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
		
		// 2、开始事务处理，对于增删改操作，必须开启事务
		Transaction ts = session.beginTransaction();
		try {
			// 3、将用户信息增加到数据库表中
			session.save(nametable);
			
			// 4、提交事务
			ts.commit();
		} catch (Exception e) {
			success = false;
			ts.rollback();
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			// 5、关闭会话
			session.close();
		}

		return success;
	}
	
	public boolean deleteUser(String username) {
		
		boolean success = true;
		
		// 1、获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		// 2、开始事务处理，对于增删改操作，必须开启事务
		Transaction ts = session.beginTransaction();
		try {
			// 3、将用户信息从数据库表中删除
			Nametable nametable = (Nametable)session.get(Nametable.class, username);
			session.delete(nametable);
			
			// 4、提交事务
			ts.commit();
		} catch (Exception e) {
			success = false;
			ts.rollback();
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			// 5、关闭会话
			session.close();
		}

		return success;
	}
	
	public boolean modifyUser(Nametable nametable) {
		
		boolean success = true;
		
		// 1、获取一个会话session
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		// 2、开始事务处理，对于增删改操作，必须开启事务
		Transaction ts = session.beginTransaction();
		try {
			// 3、将用户信息修改到数据库表中
			Nametable tNametable = (Nametable)session.get(Nametable.class, nametable.getName());
			tNametable.setAge(nametable.getAge());
			tNametable.setSalary(nametable.getSalary());
			tNametable.setPhonenumber(nametable.getPhonenumber());
			tNametable.setEmail(nametable.getEmail());
			tNametable.setPassword(nametable.getPassword());
			session.update(tNametable);
			session.flush();
			
			// 4、提交事务
			ts.commit();
		} catch (Exception e) {
			success = false;
			ts.rollback();
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			// 5、关闭会话
			session.close();
		}

		return success;
	}
}
