#include<iostream>
#include<stdlib.h>
using namespace std;
//node is a self refrential structure
struct node {
	 
	int data;
	node* link;
}*head, * curent, * add;

void delet(int p )
{
	 if(p==1)
	{ 
		 struct  node* point = head;
		 head = head->link;
		 delete point;
	}
	 else if (p == 4)
	 {
		 struct node* prev = head;
		 struct node* now = head;

		  while(now->link != NULL)
		 {
			  prev = now;
			  now = now->link;
          
		 }
		  prev->link = NULL;
		  delete now;
	 }

	 else if ((p == 2) || (p == 3))
	 {
		 struct node* prev = head;
		 struct node* now = head;

		 while (p>1)
		 {
			 prev = now;
			 now = now->link;
			 p--;
		 }
		 prev->link =now->link->link;
		 delete now;
	 }
}
void Insertion(struct node* pt, int p)
{
	if (p == 1)
	{
		pt->link = head;
		head = pt;
		
	}
	else if (p == 4)
	{
		pt->link = NULL;
		head->link->link->link = pt;
	}
	else if((p==2) ||(p==3))
	{
		struct node* now = head;
		 
		while (p > 1)
		{
			now = now->link;
			p--;
		}
		pt->link = now->link;
		now->link = pt;
	}

	
}
void search(int p)
{
	struct node* now = head;
	cout << "Data : ";
	if (p == 1)
	{
		cout << now->data;

	}
	else {

		while (p > 1)
		{
			now = now->link;
			p--;
		}
		cout << now->data;
	}


 }
void update(int p, int data)
{
	struct node* now = head;
	cout << "Data : ";
	if (p == 1)
	{
		 now->data=data;

	}
	else {

		while (p > 1)
		{
			now = now->link;
			p--;
		}
		  now->data=data;
	}


}
void print()
{
	struct node* now = head;
	while (now != NULL)
	{
		cout << now->data<<",";
		now = now->link;
		 
	}
	 
}
int main()
{    //first node
	head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of first node: ";
    cin >> head->data;
	head->link = NULL;

	//second node
	curent = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of second node: ";
	cin >> curent->data;
	curent->link = NULL;
	head->link = curent;

	//third node
	curent = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of third node: ";
	cin >> curent->data;
    curent->link = NULL;
	head->link->link = curent;

	//node to add
    add = (struct node*)malloc(sizeof(struct node));
	cout << "Enter the data of the node u want to add: ";
	cin >> add->data;
	add->link = NULL;
	int p;
	
	cout <<endl<< "Enter the position where u want to add( 1 | 2 | 3 | 4 )";
	cin >> p;
	if((p==2)||(p==3))
	{
		p=p-1;
	}
	Insertion(add, p );
	cout << endl;
	print();
	cout << endl << "Enter the position where u want to delete( 1 | 2 | 3 | 4 )";
	cin >> p;
	delet(p );
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
update(p,d);

cout << endl;
print();
	return 0;
}

