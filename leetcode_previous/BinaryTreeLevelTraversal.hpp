#include "stdafx.h"
#include <vector>
#include <stack>
#include <queue>
#include "Structs.h"
using namespace std;

class BinaryTreeLevelTraversal
{
public:
	static void connect(TreeLinkNode *root) {
		queue<TreeLinkNode*> res;
		if (!root)
			return;
		root->next = root;
		TreeLinkNode *p = root, *prev = NULL;
		res.push(p);
		while (!res.empty())
		{
			p = res.front();
			res.pop();

			if (p->left)
			{
				res.push(p->left);
				if (p->next == root)	//mark the first node of one level
					p->left->next = root;
			}
			if (p->right)
				res.push(p->right);
			
			if (prev)
			{
				if (p->next != root)
					prev->next = p;
				else
					prev->next = NULL;
			}
			prev = p;
		}
		prev->next = NULL;
	}
};