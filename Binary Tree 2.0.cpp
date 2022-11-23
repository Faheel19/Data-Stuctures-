#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
   int key;
   node *left; node *right;
};

	class Binary_Search_Tree{
	public:
        // pointer to store the root of the tree.
        node *root;
        node *search (node*, int);
        node *insert (node* root, int val);
        node *del (node*, int);
        node *minValue (node *);
        int length (node *);
        
        void inOrder (node *);
  
		Binary_Search_Tree (){    
			root = NULL;
  
		}~Binary_Search_Tree (){
    		root = NULL;

	}};

struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

node* Binary_Search_Tree::search(struct node* root, int key){
   if (root == NULL || root->key == key)
      return root;
   if (root->key < key)
      return search(root->right, key);
   return search(root->left, key);
}
node* Binary_Search_Tree::insert(struct node* node, int key){
   if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insert(node->left, key);
      else if (key > node->key)
         node->right = insert(node->right, key);
   return node;
}
node* Binary_Search_Tree::minValue(node* node){
		struct node*
	    current = node;
	//loop down to find the leftmost leaf
		while (current->left != NULL)    
			current = current->left;
	return current;
	}
node* Binary_Search_Tree::del(node* root, int key){
	    // base case
	    if (root == NULL)
	    	return root;
	    // key to be deleted is smaller than current root node.
	    // then we will find our value in the left
	    if (key < root-> key)    
			root->left = del (root->left, key);
	    // key to be deleted is greater than current root node.
	    // then we will find our value in the right
	    else if (key > root->key)
			root->right = del (root->right, key);
	    // if key is same as root's key, then This is the node
	    // to be deleted
	    else {
		// node with only one child or no child
		//case 1
				if (root->left == NULL){
					struct node *temp = root->right;
					free(root);
					return temp;
				} //case 2
				else if (root->right == NULL){
					struct node *temp = root->left;
					free(root);
					return temp;
				}
		// node with two children:
		struct node* temp = this->minValue(root->right);
		
		// Copy the inorder successor's content to this node
		root->key = temp->key;
		  
		// Deleting the inorder successor
		root->right = del(root->right, temp->key);
		}
		
	return root;	
	}
	
int Binary_Search_Tree::length(node* root){
		if(root==NULL){
			return 0;
		}else{
			return 1 + this->length(root->left) + this->length(root->right);
		}
	}
	
void Binary_Search_Tree :: inOrder(node* root){
		if(root==NULL)
			return;
		
		this->inOrder(root->left);
		cout<<root->key<<" ";
		this->inOrder(root->right);
	}	

	
int main(){
  
		char choice = 'h';
		int num;
 
 		Binary_Search_Tree bst;
  		node *temp;
		bool quit = false;
  
		while (1){
			
			switch (choice){
	
				case 'e': {    
	      			// calling the destructor and then constructor again
	      			bst.~Binary_Search_Tree();
					  bst = Binary_Search_Tree();
				break;
				}
				case 'i': {
					cin >> num;
	      			// taking input of the number and calling the insert function
	      			bst.root = bst.insert (bst.root, num);
	    		break;
				}
				case 'r': {
					cin >> num;
					// calling the del funciton to delete after taking the num in
					bst.root = bst.del (bst.root, num);
				break;
				}
				case 'l': {
					int len = bst.length (bst.root);
	      			// finding the length and then print the found value
	      			cout << "The list contains " << len << " elements" << endl;;	    
				break;
	  			}
				case 'p': {
					cin >> num;
	      			// calling the find method to check if the value is present or not
	      			bool isPresent = bst.search (bst.root, num);
					if (isPresent){
						cout << "The value " << num << " is present in the list" <<endl;}
	    			else{
						cout << "The value " << num << " is not present in the list"<<endl;}
				break;
				}
	
				case 'w':{
					cout << "The list: ";
	    
	      			// printing the list sequentially using the inorder method of the BST
	      			bst.inOrder (bst.root);	    
					cout<<endl;	    
				break;	  
				}
	
				case 'h':{
					    
				cout << "e -- Re-initialize the list to be empty." <<endl;
				cout << "i v -- Insert the value v into the list." <<endl;
				cout << "r v -- Remove the value v from the list." <<endl;
				cout << "l -- Report the length of the list." <<endl;
				cout << "p v -- Is the value v present in the list?" <<endl;
				cout << "w -- Write out the list." <<endl;
				cout << "h -- See this menu." <<endl;
				cout << "q -- Quit." <<endl;					    
				break;
				}
				case 'q':
					// quiting the service.
					quit = true;  
				break;
								 
				default:	  
					cout << "Wrong choice" << endl;  
				break;
				}
				      
				if (quit) {
					break;
				}     
					cin >> choice;
			}
		}
		


