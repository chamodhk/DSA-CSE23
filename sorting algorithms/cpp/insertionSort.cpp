#include <iostream>
#include <iomanip>
using namespace std;

void printArray(int arr[],int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << arr[i] << "  ";
    }

    cout << endl;
}

int main()
{
    const int arraySize = 6;
    int arr[arraySize] = {3,1,4,6,2,5};
    for (int i = 1; i < arraySize; i ++)

    {   
        int insert = arr[i]; // temperory holds the value we want to insert to the correct position
        int moveItem = i; // stores the index of the item we want to shift to the right and it's intially set to the insert's index

        while ((moveItem > 0) &&  (arr[moveItem-1] > insert)) //check if there is a left element and the insert value is less than that element
        {
            arr[moveItem] = arr[moveItem-1]; // if the left item is greater than the moveItem, we shift the left element to the right
            moveItem--; 


        }

        // now moveItem is set to the correct position where we should insert our insert-value.
        arr[moveItem] = insert;
    }

    printArray(arr, arraySize);

}
