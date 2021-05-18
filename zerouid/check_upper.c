#include "zerouid.h"

bool check_upper( const char *hostname ) {

  /* Declarations and initialisations */
  char *p_str_name = (char *)hostname;
  char c = '\0';
  bool status = true;
  bool cond1 = false;
  bool cond2 = false;
  bool cond3 = false;
  bool cond4 = false;

  /*
   *  Each char must be in upper case ie
   *  ASCII code in range [45,57] for digits
   *  and [65,90] for letters.
   *  Also allow dash and underscore in names.
   */

  while (( c = *p_str_name ) != '\0' ) {

    cond1 = ( isupper( c ) ) ? true : false;
    cond2 = ( isdigit( c ) ) ? true : false;
    cond3 = ( c == 45 ) ? true : false;
    cond4 = ( c == 95 ) ? true : false;
    if ( ! (cond1 || cond2 || cond3 || cond4) ) {

      status = false;
      break;
    }
    p_str_name++;

  }

  return( status );

}
