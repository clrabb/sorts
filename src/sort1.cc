#include <stdio.h>
#include "linked_array.h"
#include <string.h>


int main()
{
    linked_array words;
    words.push_back( "test", strlen( "test" ) );
    words.push_back( "goodbye", strlen( "goodbye" ) );
    words.push_back( "foobar", strlen( "foobar" ) );

    words.print_all();

    printf( "%s\n", words[ 0 ] );

    return 0;
}
