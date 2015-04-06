#include "stdafx.h"
#include <vector>
#include <stack>
#include "Structs.h"
using namespace std;

class BinaryTreePreorderTraversal
{
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		if (!root)
			return res;
		TreeNode *p = root;
		stack<TreeNode*> s;
		s.push(p);
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			res.push_back(p->val);
			//***Caution: Trap, you should push right node firstly if you want left node be traversed firstly.
			if (p->right)
				s.push(p->right);
			if (p->left)
				s.push(p->left);
		}
		return res;
	}
};