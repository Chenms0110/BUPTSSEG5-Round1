import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int x1 = scanner.nextInt();
        int y1 = scanner.nextInt();
        int x2 = scanner.nextInt();
        int y2 = scanner.nextInt();
        double res = 0;
        //如果都在线上，那么就算欧式距离
        if(a*x1+b*y1+c==0 && a*x2+b*y2+c==0){
            res = Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
            System.out.println(res);
        }
        else{
            //如果不在一条线上

            //查找当前点的x、y与直线的交点

        }

    }
}
