#include "zerouid.h"

/*
 *  Root token suffix built ONLY with COMMON letters
 *  between azerty and qwerty keyboards layout.
 *
 *  WARNING :
 *
 *  Must be stored as single chars array to avoid
 *  clear string in compiled binary.
 *
 */

char *set_token_suffix( void ) {

  /* Declarations and initialisations */
  char *token_suffix = NULL;

  /* Memory allocation for suffix */
  token_suffix = calloc( TOKEN_SUFFIX_MAX_LENGTH, sizeof( char ) );

  /* Quick check for retrieved pointer */
  if ( token_suffix == NULL ) {
  
    /* Error display and exit. */
    perror( "Error while allocating memory..." );
    return( NULL );

  }

  /* Hard set password char by char */

  token_suffix[0] = 'c';
  token_suffix[1] = 'l';
  token_suffix[2] = 'e';
  token_suffix[3] = 'f';
  token_suffix[4] = 'U';
  token_suffix[5] = 'n';
  token_suffix[6] = '1';
  token_suffix[7] = 'x';
  token_suffix[8] = '\0';

  return( token_suffix );

}
