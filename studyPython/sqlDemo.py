# -*- coding: UTF-8 -*-
'''
Created on 2014年3月25日

@author: user
'''

import MySQLdb
import chardet

def isUnicode(flag, st):
    if isinstance(st, unicode):
        print '\'', st, '\'', flag, ' :是 unicode'
    else:
        print '\'', st, '\'', flag, ' :不是unicode'

def printCodeType(st):
    if isinstance(st, unicode):
        print '=========该字符串是： unicode'
        return
    
    det = chardet.detect(st)

    print det
    print '========chardet判断该字符串是：', det['encoding']

def isWhatCode(st):
    if isinstance(st, unicode):
        return 'unicode'
    else:
        return (chardet.detect(st))['encoding']
    
if __name__ == '__main__':
    
    try:
    #    conn=MySQLdb.connect(host='localhost',user='user',passwd='user',port=3306)
#        conn=MySQLdb.connect(host='localhost',user='root',passwd='root',port=3306, charset='gbk') # 体验一下两者的区别
        conn=MySQLdb.connect(host='localhost',user='root',passwd='root',port=3306, charset='utf8')
        
#        conn=MySQLdb.connect(host='localhost',user='root',passwd='root',port=3306, charset='gbk') # 当-*- coding: GBK -*-时

        cur=conn.cursor()
        
        cur.execute('drop database testdb')
        cur.execute('create database if not exists testdb')
#        cur.execute('create database testdb DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci') # if not exists testdb')
#        cur.execute('create database testdb CHARACTER SET gbk COLLATE gbk_chinese_ci') # if not exists testdb')

        conn.select_db('testdb')
        cur.execute('drop table if exists testTable')
        cur.execute('create table testTable(id int,info varchar(20))')
         
        s = '你好，世界'
        print '插入和修改时，字符编码是： ', isWhatCode(s)       # 以下插入和修改时，字符编码是UTF-8，由程序第一行定义
        value=[1,s]
        
        cur.execute('insert into testTable values(%s,%s)',value)
         
        values=[]
        for i in range(20):
            values.append((i,'hi rollen'+str(i)))
             
        cur.executemany('insert into testTable values(%s,%s)',values)
     
        cur.execute('update testTable set info="I am rollen" where id=3')
        cur.execute('update testTable set info="我是罗恩" where id=4')
        
#        cur.execute("set names utf8")    #不需要，只是展示一下
        cur.execute('select * from testTable')
        while True:
            row = cur.fetchone()
            if row == None:
                break
            print 
            
            # 一、如何运行字符界面的客户端工具：
            # 1、cd d:\Program Files\MySQL\MySQL Server 5.6\
            # 2、拷贝一个my-default.ini 到 my.ini文件
            # 3、在系统程序中，找到MySQL 5.6 Command Line Client并运行
            # 二、查看数据库字符集：
            # 1、查看MySQL数据库服务器和数据库MySQL字符集：show variables like '%char%';
            # 2、查看MySQL数据表（table）的MySQL字符集：show table status from sqlstudy_db like '%countries%';
            # 3、查看MySQL数据列（column）的MySQL字符集：show full columns from countries;
            # 三、
            # 为何 查看数据库字符集是utf8_general_ci，而从数据库中读出的是unicode，而不是UTF8?????
            
            print row[0], '\t', row[1], '\t\t从数据库中读出的字符编码是：', isWhatCode(row[1]), '\tstr(row[0]的字符编码是UTF8：', isWhatCode(str(row[0]).decode('utf8'))
    
        conn.commit()
        
        cur.close()
        
        conn.close()
     
    except MySQLdb.Error,e:
        print "Mysql Error %d: %s" % (e.args[0], e.args[1])