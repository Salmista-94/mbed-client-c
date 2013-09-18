/**
 * \file sn_coap_header_internal.h
 *
 * \brief Header file for CoAP Header part
 *
 *  Created on: Jun 30, 2011
 *      Author: tero
 *
 * \note Supports draft-ietf-core-coap-18
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SN_COAP_HEADER_INTERNAL_H_
#define SN_COAP_HEADER_INTERNAL_H_

/* * * * * * * * * * * * * * * * * */
/* * * * GLOBAL DECLARATIONS * * * */
/* * * * * * * * * * * * * * * * * */

SN_MEM_ATTR_COAP_PARSER_DECL extern void* (*sn_coap_malloc)(uint16_t); /* Function pointer for used malloc() function */
SN_MEM_ATTR_COAP_PARSER_DECL extern void  (*sn_coap_free)(void*);      /* Function pointer for used free()   function */

/* * * * * * * * * * * */
/* * * * DEFINES * * * */
/* * * * * * * * * * * */

#define COAP_VERSION                                COAP_VERSION_1 /* Tells which IETF CoAP specification version the CoAP message supports. */
                                                                   /* This value is written to CoAP message header part. */

/* CoAP Header defines */
#define COAP_HEADER_LENGTH                          4   /* Fixed Header length of CoAP message as bytes */
#define COAP_HEADER_VERSION_MASK                    0xC0
#define COAP_HEADER_MSG_TYPE_MASK                   0x30
#define COAP_HEADER_TOKEN_LENGTH_MASK               0x0F
#define COAP_HEADER_MSG_ID_MSB_SHIFT                8

/* CoAP Options defines */
#define COAP_OPTIONS_OPTION_NUMBER_SHIFT            4

/* * * * * * * * * * * * * * */
/* * * * ENUMERATIONS  * * * */
/* * * * * * * * * * * * * * */

/* * * * * * * * * * * * * */
/* * * * STRUCTURES  * * * */
/* * * * * * * * * * * * * */

/* * * * * * * * * * * * * * * * * * * * * * */
/* * * * EXTERNAL FUNCTION PROTOTYPES  * * * */
/* * * * * * * * * * * * * * * * * * * * * * */
extern int8_t         	sn_coap_header_validity_check(sn_coap_hdr_s *src_coap_msg_ptr, coap_version_e coap_version);

#endif /* SN_COAP_HEADER_INTERNAL_H_ */

#ifdef __cplusplus
}
#endif