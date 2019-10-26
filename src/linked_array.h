#ifndef LINKED_ARRAY_H
#define LINKED_ARRAY_H

#include "node.h"

class linked_array
{
private:
    static const int INIT_NODE_ARR_SIZE = 1000000;
    node*   m_head;
    node*   m_tail;
    node*   m_ptrs[ INIT_NODE_ARR_SIZE ];
    int     m_ptr_end_idx;

public:
    // Constructors
    //
    linked_array();

    ~linked_array(){}

    // Accessing
    //
    void push_back( const char* str, int len );
    void push_front( const char* str, int len );
    node* head() { return m_head; }
    void head( node* node ) { this->m_head = node; }
    const char* operator[] ( int index );
    int size();

    // Printing
    void print_all();
    void print_item_at( int indx );

    // Testing
    //
    bool has_cycle();

private:
    linked_array( const linked_array& );
    linked_array& operator=( linked_array );
};

#endif // LINKED_ARRAY_H
