#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{
int a;
struct node *r,*l;
};
struct node *root;
 int height(struct node *);
  struct node *mknode(int );
void preorder(struct node*);
 struct node *r_rotate(struct node *);
 struct node *l_rotate(struct node *);
struct node *create(struct node *,int);
void main()
{
clrscr();
root=create(root,3);
root=create(root,5);
root=create(root,11);
root=create(root,8);
root=create(root,4);
root=create(root,1);
root=create(root,12);
root=create(root,7);
root=create(root,2);
root=create(root,6);
root=create(root,10);
printf("tree is\n");

preorder(root);
getch();
}
struct node *create(struct node *p,int t)
{
int bf;
if(p==NULL)
return mknode(t);
if (t>p->a)
p->r=create(p->r,t);
else
p->l=create(p->l,t);
bf=height(p->l)-height(p->r);
if(bf>1&&t<p->l->a)
{
return r_rotate(p);
}
if(bf<-1&&t>p->r->a)
{
return l_rotate(p);
}
if(bf>1&&t>p->l->a)
{
p->l=l_rotate(p->l);
return r_rotate(p);
}
if(bf<-1&&t<p->r->a)
{
 p->r=r_rotate(p->r);
 return l_rotate(p);
 }
 return p;
 }
 struct node *mknode(int t)
 {
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->a=t;
 temp->r=NULL;
 temp->l=NULL;
 return temp;
 }
 struct node *l_rotate(struct node *p)
 {
 struct node *temp;
 temp=p->r;
 p->r=temp->l;
 temp->l=p;
 return temp;
 }
 struct node *r_rotate(struct node *p)
 {
 struct node *temp;
 temp=p->l;
 p->l=temp->r;
 temp->r=p;
 return temp;
 }
 int height(struct node *p)
 {
 int l1,r1;
 if(p==NULL)
 return 0;

 l1=height(p->l);
 r1=height(p->r);
 if(l1>r1)
 return (l1+1);
 else
 return (r1+1);
 }
 void preorder(struct node *p)
 {
 if(p==NULL)
 return;
 printf(" %d",p->a);
 preorder(p->l);
 preorder(p->r);
 }