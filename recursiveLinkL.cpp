#include<iostream>
using namespace std;

  /*
   * Node Declaration
   */
   
typedef struct _node{
		int data;
		struct _node* next;
}
		node;
	
  /*
   * Class Declaration
   */
    
	class LinkedList{
			private:
				node* head;
			public:
	
		//constructor
		LinkedList(){
		head = nullptr;
		}
	
		//Re-initialize
		void initialize(){
		head = nullptr;
		}
	
		//insert a value into a List
		void insert(int val){
			node* newnode = new node;
			newnode->data = val;
				if (head == nullptr){
					newnode->next = nullptr;
					head = newnode;
					return;
				}
			node* pre = nullptr, * temp = head;
				if (temp->data > val){
					newnode->next = head;
					head = newnode;
					return;
				}
			while (temp != NULL && temp->data < val){
				pre = temp;
				temp = temp->next;
			}
			if (temp != NULL && temp->data == val){
				cout << "The value is already present.";
				return;
			}
			newnode->next = temp;
			pre->next = newnode;
		}
		//delete a value from a List
		
		void del(int val){
			node* temp, * pre = nullptr;
			temp = head;
			if (temp->data == val){
				head = temp->next;
				temp->next = nullptr;
				delete temp;
				return;
			}
			while (temp != nullptr && temp->data != val){
				pre = temp;
				temp = temp->next;
			}
			if (temp == nullptr) return;
			pre->next = temp->next;
			temp->next = nullptr;
			delete temp;
		}
	
		//check is a List empty or not
		void isEmpty(){
			if (head == nullptr)
			cout << "The list is empty" << endl;
			else
			cout << "The list is NOT empty" << endl;
		}
	
		//function to return the length of a List
		int length(){
			node* temp = head;
			int count = 0;
			while (temp != nullptr){
				temp = temp->next;
				count++;
			}
			return count;
		}
		
		//check a particular value is present in a List
		void isPresent(int val){
			node* temp = head;
			while (temp != nullptr && temp->data != val){
				temp = temp->next;
			}
			if (temp != nullptr && temp->data == val)
			cout << "The value " << val << " is present in the list." << endl;
			else
			cout << "The value " << val << " is NOT present in the list." << endl;
		}
		
		//the value of the kth element of a List.
		int search(int k){
			node* temp = head;
			for (int i = 1; temp != nullptr && i < k; i++){
				temp = temp->next;
			}
		if (temp == nullptr)
		return -1;
		return temp->data;
		}
		//printing the list sequentially
		
		void print(){
			node* temp = head;
			if (temp == nullptr){
				cout << "EMPTY LIST";
				return;
			}
			cout << "List: < " << temp->data;
			temp = temp->next;
			while (temp != nullptr) {
				cout << ", " << temp->data;
				temp = temp->next;
			}
			cout << " >" << endl;
		}
	};

//To display the memu
void menu(){
	
	cout << "In the following commands, k is a position in the list, and v is an integer. " << endl;
	cout<<" "<<endl;
	cout << "e -- Re-initialize the list to be empty. " << endl;
	cout << "i v -- Insert the value v into the list. " << endl;
	cout << "r v -- Remove the value v from the list. " << endl;
	cout << "m -- Is the list empty? " << endl;
	cout << "l -- Report the length of the list. " << endl;
	cout << "p v -- Is the value v present in the list? " << endl;
	cout << "k k1 -- Report the k1th value in the list. " << endl;
	cout << "w -- Write out the list. " << endl;
	cout << "h -- See this menu. " << endl;
	cout << "q -- Quit." << endl << endl;
}

//main function
int main(){
	char ch;
	LinkedList list;
	int val, k;

	menu();
	while (1){
		cout << "-->";
		cin >> ch;
		//switch statement
		switch (ch){
			case 'e':
				list.initialize();
				cout << endl;
				break;
			
			case 'i':
				cin >> val;
				list.insert(val);
				break;
		
			case 'r':
				cin >> val;
				list.del(val);
				break;
		
			case 'm':
				list.isEmpty();
				break;
		
			case 'l':
				val = list.length();
				cout << "The length of the list is " << val << endl;
				break;
		
			case 'p':
				cin >> val;
				list.isPresent(val);
				break;
		
			case 'k':
				cin >> k;
				val = list.search(k);
				if (val == -1)
				cout << "The list does not contain " << k << " values." << endl;
				else
				cout << "The " << k << "th element of the list is " << val << endl;
				break;
		
			case 'w':
				list.print();
				break;
		
			case 'h':
				menu();
				break;
		
			case 'q':
				// quiting the service.
				exit(0);
				break;
		
		default:
		cout << "Invalid command.";
		}
	}
return 0;
}

