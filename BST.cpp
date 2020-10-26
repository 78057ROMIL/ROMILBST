#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;


class node
{
	public:
	int data;
	node *L;
	node *R;
};
class Q
{
	node* a[30];
	public:
	int first,last;
	Q()
	{
	first=last=-1;
	}
	~Q()
	{ }
	void eq(node *t)
	{
	if(first==-1)
	{
	first=last=0;
	a[last++]=t;
	}
	else if(last==29)
	{
	cout<<"\n Queue full !!!";
	exit(1);
	}
	else
	{
	a[last++]=t;
	}
	}

	node* dq()
	{
	if(first==-1)
	{
	cout<<"\n Queue Empty !!!";
	}
	node *k;
	if(first==last)
	{
	k=a[first];
	first=last=-1;
	}
	else
	{
	k=a[first++];
	}
	return k;
	}
};

class BST
{
	public:
	node *temp,*temp1,*temp2,*root=NULL;
	int leaf,nonLeaf;
	BST()
	{
	leaf=nonLeaf=0;
	}
	void insert();
	void deleteCopying(node *,int);
	void deleteMerging(node *,int);
	void delmerge(node *&);
	void delcopy(node *&);
	void search(int);
	void searchMerging(int);
	void preorder(node *);
	void postorder(node *);
	void inorder(node *);
	void bfs_treversal(node *);
	void leaf_nonLeaf(node *);
	int height(node *);
	void mirrorImage(node *);
};

void BST::insert()
{
	int i;
	cout<<"\n Enter the node value ( 0 to exit ) : ";
	cin>>i;
	while(i!=0)
	{
	temp=new node;
	temp->data=i;
	temp->L=temp->R=NULL;

	if(root==NULL)
	{
	root=temp;
	}
	else
	{
	temp1=root;
	while(temp1!=NULL)
	{
	if(i<temp1->data)
	{
	temp2=temp1;
	temp1=temp1->L;
	}
	else
	{
	temp2=temp1;
	temp1=temp1->R;
	}
	}
	if(i<temp2->data)
	{
	temp2->L=temp;
	}
	else
	{
	temp2->R=temp;
	}
	}
	cout<<"\n Enter the node value ( 0 to exit ) : ";
	cin>>i;
	}
}

void BST::postorder(node *t)
{
	if(t!=NULL)
	{
	postorder(t->L);
	postorder(t->R);
	cout<<" "<<t->data;
	}
}

void BST::preorder(node *t)
{
	if(t!=NULL)
	{
	cout<<" "<<t->data;
	preorder(t->L);
	preorder(t->R);
	}
}

void BST::inorder(node *t)
{
	if(t!=NULL)
	{
	inorder(t->L);
	cout<<" "<<t->data;
	inorder(t->R);
	}
}

void BST::bfs_treversal(node *t)
{
	Q q;
	if(t!=NULL)
	{
	q.eq(t);
	while(q.first!=-1)
	{
	t=q.dq();
	cout<<" "<<t->data;
	if(t->L!=NULL)
	q.eq(t->L);
	if(t->R!=NULL)
	q.eq(t->R);
	}
	}
}

void BST::leaf_nonLeaf(node *t)
{
	if(t!=NULL)
	{
	if(t->L==0 && t->R==0)
	leaf++;
	else
	nonLeaf++;
	leaf_nonLeaf(t->L);
	leaf_nonLeaf(t->R);
	}
}

void BST::search(int el)
{
	int flag=0;
	temp=root;
	while(temp)
	{
	if(el==temp->data)
	{
	flag=1;
	break;
	}
	else if(el<temp->data)
	{
	temp=temp->L;
	}
	else
	{
	temp=temp->R;
	}
	}
	if(flag==1)
	{
	cout<<"\n Element found !";
	}
	else
	{
	cout<<"\n Element not found !!!";
	}
}


int BST::height(node *t)
{
	if(t==NULL)
	return 0;
	int lheight=height(t->L);
	int rheight=height(t->R);
	if(lheight>rheight)
	return lheight+1;
	else
	return rheight+1;
}

void BST::mirrorImage(node *t)
{
	if(t==NULL)
	return;
	else
	{
	mirrorImage(t->L);
	mirrorImage(t->R);

	temp=t->L;
	t->L=t->R;
	t->R=temp;
	}
}

void BST::deleteCopying(node *t,int el)
{
	node *prev=NULL;
	while(t!=NULL)
	{
	if(t->data==el)
	break;
	prev=t;
	if(t->data<el)
	t=t->R;
	else
	t=t->L;
	}
	if(t!=NULL && t->data==el)
	{
	if(t==root)
	delcopy(root);
	else if(prev->L==t)
	delcopy(prev->L);
	else
	delcopy(prev->R);
	}
	else if(root!=0)
	cout<<"\n KEY "<<el<<" is not in the tree";
	else
	cout<<"\n Tree is Empty";
}

void BST::delcopy(node *&t1)
{
	node *prev,*tmp=t1;
	if(t1->R==NULL)
	t1=t1->L;
	else if(t1->L==NULL)
	t1=t1->R;
	else
	{
	tmp=t1->L;
	prev=t1;
	while(tmp->R!=NULL)
	{
	prev=tmp;
	tmp=tmp->R;
	}
	t1->data=tmp->data;
	if(prev==t1)
	prev->L=tmp->L;
	else
	prev->R=tmp->L;
	}
	delete tmp;
}

void BST::deleteMerging(node *t,int el)
{
	node *prev=NULL;
	while(t!=NULL)
	{
	if(t->data==el)
	break;
	prev=t;
	if(t->data<el)
	t=t->R;
	else
	t=t->L;
	}
	if(t!=NULL && t->data==el)
	{
	if(t==root)
	delcopy(root);
	else if(prev->L==t)
	delcopy(prev->L);
	else
	delcopy(prev->R);
	}
	else if(root!=0)
	cout<<"\n KEY "<<el<<" is not in the tree";
	else
	cout<<"\n Tree is Empty";
}

void BST::delmerge(node *&t1)
{
	node *tmp=t1;
	if(t1!=NULL)
	{
	if(!t1->R)
	t1=t1->L;
	else if(!t1->L)
	t1=t1->R;
	else
	{
	tmp=t1->L;
	while(tmp->R!=NULL)
	{
	tmp=tmp->R;
	}
	tmp->R=t1->R;
	tmp=t1;
	t1=t1->L;
 }
	delete tmp;
	}
}

int main()
{
	BST ob;
	int ch,n,el;
	do
	{
	cout<<"\n -------------MAIN MENU---------------";
	cout<<"\n 1. Insertion";
	cout<<"\n 2. Deletion by Copying";
	cout<<"\n 3. Deletion by Merging";
	cout<<"\n 4. Search";
	cout<<"\n 5. Inorder, preorder and postorder treversals";
	cout<<"\n 6. bfs Treversal";
	cout<<"\n 7. Leaf and Non-Leaf nodes";
	cout<<"\n 8. Height";
	cout<<"\n 9. Mirror Image";
	cout<<"\n Enter your choice ( 0 to exit ) : ";
	cin>>ch;

	switch(ch)
	{
	case 1:
	ob.insert();
	break;
	case 2:
	cout<<"\n Enter the key to be deleted : ";
	cin>>el;
	ob.deleteCopying(ob.root,el);
	break;
	case 3:
	cout<<"\n Enter the key to be deleted : ";
	cin>>el;
	ob.deleteMerging(ob.root,el);
	break;
	case 4:
	cout<<"\n Enter the key to be serched : ";
	cin>>el;
	ob.search(el);
	break;
	case 5:
	cout<<"\n Inorder :";
	ob.inorder(ob.root);
	cout<<"\n Preorder :";
	ob.preorder(ob.root);
	cout<<"\n Postorder :";
	ob.postorder(ob.root);
	break;
	case 6:
	cout<<"\n BFS Treversal :";
	ob.bfs_treversal(ob.root);
	break;
	case 7:
	ob.leaf_nonLeaf(ob.root);
	cout<<"\n LEAF : "<<ob.leaf;
	cout<<"\n NON-LEAF : "<<ob.nonLeaf;
	break;
	case 8:
	el=ob.height(ob.root);
	cout<<"\n Height : "<<el;
	break;
	case 9:
	ob.mirrorImage(ob.root);
	cout<<"\n Tree Inverted Successfully !";
	break;
	default :
	break;
	}
	}while(ch!=0);
return 0;
}
