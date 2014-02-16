//
//  main.cpp
//  Algo_2.14
//
//  Created by Yan on 2/15/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

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

vector<int> getCorrectA(vector<int>& A, vector<int>& B)
{
    vector<int> result = A;
    
    for(int i = A.size()-1; i>=0; i--)
    {
        int rank = i-B[i];
        int kth = findKth(result, 0, i, rank);
        if(kth != A[i])
        {
            // find where the kth value is.
            // this part can be incorporated in findKth.
            
            int kthPos = 0;
            int j;
            for(j = 0; j <= i; j++)
            {
                if(kth == result[j])
                {
                    break;
                }
            }
            swap(result[i],result[j]);
        }
    }
    return result;
}


int main(int argc, const char * argv[])
{
    int p[] = {2,3,4,5,1};
    vector<int> A(p, p+sizeof(p)/sizeof(int));
    int q[] = {0,0,0,1,3};
    vector<int> B(q, q+sizeof(q)/sizeof(int));
    
    vector<int> ret = getCorrectA(A, B);
    // correct result should be 13542
    for(int i = 0; i < ret.size(); i++)
    {
        cout<<ret[i]<<" ";
    }
    
    return 0;
}

