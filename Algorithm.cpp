
#include <iostream>
#include<vector>
#include <random>
#include <chrono>



using namespace  std;
void Quick(vector<int>& arr, int l, int h) {
    if (l < h) {
        int pivot = arr[l];
        int i = l+1;
        int j = h - 1;

        while (i <= j) {
            while (arr[i] < pivot && i <= j) {
                i++;
            }
            while (arr[j] > pivot && i <= j) {
                j--;
            }
            if (i < j) {
                swap(arr[i], arr[j]);
                
            }
        }

        swap(arr[j], arr[l]);

        Quick(arr, l, j - 1);
        Quick(arr, j + 1, h);
    }
    
}
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





vector<int> generateRandomNumbers(int count) {
    vector<int> random;
    srand(58);
    for (int i = 0; i < count; ++i) {
        int randomNumber = std::rand() % 1000 ;
        random.push_back(randomNumber);
    }

    return random;
}
vector<int> selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr;
}
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
 void gnome(vector<int>& arr) {
     int index = 1;

     while (index < arr.size()) {
         
         if (arr[index] >= arr[index - 1])
             index++;
         else {
             swap(arr[index], arr[index - 1]);
             if (index > 1) {
                 index--;
             }
             else {
                 index++;  
             }
         }
     }
     
 }

 void oddEvenSort(vector<int>& arr, int n)
 {
     bool isSorted = false; 

     while (!isSorted)
     {
         isSorted = true;

         
         for (int i = 1; i <= n - 2; i = i + 2)
         {
             if (arr[i] > arr[i + 1])
             {
                 swap(arr[i], arr[i + 1]);
                 isSorted = false;
             }
         }

         
         for (int i = 0; i <= n - 2; i = i + 2)
         {
             if (arr[i] > arr[i + 1])
             {
                 swap(arr[i], arr[i + 1]);
                 isSorted = false;
             }
         }
     }

     return;
 }
 int main() {
     vector<int> randArray = generateRandomNumbers(1000);
     auto start_time = std::chrono::high_resolution_clock::now();
      //Quick(randArray, 0, randArray.size()-1);
      //randArray = selectionSort(randArray);
      //randArray=insertion(randArray);
      //heapSort(randArray,randArray.size());
     //Merge(randArray, 0, randArray.size() - 1);
     //quickSort(randArray, 0, randArray.size()-1);
     //gnome(randArray);
     auto end_time = std::chrono::high_resolution_clock::now();
     auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
     for (int i = 0; i < randArray.size(); i++) {
         cout << randArray[i] << "-";
     }
     std::cout << "Time taken: " << duration.count() << " microseconds." << std::endl;
 }

