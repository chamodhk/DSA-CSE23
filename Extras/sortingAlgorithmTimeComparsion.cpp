#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;


int timeInsertionSort(vector<int>);
int timeBubbleSort(vector<int>);
int timeBubbleSortOptimized(vector<int>);
int timeSelectionSort(vector<int>);
int randomNumber();
vector<vector<int>> generateRandomArrays(int);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()

{   
    srand(time(0));

    const int numberOfArrays = 50;
    vector<vector<int>> randomArrays = generateRandomArrays(numberOfArrays);
    cout << "Array Size,"  << "Insertion Sort," << "Bubble Sort,"  << "Bubble Sort Optimized," << "Selection Sort" << endl;


    for (int i = 0; i < numberOfArrays; i++)
    {
        vector<int> arr = randomArrays[i];
        int arrSize = arr.size();
        int insertTime = timeInsertionSort(arr);
        int bubbleTime = timeBubbleSort(arr);
        int bubbleOptimizedTime = timeBubbleSortOptimized(arr);
        int selectionTime = timeSelectionSort(arr);

        cout  << arrSize <<"," << insertTime << "," << bubbleTime << "," << bubbleOptimizedTime << "," << selectionTime << endl;
        
    }

}


int timeInsertionSort(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int timeBubbleSort(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}


int timeBubbleSortOptimized(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int timeSelectionSort(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}






int randomNumber(){
    return rand() % 10000;
}



vector<vector<int>> generateRandomArrays(int numberOfArrays)
{
    vector<vector<int>> randomArrays;

    for (int i = 0; i < numberOfArrays; i++)


    {   int inputCount = rand() % 1000 + 1;
        
        vector<int> arr;
        for (int j = 0; j < inputCount; j++)
        {
            arr.push_back(randomNumber());
        }
        randomArrays.push_back(arr);
    }
    return randomArrays;
}
