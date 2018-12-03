#include <iostream>
using namespace std;
//class complexa;

class complexa
{
private:
    double a;
    double b;
public:
    void setData(double x,double y)
    { a=x; b=y; }
    void showData()
    {
        cout<<"\na is: "<<a<<" b is: "<<b<<endl;
    }
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
void deleteatspecpos(int pos)
	{
		node* current = head;
		node* previous =head ;

		for(int i=0; i<pos ;i++)
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
			cout << temp->data.a<<" + "<<temp->data.b<<"i"<<endl;
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

    l.insertatend(c1+c2);
    l.traverse();
    //c4.showData();

    l.insertatend(c1-c3);
    l.traverse();
    //c4.showData();

    l.insertatend(c2*c3);
    l.traverse();
    //c4.showData();
    l.deleteatspecpos(4);

    l.insertatend(c1/c3);
    l.traverse();
    //c4.showData();
    return 0;
}
