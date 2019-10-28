#include "linked_array.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

linked_array::linked_array()
    : m_head( 0 ),
      m_tail( 0 ),
      m_ptr_end_idx( 0 )

{
}

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
    m_ptrs[ m_ptr_end_idx++ ] = n;
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

void
linked_array::print_item_at( int index )
{
   node* item = m_ptrs[ index ];
   printf( "%s\n", item->word() );
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

int
linked_array::size()
{
    if ( this->m_head == 0 )
        return 0;

    int size = 0;
    node* current_node = this->m_head;
    while( true )
    {
        ++size;
        if ( current_node->next() == 0 )
            break;
        else
            current_node = current_node->next();
    }

    return size;
}

bool
linked_array::has_cycle()
{
    if ( m_head == 0 )
        return false;

    bool retval = false;
    node* current_node = m_head;
    while( true )
    {
        if ( current_node->has_seen() )
        {
            retval = true;
            break;
        }
        else if ( current_node->is_last() )
        {
            break;
        }
        else
        {
            current_node = current_node->next();
        }
    }

    return retval;
}


