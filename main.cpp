//
//  main.cpp
//  algorithm_exercises
//
//  Created by Yvette Luo on 1/30/14.
//  Copyright (c) 2014 Yvette Luo. All rights reserved.
//


/*Jan, 30*/

#include <iostream>
#include <vector>

using namespace std;

bool isValid(const vector<vector<int>>& g, vector<int>& result, int v, int color) {
    for(int i = 0; i < g.size(); ++i) {
        if(g[v][i] && result[i] == color) {
            return false;
        }
    }
    return true;
}

bool colorVertex(const vector<vector<int>>& g, vector<int>& result, int v, int m) {
    //base
    if(v == result.size()){
        return true;
    }
    
    for(int i = 1; i <= m; ++i) {
        //check if valid
        if(isValid(g, result, v, i)) {
            //if valid, mark & proceed
            result[v] = i;
            
            if(colorVertex(g, result, v+1, m)){
                return true;
            } else{
                result[v] = 0;
            }
            
        }
    }
    return false;
    
}

bool colorGraph(const vector<vector<int>>& g, int m) {
    vector<int> result(g.size(), 0);
    if(colorVertex(g, result, 0, m)){
        for(int i = 0; i < result.size(); ++i){
            cout<<result[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    return false;
}

int main(int argc, const char * argv[])
{
    int g[5][5] = {
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0}
    };
    
    vector<vector<int>> vg(5, vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        vg[i].assign(g[i], g[i] + 5);
    }
    
    colorGraph(vg, 3);
    
    return 0;
}

