//
//  main.cpp
//  jan31
//
//  Created by Yvette Luo on 1/31/14.
//  Copyright (c) 2014 Yvette Luo. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> memo;

string recurGetSentence(string text, set<string> dictionary) {
    if(dictionary.find(text) != dictionary.end()) {
        return text;
    }
    if(memo.find(text) != memo.end()) {
        return memo[text];
    }
    
    for(int i = 1; i <= text.size(); ++i) {
        string prefix = text.substr(0,i);
        
        if(dictionary.find(prefix) != dictionary.end()) {
            string suffix = text.substr(i);
            string suffixResult = recurGetSentence(suffix, dictionary);
            
            if(suffixResult != " ") {
                return prefix + " " + suffixResult;
            }
        }
    }
    
    //also memo fail case
    memo[text] = " ";
    return " ";
}

string getSentence(string text, set<string> dictionary) {
    return recurGetSentence(text, dictionary);
}

int main(int argc, const char * argv[])
{
    string text = "iamastudentfromwaterloo";
    
    set<string> dict;
    dict.insert("i");
    dict.insert("am");
    dict.insert("a");
    dict.insert("student");
    dict.insert("from");
    dict.insert("water");
    dict.insert("waterloo");
    
    cout<<getSentence(text, dict);
    
    return 0;
}



