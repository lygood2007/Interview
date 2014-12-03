//
//  main.cpp
//  NegPos
//
//  Created by Yan on 12/2/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& vec)
{
    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;
}

void negpos(vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((i & 1) == 1 && vec[i] > 0)
            continue;
        if ((i & 1) == 0 && vec[i] < 0)
            continue;
        if ((i&1) == 1 && vec[i] < 0)
        {
            int j = i + 1;
            for (; vec[j] < 0&&j < vec.size(); j++) {}
            if (j < vec.size())
                swap(vec[i], vec[j]);
        }
        if ((i&1) == 0 && vec[i] > 0)
        {
            int j = i + 1;
            for (; vec[j] > 0&&j < vec.size(); j++) {}
            if (j < vec.size())
                swap(vec[i], vec[j]);
        }
    }
    print(vec);
}

void negposFollowUp(vector<int>& vec)
{
    if (vec.size() <= 1)
        return;
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((i & 1) == 1 && vec[i] > 0)
            continue;
        if ((i & 1) == 0 && vec[i] < 0)
            continue;
        if ((i&1) == 1 && vec[i] < 0)
        {
            int j = i + 1;
            for (; vec[j] < 0&&j < vec.size(); j++) {}
            if (j < vec.size())
            {
                int tmp = vec[j];
                for (int q = j; q >= i + 1; q --)
                    vec[q] = vec[q - 1];
                vec[i] = tmp;
            }
        }
        if ((i&1) == 0 && vec[i] > 0)
        {
            int j = i + 1;
            for (; vec[j] > 0&&j < vec.size(); j++) {}
            if (j < vec.size())
            {
                int tmp = vec[j];
                for (int q = j; q >= i + 1; q --)
                    vec[q] = vec[q - 1];
                vec[i] = tmp;
            }
        }
    }
    print(vec);
}

void testNegPos()
{
    vector<int> t1{1,-3,2,-4,-5};
    vector<int> t2{1, 2, 3, -4};
    vector<int> t3{-1,-3,-2,-4,-5};
    vector<int> t4{1, 2, 3, 4};
    vector<int> t5{1,3,2, -4,-5};
    vector<int> t6{1, 2, 3, 4, -2, -5};
    vector<int> t7{-1, -2, -3, 4, 5};
    vector<int> t8{-3, -4, -5, 6, 7, 8, 9, -1, -2};
    vector<int> t9{-3, 4, -5, 6, -7, 1, -2};
    vector<int> t10{4, -3, 4, -3, 4, -3};
    /*negpos(t1);
    negpos(t2);
    negpos(t3);
    negpos(t4);
    negpos(t5);
    
    negpos(t6);
    negpos(t7);*/
    negpos(t8);
    /*negpos(t9);
    negpos(t10);*/
}

void testNegPosFollowUp()
{
    vector<int> t1{1,-3,2,-4,-5};
    vector<int> t2{1, 2, 3, -4};
    vector<int> t3{-1,-3,-2,-4,-5};
    vector<int> t4{1, 2, 3, 4};
    vector<int> t5{1,3,2, -4,-5};
    vector<int> t6{1, 2, 3, 4, -2, -5};
    vector<int> t7{-1, -2, -3, 4, 5};
    vector<int> t8{-3, -4, -5, 6, 7, 8, 9, -1, -2};
    vector<int> t9{-3, 4, -5, 6, -7, 1, -2};
    vector<int> t10{4, -3, 4, -3, 4, -3};
   /* negposFollowUp(t1);
    negposFollowUp(t2);
    negposFollowUp(t3);
    negposFollowUp(t4);
    negposFollowUp(t5);
    
    negposFollowUp(t6);
    negposFollowUp(t7);*/
    negposFollowUp(t8);
    /*negposFollowUp(t9);
    negposFollowUp(t10);*/
}


int main(int argc, const char * argv[]) {
    testNegPos();
    testNegPosFollowUp();
    return 0;
}
