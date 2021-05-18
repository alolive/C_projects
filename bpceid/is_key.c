#include "bpceid.h"

bool is_key( const char *line_buffer ) {

  /* Declarations & initialisations */
  char wanted_str[4] = { '"', ':', ' ', '\0' };
  char unwanted_str1[5] = { '"', ':', ' ', '{', '\0' };
  char unwanted_str2[5] = { '"', ':', ' ', '[', '\0' };
  bool status = false;

  /* Search for key pattern */
  if ( strstr( line_buffer, wanted_str ) != NULL ) { status = true; }
  if ( strstr( line_buffer, unwanted_str1 ) != NULL ) { status = false; }
  if ( strstr( line_buffer, unwanted_str2 ) != NULL ) { status = false; }

  return( status );

}
