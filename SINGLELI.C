#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
int a;
struct node *p;
};
struct node *header;
void create(int);
void show();

void add_first(int);
void add_last(int);
void del_first();
void del_last();
void del_value(int);
void reverse();
void shorted();
void sorted(int);
int count();
void reverse2(int);
void reverse3(int);
void modify();
void modify1();
void pair_wise();
void modify3();
//void alt_del();
void alt_del2(int,int);
//int mid();
//void search(int);
//void swap();
void main()
{
int c;
clrscr();
header=NULL;
create(5);
create(6);
create(8);
create(9);
create(2);
create(3);
create(1);
create(4);
create(7);
printf("link list is\n");
show();
//swap();
//show();
add_first(10);
printf("\nadd first is\n");
show();
add_last(11);
printf("\nadd last is\n");
show();
del_first();
printf("\nafter delete a first node link list is\n");
show();
del_last();
printf("\nafter deleting last node new link list is\n");
show();
del_value(8);
printf("\nafter deleting value link list is\n");
show();
reverse();
printf("\nafter reverse the list new link list is\n");
show();
shorted();
printf("\nafter shorting new link list is\n");
show();
sorted(8);
printf("\nafter insert element sorted list is\n");
show();
c=count();
printf("\n no of element is %d",c);
reverse2(6);
printf("\nreverse after entred value\n");
show();
reverse3(2);
printf("\nreverse from by user value\n");
show();
printf("\n-----------*-----------*-------------*-----------*---\n");
printf("compny code section\n");
modify();
printf("\ncollect odd position node at first and then even position node\n");
show();
modify1();
printf("\nreverse the even position node\n");
show();
pair_wise();
printf("\nlink list after pair wise swapping\n");
show();
modify3();
printf("\nafter move last element to front link list is\n");
show();
//alt_del();
/*alt_del2(3,2);
printf("\nafter delete alternate position\n");
show();*/
//mid();
//search(4);
getch();
}

void create(int t)
{
struct node *temp,*t1;
temp=(struct node*)malloc(sizeof(struct node));
temp->a=t;
temp->p=NULL;
if(header==NULL)
header=temp;
else
{
t1=header;
while(t1->p!=NULL)
{
t1=t1->p;
}
t1->p=temp;
}
}
 void show()
 {
 struct node *t=header;
 while(t!=NULL)
 {
 printf("->%d",t->a);
 t=t->p;
 }
 }
void add_first(int t)
{
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->a=t;
temp->p=header;
header=temp;
}
void add_last(int t)
{
struct node *temp,*t1;
temp=(struct node *)malloc(sizeof(struct node));
temp->a=t;
t1=header;
while(t1->p!=NULL)
{
t1=t1->p;
 }
t1->p=temp;
temp->p=NULL;
}

void del_first()
{
if(header==NULL)
{
printf("list is empty\n");
return;
}
else
{
header=header->p;
}
}
void del_last()
{
struct node *temp,*prev;
if(header==NULL)
{
printf("list is empty\n");
return;
}
if(header->p==NULL)
{
header=NULL;
}
else
{
temp=header;
while(temp->p!=NULL)
{
prev=temp;
temp=temp->p;
}
prev->p=NULL;
}
}
void del_value(int t)
{
struct node *temp,*prev;
if(header->a==t)
{
header=header->p;
}
else
{
temp=header;
while(temp!=NULL)
{
if(temp->a==t)
{
prev->p=temp->p;
break;
}
else
{
prev=temp;
temp=temp->p;
}}}}
void reverse()
{
struct node *prev,*curr,*nxt;
prev=NULL;
curr=header;
while(curr!=NULL)
{
nxt=curr->p;
curr->p=prev;
prev=curr;
curr=nxt;
header=prev;
}
}
void shorted()
{
struct node *ptr, *ctr;
int temp;
ptr=header;
while(ptr->p!=NULL)
{
ctr=ptr->p;
while(ctr!=NULL)
{
if(ptr->a > ctr->a)
{
temp=ptr->a;
ptr->a=ctr->a;
ctr->a=temp;
}
else
{
ctr=ctr->p;
}
}
ptr=ptr->p;
}
}
void sorted(int t)
{
struct node *temp,*t1;
temp=(struct node *)malloc(sizeof(struct node));
temp->a=t;
if(header==NULL||header->a > t)
{
temp->p=header;
header=temp;
}
else
{
t1=header;
while(t1!=NULL)
{
if(t1->a<t && t1->p->a > t ||t1->p==NULL)
{
temp->p=t1->p;
t1->p=temp;
break;
}
else
{
t1=t1->p;
}
}
}
}
int count()
{
int c=0;
struct node *t=header;
while(t!=NULL)
{
t=t->p;
c++;
}
return c;
}
void reverse2(int t)
{
int count=0;
struct node *prev,*curr,*nxt;
prev=NULL;
curr=header;
while(curr!=NULL && count<t)
{
nxt=curr->p;
curr->p=prev;
prev=curr;
curr=nxt;
count++;
}
if(nxt!=NULL)
header->p=curr;
header=prev;
}

void reverse3(int t)
{
int count=0;
struct node *prev,*curr,*nxt;
prev=NULL;
curr=header;
while(curr!=NULL && count<t)
{
nxt=curr->p;
curr->p=prev;
prev=curr;
curr=nxt;
count++;
}
header=prev;
while(count<t-1&&count!=NULL)
{
curr=curr->p;
count++;
}
if(curr!=NULL)
{
nxt=curr->p;
curr->p=prev;
prev=curr;
curr=nxt;


} }
//function for change the position of node
void modify()
{
struct node *p1,*p2,*temp;
if(header==NULL||header->p==NULL||header->p->p==NULL)
return;
p1=header;
p2=p1->p;
p1->p=p2->p;
temp=p2;
p1=p1->p;
while(p1->p !=NULL &&p1!=NULL)
{
p2->p=p1->p;
p2=p2->p;
if(p2->p==NULL)
{
p1->p=temp;
break;
}
p1->p=p2->p;
p1=p1->p;
}
if(p1->p==NULL)
{
p2->p=NULL;
p1->p=temp;
}
}
 void modify1()
 {
 struct node *p1,*p2,*temp;
if(header==NULL||header->p==NULL||header->p->p==NULL)
return;
p1=header;
p2=p1->p;
p1->p=p2->p;
p2->p=NULL;
p1=p1->p;
while(p1->p!=NULL && p1!=NULL)
{
temp=p1->p->p;
p1->p->p=p2;
p2=p1->p;
if(temp==NULL)
{
p1->p=p2;
break;
}
else
{
p1->p=temp;
p1=p1->p;
}   }
if(p1->p==NULL)
{
p1->p=p2;
}}
void pair_wise()
{
struct node *f,*s,*th;
f=header;
s=f->p;
header=s;
while(1)
{
th=s->p;
s->p=f;
if(th==NULL || th->p==NULL)
{
f->p=th;
break;
}
f->p=th->p;
f=th;
s=th->p;
}}
/*
 void swap()
 {
 struct node *p1,*c1,*p2,*c2,*temp;
 int x,y;
 p1=p2=NULL;
 c1=c2=header;

 printf("\nentre the value\n");
 scanf("%d%d",&x,&y);
 if(x==y)
 return;
 while(c1->a!=x && c1!=NULL)
 {
 p1=c1;
 c1=c1->p;
 }
 while(c2->a!=y && c2!=NULL)
 {
 p2=c2;
 c2=c2->p;
 }
 if(c1==NULL || c2==NULL)
 return;
 if(p1!=header)
 p1->p=c2;
 else
 header=c2;
 if(p2!=header)

 p2->p=c1;
 else
 header=c1;

 temp=c2->p;
 c2->p=c1->p;
 c1->p=temp;
 }
 void search(int t)
 {
 struct node *temp;
 temp=header;
 while(temp!=NULL)
{
 if(temp->a==t)
 {
 printf("element found");
 return;
 }
 temp=temp->p;
 }
 printf("element not found");
 }
 int mid()
 {
 struct node *p1,*p2;
 p1=p2=header;
 while(p1!=NULL&&p2!=NULL&&p2->p!=NULL)
 {
 p1=p1->p;
 p2=p2->p->p;
 }
 printf("\nmid element id %d\n",p1->a);
 }  */
 //function to move last element to front
 void modify3()
 {
 struct node *temp,*prev;
 temp=header;
 while(temp->p!=NULL)
 {
 prev=temp;
 temp=temp->p;
 }
 prev->p=NULL;
 temp->p=header;
 header=temp;
 }  /*
 void alt_del()
 {
 struct node *f,*s;
 f=header;
 s=header->p;
 while(f!=NULL&&s!=NULL)
 {
 f->p=s->p;
 f=f->p;
 s=f->p;
 }
 }
 void alt_del2(int m,int n)
 {
 int count =0,ct=0;
 struct node *curr,*temp,*t;
 curr=header;
 while(curr!=NULL)
 {
 for(count=1;count<m;count++)
 curr=curr->p;
 t=curr->p;
 for(ct=1;ct<=n;ct++)
 {
 temp=t;
 t=t->p;
 }
 curr->p=t;
 curr=t;
 }
 }    */
