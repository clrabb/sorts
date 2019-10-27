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
    bool   m_seen;


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
node& operator=( node );
node( const node& );

public:
// Members
//
void word( const char* in_word, int len );
const char* word();

void previous( node* p ) { this->m_previous = p;             }
node* previous()         { return this->m_previous;          }
void next( node* n )     { this->m_next = n;                 }
node* next()             { return this->m_next;              }

bool has_seen()          { return this->m_seen;              }
void mark_seen()         { this->m_seen = true;              }
void mark_unseen()       { this->m_seen = false;             }

bool has_next()          { return this->m_next != 0;         }
bool has_previous()      { return this->m_previous != 0;     }

bool is_last()           { return !( this->has_next() );     }
bool is_not_last()       { return !( this->is_last() );      }
bool is_first()          { return !( this->has_previous() ); }
bool is_not_first()      { return !( this->is_first() );     }
bool is_middle()         { return this->is_not_first() && this->is_not_last(); }
bool is_only()           { return this->is_first() && this->is_last(); }

};

#endif // SORT1_H
