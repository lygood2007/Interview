//
//  main.cpp
//  algo_2_6
//
//  Created by Yan on 2/7/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
// Big O: O(n)
struct Interval
{
    int start;
    int end;
    int sum;
    Interval(){
        
    }
    Interval(int s, int e, int su)
    {
        start = s;
        end = e;
        sum = su;
    }
};

void getMax(vector<int>& vec, int start, int end, vector<Interval>& interval)
{
    // firstly check all negative
    if(vec[0] < 0)
    {
        bool negative = true;
        for(int i = 1; i < vec.size(); i++)
        {
            if(vec[i] > 0)
            {
                negative = false;
                break;
            }
        }
        if(negative)
        {
            interval[0] = Interval(0,0,vec[0]);
            Interval maxEntry = interval[0];
            for(int i = 1; i < vec.size(); i++)
            {
                if(vec[i] > maxEntry.sum)
                {
                    maxEntry.start = i;
                    maxEntry.end = i;
                    maxEntry.sum = vec[i];
                }
                interval[i] = maxEntry;
            }
            return;
        }
    }
    
    int lastBegin =start;
    int sum = vec[start];
    int step = 1;
    if(start>end)
        step = -1;
    Interval maxEntry = Interval(start, start, sum);
    interval[start] = maxEntry;
    if(sum<0)
    {
        sum = 0;
        lastBegin = start + step;
    }

    int i = start;
    do {
        i += step;
        sum += vec[i];
        if(sum > maxEntry.sum)
        {
            if(step < 0)
            {
            maxEntry.start = i;
            maxEntry.end = lastBegin;
            }else
            {
                maxEntry.start = lastBegin;
                maxEntry.end = i;
            }
            maxEntry.sum = sum;
        }
        if(sum < 0)
        {
            sum = 0;
            lastBegin = i+step;
        }
        interval[i] = maxEntry;
    } while (i != end);
}

//
void getMaxDiff(vector<int>& array, int& sub1_start, int& sub1_end, int& sub2_start, int&sub2_end, int& maxDiff)
{
    vector<Interval> maxFromLeft(array.size());
    vector<Interval> maxFromRight(array.size());
    getMax(array, 0,maxFromLeft.size()-1,maxFromLeft);
    getMax(array, maxFromRight.size()-1,0,maxFromRight);
    
    vector<int> arrayNeg = array;
    for(int i = 0; i < array.size(); i++)
    {
        arrayNeg[i]*=-1;
    }
    
    vector<Interval> minFromLeft(arrayNeg.size());
    vector<Interval> minFromRight(arrayNeg.size());
    getMax(arrayNeg, 0,minFromLeft.size()-1,minFromLeft);
    getMax(arrayNeg, minFromRight.size()-1,0,minFromRight);
    
    
    maxDiff = INT_MIN;
    for(int i = 0; i < array.size()-1; i++)
    {
        if(abs(maxFromLeft[i].sum - (-minFromRight[i+1].sum)) > maxDiff)
        {
            maxDiff = abs(maxFromLeft[i].sum - (-minFromRight[i+1].sum));
            sub1_start = maxFromLeft[i].start;
            sub1_end = maxFromLeft[i].end;
            sub2_start = minFromRight[i+1].start;
            sub2_end = minFromRight[i+1].end;
        }
        
        if(abs(maxFromRight[i+1].sum - (-minFromLeft[i].sum)) > maxDiff)
        {
            maxDiff = abs(maxFromRight[i+1].sum - (-minFromLeft[i].sum));
            sub1_start = minFromLeft[i].start;
            sub1_end = minFromLeft[i].end;
            sub2_start = maxFromRight[i+1].start;
            sub2_end = maxFromRight[i+1].end;
        }
    }
}

int main(int argc, const char * argv[])
{
    int p[] = {2, -1, -2, 1, -4, 2, 8};
    vector<int> array(p,p+sizeof(p)/sizeof(int));
    int maxDiff, sub1_start, sub1_end, sub2_start,sub2_end;
    
    getMaxDiff(array, sub1_start, sub1_end, sub2_start,sub2_end, maxDiff);
    cout<<"Subarray1:"<<sub1_start<<" "<<sub1_end<<endl;
    cout<<"Subarray2:"<<sub2_start<<" "<<sub2_end<<endl;
    cout<<"Diff:"<<maxDiff;
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

