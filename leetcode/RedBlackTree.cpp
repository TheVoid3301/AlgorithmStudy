#include <iostream>

using namespace std;

enum Color {
    BLACK,
    RED
};

template <class K, class V>
struct RBTreeNode {
    RBTreeNode(const pair<K, V> &kv): left(nullptr), right(nullptr), parent(nullptr),
                                    color(RED), kv(kv) {

    }

    RBTreeNode *left;
    RBTreeNode *right;
    RBTreeNode *parent;

    Color color;
    pair<K, V> kv;
};