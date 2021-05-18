#include "bpceid.h"

void disp_prop_llst( property_t *p_prop_header ) {

  /* Declarations & initialisations */
  property_t *p_curr_prop = p_prop_header;

  /* Let start display of whole list */
  puts( "/*" );
  do {

    printf("  %-*s", KEY_PROP_MAX_LENGTH, p_curr_prop->key );
    printf("%-*s", VALUE_PROP_MAX_LENGTH, p_curr_prop->value );
    printf("%-*s\n", SOURCE_PROP_MAX_LENGTH, p_curr_prop->source );
    p_curr_prop =  p_curr_prop->p_prop_next;

  } while (  p_curr_prop != NULL );
  puts( "*/" );

}
