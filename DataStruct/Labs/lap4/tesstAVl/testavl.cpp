#include<iostream>
#include<math.h>
#include<cmath>
#include<queue>
using namespace std;
struct node
{
    int key;
    node* left;
    node* right;
};
node* creaTeNode(int x)
{
    node* p = new node;
    p->left = NULL;
    p->right = NULL;
    p->key = x;
    return p;
}
node* rightRotate(node*& root)
{
    node* t = root->left;
    node* t1 = t->right;
    t->right = root;
    root->left = t1;
    return t;
}
node* leftRotate(node*& root)
{
    node* t = root->right;
    node* t1 = t->left;
    t->left = root;
    root->right = t1;
    return t;
}
int Height(node* root)
{
    if (root == NULL)return 0;
    return max(Height(root->left), Height(root->right)) + 1;
}
void balance(node*& root)
{
    if (root == NULL)return;
    int bal = Height(root->left) - Height(root->right);
    if (bal > 1) //cay lech trail
    {
        if (Height(root->left->left) > Height(root->left->right))//lech trail trail
        {
            root = rightRotate(root);
        }
        else if (Height(root->left->right) > Height(root->left->left))//lech trail phar
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
    }
    else if (bal < -1)
    {
        if (Height(root->right->right) > Height(root->right->left))//lech phar phar
        {
            root = leftRotate(root);
        }
        else if (Height(root->right->left) > Height(root->right->right))//lech phar trail
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }
}
void insert(node*& root, int x)
{
    if (root == NULL)
    {
        root = creaTeNode(x);
        return;
    }
    if (root->key < x)
    {
        insert(root->right, x);
    }
    else if (root->key > x)
    {
        insert(root->left, x);
    }
    balance(root);

}

node* createTree(int a[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, a[i]);
    }
    return root;
}
void remove(node*& root, int x)
{
    if (root == NULL)return;
    if (root->left == NULL && root->right == NULL)//case node root is leaves node
    {
        delete(root);
        root = NULL;
        return;
    }
    else if (root->left != NULL && root->right == NULL)//case node root has 1 node leaves
    {
        node* t = root;
        root = root->left;
        delete(t);
        return;
    }
    else if (root->left == NULL && root->right != NULL)//case node root has 1 node leaves
    {
        node* t = root;
        root = root->right;
        delete(t);
        return;
    }
    else if (root->left != NULL && root->right != NULL)//case node root have two node child
    {
        node* t = root->right;
        while (t->left != NULL)
        {
            t = t->left;
        }
        root->key = t->key;
        remove(root->right, root->key);
    }
    balance(root);
}
void levelOrder(node* root)
{
    if (root == NULL)return;
    queue<node*>p;
    p.push(root);
    while (!p.empty())
    {
        node* temp = p.front();
        p.pop();
        if (temp->left != NULL)
        {
            p.push(temp->left);
        }
        if (temp->right != NULL)
        {
            p.push(temp->right);
        }
        cout << temp->key << " ";
    }
}
int maxNode(node* root)
{
    if (root == NULL)return -10000;
    return max((max(root->key, maxNode(root->left))), root->right->key);
}
int minNode(node* root)
{
    if (root == NULL)return 10000;
    return min((min(root->key, minNode(root->left))), root->right->key);
}
bool isBST(node* root)
{
    if (root == NULL)return true;
    if ((root->left != NULL && root->key < maxNode(root->left)))
    {
        return false;
    }
    if ((root->right != NULL && root->key > minNode(root->right)))
    {
        return false;
    }
    if (!isBST(root->left) || !isBST(root->right))
        return false;
    return true;
}

bool isAVL(node* root)
{
    if (root == NULL)return true;
    // if (isBST(root) == false)return false;
    if (abs(Height(root->left) - Height(root->right)) <= 1)
        return true;
    if (root->left && root->right && isBST(root))
    {
        return (isAVL(root->left) && isAVL(root->right));
    }
    return false;
}

int main(int agrc, char* argv[])
{
    int a[7] = { 1,2,3,4,5 };
    node* root = createTree(a, 5);
    insert(root, 6);
    levelOrder(root);
    return 0;
}