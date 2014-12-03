//
//  main.cpp
//  Feb_2_luo
//
//  Created by Yvette Luo on 2/2/14.
//  Copyright (c) 2014 Yvette Luo. All rights reserved.
//

#include <iostream>
using namespace std;

int maxElement (int a[], int n) {
    int left = 0, right = n - 1;
    
    while(left != right) {
        int mid = (left + right) / 2;
        
        
        if(a[mid] < a[mid+1]) {
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    
    return a[left];
}

int maxElementWithSame(int a[], int n) {
    int left = 0, right = n-1;
    
    while(left != right) {
        int mid = (left + right) / 2;
        int lmid = mid, rmid = mid;
        
        while(a[rmid] == a[rmid + 1]) {
            ++rmid;
            if(rmid == n-1){
                break;
            }
        }
        
        while(a[lmid] == a[lmid - 1]) {
            --lmid;
            if(lmid == 0) {
                break;
            }
        }
        
        //search right
        if(rmid == n - 1 || a[rmid] < a[rmid + 1]) {
            left = rmid == n-1? rmid : rmid + 1;
        }
        else {
            //right on the peak!
            if(lmid == 0 || a[lmid] > a[lmid - 1]) {
                return a[lmid];
            }
            //search left
            else {
                right = lmid - 1;
            }
        }
    }
    
    return a[left];
}

int main(int argc, const char * argv[])
{    
    int a[] = {8, 8, 10, 20, 80, 80, 100,100, 200, 200, 400, 500, 3, 2, 1};
    cout<< maxElementWithSame(a, 15)<<endl;
    
    int b[] = {1, 3, 50, 10, 9, 7, 6};
    cout<< maxElementWithSame(b, 7)<<endl;

    int c[] = {10, 20, 30, 40, 50};
    cout <<maxElementWithSame(c, 5)<<endl;
    
    int d[] = {120, 100, 80, 20, 0};
    cout <<maxElementWithSame(d, 5)<<endl;
    
    int e[] = {3,3,3,3};
    cout <<maxElementWithSame(e, 4)<<endl;

    int f[] = {1,2,2,3,3};
    cout <<maxElementWithSame(f, 5)<<endl;
    
    int g[] = {2};
    cout <<maxElementWithSame(g, 1)<<endl;
    
    int h[] = {4,4,3,3,2,2,1};
    cout <<maxElementWithSame(h, 7)<<endl;

    return 0;
}

