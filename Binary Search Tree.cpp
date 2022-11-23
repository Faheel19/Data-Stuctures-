#include <iostream>
#include <cstdlib>
using namespace std;

  /*
   * Node Declaration
   */ 
struct node {
        int data; 
        node *left;
        node *right;
};

  /*
   * Class Declaration
   */ 
  class BST{
        public:
            // pointer to store the root of the tree.
        node *root;
        bool find (node*, int);
        node *insert (node* root, int val);
        node *del (node*, int);
        node *minValueNode (node *);
        int length (node *);
        
        void inOrder (node *);
  
		BST (){    
			root = NULL;
  
		}~BST (){
    		root = NULL;

	}};

  /*
   * Main Contains Menu
   */ 
  int main () {
  
		char choice = 'h';
		int num;
 
 		BST bst;
  		node *temp;
		bool quit = false;
  
		while (1){
			
			switch (choice){
	
				case 'e': {    
	      			// calling the destructor and then constructor again
	      			bst.~BST();
					  bst = BST();
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
	      			bool isPresent = bst.find (bst.root, num);
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


 
  /*
   * Find Element in the Tree
   */ 
	bool BST::find (node * r, int item){	  
		if (r == NULL){  
			// we are at leaf node
			return false;
		} else if (r->data == item){
			// if we found the item
			return true;    
		} else {
			// otherwise check in left and right part of the tree.
			return this->find (r->left, item) || this->find (r->right, item);
	    }	
	}
 
  /*
   * Inserting Element into the Tree
   */ 
	node *BST::insert (node *r, int item){
	    // if we are at root node we need to insert our node there.
	    if (r == NULL){
			node * temp = new node ();
			temp->data = item;
	    	temp->left = NULL;
	    	temp->right = NULL;
		return temp;
		}
	    // if data item is less than root then we need to go to insert in the left
	    else if (r->data > item){
			r->left = this->insert (r->left, item);
			return r;
		}  
	    // if new data item is greater than we need to insert it in right of root
	    else if (r->data < item){
			r->right = this->insert (r->right, item);
			return r;
		}
	    // if new data item is equal to the current root node then just return
	    // do not insert.
	    else{
			return r;
		}
	}
 
  // finding the minimum value of the tree
	node* BST::minValueNode (node* node){
		struct node *
	    current = node;
	//loop down to find the leftmost leaf
		while (current->left != NULL)    
			current = current->left;
	return current;
	}


  /*
   * Delete Element from the tree
   */ 
	node* BST::del (node *root, int data) {
	    // base case
	    if (root == NULL)
	    	return root;
	    // data to be deleted is smaller than current root node.
	    // then we will find our value in the left
	    if (data < root-> data)    
			root->left = del (root->left, data);
	    // data to be deleted is greater than current root node.
	    // then we will find our value in the right
	    else if (data > root->data)
			root->right = del (root->right, data);
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
		struct node* temp = this->minValueNode(root->right);
		
		// Copy the inorder successor's content to this node
		root->data = temp->data;
		  
		// Deleting the inorder successor
		root->right = del(root->right, temp->data);
		}
		
	return root;	
	}
	
	// length of the BST
	int BST:: length(node* root){
		if(root==NULL){
			return 0;
		}else{
			return 1 + this->length(root->left) + this->length(root->right);
		}
	}
	
	// inorder traversal of the tree.
	void BST::inOrder(node* root){
		if(root==NULL)
			return;
		
		this->inOrder(root->left);
		cout<<root->data<<" ";
		this->inOrder(root->right);
	}

