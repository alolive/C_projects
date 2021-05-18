#include "bpceid.h"

char *get_key( int line_size, const char *line_buffer ) {

  /* Declarations & initialisations */
  char *buffer = NULL;
  char *key = NULL;
  char *p_str_1 = NULL;
  unsigned int i = 0;

  /* Allocate memory to store key */
  key = calloc( KEY_PROP_MAX_LENGTH, sizeof( char ) );
  buffer = calloc( line_size, sizeof( char ) );

  /* Copy string to temp buffer before strtok use... */
  strcpy( buffer, line_buffer );

  /* Extract left part of token ':' */
  p_str_1 = strtok( buffer, ":" );

  /*
   *  Purge unwanted chars 
   *  to get clean display ie
   *  no spaces no double quotes
   */
  while ( *p_str_1 != '\0' ) {
  
    if ( *p_str_1 != '"' && *p_str_1 != ' ' ) {

      key[i] = *p_str_1;
      i++;

    }

    p_str_1++;

  }

  return( key );

}
 
