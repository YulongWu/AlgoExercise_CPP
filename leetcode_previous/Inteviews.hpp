#include "Structs.h"
#include <vector>
using namespace std;
////////////////////////
/*
Question: inplement an processor of editor which support following funcs
Input: a char stream which include 26 characters of lowercase and 4 of uppercase as following.
L: cursor move left
R: cursor move right
B: backspace
D: delete
Output: a char stream after made the operations
*/
class Editor
{
private:
	DLinkNode<char> *inputCache = NULL;
public:
	void init(const char *in)
	{
		const char *p = in;
		while (p && *p != '\0')
			++p;
		if (p)
			return init(in, p - in);
		else
			return;
	}
	void init(const char *in, int len)
	{
		bool first = true;
		DLinkNode<char> *cur = new DLinkNode<char>('\0');
		for (const char *pIn = in; pIn - in < len; ++pIn)
		{
			switch (*pIn)
			{
			case 'L':
				if (cur != NULL)
				{
					cur = cur->prev;
				}
				break;
			case 'R':
				if (cur->post != NULL)
				{
					cur = cur->post;
				}
				break;
			case 'D':
				if (cur->val != '\0')
				{
					DLinkNode<char> *del = cur;
					DLinkNode<char> *prev = cur->prev;
					DLinkNode<char> *post = cur->post;
					if (prev)
						prev->post = post;
					else
						inputCache = post;
					if (post)
					{
						post->prev = prev;
						cur = post;
					}
					else
						throw new exception("Unexpected Error in L65");
					delete del;
				}
				break;
			case 'B':
				if (cur->prev)
				{
					DLinkNode<char> *del = cur->prev;
					DLinkNode<char> *prev = del->prev;
					DLinkNode<char> *post = del->post;
					if (prev)
						prev->post = post;
					if (post)
						post->prev = prev;
					delete del;
				}
				break;
			default:
				DLinkNode<char> *n = new DLinkNode<char>(*pIn);
					n->post = cur;
					n->prev = cur->prev;
					if (cur->prev)
						cur->prev->post = n;
					cur->prev = n;
					if (first)
					{
						inputCache = n;
						first = false;
					}
				break;
			}
		}
	}
	char *output()
	{
		if (!inputCache)
			return NULL;
		vector<char> *v = new vector<char>();
		DLinkNode<char> *p = inputCache;
		while (p)
		{ 
			v->push_back(p->val);
			p = p->post;
		}
		char *res = new char[v->size()];
		res = &(*v)[0];
		return res;
	}
};