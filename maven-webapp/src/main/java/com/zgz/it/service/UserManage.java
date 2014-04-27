package com.zgz.it.service;

import org.hibernate.Session;
import org.hibernate.Transaction;

import com.zgz.it.domain.Nametable;
import com.zgz.it.util.MySessionFactory;

public class UserManage {
	public String getPhoneNumber(String username) {
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
		
		Session session = MySessionFactory.getSessionFactory().openSession();
		
		Transaction ts = session.beginTransaction();
		try {
			session.save(nametable);
			
			ts.commit();
		} catch (Exception e) {
			success = false;
//			throw new RuntimeException(e.getMessage());
		}
		finally {
			session.close();
		}

		return success;
	}
}
