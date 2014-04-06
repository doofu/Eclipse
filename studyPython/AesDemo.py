# -*- coding: UTF-8 -*-
'''
Created on 2014年3月23日

@author: user
'''
from Crypto.Cipher import AES
from Crypto import Random
import base64

BLOCK_SIZE=AES.block_size

#===============================================================================
# 数据块必须是BLOCK_SIZE的整数倍，pad补齐，unpad去除多余部分
#===============================================================================
pad = lambda s: s + (BLOCK_SIZE - len(s) % BLOCK_SIZE) * chr(BLOCK_SIZE - len(s) % BLOCK_SIZE)
unpad = lambda s : s[0:-ord(s[-1])] 


def encrypt(message, passphrase, mode): 
    # passphrase MUST be 16, 24 or 32 bytes long, how can I do that ? 
    IV = Random.new().read(BLOCK_SIZE) 

    aes = AES.new(passphrase, mode, IV) 

    return base64.b64encode(IV + aes.encrypt(pad(message))) 

def decrypt(encrypted, passphrase, mode): 
    enc = base64.b64decode(encrypted)
    IV = enc[:16]
    aes = AES.new(passphrase, mode, IV) 

    return unpad(aes.decrypt(enc[16:])) 

if __name__ == '__main__':
    key = 'F74E66709E1C4647323DBEA92412411E'
    srcMsg = 'F74E66709E1C4647323DBEA92412411EF74E66709E1C4647323DBEA92412411E80'
    print srcMsg
    
#    obj = Crypto.Cipher.AES(key, Crypto.Cipher.AES.MODE_ECB)
    obj = AES.new(key, AES.MODE_ECB)
    
    msg = base64.b64encode(obj.encrypt(pad(srcMsg)))
    print 1, msg
    
    msg1 = unpad(obj.decrypt(base64.b64decode(msg)))
    print 2, msg1

    print 'CFB'
    msg = encrypt(srcMsg, key, AES.MODE_CFB)
    print 1, msg
    
    msg1 = decrypt(msg, key, AES.MODE_CFB)
    print 2, msg1
    
    print 'ECB'
    msg = encrypt(srcMsg, key, AES.MODE_ECB)
    print 1, msg
    
    msg1 = decrypt(msg, key, AES.MODE_ECB)
    print 2, msg1
    
    print 'CBC'
    msg = encrypt(srcMsg, key, AES.MODE_CBC)
    print 1, msg
    
    msg1 = decrypt(msg, key, AES.MODE_CBC)
    print 2, msg1

    print 'OFB'
    msg = encrypt(srcMsg, key, AES.MODE_OFB)
    print 1, msg
    
    msg1 = decrypt(msg, key, AES.MODE_OFB)
    print 2, msg1