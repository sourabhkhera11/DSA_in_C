import java.util.Scanner;

public class Q3matrixArithmetic{
    static Scanner sc=new Scanner(System.in);
    public static void read(int ar[][],int r,int c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                System.out.print("Enter element at row "+i+" column "+j+" = ");
                ar[i][j]=sc.nextInt();
                System.out.println();
            }
        }
    }
    public static void display(int ar[][]){
        System.out.println();
        for(int i=0;i<ar.length;i++){
            for(int j=0;j<ar[i].length;j++){
                System.out.print(ar[i][j]+" ");
                
            }
            System.out.println();
        }
    }
    public static void add(int ar1[][],int ar2[][]){
        if(ar1.length == ar2.length){
            if(ar1[0].length==ar2[0].length){
                int sum[][]=new int[ar1.length][ar1[0].length];
                for(int i=0;i<ar1.length;i++){
                    for(int j=0;j<ar1[i].length;j++){
                        sum[i][j]=ar1[i][j]+ar2[i][j];
                    }
                }
                System.out.print("Sum");
                display(sum);
            }else{
                System.out.println("Sum is not possible !");
            }
        }
        else{

            System.out.println("Sum is not possible !");
        }
    }
    public static void sub(int ar1[][],int ar2[][]){
        if(ar1.length == ar2.length){
            if(ar1[0].length==ar2[0].length){
                int sum[][]=new int[ar1.length][ar1[0].length];
                for(int i=0;i<ar1.length;i++){
                    for(int j=0;j<ar1[i].length;j++){
                        sum[i][j]=Math.abs(ar1[i][j]-ar2[i][j]);
                    }
                }
                System.out.print("Subtraction=");
                display(sum);
            }else{
                System.out.println("Subtraction is not possible !");
            }
        }
        else{

            System.out.println("Subtraction is not possible !");
        }
    }
    public static void multi(int ar1[][],int ar2[][]){
        //ar1 m*n and ar2 n*p then only they can be multiply
        //new matrix will be m*p 
        if(ar1[0].length == ar2.length){
            int r=ar1.length;
            int c=ar2[0].length;
            int mul[][]=new int[r][c];
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    for(int k=0;k<c;k++){
                        mul[i][j]+=ar1[i][k]*ar2[k][j];
                    }
                }
            }
            System.out.println("After multiplication=");
            display(mul);
        }
        else{
            System.out.println("Matrix can not be multiplied!");
        }
    }
        public static void main(String arg[]){
        System.out.println("For matrix 1!");
        System.out.print("Enter the no of rows=");
        int r1=sc.nextInt();
        System.out.print("Enter no of columns=");
        int c1=sc.nextInt();
        int matrix1[][]=new int[r1][c1];
        read(matrix1, r1, c1);
        System.out.println("For matrix 2!");
        System.out.print("Enter the no of rows=");
        int r2=sc.nextInt();
        System.out.print("Enter no of columns=");
        int c2=sc.nextInt();
        int matrix2[][]=new int[r2][c2];
        read(matrix2, r2, c2);
        System.out.println("MAtrix 1=");
        display(matrix1);
        System.out.println("MAtrix 2=");
        display(matrix2);
        multi(matrix1, matrix2);
    }
}

