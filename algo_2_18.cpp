//
//  main.cpp
//  Algo_2_18
//
//  Created by Yan on 2/18/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int getNextLower(int val);

int getNextHigher(int val)
{
    int c1 = 0;
    int c2 = 0;
    int v = val;
    while((v&0x1) == 0)
    {
        c1++;
        v>>=1;
    }
    
    while((v&0x1) == 1)
    {
        c2++;
        v>>=1;
    }
    if(c1 + c2 == 0 || c1 + c2 == 31 || c1 + c2 == 32)
        return val;
    else
    {
        int p = c1+c2;
        val = val | (1<<p);
        val = val &(~((1<<(p))-1));
        val = val | ((1<<(c2-1))-1);
        return val;
    }
}

int getNextLower(int val)
{
    int c1 = 0;
    int c2 = 0;
    int v = val;

    while((v&0x1) == 1)
    {
        c1++;
        v>>=1;
    }
    if( v == 0)
        return val;
    while((v&0x1) == 0&& v != 0)
    {
        c2++;
        v>>=1;
    }
    
    int p = c1+ c2;
    val = val &(~((1<<(p+1))-1));
    val |= (((1<<(c1+1))-1)<<(c2-1));
    return val;
}

int main(int argc, const char * argv[])
{
    cout<<"5: "<<getNextHigher(5)<<" "<<getNextLower(5)<<endl;
    cout<<"-5: "<<getNextHigher(-5)<<" "<<getNextLower(-5)<<endl;
    return 0;
}

