//
//  main.cpp
//  Algo 2_17
//
//  Created by Yan on 2/17/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// square sort
// O(n)
vector<int> squareSort(vector<int>& arr)
{
    vector<int> result;
    if(arr.size() == 0)
        return result;
    
    if(arr[0] >= 0)
    {
        for(int i = 0; i < arr.size(); i++)
        {
            result.push_back(arr[i]*arr[i]);
        }
    }else if(arr[arr.size()-1]<=0)
    {
        for(int i = arr.size()-1; i>=0; i--)
        {
            result.push_back(arr[i]*arr[i]);
        }
    }else
    {
        // find the split position
        int i;
        for(i = 1; i < arr.size();i++)
        {
            if(arr[i]>0)
                break;
        }
        
        int p1 = i-1;
        int p2 = i;
        while(p1>=0&&p2 < arr.size())
        {
            if(abs(arr[p1]) > arr[p2])
            {
                result.push_back(arr[p2]*arr[p2]);
                p2++;
            }else
            {
                result.push_back(arr[p1]*arr[p1]);
                p1--;
            }
        }
        while(p1 >=0)
        {
            result.push_back(arr[p1]*arr[p1]);
            p1--;
        }
        while(p2 < arr.size())
        {
            result.push_back(arr[p2]*arr[p2]);
            p2++;
        }
    }
    return result;
}

// find the largest two numbers
// 一遍loop
vector<int> findLargest(vector<int>& arr)
{
    vector<int> result;
    if(arr.size() < 2)
    {
        return result;
    }else
    {
        int max = arr[0];
        int minDiff = INTMAX_MAX;
        int max2;
        
        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i] > max)
            {
                max2 = max;
                max = arr[i];
                
            }else if( max - arr[i] > 0 && max - arr[i]<minDiff)
            {
                minDiff = max-arr[i];
                max2 = arr[i];
            }
        }
        result.push_back(max);
        result.push_back(max2);
        return result;
    }
}

int main(int argc, const char * argv[])
{

    /*int test[] = {-5,-3,-1,2,4,5,8};
    vector<int> testv(test, test+sizeof(test)/sizeof(int));
    vector<int> ret = squareSort(testv);
    cout<<"result:";
    for(int i = 0;i  < ret.size(); i++)
    {
        cout<<ret[i]<<" ";
    }*/
    
    
    int test2[] = {-5,-4,-3,-2,-1};
    vector<int> testv(test2, test2+sizeof(test2)/sizeof(int));
    vector<int> ret = findLargest(testv);
    
    cout<<ret[0]<<" "<<ret[1]<<" "<<endl;
    return 0;
}

