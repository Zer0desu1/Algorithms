vector<int>insertion(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int num = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
    return arr;
}
