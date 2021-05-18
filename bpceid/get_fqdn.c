#include "bpceid.h"

char *get_fqdn( const char *p_short_name ) {

  /* Declarations and initialisations */
  unsigned int i = 0;
  size_t size = 0;
  bool found = false;
  char *fqdn = NULL;
  char *p_str_ws1 = NULL;
  char *p_str_ws2 = NULL;
  DIR *inventory = NULL;
  struct dirent* snippet = NULL;
  
  /* 
   *  Memory allocation for workspace and FQDN result
   *  We use calloc as it's to have zero to terminate
   *  strings
   */
  p_str_ws1 = calloc( FQDN_MAX_LENGTH, sizeof( char ) );
  fqdn = calloc( FQDN_MAX_LENGTH, sizeof( char ) );

  /* Check if everything's fine */
  if ( fqdn == NULL || p_str_ws1 == NULL ) {
  
    /* Error display and exit. */
    perror( "Error while allocating memory..." );
    p_str_ws1 = fqdn = NULL;
    return( fqdn );
  
  }
  
  /* Lowering short hostname first */
  size = strlen( p_short_name );
  for ( i = 0; i <= size ; i++ ) {
  
    p_str_ws1[i] = tolower( p_short_name[i]);
   
  }
  
  /* Open snippet directory to seek in */
  inventory = opendir( SNIPPET_DIR );
  if ( inventory == NULL ) {
  
    /* Error display, freeing stuffs and exit. */
    perror( "Can't access to snippets inventory directory" );
    free( p_str_ws1 );
    free( fqdn );
    p_str_ws1 = fqdn = NULL;
    return( fqdn );
  
  }
  
  /* Does the directory contain host that match pattern ? */
  while ( ( snippet = readdir( inventory ) ) != NULL ) {
  
    /* Search in .sjson file only */
    if ( strstr( snippet->d_name, ".sjson" ) ) {
  
      if ( strstr( snippet->d_name, p_str_ws1 ) ) {

        /* Matching found. Save it and exit loop. */
        strcpy( p_str_ws1, snippet->d_name );
        found = true;
        break;

      }
  
    }
  
  }
  
  /* Did we find something */
  if ( !found ) {
  
    /* Error display, freeing stuffs and exit. */
    puts( "Can't find host in inventory directory" );
    free( p_str_ws1 );
    free( fqdn );
    closedir( inventory );
    p_str_ws1 = fqdn = NULL;
    return( fqdn );
  
  }
  
  /* 
   *  We have to remove file extension to get FQDN
   *  ie remove eveything after last dot found.
   */
  p_str_ws2 = strrchr( p_str_ws1, '.' );
  size = strlen( p_str_ws1 ) - strlen( p_str_ws2 );
  strncat( fqdn, p_str_ws1, size );
  
  /* Freeing stuffs and exit. */
  free( p_str_ws1 );
  closedir( inventory );
  return( fqdn );

}
