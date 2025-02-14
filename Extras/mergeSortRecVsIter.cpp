#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int timeIterativeMergeSort(vector<int>);
int timeRecMergeSort(vector<int>);
int randomNumber();
vector<vector<int>> generateRandomArrays(int);


void IterativeMerge(vector<int>& arr, int L1, int R1, int L2, int R2)
{
    vector<int> temp(R2 - L1 + 1);
    int index = 0, i = L1, j = L2;

    while (i <= R1 && j <= R2)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }

    while (i <= R1)
    {
        temp[index++] = arr[i++];
    }

    while (j <= R2)
    {
        temp[index++] = arr[j++];
    }

    for (int k = 0; k < (int)temp.size(); k++)
    {
        arr[L1 + k] = temp[k]; // Copy back to original array
    }
}


void IterativeMergeSort(vector<int>& arr, int n)
{
    int len = 1;
    while (len < n)
    {
        int i = 0;
        while (i < n)
        {
            int L1 = i;
            int R1 = i + len - 1;
            int L2 = i + len;
            int R2 = i + 2 * len - 1;

            if (L2 >= n)
                break;

            if (R2 >= n)
                R2 = n - 1;

            IterativeMerge(arr, L1, R1, L2, R2);
            i += 2 * len;
        }

        len *= 2;
    }
}


void RecMerge(vector<int>& arr, int left, int mid, int right)  
{   
    //copy elemnts to leftArray and rightArray
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1); 
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left; // overwrite the values of the original array from left posisition.
    
    int leftArrSize = leftArr.size();
    int rightArrSize = rightArr.size();
    
    //merge
    while (i < leftArrSize && j < rightArrSize) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    
    //overwrite the array using the leftovers in leftArr
    while (i < leftArrSize) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }


    //overwrite the array using the leftovers in rightArr

    while (j < rightArrSize) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void RecMergeSort(vector<int>& arr, int left, int right)
{
    //check if left and right values are valiid
    if (left < right)  
    {
        int mid = left + (right - left) / 2;
        
        RecMergeSort(arr, left, mid);
        RecMergeSort(arr, mid + 1, right);
        RecMerge(arr, left, mid, right);  
    }
}

int main()

{   
    srand(time(0));

    const int numberOfArrays = 50;
    vector<vector<int>> randomArrays = generateRandomArrays(numberOfArrays);
    cout << "Array Size,"  << "Recursive," << "Iterative," << endl;


    for (int i = 0; i < numberOfArrays; i++)
    {
        vector<int> arr = randomArrays[i];
        int arrSize = arr.size();
        int RecTime = timeRecMergeSort(arr);
        int IterTime = timeIterativeMergeSort(arr);

        cout  << arrSize <<"," << RecTime << "," << IterTime << endl;
        
    }

}


int timeRecMergeSort(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    int left = 0;
    int right = arr.size() - 1;  
    
    RecMergeSort(arr, left, right);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();
}

int timeIterativeMergeSort(vector<int> arr)
{
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size(); 
    
    IterativeMergeSort(arr, n); 
    
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
