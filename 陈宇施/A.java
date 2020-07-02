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
                //临时数组用于验证结果
                arrTemp[j] = arr[j];
            }
            //排序
            Arrays.sort(arrTemp);
            //输入p序列
            for(int k=0;k<m;k++){
                parr[k] = scanner.nextInt();
            }
            //追加：根据p数组中的值，再判断一下原数组中的数值大小，如果前面的大，则两个数交换一下
            for(int r=0;r<parr.length;r++){
                if(arr[parr[r]-1]>arr[parr[r]]){
                    int temp = arr[parr[r]-1];
                    arr[parr[r]-1] = arr[parr[r]];
                    arr[parr[r]] = temp;
                }
            }
            //追加：将得到的结果与排好序的临时数组进行比较，确定结果
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
