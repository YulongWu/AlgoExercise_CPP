// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
#include "Structs.h"
#include "CommonUtils.h"

//Questions of leetcode
#include "ReverseInteger.h"
#include "BestTimeToBuyAndSellStock2h.h"
#include "NumTrees.h"
#include "LinkedListCycle.h"
#include "BinaryTreePreorderTraversal.h"
#include "BinaryTreeInorderTraversal.h"
#include "BinaryTreeLevelTraversal.h"

//Questions from interviews
#include "Inteviews.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/* ReverseInteger
	ReverseInteger inst;
	int val = 900000;
	int res = inst.reverse(val);
	cout << res << endl;
	cin >> res;
	return 0;
	*/
	/* Number of unique tree
	NumTrees inst;
	int res = inst.numTrees(100);
	cout << res << endl;
	res = inst.numTreesNoOpt(100);
	cout << res << endl;
	cin >> res;
	return 0;
	*/
	/* Linked list cycle
	LinkedListCycle inst;
	ListNode *listNode = new ListNode(0);
	listNode->next = listNode;
	if (inst.hasCycle(listNode))
		cout << "has cycle." << endl;
	else
		cout << "has no cycle." << endl;
	system("pause");
	*/
	//TreeNode* root = createBinaryTree("{1,#,2,3}");
	/* Binary Tree Preorder Traversal
	BinaryTreePreorderTraversal inst;
	vector<int> res = inst.preorderTraversal(root);
	*/
	/* Binary Tree Inorder Traversal
	BinaryTreeInorderTraversal inst;
	vector<int> res = inst.inorderTraversal(root);
	for each (int i in res)
	{
		cout << i << ", ";
	}
	cout << endl;
	*/
	/* Populating Next Right Pointers in Each Node
	TreeLinkNode* root = new TreeLinkNode(0);
	root = createBinaryTree(root, "{1,2,3,4,5,6,7}");
	BinaryTreeLevelTraversal inst;
	inst.connect(root);
	TreeLinkNode *p = root, *levelFirst = root;
	while (p)
	{
		cout << p->val;
		if (p->next)
			p = p->next;
		else if (levelFirst)
		{
			p = levelFirst->left;
			cout << endl;
			levelFirst = levelFirst->left;
		}
	}
	*/
	string s = "abefLLcdRRBBLDDDRR";
	const char *input = s.c_str();
	Editor ins;
	ins.init(input);
	char *output = ins.output();
	cout << output << endl;
	getchar();
}