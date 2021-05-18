#include "bpceid.h"

char *get_value( int line_size, const char *line_buffer ) {

  /* Declarations & initialisations */
  char *buffer = NULL;
  char *value = NULL;
  char *p_str_1 = NULL;
  unsigned int i = 0;
  unsigned int j = 0;
  char banned_chars[4]= { '"', ' ', ',', '\n' };
  size_t length = 0;
  bool banned = false;

  /* Allocate memory to store value */
  value = calloc( VALUE_PROP_MAX_LENGTH, sizeof( char ) );
  buffer = calloc( line_size, sizeof( char ) );

  /* Copy string to temp buffer before strtok use... */
  strcpy( buffer, line_buffer );

  /* Extract right part of token ':' */
  p_str_1 = strtok( buffer, ":" );
  p_str_1 = strtok( NULL, ":" );

  /* Purge unwanted chars  */
  length = strlen( banned_chars );
  while ( *p_str_1 != '\0' ) {

    for ( j = 0; j <= length; j++ ) {

      if ( *p_str_1 == banned_chars[j] ) { banned = true; break; } 

    }

    if ( !banned ) { value[i] = *p_str_1; i++; }
    banned = false;
    p_str_1++;

  }

  return( value );

}
 
