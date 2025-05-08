import java.util.Scanner;

public class Q2sparseMatrix {
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
        System.out.println("Array=");
        for(int i=0;i<ar.length;i++){
            for(int j=0;j<ar[i].length;j++){
                System.out.print(ar[i][j]+" ");
                
            }
            System.out.println();
        }
    }
    public static boolean checkSparse(int ar[][],int r,int c){
        int half=(c*r)/2;
        int zero=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ar[i][j]==0){
                    zero++;
                }
            }
        }
        if(zero>half){
            represent(ar, r, c,zero);
            return true;
        }
        return false;
        }
    public static int[][] represent(int ar[][],int r,int c,int zero){
        int sparse[][]=new int[r*c-zero][3];
        int row=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(ar[i][j]!=0){
                    sparse[row][0]=i;
                    sparse[row][1]=j;
                    sparse[row][2]=ar[i][j];
                    row++;
                }
            }
        }
        display(sparse);
        return sparse;
    }
    public static void main(String arg[]){
        System.out.print("Enter the no of rows=");
        int r=sc.nextInt();
        System.out.print("Enter no of columns=");
        int c=sc.nextInt();
        int ar[][]=new int[r][c];
        read(ar, r, c);
        display(ar);
        checkSparse(ar, r, c);
    }
}
