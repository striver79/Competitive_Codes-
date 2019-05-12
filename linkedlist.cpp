// http://btechsmartclass.com/DS/U2_T3.html
#include <bits/stdc++.h>
using namespace std;
typedef struct node
{
    int num;
    struct node *ptr;
}node;
node *head,*first,*temp=0;
void insert(int n)
{
    first=0;
    for (int i=0;i<n;i++)
    {
        head=new node;
        cin >> head->num;
        if(first!=0){temp->ptr=head;temp=head;}
        else first=temp=head;
        }
        temp->ptr=0;
}
void print()
{
    temp=first;
    while(temp!=0){cout << temp->num <<" ";temp=temp->ptr;}
    cout << endl;
}
void delete1(int x)
{
    temp=first;
    head=first;
    if(temp->num==x) { first=temp->ptr; return ;}
    while(temp!=0 && temp->num!=x)
    {
        head=temp;
        temp=temp->ptr;
    }
    head->ptr=temp->ptr;
   
    free(temp);
}
void add(int b)
{
    temp=first;
    while(temp->ptr !=0)
    temp=temp->ptr;
head=new node;
head->num=b;
temp->ptr=head;
temp=head;
temp->ptr=0;

}
int main() 
{
int n;
cin >> n;
insert(n);
print();
int m;
cin >> m;
delete1(m);
print();
add(8);
print();
return 0;
}