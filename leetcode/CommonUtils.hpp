#include <algorithm>
#include <string>
#include <queue>
#include "Structs.hpp"
using namespace std;

class Boosted_string
{
public:
	static string& remove_all(string& s, char ch)
	{
		string::size_type pos;
		while ((pos = s.find(ch)) != string::npos)
		{
			s.erase(pos, 1);
		}
		return s;
	}
	static std::vector<std::string> tokenize_string(const std::string& str,
		const std::string separator,
		bool empty  = false )
	{
		const std::string::size_type strlength = str.length();
		const std::string::size_type seplength = separator.length();

		std::string::size_type prev = 0;
		std::string::size_type next = str.find(separator, prev);

		std::vector<std::string> tokens;

		while (std::string::npos != next)
		{
			if (empty || prev != next)
				tokens.push_back(str.substr(prev, next - prev));
			prev = next + seplength;
			next = str.find(separator, prev);
		}
		if (empty || prev != strlength)
			tokens.push_back(str.substr(prev, strlength - prev));
		return tokens;
	}
};
TreeNode* createBinaryTree(string s)
{
	Boosted_string::remove_all(s, '{');
	Boosted_string::remove_all(s, '}');
	vector<std::string> sNodes = Boosted_string::tokenize_string(s, ",");
	if (sNodes.size() == 0)
		return NULL;
	vector<int> nNode;
	std::queue<TreeNode*> treeQueue;
	vector<std::string>::iterator iter = sNodes.begin();
	TreeNode *curNode, *root = new TreeNode((int)atoi((*iter++).c_str())), *stopNode=new TreeNode(0);
	treeQueue.push(root);
	while (!treeQueue.empty())
	{
		curNode = treeQueue.front();
		treeQueue.pop();
		if (iter != sNodes.end())
		{
			for (TreeNode **q = & curNode->left; 
				*q != stopNode && iter != sNodes.end(); 
				*q == curNode->left ? (q = & curNode->right) : (q = &stopNode), 
					++iter)
			{
				if (iter == sNodes.end() || !(*iter).compare("#"))
				{
					continue;
				}
				else
				{
					TreeNode *t = new TreeNode(atoi((*iter).c_str()));
					treeQueue.push(t);
					*q = t;
				}
			}
		}
	}
	return root;
}

template<class T> 
T* createBinaryTree(T *root, string s)
{
	Boosted_string::remove_all(s, '{');
	Boosted_string::remove_all(s, '}');
	vector<std::string> sNodes = Boosted_string::tokenize_string(s, ",");
	if (sNodes.size() == 0)
		return NULL;
	vector<int> nNode;
	std::queue<T*> treeQueue;
	vector<std::string>::iterator iter = sNodes.begin();
	root = new T((int)atoi((*iter++).c_str()));
	T *stopNode = new T(0);
	T *curNode;
	treeQueue.push(root);
	while (!treeQueue.empty())
	{
		curNode = treeQueue.front();
		treeQueue.pop();
		if (iter != sNodes.end())
		{
			for (T **q = &curNode->left;
				*q != stopNode && iter != sNodes.end();
				*q == curNode->left ? (q = &curNode->right) : (q = &stopNode),
				++iter)
			{
				if (iter == sNodes.end() || !(*iter).compare("#"))
				{
					continue;
				}
				else
				{
					T *t = new T(atoi((*iter).c_str()));
					treeQueue.push(t);
					*q = t;
				}
			}
		}
	}
	return root;
}

template <typename T>
void PrintVector(vector<T> vec) {
    cout << "[ ";
    bool is_first = true;
    for(auto iter=vec.begin(), end=vec.end(); iter != end; ++iter) {
        if(!is_first) 
            cout << ", ";
        else
            is_first = false;
        cout << *iter;
    }
    cout << " ]" << endl;
}

template <typename T>
inline T min(const T a1,const T a2,const T a3,const T a4) {
    T t1 = min(a1, a2), t2 = min(a3, a4);
    return min(t1, t2);
}
