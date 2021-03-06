# -*- coding:GBK -*-
'''
Created on 2014年3月22日

@author: user

字符串在Python内部的表示是unicode编码，因此，在做编码转换时，通常需要以unicode作为中间编码，
即先将其他编码的字符串解码（decode）成unicode，再从unicode编码（encode）成另一种编码。
因此，转码的时候一定要先搞明白，字符串str是什么编码，然后decode成unicode，然后再encode成其他编码
chardet库是一个单独安装的库，可以判断字符串的编码类型
'''

import sys
import chardet

def printStingByChar(st):    
    for c in st:
        print c,
    print
        
def isUnicode(flag, st):
    if isinstance(st, unicode):
        print '\'', st, '\'', flag, ' :是 unicode'
    else:
        print '\'', st, '\'', flag, ' :不是unicode'
        
def isWhatCode(st):
    if isinstance(st, unicode):
        return 'unicode'
    else:
        return (chardet.detect(st))['encoding']

    
def printCodeType(st):
    if isinstance(st, unicode):
        print '=========该字符串是： unicode'
        return
    
    det = chardet.detect(st)

    print det
    print '========chardet判断该字符串是：', det['encoding']

#===========================================================================
# 主程序
#===========================================================================
if __name__ == '__main__':

    print sys.getdefaultencoding()
        
    sUTF8 = 'GBK字符'
    isUnicode('1不是', sUTF8)
    printStingByChar(sUTF8)
    print sUTF8.__class__
    printCodeType(sUTF8)
    print
    
    sUTF8_1 = 'GBK字符串长度比较长，就能正确判断字符类型'
    isUnicode('1_1不是', sUTF8_1)
    printStingByChar(sUTF8_1)
    print sUTF8.__class__
    printCodeType(sUTF8_1)
    print
    
    sUTF8ToUnicode = unicode(sUTF8, 'GB2312')
    isUnicode('2转换后是', sUTF8ToUnicode)
    printStingByChar(sUTF8ToUnicode)
    print sUTF8ToUnicode.__class__
    printCodeType(sUTF8ToUnicode)
    print
    
    sUTF8ToUnicode1 = sUTF8.decode('gbk')
    isUnicode('3转换后是', sUTF8ToUnicode1)
    printStingByChar(sUTF8ToUnicode1)
    printCodeType(sUTF8ToUnicode1)
    print
    
    sUTF8ToUnicode2 = sUTF8_1.decode(isWhatCode(sUTF8_1))
    isUnicode('3_1转换后是', sUTF8ToUnicode2)
    printStingByChar(sUTF8ToUnicode2)
    printCodeType(sUTF8ToUnicode2)
    print    
         
    sUnicode = u'UNICODE字符'
    isUnicode('4是', sUnicode)
    printStingByChar(sUnicode)
    printCodeType(sUTF8ToUnicode)


        
        