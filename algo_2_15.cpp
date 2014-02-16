//
//  main.cpp
//  algo 2.14
//
//  Created by Yan on 2/13/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Pair
{
public:
    int x;
    int y;
    Pair(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
class Hash
{
public:
    bool operator()(const Pair&p) const
    {
        return 1;
    }
};

class HashComp
{
public:
    bool operator()(const Pair&p1, const Pair& p2)const
    {
        return (p1.x == p2.x && p1.y == p2.y)||(p1.x == p2.y &&p2.x == p1.y);
    }
};

void merge(vector<int>& list, int s, int e, unordered_set<Pair, Hash, HashComp>& pair, int k)
{
    vector<int> list2(list.begin()+s, list.begin()+e+1);
    
    int mid = (e-s)/2;
    int n1 = 0;
    int n2 = mid+1;
    int n = s;
    
    while(n1 <= mid&&n2 <= e-s)
    {
        if(list2[n1] + list2[n2] <= k)
        {
            pair.insert(Pair(list2[n1], list2[n2]));
        }
        if(list2[n1]<list2[n2])
        {
            list[n] = list2[n1];
            n1++;
        }else
        {
            list[n] = list2[n2];
            n2++;
        }
        n++;
    }
    while(n1 <= mid)
    {
        for(int i = mid+1; i<=e; i++)
        {
            if(list2[n1] + list2[i]<=k)
                pair.insert(Pair(list2[i],list2[n1]));
           
        }
        list[n++] = list2[n1++];
    }
    
    while(n2 <= e-s)
    {
        for(int i = 0; i<=mid; i++)
        {
            if(list2[n2] + list2[i]<=k)
                pair.insert(Pair(list2[i],list2[n2]));
           
        }
        list[n++] = list2[n2++];
    }
}
void mergefind(vector<int>& list, unordered_set<Pair, Hash, HashComp>& pair, int s, int e, int k)
{
    if(s >= e)
    {
        return;
    }else
    {
        int mid = (s+e)/2;
        mergefind(list, pair, s, mid, k);
        mergefind(list, pair, mid+1, e, k);
        merge(list, s, e,pair, k);
    }
}


int main(int argc, const char * argv[])
{
    unordered_set<Pair, Hash, HashComp> p;
    int q[] = {8,1,0};
    vector<int> qq(q, q+sizeof(q)/sizeof(int));
    mergefind(qq, p, 0, qq.size()-1, 30);
    int i = 0;
    for(unordered_set<Pair, Hash, HashComp>::iterator it = p.begin(); it != p.end(); it++)
    {
        cout<<"<"<<it->x <<" "<<it->y<<">"<<endl;
        i++;
    }
    
    cout<<"num:"<<i;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

