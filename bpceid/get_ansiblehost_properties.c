#include "bpceid.h"

property_t *get_ansiblehost_properties( property_t *current_prop, const char *fqdn ) {

  /* Declarations and initialisations */
  char filename[SNIPPET_NAME_MAX_LENGTH] = "";
  char source[SOURCE_PROP_MAX_LENGTH] = "(Evaluated)";
  FILE *snippet_ansh = NULL;
  char *line_buffer = NULL;
  size_t length = 0;
  ssize_t line_size = 0;
  property_t *new_prop = NULL;
  
  /* Open Ansible SSH host json snippet */
  sprintf( filename, "%s/%s%s", SNIPPET_DIR, fqdn, ".ajson" );
  snippet_ansh = fopen( filename, "r" );
  if ( snippet_ansh == NULL ) { return( NULL ); }
  
  /* parse snippet line by line */
  while (( line_size = getline( &line_buffer, &length, snippet_ansh )) != -1 ) {
  
    if ( is_key( line_buffer ) ) {

      /*  We've got a new property to register ! */
      new_prop = malloc( sizeof( property_t ) );
      if ( new_prop == NULL ) {

        perror( "Error while allocating memory..." );
        return( NULL );

      }

      /* Ensure proper list links */
      current_prop->p_prop_next = new_prop;
      new_prop->p_prop_prev = current_prop;
      new_prop->p_prop_next = NULL;

      /* Specify source for property */
      strcpy( new_prop->source, source );
      
      /* Retrieve and store key property */
      strcpy( new_prop->key, get_key( line_size, line_buffer ) );

      /* Retrieve and store value property */
      strcpy( new_prop->value, get_value( line_size, line_buffer ) );

      /* Make new prop the current one ! */
      current_prop = new_prop;

    }

  }
  
  /* Close file, free stuffs and exit */
  fclose( snippet_ansh );

  return( current_prop );

}
