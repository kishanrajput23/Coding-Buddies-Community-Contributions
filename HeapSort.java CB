import java.util.Arrays;

public class Heap_sort{
    public static void main(String args[]){
        int[] a = {23,78,56,98,13};
        HeapSort(a);
        System.out.println("Heap_sort" + Arrays.toString(a));
    }
    static int heapSize;
    public static void buildMaxHeap(int[] a){
        heapSize = a.length-1;
        for(int i=a.length/2;i>=0;i--){
            maxHeapify(a,i);
        }
        System.out.println("buildMaxHeap" + Arrays.toString(a));
    }
    public static void HeapSort(int[] a){
        buildMaxHeap(a);
        for(int i=a.length-1;i>=1;i--){
            int temp=a[i];
            a[i]=a[0];
            a[0]=temp;
            heapSize=heapSize-1;
            maxHeapify(a,0);
        }
    }
    public static void maxHeapify(int[] a, int i){
        int l=2*i;
        int r=2*i+1;
        int largest;
        if(l<=heapSize && a[l]>a[i]){
            largest=l;
        }else{
            largest=i;
        }
        if(r<=heapSize && a[r]>a[largest]){
            largest=r;
        }
        if(largest!=i){
            int temp=a[i];
            a[i]=a[largest];
            a[largest]=temp;
            maxHeapify(a,largest);
        }
        System.out.println("maxHeapify" + Arrays.toString(a));
    }
}
