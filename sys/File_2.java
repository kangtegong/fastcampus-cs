import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileDescriptor;
import java.io.IOException;

public class File_2 {
    public static void main(String[] args) {
        try {
            String filePath = "example.txt";

            // 파일 디스크립터로 파일 열기
            FileInputStream fis = new FileInputStream(filePath);
            FileDescriptor fd = fis.getFD();

            // 파일 디스크립터 값 출력
            System.out.println("파일 디스크립터 값: " + fd.toString());

            // 파일 디스크립터를 이용한 파일 읽기
            byte[] buffer = new byte[1024];
            int bytesRead = fis.read(buffer);
            System.out.println("파일 내용: " + new String(buffer, 0, bytesRead));

            // 파일 닫기
            fis.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

