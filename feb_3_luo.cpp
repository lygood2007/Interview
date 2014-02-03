#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[(left+right) / 2];
    
    while(left <= right) {
        while(a[left] < pivot) {
            ++left;
        }
        while(a[right] > pivot) {
            --right;
        }
        
        if(left <= right) {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
            
            ++left;
            --right;
        }
    }
    
    return left;
}

int recurFindKth(int a[], int left, int right, int k) {
    if(left == right) {
        return a[left];
    }
    
    int pivotIndex = partition(a, left, right);
    
    if(pivotIndex == k - 1){
        return a[pivotIndex];
    } else if(k - 1 > pivotIndex){
        return recurFindKth(a, pivotIndex + 1, right, k - pivotIndex - 1);
    } else {
        return recurFindKth(a, left, pivotIndex - 1, k);
    }
}

int findKth(int a[], int n, int k) {
    return recurFindKth(a, 0, n-1, k);
}


int main(int argc, const char * argv[])
{
    
    int a[] = {3,1,2,1,4};
    int x = findKth(a, 5, 3);
    
    cout<<x;
    return 0;
}

