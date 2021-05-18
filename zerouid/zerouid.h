#ifndef ZEROUID_H

  #define ZEROUID_H

  #define  _GNU_SOURCE
  #define _XOPEN_SOURCE
  #include <stdio.h>
  #include <stdlib.h>
  #include <errno.h>
  #include <string.h>
  #include <dirent.h>
  #include <ctype.h>
  #include <stdbool.h>
  #include <unistd.h>
  #include <termios.h>

  /* Maximum FQDN length */
  #define GCONF_NAME_MAX_LENGTH 32

  /* Define arg option to decode and print root token */
  #define DECODE_OPT "--decode"

  /* Maximum decode password length */
  #define DECODE_PASSWORD_MAX_LENGTH 32

  /* Maximum root token suffix length */
  #define TOKEN_SUFFIX_MAX_LENGTH 16

  /* Set decode password */
  char *set_decode_password( void );

  /* Set root token suffix */
  char *set_token_suffix( void );

  /* Check upper case in GCONF NAME */
  bool check_upper( const char *fqdn );

  /* Check no DNS nor dots in GCONF NAME */
  bool check_nodns( const char *fqdn );

  /* Build root token */
  char *build_root_token( const char *fqdn, const char *token_suffix );

#endif
