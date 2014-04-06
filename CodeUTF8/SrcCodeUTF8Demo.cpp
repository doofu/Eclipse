//============================================================================
// Name        : MyCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : 本程序文本使用UTF-8字符集
// MinGW缺省使用UTF-8选项，因此不用设置
//============================================================================

#include <iostream>
#include <stdio.h>
#include "tchar.h"		// 使用TCHAR、_T必须使用tchar.h
#include "wchar.h"
#include "windows.h"	//WideCharToMultiByte、CP_ACP需要windows.h

using namespace std;

int main()
{
	void printTChar(int, const TCHAR *);
	void printWChar_t(int, const wchar_t *);
	void printChar(int, const char *);
	char * WCharToChar1(const wchar_t * pwszBuffer, int * pnLen = NULL);
//	char * WCharToChar1(wchar_t * pwszBuffer, const int &nLen = 0);		//函数调用，引用参数设为缺省值，可否？
																		//只有为const int &nLen = 0,
	char * WCharToChar2(const wchar_t * pwszBuffer, int * pnLen = NULL);
	wchar_t * CharToWChar1(const char * pszBuffer, int * pnLen = NULL);
	wchar_t * CharToWChar2(const char * pszBuffer, int * pnLen = NULL);

//	setlocale(LC_ALL,"C");		//当程序启动时，setlocale( LC_ALL, "C" )默认初始化

//	setlocale(LC_ALL,"chs");	//printf 只能提供ANSI/MB 的输出，不支持输出unicode字符串输出。
								//wprintf同样不会提供unicode输出,但是他会把wchar_t的字符串转为locale的SB/MB字符编码，然后输出
								//因为wprintf没有办法把L"字符数组abcde012"转为默认的ANSI,需要设置locale
								//综上所述：CRT I/O functions do not provide Unicode output.
//	setlocale(LC_ALL,".936");
cout << "本程序文本使用UTF-8字符集" << endl;
cout << "设置前" << endl;
	cout << setlocale(LC_ALL,"");	//返回：Chinese_People's Republic of China.936
cout << endl << "设置后" << endl;
//	wcout << _wsetlocale(LC_ALL, L"");
//	_tprintf(_T("%s"), _tsetlocale(LC_ALL, _T("")));

	cout << endl;

	TCHAR	tszBuffer[50] = _T("字符数组abcde012");
	TCHAR	tszBuffer1[50] = _TEXT("字符数组abcde012");
	char	szBuffer[50] = "字符数组abcde012";
	wchar_t	wszBuffer[50] = L"字符数组abcde012";			// wchar_t在string.h中定义。
//	char * pszBuffer;
	LPSTR pszBuffer;
	int nLen;

#ifdef UNICODE
	cout << "01 使用Unicode字符集" << endl << endl;
#else
	cout << "02使用多字节字符集" << endl << endl;
#endif

	_tprintf(_T("03 字符串=%s, 每个(TCHAR)占用%d个字节, sizeof(tszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n"), tszBuffer, sizeof(TCHAR), sizeof(tszBuffer), _tcslen(tszBuffer), (_tcslen(tszBuffer)+1)*sizeof(TCHAR));
	_tprintf(_T("04 字符串=%s, 每个(TCHAR)占用%d个字节, sizeof(tszBuffer1)=%d, 字符串长度=%d, 占用内存=%d个字节\n"), tszBuffer1, sizeof(TCHAR), sizeof(tszBuffer1), _tcslen(tszBuffer1), (_tcslen(tszBuffer1)+1)*sizeof(TCHAR));
	printf("05 字符串=%s, 每个(char)占用%d个字节, sizeof(szBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n", szBuffer, sizeof(char), sizeof(szBuffer), strlen(szBuffer), (strlen(szBuffer)+1)*sizeof(char));
	wprintf(L"06 字符串=%ls, 每个(wchar_t)占用%d个字节, sizeof(wszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n", wszBuffer, sizeof(wchar_t), sizeof(wszBuffer), wcslen(wszBuffer), (wcslen(wszBuffer)+1)*sizeof(wchar_t));	//window环境下%ws,%s也可

	cout << endl;
	printTChar(sizeof(tszBuffer), tszBuffer);
	printTChar(sizeof(tszBuffer1), tszBuffer1);
	printChar(sizeof(szBuffer), szBuffer);
	printWChar_t(sizeof(wszBuffer), wszBuffer);

	cout << endl;
	_tprintf(_T("07 字符串=%s, 每个(TCHAR)占用%d个字节, sizeof(tszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n"), tszBuffer, sizeof(TCHAR), sizeof(tszBuffer), _tcslen(tszBuffer), _tcslen(tszBuffer)*sizeof(TCHAR));
	_tprintf(_T("08 字符串=%s, 每个(TCHAR)占用%d个字节, sizeof(tszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n"), tszBuffer1, sizeof(TCHAR), sizeof(tszBuffer1), _tcslen(tszBuffer1), _tcslen(tszBuffer1)*sizeof(TCHAR));
	printf("09 字符串=%s, 每个(char)占用%d个字节, sizeof(tszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n", szBuffer, sizeof(char), sizeof(szBuffer), strlen(szBuffer), strlen(szBuffer)*sizeof(char));
	wprintf(L"10 字符串=%ws, 每个(wchar_t)占用%d个字节, sizeof(tszBuffer)=%d, 字符串长度=%d, 占用内存=%d个字节\n", wszBuffer, sizeof(wchar_t), sizeof(wszBuffer), wcslen(wszBuffer), wcslen(wszBuffer)*sizeof(wchar_t));

	cout << endl;
//	wchar_t *pwszBuffer = L"指针定义的宽字串abcde012";
	LPWSTR pwszBuffer = L"指针定义的宽字串abcde012";
	wcout << "11 " << pwszBuffer << endl;
	wprintf(L"12 %ws\n", pwszBuffer);
	printf("13 %ws\n", pwszBuffer);
	pszBuffer = WCharToChar1(pwszBuffer);
	cout << "14 " << pszBuffer << endl;
	printf("15 %s\n", pszBuffer);
	delete pszBuffer;				//在WcharToChar1()中，动态申请了空间，因此每次调用后必须用delete释放空间

//	宽字符串转化为多字节字符串的不同方法：
	cout << endl << "Unicode宽字符串转化为多字节字符串的不同方法演示：" << endl;
	printWChar_t(sizeof(L"Unicode宽字符串转化为多字节字符串"), L"Unicode宽字符串转化为多字节字符串");

	cout << "方法一：" << endl;
	pszBuffer = WCharToChar1(L"Unicode宽字符串转化为多字节字符串", &nLen);
	//	pszBuffer = WCharToChar1(L"Unicode宽字符串转化为多字节字符串", nLen);
	printChar(nLen, pszBuffer);
	delete pszBuffer;

	cout << "方法二：" << endl;
	pszBuffer = WCharToChar2(L"Unicode宽字符串转化为多字节字符串", &nLen);
	printChar(nLen, pszBuffer);
	delete pszBuffer;

//	多字节字符串转化为宽字符串的不同方法：
	cout << endl << "16 多字节字符串转化为Unicode宽字符串的不同方法演示：" << endl;
	printChar(sizeof("17 多字节字符串转化为Unicode宽字符串"), "多字节字符串转化为Unicode宽字符串");

	cout << "方法一：" << endl;
	pwszBuffer = CharToWChar1("多字节字符串转化为Unicode宽字符串", &nLen);
	printWChar_t(nLen, pwszBuffer);
	delete pwszBuffer;

	cout << "方法二：" << endl;
	pwszBuffer = CharToWChar2("多字节字符串转化为Unicode宽字符串", &nLen);
	printWChar_t(nLen, pwszBuffer);
	delete pwszBuffer;

	return 0;
}

//	输出TCHAR类型字符串
void printTChar(int nBufferSize, const TCHAR * ptszBuffer)
{
//	几种输出宽字符方式，任选其中之一。建议使用_tprintf


#ifdef UNICODE
	wcout << _T("A01 TCHAR(wcout)：Buffer大小 = ") << nBufferSize << _T("个字节；字符串长度 = ") << lstrlen(ptszBuffer) << _T("个字符；字串 = “") << ptszBuffer << _T("”") << endl;
	wprintf(_T("A02 TCHAR(wprintf)：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = “%s”\n"), nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
	printf("A03 TCHAR(printf %ws)：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = “%ws”\n", nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
#else
	printf("A04 TCHAR(printf)：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = %s\n", nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
#endif

	_tprintf(_T("A05 TCHAR(_tprintf)：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = %s\n"), nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
}

//	输出char类型字符串
void printChar(int nBufferSize, const char * pszBuffer)
{
	cout << "B01 char：Buffer大小 = " << nBufferSize << "个字节；字符串长度 = " << strlen(pszBuffer) << "个字符；字串 = “"<< pszBuffer << "”" << endl;
}

//	输出wchar_t类型字符串
void printWChar_t(int nBufferSize, const wchar_t * pwszBuffer)
{
	//三种输出宽字符方式，任选其中之一
//	wcout << L"C01 wchar_t：Buffer大小 = " << nBufferSize << L"个字节；字符串长度 = " << wcslen(pwszBuffer) << L"个字符；字串 = “"<< pwszBuffer << L"”" << endl;
//	wprintf(L"C02 wchar_t：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = “%s”\n", nBufferSize, wcslen(pwszBuffer), pwszBuffer);
	printf("C03 wchar_t：Buffer大小 = %d个字节；字符串长度 = %d个字符；字串 = %ws\n", nBufferSize, wcslen(pwszBuffer), pwszBuffer);
}

//	宽字符串转化为多字节字符串的方法一
char * WCharToChar1(const wchar_t * pwszBuffer, int * pnLen)
//char * WCharToChar1(wchar_t * pwszBuffer, const int & nnLen)	//宽字符串转化为多字节字符串的方法一
{
	int nLen = wcslen(pwszBuffer) * 2 + 1; //或者通过下面一行的代码获取所需长度
	// int nLen = WideCharToMultiByte(CP_ACP, 0, pwszBuffer, -1, NULL, 0, NULL, NULL);	//pwszBuffer必须已申请空间
	char * pszBuffer = new char[nLen];
	int nstrLen = WideCharToMultiByte(CP_ACP, 0, pwszBuffer, -1, pszBuffer, nLen, NULL, NULL); // 长度中包含'\0'字符
cout << "D01 WideCharToMultiByte返回字串长度为：" << nstrLen << "，长度中包含\'\\0\'字符。" << endl;
	if (pnLen != NULL)
		*pnLen = sizeof(char) * nLen;
	return pszBuffer;
}

//	宽字符串转化为多字节字符串的方法二
char * WCharToChar2(const wchar_t * pwszBuffer, int * pnLen)
{
	int nLen = wcslen(pwszBuffer) * 2 + 1;			// 或者通过下面一行的代码获取所需长度
	//int nLen = wcstombs(NULL, pwszBuf, 0) + 1;
	char * pszBuffer = new char[nLen];
	int nstrLen = wcstombs(pszBuffer, pwszBuffer, nLen);
cout << "E01 wcstombs返回字串长度为：" << nstrLen << "，注意：长度中不包含\'\\0\'字符，因此此函数不安全，编译有告警。" << endl;
	if (pnLen != NULL)
		*pnLen = sizeof(char) * nLen;
	return pszBuffer;
}

//	多字节字符串转化为宽字符串的方法一
wchar_t * CharToWChar1(const char * pszBuffer, int * pnLen)
{
	int nLen = strlen(pszBuffer) + 1; // 或者通过下面一行的代码获取所需长度
	// int nLen = MultiByteToWideChar(CP_ACP, 0, pszBuffer, -1, NULL, 0);
	wchar_t *pwszBuffer = new wchar_t[nLen];
	int nwstrLen = MultiByteToWideChar(CP_ACP, 0, pszBuffer, -1, pwszBuffer, nLen);
cout << "F01 MultiByteToWideChar返回字串长度为：" << nwstrLen << "，长度中包含\'\\0\'字符。" << endl;

	if (pnLen != NULL)
		*pnLen = sizeof(wchar_t) * nLen;
	return pwszBuffer;
}

//	多字节字符串转化为宽字符串的方法二
wchar_t * CharToWChar2(const char * pszBuffer, int * pnLen)
{
	int nLen = strlen(pszBuffer) + 1; // 或者通过下面一行的代码获取所需长度
	// int nLen = mbstowcs(NULL, pszBuffer, 0) + 1;
	wchar_t *pwszBuffer = new wchar_t[nLen];
	int nwstrLen = mbstowcs(pwszBuffer, pszBuffer, nLen);
cout << "G01 mbstowcs返回字串长度为：" << nwstrLen << "，注意：长度中不包含\'\\0\'字符，因此此函数不安全，编译有告警。" << endl;

	if (pnLen != NULL)
		*pnLen = sizeof(wchar_t) * nLen;
	return pwszBuffer;
}
