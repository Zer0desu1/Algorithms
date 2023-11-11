int main() {
    vector<int> randArray = generateRandomNumbers(1000000);
    auto start_time = std::chrono::high_resolution_clock::now();
     //Quick(randArray, 0, randArray.size()-1);
     //randArray = selectionSort(randArray);
     //randArray=insertion(randArray);
     //heapSort(randArray,randArray.size());
    //Merge(randArray, 0, randArray.size() - 1);
    //quickSort(randArray, 0, randArray.size()-1);
    gnome(randArray);
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    for (int i = 0; i < randArray.size(); i++) {
        cout << randArray[i] << "-";
    }
    std::cout << "Time taken: " << duration.count() << " microseconds." << std::endl;
}
