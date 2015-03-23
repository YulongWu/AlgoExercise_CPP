#pragma once
#include "stdafx.h"
#include <vector>
#include <stack>
#include "Structs.h"
using namespace std;

class BinaryTreeInorderTraversal 
{
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == NULL)
			return res;
		TreeNode *p = root;
		stack<TreeNode *> stack;
		stack.push(p);
		while (!stack.empty())
		{
			if (stack.top() == p)
			{
				while (p -> left)
				{
					stack.push(p->left);
					p = p->left;
				}
			}
			p = stack.top();
			stack.pop();
			res.push_back(p->val);
			if (p->right)
			{
				stack.push(p->right);
				p = p->right;
			}
			else
				p = NULL;
		}
		return res;
	}
};