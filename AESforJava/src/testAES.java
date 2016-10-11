import com.enc.utils.*;

public class testAES {
	
	public static void main(String[] args) throws Exception {
		String content = "t太阳est地";
		String password = "12345678";
		// 加密
		System.out.println("加密前：" + content);

		String tt4 = AES.encrypt2Str(content, password);
		System.out.println(new String(tt4));

		// 解密
		String d = AES.decrypt2Str(tt4, password);
		System.out.println("解密后：" + d);
		
//		加密前：t太阳est地
//		Bpf0jyJDj/pVHaRf66+OMA==
//		解密后：t太阳est地
	}

}
