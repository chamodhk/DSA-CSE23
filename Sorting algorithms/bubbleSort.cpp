// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


void printArr(int arr[], int arrSize)
{   //cout << arr[0] << endl;
    for (int j = 0; j < arrSize; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}



int main() {
    // Write C++ code here
    const int arrSize = 5;
    int arr[arrSize]  = {10,88,43,2,65};
    
    for (int i = 1; i < arrSize; i++)
    {
        int tmp;
        for (int j = 0; j <  arrSize - i; j++) {
            printArr(arr, arrSize);
            if (arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                
                
                
            }
        }
    
            
        
        
        
    }
        

    return 0;
}
