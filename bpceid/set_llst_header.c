#include "bpceid.h"

property_t *set_llst_header( const char hostname[FQDN_MAX_LENGTH] ) {

  /* Declarations & initialisations */
  property_t *p_curr_prop = NULL;

  /* Allocate memory space first */
  p_curr_prop = malloc( sizeof( property_t ) ); 
  if ( p_curr_prop == NULL ) {

    /* Error display and exit. */
    perror( "Error while initializing properties list..." );
    return( NULL );

  }

  /* Set FQDN as first property and header of linked list. */
  strcpy( p_curr_prop->source, "(Satellite)" );
  strcpy( p_curr_prop->key, "fqdn" );
  strcpy( p_curr_prop->value, hostname );
  p_curr_prop->p_prop_prev = NULL;
  p_curr_prop->p_prop_next = NULL;

  return( p_curr_prop );

}
