/**
 * \file sn_coap_header_check.c
 *
 * \brief CoAP Header validity checker
 *
 * Functionality: Checks validity of CoAP Header
 *
 *  Created on: Aug 22, 2011
 *      Author: tero
 *
 * \note Supports draft-ietf-core-coap-18
 */

/* * * * INCLUDE FILES * * * */
#include "nsdl_types.h"
#include "sn_nsdl.h"
#include "sn_coap_header.h"
#include "sn_coap_protocol.h"
#include "sn_coap_header_internal.h"
#include "sn_coap_protocol_internal.h"

/**
 * \fn int8_t sn_coap_header_validity_check(sn_coap_hdr_s *src_coap_msg_ptr, coap_version_e coap_version)
 *
 * \brief Checks validity of given Header
 *
 * \param *src_coap_msg_ptr is source for building Packet data
 * \param coap_version is version of used CoAP specification
 *
 * \return Return value is status of validity check. In ok cases 0 and in
 *         failure cases -1
 */
SN_MEM_ATTR_COAP_VALID_CHECK_FUNC
int8_t sn_coap_header_validity_check(sn_coap_hdr_s *src_coap_msg_ptr, coap_version_e coap_version)
{
	/* * Check validity of CoAP Version * */
    if (coap_version != COAP_VERSION_1)
    {
        return -1;
    }

    /* * Check validity of Message type * */
    switch (src_coap_msg_ptr->msg_type)
    {
		case COAP_MSG_TYPE_CONFIRMABLE:
		case COAP_MSG_TYPE_NON_CONFIRMABLE:
		case COAP_MSG_TYPE_ACKNOWLEDGEMENT:
		case COAP_MSG_TYPE_RESET:
			break;	    /* Ok cases */
		default:
			return -1;		/* Failed case */
    }

    /* * Check validity of Message code * */
    switch (src_coap_msg_ptr->msg_code)
    {
       case COAP_MSG_CODE_EMPTY:
        case COAP_MSG_CODE_REQUEST_GET:
        case COAP_MSG_CODE_REQUEST_POST:
        case COAP_MSG_CODE_REQUEST_PUT:
        case COAP_MSG_CODE_REQUEST_DELETE:
        case COAP_MSG_CODE_RESPONSE_CREATED:
        case COAP_MSG_CODE_RESPONSE_DELETED:
        case COAP_MSG_CODE_RESPONSE_VALID:
        case COAP_MSG_CODE_RESPONSE_CHANGED:
        case COAP_MSG_CODE_RESPONSE_CONTENT:
        case COAP_MSG_CODE_RESPONSE_BAD_REQUEST:
        case COAP_MSG_CODE_RESPONSE_UNAUTHORIZED:
        case COAP_MSG_CODE_RESPONSE_BAD_OPTION:
        case COAP_MSG_CODE_RESPONSE_FORBIDDEN:
        case COAP_MSG_CODE_RESPONSE_NOT_FOUND:
        case COAP_MSG_CODE_RESPONSE_METHOD_NOT_ALLOWED:
        case COAP_MSG_CODE_RESPONSE_NOT_ACCEPTABLE:
        case COAP_MSG_CODE_RESPONSE_REQUEST_ENTITY_INCOMPLETE:
        case COAP_MSG_CODE_RESPONSE_PRECONDITION_FAILED:
        case COAP_MSG_CODE_RESPONSE_REQUEST_ENTITY_TOO_LARGE:
        case COAP_MSG_CODE_RESPONSE_UNSUPPORTED_CONTENT_FORMAT:
        case COAP_MSG_CODE_RESPONSE_INTERNAL_SERVER_ERROR:
        case COAP_MSG_CODE_RESPONSE_NOT_IMPLEMENTED:
        case COAP_MSG_CODE_RESPONSE_BAD_GATEWAY:
        case COAP_MSG_CODE_RESPONSE_SERVICE_UNAVAILABLE:
        case COAP_MSG_CODE_RESPONSE_GATEWAY_TIMEOUT:
        case COAP_MSG_CODE_RESPONSE_PROXYING_NOT_SUPPORTED:
            break;	    /* Ok cases */
        default:
        	return -1;		/* Failed case */
    }

    /* Success */
    return 0;
}