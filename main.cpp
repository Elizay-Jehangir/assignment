#include <iostream>
using namespace std;

class complexa
{
private:
    double a;
    double b;
public:
    void setData(double x,double y)
    { a=x; b=y; }
    /*void showData()
    {
        cout<<"\na is: "<<a<<" b is: "<<b<<endl;
    }*/
    complexa operator+(complexa c)
   {
        complexa temp;
        temp.a= a+c.a;
        temp.b= b+c.b;
        return temp;
    }
     complexa operator-(complexa c)
    {
        complexa temp;
        temp.a= a-c.a;
        temp.b= b-c.b;
        return temp;
    }
    complexa operator*(complexa c)
    {
        complexa temp;
        temp.a = (a*c.a) -  (b*c.b);
        temp.b = (a*c.b) + (b*c.a);
        return temp;
    }
    complexa operator/(complexa c)
    {
        complexa temp;
        temp.a = ((a*c.a) + (b*c.b))/(c.a*c.a - c.b*c.b);
        temp.b = ((b*c.a) - (a*c.b))/(c.a*c.a - c.b*c.b);
        return temp;
    }
   friend class linkedlist;
};

struct node{
complexa data;
node*next;
};

class linkedlist
{
private:
    node* head;
public:
    linkedlist()
    {
        head=NULL;
    }

void insertatend(complexa c)
{
    node *last = new node;
    last->data.a= c.a; last->data.b= c.b;
    last->next = NULL;

     if (head == NULL)
	 {
        head = last;
     }
	 else
	 {
        node *temp = new node;
        temp = head;
		while (temp->next != NULL)
		{
            temp = temp->next;
        }
        temp->next = last;
     }

}

	 void deleteatstart()
	 {
		node* temphead = new node;
		temphead -> next = head;
		head = head->next;
		delete temphead;
	}

void deleteatspecpos(int pos)
	{
		node* current = head;
		node* previous =head ;

		for(int i=0; i<pos-1 ;i++)
		{
			previous=current;
			current = current -> next;
		}
		previous -> next = current -> next;
		delete current;
}
void traverse()
	{
		node* temp = new node;
		temp = head;
		while(temp!=NULL)
		{
			cout << "("<<temp->data.a<<" + "<<temp->data.b<<"i ) ";
			temp=temp->next;
		}
		cout<<endl;
	}
};


int main()
{
    linkedlist l;
    complexa c1,c2,c3;
    c1.setData (-4,5);
    c2.setData (-3,-3);
    c3.setData (-4,3);
    //storing the 3 complex numbers in the list
    l.insertatend(c1);
    l.insertatend(c2);
    l.insertatend(c3);
        //displaying the list
        l.traverse();
    //now delete, we assume deleting at start
    l.deleteatstart();
    //adding the first two numbers and storing in list at last
    l.insertatend(c1+c2);
        //displaying the list
        l.traverse();
    //subtracting 1 and 3 and storing in the list at last
    l.insertatend(c1-c3);
        //displaying the list
        l.traverse();
    //multiplying 2 and 3 and storing in the list at last
    l.insertatend(c2*c3);
        //displaying the list
        l.traverse();

    //delete the element at 4
    l.deleteatspecpos(4);
        //displaying the list
        l.traverse();
    //dividing 1 and 3 and storing in the list at last
    l.insertatend(c1/c3);
        //displaying the list
        l.traverse();

    return 0;
}
