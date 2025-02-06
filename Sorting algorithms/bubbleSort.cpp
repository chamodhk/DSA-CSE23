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
    int arr[arrSize]  = {100,99,45,32,29};
    
    for (int i = 1; i < arrSize; i++)
    {
        printArr(arr, arrSize);
        int tmp;
        
        bool noSwapFlag = true;
        for (int j = 0; j <  arrSize - i; j++) {
            
            if (arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                noSwapFlag = false;
                
                
                
                
            }
        }
        
        if (noSwapFlag == true) {
            cout << "braked" << endl;
            break;
            
        }
  
        
    }
    printArr(arr, arrSize);    

    return 0;
}
