#include "zerouid.h"

int main( int argc, char *argv[] ) {

  /* Declarations and initialisations */
  char hostname[GCONF_NAME_MAX_LENGTH] = "";
  char salt[3] = "";
  char *p_str_token_suffix = NULL;
  char *p_str_decode_password = NULL;
  char *p_str_root_token = NULL;
  char buffer[DECODE_PASSWORD_MAX_LENGTH] = "";
  bool decode = false;
  bool upper = false;
  bool no_dns_extension = false;
  struct termios terminfo;
  
  /* Ensure we got only one or two args */
  if ( argc < 2 || argc > 3 ) {
  
    puts("Please provide one and only one upper case GCONF name");
    return( 1 );
  
  }

  /* First case, we've one argument only so it's the hostname */
  if ( argc == 2 ) { strncpy( hostname, argv[1], GCONF_NAME_MAX_LENGTH ); }

  /*
   *  Second case, we've two arguments so got to ensure
   *  the first one match the decode option.
   */
  if ( argc == 3 ) { 
  
    if ( strcmp( argv[1], DECODE_OPT ) != 0 ) {

      puts("Wrong argument or option");
      return( 3 );

    }

    else { 

      /* Build the decode password */
      p_str_decode_password = set_decode_password();

      /* Retrieve all terminal info */
      tcgetattr(0,&terminfo);

      /* Turn terminal echo off */
      terminfo.c_lflag &= ~(ECHO);
      tcsetattr( 0, TCSANOW, &terminfo );

      /* Ask user for password */
      printf( "%s : ", "Please enter decode password" );
      fgets( buffer, DECODE_PASSWORD_MAX_LENGTH, stdin );

      /* Remove \n at end of string */
      buffer[ strlen ( buffer ) - 1 ] = '\0';

      /* Turn terminal echo back on */
      terminfo.c_lflag |= ECHO;
      tcsetattr( 0, TCSANOW, &terminfo );

      /* Check consistency */
      if ( strcmp( p_str_decode_password, buffer ) != 0 ) {
 
        puts("Wrong password entered");
        return( 4 );

      }

      strncpy( hostname, argv[2], GCONF_NAME_MAX_LENGTH );
      decode = true;

    }

  }

  /* Check we have a true uppercase style GCONF name as arg */
  upper = check_upper( hostname );
  if ( ! upper ) {

    puts("Please provide uppercase style GCONF name as arg");
    return( 5 );

  }
  
  /* Check we don't have DNS extension in arg */
  no_dns_extension = check_nodns( hostname );
  if ( ! no_dns_extension ) {

    puts("Please provide a non FQDN >= 8 chars uppercase style GCONF name");
    return( 6 );

  }

  /* Args seem good so we can build salt first */
  sprintf(salt, "$6$%c%c$", hostname[4], hostname[5] );
  
  p_str_token_suffix = set_token_suffix();
  p_str_root_token = build_root_token( hostname, p_str_token_suffix );

  /* Display wheter hash or clear password */
  if ( decode ) { printf( "\n%s\n", p_str_root_token ); }
  else { printf( "%s\n", crypt( p_str_root_token, salt ) ); }

  return( 0 );

}
