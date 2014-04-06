# -*- coding:GBK -*-
'''
Created on 2014��3��22��

@author: user

�ַ�����Python�ڲ��ı�ʾ��unicode���룬��ˣ���������ת��ʱ��ͨ����Ҫ��unicode��Ϊ�м���룬
���Ƚ�����������ַ������루decode����unicode���ٴ�unicode���루encode������һ�ֱ��롣
��ˣ�ת���ʱ��һ��Ҫ�ȸ����ף��ַ���str��ʲô���룬Ȼ��decode��unicode��Ȼ����encode����������
chardet����һ��������װ�Ŀ⣬�����ж��ַ����ı�������
'''

import sys
import chardet

def printStingByChar(st):    
    for c in st:
        print c,
    print
        
def isUnicode(flag, st):
    if isinstance(st, unicode):
        print '\'', st, '\'', flag, ' :�� unicode'
    else:
        print '\'', st, '\'', flag, ' :����unicode'
        
def isWhatCode(st):
    if isinstance(st, unicode):
        return 'unicode'
    else:
        return (chardet.detect(st))['encoding']

    
def printCodeType(st):
    if isinstance(st, unicode):
        print '=========���ַ����ǣ� unicode'
        return
    
    det = chardet.detect(st)

    print det
    print '========chardet�жϸ��ַ����ǣ�', det['encoding']

#===========================================================================
# ������
#===========================================================================
if __name__ == '__main__':

    print sys.getdefaultencoding()
        
    sUTF8 = 'GBK�ַ�'
    isUnicode('1����', sUTF8)
    printStingByChar(sUTF8)
    print sUTF8.__class__
    printCodeType(sUTF8)
    print
    
    sUTF8_1 = 'GBK�ַ������ȱȽϳ���������ȷ�ж��ַ�����'
    isUnicode('1_1����', sUTF8_1)
    printStingByChar(sUTF8_1)
    print sUTF8.__class__
    printCodeType(sUTF8_1)
    print
    
    sUTF8ToUnicode = unicode(sUTF8, 'GB2312')
    isUnicode('2ת������', sUTF8ToUnicode)
    printStingByChar(sUTF8ToUnicode)
    print sUTF8ToUnicode.__class__
    printCodeType(sUTF8ToUnicode)
    print
    
    sUTF8ToUnicode1 = sUTF8.decode('gbk')
    isUnicode('3ת������', sUTF8ToUnicode1)
    printStingByChar(sUTF8ToUnicode1)
    printCodeType(sUTF8ToUnicode1)
    print
    
    sUTF8ToUnicode2 = sUTF8_1.decode(isWhatCode(sUTF8_1))
    isUnicode('3_1ת������', sUTF8ToUnicode2)
    printStingByChar(sUTF8ToUnicode2)
    printCodeType(sUTF8ToUnicode2)
    print    
         
    sUnicode = u'UNICODE�ַ�'
    isUnicode('4��', sUnicode)
    printStingByChar(sUnicode)
    printCodeType(sUTF8ToUnicode)


        
        