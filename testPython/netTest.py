# -*- coding: UTF-8 -*-

'''
Created on 2014年3月17日

@author: user
'''

import base64
import sys
import socket

#===============================================================================
# isNotHexNumber:判断字符串是否是十六进制数
#===============================================================================
def isNotHexNumber(s):
    for c in s:
        if not (c.isdigit() or (c >='A' and c <= 'F') or (c >='a' and c <= 'f')):
            return True

    return False

#===============================================================================
# base64StringToList：按‘,’切分数据成“数组”，按“数组”解码，并放在列表中
#===============================================================================
def base64StringToList(encCode):
    encCodeList = encCode.split(',')
    
    decCodeList = []
    for word in encCodeList:
        decCodeList.append(base64.b64decode(word))
        
    return decCodeList

#===============================================================================
# getMaxList：去除不合法的数据；取累加和最小的“数组”，进行十进制转换，将每个数值放置在列表中       
#===============================================================================
def getMinList(decCodeList):
    minNum = sys.maxint
    minList = []
    
    for word in decCodeList:
        if isNotHexNumber(word):
            continue
            
        sumNum = 0
        numList = []
        
        for c in word:
            num = int(c, 16)
            sumNum += num
            numList.append(num)
        
        if sumNum < minNum:
            minList = numList
            minNum = sumNum
                
    return minList

#===============================================================================
# listToBase64String：将数据组转变为字符串，并编码
#===============================================================================
def listToBase64String(nList):
    st = ''
                
    for num in nList:
        if st == '':
            st = st + str(num)
        else:
            st = st + ' ' + str(num)
    
    return base64.b64encode(st) + '\n'

#===============================================================================
# receiveData：从服务器接收数据
# 优点：不受DATA_BUFFER大小的限制
# 缺点：可能没有读完服务器端的数据，会影响后面从服务器读取数据的内容
#===============================================================================
def receiveData(tcpClientSock):
    data = ''
    preChar = ''
    while True:
        currentChar = tcpClientSock.recv(1)
        if '\\' == preChar and 'n' == currentChar:
            break
        
        data = data + preChar
        preChar = currentChar

    return data

#===============================================================================
# prompt: 查看数据内容
#===============================================================================
def prompt(message, data):
    print message, '\t', data

#===============================================================================
# 主程序
#===============================================================================
if __name__ == '__main__':
    DATA_BUFFER = 102400
#    ADDR = ('192.168.135.8', 9400)
    ADDR = ('127.0.0.1', 34564)
    
    try:
        tcpClientSock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)      # 创建客户端套接字
        tcpClientSock.connect(ADDR)                                     # 连接地址和端口为ADDR的服务器
        
#        encCode = "QTIxMw==,MTIzRg==,QU5EWV9JU19BX0JBRF9NQU4=\n"
#        encCode = 'MkZBMjNhZw==,MTIzRg==,MkZBMjNhRg==,QTlDRg==,MDE=,QU5EWV9JU19BX0JBRF9NQU4=,QUIzNA==,MzQ1Qg==\n'
# 从服务器读取数据
        encCode = tcpClientSock.recv(DATA_BUFFER)
#        encCode = receiveData(tcpClientSock)    # 另一种读取服务器数据的方法
        
# 截取'\n'之前的数据串
        i = encCode.find('\n')
        if i != -1:
            encCode = encCode[0 : i]
            

        prompt('encCode:', encCode)

# 按‘,’切分数据成“数组”，按“数组”解码，并放在列表中
        decCodeList= base64StringToList(encCode)
        prompt('decCodeList:', decCodeList)

# 去除不合法的数据；取累加和最小的“数组”，进行十进制转换，将每个数值放置在列表中            
        minList = getMinList(decCodeList)
        prompt('minList:', minList)
        
# 排序
        minList.sort()
        prompt('sorted:', minList) 

# 将数据组转变为字符串，并编码                
        b64Str = listToBase64String(minList)
        prompt('send data:', b64Str)

# 将结果发往服务器    
        tcpClientSock.send(b64Str)

# 从服务读取数据，判断是不是’SUCCESS‘ 
        ret = tcpClientSock.recv(DATA_BUFFER)       
        if ret == 'SUCCESS\n':
            
            prompt('Server return: ', ret)
            
# 将学号和手机号码发往服务器            
            tcpClientSock.send('13274****+18800001231\n')
            prompt('Send Study Number and Mobile Number to Server!', '')
            
# 接受服务器发来的消息
            prompt('Server return: ', tcpClientSock.recv(DATA_BUFFER))
        else:
            prompt('Server return: ', ret)
            
    except socket.error, e:
        prompt('Network Error!', e)

    finally:
        tcpClientSock.close()
        


    




    