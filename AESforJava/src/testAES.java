import com.enc.utils.*;

public class testAES {
	
	public static void main(String[] args) throws Exception {
		String content = "t̫��est��";
		String password = "12345678";
		// ����
		System.out.println("����ǰ��" + content);

		String tt4 = AES.encrypt2Str(content, password);
		System.out.println(new String(tt4));

		// ����
		String d = AES.decrypt2Str(tt4, password);
		System.out.println("���ܺ�" + d);
		
//		����ǰ��t̫��est��
//		Bpf0jyJDj/pVHaRf66+OMA==
//		���ܺ�t̫��est��
	}

}
