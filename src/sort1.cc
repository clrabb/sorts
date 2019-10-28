#include <stdio.h>
#include "linked_array.h"
#include <string.h>
#include <cstdio>

node* selection_sort( node* head );
node* snip_smallest( node* head );
node* find_smallest( node* head );
void  snip( node* snip_me );
int strcmp_nodes( node* lhs, node* rhs );




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
    while ( head != 0 )
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
        if ( buffer[ 0 ] != '\n' )
            continue;

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
            new_node->previous( tail );
            tail->next( new_node );
            tail = new_node;
        }
    }
    fclose( file );

    node* new_list = selection_sort( head );
}


int count( node* head )
{
    int count = 0;
    node* current_node = head;
    while ( true )
    {
        ++count;
        if ( current_node->has_next() )
            current_node = current_node->next();
        else
            break;
    }

    return count;
}

node* selection_sort( node* head )
{
    node* new_head = new node();
    node* new_tail = 0;
    bool first     = true;


    int loop_cnt = 0;
    while ( head != 0 )
    {
        if ( first )
        {
            new_head = snip_smallest( head );
            new_tail = new_head;
            first = false;
        }
        else
        {
           new_tail->next( snip_smallest( head ) );
           new_tail = new_tail->next();
        }

        if ( loop_cnt++ % 1 == 0 )
        {
            printf( "original list: %d\n", count( head ) );
            printf( "new list: %d\n", count( new_head ) );
        }
    }

    return new_head;
}

node* snip_smallest( node* head )
{
    node* smallest = find_smallest( head );
    node* retval = new node();
    retval->word( smallest->word(), strlen( smallest->word() ) );
    snip( smallest );
    return retval;
}

node* find_smallest( node* head )
{
    node* current_node;
    node* smallest_node;
    current_node  = head;
    smallest_node = head;

    while ( true )
    {
        if ( current_node->is_only() )
        {
            smallest_node = current_node;
            break;
        }
        else if ( current_node->is_last() )
        {
            int retval = strcmp_nodes( current_node, smallest_node );
            if ( retval < 0 )
            {
                smallest_node = current_node;
            }

            break;

        }
        else
        {
            int retval = strcmp_nodes( current_node, smallest_node );
            if ( retval < 0 )
            {
                smallest_node = current_node;
            }

            current_node = current_node->next();
        }
    }

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
    else if ( node_to_snip->is_first() )
    {
        node* next_node = node_to_snip->next();
        next_node->previous( 0 );
    }
    else if ( node_to_snip->is_middle() )
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

    delete( node_to_snip );
}
