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
        return recurFindKth(a, pivotIndex + 1, right, k);
    } else {
        return recurFindKth(a, left, pivotIndex - 1, k);
    }
}

int findKth(int a[], int n, int k) {
    return recurFindKth(a, 0, n-1, k);
}


int main(int argc, const char * argv[])
{
    
    int a[] = {6,4,1,3,5,2,10,9,7,8};
    cout<<findKth(a, 10, 1);
    cout<<findKth(a, 10, 2);
    cout<<findKth(a, 10, 3);
    cout<<findKth(a, 10, 4);
    cout<<findKth(a, 10, 5);
    cout<<findKth(a, 10, 6);
    cout<<findKth(a, 10, 7);
    cout<<findKth(a, 10, 8);
    cout<<findKth(a, 10, 9);
    cout<<findKth(a, 10, 10);
    
    return 0;
}

