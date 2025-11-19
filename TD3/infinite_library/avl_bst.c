#include <stdio.h>
#include <stdlib.h>
#include "avl_bst.h"

// Intially used to be recursive, but added height to struct
int get_height(AVL_Node n) {
    if (n == NULL)
        return 0;
    return n->height;
}


AVL_Node create_node(long int key) {
    AVL_Node node  = malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}


int get_balance(AVL_Node n) {
    if (n == NULL) return 0;
    return get_height(n->left) - get_height(n->right);
}


AVL_Node right_rotate(AVL_Node y) {
    AVL_Node x = y->left;
    AVL_Node left_right = x->right;

    x->right = y;
    y->left = left_right;

    y->height = MAX(get_height(y->left), get_height(y->right)) + 1;
    x->height = MAX(get_height(x->left), get_height(x->right)) + 1;

    return x;
}


AVL_Node left_rotate(AVL_Node x) {
    AVL_Node y = x->right;
    AVL_Node right_left = y->left;

    y->left = x;
    x->right = right_left;

    x->height = MAX(get_height(x->left), get_height(x->right)) + 1;
    y->height = MAX(get_height(y->left), get_height(y->right)) + 1;

    return y;
}


AVL_Node insert(AVL_Node node, long int key) {
    if (node == NULL)
        return create_node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    node->height = 1 + MAX(get_height(node->left), get_height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}


// Because it is mentionned we need to display book IDs in order
void in_order(AVL_Node root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%ld ", root->key);
        in_order(root->right);
    }
}


AVL_Node search(AVL_Node root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}