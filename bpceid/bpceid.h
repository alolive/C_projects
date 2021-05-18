#ifndef BPCEID_H

  #define BPCEID_H

  #define  _GNU_SOURCE
  #include <stdio.h>
  #include <stdlib.h>
  #include <errno.h>
  #include <string.h>
  #include <dirent.h>
  #include <ctype.h>
  #include <stdbool.h>

  /* Maximum FQDN length */
  #define FQDN_MAX_LENGTH 128

  /* Maximum snippet name length */
  #define SNIPPET_NAME_MAX_LENGTH 256

  /* Maximum property key length */
  #define KEY_PROP_MAX_LENGTH 20

  /* Maximum property value length */
  #define VALUE_PROP_MAX_LENGTH 50

  /* Maximum property value length */
  #define SOURCE_PROP_MAX_LENGTH 16

  /* Snippets inventory directory */
  #define SNIPPET_DIR "/appli/ansible/inventories/bpceit_inventory_output"  

  /*
   *  Type declaration of structure to
   *  store host properties
   */
  typedef struct property_t {

    char key[KEY_PROP_MAX_LENGTH];
    char value[VALUE_PROP_MAX_LENGTH];
    char source[SOURCE_PROP_MAX_LENGTH];
    struct property_t *p_prop_prev;
    struct property_t *p_prop_next;

  } property_t;

  /* Get real inventory fqdn */
  char *get_fqdn( const char *p_short_name );

  /* Initialization of linked list and header retrieval */
  property_t *set_llst_header( const char hostname[FQDN_MAX_LENGTH] );

  /* Display properties linked list */
  void disp_prop_llst( property_t *p_prop_header );

  /* Get satellite properties for a fqdn through inventory snippet */
  property_t *get_sat_properties( property_t *current_prop, const char *fqdn );

  /* Get ansible host properties for a fqdn through inventory snippet */
  property_t *get_ansiblehost_properties( property_t *current_prop, const char *fqdn );

  /* Get DMZ properties for a fqdn through inventory snippet */
  property_t *get_dmz_properties( property_t *current_prop, const char *fqdn );

  /* Get Gconf properties for a fqdn through inventory snippet */
  property_t *get_gconf_properties( property_t *current_prop, const char *fqdn );

  /* Check whether line is a key line or not */ 
  bool is_key( const char *line );

  /* Check whether line is a list line or not */ 
  bool is_list( const char *line );

  /* Extract key from a key:value line */ 
  char *get_key( int line_size, const char *line );

  /* Extract value from a key:value line */ 
  char *get_value( int line_size, const char *line );

  /* Extract list for a key line */ 
  char *get_list( FILE *snippet );

#endif
