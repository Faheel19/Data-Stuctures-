#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Teller_s {
	bool active;
	int time_At;
	int id;
	int count;
};


typedef int ElementType;
class Queue { 
public: 		

	class Node { 			
	public: 			
		ElementType id;
		ElementType enqueue_Time;
		ElementType dequeue_Time;

		Node *next;				  				
		Node() { 
			// Node constructor					
			id = 0;
			enqueue_Time = 0;
			dequeue_Time = 0;
			next = NULL;				
		} 		
	}; //--- end of Node class 
	
	typedef Node *NodePointer; 

//Default constructor		
	Queue(); 		
	
	
//Add to the back of the queue		
	void enqueue(ElementType& a,ElementType &b); 		
	
//Remove from the front of the queue		
	void dequeue(); 		
	
//Returns the front of the queue		
	NodePointer front()
	{
		if (first) {		
		NodePointer ptr = first;		
		return ptr;	}
	}

//Return size of the queue		
	int getSize(); 	

//Return arrive time
	ElementType enqueueTime(NodePointer p){
		return p->enqueue_Time;
	}

	ElementType dequeueTime(NodePointer p){
		return p->dequeue_Time;
	}

	int  getId(NodePointer p){
		return p->id;
	}
//Destructor		
	~Queue(); 	

private: 	

	Node *first;		
	Node *last;		
	int mySize; 
};

Queue::Queue() {	
	mySize = 0;
	first = NULL;	
	last = NULL;	
}

void Queue::enqueue(ElementType &a,ElementType &b)
{	
	NodePointer nPtr = new Node();
	nPtr->id = a;
	nPtr->enqueue_Time = b;
	NodePointer predPtr = first; 	
	if (first == NULL) { //Insert if queue is empty		
		nPtr->next = first;		
		first = nPtr;	} 
	else { //Insert into the queue at the end		
		while (predPtr->next) {			
			predPtr = predPtr->next;		}		
		predPtr->next = nPtr;	}	
	mySize++;	
	last = nPtr; 
} 

void Queue::dequeue() {	

	if (first) {	
		NodePointer dPtr = first;
		first = first->next; //Set first to the second node in the list		
		delete dPtr; //Delete the node that has been dequeued	
	}	
	mySize--; 
}

int Queue::getSize() {	
	return mySize;
}

Queue::~Queue() {	
	if (first)
	{		//Deallocate all nodes in queue		
		NodePointer current = first;		
		NodePointer temp = first; 
		temp = current->next;		
		delete current;		
		current = temp;	
	}
}

int main() {
	//Min/Max values for user input
	const int    MIN_SIM_TIME   = 0, MAX_SIM_TIME   = 10000,
	             MIN_TRANS_TIME = 0, MAX_TRANS_TIME = 100,
				 MIN_NUM_SERV   = 0, MAX_NUM_SERV   = 10,
				 MIN_ARRIV_TIME = 0, MAX_ARRIV_TIME = 100;
				 
	char runAgain = 'Y'; //Set runAgain so the program runs
	int sim_Time, trans_Time, num_Serv, arriv_Time; //User input variables
	int i, c_Time; //Counters
	int customers ,wait_Time; //Total customers and integer for customer waiting time
	srand(time(0));
	while (runAgain != 'N') {
		i = 0; c_Time = 0;
		customers = 0; wait_Time = 0;
		
		Queue bankQ; //Create <strong class="highlight">queue</strong> object
	
		cout << "\n------------------------------------------"
			 << "\n- Queue Simulation Program -"
			 << "\n------------------------------------------";
		
		//Menu information
		cout << "\n\nPlease input the following data(Time in minutes):\n";
		cout << "\nLength of the Simulation: ";
		cin >> sim_Time;
		while (sim_Time <= MIN_SIM_TIME || sim_Time > MAX_SIM_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> sim_Time;
		}
			cout << "Average Number of Servers: ";
		cin >> num_Serv;
		while (num_Serv <= MIN_NUM_SERV || num_Serv > MAX_NUM_SERV) {
			cout << "Invalid input. Please re-enter: ";
			cin >> num_Serv;
		}
				cout << "Average Transaction Time: ";
		cin >> trans_Time;
		while (trans_Time <= MIN_TRANS_TIME || trans_Time > MAX_TRANS_TIME) {
			cout << "Invalid input. Please re-enter: ";
			cin >> trans_Time;
		}
				
		//Dynamically allocate an array for the teller structure
		Teller_s * tellArray = new Teller_s[num_Serv];
		
		//Set all tellers to empty
		for (i = 0; i < num_Serv; i++) {
			tellArray[i].active = false;
			tellArray[i].time_At = 0;
			tellArray[i].id = 0;
			tellArray[i].count = 0;
		}
		int total_trans_time = 0;
		int arriv_Customers = 0;
		int wait = 0;

		while (c_Time < sim_Time) { //Run until simulation time is reached

			arriv_Customers = rand() % 5;
			cout << "At time "<< c_Time << " "<< arriv_Customers << "   customers come" << endl;

				for(i = 0 ; i < arriv_Customers; i++)
				{
					bankQ.enqueue(++customers,c_Time);
				}

			for (i = 0; i < num_Serv; i++) {
if (tellArray[i].active == false && bankQ.getSize() != 0) { //Dequeue if a teller is open
					trans_Time = rand() % 30 + 1;
					total_trans_time  += trans_Time;
					
					tellArray[i].active = true;
					tellArray[i].time_At = trans_Time;
					tellArray[i].id = bankQ.front()->id;
					tellArray[i].count++;
					wait = c_Time - bankQ.front()->enqueue_Time;
					
					cout <<" server " << i << "  is serving customer" << tellArray[i].id<< endl;
					cout << "waited time  " << wait << "\ttransaction time" << trans_Time << endl;
					bankQ.dequeue();
				}
			}
			
			
			for (i = 0; i < num_Serv; i++) {
				if (tellArray[i].active == true) {
					tellArray[i].time_At--;  //Decrement time spent at teller
				}
				if (tellArray[i].time_At == 0) {
					tellArray[i].active = false; //Set teller to open if time limit is reached
				}
			}

			wait_Time += bankQ.getSize(); //Set wait time to persons left in Queue*/
			c_Time++;
		}
		//Output user input data
		cout << "\n---------------"
			 << "\n- Data Output -"
			 << "\n---------------\n";
			 
		cout << setw(31) << left << "Simulation Time: ";
		cout << sim_Time << endl;
		
		cout << setw(31) << left << "Average Transaction Time: ";
		cout << float(total_trans_time) / (customers - bankQ.getSize()) << endl;
		
		cout << setw(31) << left << "Average Number of Servers: ";
		cout << num_Serv << endl;
		
		//cout << setw(31) << left << "Average Time Between Arrivals: ";
		//cout << arriv_Time << endl << endl;
		
		//Output calculated data
		cout << "Average Total Wait Time: ";
		cout << fixed << setprecision(2)
			 << (float)wait_Time/customers;
		cout << "\nCustomers in line at end of simulation: "
	         << bankQ.getSize() << endl;
		
		cout << "After simulation time : " << endl;
		for(i = 0; i < num_Serv;i++)
		{
			cout << "server" <<" "<< i <<" "<< "is serving customer" <<" "<< tellArray[i].id << endl;
			cout << "server" <<" "<< i <<" "<< "has served " << tellArray[i].count <<" "<< "customers" << endl;
		}
		//Ask to run again
		cout << "\nRun the program again? (y/n): ";
		cin >> runAgain;
		runAgain = (char)toupper(runAgain);
		while (runAgain != 'Y' && runAgain != 'N') {
			cout << "Invalid Entry, please re-enter: ";
			cin >> runAgain;
			runAgain = (char)toupper(runAgain);
		}
		//Deallocate teller structure array
		delete [] tellArray;
	}	
	return 0;
}
