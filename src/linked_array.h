#ifndef LINKED_ARRAY_H
#define LINKED_ARRAY_H

#include "node.h"

class linked_array
{
private:
    node* m_head;
    node* m_tail;


public:
    // Constructors
    //
    linked_array()
        : m_head( 0 ),
          m_tail( 0 )
    {
    }

    ~linked_array(){}

    // Accessing
    //
    void push_back( const char* str, int len );
    void push_front( const char* str, int len );
    const char* operator[] ( int index );
    int size();

    // Printing
    void print_all();

    // Testing
    //
    bool has_cycle();

private:
    linked_array( const linked_array& );
    linked_array& operator=( linked_array );
};

#endif // LINKED_ARRAY_H
