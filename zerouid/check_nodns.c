#include "zerouid.h"

bool check_nodns( const char *hostname ) {

  /* Declarations and initialisations */
  char *p_str_name = (char *)hostname;
  char c = '\0';
  bool status = true;
 
  /* Memory allocations */

  /* Check shortname is not too short... */
  if ( strlen( p_str_name ) < 8 ) { status = false; }

  /* Check we don't have dot in hostname */
  while (( c = *p_str_name ) != '\0' ) {

    if ( c == '.' ) { status = false; break; }
    p_str_name++;

  }

  return( status );

}
