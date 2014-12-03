//
//  main.cpp
//  algo_2_4
//
//  Created by Yan on 2/4/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//  Big O: O(nklogk)

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int m_next;
    int m_val;
    int m_i;
   
};
class MinHeap
{
public:
    MinHeap(vector<Node>& arr)
    {
        items = arr;
        int count = items.size();
        m_max = INT_MIN;
       // m_min = INT_MAX;
        for(int i = count/2-1;i>=0; i--)
        {
            heapify(i);
        }
        m_min = items[0].m_val;

        
    }
    
    int getLeft(int index)
    {
        int left = index*2+1;
        return left>= items.size()?-1:left;
    }
    
    int getRight(int index)
    {
        int right = index*2+2;
        return right>= items.size()?-1:right;
    }
    
    void replaceRoot(Node data)
    {
        items[0] = data;
        heapify(0);
        m_min = items[0].m_val;
    }
    
    Node getRoot(){
        return items[0];
    }
    
    void heapify(int index)
    {
        
        int val = items[index].m_val;
        //  int high = items.size();
        int left = getLeft(index);
        int right = getRight(index);
        m_max = max(m_max,items[index].m_val);
       
        int nextIndex = index;
        
        if(left != -1)
        {
            m_max = max(m_max, items[left].m_val);
            if(items[left].m_val<val)
            {
                nextIndex = left;
                val = items[left].m_val;
            }
        }
        if(right != -1)
        {
            m_max = max(m_max, items[right].m_val);
            if(items[right].m_val < val)
            {
                nextIndex = right;
            }
        }
        if(nextIndex != index)
        {
            swap(items[nextIndex],items[index]);
            heapify(nextIndex);
        }
    }
    
    vector<Node>& getItems(){
        return items;
    }
    
    int getMin(){
        return m_min;
    }
    
    int getMax(){
        return m_max;
    }
    
private:

    vector<Node> items;
    int m_min;
    int m_max;
};

int findRange(vector<vector<int> >& list)
{
    vector<Node> nodes;
    for(int i = 0; i  < list.size(); i++)
    {
        Node newNode;
        newNode.m_i = i;
        newNode.m_next = 1;
        newNode.m_val = list[i][0];
        nodes.push_back(newNode);
    }
    
    MinHeap minHeap(nodes);
    int minRange = INT_MAX;
    while(minHeap.getRoot().m_val != INT_MAX)
    {
        int min = minHeap.getMin();
        int max = minHeap.getMax();
        if(min!= INT_MAX&&max != INT_MAX&&max - min < minRange )
        {
            minRange = max - min;
        }
        Node nextNode;
        int next = minHeap.getRoot().m_next;
        int i = minHeap.getRoot().m_i;
        
        if(next == list[i].size())
            nextNode.m_val = INT_MAX;
        else
        {
            nextNode.m_i = i;
            nextNode.m_next = next+1;
            nextNode.m_val = list[i][next];
        }
        minHeap.replaceRoot(nextNode);
    }
    return minRange;
}

int main(int argc, const char * argv[])
{
    int p1[] = {4,10,15,24,26};
    int p2[] = {0,9,12,20};
    int p3[] = {5,18,22,30};
    vector<int> v1(p1,p1+sizeof(p1)/sizeof(int));
     vector<int> v2(p2,p2+sizeof(p2)/sizeof(int));
     vector<int> v3(p3,p3+sizeof(p3)/sizeof(int));
    
    vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    cout<<findRange(v);
    return 0;
}

