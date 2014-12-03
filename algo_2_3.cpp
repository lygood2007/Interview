//
//  main.cpp
//  algo_2_3
//
//  Created by Yan on 2/3/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

// Big O: O(nlogk)

#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int>& array, int start, int end)
{
    int random = rand()%(end-start+1)+start;
    
    int pivot = array[random];
    
    swap(array[random], array[start]);
    
    int last_sorted = start;
    for(int i = start+1; i <= end; i++)
    {
        if(array[i]<pivot)
        {
            last_sorted++;
            swap(array[i],array[last_sorted]);
        }
    }
    swap(array[last_sorted], array[start]);
    return last_sorted;
}


int findKth(vector<int>& array, int start, int end, int k)
{
    if(start<end)
    {
        int p = partition(array, start, end);
        if(p == k)
        {
            return array[p];
        }else if(p > k)
        {
            return findKth(array, start, p-1, k);
        }else
        {
            return findKth(array, p+1, end, k);
        }
    }else if(start == end && start == k)
    {
        return array[start];
    }else
    {
        return -1;
    }
}

void test(vector<int>& array, int k)
{
    cout<<"My result:"<<findKth(array, 0, array.size()-1, k)<<endl;
    sort(array.begin(),array.end());
    cout<<"Correct Result:"<<array[k]<<endl;

}
int main(int argc, const char * argv[])
{
    srand(0);
    
    int p[] = {3, 1, 2, 1, 4,3,2,4,6};
    vector<int> v(p,p+sizeof(p)/sizeof(int));
    
    test(v,3);
    test(v,4);
    test(v,5);
    test(v,6);
    test(v,7);
    return 0;
}

