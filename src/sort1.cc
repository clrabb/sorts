#include <stdio.h>
#include "linked_array.h"
#include <string.h>
#include <cstdio>

void selection_sort( node** head, node** new_list );
node** find_smallest( node** head );
void move_node( node** node_to_move, node** new_list );
node** snip_smallest( node** head );
void  disconnect( node** snip_me );
int strcmp_nodes( node** lhs, node** rhs );
void make_smallest_if_needed( node** lhs, node** rhs );




void remove_newline( char* buffer )
{
    buffer[ strcspn( buffer, "\n" ) ] = 0;
}

void print_all( node* head )
{
    if ( head == 0 )
        return;

    node* current_node = head;
    while ( true )
    {
        printf( "%s\n", current_node->word() );

        if ( current_node->is_last() )
            break;
        else
            current_node = current_node->next();
    }
}

void print_count( node* head )
{
    int cnt = 0;
    node* current_node = head;
    while ( true )
    {
        if ( head == 0 )
        {
            break;
        }
        else if ( current_node->has_next() )
        {
            current_node = current_node->next();
        }
        else
        {
            break;
        }

        ++cnt;
    }

    printf( "The number of nodes is: %d\n", cnt );
}


int count( node* head )
{
    if ( head == 0 )
        return 0;

    int count = 0;
    node* current_node = head;
    while ( true )
    {
        if ( current_node->has_next() )
            current_node = current_node->next();
        else
            break;

        ++count;
    }

    return count;
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
        if ( buffer[ 0 ] == '\n' )
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

    node* new_list = 0;
    selection_sort( &head, &new_list );

    print_all( new_list );
}


void selection_sort( node** head, node** new_list_head )
{
    bool   first          = true;
    node** new_list_tail  = 0;

    int loop_cnt = 0;
    while ( (*head) != 0 )
    {
        node** smallest = find_smallest( head );
        if ( first )
        {
            move_node( smallest, new_list_head );
            new_list_tail = new_list_head;
            first = false;
        }
        else
        {
            move_node( new_list_tail, smallest );
        }

        if ( loop_cnt++ % 1 == 0 )
        {
            printf( "original list: %d\n", count( *head ) );
            printf( "new list: %d\n", count( *new_list_head ) );
        }
    }
}

node** find_smallest( node** head )
{
    // Early out, since there is only the one
    // node in the list
    //
    if ( (*head)->is_only() )
        return head;

    node** current_node;
    node** smallest_node;
    current_node  = head;
    smallest_node = head;

    while ( true )
    {
        // If the current_node is greater than the smallest we've seen, 
        // Make the current the smallest
        //
        make_smallest_if_needed( smallest_node, current_node );

        // Move to the next node
        //
        if ( (*current_node)->is_last() )
            break;

        node* next_node = (*current_node)->next();
        current_node = &next_node;
    }

    return smallest_node;
}

void make_smallest_if_needed( node** lhs, node** rhs )
{
    if ( strcmp_nodes( rhs, lhs ) < 0 )
    {
        *lhs = *rhs;
    }
}

void move_node( node** node_to_move, node** new_list )
{
    if ( (*new_list) == 0 )
    {
        // list is empty
        //
        *new_list = *node_to_move;
    } 
    else
    {
       (*new_list)->next( *node_to_move ); 
    }

    if ( (*node_to_move)->is_first() && (*node_to_move)->has_next() )
    {
        node* next = (*node_to_move)->next();
        next->previous( 0 );
    }
    else if ( (*node_to_move)->is_last() && (*node_to_move)->has_previous() )
    {
        node* previous = (*node_to_move)->previous();
        previous->next( 0 );
    }
    else if ( (*node_to_move)->is_middle() )
    {
       node* next     = (*node_to_move)->next();
       node* previous = (*node_to_move)->previous();

       previous->next( next );
       next->previous( previous );
    }
    else // Only
    {
        *node_to_move = 0;
    }
}


int strcmp_nodes( node** lhs, node** rhs )
{
    const char* current_word = (*lhs)->word();
    const char* next_word    = (*rhs)->word();

    return strcmp( current_word, next_word );
}

