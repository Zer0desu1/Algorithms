 void Merge(vector<int>& arr, int l, int h) {
     if (l < h) {
         int mid = (l + h) / 2;
         Merge(arr, l, mid);
         Merge(arr, mid + 1, h);

         vector<int> v1;
         vector<int> v2;

         for (int i = l; i <= mid; i++) {
             v1.push_back(arr[i]);
         }

         for (int i = mid + 1; i <= h; i++) {
             v2.push_back(arr[i]);
         }

         int i = 0, j = 0, k = l;
         while (i < v1.size() && j < v2.size()) {
             if (v1[i] < v2[j]) {
                 arr[k] = v1[i];
                 i++;
             }
             else {
                 arr[k] = v2[j];
                 j++;
             }
             k++;
         }

         while (i < v1.size()) {
             arr[k] = v1[i];
             i++;
             k++;
         }

         while (j < v2.size()) {
             arr[k] = v2[j];
             j++;
             k++;
         }
     }
 }
