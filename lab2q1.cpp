/*Implement Singly Linked List using C++. Make sure the following functions: 
insert(int data) - Adds a new element to the end of the linked list. 
insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.  
Example: insertAt(1, 3) - inserts 3 at the first position. 
	It should print a statement “Linked List does not have that many elements” if the position does not exist in the linked list.   
delete() - Deletes the element at the end of the list. 
deleteAt(int pos) - Deletes the element(or node) at the position pos)
countItems() - Returns the number of items in the linked list. 
display() - Displays all the elements in the linked list. Format should be followed as “1 -> 2 -> 3 -> 4 -> NULL” for a linked list holding integers in the order 1,2,3,4. 
*/
//library
#include<iostream>
using namespace std;
class node
{
	public:
	//declare data
	int data;
	//declare a pointer which links to the next circle
	node * next;
	//a constructor that sets the value of next to null
	node()
	{
		next = NULL;
	}
};
class linkedlist
{
	public:
	//declare head and tail pointers
	node * head;
	node * tail;
	//constructor
	linkedlist()
	{
		head = NULL;
		tail = NULL;
	}
	//function that adds new elements at the end of the linked list
	void insert(int value)
	{
		//create the pointer that points to the class node
		node * temp = new node;
		//store the value in the data of the new pointer
		temp->data = value;
		//insert the value in the first node
		if(head == NULL)
		{
			head = temp;
		}
		// insert the value in any other node
		else
		{
			tail->next = temp;
		}
		tail = temp;
	}
	void insertat(int pos, int value)
	{
		//create a pointer that points to node
		node * current = head;
		int i = 0;
		while(i<pos)
		{
			i++;
			if(current->next==NULL)
			{
				cout<<"Linked list does not have that many elements!"<<endl;
				break;
			}
			else
			{
			current = current->next;
			}
		}
		//create a node
		node * temp = new node;
		temp->data = value;
		temp->next = current->next;
		current->next = temp;
	}
	//deletion of last element
	void del(){
		//store the tail in temp
		node * temp = tail;
		//before tail has to point to null
		node * current = head;
		while(current->next != tail){
			current = current->next;
		}
		current->next = NULL;
		//update  tail
		tail = current;
		//delete temp
		delete temp;
	}
	//to delete the element at a particular position
	void delat(int pos)
	{
		node * current = head;
		for(int i=1; i<(pos-1);i++)
		{
			current = current->next;
		}
		node * temp;
		temp=current->next;
		current->next=temp->next;
		delete temp;
	}
	//return the number of items in the linked list
	void countitems()
	{
		int i = 0;
		node * current = head;
		while(current != NULL)
		{
			i++;
			current = current->next;
		}
		cout<<i<<endl;
	}
	//display
	void display(){
	node * current = head;
	while(current != NULL){
		cout<<current->data<<"->";
		current = current->next;
		}
	cout<<endl;
	}
};
//write the main function
int main()
{
	linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.countitems();
	l1.delat(2);
	l1.del();
	l1.display();
	return 0;
}
	
