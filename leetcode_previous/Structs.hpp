#pragma once
#include "stdafx.h"
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Linked list related
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

template <typename T>
struct DLinkNode {
	T val;
	DLinkNode *prev, *post;
	DLinkNode(T val) :val(val), prev(NULL), post(NULL) {}
	DLinkNode() :prev(NULL), post(NULL) { val = NULL; }
};

//Tree related
struct TreeLinkNode {
	int val;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL) , next(NULL) {}
};
