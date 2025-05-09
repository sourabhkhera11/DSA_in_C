import java.util.Scanner;

public class Q4matrixOperation {
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
        for(int i=0;i<ar.length;i++){
            for(int j=0;j<ar[i].length;j++){
                System.out.print(ar[i][j]+" ");
                
            }
            System.out.println();
        }
    }
    public static void transpose(int ar[][]){
        int r=ar[0].length;
        int c=ar.length;
        int trans[][]=new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                trans[i][j]=ar[j][i];
            }
        }
        System.out.println("-------After Transpose!--------");
        display(trans);
    }
    public static void rowAdd(int ar[][]){
        for(int i=0;i<ar.length;i++){
            int sum=0;
            for(int j=0;j<ar[0].length;j++){
                sum+=ar[i][j];
            }
            System.out.println("Sum of "+(i+1)+" row= "+sum);
        }
    }
    public static void colAdd(int ar[][]){
        for(int i=0;i<ar[0].length;i++){
            int sum=0;
            for(int j=0;j<ar.length;j++){
                sum+=ar[j][i];
            }
            System.out.println("Sum of "+(i+1)+" column= "+sum);
        }
    }
    public static void sumOffDia(int ar[][]){
        int r=ar.length;
        int c=ar[0].length;
        if(r==c){
            int sum=0;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i!=j){
                        sum+=ar[i][j];
                    }
                }
            }
        System.out.println("Sum of off diagonal elemets= "+sum);
        }
        else{
            System.out.println("Not a sqaure matrix!");
        }
    }
    public static void disUT(int ar[][]){
        int r=ar.length;
        int c=ar[0].length;
        if(r==c){
            System.out.println("--------Upper Triangular Matrix!--------");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i<=j){
                        System.out.print(ar[i][j]+" ");
                    }
                    else{
                        System.out.print(0+" ");
                    }
                }
                System.out.println();
            }
        }
        else{
            System.out.println("Not a sqaure matrix!");
        }
    }
    public static void disLT(int ar[][]){
        int r=ar.length;
        int c=ar[0].length;
        if(r==c){
            System.out.println("--------Lower Triangular Matrix!--------");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i>=j){
                        System.out.print(ar[i][j]+" ");
                    }
                    else{
                        System.out.print(0+" ");
                    }
                }
                System.out.println();
            }
        }
        else{
            System.out.println("Not a sqaure matrix!");
        }
    }
    public static void disDia(int ar[][]){
        int r=ar.length;
        int c=ar[0].length;
        if(r==c){
            System.out.println("--------Diagonal Matrix!--------");
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==j){
                        System.out.print(ar[i][j]+" ");
                    }
                    else{
                        System.out.print(0+" ");
                    }
                }
                System.out.println();
            }
        }
        else{
            System.out.println("Not a sqaure matrix!");
        }
    }
       public static void main(String arg[]){
        System.out.print("Enter the no of rows=");
        int r=sc.nextInt();
        System.out.print("Enter no of columns=");
        int c=sc.nextInt();
        int ar[][]=new int[r][c];
        read(ar, r, c);
        System.out.println("-------Matrix!-------");
        display(ar);
        disUT(ar);
        disLT(ar);
        disDia(ar);
    }
}
