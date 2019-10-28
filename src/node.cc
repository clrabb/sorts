#include "node.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


node::~node()
{
    free( this->m_word );
}

void 
node::word( const char* in_word, int len )
{
	char* mem = static_cast< char* >( malloc( ( len + 1 ) * sizeof( char ) ) );
	strncpy( mem, in_word, len );
	mem[ len ] = 0;
	this->m_word = mem;
}


const char*
node::word()
{
	return this->m_word;
}


