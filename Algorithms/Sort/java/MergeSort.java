/* MergeSort.java */
public class MergeSort {
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    private static void merge(int[] arr, int left, int mid, int right) {
        int size_cpy = right - left + 1;
        int idx_left = 0, idx_right, idx_origin = left;
        int len_left = (mid - left) + 1, len_right = (right - mid) + 1;
        int[] arrCpy = new int[size_cpy];

        System.arraycopy(arr, left, arrCpy, 0, size_cpy);

        idx_right = len_left;
        while (idx_left < len_left && idx_right < size_cpy)
            arr[idx_origin++] =
                (arrCpy[idx_left] <= arrCpy[idx_right] ?
                arrCpy[idx_left++] : arrCpy[idx_right++]);

        while (idx_left < len_left)
            arr[idx_origin++] = arrCpy[idx_left++];
        while (idx_right < size_cpy)
            arr[idx_origin++] = arrCpy[idx_right++];
    }
}
