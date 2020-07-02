import java.util.Arrays;
import java.util.Scanner;

public class A {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        int flag=0;
        for(int i=0;i<t;i++){
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[] arr = new int[n];
            int[] arrTemp = new int[n];
            int[] parr = new int[m];
            //输入数组
            for(int j=0;j<n;j++){
                arr[j] = scanner.nextInt();
                arrTemp[j] = arr[j];
            }
            Arrays.sort(arrTemp);
            //输入p序列
            for(int k=0;k<m;k++){
                parr[k] = scanner.nextInt();
            }
            for(int r=0;r<parr.length;r++){
                if(arr[parr[r]-1]>arr[parr[r]]){
                    int temp = arr[parr[r]-1];
                    arr[parr[r]-1] = arr[parr[r]];
                    arr[parr[r]] = temp;
                }
            }

            for(int j=0;j<n;j++){
                if(arr[j]==arrTemp[j]){
                    continue;
                }
                else{
                    System.out.println("NO");
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                System.out.println("YES");
            }
        }
    }
}
