int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;  

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
           
            std::swap(arr[i], arr[j]);
            ++i;  
        }
    }

    std::swap(arr[low], arr[i - 1]);

    return i - 1;  
}
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        
        int pivot = partition(arr, low, high);

        
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
