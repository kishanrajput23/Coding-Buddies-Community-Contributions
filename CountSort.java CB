import java.util.Arrays;

public class Count_sort {
    public static void main(String[] args) {
        int a[] = {2,1,2,3,1,2,4};
        int[] count = new int[5];

        for(int x : a){
            count[x]++;
        }
        System.out.println("initial count array " + Arrays.toString(count));

        for(int i=1;i<5;i++){
            count[i] +=count[i-1];
        }
        System.out.println("count array " + Arrays.toString(count));

        int[] b = new int[a.length];
        for(int i=b.length-1;i>=0;i--){
            b[count[a[i]]-1] = a[i];
            count[a[i]]--;
        }
        System.out.println("Sorted array " + Arrays.toString(b));
    }
}
