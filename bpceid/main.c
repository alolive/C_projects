#include "bpceid.h"

int main( int argc, char *argv[] ) {

  /* Declarations and initialisations */
  char hostname[FQDN_MAX_LENGTH] = "";
  char *p_str_saver = NULL;
  property_t *p_prop_header = NULL;
  property_t *p_prop_saver = NULL;
  property_t *p_prop_call = NULL;
  
  /* Ensure we got only one arg */
  if ( argc != 2  ) {
  
    puts("Please provide only one short hostname");
    return( 1 );
  
  }
  
  /* Does arg contains a dot ? */
  if ( strstr( argv[1], "." ) != NULL ) {
  
    puts("Please provide a non FQDN short hostname");
    return( 2 );
  
  }
  
  /* Try to get a real FQDN form arg */
  p_str_saver = get_fqdn( argv[1] );
  if ( p_str_saver == NULL ) { return( 3 ); }
  
  strcpy( hostname, p_str_saver );

  p_prop_header = set_llst_header( hostname );
  p_prop_saver = p_prop_header;

  p_prop_call = get_ansiblehost_properties( p_prop_saver, hostname );
  if ( p_prop_call != NULL ) { p_prop_saver = p_prop_call; }

  p_prop_call = get_dmz_properties( p_prop_saver, hostname );
  if ( p_prop_call != NULL ) { p_prop_saver = p_prop_call; }

  p_prop_call = get_gconf_properties( p_prop_saver, hostname );
  if ( p_prop_call != NULL ) { p_prop_saver = p_prop_call; }

  p_prop_call = get_sat_properties( p_prop_saver, hostname );

  disp_prop_llst( p_prop_header );
  
  return( 0 );

}
