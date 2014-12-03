//
//  main.cpp
//  algo_2_5
//
//  Created by Yan on 2/5/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

typedef unordered_map<string, list<string> > Hashmap;

// Big O: O(Nlogm)
vector<string> anagram(vector<string>& input)
{
    Hashmap hashmap;
    for(int i = 0; i < input.size(); i++)
    {
        string tmp = input[i];
        sort(tmp.begin(), tmp.end());
        
        hashmap[tmp].push_back(input[i]);
    }
    vector<string> result;
    Hashmap::iterator it = hashmap.begin();
    for(; it != hashmap.end(); it++)
    {
        list<string>::iterator it2 = it->second.begin();
        
        for(; it2 != it->second.end(); it2++)
        {
            result.push_back(*it2);
        }
    }
    return result;
}


int main(int argc, const char * argv[])
{

    vector<string> test;
    test.push_back("ab");
    test.push_back("a");
    test.push_back("ba");
    test.push_back("cab");
    test.push_back("a");
    test.push_back("bca");
    test.push_back("cba");
    test.push_back("a");
    test.push_back("b");
    
    vector<string> ret = anagram(test);
    for(int i = 0; i < ret.size(); i++)
    {
        cout<<ret[i]<<" ";
    }
    return 0;
}

