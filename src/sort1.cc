#include <stdio.h>
#include "linked_array.h"
#include <string.h>
#include <cstdio>

node* selection_sort( node* head );
node* snip_smallest( node* head );
node* find_smallest( node* head );
void remove_newline( char* buffer )
{
    buffer[ strcspn( buffer, "\n" ) ] = 0;
}

void print_all( node* head )
{
    node* current_node = head;
    while ( true )
    {
        printf( "%s\n", current_node->word() );
        if ( current_node->has_next() )
            current_node = current_node->next();
        else
            break;
    }
}

void print_count( node* head )
{
    int cnt = 0;
    node* current_node = head;
    while ( true )
    {
        ++cnt;
        if ( current_node->has_next() )
        {
            current_node = current_node->next();
        }
        else
        {
            break;
        }
    }

    printf( "The number of nodes is: %d\n", cnt );
}


int main()
{

    int MAX_BUFF_SIZE = 1000;
    char buffer[ MAX_BUFF_SIZE ];
    node* head = 0;
    node* tail = 0;
    bool  first = true;

    FILE* file = fopen( "words.txt", "r" );
    while ( fgets( buffer, MAX_BUFF_SIZE, file ) != NULL  )
    {
        remove_newline( buffer );
        node* new_node = new node();
        new_node->word( buffer, strlen( buffer ) );

        if ( first )
        {
            head = new_node;
            tail = new_node;
            first = false;
        }
        else
        {
            tail->next( new_node );
            new_node->previous( tail );
            tail = new_node;
        }
    }
    fclose( file );

    node* new_list = selection_sort( head );
}

node* selection_sort( node* head )
{
    node* result = new node();
    while ( head != 0 )
    {
        break;    
    }

    return result;
}

node* snip_smallest( node* head )
{
    node* smallest = find_smallest( head );
    node* retval = new node();
    retval->word( smallest->word(), strlen( smallest->word() ) );
    /*snip( smallest );*/
    return retval;
}

node* find_smallest( node* head )
{
    node* current_node;
    node* smallest_node;
    current_node  = head;
    smallest_node = head;

    /* 
    while ( true )
    {
        if ( current_node->is_only() )
        {
            smallest_node = current_node;
            break;
        }
    }
    */

    return smallest_node;
}

int strcmp_nodes( node* lhs, node* rhs )
{
    const char* current_word = lhs->word();
    const char* next_word    = rhs->word();

    return strcmp( current_word, next_word );
}

void snip( node* node_to_snip )
{
    node* parent = 0;
    node* child  = 0;

    if ( node_to_snip->is_only() )
    {
        node_to_snip = 0;
    }
    
    if ( node_to_snip->is_middle() )
    {
        parent = node_to_snip->previous();
        child  = node_to_snip->next();

        parent->next( child );
        child->previous( parent );
    }
    else // It's the last
    {
        parent = node_to_snip->previous();
        parent->next( 0 );
    }
}
