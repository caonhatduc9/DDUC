#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>;
#include<queue>
#include<stack>
using namespace std;
#define MAX 999999
vector<vector<int>> toAdjList()
{
	ifstream fi("graph1.txt");
	string s, s1;
	getline(fi, s);
	int v = stoi(s);
	vector<vector<int>> adjList;
	for (int i = 0; i < v; i++)
	{
		getline(fi, s);
		stringstream ss(s);
		vector<int> temp;
		for (int i = 0; i < v; i++)
		{
			getline(ss, s1, ' ');
			if (s1 == "1")
				temp.push_back(i);
		}
		adjList.push_back(temp);
	}
	return adjList;
}
vector<vector<int>> toAdjMatrix()
{
	ifstream fi("graph2.txt");
	string s, s1;
	getline(fi, s);
	int v = stoi(s);
	vector<vector<int>> adjMatrix;
	for (int i = 0; i < v; i++)
	{
		getline(fi, s);
		stringstream ss(s);
		vector<int> temp(v, 0);
		while (!ss.eof())
		{
			getline(ss, s1, ' ');
			temp[stoi(s1)] = 1;
		}
		adjMatrix.push_back(temp);
	}
	return adjMatrix;
}
bool isDirected1(vector<vector<int>> adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
		for (int j = 0; j < adjMatrix[i].size(); j++)
			if (adjMatrix[i][j] != adjMatrix[j][i])
				return 1;
	return 0;
}
bool isDirected2(vector<vector<int>> adjList)
{
	bool check;
	for (int i = 0; i < adjList.size(); i++)
		for (int j = 0; j < adjList[i].size(); j++) {
			for (int j = 0; j < adjList[i].size(); j++)
			{
				check = false;
				for (int k = 0; k < adjList[adjList[i][j]].size(); k++)
					if (i == adjList[adjList[i][j]][k])
					{
						check = true;
						break;
					}
				if (check == false)
					return 1;
			}
			return 0;
		}
}
void show(vector<vector<int>> adjList)
{
	for (int i = 0; i < adjList.size(); i++) {
		for (int i = 0; i < adjList.size(); i++)
		{
			for (int j = 0; j < adjList[i].size(); j++)
				cout << adjList[i][j] << " ";
			cout << endl;
		}
	}

}
int numberOfVertices(vector<vector<int>> adjList)
{
	return adjList.size();
}
int numberOfEdge1(vector<vector<int>> adjmaTrix)
{
	int sum = 0;
	for (int i = 0; i < adjmaTrix.size(); i++)
		for (int j = 0; j < adjmaTrix[i].size(); j++)
			if (adjmaTrix[i][j] == 1)
				sum++;
	if (isDirected1(adjmaTrix))
		return sum;
	return sum / 2;
}
int numberOfEdge2(vector<vector<int>> adjList)
{
	int sum = 0;
	for (int i = 0; i < adjList.size(); i++)
		sum += adjList[i].size();
	if (isDirected2(adjList))
		return sum;
	return sum / 2;
}
int outDegree1(vector<vector<int>> adjMatrix, int vertex)
{
	return count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1);

}
int outDegree2(vector<vector<int>> adjList, int vertex)
{
	return adjList[vertex].size();
}
int inDegreeOf1(vector<vector<int>> adjMatrix, int vertex)
{
	int count = 0;
	for (int i = 0; i < adjMatrix.size(); i++)
		if (adjMatrix[i][vertex])
			count++;
	return count;
}
int inDegreeOf2(vector<vector<int>> adjList, int vertex)
{
	int sum = 0;
	for (int i = 0; i < adjList.size(); i++)
		sum += count(adjList[i].begin(), adjList[i].end(), vertex);
	return sum;
}
int degreeOf1(vector<vector<int>> adjMatrix, int vertex)
{
	if (isDirected1(adjMatrix))
		return inDegreeOf1(adjMatrix, vertex) + outDegree1(adjMatrix, vertex);
	return count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1);
}
int degreeOf2(vector<vector<int>> adjList, int vertex)
{
	if (isDirected2(adjList))
		return inDegreeOf2(adjList, vertex) + outDegree1(adjList, vertex);
	return adjList[vertex].size();
}
//isolated: dinh co lap khong noi voi dinh khac(bac 0)
//leaf vertex la dinh chi noi voi 1 dinh khac duy nhat(bac=1)
// neu bac = 1 thi co the la dinh treo hoac laf dinh colap
vector<int> listOfIsolated1(vector<vector<int>> adjMatrix)
{
	vector<int> isolatedVertices;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 0)
			isolatedVertices.push_back(i);
		if (count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 1 && adjMatrix[i][i] == 1)
			isolatedVertices.push_back(i);
	}
	return isolatedVertices;
}
vector<int> listOfIsolated2(vector<vector<int>> adjList)
{
	vector<int> isolatedVertices;
	for (int i = 0; i < adjList.size(); i++)
	{
		if (adjList[i].size() == 0)
			isolatedVertices.push_back(i);
		if (adjList[i].size() == 1)
			if (adjList[i][0] = i)
				isolatedVertices.push_back(i);
	}
	return isolatedVertices;
}
vector<int> listOfLeaf1(vector<vector<int>> adjMatrix)
{
	vector<int> leafVertices;
	for (int i = 0; i < adjMatrix.size(); i++)
	{
		if (count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 1 && adjMatrix[i][i] != 1)
			leafVertices.push_back(i);
		if (count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) == 2 && adjMatrix[i][i] == 1)
			leafVertices.push_back(i);
	}
	return leafVertices;
}
vector<int> listOfLeaf2(vector<vector<int>> adjList)
{
	vector<int> leafVertices;
	for (int i = 0; i < adjList.size(); i++)
	{
		if (adjList[i].size() == 1 && adjList[i][0] != i)
			leafVertices.push_back(i);
		if (adjList[i].size() == 2)
			if (adjList[i][0] == i || adjList[i][1] == i)
				leafVertices.push_back(i);
	}
	return leafVertices;
}
// doi thi hoan chinh: giua hai dinh bat ki luon co canh noi, khong noi voi chinh no, vo huong
bool isCompletedGraph2(vector<vector<int>> adjList)
{// xet khuyen

	for (int i = 0; i < adjList.size(); i++)
		if (adjList[i].size() != adjList.size() - 1)
			return false;
	return true;
}
bool isCompletedGraph1(vector<vector<int>> adjMatrix)
{
	for (int i = 0; i < adjMatrix.size(); i++)
		if (adjMatrix[i][i] != 0 || count(adjMatrix[i].begin(), adjMatrix[i].end(), 1) != adjMatrix.size())
			return false;
	return true;
}
bool isCicularGraph1(vector<vector<int>> adjMatrix)
{
	int vertex;
	vector <bool> check(adjMatrix.size(), false);
	queue <int> q;
	q.push(0);
	check[0] = true;
	while (!q.empty())
	{
		vertex = q.front();
		q.pop();
		if (count(adjMatrix[vertex].begin(), adjMatrix[vertex].end(), 1) != 2)
			return false;
		else {
			for (int j = 0; j < adjMatrix.size(); j++)
			{
				if (adjMatrix[vertex][j] == 1)
				{
					if (check[j] == false)
					{
						q.push(j);
						check[j] = true;
					}
				}
			}
		}
	}
	return true;
}
bool isCicularGraph2(vector<vector<int>> adjList)
{
	int vertex;
	vector <bool> check(adjList.size(), false);
	queue <int> q;
	q.push(0);
	check[0] = true;
	while (!q.empty())
	{
		vertex = q.front();
		q.pop();
		if (adjList[vertex].size() != 2)
			return false;
		else {
			if (check[adjList[vertex][0]] == false)
			{
				q.push(adjList[vertex][0]);
				adjList[vertex][0] = true;

			}
			if (check[adjList[vertex][1]] == false)
			{
				q.push(adjList[vertex][1]);
				adjList[vertex][1] = true;

			}
		}
	}
	return true;
}
// do thi phan doi(Bigraph) co the chia thanh 2 tap dinh (A) va (B) sao cho cac ddinh cua
//A khong noi duoc voi nhau va cac dinh cua B khong noi duoc voi nhau
bool biGraph2(vector<vector<int>> adjList)
{
	int v;
	queue <int> q;
	vector <int> color(adjList.size(), 0);
	q.push(0);
	color[0] = 1;
	while (!q.empty())
	{
		v = q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjList[v].size(); i++)
			{
				if (color[adjList[v][i]] == color[v])
					return false;
				if (color[adjList[v][i]] == 0)
				{
					color[adjList[v][i]] = -color[v];
					q.push(adjList[v][i]);
				}

			}
		}
		q.pop();
	}
	return true;
}
bool biGraph1(vector<vector<int>> adjMatrix)
{
	int v;
	queue <int> q;
	vector <int> color(adjMatrix.size(), 0);
	q.push(0);
	color[0] = 1;
	while (!q.empty())
	{
		v = q.front();
		if (color[v] != 0)
		{
			for (int i = 0; i < adjMatrix[v].size(); i++)
			{
				if (adjMatrix[v][i] && color[v] == color[i])
					return false;
				if (adjMatrix[v][i] && color[i] == 0)

				{
					color[i] = -color[v];
					q.push(i);
				}
			}
		}
		q.pop();
	}
	return true;
}
int dijkstra(vector<vector<int>> adjMatrix, int verStart, int verEnd)
{
	int n = adjMatrix.size();
	int* f = new int[n];
	bool* check = new bool[n];
	int* trace = new int[n];
	for (int i = 0; i < n; i++)
	{
		f[i] = MAX;
		check[i] = true;
		trace[i] = -1;
	}
	f[verStart] = 0;
	trace[verStart] = 0;
	int ver = verStart, min;
	while (ver != verEnd)
	{
		//tim ver
		min = MAX;
		for (int i = 0; i < n; i++)
			if (check[i] == true && min > f[i])
			{
				min = f[i];
				ver = i;
			}
		if (min == MAX)
			break;
		//xoa v khoi t2
		check[ver] = false;
		//toi uu cac dinh trong t2
		for (int i = 0; i < n; i++)
			if (adjMatrix[ver][i] > 0 && f[i] > f[ver] + adjMatrix[ver][i])
			{
				f[i] = f[ver] + adjMatrix[ver][i];
				trace[i] = ver;
			}
	}
	return f[verEnd];
}
int main()
{
	vector<vector<int>> adjList = toAdjList();
	vector<vector<int>> adjMatrix = toAdjMatrix();
	//cout << isDirected2(adjList);
	//show(adjList);
	//show(adjMatrix);
	//cout << numberOfEdge1(adjMatrix);
	//cout << numberOfEdge2(adjList);
//	cout << endl << numberOfVertices(adjList);
	//cout << isCicularGraph2(adjList);
	cout << dijkstra(adjMatrix, 4 ,1);
	return 0;
}
//9
//0 0 1 0 0 1 0 0 0
//0 0 0 0 0 0 1 0 0
//1 0 0 0 0 0 1 1 0
//0 0 0 0 1 1 0 0 0
//0 0 0 1 0 1 0 0 0
//1 0 0 1 1 0 0 1 0
//0 1 1 0 0 0 0 0 0
//0 0 1 0 0 1 0 0 1
//0 0 0 0 0 0 0 1 0