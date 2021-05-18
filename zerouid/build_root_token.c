#include "zerouid.h"

char *build_root_token( const char *hostname, const char *token_suffix ) {

  /* Declarations and initialisations */
  char *root_token = NULL;
  char banned_chars[7] = "AMQWZ-_";
  size_t length = 0;
  unsigned int i = 0;
  bool alphabet_order = false;
  int ascii_difference = 0;
  char Char_one = hostname[4];
  char Char_two = hostname[5];
  char Char_three = hostname[ strlen( hostname ) - 2 ];
  char Char_four = hostname[ strlen( hostname ) - 1 ];

  /* Memory allocations */
  root_token = calloc( TOKEN_SUFFIX_MAX_LENGTH * 2, sizeof( char ) );

  /* Quick check for retrieved pointer */
  if ( root_token == NULL ) {
  
    /* Error display and exit. */
    perror( "Error while allocating memory..." );
    return( NULL );

  }

  /* Code build algorithm below */

  /* First part of token is ASCII code of fifth char */
  sprintf( root_token, "%d", Char_one );

  /* Are fifth and sixth chars in alphabet order ? */
  ascii_difference = (int)Char_two - (int)Char_one;
  if ( ascii_difference > 0 ) { alphabet_order = true; }

  /*
   *  We have to convert banned chars to space
   *  to get rid of keyboard layout.
   */
  length = strlen( banned_chars );
  for ( i = 0; i <= length; i++ ) {
 
    if ( Char_one == banned_chars[i] ) { Char_one = ' '; }
    if ( Char_two == banned_chars[i] ) { Char_two = ' '; }
    if ( Char_three == banned_chars[i] ) { Char_three = ' '; }
    if ( Char_four == banned_chars[i] ) { Char_four = ' '; }

  } 

  /* Add fifth and sixth chars in lowercase to token */
  root_token[2] = tolower( Char_one );
  root_token[3] = tolower( Char_two );

  /* Add boolean alphabet order shift to char with ASCII offset */
  root_token[4] = alphabet_order + 48;

  /* Add the two last chars of hostname in lowercase to token */
  root_token[5] = tolower( Char_three );
  root_token[6] = tolower( Char_four );

  /* Add suffix and basta */
  strcat( root_token, token_suffix );

  return( root_token );

}
