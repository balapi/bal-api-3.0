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

#ifndef BCMOLT_API_MODEL_SUPPORTING_STRUCT_FUNCS_H_
#define BCMOLT_API_MODEL_SUPPORTING_STRUCT_FUNCS_H_

#include <bcmos_system.h>
#include <bcmolt_buf.h>
#include <bcmolt_string.h>
#include <bcmolt_system_types.h>
#include "bcmolt_api_model_internal.h"
#include "bcmolt_api_model_supporting_structs.h"


void bcmolt_action_set_default(bcmolt_action *obj);


bcmos_bool bcmolt_action_pack(const bcmolt_action *obj, bcmolt_buf *buf);


uint32_t bcmolt_action_get_packed_length(const bcmolt_action *obj);


bcmos_bool bcmolt_action_unpack(bcmolt_action *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_action_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_action_validate(const bcmolt_action *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_16_set_default(bcmolt_bin_str_16 *obj);


bcmos_bool bcmolt_bin_str_16_pack(const bcmolt_bin_str_16 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_16_unpack(bcmolt_bin_str_16 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_16_validate(const bcmolt_bin_str_16 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_aes_key_set_default(bcmolt_aes_key *obj);


bcmos_bool bcmolt_aes_key_pack(const bcmolt_aes_key *obj, bcmolt_buf *buf);


uint32_t bcmolt_aes_key_get_packed_length(const bcmolt_aes_key *obj);


bcmos_bool bcmolt_aes_key_unpack(bcmolt_aes_key *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_aes_key_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_aes_key_validate(const bcmolt_aes_key *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_calibration_record_8_set_default(bcmolt_arr_calibration_record_8 *obj);


bcmos_bool bcmolt_arr_calibration_record_8_pack(const bcmolt_arr_calibration_record_8 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_calibration_record_8_get_packed_length(const bcmolt_arr_calibration_record_8 *obj);


bcmos_bool bcmolt_arr_calibration_record_8_unpack(bcmolt_arr_calibration_record_8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_calibration_record_8_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_calibration_record_8_validate(const bcmolt_arr_calibration_record_8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ds_frequency_offset_set_default(bcmolt_ds_frequency_offset *obj);


bcmos_bool bcmolt_ds_frequency_offset_pack(const bcmolt_ds_frequency_offset *obj, bcmolt_buf *buf);


uint32_t bcmolt_ds_frequency_offset_get_packed_length(const bcmolt_ds_frequency_offset *obj);


bcmos_bool bcmolt_ds_frequency_offset_unpack(bcmolt_ds_frequency_offset *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ds_frequency_offset_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ds_frequency_offset_validate(const bcmolt_ds_frequency_offset *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_id_set_default(bcmolt_pon_id *obj);


bcmos_bool bcmolt_pon_id_pack(const bcmolt_pon_id *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_id_get_packed_length(const bcmolt_pon_id *obj);


bcmos_bool bcmolt_pon_id_unpack(bcmolt_pon_id *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_id_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_id_validate(const bcmolt_pon_id *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_channel_profile_set_default(bcmolt_channel_profile *obj);


bcmos_bool bcmolt_channel_profile_pack(const bcmolt_channel_profile *obj, bcmolt_buf *buf);


uint32_t bcmolt_channel_profile_get_packed_length(const bcmolt_channel_profile *obj);


bcmos_bool bcmolt_channel_profile_unpack(bcmolt_channel_profile *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_channel_profile_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_channel_profile_validate(const bcmolt_channel_profile *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_channel_profile_8_set_default(bcmolt_arr_channel_profile_8 *obj);


bcmos_bool bcmolt_arr_channel_profile_8_pack(const bcmolt_arr_channel_profile_8 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_channel_profile_8_get_packed_length(const bcmolt_arr_channel_profile_8 *obj);


bcmos_bool bcmolt_arr_channel_profile_8_unpack(bcmolt_arr_channel_profile_8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_channel_profile_8_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_channel_profile_8_validate(const bcmolt_arr_channel_profile_8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_power_consumption_channel_report_set_default(bcmolt_power_consumption_channel_report *obj);


bcmos_bool bcmolt_power_consumption_channel_report_pack(const bcmolt_power_consumption_channel_report *obj, bcmolt_buf *buf);


uint32_t bcmolt_power_consumption_channel_report_get_packed_length(const bcmolt_power_consumption_channel_report *obj);


bcmos_bool bcmolt_power_consumption_channel_report_unpack(bcmolt_power_consumption_channel_report *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_power_consumption_channel_report_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_power_consumption_channel_report_validate(const bcmolt_power_consumption_channel_report *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_power_consumption_channel_report_8_set_default(bcmolt_arr_power_consumption_channel_report_8 *obj);


bcmos_bool bcmolt_arr_power_consumption_channel_report_8_pack(const bcmolt_arr_power_consumption_channel_report_8 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_power_consumption_channel_report_8_get_packed_length(const bcmolt_arr_power_consumption_channel_report_8 *obj);


bcmos_bool bcmolt_arr_power_consumption_channel_report_8_unpack(bcmolt_arr_power_consumption_channel_report_8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_power_consumption_channel_report_8_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_power_consumption_channel_report_8_validate(const bcmolt_arr_power_consumption_channel_report_8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_tm_queue_ref_set_default(bcmolt_tm_queue_ref *obj);


bcmos_bool bcmolt_tm_queue_ref_pack(const bcmolt_tm_queue_ref *obj, bcmolt_buf *buf);


uint32_t bcmolt_tm_queue_ref_get_packed_length(const bcmolt_tm_queue_ref *obj);


bcmos_bool bcmolt_tm_queue_ref_unpack(bcmolt_tm_queue_ref *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_tm_queue_ref_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_tm_queue_ref_validate(const bcmolt_tm_queue_ref *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_tm_queue_ref_8_set_default(bcmolt_arr_tm_queue_ref_8 *obj);


bcmos_bool bcmolt_arr_tm_queue_ref_8_pack(const bcmolt_arr_tm_queue_ref_8 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_tm_queue_ref_8_get_packed_length(const bcmolt_arr_tm_queue_ref_8 *obj);


bcmos_bool bcmolt_arr_tm_queue_ref_8_unpack(bcmolt_arr_tm_queue_ref_8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_tm_queue_ref_8_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_tm_queue_ref_8_validate(const bcmolt_arr_tm_queue_ref_8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_u16_2_set_default(bcmolt_arr_u16_2 *obj);


bcmos_bool bcmolt_arr_u16_2_pack(const bcmolt_arr_u16_2 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_u16_2_get_packed_length(const bcmolt_arr_u16_2 *obj);


bcmos_bool bcmolt_arr_u16_2_unpack(bcmolt_arr_u16_2 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_u16_2_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_u16_2_validate(const bcmolt_arr_u16_2 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_burst_profile_set_default(bcmolt_xgpon_burst_profile *obj);


bcmos_bool bcmolt_xgpon_burst_profile_pack(const bcmolt_xgpon_burst_profile *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_burst_profile_get_packed_length(const bcmolt_xgpon_burst_profile *obj);


bcmos_bool bcmolt_xgpon_burst_profile_unpack(bcmolt_xgpon_burst_profile *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_burst_profile_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_burst_profile_validate(const bcmolt_xgpon_burst_profile *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_arr_xgpon_burst_profile_4_set_default(bcmolt_arr_xgpon_burst_profile_4 *obj);


bcmos_bool bcmolt_arr_xgpon_burst_profile_4_pack(const bcmolt_arr_xgpon_burst_profile_4 *obj, bcmolt_buf *buf);


uint32_t bcmolt_arr_xgpon_burst_profile_4_get_packed_length(const bcmolt_arr_xgpon_burst_profile_4 *obj);


bcmos_bool bcmolt_arr_xgpon_burst_profile_4_unpack(bcmolt_arr_xgpon_burst_profile_4 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_arr_xgpon_burst_profile_4_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_arr_xgpon_burst_profile_4_validate(const bcmolt_arr_xgpon_burst_profile_4 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_automatic_onu_deactivation_set_default(bcmolt_automatic_onu_deactivation *obj);


bcmos_bool bcmolt_automatic_onu_deactivation_pack(const bcmolt_automatic_onu_deactivation *obj, bcmolt_buf *buf);


uint32_t bcmolt_automatic_onu_deactivation_get_packed_length(const bcmolt_automatic_onu_deactivation *obj);


bcmos_bool bcmolt_automatic_onu_deactivation_unpack(bcmolt_automatic_onu_deactivation *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_automatic_onu_deactivation_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_automatic_onu_deactivation_validate(const bcmolt_automatic_onu_deactivation *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ber_monitor_params_set_default(bcmolt_ber_monitor_params *obj);


bcmos_bool bcmolt_ber_monitor_params_pack(const bcmolt_ber_monitor_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_ber_monitor_params_get_packed_length(const bcmolt_ber_monitor_params *obj);


bcmos_bool bcmolt_ber_monitor_params_unpack(bcmolt_ber_monitor_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ber_monitor_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ber_monitor_params_validate(const bcmolt_ber_monitor_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_set_default(bcmolt_bin_str *obj);


bcmos_bool bcmolt_bin_str_pack(const bcmolt_bin_str *obj, bcmolt_buf *buf);


uint32_t bcmolt_bin_str_get_packed_length(const bcmolt_bin_str *obj);


bcmos_bool bcmolt_bin_str_unpack(bcmolt_bin_str *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_bin_str_validate(const bcmolt_bin_str *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_10_set_default(bcmolt_bin_str_10 *obj);


bcmos_bool bcmolt_bin_str_10_pack(const bcmolt_bin_str_10 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_10_unpack(bcmolt_bin_str_10 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_10_validate(const bcmolt_bin_str_10 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_13_set_default(bcmolt_bin_str_13 *obj);


bcmos_bool bcmolt_bin_str_13_pack(const bcmolt_bin_str_13 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_13_unpack(bcmolt_bin_str_13 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_13_validate(const bcmolt_bin_str_13 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_36_set_default(bcmolt_bin_str_36 *obj);


bcmos_bool bcmolt_bin_str_36_pack(const bcmolt_bin_str_36 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_36_unpack(bcmolt_bin_str_36 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_36_validate(const bcmolt_bin_str_36 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_4_set_default(bcmolt_bin_str_4 *obj);


bcmos_bool bcmolt_bin_str_4_pack(const bcmolt_bin_str_4 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_4_unpack(bcmolt_bin_str_4 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_4_validate(const bcmolt_bin_str_4 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_40_set_default(bcmolt_bin_str_40 *obj);


bcmos_bool bcmolt_bin_str_40_pack(const bcmolt_bin_str_40 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_40_unpack(bcmolt_bin_str_40 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_40_validate(const bcmolt_bin_str_40 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_bin_str_8_set_default(bcmolt_bin_str_8 *obj);


bcmos_bool bcmolt_bin_str_8_pack(const bcmolt_bin_str_8 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_bin_str_8_unpack(bcmolt_bin_str_8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_bin_str_8_validate(const bcmolt_bin_str_8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_cbr_rt_allocation_profile_set_default(bcmolt_cbr_rt_allocation_profile *obj);


bcmos_bool bcmolt_cbr_rt_allocation_profile_pack(const bcmolt_cbr_rt_allocation_profile *obj, bcmolt_buf *buf);


uint32_t bcmolt_cbr_rt_allocation_profile_get_packed_length(const bcmolt_cbr_rt_allocation_profile *obj);


bcmos_bool bcmolt_cbr_rt_allocation_profile_unpack(bcmolt_cbr_rt_allocation_profile *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_cbr_rt_allocation_profile_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_cbr_rt_allocation_profile_validate(const bcmolt_cbr_rt_allocation_profile *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_classifier_set_default(bcmolt_classifier *obj);


bcmos_bool bcmolt_classifier_pack(const bcmolt_classifier *obj, bcmolt_buf *buf);


uint32_t bcmolt_classifier_get_packed_length(const bcmolt_classifier *obj);


bcmos_bool bcmolt_classifier_unpack(bcmolt_classifier *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_classifier_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_classifier_validate(const bcmolt_classifier *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ddr_test_completed_set_default(bcmolt_ddr_test_completed *obj);


bcmos_bool bcmolt_ddr_test_completed_pack(const bcmolt_ddr_test_completed *obj, bcmolt_buf *buf);


uint32_t bcmolt_ddr_test_completed_get_packed_length(const bcmolt_ddr_test_completed *obj);


bcmos_bool bcmolt_ddr_test_completed_unpack(bcmolt_ddr_test_completed *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ddr_test_completed_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ddr_test_completed_validate(const bcmolt_ddr_test_completed *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_debug_device_cfg_set_default(bcmolt_debug_device_cfg *obj);


bcmos_bool bcmolt_debug_device_cfg_pack(const bcmolt_debug_device_cfg *obj, bcmolt_buf *buf);


uint32_t bcmolt_debug_device_cfg_get_packed_length(const bcmolt_debug_device_cfg *obj);


bcmos_bool bcmolt_debug_device_cfg_unpack(bcmolt_debug_device_cfg *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_debug_device_cfg_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_debug_device_cfg_validate(const bcmolt_debug_device_cfg *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_debug_flow_config_set_default(bcmolt_debug_flow_config *obj);


bcmos_bool bcmolt_debug_flow_config_pack(const bcmolt_debug_flow_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_debug_flow_config_get_packed_length(const bcmolt_debug_flow_config *obj);


bcmos_bool bcmolt_debug_flow_config_unpack(bcmolt_debug_flow_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_debug_flow_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_debug_flow_config_validate(const bcmolt_debug_flow_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_tm_sched_ref_set_default(bcmolt_tm_sched_ref *obj);


bcmos_bool bcmolt_tm_sched_ref_pack(const bcmolt_tm_sched_ref *obj, bcmolt_buf *buf);


uint32_t bcmolt_tm_sched_ref_get_packed_length(const bcmolt_tm_sched_ref *obj);


bcmos_bool bcmolt_tm_sched_ref_unpack(bcmolt_tm_sched_ref *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_tm_sched_ref_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_tm_sched_ref_validate(const bcmolt_tm_sched_ref *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_egress_qos_set_default(bcmolt_egress_qos *obj);


bcmos_bool bcmolt_egress_qos_pack(const bcmolt_egress_qos *obj, bcmolt_buf *buf);


uint32_t bcmolt_egress_qos_get_packed_length(const bcmolt_egress_qos *obj);


bcmos_bool bcmolt_egress_qos_unpack(bcmolt_egress_qos *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_egress_qos_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_egress_qos_validate(const bcmolt_egress_qos *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_64_set_default(bcmolt_str_64 *obj);


bcmos_bool bcmolt_str_64_pack(const bcmolt_str_64 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_64_unpack(bcmolt_str_64 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_64_validate(const bcmolt_str_64 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_embedded_image_entry_set_default(bcmolt_embedded_image_entry *obj);


bcmos_bool bcmolt_embedded_image_entry_pack(const bcmolt_embedded_image_entry *obj, bcmolt_buf *buf);


uint32_t bcmolt_embedded_image_entry_get_packed_length(const bcmolt_embedded_image_entry *obj);


bcmos_bool bcmolt_embedded_image_entry_unpack(bcmolt_embedded_image_entry *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_embedded_image_entry_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_embedded_image_entry_validate(const bcmolt_embedded_image_entry *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_embedded_image_entry_list_u8_max_4_set_default(bcmolt_embedded_image_entry_list_u8_max_4 *obj);


bcmos_bool bcmolt_embedded_image_entry_list_u8_max_4_pack(const bcmolt_embedded_image_entry_list_u8_max_4 *obj, bcmolt_buf *buf);


uint32_t bcmolt_embedded_image_entry_list_u8_max_4_get_packed_length(const bcmolt_embedded_image_entry_list_u8_max_4 *obj);


bcmos_bool bcmolt_embedded_image_entry_list_u8_max_4_unpack(bcmolt_embedded_image_entry_list_u8_max_4 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_embedded_image_entry_list_u8_max_4_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_embedded_image_entry_list_u8_max_4_validate(const bcmolt_embedded_image_entry_list_u8_max_4 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_epon_tunnel_id_range_set_default(bcmolt_epon_tunnel_id_range *obj);


bcmos_bool bcmolt_epon_tunnel_id_range_pack(const bcmolt_epon_tunnel_id_range *obj, bcmolt_buf *buf);


uint32_t bcmolt_epon_tunnel_id_range_get_packed_length(const bcmolt_epon_tunnel_id_range *obj);


bcmos_bool bcmolt_epon_tunnel_id_range_unpack(bcmolt_epon_tunnel_id_range *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_epon_tunnel_id_range_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_epon_tunnel_id_range_validate(const bcmolt_epon_tunnel_id_range *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_32_set_default(bcmolt_str_32 *obj);


bcmos_bool bcmolt_str_32_pack(const bcmolt_str_32 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_32_unpack(bcmolt_str_32 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_32_validate(const bcmolt_str_32 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_firmware_sw_version_set_default(bcmolt_firmware_sw_version *obj);


bcmos_bool bcmolt_firmware_sw_version_pack(const bcmolt_firmware_sw_version *obj, bcmolt_buf *buf);


uint32_t bcmolt_firmware_sw_version_get_packed_length(const bcmolt_firmware_sw_version *obj);


bcmos_bool bcmolt_firmware_sw_version_unpack(bcmolt_firmware_sw_version *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_firmware_sw_version_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_firmware_sw_version_validate(const bcmolt_firmware_sw_version *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_flow_intf_ref_set_default(bcmolt_flow_intf_ref *obj);


bcmos_bool bcmolt_flow_intf_ref_pack(const bcmolt_flow_intf_ref *obj, bcmolt_buf *buf);


uint32_t bcmolt_flow_intf_ref_get_packed_length(const bcmolt_flow_intf_ref *obj);


bcmos_bool bcmolt_flow_intf_ref_unpack(bcmolt_flow_intf_ref *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_flow_intf_ref_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_flow_intf_ref_validate(const bcmolt_flow_intf_ref *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gem_port_configuration_set_default(bcmolt_gem_port_configuration *obj);


bcmos_bool bcmolt_gem_port_configuration_pack(const bcmolt_gem_port_configuration *obj, bcmolt_buf *buf);


uint32_t bcmolt_gem_port_configuration_get_packed_length(const bcmolt_gem_port_configuration *obj);


bcmos_bool bcmolt_gem_port_configuration_unpack(bcmolt_gem_port_configuration *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gem_port_configuration_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gem_port_configuration_validate(const bcmolt_gem_port_configuration *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gem_port_id_list_u8_max_16_set_default(bcmolt_gem_port_id_list_u8_max_16 *obj);


bcmos_bool bcmolt_gem_port_id_list_u8_max_16_pack(const bcmolt_gem_port_id_list_u8_max_16 *obj, bcmolt_buf *buf);


uint32_t bcmolt_gem_port_id_list_u8_max_16_get_packed_length(const bcmolt_gem_port_id_list_u8_max_16 *obj);


bcmos_bool bcmolt_gem_port_id_list_u8_max_16_unpack(bcmolt_gem_port_id_list_u8_max_16 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gem_port_id_list_u8_max_16_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gem_port_id_list_u8_max_16_validate(const bcmolt_gem_port_id_list_u8_max_16 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_onu_alarm_state_set_default(bcmolt_gpon_onu_alarm_state *obj);


bcmos_bool bcmolt_gpon_onu_alarm_state_pack(const bcmolt_gpon_onu_alarm_state *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_onu_alarm_state_get_packed_length(const bcmolt_gpon_onu_alarm_state *obj);


bcmos_bool bcmolt_gpon_onu_alarm_state_unpack(bcmolt_gpon_onu_alarm_state *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_onu_alarm_state_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_onu_alarm_state_validate(const bcmolt_gpon_onu_alarm_state *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_onu_alarms_set_default(bcmolt_gpon_onu_alarms *obj);


bcmos_bool bcmolt_gpon_onu_alarms_pack(const bcmolt_gpon_onu_alarms *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_onu_alarms_get_packed_length(const bcmolt_gpon_onu_alarms *obj);


bcmos_bool bcmolt_gpon_onu_alarms_unpack(bcmolt_gpon_onu_alarms *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_onu_alarms_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_onu_alarms_validate(const bcmolt_gpon_onu_alarms *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_onu_alarms_thresholds_set_default(bcmolt_gpon_onu_alarms_thresholds *obj);


bcmos_bool bcmolt_gpon_onu_alarms_thresholds_pack(const bcmolt_gpon_onu_alarms_thresholds *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_onu_alarms_thresholds_get_packed_length(const bcmolt_gpon_onu_alarms_thresholds *obj);


bcmos_bool bcmolt_gpon_onu_alarms_thresholds_unpack(bcmolt_gpon_onu_alarms_thresholds *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_onu_alarms_thresholds_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_onu_alarms_thresholds_validate(const bcmolt_gpon_onu_alarms_thresholds *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_onu_params_set_default(bcmolt_gpon_onu_params *obj);


bcmos_bool bcmolt_gpon_onu_params_pack(const bcmolt_gpon_onu_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_onu_params_get_packed_length(const bcmolt_gpon_onu_params *obj);


bcmos_bool bcmolt_gpon_onu_params_unpack(bcmolt_gpon_onu_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_onu_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_onu_params_validate(const bcmolt_gpon_onu_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_power_level_set_default(bcmolt_pon_power_level *obj);


bcmos_bool bcmolt_pon_power_level_pack(const bcmolt_pon_power_level *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_power_level_get_packed_length(const bcmolt_pon_power_level *obj);


bcmos_bool bcmolt_pon_power_level_unpack(bcmolt_pon_power_level *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_power_level_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_power_level_validate(const bcmolt_pon_power_level *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_pon_params_set_default(bcmolt_gpon_pon_params *obj);


bcmos_bool bcmolt_gpon_pon_params_pack(const bcmolt_gpon_pon_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_pon_params_get_packed_length(const bcmolt_gpon_pon_params *obj);


bcmos_bool bcmolt_gpon_pon_params_unpack(bcmolt_gpon_pon_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_pon_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_pon_params_validate(const bcmolt_gpon_pon_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_gpon_trx_set_default(bcmolt_gpon_trx *obj);


bcmos_bool bcmolt_gpon_trx_pack(const bcmolt_gpon_trx *obj, bcmolt_buf *buf);


uint32_t bcmolt_gpon_trx_get_packed_length(const bcmolt_gpon_trx *obj);


bcmos_bool bcmolt_gpon_trx_unpack(bcmolt_gpon_trx *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_gpon_trx_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_gpon_trx_validate(const bcmolt_gpon_trx *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_intf_ref_set_default(bcmolt_intf_ref *obj);


bcmos_bool bcmolt_intf_ref_pack(const bcmolt_intf_ref *obj, bcmolt_buf *buf);


uint32_t bcmolt_intf_ref_get_packed_length(const bcmolt_intf_ref *obj);


bcmos_bool bcmolt_intf_ref_unpack(bcmolt_intf_ref *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_intf_ref_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_intf_ref_validate(const bcmolt_intf_ref *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_group_member_info_set_default(bcmolt_group_member_info *obj);


bcmos_bool bcmolt_group_member_info_pack(const bcmolt_group_member_info *obj, bcmolt_buf *buf);


uint32_t bcmolt_group_member_info_get_packed_length(const bcmolt_group_member_info *obj);


bcmos_bool bcmolt_group_member_info_unpack(bcmolt_group_member_info *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_group_member_info_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_group_member_info_validate(const bcmolt_group_member_info *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_group_member_info_list_u8_set_default(bcmolt_group_member_info_list_u8 *obj);


bcmos_bool bcmolt_group_member_info_list_u8_pack(const bcmolt_group_member_info_list_u8 *obj, bcmolt_buf *buf);


uint32_t bcmolt_group_member_info_list_u8_get_packed_length(const bcmolt_group_member_info_list_u8 *obj);


bcmos_bool bcmolt_group_member_info_list_u8_unpack(bcmolt_group_member_info_list_u8 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_group_member_info_list_u8_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_group_member_info_list_u8_validate(const bcmolt_group_member_info_list_u8 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_group_members_update_command_set_default(bcmolt_group_members_update_command *obj);


bcmos_bool bcmolt_group_members_update_command_pack(const bcmolt_group_members_update_command *obj, bcmolt_buf *buf);


uint32_t bcmolt_group_members_update_command_get_packed_length(const bcmolt_group_members_update_command *obj);


bcmos_bool bcmolt_group_members_update_command_unpack(bcmolt_group_members_update_command *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_group_members_update_command_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_group_members_update_command_validate(const bcmolt_group_members_update_command *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_host_sw_version_set_default(bcmolt_host_sw_version *obj);


bcmos_bool bcmolt_host_sw_version_pack(const bcmolt_host_sw_version *obj, bcmolt_buf *buf);


uint32_t bcmolt_host_sw_version_get_packed_length(const bcmolt_host_sw_version *obj);


bcmos_bool bcmolt_host_sw_version_unpack(bcmolt_host_sw_version *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_host_sw_version_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_host_sw_version_validate(const bcmolt_host_sw_version *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_hw_pon_id_set_default(bcmolt_hw_pon_id *obj);


bcmos_bool bcmolt_hw_pon_id_pack(const bcmolt_hw_pon_id *obj, bcmolt_buf *buf);


uint32_t bcmolt_hw_pon_id_get_packed_length(const bcmolt_hw_pon_id *obj);


bcmos_bool bcmolt_hw_pon_id_unpack(bcmolt_hw_pon_id *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_hw_pon_id_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_hw_pon_id_validate(const bcmolt_hw_pon_id *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_256_set_default(bcmolt_str_256 *obj);


bcmos_bool bcmolt_str_256_pack(const bcmolt_str_256 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_256_unpack(bcmolt_str_256 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_256_validate(const bcmolt_str_256 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ieee_8021_as_tod_set_default(bcmolt_ieee_8021_as_tod *obj);


bcmos_bool bcmolt_ieee_8021_as_tod_pack(const bcmolt_ieee_8021_as_tod *obj, bcmolt_buf *buf);


uint32_t bcmolt_ieee_8021_as_tod_get_packed_length(const bcmolt_ieee_8021_as_tod *obj);


bcmos_bool bcmolt_ieee_8021_as_tod_unpack(bcmolt_ieee_8021_as_tod *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ieee_8021_as_tod_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ieee_8021_as_tod_validate(const bcmolt_ieee_8021_as_tod *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_inband_conn_data_set_default(bcmolt_inband_conn_data *obj);


bcmos_bool bcmolt_inband_conn_data_pack(const bcmolt_inband_conn_data *obj, bcmolt_buf *buf);


uint32_t bcmolt_inband_conn_data_get_packed_length(const bcmolt_inband_conn_data *obj);


bcmos_bool bcmolt_inband_conn_data_unpack(bcmolt_inband_conn_data *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_inband_conn_data_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_inband_conn_data_validate(const bcmolt_inband_conn_data *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_indication_shaping_set_default(bcmolt_indication_shaping *obj);


bcmos_bool bcmolt_indication_shaping_pack(const bcmolt_indication_shaping *obj, bcmolt_buf *buf);


uint32_t bcmolt_indication_shaping_get_packed_length(const bcmolt_indication_shaping *obj);


bcmos_bool bcmolt_indication_shaping_unpack(bcmolt_indication_shaping *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_indication_shaping_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_indication_shaping_validate(const bcmolt_indication_shaping *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_inni_config_set_default(bcmolt_inni_config *obj);


bcmos_bool bcmolt_inni_config_pack(const bcmolt_inni_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_inni_config_get_packed_length(const bcmolt_inni_config *obj);


bcmos_bool bcmolt_inni_config_unpack(bcmolt_inni_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_inni_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_inni_config_validate(const bcmolt_inni_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_serial_number_set_default(bcmolt_serial_number *obj);


bcmos_bool bcmolt_serial_number_pack(const bcmolt_serial_number *obj, bcmolt_buf *buf);


uint32_t bcmolt_serial_number_get_packed_length(const bcmolt_serial_number *obj);


bcmos_bool bcmolt_serial_number_unpack(bcmolt_serial_number *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_serial_number_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_serial_number_validate(const bcmolt_serial_number *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itupon_onu_aes_key_set_default(bcmolt_itupon_onu_aes_key *obj);


bcmos_bool bcmolt_itupon_onu_aes_key_pack(const bcmolt_itupon_onu_aes_key *obj, bcmolt_buf *buf);


uint32_t bcmolt_itupon_onu_aes_key_get_packed_length(const bcmolt_itupon_onu_aes_key *obj);


bcmos_bool bcmolt_itupon_onu_aes_key_unpack(bcmolt_itupon_onu_aes_key *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itupon_onu_aes_key_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itupon_onu_aes_key_validate(const bcmolt_itupon_onu_aes_key *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_alarm_state_set_default(bcmolt_xgpon_onu_alarm_state *obj);


bcmos_bool bcmolt_xgpon_onu_alarm_state_pack(const bcmolt_xgpon_onu_alarm_state *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_alarm_state_get_packed_length(const bcmolt_xgpon_onu_alarm_state *obj);


bcmos_bool bcmolt_xgpon_onu_alarm_state_unpack(bcmolt_xgpon_onu_alarm_state *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarm_state_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarm_state_validate(const bcmolt_xgpon_onu_alarm_state *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ngpon2_onu_params_set_default(bcmolt_ngpon2_onu_params *obj);


bcmos_bool bcmolt_ngpon2_onu_params_pack(const bcmolt_ngpon2_onu_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_ngpon2_onu_params_get_packed_length(const bcmolt_ngpon2_onu_params *obj);


bcmos_bool bcmolt_ngpon2_onu_params_unpack(bcmolt_ngpon2_onu_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ngpon2_onu_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ngpon2_onu_params_validate(const bcmolt_ngpon2_onu_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_registration_keys_set_default(bcmolt_xgpon_onu_registration_keys *obj);


bcmos_bool bcmolt_xgpon_onu_registration_keys_pack(const bcmolt_xgpon_onu_registration_keys *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_registration_keys_get_packed_length(const bcmolt_xgpon_onu_registration_keys *obj);


bcmos_bool bcmolt_xgpon_onu_registration_keys_unpack(bcmolt_xgpon_onu_registration_keys *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_registration_keys_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_registration_keys_validate(const bcmolt_xgpon_onu_registration_keys *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_request_registration_status_set_default(bcmolt_request_registration_status *obj);


bcmos_bool bcmolt_request_registration_status_pack(const bcmolt_request_registration_status *obj, bcmolt_buf *buf);


uint32_t bcmolt_request_registration_status_get_packed_length(const bcmolt_request_registration_status *obj);


bcmos_bool bcmolt_request_registration_status_unpack(bcmolt_request_registration_status *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_request_registration_status_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_request_registration_status_validate(const bcmolt_request_registration_status *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_params_set_default(bcmolt_xgpon_onu_params *obj);


bcmos_bool bcmolt_xgpon_onu_params_pack(const bcmolt_xgpon_onu_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_params_get_packed_length(const bcmolt_xgpon_onu_params *obj);


bcmos_bool bcmolt_xgpon_onu_params_unpack(bcmolt_xgpon_onu_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_params_validate(const bcmolt_xgpon_onu_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itu_onu_params_set_default(bcmolt_itu_onu_params *obj);


bcmos_bool bcmolt_itu_onu_params_pack(const bcmolt_itu_onu_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_itu_onu_params_get_packed_length(const bcmolt_itu_onu_params *obj);


bcmos_bool bcmolt_itu_onu_params_unpack(bcmolt_itu_onu_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itu_onu_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itu_onu_params_validate(const bcmolt_itu_onu_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_available_bandwidth_set_default(bcmolt_pon_available_bandwidth *obj);


bcmos_bool bcmolt_pon_available_bandwidth_pack(const bcmolt_pon_available_bandwidth *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_available_bandwidth_get_packed_length(const bcmolt_pon_available_bandwidth *obj);


bcmos_bool bcmolt_pon_available_bandwidth_unpack(bcmolt_pon_available_bandwidth *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_available_bandwidth_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_available_bandwidth_validate(const bcmolt_pon_available_bandwidth *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_drift_control_set_default(bcmolt_pon_drift_control *obj);


bcmos_bool bcmolt_pon_drift_control_pack(const bcmolt_pon_drift_control *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_drift_control_get_packed_length(const bcmolt_pon_drift_control *obj);


bcmos_bool bcmolt_pon_drift_control_unpack(bcmolt_pon_drift_control *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_drift_control_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_drift_control_validate(const bcmolt_pon_drift_control *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_activation_set_default(bcmolt_onu_activation *obj);


bcmos_bool bcmolt_onu_activation_pack(const bcmolt_onu_activation *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_activation_get_packed_length(const bcmolt_onu_activation *obj);


bcmos_bool bcmolt_onu_activation_unpack(bcmolt_onu_activation *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_activation_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_activation_validate(const bcmolt_onu_activation *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_key_exchange_set_default(bcmolt_key_exchange *obj);


bcmos_bool bcmolt_key_exchange_pack(const bcmolt_key_exchange *obj, bcmolt_buf *buf);


uint32_t bcmolt_key_exchange_get_packed_length(const bcmolt_key_exchange *obj);


bcmos_bool bcmolt_key_exchange_unpack(bcmolt_key_exchange *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_key_exchange_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_key_exchange_validate(const bcmolt_key_exchange *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_power_management_configuration_set_default(bcmolt_onu_power_management_configuration *obj);


bcmos_bool bcmolt_onu_power_management_configuration_pack(const bcmolt_onu_power_management_configuration *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_power_management_configuration_get_packed_length(const bcmolt_onu_power_management_configuration *obj);


bcmos_bool bcmolt_onu_power_management_configuration_unpack(bcmolt_onu_power_management_configuration *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_power_management_configuration_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_power_management_configuration_validate(const bcmolt_onu_power_management_configuration *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_periodic_standby_pon_monitoring_set_default(bcmolt_periodic_standby_pon_monitoring *obj);


bcmos_bool bcmolt_periodic_standby_pon_monitoring_pack(const bcmolt_periodic_standby_pon_monitoring *obj, bcmolt_buf *buf);


uint32_t bcmolt_periodic_standby_pon_monitoring_get_packed_length(const bcmolt_periodic_standby_pon_monitoring *obj);


bcmos_bool bcmolt_periodic_standby_pon_monitoring_unpack(bcmolt_periodic_standby_pon_monitoring *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_periodic_standby_pon_monitoring_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_periodic_standby_pon_monitoring_validate(const bcmolt_periodic_standby_pon_monitoring *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_prbs_checker_config_set_default(bcmolt_prbs_checker_config *obj);


bcmos_bool bcmolt_prbs_checker_config_pack(const bcmolt_prbs_checker_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_prbs_checker_config_get_packed_length(const bcmolt_prbs_checker_config *obj);


bcmos_bool bcmolt_prbs_checker_config_unpack(bcmolt_prbs_checker_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_prbs_checker_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_prbs_checker_config_validate(const bcmolt_prbs_checker_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_prbs_generator_config_set_default(bcmolt_prbs_generator_config *obj);


bcmos_bool bcmolt_prbs_generator_config_pack(const bcmolt_prbs_generator_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_prbs_generator_config_get_packed_length(const bcmolt_prbs_generator_config *obj);


bcmos_bool bcmolt_prbs_generator_config_unpack(bcmolt_prbs_generator_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_prbs_generator_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_prbs_generator_config_validate(const bcmolt_prbs_generator_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_prbs_status_set_default(bcmolt_prbs_status *obj);


bcmos_bool bcmolt_prbs_status_pack(const bcmolt_prbs_status *obj, bcmolt_buf *buf);


uint32_t bcmolt_prbs_status_get_packed_length(const bcmolt_prbs_status *obj);


bcmos_bool bcmolt_prbs_status_unpack(bcmolt_prbs_status *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_prbs_status_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_prbs_status_validate(const bcmolt_prbs_status *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itupon_protection_switching_set_default(bcmolt_itupon_protection_switching *obj);


bcmos_bool bcmolt_itupon_protection_switching_pack(const bcmolt_itupon_protection_switching *obj, bcmolt_buf *buf);


uint32_t bcmolt_itupon_protection_switching_get_packed_length(const bcmolt_itupon_protection_switching *obj);


bcmos_bool bcmolt_itupon_protection_switching_unpack(bcmolt_itupon_protection_switching *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itupon_protection_switching_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itupon_protection_switching_validate(const bcmolt_itupon_protection_switching *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ituonu_upgrade_params_set_default(bcmolt_ituonu_upgrade_params *obj);


bcmos_bool bcmolt_ituonu_upgrade_params_pack(const bcmolt_ituonu_upgrade_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_ituonu_upgrade_params_get_packed_length(const bcmolt_ituonu_upgrade_params *obj);


bcmos_bool bcmolt_ituonu_upgrade_params_unpack(bcmolt_ituonu_upgrade_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ituonu_upgrade_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ituonu_upgrade_params_validate(const bcmolt_ituonu_upgrade_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_upgrade_status_set_default(bcmolt_onu_upgrade_status *obj);


bcmos_bool bcmolt_onu_upgrade_status_pack(const bcmolt_onu_upgrade_status *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_upgrade_status_get_packed_length(const bcmolt_onu_upgrade_status *obj);


bcmos_bool bcmolt_onu_upgrade_status_unpack(bcmolt_onu_upgrade_status *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_upgrade_status_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_upgrade_status_validate(const bcmolt_onu_upgrade_status *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_upgrade_status_list_u32_max_128_set_default(bcmolt_onu_upgrade_status_list_u32_max_128 *obj);


bcmos_bool bcmolt_onu_upgrade_status_list_u32_max_128_pack(const bcmolt_onu_upgrade_status_list_u32_max_128 *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_upgrade_status_list_u32_max_128_get_packed_length(const bcmolt_onu_upgrade_status_list_u32_max_128 *obj);


bcmos_bool bcmolt_onu_upgrade_status_list_u32_max_128_unpack(bcmolt_onu_upgrade_status_list_u32_max_128 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_upgrade_status_list_u32_max_128_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_upgrade_status_list_u32_max_128_validate(const bcmolt_onu_upgrade_status_list_u32_max_128 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_onu_upgrade_status_set_default(bcmolt_pon_onu_upgrade_status *obj);


bcmos_bool bcmolt_pon_onu_upgrade_status_pack(const bcmolt_pon_onu_upgrade_status *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_onu_upgrade_status_get_packed_length(const bcmolt_pon_onu_upgrade_status *obj);


bcmos_bool bcmolt_pon_onu_upgrade_status_unpack(bcmolt_pon_onu_upgrade_status *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_onu_upgrade_status_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_onu_upgrade_status_validate(const bcmolt_pon_onu_upgrade_status *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_alarms_thresholds_set_default(bcmolt_xgpon_onu_alarms_thresholds *obj);


bcmos_bool bcmolt_xgpon_onu_alarms_thresholds_pack(const bcmolt_xgpon_onu_alarms_thresholds *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_alarms_thresholds_get_packed_length(const bcmolt_xgpon_onu_alarms_thresholds *obj);


bcmos_bool bcmolt_xgpon_onu_alarms_thresholds_unpack(bcmolt_xgpon_onu_alarms_thresholds *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarms_thresholds_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarms_thresholds_validate(const bcmolt_xgpon_onu_alarms_thresholds *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_alarm_indication_control_set_default(bcmolt_xgpon_onu_alarm_indication_control *obj);


bcmos_bool bcmolt_xgpon_onu_alarm_indication_control_pack(const bcmolt_xgpon_onu_alarm_indication_control *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_alarm_indication_control_get_packed_length(const bcmolt_xgpon_onu_alarm_indication_control *obj);


bcmos_bool bcmolt_xgpon_onu_alarm_indication_control_unpack(bcmolt_xgpon_onu_alarm_indication_control *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarm_indication_control_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarm_indication_control_validate(const bcmolt_xgpon_onu_alarm_indication_control *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_multicast_key_set_default(bcmolt_xgpon_multicast_key *obj);


bcmos_bool bcmolt_xgpon_multicast_key_pack(const bcmolt_xgpon_multicast_key *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_multicast_key_get_packed_length(const bcmolt_xgpon_multicast_key *obj);


bcmos_bool bcmolt_xgpon_multicast_key_unpack(bcmolt_xgpon_multicast_key *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_multicast_key_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_multicast_key_validate(const bcmolt_xgpon_multicast_key *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_tuning_configuration_set_default(bcmolt_onu_tuning_configuration *obj);


bcmos_bool bcmolt_onu_tuning_configuration_pack(const bcmolt_onu_tuning_configuration *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_tuning_configuration_get_packed_length(const bcmolt_onu_tuning_configuration *obj);


bcmos_bool bcmolt_onu_tuning_configuration_unpack(bcmolt_onu_tuning_configuration *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_tuning_configuration_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_tuning_configuration_validate(const bcmolt_onu_tuning_configuration *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ngpon2_pon_params_set_default(bcmolt_ngpon2_pon_params *obj);


bcmos_bool bcmolt_ngpon2_pon_params_pack(const bcmolt_ngpon2_pon_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_ngpon2_pon_params_get_packed_length(const bcmolt_ngpon2_pon_params *obj);


bcmos_bool bcmolt_ngpon2_pon_params_unpack(bcmolt_ngpon2_pon_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ngpon2_pon_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ngpon2_pon_params_validate(const bcmolt_ngpon2_pon_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_ploam_retransmission_set_default(bcmolt_ploam_retransmission *obj);


bcmos_bool bcmolt_ploam_retransmission_pack(const bcmolt_ploam_retransmission *obj, bcmolt_buf *buf);


uint32_t bcmolt_ploam_retransmission_get_packed_length(const bcmolt_ploam_retransmission *obj);


bcmos_bool bcmolt_ploam_retransmission_unpack(bcmolt_ploam_retransmission *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_ploam_retransmission_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_ploam_retransmission_validate(const bcmolt_ploam_retransmission *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_operation_control_set_default(bcmolt_operation_control *obj);


bcmos_bool bcmolt_operation_control_pack(const bcmolt_operation_control *obj, bcmolt_buf *buf);


uint32_t bcmolt_operation_control_get_packed_length(const bcmolt_operation_control *obj);


bcmos_bool bcmolt_operation_control_unpack(bcmolt_operation_control *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_operation_control_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_operation_control_validate(const bcmolt_operation_control *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_pon_params_set_default(bcmolt_xgpon_pon_params *obj);


bcmos_bool bcmolt_xgpon_pon_params_pack(const bcmolt_xgpon_pon_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_pon_params_get_packed_length(const bcmolt_xgpon_pon_params *obj);


bcmos_bool bcmolt_xgpon_pon_params_unpack(bcmolt_xgpon_pon_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_pon_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_pon_params_validate(const bcmolt_xgpon_pon_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itu_pon_params_set_default(bcmolt_itu_pon_params *obj);


bcmos_bool bcmolt_itu_pon_params_pack(const bcmolt_itu_pon_params *obj, bcmolt_buf *buf);


uint32_t bcmolt_itu_pon_params_get_packed_length(const bcmolt_itu_pon_params *obj);


bcmos_bool bcmolt_itu_pon_params_unpack(bcmolt_itu_pon_params *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itu_pon_params_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itu_pon_params_validate(const bcmolt_itu_pon_params *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itu_tod_set_default(bcmolt_itu_tod *obj);


bcmos_bool bcmolt_itu_tod_pack(const bcmolt_itu_tod *obj, bcmolt_buf *buf);


uint32_t bcmolt_itu_tod_get_packed_length(const bcmolt_itu_tod *obj);


bcmos_bool bcmolt_itu_tod_unpack(bcmolt_itu_tod *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itu_tod_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itu_tod_validate(const bcmolt_itu_tod *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itupon_onu_eqd_set_default(bcmolt_itupon_onu_eqd *obj);


bcmos_bool bcmolt_itupon_onu_eqd_pack(const bcmolt_itupon_onu_eqd *obj, bcmolt_buf *buf);


uint32_t bcmolt_itupon_onu_eqd_get_packed_length(const bcmolt_itupon_onu_eqd *obj);


bcmos_bool bcmolt_itupon_onu_eqd_unpack(bcmolt_itupon_onu_eqd *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itupon_onu_eqd_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itupon_onu_eqd_validate(const bcmolt_itupon_onu_eqd *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_itupon_onu_eqd_list_u32_set_default(bcmolt_itupon_onu_eqd_list_u32 *obj);


bcmos_bool bcmolt_itupon_onu_eqd_list_u32_pack(const bcmolt_itupon_onu_eqd_list_u32 *obj, bcmolt_buf *buf);


uint32_t bcmolt_itupon_onu_eqd_list_u32_get_packed_length(const bcmolt_itupon_onu_eqd_list_u32 *obj);


bcmos_bool bcmolt_itupon_onu_eqd_list_u32_unpack(bcmolt_itupon_onu_eqd_list_u32 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_itupon_onu_eqd_list_u32_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_itupon_onu_eqd_list_u32_validate(const bcmolt_itupon_onu_eqd_list_u32 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_log_level_msg_count_set_default(bcmolt_log_level_msg_count *obj);


bcmos_bool bcmolt_log_level_msg_count_pack(const bcmolt_log_level_msg_count *obj, bcmolt_buf *buf);


uint32_t bcmolt_log_level_msg_count_get_packed_length(const bcmolt_log_level_msg_count *obj);


bcmos_bool bcmolt_log_level_msg_count_unpack(bcmolt_log_level_msg_count *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_log_level_msg_count_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_log_level_msg_count_validate(const bcmolt_log_level_msg_count *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_log_level_per_file_set_default(bcmolt_log_level_per_file *obj);


bcmos_bool bcmolt_log_level_per_file_pack(const bcmolt_log_level_per_file *obj, bcmolt_buf *buf);


uint32_t bcmolt_log_level_per_file_get_packed_length(const bcmolt_log_level_per_file *obj);


bcmos_bool bcmolt_log_level_per_file_unpack(bcmolt_log_level_per_file *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_log_level_per_file_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_log_level_per_file_validate(const bcmolt_log_level_per_file *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_nni_link_status_set_default(bcmolt_nni_link_status *obj);


bcmos_bool bcmolt_nni_link_status_pack(const bcmolt_nni_link_status *obj, bcmolt_buf *buf);


uint32_t bcmolt_nni_link_status_get_packed_length(const bcmolt_nni_link_status *obj);


bcmos_bool bcmolt_nni_link_status_unpack(bcmolt_nni_link_status *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_nni_link_status_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_nni_link_status_validate(const bcmolt_nni_link_status *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_onu_id_list_u32_set_default(bcmolt_onu_id_list_u32 *obj);


bcmos_bool bcmolt_onu_id_list_u32_pack(const bcmolt_onu_id_list_u32 *obj, bcmolt_buf *buf);


uint32_t bcmolt_onu_id_list_u32_get_packed_length(const bcmolt_onu_id_list_u32 *obj);


bcmos_bool bcmolt_onu_id_list_u32_unpack(bcmolt_onu_id_list_u32 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_onu_id_list_u32_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_onu_id_list_u32_validate(const bcmolt_onu_id_list_u32 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pcie_conn_data_set_default(bcmolt_pcie_conn_data *obj);


bcmos_bool bcmolt_pcie_conn_data_pack(const bcmolt_pcie_conn_data *obj, bcmolt_buf *buf);


uint32_t bcmolt_pcie_conn_data_get_packed_length(const bcmolt_pcie_conn_data *obj);


bcmos_bool bcmolt_pcie_conn_data_unpack(bcmolt_pcie_conn_data *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pcie_conn_data_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pcie_conn_data_validate(const bcmolt_pcie_conn_data *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_alloc_sla_set_default(bcmolt_pon_alloc_sla *obj);


bcmos_bool bcmolt_pon_alloc_sla_pack(const bcmolt_pon_alloc_sla *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_alloc_sla_get_packed_length(const bcmolt_pon_alloc_sla *obj);


bcmos_bool bcmolt_pon_alloc_sla_unpack(bcmolt_pon_alloc_sla *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_alloc_sla_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_alloc_sla_validate(const bcmolt_pon_alloc_sla *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_pon_distance_set_default(bcmolt_pon_distance *obj);


bcmos_bool bcmolt_pon_distance_pack(const bcmolt_pon_distance *obj, bcmolt_buf *buf);


uint32_t bcmolt_pon_distance_get_packed_length(const bcmolt_pon_distance *obj);


bcmos_bool bcmolt_pon_distance_unpack(bcmolt_pon_distance *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_pon_distance_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_pon_distance_validate(const bcmolt_pon_distance *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_service_discovery_set_default(bcmolt_service_discovery *obj);


bcmos_bool bcmolt_service_discovery_pack(const bcmolt_service_discovery *obj, bcmolt_buf *buf);


uint32_t bcmolt_service_discovery_get_packed_length(const bcmolt_service_discovery *obj);


bcmos_bool bcmolt_service_discovery_unpack(bcmolt_service_discovery *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_service_discovery_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_service_discovery_validate(const bcmolt_service_discovery *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_stat_alarm_trigger_config_set_default(bcmolt_stat_alarm_trigger_config *obj);


bcmos_bool bcmolt_stat_alarm_trigger_config_pack(const bcmolt_stat_alarm_trigger_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_stat_alarm_trigger_config_get_packed_length(const bcmolt_stat_alarm_trigger_config *obj);


bcmos_bool bcmolt_stat_alarm_trigger_config_unpack(bcmolt_stat_alarm_trigger_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_stat_alarm_trigger_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_stat_alarm_trigger_config_validate(const bcmolt_stat_alarm_trigger_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_stat_alarm_soak_config_set_default(bcmolt_stat_alarm_soak_config *obj);


bcmos_bool bcmolt_stat_alarm_soak_config_pack(const bcmolt_stat_alarm_soak_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_stat_alarm_soak_config_get_packed_length(const bcmolt_stat_alarm_soak_config *obj);


bcmos_bool bcmolt_stat_alarm_soak_config_unpack(bcmolt_stat_alarm_soak_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_stat_alarm_soak_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_stat_alarm_soak_config_validate(const bcmolt_stat_alarm_soak_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_stat_alarm_config_set_default(bcmolt_stat_alarm_config *obj);


bcmos_bool bcmolt_stat_alarm_config_pack(const bcmolt_stat_alarm_config *obj, bcmolt_buf *buf);


uint32_t bcmolt_stat_alarm_config_get_packed_length(const bcmolt_stat_alarm_config *obj);


bcmos_bool bcmolt_stat_alarm_config_unpack(bcmolt_stat_alarm_config *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_stat_alarm_config_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_stat_alarm_config_validate(const bcmolt_stat_alarm_config *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_100_set_default(bcmolt_str_100 *obj);


bcmos_bool bcmolt_str_100_pack(const bcmolt_str_100 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_100_unpack(bcmolt_str_100 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_100_validate(const bcmolt_str_100 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_16_set_default(bcmolt_str_16 *obj);


bcmos_bool bcmolt_str_16_pack(const bcmolt_str_16 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_16_unpack(bcmolt_str_16 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_16_validate(const bcmolt_str_16 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_2000_set_default(bcmolt_str_2000 *obj);


bcmos_bool bcmolt_str_2000_pack(const bcmolt_str_2000 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_2000_unpack(bcmolt_str_2000 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_2000_validate(const bcmolt_str_2000 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_str_2048_set_default(bcmolt_str_2048 *obj);


bcmos_bool bcmolt_str_2048_pack(const bcmolt_str_2048 *obj, bcmolt_buf *buf);


bcmos_bool bcmolt_str_2048_unpack(bcmolt_str_2048 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_str_2048_validate(const bcmolt_str_2048 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_sw_error_set_default(bcmolt_sw_error *obj);


bcmos_bool bcmolt_sw_error_pack(const bcmolt_sw_error *obj, bcmolt_buf *buf);


uint32_t bcmolt_sw_error_get_packed_length(const bcmolt_sw_error *obj);


bcmos_bool bcmolt_sw_error_unpack(bcmolt_sw_error *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_sw_error_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_sw_error_validate(const bcmolt_sw_error *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_system_profile_set_default(bcmolt_system_profile *obj);


bcmos_bool bcmolt_system_profile_pack(const bcmolt_system_profile *obj, bcmolt_buf *buf);


uint32_t bcmolt_system_profile_get_packed_length(const bcmolt_system_profile *obj);


bcmos_bool bcmolt_system_profile_unpack(bcmolt_system_profile *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_system_profile_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_system_profile_validate(const bcmolt_system_profile *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_tm_sched_param_set_default(bcmolt_tm_sched_param *obj);


bcmos_bool bcmolt_tm_sched_param_pack(const bcmolt_tm_sched_param *obj, bcmolt_buf *buf);


uint32_t bcmolt_tm_sched_param_get_packed_length(const bcmolt_tm_sched_param *obj);


bcmos_bool bcmolt_tm_sched_param_unpack(bcmolt_tm_sched_param *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_tm_sched_param_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_tm_sched_param_validate(const bcmolt_tm_sched_param *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_tm_sched_attachment_point_set_default(bcmolt_tm_sched_attachment_point *obj);


bcmos_bool bcmolt_tm_sched_attachment_point_pack(const bcmolt_tm_sched_attachment_point *obj, bcmolt_buf *buf);


uint32_t bcmolt_tm_sched_attachment_point_get_packed_length(const bcmolt_tm_sched_attachment_point *obj);


bcmos_bool bcmolt_tm_sched_attachment_point_unpack(bcmolt_tm_sched_attachment_point *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_tm_sched_attachment_point_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_tm_sched_attachment_point_validate(const bcmolt_tm_sched_attachment_point *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_tm_shaping_set_default(bcmolt_tm_shaping *obj);


bcmos_bool bcmolt_tm_shaping_pack(const bcmolt_tm_shaping *obj, bcmolt_buf *buf);


uint32_t bcmolt_tm_shaping_get_packed_length(const bcmolt_tm_shaping *obj);


bcmos_bool bcmolt_tm_shaping_unpack(bcmolt_tm_shaping *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_tm_shaping_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_tm_shaping_validate(const bcmolt_tm_shaping *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_topology_map_set_default(bcmolt_topology_map *obj);


bcmos_bool bcmolt_topology_map_pack(const bcmolt_topology_map *obj, bcmolt_buf *buf);


uint32_t bcmolt_topology_map_get_packed_length(const bcmolt_topology_map *obj);


bcmos_bool bcmolt_topology_map_unpack(bcmolt_topology_map *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_topology_map_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_topology_map_validate(const bcmolt_topology_map *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_topology_map_list_u32_set_default(bcmolt_topology_map_list_u32 *obj);


bcmos_bool bcmolt_topology_map_list_u32_pack(const bcmolt_topology_map_list_u32 *obj, bcmolt_buf *buf);


uint32_t bcmolt_topology_map_list_u32_get_packed_length(const bcmolt_topology_map_list_u32 *obj);


bcmos_bool bcmolt_topology_map_list_u32_unpack(bcmolt_topology_map_list_u32 *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_topology_map_list_u32_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_topology_map_list_u32_validate(const bcmolt_topology_map_list_u32 *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_topology_set_default(bcmolt_topology *obj);


bcmos_bool bcmolt_topology_pack(const bcmolt_topology *obj, bcmolt_buf *buf);


uint32_t bcmolt_topology_get_packed_length(const bcmolt_topology *obj);


bcmos_bool bcmolt_topology_unpack(bcmolt_topology *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_topology_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_topology_validate(const bcmolt_topology *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_onu_alarms_set_default(bcmolt_xgpon_onu_alarms *obj);


bcmos_bool bcmolt_xgpon_onu_alarms_pack(const bcmolt_xgpon_onu_alarms *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_onu_alarms_get_packed_length(const bcmolt_xgpon_onu_alarms *obj);


bcmos_bool bcmolt_xgpon_onu_alarms_unpack(bcmolt_xgpon_onu_alarms *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarms_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_onu_alarms_validate(const bcmolt_xgpon_onu_alarms *obj, bcmos_errno *err, bcmolt_string *err_details);



void bcmolt_xgpon_trx_set_default(bcmolt_xgpon_trx *obj);


bcmos_bool bcmolt_xgpon_trx_pack(const bcmolt_xgpon_trx *obj, bcmolt_buf *buf);


uint32_t bcmolt_xgpon_trx_get_packed_length(const bcmolt_xgpon_trx *obj);


bcmos_bool bcmolt_xgpon_trx_unpack(bcmolt_xgpon_trx *obj, bcmolt_buf *buf, void **extra_mem);


bcmos_bool bcmolt_xgpon_trx_scan(bcmolt_buf *buf, uint32_t *extra_mem);


bcmos_bool bcmolt_xgpon_trx_validate(const bcmolt_xgpon_trx *obj, bcmos_errno *err, bcmolt_string *err_details);




#endif
