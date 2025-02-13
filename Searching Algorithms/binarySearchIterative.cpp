#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target)
{

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] > target) 
            right = mid - 1;

        else if (arr[mid] < target)
            left = mid + 1;

    }

    return -1;
}

int main()
{
    vector<int> arr = {10,32,35,64,65,87,87};
    int target = 87;
    cout << binarySearch(arr, target) << endl;


}
