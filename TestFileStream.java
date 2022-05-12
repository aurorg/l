import java.io.*;
public class TestFileStream {
    public static void main(String[] args) throws IOException{
        try(
                FileOutputStream output = new FileOutputStream("/home/shizhanli/luck.txt");
                ) {
            for (int i = 1; i <= 10; i++) {
                output.write(i);
            }
        }
        try(
                FileInputStream input = new FileInputStream("/home/shizhanli/luck.txt");
                ){
            int value ;
            while ((value = input.read()) !=-1)
                System.out.println(value + " ");
        }
    }
}

