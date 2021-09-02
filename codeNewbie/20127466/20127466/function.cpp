#include"function.h"

Node* createNode(flight value) {
    Node* temp = new Node;
    temp->data = value;
    temp->pnext = NULL;
    return temp;
}
void initlist(mylist& l)
{
    l.phead = NULL;
}

bool checkEmpty(mylist l) {
    if (l.phead == NULL)
        return true;
    return false;
}
void addTail(mylist& l, Node* p) {
    if (checkEmpty(l)) {
        l.phead = p;
    }
    else {
        
        Node* temp = l.phead;
        while (temp->pnext != NULL) {
            temp = temp->pnext;
        }
        temp->pnext = p;
    }
}
void inputflight(mylist &l) 
{  
    int n = rand() % 11 + 10;
   flight f;
   Node* p;
   for (int i = 0; i < 4; i++) 
   {
       cout << "eter id: ";
       cin >> f.id;
       cout << "enter day: ";
       cin >> f.day.d;
       cout << "enter month: ";
       cin >> f.day.m;
       cout << "enter year: ";
       cin >> f.day.y;
       cout << "enter capacity: ";
       cin >> f.capacity;
       cin.ignore();
       cout << "enter name: ";
       cin.getline(f.name, 50);

       p = createNode(f);
       addTail(l, p);
   }
}
int sumCapacity(mylist l)
{
    int sum = 0;
    for (Node* i = l.phead; i != NULL; i = i->pnext)
    {
        if (i->data.day.y == 2021)
        {
            if (i->data.day.m == 1 || i->data.day.m == 2 || i->data.day.m == 3)
                sum = sum + i->data.capacity;
        }
    }
    return sum;
}

void removeUnder(mylist& l)
{

    while (l.phead != NULL && l.phead->data.capacity < 100)
    {
        {
            Node* p = l.phead;
            l.phead = l.phead->pnext;
            delete p;
        }
    }
  
    Node* g = l.phead;

    while (g != NULL && g->pnext != NULL)
    {
        if (g->pnext->data.capacity < 100)
        {
            Node* next = g->pnext->pnext;
            delete g->pnext;
            g->pnext = next;
        }
    }
}
void printList(mylist l)
{
    if (l.phead == NULL)
    {
        cout << "\nNULL";
        return;
    }
    for (Node* i = l.phead; i != NULL; i = i->pnext)
    {
        cout << "\nid: " << i->data.id;
        cout << "\nname: " << i->data.name;
        cout << "\nday:" << i->data.day.d;
        cout << "\ncapacity: " << i->data.capacity << endl;
    }
}
void printfIndex6(mylist l, int k)
{
    int idx = 0;
    for (Node* i = l.phead; i != NULL; i = i->pnext)
    {
       
        if (idx == k - 1);
        {
            cout << "\nid: " << i->data.id;
            cout << "\nname: " << i->data.name;
            cout << "\nday:" << i->data.day.d << "/" << i->data.day.m << "/" << i->data.day.y;
            cout << "\ncapacity: " << i->data.capacity << endl;
            return;
        }
        idx++;
    }
}
int findMaxCapacity(mylist l)
{
   
    int max = 0;
    for (Node* i = l.phead; i != NULL; i = i->pnext)
    {
        if (i->data.capacity > max)
            max = i->data.capacity;
    }
    return max;
}