#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//Node class
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
};

//Tree class
class Tree
{
   public: Node* root;
   //Constructor
   public: Tree()
   {
     root=NULL;  
   }
   //Function to insert
   public: void insert(int data)
   {
       Node* new_node=new Node();
       new_node->data=data;
       new_node->right=NULL;
       new_node->left=NULL;
       
       if(root==NULL)
         root=new_node;
       else
       {
           Node* current=root;
           Node* prev=root;
           //Loop to find right place
           while(current!=NULL)
           {
               prev=current;
               if(current->data==data)
               cout<<"Dublication";
               else if(current->data<data)
                current=current->right;
               else
                current=current->left;
           }
           
           //Linking new node 
           if(prev->data<data)
            prev->right=new_node;
           else
            prev->left=new_node;
       }
   }
   
   
   //Function to display
   public: void display(Node* root)
   {
       if(root==NULL)
       return;
       else
       {
       display(root->left);
       cout<<root->data<<" \n";
       display(root->right);
       }
   }
   
   int maxHeight(Node* root)
   {
    if (root == NULL)
        return -1;
    else
    {
        //Compute the Height of each subtree
        int lHeight = maxHeight(root->left);
        int rHeight  = maxHeight(root->right);
     	return max(lHeight,rHeight)+1;
    }
   }
//-------------------------------------------------------TASK 1-----------------------------------------------------------------------------------------------------
   int maximum(int n1,int n2,int n3)
   {
   		int m;
   		if(n1 > n2)
    	{
        	if(n1 > n3)
        	{
        	    m = n1;
        	}
        	else
        	{
        	    m = n3;
        	}
    	}
    	else
    	{
    	    if(n2 > n3)
    	    {
    	        m = n2;
    	    }
    	    else
    	    {
    	        m = n3;
    	    }
    	}
    	return m;
   }
   
   int getDiameter(Node* root)
   {
   		int right_Diameter;
   		int left_Diameter;
   		int height_left;
   		int height_right;
   		int max_Distance;
   		int diameter;
   		
   		if(root==NULL)
   		{
   			return 0;
   		}
   		
   		right_Diameter= getDiameter(root->right);
   		left_Diameter= getDiameter(root->left);
   		height_left = maxHeight(root->left);
   		height_right = maxHeight(root->right);
   		max_Distance = height_left + height_right + 3;
   		
   		diameter = maximum(right_Diameter,left_Diameter,max_Distance);
   		
   		return diameter;
   }
};



//Main Function
int main()
{
    Tree* tree=new Tree();
    
    tree->insert(4);
    tree->insert(2);
    tree->insert(3);
    tree->insert(7);
    tree->insert(5);
    tree->insert(11);
    tree->insert(21);
    
    cout<<"Tree Values: "<<endl;
    tree->display(tree->root);
    cout<<endl;
    cout<<"Diameter = "<<tree->getDiameter(tree->root);
    
    return 0;
}

