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

#ifndef BCMOLT_SYSTEM_TYPES_ENUMS_H_
#define BCMOLT_SYSTEM_TYPES_ENUMS_H_

#include <bcmos_system.h>

/** \addtogroup object_model
 * @{
 */


typedef enum
{
    BCMOLT_CONN_TYPE__BEGIN = 0,
    BCMOLT_CONN_TYPE_MUX = 0, 
    BCMOLT_CONN_TYPE_APP = 1, 
    BCMOLT_CONN_TYPE_FAST = 2, 
    BCMOLT_CONN_TYPE__NUM_OF, 
} bcmolt_conn_type;


typedef enum
{
    BCMOLT_CONN_TYPE_MASK__BEGIN = 1,
    BCMOLT_CONN_TYPE_MASK_MUX = 1, 
    BCMOLT_CONN_TYPE_MASK_APP = 2, 
    BCMOLT_CONN_TYPE_MASK_FAST = 4, 
    BCMOLT_CONN_TYPE_MASK__NUM_OF, 
} bcmolt_conn_type_mask;


typedef enum
{
    BCMOLT_ENERGY_DETECT_SOURCE__BEGIN = 0,
    BCMOLT_ENERGY_DETECT_SOURCE_INTERNAL = 0, 
    BCMOLT_ENERGY_DETECT_SOURCE_TRX = 1, 
    BCMOLT_ENERGY_DETECT_SOURCE_BCDR = 2, 
    BCMOLT_ENERGY_DETECT_SOURCE__NUM_OF, 
} bcmolt_energy_detect_source;


typedef enum
{
    BCMOLT_INNI_MODE__BEGIN = 0,
    BCMOLT_INNI_MODE_ALL_1_G = 0, 
    BCMOLT_INNI_MODE_ALL_2_P_5_G = 1, 
    BCMOLT_INNI_MODE_ALL_10_G_XFI = 2, 
    BCMOLT_INNI_MODE_ALL_10_G_KR = 3, 
    BCMOLT_INNI_MODE_ALL_10_G_SFI = 4, 
    BCMOLT_INNI_MODE_ALL_12_P_5_G = 5, 
    BCMOLT_INNI_MODE_ALL_25_G_XFI = 6, 
    BCMOLT_INNI_MODE_ALL_25_G_KR = 7, 
    BCMOLT_INNI_MODE_HALF_10_G_HALF_2_P_5_G = 8, 
    BCMOLT_INNI_MODE__NUM_OF, 
} bcmolt_inni_mode;


typedef enum
{
    BCMOLT_INNI_MUX__BEGIN = 0,
    BCMOLT_INNI_MUX_NONE = 0, 
    BCMOLT_INNI_MUX_FOUR_TO_ONE = 1, 
    BCMOLT_INNI_MUX_TWO_TO_ONE = 2, 
    BCMOLT_INNI_MUX__NUM_OF, 
} bcmolt_inni_mux;



/** @} */

#endif
