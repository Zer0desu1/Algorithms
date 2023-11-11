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
