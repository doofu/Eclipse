//============================================================================
// Name        : MyCPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : �������ı�ʹ��GB18030�ַ���
// ����ĿCodeGB18030�Ҽ�,properties->C/C++ Build->Settings->Tool Settings->Dialet->Other dialet flags,
//		����-finput-charset=GB18030 -fexec-charset=GB18030����ѡ����߱�������Դ�ļ�����ΪGB18030
//============================================================================

#include <iostream>
#include <stdio.h>
#include "tchar.h"		// ʹ��TCHAR��_T����ʹ��tchar.h
#include "wchar.h"
#include "windows.h"	//WideCharToMultiByte��CP_ACP��Ҫwindows.h

using namespace std;

int main()
{
	void printTChar(int, const TCHAR *);
	void printWChar_t(int, const wchar_t *);
	void printChar(int, const char *);
	char * WCharToChar1(const wchar_t * pwszBuffer, int * pnLen = NULL);
//	char * WCharToChar1(const wchar_t * pwszBuffer, const int &nLen = 0);		//�������ã����ò�����Ϊȱʡֵ���ɷ�
																		//ֻ��Ϊconst int &nLen = 0,
	char * WCharToChar2(const wchar_t * pwszBuffer, int * pnLen = NULL);
	wchar_t * CharToWChar1(const char * pszBuffer, int * pnLen = NULL);
	wchar_t * CharToWChar2(const char * pszBuffer, int * pnLen = NULL);

//	setlocale(LC_ALL,"C");		//����������ʱ��setlocale( LC_ALL, "C" )Ĭ�ϳ�ʼ��

//	setlocale(LC_ALL,"chs");	//printf ֻ���ṩANSI/MB ���������֧�����unicode�ַ��������
								//wprintfͬ�������ṩunicode���,���������wchar_t���ַ���תΪlocale��SB/MB�ַ����룬Ȼ�����
								//��Ϊwprintfû�а취��L"�ַ�����abcde012"תΪĬ�ϵ�ANSI,��Ҫ����locale
								//����������CRT I/O functions do not provide Unicode output.
//	setlocale(LC_ALL,".936");
cout << "�������ı�ʹ��GB18030�ַ���" << endl;
cout << "����ǰ" << endl;
	cout << setlocale(LC_ALL,"");	//���أ�Chinese_People's Republic of China.936
cout << endl << "���ú�" << endl;
//	wcout << _wsetlocale(LC_ALL, L"");
//	_tprintf(_T("%s"), _tsetlocale(LC_ALL, _T("")));

	cout << endl;

	TCHAR	tszBuffer[50] = _T("�ַ�����abcde012");
	TCHAR	tszBuffer1[50] = _TEXT("�ַ�����abcde012");
	char	szBuffer[50] = "�ַ�����abcde012";
	wchar_t	wszBuffer[50] = L"�ַ�����abcde012";			// wchar_t��string.h�ж��塣
//	char * pszBuffer;
	LPSTR pszBuffer;
	int nLen;

#ifdef UNICODE
	cout << "01 ʹ��Unicode�ַ���" << endl << endl;
#else
	cout << "02ʹ�ö��ֽ��ַ���" << endl << endl;
#endif

	_tprintf(_T("03 �ַ���=%s, ÿ��(TCHAR)ռ��%d���ֽ�, sizeof(tszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n"), tszBuffer, sizeof(TCHAR), sizeof(tszBuffer), _tcslen(tszBuffer), (_tcslen(tszBuffer)+1)*sizeof(TCHAR));
	_tprintf(_T("04 �ַ���=%s, ÿ��(TCHAR)ռ��%d���ֽ�, sizeof(tszBuffer1)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n"), tszBuffer1, sizeof(TCHAR), sizeof(tszBuffer1), _tcslen(tszBuffer1), (_tcslen(tszBuffer1)+1)*sizeof(TCHAR));
	printf("05 �ַ���=%s, ÿ��(char)ռ��%d���ֽ�, sizeof(szBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n", szBuffer, sizeof(char), sizeof(szBuffer), strlen(szBuffer), (strlen(szBuffer)+1)*sizeof(char));
	wprintf(L"06 �ַ���=%ls, ÿ��(wchar_t)ռ��%d���ֽ�, sizeof(wszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n", wszBuffer, sizeof(wchar_t), sizeof(wszBuffer), wcslen(wszBuffer), (wcslen(wszBuffer)+1)*sizeof(wchar_t));	//window������%ws,%sҲ��

	cout << endl;
	printTChar(sizeof(tszBuffer), tszBuffer);
	printTChar(sizeof(tszBuffer1), tszBuffer1);
	printChar(sizeof(szBuffer), szBuffer);
	printWChar_t(sizeof(wszBuffer), wszBuffer);

	cout << endl;
	_tprintf(_T("07 �ַ���=%s, ÿ��(TCHAR)ռ��%d���ֽ�, sizeof(tszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n"), tszBuffer, sizeof(TCHAR), sizeof(tszBuffer), _tcslen(tszBuffer), _tcslen(tszBuffer)*sizeof(TCHAR));
	_tprintf(_T("08 �ַ���=%s, ÿ��(TCHAR)ռ��%d���ֽ�, sizeof(tszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n"), tszBuffer1, sizeof(TCHAR), sizeof(tszBuffer1), _tcslen(tszBuffer1), _tcslen(tszBuffer1)*sizeof(TCHAR));
	printf("09 �ַ���=%s, ÿ��(char)ռ��%d���ֽ�, sizeof(tszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n", szBuffer, sizeof(char), sizeof(szBuffer), strlen(szBuffer), strlen(szBuffer)*sizeof(char));
	wprintf(L"10 �ַ���=%ws, ÿ��(wchar_t)ռ��%d���ֽ�, sizeof(tszBuffer)=%d, �ַ�������=%d, ռ���ڴ�=%d���ֽ�\n", wszBuffer, sizeof(wchar_t), sizeof(wszBuffer), wcslen(wszBuffer), wcslen(wszBuffer)*sizeof(wchar_t));

	cout << endl;
//	wchar_t *pwszBuffer = L"ָ�붨��Ŀ��ִ�abcde012";
	LPWSTR pwszBuffer = L"ָ�붨��Ŀ��ִ�abcde012";
	wcout << "11 " << pwszBuffer << endl;
	wprintf(L"12 %ws\n", pwszBuffer);
	printf("13 %ws\n", pwszBuffer);
	pszBuffer = WCharToChar1(pwszBuffer);
	cout << "14 " << pszBuffer << endl;
	printf("15 %s\n", pszBuffer);
	delete pszBuffer;				//��WcharToChar1()�У���̬�����˿ռ䣬���ÿ�ε��ú������delete�ͷſռ�

//	���ַ���ת��Ϊ���ֽ��ַ����Ĳ�ͬ������
	cout << endl << "Unicode���ַ���ת��Ϊ���ֽ��ַ����Ĳ�ͬ������ʾ��" << endl;
	printWChar_t(sizeof(L"Unicode���ַ���ת��Ϊ���ֽ��ַ���"), L"Unicode���ַ���ת��Ϊ���ֽ��ַ���");

	cout << "����һ��" << endl;
	pszBuffer = WCharToChar1(L"Unicode���ַ���ת��Ϊ���ֽ��ַ���", &nLen);
	//	pszBuffer = WCharToChar1(L"Unicode���ַ���ת��Ϊ���ֽ��ַ���", nLen);
	printChar(nLen, pszBuffer);
	delete pszBuffer;

	cout << "��������" << endl;
	pszBuffer = WCharToChar2(L"Unicode���ַ���ת��Ϊ���ֽ��ַ���", &nLen);
	printChar(nLen, pszBuffer);
	delete pszBuffer;

//	���ֽ��ַ���ת��Ϊ���ַ����Ĳ�ͬ������
	cout << endl << "16 ���ֽ��ַ���ת��ΪUnicode���ַ����Ĳ�ͬ������ʾ��" << endl;
	printChar(sizeof("17 ���ֽ��ַ���ת��ΪUnicode���ַ���"), "���ֽ��ַ���ת��ΪUnicode���ַ���");

	cout << "����һ��" << endl;
	pwszBuffer = CharToWChar1("���ֽ��ַ���ת��ΪUnicode���ַ���", &nLen);
	printWChar_t(nLen, pwszBuffer);
	delete pwszBuffer;

	cout << "��������" << endl;
	pwszBuffer = CharToWChar2("���ֽ��ַ���ת��ΪUnicode���ַ���", &nLen);
	printWChar_t(nLen, pwszBuffer);
	delete pwszBuffer;

	return 0;
}

//	���TCHAR�����ַ���
void printTChar(int nBufferSize, const TCHAR * ptszBuffer)
{
//	����������ַ���ʽ����ѡ����֮һ������ʹ��_tprintf


#ifdef UNICODE
	wcout << _T("A01 TCHAR(wcout)��Buffer��С = ") << nBufferSize << _T("���ֽڣ��ַ������� = ") << lstrlen(ptszBuffer) << _T("���ַ����ִ� = ��") << ptszBuffer << _T("��") << endl;
	wprintf(_T("A02 TCHAR(wprintf)��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = ��%s��\n"), nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
	printf("A03 TCHAR(printf %ws)��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = ��%ws��\n", nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
#else
	printf("A04 TCHAR(printf)��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = %s\n", nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
#endif

	_tprintf(_T("A05 TCHAR(_tprintf)��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = %s\n"), nBufferSize, lstrlen(ptszBuffer), ptszBuffer);
}

//	���char�����ַ���
void printChar(int nBufferSize, const char * pszBuffer)
{
	cout << "B01 char��Buffer��С = " << nBufferSize << "���ֽڣ��ַ������� = " << strlen(pszBuffer) << "���ַ����ִ� = ��"<< pszBuffer << "��" << endl;
}

//	���wchar_t�����ַ���
void printWChar_t(int nBufferSize, const wchar_t * pwszBuffer)
{
	//����������ַ���ʽ����ѡ����֮һ
//	wcout << L"C01 wchar_t��Buffer��С = " << nBufferSize << L"���ֽڣ��ַ������� = " << wcslen(pwszBuffer) << L"���ַ����ִ� = ��"<< pwszBuffer << L"��" << endl;
//	wprintf(L"C02 wchar_t��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = ��%s��\n", nBufferSize, wcslen(pwszBuffer), pwszBuffer);
	printf("C03 wchar_t��Buffer��С = %d���ֽڣ��ַ������� = %d���ַ����ִ� = %ws\n", nBufferSize, wcslen(pwszBuffer), pwszBuffer);
}

//	���ַ���ת��Ϊ���ֽ��ַ����ķ���һ
char * WCharToChar1(const wchar_t * pwszBuffer, int * pnLen)
//char * WCharToChar1(wchar_t * pwszBuffer, const int & nnLen)	//���ַ���ת��Ϊ���ֽ��ַ����ķ���һ
{
	int nLen = wcslen(pwszBuffer) * 2 + 1; //����ͨ������һ�еĴ����ȡ���賤��
	// int nLen = WideCharToMultiByte(CP_ACP, 0, pwszBuffer, -1, NULL, 0, NULL, NULL);	//pwszBuffer����������ռ�
	char * pszBuffer = new char[nLen];
	int nstrLen = WideCharToMultiByte(CP_ACP, 0, pwszBuffer, -1, pszBuffer, nLen, NULL, NULL); // �����а���'\0'�ַ�
cout << "D01 WideCharToMultiByte�����ִ�����Ϊ��" << nstrLen << "�������а���\'\\0\'�ַ���" << endl;
	if (pnLen != NULL)
		*pnLen = sizeof(char) * nLen;
	return pszBuffer;
}

//	���ַ���ת��Ϊ���ֽ��ַ����ķ�����
char * WCharToChar2(const wchar_t * pwszBuffer, int * pnLen)
{
	int nLen = wcslen(pwszBuffer) * 2 + 1;			// ����ͨ������һ�еĴ����ȡ���賤��
	//int nLen = wcstombs(NULL, pwszBuf, 0) + 1;
	char * pszBuffer = new char[nLen];
	int nstrLen = wcstombs(pszBuffer, pwszBuffer, nLen);
cout << "E01 wcstombs�����ִ�����Ϊ��" << nstrLen << "��ע�⣺�����в�����\'\\0\'�ַ�����˴˺�������ȫ�������и澯��" << endl;
	if (pnLen != NULL)
		*pnLen = sizeof(char) * nLen;
	return pszBuffer;
}

//	���ֽ��ַ���ת��Ϊ���ַ����ķ���һ
wchar_t * CharToWChar1(const char * pszBuffer, int * pnLen)
{
	int nLen = strlen(pszBuffer) + 1; // ����ͨ������һ�еĴ����ȡ���賤��
	// int nLen = MultiByteToWideChar(CP_ACP, 0, pszBuffer, -1, NULL, 0);
	wchar_t *pwszBuffer = new wchar_t[nLen];
	int nwstrLen = MultiByteToWideChar(CP_ACP, 0, pszBuffer, -1, pwszBuffer, nLen);
cout << "F01 MultiByteToWideChar�����ִ�����Ϊ��" << nwstrLen << "�������а���\'\\0\'�ַ���" << endl;

	if (pnLen != NULL)
		*pnLen = sizeof(wchar_t) * nLen;
	return pwszBuffer;
}

//	���ֽ��ַ���ת��Ϊ���ַ����ķ�����
wchar_t * CharToWChar2(const char * pszBuffer, int * pnLen)
{
	int nLen = strlen(pszBuffer) + 1; // ����ͨ������һ�еĴ����ȡ���賤��
	// int nLen = mbstowcs(NULL, pszBuffer, 0) + 1;
	wchar_t *pwszBuffer = new wchar_t[nLen];
	int nwstrLen = mbstowcs(pwszBuffer, pszBuffer, nLen);
cout << "G01 mbstowcs�����ִ�����Ϊ��" << nwstrLen << "��ע�⣺�����в�����\'\\0\'�ַ�����˴˺�������ȫ�������и澯��" << endl;

	if (pnLen != NULL)
		*pnLen = sizeof(wchar_t) * nLen;
	return pwszBuffer;
}
