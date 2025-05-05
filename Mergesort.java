import java.io.*;
import java.util.*;
class Mergesort{
    public static void main(String args[]){
        System.out.println("how many no do you want to sort ? ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        int[] merged = sort(arr,0, arr.length-1);
        for(int i = 0; i< merged.length; i++){
            System.out.print(merged[i] + "  ");
        }
    }
    public static int[] sort(int arr[], int low, int high){
        if(low == high){
            int[] n = new int[1];
            n[0] = arr[low];
            return n;
        }
        int mid = (low + high)/2;
        int[] left = sort(arr, low, mid);
        int[] right = sort(arr, mid+1, high);
        return merge(left, right);
    }
    public static int[] merge(int arr1[], int arr2[]){
        int[] m = new int[arr1.length + arr2.length];
        int i =0, j = 0, k = 0;
        while(i<arr1.length && j<arr2.length){
            if(arr1[i]<arr2[j]){
                m[k] = arr1[i];
                k++;
                i++;
            }
            else{
                m[k] = arr2[j];
                j++;
                k++;
            }
        }
        while(i<arr1.length){
            m[k] = arr1[i];
            i++;
            k++;
        }
        while(j<arr2.length){
            m[k] = arr2[j];
            j++;
            k++;
        }
        return m;
    }

}