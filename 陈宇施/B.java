import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        //使用贪心法，让木板的右端尽量靠近最远能跳到的格子
        //两个木板间的距离尽量是最远距离
        int flag = 0;
        Scanner scanner = new Scanner(System.in);
        //河流宽度
        int n = scanner.nextInt();
        //木板数量
        int m = scanner.nextInt();
        //最远距离
        int d = scanner.nextInt();
        int[] c = new int[m];
        int[] river = new int[n+2];
        //各木板宽度
        for(int i=0;i<m;i++){
            c[i]=scanner.nextInt();
        }
        int location=0;
        for(int i=0;i<m;i++){
            location = location+d+c[i]-1;
            if(n+1-location>=d){
                //river[location]=i+1;
                for(int k=0;k<c[i];k++){
                    river[location-k]=i+1;
                }
            }
        }
        if(n+1-location<=d){
            System.out.println("YES");
            //flag=1;
            for(int i=1;i<river.length-2;i++){
                System.out.println(river[i]+" ");
            }
            System.out.println(river[river.length-2]);
        }
        else{
            System.out.println("NO");
        }
    }
}
