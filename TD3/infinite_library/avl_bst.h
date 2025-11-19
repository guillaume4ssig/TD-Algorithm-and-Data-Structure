#ifndef AVL
#define AVL

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Node {
    long int key; // Long because ID is up to 10^9
    struct Node* left;
    struct Node* right;
    int height;
};

typedef struct Node * AVL_Node;

int get_height(AVL_Node n);
AVL_Node create_node(long int key);
int get_balance(AVL_Node n);
AVL_Node right_rotate(AVL_Node y);
AVL_Node left_rotate(AVL_Node x);
AVL_Node insert(AVL_Node node, long int key);
void in_order(AVL_Node root);
AVL_Node search(AVL_Node root, int key);

#endif