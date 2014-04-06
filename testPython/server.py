# -*- coding: UTF-8 -*-
'''
Created on 2014年3月21日

@author: user
'''

import socket

#===============================================================================
# 模拟Server程序
#===============================================================================
if __name__ == '__main__':
    DATA_BUFFER = 102400
#    ADDR = ('192.168.135.8', 9400)
    ADDR = ('127.0.0.1', 34564)
    
    try:
        # 创建服务器套接字
        tcpServerSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
        # 把地址绑定到套接字上   
        tcpServerSock.bind(ADDR)
        # 监听连接（最多允许3个连接同时连进来）                        
        tcpServerSock.listen(3)
   
        while True:
            print 'waiting for connection...'
            
            # 接受客户端连接
            tcpClientSock, addr = tcpServerSock.accept() 
            print '...connected from:', addr
    
            encCode = "QTIxMw==,MTIzRg==,QU5EWV9JU19BX0JBRF9NQU4=,MzMz\n"
#            encCode = "QTIxMw==,MTIzRg==,QU5EWV9JU19BX0JBRF9NQU4=\nMkZBMjNhZw==,MTIzRg==,MkZBMjNhRg==,QTlDRg==\n"
#            encCode = 'MkZBMjNhZw==,MTIzRg==,MkZBMjNhRg==,QTlDRg==,QU5EWV9JU19BX0JBRF9NQU4=,QUIzNA==,MzQ1Qg==\n'
#            encCode = 'MkZBMjNhZw==,MTIzRg==,MkZBMjNhRg==,QTlDRg==,MDE=,QU5EWV9JU19BX0JBRF9NQU4=,QUIzNA==,MzQ1Qg==\n'
#            encCode = 'ZmI1MTZjYWE1MTI3YTQyNzQ1N2FjM2M2MTc4Mjk5MTYxMmIyOGJiNDVkYTY3NDAyZTM1Yzg5ODExMmMzMGEzYThjYjk3YjYxZGI2ZWU5NTg3ODNlNGUxOWEzZTczMWY3YTVhYg==,QklUQ0g=ZmZkYjM1MGJlZDZiNzhhNWFlNjVmZTkwMzQyNDU1ZWQzODQxNTY5YzRjZjI0NGY2OTdjMWY3NzUyZjkxYWY0YjI5NGZkYWMxNTNiNDI4NDJkN2U4YzFmYTU0NGRhOTZmNDAyZA==,ZmZkYjM1MGJlZDZiNzhhNWFlNjVmZTkwMzQyNDU1ZWQzODQxNTY5YzRjZjI0NGY2OTdjMWY3NzUyZjkxYWY0YjI5NGZkYWMxNTNiNDI4NDJkN2U4YzFmYTU0NGRhOTZmNDAyZA==\n'
# 向客户端发送原始数据
            tcpClientSock.send(encCode)
            print "Server send: ", encCode

# 接受客户端的处理结果数据
            data = tcpClientSock.recv(DATA_BUFFER)
            print 'accept from ', addr, ' is ', data

# 假设正确，发送‘SUCCESS\n'成功信息给客户端            
            tcpClientSock.send('SUCCESS\n')
            
# 接受客户端发来的学号和手机号
            data = tcpClientSock.recv(DATA_BUFFER)
            print 'Study Number + Mobil Number: ', data
            
# 发送’NICE JOB\n'信息给客户端
            tcpClientSock.send('NICE JOB\n')
            
            tcpClientSock.close()
            
    except socket.error, e:
        print 'Network Error!', e
            
    finally:
        tcpServerSock.close()
        

    
        