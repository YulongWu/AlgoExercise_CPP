/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

bool g_valid = true;

bool isleaf(node * p) {
    if ( p ) {
        if (! p -> left && ! p -> right && p -> data != '\0') {
            return true;
        } else if (p -> left && p -> right && p -> data == '\0'){
            return false;
        }
    }
    g_valid = false;
    return false;
}
void decode_huff(node * root,string s)
{
    if (root == NULL)    
        return;

    string res;
    node *p = root;
    for (string::iterator it = s.begin(); g_valid && it < it.end(); ++it) {
        if (*it == '0') {
            p = p -> left;
        }
        else if (*it == '1') {
            p = p -> right;
        }
        else {
            g_valid = false;
            return;
        }

        if ( isleaf(p) ) {
            res.append("" + p -> data);
            p = root;
        }
    }

    std::cout << res << std::endl;
}
