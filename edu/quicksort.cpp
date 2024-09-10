#include <bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int lo,int hi){
    int pivot = arr[lo];
    int i = lo;
    int j = hi;
    while(i < j){
        while(arr[i] <= pivot && i <= hi-1){
            i++;
        }
        while(arr[j] >= pivot && j >= lo+1){
            j--;
        }
        if(i < j) swap(arr[i],arr[j]);
    }
    swap(arr[lo],arr[j]);
    return j;
}
void quickSort(vector<int>&arr,int lo,int hi){
    if(lo < hi){
        int pivot = partition(arr,lo,hi);
        quickSort(arr,lo,pivot-1);
        quickSort(arr,pivot+1,hi);
    }
}

int main()
{
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();
    cout << "Before Using quick Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr,0,arr.size()-1);
    cout << "After Using quick sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}