//  从此版本起，有Visual Studio 6.0 转为Visual Studio 2010

#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "AesCipher.h"
#include "Base64.h"

#define BUFFERSIZE 1024
#define FILESIZE 10240

using namespace std;

char in[BUFFERSIZE] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
char in1[FILESIZE];

void test1();
void test2();
void test3();
//void test4();

int main()
{
	test1();
//	test2();
//	test3();
//	test4();

    return 0;
}

//
// Test1: encrypt/decrypt string with ECB, CBC, CFB, OFB working modes.
//
void test1()
{
    cout << "=======================================" << endl;
    cout << ">> Test1: encrypt/decrypt string with ECB, CBC, CFB, OFB working modes." << endl;

    cout << "Plaintext: \n" << in << endl;
    cout << "Length: " << strlen(in) << endl;

    char out[BUFFERSIZE];
    char out2[BUFFERSIZE+345];
    char out3[BUFFERSIZE+345];
//  由于out2、out3存放的是Base64代码，长度需要根据BUFFERSIZE计算而得，345是有Base64::calculateBase64Len(BUFFERSIZE)计算而得。

    AesCipher crypto;
    crypto.makeRoundKey("12345678901234567890123456789012");

    // ECB mode
    cout << "\nECB Mode: " << endl;
    crypto.encrypt(in, out, BUFFERSIZE, AesCipher::ECB);

    Base64::binToBase64((unsigned char*)out, out3, BUFFERSIZE);
    cout << "base64: " << out3 << endl;
    Base64::base64ToBin(out3, (unsigned char*)out, Base64::calculateBase64Len(BUFFERSIZE));

    crypto.decrypt(out, out2, BUFFERSIZE, AesCipher::ECB);
    out2[BUFFERSIZE - 1] = '\0';
    cout << out2 << endl;
    assert(strcmp(in, out2) == 0);

    // CBC mode, default
    crypto.setIV("chain.0123456789");

    cout << "\nCBC Mode: " << endl;
    crypto.encrypt(in, out, BUFFERSIZE);
    
    Base64::binToBase64((unsigned char*)out, out3, BUFFERSIZE);
    cout << "base64: " << out3 << endl;
    Base64::base64ToBin(out3, (unsigned char*)out, Base64::calculateBase64Len(BUFFERSIZE));

    crypto.decrypt(out, out2, BUFFERSIZE);
    out2[BUFFERSIZE - 1] = '\0';
    cout << out2 << endl;
    assert(strcmp(in, out2) == 0);

    // CFB mode
    cout << "\nCFB Mode: " << endl;
    crypto.encrypt(in, out, BUFFERSIZE, AesCipher::CFB);
    
    Base64::binToBase64((unsigned char*)out, out3, BUFFERSIZE);
    cout << "base64: " << out3 << endl;
    Base64::base64ToBin(out3, (unsigned char*)out, Base64::calculateBase64Len(BUFFERSIZE));

    crypto.decrypt(out, out2, BUFFERSIZE, AesCipher::CFB);
    out2[BUFFERSIZE - 1] = '\0';
    cout << out2 << endl;
    assert(strcmp(in, out2) == 0);

    // OFB mode
    cout << "\nOFB Mode: " << endl;
    crypto.encrypt(in, out, BUFFERSIZE, AesCipher::OFB);
    
    Base64::binToBase64((unsigned char*)out, out3, BUFFERSIZE);
    cout << "base64: " << out3 << endl;
    Base64::base64ToBin(out3, (unsigned char*)out, Base64::calculateBase64Len(BUFFERSIZE));

    //crypto.decrypt(out, out2, 32, AesCipher::OFB);
    // at this mode, decryption is the same with encryption
    crypto.encrypt(out, out2, BUFFERSIZE, AesCipher::OFB);
    out2[BUFFERSIZE - 1] = '\0';
    cout << out2 << endl;
    assert(strcmp(in, out2) == 0);
}

//
// Test2: encrypt/decrypt string with arbitrary lenght and CTR working mode.
//
void test2()
{
    cout << "\n=======================================" << endl;
    cout << ">> Test2: encrypt/decrypt string with arbitrary lenght and CTR working mode." << endl;
	ifstream fin("Plaintext.txt");
	int i = 0;
	while(fin.get(in1[i]))
	{
		i++;
	}

    // const char in[] = "2010.10.4工作记录——liyang加密程序测试姚尧 2010.10.4一．测试平台Win7二．内容简述单独测试xxtea算法的加密模块的加/解密功能。1.加密功能：从文本plain.txt读入明文，由程序加密后将密文写入文本cipher.txt。2.解密功能：从文本cipher.txt读入密文，由程序解密后将明文写入文本plain_de.txt。三．测试报告当加密内容过多时，会出现越界，程序瘫痪。如下图：1.	加密内容过多，无法加密：（输入4，000个阿拉伯数字）";
	// 大小取决于 BUFFERSIZE，超过则越界。
	ofstream Outbase("Ciphertext.txt");

	ofstream Out("Plaintext restored.txt");


    cout << "Plaintext: " << in1 << endl;
    cout << "Length: " << strlen(in1) << endl;
	char KEY[128];
	cout << "输入密钥（32个字符）: ";
	cin >> KEY;

    char counter[16];
    memset(counter, 0, 16);
    counter[5] = -113;
    AesCipher crypto;
    crypto.makeRoundKey(KEY);//"Base64::binToBase64((unsigned char*)out, buf, outLen);");   

	// setCouter是何含义？
    crypto.setCounter(counter);

    int outLen = crypto.calculateCipherLen(strlen(in1));
    char *out = new char[outLen];
    if (out == 0)
        return ;
    crypto.encryptString(in1, out, strlen(in1), AesCipher::CTR);

    char *buf = new char[Base64::calculateBase64Len(outLen)];
    Base64::binToBase64((unsigned char*)out, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
	Outbase << buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)out, outLen);
    delete [] buf;

    char *out2 = new char[outLen + 1];
    if (out2 == 0)
        return ;
    int len = crypto.decryptString(out, out2, outLen, AesCipher::CTR);
    out2[len] = '\0';
	cout << "Plaintext restored: " << out2 << endl;
    Out << out2 << endl;
    assert(strcmp(in1, out2) == 0);

    delete [] out;
    delete [] out2;
//	system("pause");
}

//
// Test3: Thc case when in and out pointers point to the same address.
//
void test3()
{
    cout << "\n=======================================" << endl;
    cout << ">> Test3: Thc case when in and out pointers point to the same address." << endl;

    char in[100] = "Thc case when in and out pointers point to the same address.";
    char in2[100] = "Thc case when in and out pointers point to the same address.";
    cout << "Plaintext: " << in << endl;
    cout << "Length: " << strlen(in) << endl;

    AesCipher crypto;
    crypto.makeRoundKey("this is a key.ok");   
    crypto.setIV("chain.0123456789");

    int outLen = crypto.calculateCipherLen(strlen(in));
    char *buf;
    int len;

    // input and output pointers are all "in"!

    // ECB mode
    cout << "\nECB Mode: " << endl;

	crypto.encryptString(in, in, strlen(in), AesCipher::ECB);

    buf = new char[Base64::calculateBase64Len(outLen)];

    Base64::binToBase64((unsigned char*)in, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)in, outLen);
    delete [] buf;

    len = crypto.decryptString(in, in, outLen, AesCipher::ECB);
    in[len] = '\0';
    cout << "Plaintext restored: " << in << endl;
    assert(strcmp(in, in2) == 0);

    // CBC mode
    cout << "\nCBC Mode: " << endl;
    crypto.encryptString(in, in, strlen(in), AesCipher::CBC);

    buf = new char[Base64::calculateBase64Len(outLen)];
    Base64::binToBase64((unsigned char*)in, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)in, outLen);
    delete [] buf;

    len = crypto.decryptString(in, in, outLen, AesCipher::CBC);
    in[len] = '\0';
    cout << "Plaintext restored: " << in << endl;
    assert(strcmp(in, in2) == 0);

    // CFB mode
    cout << "\nCFB Mode: " << endl;
    char counter[16];
    memset(counter, 0, 16);
    counter[13] = -25;
    counter[5] = 117;  
    crypto.setCounter(counter);
    crypto.encryptString(in, in, strlen(in), AesCipher::CFB);

    buf = new char[Base64::calculateBase64Len(outLen)];
    Base64::binToBase64((unsigned char*)in, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)in, outLen);
    delete [] buf;

    len = crypto.decryptString(in, in, outLen, AesCipher::CFB);
    in[len] = '\0';
    cout << "Plaintext restored: " << in << endl;
    assert(strcmp(in, in2) == 0);

    // OFB mode
    cout << "\nOFB Mode: " << endl;
    crypto.encryptString(in, in, strlen(in), AesCipher::OFB);

    buf = new char[Base64::calculateBase64Len(outLen)];
    Base64::binToBase64((unsigned char*)in, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)in, outLen);
    delete [] buf;

    len = crypto.decryptString(in, in, outLen, AesCipher::OFB);
    in[len] = '\0';
    cout << "Plaintext restored: " << in << endl;
    assert(strcmp(in, in2) == 0);

    // CTR mode
    cout << "\nCTR Mode: " << endl;
    crypto.encryptString(in, in, strlen(in), AesCipher::CTR);

    buf = new char[Base64::calculateBase64Len(outLen)];
    Base64::binToBase64((unsigned char*)in, buf, outLen);
    cout << "Ciphertext with base64: " <<  buf << endl;
    Base64::base64ToBin(buf, (unsigned char*)in, outLen);
    delete [] buf;

    len = crypto.decryptString(in, in, outLen, AesCipher::CTR);
    in[len] = '\0';
    cout << "Plaintext restored: " << in << endl;
    assert(strcmp(in, in2) == 0);
}

/*
void test4()
{
	char title[100], url[100], username[100], password[100], category[100], notes[256];

	SecretNoteRec snr;

	cin >> title;
	cin >> url;
	cin >> username;
	cin >> password;
	cin >> category;
	cin >> notes;
	snr.setSecretNoteRec(title, url, username, password, category, notes);

	cout << snr;
}
*/
