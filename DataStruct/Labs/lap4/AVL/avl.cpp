#include<iostream>
#include<queue>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
};

Node* createNode(int data)
{

	Node* p = new Node;
	p->key = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
int Height(Node* pRoot)
{
	if (pRoot == NULL)
		return 0;
	else return max(Height(pRoot->left), Height(pRoot->right)) + 1;
}
int heightNode(Node* pRoot, int x)
{
	if (pRoot == NULL)
		return 0;
	else if (pRoot->key > x)
		return heightNode(pRoot->left, x);
	else if (pRoot->key < x)
		return heightNode(pRoot->right, x);
	else if (pRoot->key == x)
		return Height(pRoot);
}
void LRotate(Node*& pRoot)
{
	Node* p = pRoot->right;
	pRoot->right = p->left;
	p->left = pRoot;
	pRoot = p;
}
void RRotate(Node*& pRoot)
{
	Node* p = pRoot->left;
	pRoot->left = p->right;
	p->right = pRoot;
	pRoot = p;
}
void balanceTree(Node*& pRoot)
{
	if (pRoot == NULL)
		return;
	int balance = Height(pRoot->left) - Height(pRoot->right);
	if (balance > 1)//mat can bang trai
	{
		if (Height(pRoot->left->left) > Height(pRoot->left->right))
			//mat can bnawg trai trai
			RRotate(pRoot);
		else if (Height(pRoot->left->left) < Height(pRoot->left->right))
		{
			LRotate(pRoot->left);
			RRotate(pRoot);
		}
	}
	if (balance < -1)//mat can bang phai
	{
		if (Height(pRoot->right->left) < Height(pRoot->right->right))
			//mat can bnawg phai phai
			LRotate(pRoot);
		else	if (Height(pRoot->right->left) < Height(pRoot->right->right))
		{
			RRotate(pRoot->right);
			LRotate(pRoot);
		}
	}
}
void insertNode(Node*& pRoot, int x)
{
	if (pRoot == NULL)
	{
		pRoot = createNode(x);
		return;
	}
	if (pRoot->key == x)
		return;
	if (x < pRoot->key)
		insertNode(pRoot->left, x);
	if (x > pRoot->key)
		insertNode(pRoot->right, x);
	balanceTree(pRoot);
}
Node* createTree(int a[], int n)
{
	Node* pRoot = NULL;
	for (int i = 0; i < n; i++)
		insertNode(pRoot, a[i]);
	return pRoot;
}
void removeNode(Node*& pRoot, int x)
{
	if (pRoot == NULL)
		return;
	if (pRoot->key > x)
		removeNode(pRoot->left, x);
	if (pRoot->key < x)
		removeNode(pRoot->right, x);
	if (pRoot->key == x)
	{
		if (pRoot->left == NULL && pRoot->right == NULL)
		{
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->left != NULL && pRoot->right == NULL)
		{
			Node* p = pRoot;
			pRoot = pRoot->left;
			delete p;
		}
		else if (pRoot->left == NULL && pRoot->right != NULL)
		{
			Node* p = pRoot;
			pRoot = pRoot->right;
			delete p;
		}
		else if (pRoot->left != NULL && pRoot->right != NULL)
		{
			Node* p = pRoot->right;
			while (p->left != NULL)
				p = p->left;
			pRoot->key = p->key;
			removeNode(pRoot->right, pRoot->key);
		}
	}
	if (pRoot == NULL)
		return;
	balanceTree(pRoot);
}
void LevelOrder(Node* pRoot)
{
	if (pRoot != NULL)
	{
		queue<Node*> a;
		a.push(pRoot);
		while (!a.empty())
		{
			Node* p = a.front();
			cout << p->key << "\t";
			a.pop();
			if (p->left != NULL)
				a.push(p->left);
			if (p->right != NULL)
				a.push(p->right);
		}
	}
}
int findMin(Node* pRoot)
{
	if (pRoot == NULL)
		return 100000;
	return min(min(pRoot->key, findMin(pRoot->left)), findMin(pRoot->right));
}
int findMax(Node* pRoot)
{
	if (pRoot == NULL)
		return -100000;
	return max(max(pRoot->key, findMax(pRoot->left)), findMax(pRoot->right));
}

bool isBST(Node* pRoot)
{
	if (pRoot == NULL)
		return true;
	if (pRoot->key<findMin(pRoot->right) && pRoot->key>findMax(pRoot->left))
		return isBST(pRoot->left) && isBST(pRoot->right);
	return false;
}
bool isFullBST(Node* pRoot)
{
	if (pRoot == NULL)
		return true;
	if (pRoot->left == NULL && pRoot->right == NULL)
		return true;
	if (pRoot->left != NULL && pRoot->right != NULL && isBST(pRoot))
		return isFullBST(pRoot->left) && isFullBST(pRoot->right);
	return false;
}
bool isAVL(Node* pRoot)
{
	if (isBST(pRoot) && abs(Height(pRoot->left) - Height(pRoot->right)) <= 1)
		return true;
	return false;
}
//tim node be nhat co cung chieu cao
int findNode(Node* pRoot, int x, int h)
{
	if (pRoot == NULL)
		return 100000;
	int hn = Height(pRoot);
	if (hn == h && pRoot->key != x)
	{
		return min(findNode(pRoot->left, x, h), min(findNode(pRoot->right, x, h), pRoot->key));
	}
	return	min(findNode(pRoot->left, x, h), findNode(pRoot->right, x, h));
}
// tim node lon nhat co cung chieu cao
int findNodeMax(Node* pRoot, int x, int h)
{
	if (pRoot == NULL)
		return 0;
	int hn = Height(pRoot);
	if (hn == h && pRoot->key != x)
	{
		return max(findNodeMax(pRoot->left, x, h), max(findNodeMax(pRoot->right, x, h), pRoot->key));
	}
	return	max(findNodeMax(pRoot->left, x, h), findNodeMax(pRoot->right, x, h));
}
// tim so nguyen to lon nhat
bool isPrime(int n) {
	for (int i = 2; i < n; i++)
		if (n % i == 0) {
			// n chia hết cho số khác 1 và chính nó.
			return false;
		}
	return n > 1;
}
int findPrime(Node* pRoot)
{
	if (pRoot == NULL)
		return -1;
	if (isPrime(pRoot->key))
		return max(findPrime(pRoot->left), max(findPrime(pRoot->right), pRoot->key));
	return max(findPrime(pRoot->right), findPrime(pRoot->left));
}

int main()
{
	int a[11] = { 60,20,80, 10, 40, 70, 90, 30, 50, 100, 110 };

	//int a[7] = { 1,11,9,5,7,8,20 };
	Node* pRoot;
	pRoot = NULL;
	pRoot = createTree(a, 11);
	cout<<heightNode(pRoot, 70);
		//LevelOrder(pRoot);
		//cout << heightNode(pRoot,10);
	//cout << findNode(pRoot, 60, h);
//	cout << findPrime(pRoot);
//	cout << findNodeMax(pRoot, 40, heightNode(pRoot, 40));
	//	cout << " \n\t" << isAVL(pRoot);

	return 0;
}