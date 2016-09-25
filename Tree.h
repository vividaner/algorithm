//
//  Tree.h
//  algorithm
//
//  Created by DanMiao on 8/18/16.
//  Copyright © 2016 DanMiao. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <queue>

struct binary_tree
{
    binary_tree* left;
    binary_tree* right;
    int key;
};

struct tbt_tree
{
    int ltag;
    int rtag;
    tbt_tree* left;
    tbt_tree* right;
    int key;
};

tbt_tree* pre = NULL;

void in_thread(tbt_tree* p, tbt_tree** pre)
{
    if(p != NULL)
    {
        in_thread(p->left, pre);
        
        if(p->left == NULL)
        {
            p->left = *pre;
            p->ltag = 1;
        }
        
        if((*pre) != NULL && (*pre)->right == NULL)
        {
            (*pre)->right = p;
            (*pre)->rtag = 1;
        }
        *pre = p;
        in_thread(p->right, pre);
    }
}

void create_in_thread(tbt_tree* root)
{
    tbt_tree* pre = NULL;
    if(root != NULL)
    {
        in_thread(root, &pre);
        pre->right = NULL;
        pre->rtag = 1;
    }
}

void pre_thread(tbt_tree* p, tbt_tree* &pre)
{
    if(p != NULL)
    {
        if(p->left == NULL)
        {
            p->ltag = 1;
            p->left = pre;
        }
        if(pre != NULL && pre->right == NULL)
        {
            pre->rtag = 1;
            pre->right = p;
        }
        pre = p;
        pre_thread(p->left, pre);
        pre_thread(p->right, pre);
    }
}

void create_pre_thread(tbt_tree* root)
{
    tbt_tree* pre = NULL;
    if(root != NULL)
    {
        pre_thread(root, pre);
    }
}

void visit(binary_tree* node)
{
    
}

void pre_order_r(binary_tree* node)
{
    if(node)
    {
        visit(node);
        pre_order_r(node->left);
        pre_order_r(node->right);
    }
}

void pre_order(binary_tree* root)
{
    binary_tree* p;
    stack<binary_tree*> s;
    p = root;
    if(p!=NULL)
        s.push(p);
    while(!s.empty())
    {
        p = s.top();
        s.pop();
        visit(p);
        if(p->right != NULL)
            s.push(p->right);
        if(p->left != NULL)
            s.push(p->left);
    }
}

void in_order(binary_tree* root)
{
    binary_tree* p;
    stack<binary_tree*> s;
    p = root;
    
    while(!s.empty() || p!=NULL)
    {
        if(p!=NULL)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            visit(p);
            p = p->right;
        }
    }
        
}

void post_order(binary_tree* root)
{
    binary_tree* p = root;
    binary_tree* q;
    stack<binary_tree*> s;
    while(!s.empty())
    {
        while(p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        q = NULL;
        while(!s.empty())
        {
            p = s.top();
            s.pop();
            if(p->right == q)
            {
                visit(p);
                q = p;
            }
            else
            {
                s.push(p);
                p = p->right;
                break;
            }
        }
        
    }
}

void level_order(binary_tree* root)
{
    binary_tree* p = root;
    queue<binary_tree*> q;
    if(p!=NULL)
        q.push(p);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        visit(p);
        if(p->left != NULL)
            q.push(p->left);
        if(p->right != NULL)
            q.push(p->right);
    }
}
#endif /* Tree_h */
