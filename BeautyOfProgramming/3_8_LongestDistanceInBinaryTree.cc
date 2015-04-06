#include <iostream>
using namespace std;

struct NODE {
    NODE *pLeft;
    NODE *pRight;
};

struct RESULT {
    int nMaxDistance;
    int nMaxDepth;
};

RESULT GetMaximumDistance(NODE *root) {
    if(!root) {
        RESULT empty = {0, -1};  //trick: nMaxDepth is -1 and then caller will plus 1 to balance it as zero.
        return empty;
    }

    RESULT lhs = GetMaximumDistance(root -> pLeft);
    RESULT rhs = GetMaximumDistance(root -> pRight);

    RESULT result;
    result.nMaxDepth = max(lhs.nMaxDepth, rhs.nMaxDepth) + 1;
    result.nMaxDistance = max(max(lhs.nMaxDistance, rhs.nMaxDistance), lhs.nMaxDepth + rhs.nMaxDepth + 2);
    return result;
}

//following is code for test
void Link(NODE *nodes, int parent, int left, int right) {
    if(left != -1)
        nodes[parent].pLeft = &nodes[left];
    if(right != -1)
        nodes[parent].pRight = &nodes[right];
}

int main() {
    // P. 241 Graph 3-12
    NODE test1[9] = {0};
    Link(test1, 0, 1, 2);
    Link(test1, 1, 3, 4);
    Link(test1, 2, 5, 6);
    Link(test1, 3, 7, -1);
    Link(test1, 5, -1, 8);
    cout << "test1: " << GetMaximumDistance(&test1[0]).nMaxDistance << endl;

    //P. 243 Graph 3-15
    NODE test2[9] = {0};
    Link(test2, 0, 1, 2);
    Link(test2, 1, 3, 4);
    Link(test2, 3, 5, 6);
    Link(test2, 5, 7, -1);
    Link(test2, 6, -1, 8);
    cout << "test2: " << GetMaximumDistance(&test2[0]).nMaxDistance << endl;
}
