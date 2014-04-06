# -*- coding: utf-8 -*-
'''
Created on 2014年3月29日

@author: user
'''
import win32api  
import win32con

if __name__ == '__main__':
    win32api.MessageBox(win32con.NULL, u'Python 你好！', u'你好', win32con.MB_OK)  