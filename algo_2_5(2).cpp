//
//  main.cpp
//  algo_2_5(2)
//
//  Created by Yan on 2/5/14.
//  Copyright (c) 2014 Yan. All rights reserved.
//

#include <iostream>
using namespace std;


struct TNode
{
    TNode* left;
    TNode* right;
    
    int val;
    
    TNode(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
    }
};

// Big O: O(n)
TNode* findPath(TNode* root, TNode* n1, TNode* n2, int& path, bool& found)
{
    if(root == NULL)
    {
        return NULL;
    }

        int path1 = 0;
        int path2 = 0;
        TNode* left = findPath(root->left, n1, n2, path1,found);
        if(found)
        {
            path = path1;
            return left;
        }
        TNode* right = findPath(root->right, n1, n2, path2,found);
        if(found)
        {
            path = path2;
            return right;
        }
        if(left&&right)
        {
            //if(!found)
            //{
                path = path1 + path2;
                found = true;
            //}
            return root;
        }else if(left || right)
        {
            if(root == n1 || root == n2)
            {
                if(left != NULL)
                {
                    path = path1;
                }else
                {
                    path = path2;
                }
                found = true;
                return root;
            }else
            {
                if(left != NULL)
                    path = path1+1;
                else if(right != NULL)
                    path = path2+1;
                return left != NULL?left:right;
            }
        }else
        {
            if(root == n1 || root == n2)
            {
                
                    path = 1;
                return root;
            }else
            {
                //if(!found)
                    path = 0;
                return NULL;
            }
        }
}

int findPath(TNode* root, TNode*n1, TNode* n2)
{
    if(n1 == n2)
        return 0;
    int num = 0;
    bool flag = false;
    findPath(root, n1,n2,num,flag);
    return num;
}
int main(int argc, const char * argv[])
{

    TNode* root = new TNode(1);
    root->left = new TNode(2);
    root->right = new TNode(3);
    root->left->left = new TNode(4);
     root->left->right = new TNode(5);
    
    cout<<findPath(root, root->left->right, root->right)<<endl;
     cout<<findPath(root, root->left->right, root->left)<<endl;
     cout<<findPath(root, root, root->right)<<endl;
     cout<<findPath(root, root->left->left, root->left)<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

