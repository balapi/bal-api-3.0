/*
<:copyright-BRCM:2018:proprietary:standard

   Broadcom Proprietary and Confidential.(c) 2018 Broadcom
   All Rights Reserved

This program is the proprietary software of Broadcom Corporation and/or its
licensors, and may only be used, duplicated, modified or distributed pursuant
to the terms and conditions of a separate, written license agreement executed
between you and Broadcom (an "Authorized License").  Except as set forth in
an Authorized License, Broadcom grants no license (express or implied), right
to use, or waiver of any kind with respect to the Software, and Broadcom
expressly reserves all rights in and to the Software and all intellectual
property rights therein.  IF YOU HAVE NO AUTHORIZED LICENSE, THEN YOU HAVE
NO RIGHT TO USE THIS SOFTWARE IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY
BROADCOM AND DISCONTINUE ALL USE OF THE SOFTWARE.

Except as expressly set forth in the Authorized License,

1. This program, including its structure, sequence and organization,
    constitutes the valuable trade secrets of Broadcom, and you shall use
    all reasonable efforts to protect the confidentiality thereof, and to
    use this information only in connection with your use of Broadcom
    integrated circuit products.

2. TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
    AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES, REPRESENTATIONS OR
    WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
    RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY DISCLAIMS ANY AND
    ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT,
    FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR
    COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE
    TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING OUT OF USE OR
    PERFORMANCE OF THE SOFTWARE.

3. TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL BROADCOM OR
    ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL, INCIDENTAL, SPECIAL,
    INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER ARISING OUT OF OR IN ANY
    WAY RELATING TO YOUR USE OF OR INABILITY TO USE THE SOFTWARE EVEN
    IF BROADCOM HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES;
    OR (ii) ANY AMOUNT IN EXCESS OF THE AMOUNT ACTUALLY PAID FOR THE
    SOFTWARE ITSELF OR U.S. $1, WHICHEVER IS GREATER. THESE LIMITATIONS
    SHALL APPLY NOTWITHSTANDING ANY FAILURE OF ESSENTIAL PURPOSE OF ANY
    LIMITED REMEDY.
:>
*/

#ifndef BCMOLT_API_MODEL_SUPPORTING_TYPEDEFS_H_
#define BCMOLT_API_MODEL_SUPPORTING_TYPEDEFS_H_

#include <bcmos_system.h>

/** \addtogroup object_model
 * @{
 */


typedef uint32_t bcmolt_ber_interval;
#define BCMOLT_BER_INTERVAL_BER_INTERVAL_NOT_CONFIGURED ((bcmolt_ber_interval)0)


typedef uint8_t bcmolt_burst_profile_index;


typedef uint64_t bcmolt_cookie;


typedef uint16_t bcmolt_epon_llid;
#define BCMOLT_EPON_LLID_BROADCAST_LLID_10_G ((bcmolt_epon_llid)32766)
#define BCMOLT_EPON_LLID_BROADCAST_LLID_1_G ((bcmolt_epon_llid)32767)
#define BCMOLT_EPON_LLID_INVALID ((bcmolt_epon_llid)65535U)


typedef uint32_t bcmolt_epon_tunnel_id;
#define BCMOLT_EPON_TUNNEL_ID_INVALID ((bcmolt_epon_tunnel_id)4294967295UL)


typedef uint16_t bcmolt_group_id;
#define BCMOLT_GROUP_ID_INVALID ((bcmolt_group_id)65535U)


typedef uint16_t bcmolt_ieee_link;
#define BCMOLT_IEEE_LINK_NEXT_FREE ((bcmolt_ieee_link)65534U)
#define BCMOLT_IEEE_LINK_INVALID ((bcmolt_ieee_link)65535U)
#define BCMOLT_IEEE_LINK_COUNT_1G10G ((bcmolt_ieee_link)2048)
#define BCMOLT_IEEE_LINK_COUNT_25G ((bcmolt_ieee_link)4096)


typedef uint8_t bcmolt_interface_id;
#define BCMOLT_INTERFACE_ID_INVALID ((bcmolt_interface_id)255)


typedef uint32_t bcmolt_mtu;
#define BCMOLT_MTU_MIN ((bcmolt_mtu)4096)
#define BCMOLT_MTU_MAX ((bcmolt_mtu)16384)


typedef uint32_t bcmolt_service_port_id;
#define BCMOLT_SERVICE_PORT_ID_INVALID ((bcmolt_service_port_id)65535UL)
#define BCMOLT_SERVICE_PORT_ID_NEXT_FREE ((bcmolt_service_port_id)65536UL)


typedef uint32_t bcmolt_time_quanta;


typedef uint8_t bcmolt_tm_priority;


typedef uint16_t bcmolt_tm_queue_id;


typedef uint16_t bcmolt_tm_sched_id;
#define BCMOLT_TM_SCHED_ID_UNKNOWN ((bcmolt_tm_sched_id)65535U)


typedef uint8_t bcmolt_tm_weight;



/** @} */

#endif
