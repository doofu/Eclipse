#ifndef __BASE64_H__
#define __BASE64_H__

#include <stddef.h>

/*
    Base64是一种基于64个可打印字符来表示二进制数据的表示方法。
    Base64要求把每三个8Bit的字节转换为四个6Bit的字节（3*8 = 4*6 = 24），然后把6Bit再添两位高位0，组成四个8Bit的字节，
也就是说，转换后的字符串理论上将要比原来的长1/3。

关于这个编码的规则：
    ①  把3个字符变成4个字符.
    ②  每76个字符加一个换行符.
    ③  最后的结束符也要处理.

Base64 字母表
索引	对应字符	索引	对应字符	索引	对应字符	索引	对应字符 
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

    原文的字节数量应该是3的倍数啊，如果这个条件不能满足的话，那该怎么办呢？
    我们的解决办法是这样的：原文的字节不够的地方可以用全0来补足，转换时Base64编码用=号来代替。这就是为什么有些Base64
编码会以一个或两个等号结束的原因，但等号最多只有两个。因为：
    余数 = 原文字节数 MOD 3
    所以余数任何情况下都只可能是0，1，2这三个数中的一个。如果余数是0的话，就表示原文字节数正好是3的倍数（最理想的情
况啦）。如果是1的话，为了让Base64编码是3的倍数，就要补2个等号；同理，如果是2的话，就要补1个等号。
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
//	原文长度转变为Base64后，长度为：(原文长度 / 3) * 4 + 1。多一位是为了放字符串结束符'\0'
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
//	计算Base64转为原文，原文所需的长度；
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
