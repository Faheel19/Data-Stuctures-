#include <iostream>
#include <cstdlib>
#include <iostream>// Provides ostream
using namespace std;
class doubleList
{
public:
// TYPEDEF
typedef char Item;// What can go in a list
// CONSTRUCTORS
doubleList( ) { first = NULL; last = NULL; }// Inline
// DESTRUCTOR
~doubleList( );
// MODIFICATION MEMBER FUNCTIONS
void append ( const Item&entry );
void remove_last ();
// CONSTANT MEMBER FUNCTIONS
bool empty( ) const { return first == NULL; } // Inline
// FRIEND FUNCTION for the List class:
friend std::ostream&operator << ( std::ostream&out_s,
const doubleList&l );
private:
// DATA MEMBERS
struct Node
{
Item data;
Node *next;
Node *back;
};



Node *first;
Node *last;


// PRIVATE FUNCTION
Node* get_node ( const Item&entry, Node* link1, Node* link2);
};

///////////////////////////////////////////////////////////


// Default constructor is inline.


// Destructor
doubleList::~doubleList( )
{
Node* temp;

while ( first != NULL )
{
temp = first;
first = first -> next;
delete temp;
}
}

// Modification member functions

void doubleList::append ( const Item&entry )
{
Node *prev;

if ( first == NULL)
first = get_node(entry,first,NULL);
else
{
prev = last;
prev = prev->next;
prev->next = get_node(entry,prev->next,prev->next->back);
}
}

void doubleList::remove_last ()
{

Node *p;

if(first = NULL)
return;
else
{
p = last;
p->back->next = NULL;
last = p->back;
}
delete p;


}


// Constant member functions is inline

// Friend Function
ostream&operator << ( ostream&out_s, const doubleList&l )
{
doubleList::Node *cursor;
for ( cursor=l.first;
cursor != NULL &&cursor->next != NULL;
cursor=cursor->next )
out_s << cursor->data << "# ";
out_s << cursor->data;

return out_s;
}

// Private function
doubleList::Node* doubleList::get_node ( const Item&entry, Node* forward,
Node* backward )
{
Node *temp;

temp = new Node;
temp->data = entry;
temp->next = forward;
temp->back = backward;
return temp;
}




