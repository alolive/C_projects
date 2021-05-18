#include "bpceid.h"

char *get_list( FILE *snippet ) {

  /* Declarations & initialisations */
  char *value = NULL;
  char *p_str_1 = NULL;
  char c = '\0';
  int i = 0;
  FILE *p_file_saver = snippet;

  /* Memory allocations */
  value = calloc( 3 * VALUE_PROP_MAX_LENGTH, sizeof( char ) );
  p_str_1 = calloc( 3 * VALUE_PROP_MAX_LENGTH, sizeof( char ) );

  /* Retrieve at most 3 lines until end of list found */
  while ( fgets( p_str_1, VALUE_PROP_MAX_LENGTH, p_file_saver ) != NULL ) {

    if ( strstr( p_str_1, "]," ) || i > 2 ) { break; }
    strcat( value, p_str_1 );
    i++;

  }

  /* Purge unwanted chars */
  p_str_1 = value;
  i = 0;
  while ( (c = *p_str_1) != '\0' ) {

    if ( c != '"' && c != ' ' && c != '\n' ) {

      value[i] = *p_str_1; i++;

    }

    p_str_1++;

  }

  value[ i ] = '\0';
  return( value );

}
 
