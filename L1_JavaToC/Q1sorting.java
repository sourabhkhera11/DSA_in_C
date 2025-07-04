import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
//Q1-Q5
public class Q1sorting{
    static Scanner sc =new Scanner(System.in);
    public static void read(int ar[],int num){
        for(int i=0;i<num;i++){
            System.out.print("Enter the element at "+i+" index=");
            ar[i]=sc.nextInt();
        }
    }
    public static void swap(int ar[],int i1,int i2){
        int temp=ar[i1];
        ar[i1]=ar[i2];
        ar[i2]=temp;
    }
    public static void display(int ar[]){
        System.out.println();
        System.out.print("Array= ");
        for(int i=0;i<ar.length;i++){
            System.out.print(ar[i]+" ");
        }
    }
    public static void selectionSort(int ar[]){
        int len=ar.length;
        for(int i=0;i<len-1;i++){
            int min=i;
            for(int j=i+1;j<len;j++){
                if(ar[j]<ar[min]){
                    min=j;
                }
            }
            swap(ar, i, min);
        }
    }
    public static void bubbleSort(int ar[]){
        int len=ar.length;
        boolean flag=false;
        for(int i=0;i<len;i++){
            for(int j=0;j<len-1-i;j++){
                if(ar[j]>ar[j+1]){
                    swap(ar, j, j+1);
                    flag=true;
                }
            }
            if(flag=false){
                return;
            }
        }
    }
    public static void insertionSort(int ar[]){
        int len=ar.length;
        for(int i=1;i<len;i++){
            int j=i-1;
            int cur=ar[i];
            while( j>=0 && cur< ar[j]){
                ar[j+1]=ar[j];
                j--;
            }
            ar[j+1]=cur;
        }
    }
    public static void mergeSort(int ar[],int l,int h){
        if(l<h){
            int mid=l+(h-l)/2;
            mergeSort(ar, l, mid);
            mergeSort(ar, mid+1, h);
            merge(ar, l, mid, mid+1, h);
        }
    }
    public static void merge(int ar[],int l,int mid,int mid1,int h){
        int n1=mid-l+1;
        int n2=h-mid1+1;
        int ar1[]=new int[n1];
        int ar2[]=new int[n2];
        //Initialisation
        for(int i=0;i<n1;i++){
            ar1[i]=ar[l+i];
        }
        for(int i=0;i<n2;i++){
            ar2[i]=ar[mid1+i];
        }
        int i=0;
        int j=0;
        int k=l;
        while(i<n1 && j<n2){
            if(ar1[i]<ar2[j]){
                ar[k]=ar1[i];
                i++;
            }
            else{
                ar[k]=ar2[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            ar[k]=ar1[i];
            k++;
            i++;
        }
        while(j<n2){
            ar[k]=ar2[j];
            k++;
            j++;
        }
    }
    public static void quickSort(int ar[],int l,int h){
        if(l<h){
            int p=partition(ar,l,h);
            quickSort(ar, l, p-1);
            quickSort(ar,p+1,h);
        }
    }
    public static int partition(int ar[],int l,int h){
        int pivot=ar[l];
        int i=l;
        int j=h;
        while(i<j){
            while(ar[i]<=pivot && i<h){
                i++;
            }
            while(ar[j]>pivot && j>0){
                j--;
            }
            if(i<j){
                swap(ar, i, j);
            }
        }
        swap(ar, j, l);
        return j;
    }
    public static void shellSort(int ar[]){
        int n=ar.length;
        for(int gap=n/2;gap>0;gap=gap/2){
            for(int i=gap;i<n;i++){
                int j;
                int cur=ar[i];
                for(j=i;j>=gap && cur < ar[j-gap];j=j-gap){
                    ar[j]=ar[j-gap];
                }
                ar[j]=cur;
            }
        }
    }
    public static int getMax(int ar[]){
        int max=ar[0];
        for(int i=1;i<ar.length;i++){
            if(ar[i]>max){
                max=ar[i];
            }
        }
        return max;
    }
    public static void radixSort(int ar[]){
        int m=getMax(ar);
        for(int exp=1;(m/exp)>0;exp*=10){
            countingSort(ar,exp);
        }
    }
    public static void countingSort(int ar[],int exp){
        int len=ar.length;
        int output[]=new int[len];
        int count[]=new int[10];
        for(int i=0;i<len;i++){
            count[(ar[i]/exp)%10]++;
        }
        //Actual position 
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        //actual output
        for(int i=0;i<len;i++){
            int digit=((ar[i]/exp)%10);
            output[count[digit]-1]=ar[i];
            count[digit]--;
        }
        //Move it back to the actual array
        for(int i=0;i<len;i++){
            ar[i]=output[i];
        }
    }
    public static void frequency(int ar[]){
        Map<Integer,Integer> freq=new HashMap<>();
        for(int i=0;i<ar.length;i++){
            freq.put(ar[i], freq.getOrDefault(ar[i], 0)+1);
        }
        for(Map.Entry<Integer,Integer> e: freq.entrySet()){
            System.out.println("Freq of "+e.getKey()+" = "+e.getValue());
        }
         
    }
    public static void main(String args[]){
        System.out.print("Enter the number of elements in the array=");
        // int num=sc.nextInt();
        int ar[]={91,2,43,27,18,18,27,91,91,91};
        //read(ar, num);
        /* display(ar);
        radixSort(ar);
        display(ar); */
        frequency(ar);
    }
}