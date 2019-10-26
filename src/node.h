#ifndef SORT1_H
#define SORT1_H

class node
{

// Member vars
//
private:
	node*  m_next;
	node*  m_previous;
	char*  m_word;


// Constructors
//
public:
node()
	: m_next( 0 ),
	  m_previous( 0 ),
	  m_word( 0 )
{
}

// Destructor
//
~node() {}

// Make generated shit private so the compiler
// can't make them
private:
node( const node& );
node& operator=( node );

public:
// Members
//
void word( const char* in_word, int len );
const char* word();

void previous( node* p ) { this->m_previous = p; }
node* previous()         { return this->m_previous; }
void next( node* n )     { this->m_next = n; }
node* next()             { return this->m_next; }

};

#endif // SORT1_H
