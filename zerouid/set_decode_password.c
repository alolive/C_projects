#include "zerouid.h"

/*
 *  Decode password should be only known by admin
 *  as we can easily get root password for all hosts.
 *
 *  WARNING :
 *
 *  Must be stored as single chars array to avoid
 *  clear string in compiled binary.
 *
 */

char *set_decode_password( void ) {

  /* Declarations and initialisations */
  char *decode_password = NULL;

  /* Memory allocation for suffix */
  decode_password = calloc( DECODE_PASSWORD_MAX_LENGTH, sizeof( char ) );

  /* Quick check for retrieved pointer */
  if ( decode_password == NULL ) {
  
    /* Error display and exit. */
    perror( "Error while allocating memory..." );
    return( NULL );

  }

  /* Hard set password char by char */

  decode_password[0] = 'S';
  decode_password[1] = 'e';
  decode_password[2] = 's';
  decode_password[3] = 'a';
  decode_password[4] = 'm';
  decode_password[5] = 'e';
  decode_password[6] = '0';
  decode_password[7] = 'u';
  decode_password[8] = 'v';
  decode_password[9] = 'r';
  decode_password[10] = 'e';
  decode_password[11] = 't';
  decode_password[12] = 'o';
  decode_password[13] = 'i';
  decode_password[14] = '.';
  decode_password[15] = '.';
  decode_password[16] = '.';
  decode_password[17] = '\0';

  return( decode_password );

}
