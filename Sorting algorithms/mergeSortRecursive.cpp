#include <iostream>
#include <vector>
using namespace std;


void vectorPrint(vector<int> arr)
{
    for (int i = 0; i < (int)arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

vector<int> merge(vector<int> leftArr, vector<int> rightArr, vector<int> arr)
{
    int i = 0;
    int j = 0;
    int k = 0;

    int leftSize = leftArr.size();
    int rightSize = rightArr.size();
    vectorPrint(arr);


    while(i < leftSize && j < rightSize)
    {
        if(leftArr[i] <= rightArr[j])
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

    while (i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;

    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;

    }

    return arr;
    


}



vector<int> mergeSort(vector<int> arr)
{
    int arrSize = arr.size();

    if (arrSize == 1)
    {
        return arr;
    }

    int mid = arrSize / 2;
    vector<int> leftArr;
    vector<int> rightArr;

    for ( int i = 0; i < mid; i ++)
    {
        leftArr.push_back(arr[i]);
    }

    for (int i = mid; i < arrSize; i++)
    {
        rightArr.push_back(arr[i]);
    }

    leftArr = mergeSort(leftArr);
    rightArr = mergeSort(rightArr);
    arr = merge(leftArr, rightArr, arr);

    return arr;

    
}

int main()
{
    vector<int> arr = {1,4,3,6,2,5,53,223,42,54,24,26,67,34,23,74,34};
    arr = mergeSort(arr);
    vectorPrint(arr);



    
}
