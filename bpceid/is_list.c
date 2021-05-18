#include "bpceid.h"

bool is_list( const char *line_buffer ) {

  /* Declarations & initialisations */
  char wanted_str[5] = { '"', ':', ' ', '[', '\0' };
  char unwanted_char = ']';
  bool status = false;
  bool wanted = false;
  bool unwanted = false;

  /* Search for key pattern */
  if ( strstr( line_buffer, wanted_str ) ) wanted = true;

  /* Search for empty list */
  if ( strchr( line_buffer, unwanted_char ) ) unwanted = true;

  if ( wanted && !unwanted ) { status = true; }

  return( status );

}
