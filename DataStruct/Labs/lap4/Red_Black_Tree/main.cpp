#include<iostream>
using namespace std;
enum rbt_color { red, black };
struct node
{
    int key;
    node* left;
    node* right;
    node* parent;
    rbt_color color;
};
node* createNode(int key)
{
    node* k = new node;
    k->key = key;
    k->left = k->right = NULL;
    k->color = red;
    return k;
}
void insert(node*& root, node* x, node* parent)
{
    if (root == NULL)
    {
        x->parent = parent;
        root = x;
    }
    if (x->key < root->key)
    {
        insert(root->left, x, root);
    }
    else if (x->key > root->key)
    {
        insert(root->right, x, root);
    }
}

void leftRotate(node*& root, node*& x)
{
    node* y = x->right;
    if (y != NULL)
    {
        x->right = y->left;
        if (y->left != NULL)
        {
            y->left->parent = x;
        }
        if (x->parent == NULL)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        y->left = x;
        y->parent = x->parent;
        y->left->parent = y;
    }
}
void rightRotate(node*& root, node*& x)
{
    node* y = x->left;
    if (y != NULL)
    {
        x->left = y->right;
        if (y->right != NULL)
        {
            y->right->parent = x;
        }
        if (x->parent == NULL)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        y->right = x;
        y->parent = x->parent;//cap nhat lai node cha cua node moi se la node cha cua node cu
        y->right->parent = y;//cap nhat lai node cha cua node cu
    }
}

void insertion(node*& root, int key, node* parent)
{
    node* p = createNode(key);
    insert(root, p, parent);
    while (p != root && p->parent->color == red)//isnn't node root and father node is red (because parent node color is black isn't edit)
    {
        if (p->parent == p->parent->parent->left) //if new node insert is left node
        {
            node* uncle = p->parent->parent->right;//uncle node
            if (uncle != NULL && uncle->color == red)//check uncle node,if color is red
            {
                p->parent->color = black;//change color parent node
                uncle->color = black; //change color uncle node
                p->parent->parent->color = red;//change color grand node
                p = p->parent->parent;
            }
            else //neu uncle khong ton tai : case 2
            {
                if (p == p->parent->right)
                {
                    p = p->parent;
                    leftRotate(root, p);
                }
                p->parent->color = black;
                p->parent->parent->color = red;
                rightRotate(root, p->parent->parent);
            }
        }
        else if (p->parent == p->parent->parent->right)
        {
            node* uncle = p->parent->parent->left;//uncle node
            if (uncle != NULL && uncle->color == red)//check uncle node,if color is red
            {
                p->parent->color = black;
                uncle->color = black;
                p->parent->parent->color = red;
                p = p->parent->parent;
            }
            else //neu uncle khong ton tai
            {
                if (p == p->parent->left)
                {
                    p = p->parent;
                    rightRotate(root, p);
                }
                p->parent->color = black;
                p->parent->parent->color = red;
                leftRotate(root, p->parent->parent);
            }
        }
    }
    root->color = black;
}

void insertion1(node*& root, int key, node* parent)
{
    node* p = createNode(key);
    insert(root, p, parent);
    while (p != root && p->parent->color == red)
    {
        if (p->parent == p->parent->parent->left)
        {
            node* uncle = p->parent->parent->right;
            if (uncle != NULL && uncle->color == red)
            {
                uncle->color = black;
                p->parent->parent->color = red;
                p->parent->color = black;
                p = p->parent->parent;
            }
            else
            {
                if (p == p->parent->right)
                {
                    p = p->parent;
                    leftRotate(root, p);
                }
                p->parent->color = black;
                p->parent->parent->color = red;
                rightRotate(root, p->parent->parent);
            }

        }
        else if (p->parent == p->parent->parent->right)
        {
            node* uncle = p->parent->parent->left;
            if (uncle != NULL && uncle->color == red)
            {
                uncle->color = black;
                p->parent->parent->color = red;
                p->parent->color = black;
                p = p->parent->parent;
            }
            else
            {
                if (p == p->parent->left)
                {
                    p = p->parent;
                    rightRotate(root, p);
                }
                p->parent->color = black;
                p->parent->parent->color = red;
                leftRotate(root, p->parent->parent);
            }
        }
    }
    root->color = black;
}
void print_out(node* root)
{
    if (root != NULL)
    {
        print_out(root->left);

        printf("key:%d\t", root->key);
        if (root->color == black)
            printf("color:black\t");
        else
            printf("color:red\t");
        if (root->parent != NULL)
            printf("parent:%d\t", root->parent->key);
        else
            printf("parent:-\t");
        if (root->left != NULL)
            printf("left:%d\t", root->left->key);
        else
            printf("left:-\t");
        if (root->right != NULL)
            printf("right:%d\t", root->right->key);
        else
            printf("right:-\t");
        printf("\n");

        print_out(root->right);
    }
}
void NLR(node* root)
{
    if (root == NULL)return;
    cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
}
node* searchNode(node* root, int p)
{
    if (root != NULL)
    {
        if (p == root->key)
        {
            return root;
        }
        else if (p < root->key)
        {
            return searchNode(root->left, p);
        }
        else if (p > root->key)
        {
            return searchNode(root->right, p);
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so node can them: ";
    cin >> n;
    int key;
    node* x = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri cho tung node: ";
        cin >> key;
        insertion1(x, key, NULL);
    }
    print_out(x);
    node* p = searchNode(x, 2); cout << p->left->key;
    NLR(x);
    return 0;
}