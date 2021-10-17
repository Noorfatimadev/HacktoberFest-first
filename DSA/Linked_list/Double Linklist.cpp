#include<iostream>
#include<stdlib.h>
using namespace std;
//node is a self refrential structure
struct node {

	int data;
	node* prev;
	node* next;
}*f, * c, * add;

void delet(int p)
{
	if (p == 1)
	{
		struct  node* point = f;
		f = f->next;
		f->prev = NULL;
		delete point;
	}
	else if (p == 4)
	{
		struct node* pre = f;
		struct node* now = f;

		while (now->next != NULL)
		{
			pre = now;
			now = now->next;
			now->prev = pre;

		}
		pre->next = NULL;
		delete now;
	}

	else if ((p == 2) || (p == 3))
	{
		struct node* pre = f;
		struct node* now = f;

		while (p > 1)
		{
			now = now->next;
         	p--;
		}
		pre = now->prev;
		pre->next = now->next;
		now->next->prev = pre;
		delete now;
	}
}
void Insertion(struct node* pt, int p)
{
	if (p == 1)
	{
		pt->next = f;
		f = pt;

	}
	else if (p == 4)
	{
		pt->next = NULL;
		f->next->next->next = pt;
		pt->prev = f->next->next;
	}
	else if ((p == 2) || (p == 3))
	{
		struct node* now = f;
		p--;
		while (p > 1)
		{
			now->prev = now;
			now = now->next;
			p--;

		}
		pt->next = now->next;
		now->next = pt;
		pt->prev = now;
	}

}

void search(int p)
{
	struct node* now = f;
	cout << "Data : ";
	if (p == 1)
	{
		cout << now->data;

	}
	else {

		while (p > 1)
		{
		 
			now = now->next;
			p--;
		}
		cout << now->data;
	}


}
void update(int p, int d)
{
	struct node* now = f;

	if (p == 1)
	{
		now->data = d;

	}
	else {

		while (p > 1)//for 3 position it will make 2 jumps and 1 jump for position 2
		{
			now->prev = now;	 ///  will store the previous node
			now = now->next;//now  will store the next node

			p--;
		}
		now->data = d;
	}


}
void print()
{
	struct node* now = f;
	while (now  != NULL)
	{
		cout << now->data << ",";
		 		 
		now = now->next;


	}

	cout << "\b";
}
int main()
{    //first node
	f = NULL;
	f = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of first node: ";
	cin >> f->data;
	f->prev = NULL;
	f->next = NULL;

	//second node
	c = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of second node: ";
	cin >> c->data;
	c->next = NULL;
	f->next = c;
	c->prev = f;
	//third node
	c = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of third node: ";
	cin >> c->data;
	c->next = NULL;
	f->next->next = c;
	c->prev = f->next;

	//node to add
	add = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of the node u want to add: ";
	cin >> add->data;
	add->next = NULL;
	add->prev = NULL;
	int p;

	cout << endl << "Enter the position where u want to add( 1 | 2 | 3 | 4 )";
	cin >> p;

	Insertion(add, p);
	cout << endl;
	print();
	cout << endl << "Enter the position where u want to delete( 1 | 2 | 3 | 4 )";
	cin >> p;
	delet(p);
	cout << endl;
	print();
	cout << endl << "Enter the position u want to search the data of ( 1 | 2 | 3  )";
	cin >> p;
	search(p);
	cout << endl << "Enter the position u want to update the data of ( 1 | 2 | 3  )";
	cin >> p;
	int d;
	cout << endl << "Enter the data u want to update ";
	cin >> d;
	update(p, d);

	cout << endl;
	print();
	return 0;
}

