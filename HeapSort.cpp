void heap(vector<int>& arr, int h, int root) {
    int largest = root;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < h && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < h && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != root) {
        swap(arr[root], arr[largest]);
        heap(arr, h, largest);
    }
}

 void heapSort(vector<int> &arr, int N)
 {

     for (int i = N / 2 - 1; i >= 0; i--)
         heap(arr, N, i);

     for (int i = N - 1; i >= 0; i--) {

         swap(arr[0], arr[i]);

         
         heap(arr, i, 0);
     }
 }
