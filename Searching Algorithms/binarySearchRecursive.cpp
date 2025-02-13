#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;


    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, left, mid - 1, target);
    }

    else 
        return binarySearch(arr, mid + 1, right, target);
}



int main() 
{
    vector<int> arr = {10,34,23,54,87,34,54};
    int right = arr.size() - 1 ;
    int left = 0;
    int target = 34;

    cout << binarySearch(arr, left, right, target) << endl;
}
