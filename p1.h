#include<string.h>
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<fstream>

static int count_avail = 0;//seat count_available
static int booked = 0; //seat count_booked
using namespace std;

struct avl_node
    {
    	string data;//seat num
        int avail;//0 free 1 booked
        struct avl_node *left;
        struct avl_node *right;
    }*root;
class avlTree
{	
    public:
        //avl code  -- all 3 members     
        int height(avl_node *);
		int diff(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, string );		
    	avl_node *minValNode(avl_node *);
    	avl_node *deleteNode(avl_node *, string);
        void inorder(avl_node *);
        avlTree()
        {
            root = NULL;
        }
        //user defined functions
		void search(avl_node *,string);//all 3 members
        void display(avl_node *, int);//Akila shree
		void displayavail(avl_node *ptr, int level);//Akila shree
		void displaybooked(avl_node *ptr, int );//Nandhini
		void booking(string &x);//Nandhini
		void cancel(string &x);//Madhu mitha
		void billing(int);//Madhu mitha
};
//------------------------------------------------------------------- AVL BASIC CODE ------------------------------------------------------------------------------
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avlTree::diff(avl_node *temp)
{
    if(temp == NULL)
    {
		return 0;
	}
		return (height (temp->left) - height (temp->right));

}
avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
        }
	    else if (bal_factor < -1)
	    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
	    }
    return temp;
}
avl_node *avlTree::insert(avl_node *root, string value)
{
    if (root == NULL)
    {
    
        root = new avl_node;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
		root->avail=0;//availability of seat set to 0 -- inserted seat set to 0
        ++count_avail;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
	root->avail=0;
    
    return root;
}
void avlTree::inorder(avl_node *tree)
{
    if (tree == NULL)
        return
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}
avl_node * avlTree::minValNode(avl_node * node) 
{
	avl_node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
avl_node * avlTree::deleteNode(avl_node *root, string data) 
{
	if(root == NULL)
		return(root);
	if(data<root->data)
		root->left = deleteNode(root->left, data);
	else if(data>root->data)
		root->right = deleteNode(root->right, data);
	else {
		if(root->left == NULL || root -> right == NULL) 
        {
			avl_node * t = root -> left ? root-> left : root->right;

			if(t == NULL) {
				t = root;
				root = NULL;
			}
			else
				*root = *t;
			free(t);
		}
		else
		{
			avl_node *t = minValNode(root->right);
			root->data = t->data;
			root->right = deleteNode(root->right, t->data);
		}
	}

	if(root==NULL)
		return(root);

	int balance = diff(root);

	if(balance > 1 && diff(root->left) >= 0)
		return(ll_rotation(root));

	if (balance > 1 && diff(root->left) < 0)
	{
		root->left = rr_rotation(root->left);
        return(ll_rotation(root));
	}

	if (balance < -1 && diff(root->right) <= 0)
	     return(rr_rotation(root));

	if (balance < -1 && diff(root->right) > 0)
	{
		root->right = ll_rotation(root->right);
        return(rr_rotation(root));
	}

	return(root);
}
//--------------------------------------------------------------------- USER DEFINED FUNCTIONS -------------------------------------------------------------------------
void avlTree::search(avl_node *root,string data)
{
    avl_node *temp=new avl_node;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
			if(temp->avail==0)
			{
				cout<<"\nTHE SEAT "<<data<<" IS AVAILABLE\n";
				break;
			}
			else if(temp->avail!=0)
			{
				cout<<"\nTHE SEAT "<<data<<" IS BOOKED\n";
				break;
			}
			else
			{
				cout<<"\nSORRY SEAT NOT AVAILABLE\n";
				break;
			}
        }
        else if(temp->data>data)
            temp=temp->left;
        else
            temp=temp->right;
    }
}
//-------------------------------------------------------------------------- AKILA SHREE S --------------------------------------------------------------------------
//display total seats in tree format
void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";//displaying in  tree format
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
//display available seats in tree format
void avlTree::displayavail(avl_node *ptr, int level)
{
	int i;
    if (ptr!=NULL)
    {
		if( ptr->avail == 0 || (ptr->left!=NULL || ptr->right!=NULL))
		{
			displayavail(ptr->right, level + 1);
			printf("\n");
			if (ptr == root)
			cout<<"Root -> ";
			for (i = 0; i < level && ptr != root; i++)
				cout<<"        ";
			if( ptr->avail == 0 )
			{
				cout<<ptr->data;
			}
			displayavail(ptr->left, level + 1);
		}
		
    }
}
//-------------------------------------------------------------------------- NANDHINI B --------------------------------------------------------------------------
//display booked seats in tree format
void avlTree::displaybooked(avl_node *ptr, int level)
{
	int i;
    if (ptr!=NULL)
    {
		if( ptr->avail !=0 || (ptr->left!=NULL || ptr->right!=NULL))
		{
			displaybooked(ptr->right, level + 1);
			printf("\n");
			if (ptr == root)
			cout<<"Root -> ";
			for (i = 0; i < level && ptr != root; i++)
				cout<<"        ";
			if( ptr->avail == 1 )
			{
				cout<<ptr->data;
			}
			displaybooked(ptr->left, level + 1);
		}
    }
}
//for user to book desired seats
void avlTree::booking(string &x)
{
	avl_node *temp=new avl_node;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {			
            if (temp->avail == 0)
			{
				temp->avail = 1;
				cout << "\nYOUR SEAT HAS BEEN BOOKED!\n";
				++booked;//incrementing the no of seats booked
                --count_avail;//decrementing available seat count
				return;
			}
            else if (temp->avail == 1 && temp->data==x)
            {
                cout<<"\nALREADY RESERVED TRY AGAIN\n";                
            }            
        }
        else if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    cout<<"\nSORRY SEAT NOT AVAILABLE\n";
}
//-------------------------------------------------------------------------- MADHU MITHA S --------------------------------------------------------------------------
//for user to cancel desired seat
void avlTree::cancel(string &x)
{
	avl_node *temp=new avl_node;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
			if (temp->avail == 1)
			{
				temp->avail = 0;
				cout << "\nYOUR SEAT HAS BEEN CANCELLED\n";
				--booked;//decrementing the no of seats booked
                ++count_avail;//incrementing the no of seats available
				return;
			}
            else
            {
                cout<<"\nSORRY YOU HAVEN'T BOOKED YOUR SEAT YET\n";
                break;
            }
        }
        else if(temp->data>x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    
}
//generates tickets based on booking count
void avlTree::billing(int c)
{
	cout<<"\t\t\t+-----------------------------------------------+\n";
    cout<<"\t\t\t|Price per Ticket:\t\t\t120\t|"<<endl;
    cout<<"\t\t\t|Total No of tickets booked:\t\t"<<c<<"\t|"<<endl;
	cout<<"\t\t\t+-----------------------------------------------+\n";
    cout<<"\t\t\t|Total Amount:\t\t\t"<<c <<" * 120"<<" = "<<c*120<<"\t|"<<endl;
	cout<<"\t\t\t+-----------------------------------------------+\n";
}

