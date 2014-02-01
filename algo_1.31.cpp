//
//  main.cpp
//  luohao
//
//  Created by Yan on 2/1/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
bool wordBreakBT(string str, set<string>& dict, string& result)
{
    if(str == "")
        return true;;
    
    for(int i = 1; i <= str.size(); i++)
    {
        string substr = str.substr(0,i);
        string tmp = result;
        result = result + " " + substr;
        if(dict.count(substr) &&wordBreakBT(str.substr(i), dict, result))
        {
            return true;
        }
        result = tmp;
    }
    return false;
}

string wordBreakWrapper(string str, set<string>& dict)
{
    
    string ret;
    wordBreakBT(str, dict, ret);
    ret = ret.substr(1);
    return ret;
    
}

string wordBreakDP(string str, set<string>& dict)
{
    vector<int> table(str.size()+1,-1);
    table[0] = 0;
    for(int i = 1; i <= str.size(); i++)
    {
        for(int j = 0; j <= i-1; j++)
        {
            if(table[0] < 0)
                continue;
            else
            {
                if(dict.count(str.substr(j,i-j)))
                {
                    table[i] = j;
                    break;
                }
            }
        }
    }
    string result;
    int i = str.size();
    while(i>0)
    {
        int j = table[i];
        result = str.substr(j,i-j) + " " + result;
        i = j;
    }
    return result.substr(0,result.size()-1);
}

int main(int argc, const char * argv[])
{
    set<string> dict;
    dict.insert("from");
    dict.insert("waterloo");
    dict.insert("yes");
    dict.insert("i");
    dict.insert("am");
    dict.insert("student");
    dict.insert("a");
    cout<<wordBreakDP("iamastudentfromwaterloo", dict);

    return 0;
}

