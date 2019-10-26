#include "linked_array.h"
#include "node.h"
#include "stdio.h"

void
linked_array::push_back( const char* str, int len )
{
    node* n = new node();
    n->word( str, len ); 
    if ( this->m_tail == 0 )
    {
        this->m_tail = n;
        this->m_head = n;
    }
    else
    {
        this->m_tail->next( n );
        this->m_tail = n;
    }
}

void 
linked_array::print_all()
{
    if ( this->m_head == 0 )
        return;

    node* n = this->m_head;
    while ( true )
    {
        printf( "%s\n", n->word() );
        if ( n->next() == 0 )
            break;

        n = n->next();
    }
}

const char*
linked_array::operator[] ( int index )
{
    node* n = this->m_head;
    int i = 0;
    while ( true )
    {
        if ( i == index )
            break;
        else
            n = n->next();

        ++i;
    }

    return n->word();
}
