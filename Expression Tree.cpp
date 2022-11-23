#include "ET.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <istream>
#include <fstream>
using namespace std;

ET::ET(){ 
    root = NULL;
}

ET::~ET(){
    destroy(root);
}

void ET::destroy(Node *r){

  if(r != NULL)
    {
        destroy(r -> left);
        destroy(r -> right);
        delete r;
    }
}


void ET::build_tree(istream& in_s){

    destroy(root); // make sure the tree is empty
    root = help_build(in_s);


}

ET::Node* ET::help_build(istream& in_s){

    char ch;
    Node* temp;
    in_s>>ch;
    if(isdigit(ch)){

        temp= new Node;
        temp -> operand = ch - '0';
        temp -> left = NULL;
        temp -> right = NULL;

    }
	else{

        temp = new Node;
        temp -> left = help_build(in_s);
        in_s>> temp -> optr;
        temp -> right = help_build(in_s);
        in_s >> ch; // ')'
    }
    return temp;
}

void ET::pre_order(Node* r, ostream& out_s){ //Prefix

    if( r -> left == NULL){ // its a leaf
        out_s << r -> operand << " ";


    }
	
	else{
        out_s << r -> optr << " ";
        pre_order(r -> left, out_s);
        pre_order(r -> right, out_s);
    }
}

void ET::post_order(Node* r, ostream& out_s){ //Postfix

    if( r -> left == NULL){ // its a leaf
        out_s << r -> operand << " ";


    }
	
	else{

        post_order(r -> left, out_s);
        post_order(r -> right, out_s);
        out_s << r -> optr << " ";
    }
}

void ET::in_order(Node* r, ostream& out_s){ //Infix

 if( r -> left == NULL){ // its a leaf

        out_s << r -> operand << " ";


    }
	
	else{
        out_s << '(';
        in_order(r -> left, out_s);
        out_s << r -> optr << " ";
        in_order(r -> right, out_s);
        out_s << ')';
    }

}

int ET:: eval(Node* x) {

    int result;

    switch (x -> optr) {
       case '+': result = eval(x->left) + eval(x->right);
               break;
       case '-': result = eval(x->left) - eval(x->right);
               break;
       case '*': result = eval(x->left) * eval(x->right);
               break;
       case '/': result = (eval(x->left)) / (eval(x->right));
               break;
       default:
            return x -> operand;

}
 return result;

}


int ET::Value(){ 
    return eval(root);
}

ostream& operator << (ostream& out_s, ET& e){ //ouptut 
    cout<<""<<endl;
    
	out_s << "Prefix: ";
    e.pre_order(e.root, out_s);
    out_s << endl;
    	
    
    
    out_s << "Infix: ";
    e.in_order(e.root, out_s);
	out_s << endl;
		
    
	out_s << "Postfix: ";
    e.post_order(e.root, out_s);
    out_s << endl;
    cout<<"Value:"<<e.Value()<< endl;
    
	cout<<""<<endl;
    



    return out_s;
}

void tree(ifstream& in_f){

ET e;
string expression;

        e.build_tree(in_f);
        cout << e;
	
        while(getline(in_f, expression)){
            e.build_tree(in_f);
        cout << e;
        }
}

//////////////////////////////////////////////////
int main()
{
    ifstream infile;
    char file_name[100];
    string str;


     cout << "Enter a file name: ";
     cin >> file_name;               // Get file name

     infile.open(file_name);         // Open file
    if(!infile)                     // If we couldn't open the file...
    {
        cout << "Failed to open file." << endl;
        return 0;
    }

tree(infile);
infile.close();


    return 0;
}



