public class Test23_2 {
    public static void main(String[] args){
        int[] list = {6,8,10,5,3,11,99};
        mergeSort(list);
        for(int i =0;i<list.length;i++){
            System.out.print(list[i] + " ");
        }

    }
    public static void mergeSort(int[] list){
        if(list.length>1){
            int[] firstHalf = new int[list.length/2];
            System.arraycopy(list,0,firstHalf,0,list.length/2);
            mergeSort(firstHalf);

            int secondHalfLength = list.length -list.length/2;
            int[] secondHalf = new int[secondHalfLength];
            System.arraycopy(list,list.length/2,secondHalf,0,secondHalfLength);
            mergeSort(secondHalf);

            merge(firstHalf,secondHalf,list);//调用方法merge
        }
    }

    public static void merge(int[] list1,int[] list2,int[] temp){
        int current1=0;
        int current2=0;
        int current3=0;

        while(current1 < list1.length && current2 < list2.length){
            if(list1[current1] < list2[current2])//如果较小的元素在list1中，current1++；
                temp[current3++] = list1[current1++];
            else
                temp[current3++] =list2[current2++];//如果较小的元素在list2中，current2++；
        }

        while(current1 < list1.length)
            temp[current3++] = list1[current1++];

        while(current2 < list2.length)
            temp[current3++] = list2[current2++];
    }
}
