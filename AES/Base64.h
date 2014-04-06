#ifndef __BASE64_H__
#define __BASE64_H__

#include <stddef.h>

/*
    Base64��һ�ֻ���64���ɴ�ӡ�ַ�����ʾ���������ݵı�ʾ������
    Base64Ҫ���ÿ����8Bit���ֽ�ת��Ϊ�ĸ�6Bit���ֽڣ�3*8 = 4*6 = 24����Ȼ���6Bit������λ��λ0������ĸ�8Bit���ֽڣ�
Ҳ����˵��ת������ַ��������Ͻ�Ҫ��ԭ���ĳ�1/3��

�����������Ĺ���
    ��  ��3���ַ����4���ַ�.
    ��  ÿ76���ַ���һ�����з�.
    ��  ���Ľ�����ҲҪ����.

Base64 ��ĸ��
����	��Ӧ�ַ�	����	��Ӧ�ַ�	����	��Ӧ�ַ�	����	��Ӧ�ַ� 
0		A			17		R			34		i			51		z 
1		B			18		S			35		j			52		0 
2		C			19		T			36		k			53		1 
3		D			20		U			37		l			54		2 
4		E			21		V			38		m			55		3 
5		F			22		W			39		n			56		4 
6		G			23		X			40		o			57		5 
7		H			24		Y			41		p			58		6 
8		I			25		Z			42		q			59		7 
9		J			26		a			43		r			60		8 
10		K			27		b			44		s			61		9 
11		L			28		c			45		t			62		+ 
12		M			29		d			46		u			63		/ 
13		N			30		e			47		v 
14		O			31		f			48		w 
15		P			32		g			49		x 
16		Q			33		h			50		y 

    ԭ�ĵ��ֽ�����Ӧ����3�ı�������������������������Ļ����Ǹ���ô���أ�
    ���ǵĽ���취�������ģ�ԭ�ĵ��ֽڲ����ĵط�������ȫ0�����㣬ת��ʱBase64������=�������档�����Ϊʲô��ЩBase64
�������һ���������ȺŽ�����ԭ�򣬵��Ⱥ����ֻ����������Ϊ��
    ���� = ԭ���ֽ��� MOD 3
    ���������κ�����¶�ֻ������0��1��2���������е�һ�������������0�Ļ����ͱ�ʾԭ���ֽ���������3�ı��������������
�������������1�Ļ���Ϊ����Base64������3�ı�������Ҫ��2���Ⱥţ�ͬ�������2�Ļ�����Ҫ��1���Ⱥš�
*/

/**
 * The Base64 class is a utility class for coding/decoding data with base64.
 * Its all members are static member.
 */

class Base64
{
public:
    /**
     * Get number of bytes of base64 string corresponding to 
     * binary string with length @param len.
     * @param len: Number of bytes of binary string.
     * @return: Number of bytes of base64 string.
     */
//	ԭ�ĳ���ת��ΪBase64�󣬳���Ϊ��(ԭ�ĳ��� / 3) * 4 + 1����һλ��Ϊ�˷��ַ���������'\0'
    static int calculateBase64Len(size_t len) {
        return (len / 3 + (len % 3 ? 1 : 0)) * 4 + 1; // one more byte for '\0'
    }

    /**
     * Binary bytes to base 64 string (NUL-terminated).
     * Every three bytes inputted needs four bytes to output. 
     * A byte more needs to hold NUL terminator.
     * @param in: Input buffer.
     * @param out: Output buffer.
     * @param inLength: Number of bytes in input buffer.
     */
    static void binToBase64(const unsigned char *in, char *out, size_t inLength);

    /**
     * Get number of bytes of binary string corresponding to 
     * base64 string with length @param len.
     * @param len: Number of bytes of base64 string.
     * @return: Number of bytes of binary string.
     */
//	����Base64תΪԭ�ģ�ԭ������ĳ��ȣ�
    static int calculateBinLen(size_t len) {
        return len / 4 * 3; 
    }

    /**
     * base64 string to binary bytes.
     * @param in: Input buffer.
     * @param out: Output buffer.
     * @param maxLen: Size of output buffer. Set to zero to ignore.
     * @return: Number of bytes actually converted.
     */
    static int base64ToBin(const char *in, unsigned char *out, size_t maxLen);

private:
    static char decode64(unsigned char ch) {
        return ch < 128 ? sm_base64val[ch] : BAD;
    }

private:
    enum {BAD = -1};
    static const char sm_base64digits[65];
    static const char sm_base64val[128];
};

#endif // __BASE64_H__
