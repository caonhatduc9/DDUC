#include<iostream>
#include<queue>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
};
void destroy(Node*& pRoot)
{
	if (pRoot != NULL)
	{
		destroy(pRoot->left);
		destroy(pRoot->right);
		delete pRoot;
		pRoot = NULL;
	}
}
//1
Node* createNode(int data)
{

	Node* p = new Node;
	p->key = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
//2
void insertNode(Node*& pRoot, int x) {
	if (pRoot == NULL)
		pRoot = createNode(x);
	else
	{
		if (x < pRoot->key)
			insertNode(pRoot->left, x);
		else if (x > pRoot->key)
			insertNode(pRoot->right, x);
	}
}
//3
void print_NLR(Node* pRoot)
{
	if (pRoot != NULL)
	{
		cout << pRoot->key << "\t";
		print_NLR(pRoot->left);
		print_NLR(pRoot->right);
	}
}
//4-xuat ra cac phan tu theo thu tu min->max

void print_LNR(Node* pRoot)
{
	if (pRoot != NULL)
	{
		print_LNR(pRoot->left);
		cout << pRoot->key << "\t";
		print_LNR(pRoot->right);
	}
}
//5
void print_LRN(Node* pRoot)
{
	if (pRoot != NULL)
	{
		print_LRN(pRoot->left);
		print_LRN(pRoot->right);
		cout << pRoot->key << "\t";
	}
}
//6
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
int sumOfNodesAtNthLevel(struct Node* root,int k)
{
	if (root == NULL)
		return 0;
	queue<struct Node*> que;
	que.push(root);
	int level = 0;
	int sum = 0;
	int flag = 0;
	while (!que.empty()) 
	{
		int size = que.size();
		while (size--) 
		{
			struct Node* ptr = que.front();
			que.pop();

			if (level == k) {
				flag = 1;
				sum += ptr->key;
			}
			else {
				if (ptr->left)
					que.push(ptr->left);
				if (ptr->right)
					que.push(ptr->right);
			}
		}
		level++;
		if (flag == 1)
			break;
	}
	return sum;
}
void LevelOrder2(Node* root,int k)
{
	if (root == NULL)
		return;
	if (root != NULL)
	{
		queue<Node*> que;
		que.push(root);
		int level = 0, flag = 0;
		while (!que.empty())
		{
			int size = que.size();
			while (size--)
			{
				struct Node* ptr = que.front();
				que.pop();

				if (level == k) {
					flag = 1;
					cout <<"level: "<< level << " ";
					cout << ptr->key << endl;
				}
				else {
					if (ptr->left)
						que.push(ptr->left);
					if (ptr->right)
						que.push(ptr->right);
				}
			}
			level++;
			if (flag == 1)
				break;
		}
	}
}
//7
int Height(Node* pRoot)
{
	if (pRoot == NULL)
		return 0;
	else return max(Height(pRoot->left), Height(pRoot->right)) + 1;
}
//8
int countNode(Node* pRoot)
{
	if (pRoot == NULL)
		return 0;
	else
		return countNode(pRoot->left) + countNode(pRoot->right) + 1;
}
//9
int sumNode(Node* pRoot)
{
	if (pRoot == NULL)
		return 0;
	else return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}
//10
Node* Search(Node* pRoot, int x)
{
	if (pRoot == NULL)
		return NULL;
	if (pRoot->key == x)
		return pRoot;
	if (pRoot->key < x)
		return Search(pRoot->right, x);
	if (pRoot->key > x)
		return	 Search(pRoot->left, x);
}

//11
void Remove(Node*& pRoot, int x)
{
	//	Node* p = Search(pRoot, x);
	if (pRoot == NULL)
		return;
	else {
		if (x < pRoot->key)
			Remove(pRoot->left, x);
		else if (x > pRoot->key)
			Remove(pRoot->right, x);
		else
		{
			if (pRoot->left == NULL)//Node can xoa la no la
			{
				Node* q = pRoot;
				pRoot = pRoot->right;
				delete q;
				return;
			}
			else if (pRoot->right == NULL)//Node can xoa la Node la
			{
				Node* q = pRoot;
				pRoot = pRoot->left;
				delete q;
				return;
			}
			if (pRoot->right != NULL && pRoot->left != NULL)

				//xoq Node co 2 con
			{//c1 tim Node trai nhat cua cay con phai
				Node* p = pRoot->right;
				while (p->left != NULL)
					p = p->left;
				pRoot->key = p->key;
			}
			Remove(pRoot->right, pRoot->key);

		}
	}
}
//12
Node* createTree(int a[], int n)
{
	Node* pRoot = NULL;
	for (int i = 0; i < n; i++)
		insertNode(pRoot, a[i]);
	return pRoot;
}
//13
void removeTree(Node*& pRoot)
{
	while (pRoot != NULL)
		Remove(pRoot, pRoot->key);
}
//14
int heightNode(Node* pRoot, int value) {
	Node* q = Search(pRoot, value);
	return	Height(q);
}
//15
int Level(Node* pRoot, Node* p) {
	if (pRoot == NULL)
		return 0;
	int level = 1;
	while (pRoot->key != p->key)
	{
		if (pRoot->key > p->key)
		{
			pRoot = pRoot->left;
			level += 1;
		}
		if (pRoot->key < p->key)
		{
			pRoot = pRoot->right;
			level += 1;
		}
	}
	if (pRoot == NULL)
		return 0;
	return level;

}
//16
int countLeaf(Node* pRoot)
{	
	if (pRoot == 0)
		return 0;
	if (pRoot->left == NULL && pRoot->right == NULL)
		return 1;
	else
		return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}
//17
int countLess(Node* pRoot, int x) {
	if (pRoot == NULL)
		return 0;
	
	if (pRoot->key == x)
		return countNode(pRoot->left);
	if(pRoot->key < x)
	return countNode(pRoot->left) + 1 + countLess(pRoot->right, x);
	if (pRoot->key > x)
		return countLess(pRoot->left, x);
}
//18 dem so Node lon hon gia tri da cho
int countGreater(Node* pRoot, int x)
{
	if (pRoot == NULL)
		return 0;
	//return  countNode(pRoot) - countLess(pRoot, x);
	if (pRoot->key = x)
		return countNode(pRoot->right);
	else if (pRoot->key > x)
		return countNode(pRoot->right) + 1 + countGreater(pRoot->left, x);
	else if (pRoot->key < x)
		return countGreater(pRoot->right, x);

}
//20
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
void menu(Node*& pRoot)
{
	while (1) {
		cout << "\n1 add data\n2 print data\n3 Height:\n4 countNode\n5 sumNode\n6 Search\n7 remove";
		cout << "\n8 removeTree\n9 heightNode\n10 level\n11 count leaf\n12 count less\n13 count greater";
		cout << "\n14 isBST\n15 isFullBST";
		cout << "\n\t\t0 quit : ";
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			/*int x;
			cout << "input data: ";
			cin >> x;
			insertNode(pRoot, x);*/
			//int a[11] = { 60,20,80,10,40,70,90,30,50,100,110 };
			int a[9] = { 30,15,60,7,22,45,75,17,27 };
			pRoot = createTree(a, 9);
		}
		else if (choice == 2)
		{
			LevelOrder(pRoot);
			//	print_LNR(pRoot);
		}
		else if (choice == 3)
			cout << Height(pRoot);
		else if (choice == 4)
			cout << countNode(pRoot);
		else if (choice == 5)
			cout << sumNode(pRoot);
		else if (choice == 6)
		{
			cout << " \n nhap x:";
			int x; cin >> x;
			cout << Search(pRoot, x)->right->key;
		}
		else if (choice == 7)
		{
			cout << " \n nhap x:";
			int x; cin >> x;
			Remove(pRoot, x);
		}
		else if (choice == 8)
		{
			removeTree(pRoot);
		}
		else if (choice == 9)
		{
			cout << " \n nhap x:";
			int x; cin >> x;
			cout << heightNode(pRoot, x);
		}
		else if (choice == 10)
		{
			cout << " \n nhap x:";
			int x; cin >> x;

			cout << Level(pRoot, Search(pRoot, x));
		}
		else if (choice == 11)
			cout << countLeaf(pRoot);
		else if (choice == 12) {
			int x;
			cout << "nhap x";
			cin >> x;			cout << countLess(pRoot, x);
		}
		else if (choice == 13) {
			int x;
			cout << "nhap x";
			cin >> x;			cout << countGreater(pRoot, x);
		}
		else if (choice == 14)
			cout << isBST(pRoot);
		else if (choice == 15)
			cout << isFullBST(pRoot);
		else if (choice == 0)
			break;

	}
}
void sumLevel(Node* pRoot)
{
	int m = Height(pRoot);
	for (int i = 1; i <= m; i++)
	{
		cout << "sum level" << i << "  " << sumOfNodesAtNthLevel(pRoot, i) << endl;
	}
}
void showLevelOrder(Node* pRoot)
{
	int m = Height(pRoot);
	for (int i = 1; i <= m; i++)
	{
		LevelOrder2(pRoot, i);

	}
}
int main()
{
	system("color 71");
	Node* pRoot;
	pRoot = NULL;
	//menu(pRoot);
	//destroy(pRoot);
	int a[11] = { 60,20,80, 10, 40, 70, 90, 30, 50, 100, 110 };
	pRoot = createTree(a, 11);
	
	showLevelOrder(pRoot);
	//sumLevel(pRoot);
	return 0;
}