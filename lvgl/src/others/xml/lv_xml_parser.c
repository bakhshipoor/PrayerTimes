/**
 * @file lv_xml.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_xml.h"
#if LV_USE_XML

#include "lv_xml_private.h"
#include "lv_xml_parser.h"
#include "lv_xml_style.h"
#include "lv_xml_component_private.h"
#include "lv_xml_base_types.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_xml_parser_state_init(lv_xml_parser_state_t * state)
{
    lv_memzero(state, sizeof(lv_xml_parser_state_t));
    lv_ll_init(&state->ctx.style_ll, sizeof(lv_xml_style_t));
    lv_ll_init(&state->ctx.const_ll, sizeof(lv_xml_const_t));
    lv_ll_init(&state->ctx.param_ll, sizeof(lv_xml_param_t));
    lv_ll_init(&state->parent_ll, sizeof(lv_obj_t *));
}

void lv_xml_parser_start_section(lv_xml_parser_state_t * state, const char * name)
{
    /* Check for context changes */
    if(lv_streq(name, "api")) {
        state->section = LV_XML_PARSER_SECTION_API;
        return;
    }
    else if(lv_streq(name, "consts")) {
        state->section = LV_XML_PARSER_SECTION_CONSTS;
        return;
    }
    else if(lv_streq(name, "styles")) {
        state->section = LV_XML_PARSER_SECTION_STYLES;
        return;
    }
    else if(lv_streq(name, "view")) {
        state->section = LV_XML_PARSER_SECTION_VIEW;
        return;
    }
}

void lv_xml_parser_end_section(lv_xml_parser_state_t * state, const char * name)
{

    /* Reset context when leaving a block */
    if(lv_streq(name, "params") ||
       lv_streq(name, "consts") ||
       lv_streq(name, "styles") ||
       lv_streq(name, "view")) {
        state->section = LV_XML_PARSER_SECTION_NONE;
    }
}

void * lv_xml_state_get_parent(lv_xml_parser_state_t * state)
{
    return state->parent;
}

void * lv_xml_state_get_item(lv_xml_parser_state_t * state)
{
    return state->item;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
