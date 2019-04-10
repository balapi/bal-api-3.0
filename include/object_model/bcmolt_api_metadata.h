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

#ifndef BCMOLT_API_METADATA_H_
#define BCMOLT_API_METADATA_H_

#include <bcmos_system.h>
#include <bcmolt_type_metadata.h>
#include <bcmolt_api_model.h>

/* All APIs return
 * BCM_ERR_OK - ok
 * BCM_ERR_NOENT - if id is in range, but doesn't correspond to any value (a hole)
 * BCM_ERR_RANGE - id is out of range
 */

/* Get object descriptor */
bcmos_errno bcmolt_obj_descr_get(bcmolt_obj_id obj_id, const bcmolt_obj_descr **descr);

/* Get tag descriptor */
bcmos_errno bcmolt_tag_descr_get(uint8_t tag_id, const bcmolt_tag_descr **descr);

/* Get object subgroup descriptor (e.g. cfg or a single operation), using subgroup index */
bcmos_errno bcmolt_group_descr_get(
    bcmolt_obj_id obj_id,
    bcmolt_mgt_group mgt_group,
    uint16_t subgroup_idx,
    const bcmolt_group_descr **descr);

/* Get object subgroup descriptor using persistent group ID */
bcmos_errno bcmolt_group_descr_get_by_group_id(
    bcmolt_obj_id obj_id,
    uint8_t group_id,
    const bcmolt_group_descr **descr);

/* Get object subgroup descriptor using global group ID */
bcmos_errno bcmolt_group_descr_get_by_global_id(bcmolt_api_group_id global_id, const bcmolt_group_descr **descr);

/* Get subgroup count for object group */
uint16_t bcmolt_group_count_get(
    bcmolt_obj_id obj_id,
    bcmolt_mgt_group mgt_group);

/* Message group name */
const char *bcmolt_mgt_group_to_str(bcmolt_mgt_group group);

/* Convert an enum value to the corresponding string */
#define BCMOLT_ENUM_STRING_VAL(enum_name, value) \
    bcmolt_enum_stringval(enum_name ## _string_table, (value))

/* Get tags by system mode */
bcmolt_tag bcmolt_system_mode_tags(bcmolt_system_mode system_mode);

/* Detect whether or not a given object is supported in a given system mode. */
bcmos_bool bcmolt_object_is_supported(bcmolt_system_mode system_mode, bcmolt_obj_id obj);

/** Gets the device ID and interface ID for a given message based on the object key.
 *
 * \param msg[in] The message to check.
 * \param has_device_id[out] TRUE if *device_id is set
 * \param device_id[out] The device ID field of the object key (unchanged if device ID doesn't exist).
 * \param has_interface_id[out] TRUE if *interface_id is set
 * \param interface_id[out] The interface ID field of the object key (unchanged if interface ID doesn't exist).
 */
void bcmolt_devif_get(const bcmolt_msg *msg, bcmos_bool *has_device_id, bcmolt_ldid *device_id,
    bcmos_bool *has_interface_id, bcmolt_interface *interface_id);

/** Sets the device ID and interface ID for a given message by mutating the object key.
 *
 * \param msg[in/out] The message to change.
 * \param device_id[in] The device ID field of the object key (not used if device ID doesn't exist).
 * \param interface_id[in] The interface ID field of the object key (not used if interface ID doesn't exist).
 */
void bcmolt_devif_set(bcmolt_msg *msg, bcmolt_ldid device_id, bcmolt_interface interface_id);

/** Converts a global group ID into a specific object type, group and subgroup.
 *
 * \param group_id The global group ID.
 * \param obj The object type that corresponds to the group ID.
 * \param group The group type that corresponds to the group ID.
 * \param subgroup The subgroup index that corresponds to the group ID.
 * \return An error code or BCM_ERR_OK for success.
 */
bcmos_errno bcmolt_group_id_split(
    bcmolt_api_group_id group_id,
    bcmolt_obj_id *obj,
    bcmolt_mgt_group *group,
    uint16_t *subgroup);

/** Converts a specific object type, group and subgroup into a global group ID.
 *
 * \param obj The object type that corresponds to the group ID.
 * \param group The group type that corresponds to the group ID.
 * \param subgroup The subgroup index that corresponds to the group ID.
 * \param group_id The global group ID.
 * \return An error code or BCM_ERR_OK for success.
 */
bcmos_errno bcmolt_group_id_combine(
    bcmolt_obj_id obj,
    bcmolt_mgt_group group,
    uint16_t subgroup,
    bcmolt_api_group_id *group_id);

/* Common type descriptors for common/primitive types, exported for use with macros. */
extern const bcmolt_type_descr type_descr_uint8_t;
extern const bcmolt_type_descr type_descr_uint16_t;
extern const bcmolt_type_descr type_descr_uint32_t;
extern const bcmolt_type_descr type_descr_uint64_t;
extern const bcmolt_type_descr type_descr_uint8_t_hex;
extern const bcmolt_type_descr type_descr_uint16_t_hex;
extern const bcmolt_type_descr type_descr_uint32_t_hex;
extern const bcmolt_type_descr type_descr_uint64_t_hex;
extern const bcmolt_type_descr type_descr_int8_t;
extern const bcmolt_type_descr type_descr_int16_t;
extern const bcmolt_type_descr type_descr_int32_t;
extern const bcmolt_type_descr type_descr_int64_t;
extern const bcmolt_type_descr type_descr_float;
extern const bcmolt_type_descr type_descr_double;
extern const bcmolt_type_descr type_descr_bcmos_mac_address;
extern const bcmolt_type_descr type_descr_bcmos_ipv4_address;
extern const bcmolt_type_descr type_descr_bcmos_bool;


extern const bcmolt_enum_val bcmolt_action_cmd_id_string_table[];
extern const bcmolt_enum_val bcmolt_activation_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_activation_state_string_table[];
extern const bcmolt_enum_val bcmolt_additional_bw_eligibility_string_table[];
extern const bcmolt_enum_val bcmolt_alloc_operation_string_table[];
extern const bcmolt_enum_val bcmolt_alloc_type_string_table[];
extern const bcmolt_enum_val bcmolt_automatic_onu_deactivation_reason_string_table[];
extern const bcmolt_enum_val bcmolt_bal_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_bal_state_string_table[];
extern const bcmolt_enum_val bcmolt_calibration_record_string_table[];
extern const bcmolt_enum_val bcmolt_chip_family_string_table[];
extern const bcmolt_enum_val bcmolt_comm_mode_string_table[];
extern const bcmolt_enum_val bcmolt_control_state_string_table[];
extern const bcmolt_enum_val bcmolt_dba_mode_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_result_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_status_string_table[];
extern const bcmolt_enum_val bcmolt_deactivation_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_device_chip_revision_string_table[];
extern const bcmolt_enum_val bcmolt_device_image_type_string_table[];
extern const bcmolt_enum_val bcmolt_disable_serial_number_control_string_table[];
extern const bcmolt_enum_val bcmolt_egress_qos_type_string_table[];
extern const bcmolt_enum_val bcmolt_embedded_image_transfer_status_string_table[];
extern const bcmolt_enum_val bcmolt_epon_link_create_error_string_table[];
extern const bcmolt_enum_val bcmolt_epon_link_rate_string_table[];
extern const bcmolt_enum_val bcmolt_ext_irq_string_table[];
extern const bcmolt_enum_val bcmolt_flow_interface_type_string_table[];
extern const bcmolt_enum_val bcmolt_flow_state_string_table[];
extern const bcmolt_enum_val bcmolt_flow_type_string_table[];
extern const bcmolt_enum_val bcmolt_frequency_adjustment_direction_string_table[];
extern const bcmolt_enum_val bcmolt_gem_port_direction_string_table[];
extern const bcmolt_enum_val bcmolt_gem_port_operation_string_table[];
extern const bcmolt_enum_val bcmolt_gem_port_type_string_table[];
extern const bcmolt_enum_val bcmolt_gpio_pin_string_table[];
extern const bcmolt_enum_val bcmolt_gpio_pin_dir_string_table[];
extern const bcmolt_enum_val bcmolt_gpio_value_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_key_exchange_mode_string_table[];
extern const bcmolt_enum_val bcmolt_group_member_update_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_group_state_string_table[];
extern const bcmolt_enum_val bcmolt_group_type_string_table[];
extern const bcmolt_enum_val bcmolt_host_connection_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_image_transfer_status_string_table[];
extern const bcmolt_enum_val bcmolt_inni_mode_string_table[];
extern const bcmolt_enum_val bcmolt_inni_mux_string_table[];
extern const bcmolt_enum_val bcmolt_interface_operation_string_table[];
extern const bcmolt_enum_val bcmolt_interface_state_string_table[];
extern const bcmolt_enum_val bcmolt_interface_type_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_redundancy_string_table[];
extern const bcmolt_enum_val bcmolt_link_type_string_table[];
extern const bcmolt_enum_val bcmolt_log_file_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_level_string_table[];
extern const bcmolt_enum_val bcmolt_log_style_string_table[];
extern const bcmolt_enum_val bcmolt_log_type_string_table[];
extern const bcmolt_enum_val bcmolt_members_update_command_string_table[];
extern const bcmolt_enum_val bcmolt_mpcp_discovery_info_string_table[];
extern const bcmolt_enum_val bcmolt_nni_connection_string_table[];
extern const bcmolt_enum_val bcmolt_nni_loopback_type_string_table[];
extern const bcmolt_enum_val bcmolt_odn_class_string_table[];
extern const bcmolt_enum_val bcmolt_olt_disconnect_reason_string_table[];
extern const bcmolt_enum_val bcmolt_omci_device_id_string_table[];
extern const bcmolt_enum_val bcmolt_omci_port_id_operation_string_table[];
extern const bcmolt_enum_val bcmolt_onu_operation_string_table[];
extern const bcmolt_enum_val bcmolt_onu_post_discovery_mode_string_table[];
extern const bcmolt_enum_val bcmolt_onu_rate_string_table[];
extern const bcmolt_enum_val bcmolt_onu_state_string_table[];
extern const bcmolt_enum_val bcmolt_onu_upgrade_status_code_string_table[];
extern const bcmolt_enum_val bcmolt_packet_injection_error_string_table[];
extern const bcmolt_enum_val bcmolt_packet_type_string_table[];
extern const bcmolt_enum_val bcmolt_password_authentication_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_pkt_tag_type_string_table[];
extern const bcmolt_enum_val bcmolt_pon_ni_onu_upgrade_status_code_string_table[];
extern const bcmolt_enum_val bcmolt_pon_protection_switching_options_string_table[];
extern const bcmolt_enum_val bcmolt_power_levelling_control_string_table[];
extern const bcmolt_enum_val bcmolt_power_management_transition_reason_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_checker_mode_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_lock_state_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_polynomial_string_table[];
extern const bcmolt_enum_val bcmolt_ranging_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_request_registration_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_reset_mode_string_table[];
extern const bcmolt_enum_val bcmolt_result_string_table[];
extern const bcmolt_enum_val bcmolt_rssi_measurement_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_secure_mutual_authentication_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_shaper_mode_string_table[];
extern const bcmolt_enum_val bcmolt_sign_string_table[];
extern const bcmolt_enum_val bcmolt_stat_condition_type_string_table[];
extern const bcmolt_enum_val bcmolt_status_string_table[];
extern const bcmolt_enum_val bcmolt_switch_over_type_c_onu_state_string_table[];
extern const bcmolt_enum_val bcmolt_system_mode_string_table[];
extern const bcmolt_enum_val bcmolt_tc_protocol_string_table[];
extern const bcmolt_enum_val bcmolt_tm_queue_state_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_dir_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_output_type_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_param_type_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_type_string_table[];
extern const bcmolt_enum_val bcmolt_traffic_resume_result_string_table[];
extern const bcmolt_enum_val bcmolt_trivalent_string_table[];
extern const bcmolt_enum_val bcmolt_trx_type_string_table[];
extern const bcmolt_enum_val bcmolt_tune_in_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_tune_out_fail_reason_string_table[];
extern const bcmolt_enum_val bcmolt_uart_baudrate_string_table[];
extern const bcmolt_enum_val bcmolt_upstream_line_rate_capabilities_string_table[];
extern const bcmolt_enum_val bcmolt_us_gem_port_destination_string_table[];
extern const bcmolt_enum_val bcmolt_us_operating_wavelength_bands_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_trx_type_string_table[];
extern const bcmolt_enum_val bcmolt_obj_id_string_table[];
extern const bcmolt_enum_val bcmolt_api_group_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_device_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_flow_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_flow_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_group_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_group_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_log_file_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_olt_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_olt_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_onu_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_onu_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_auto_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_oper_subgroup_string_table[];
extern const bcmolt_enum_val bcmolt_action_id_string_table[];
extern const bcmolt_enum_val bcmolt_aes_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_automatic_onu_deactivation_id_string_table[];
extern const bcmolt_enum_val bcmolt_ber_monitor_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_cbr_rt_allocation_profile_id_string_table[];
extern const bcmolt_enum_val bcmolt_channel_profile_id_string_table[];
extern const bcmolt_enum_val bcmolt_classifier_id_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_completed_id_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_completed_default_id_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_completed_completed_id_string_table[];
extern const bcmolt_enum_val bcmolt_ddr_test_completed_connection_failed_id_string_table[];
extern const bcmolt_enum_val bcmolt_debug_device_cfg_id_string_table[];
extern const bcmolt_enum_val bcmolt_debug_flow_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_ds_frequency_offset_id_string_table[];
extern const bcmolt_enum_val bcmolt_egress_qos_id_string_table[];
extern const bcmolt_enum_val bcmolt_egress_qos_fixed_queue_id_string_table[];
extern const bcmolt_enum_val bcmolt_egress_qos_tc_to_queue_id_string_table[];
extern const bcmolt_enum_val bcmolt_egress_qos_pbit_to_tc_id_string_table[];
extern const bcmolt_enum_val bcmolt_embedded_image_entry_id_string_table[];
extern const bcmolt_enum_val bcmolt_epon_tunnel_id_range_id_string_table[];
extern const bcmolt_enum_val bcmolt_firmware_sw_version_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_intf_ref_id_string_table[];
extern const bcmolt_enum_val bcmolt_gem_port_configuration_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_onu_alarm_state_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_onu_alarms_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_onu_alarms_thresholds_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_onu_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_pon_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpon_trx_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_member_info_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_members_update_command_id_string_table[];
extern const bcmolt_enum_val bcmolt_host_sw_version_id_string_table[];
extern const bcmolt_enum_val bcmolt_hw_pon_id_id_string_table[];
extern const bcmolt_enum_val bcmolt_ieee_8021_as_tod_id_string_table[];
extern const bcmolt_enum_val bcmolt_inband_conn_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_indication_shaping_id_string_table[];
extern const bcmolt_enum_val bcmolt_inni_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_intf_ref_id_string_table[];
extern const bcmolt_enum_val bcmolt_itu_onu_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_itu_pon_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_itu_tod_id_string_table[];
extern const bcmolt_enum_val bcmolt_ituonu_upgrade_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_onu_aes_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_onu_eqd_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_protection_switching_id_string_table[];
extern const bcmolt_enum_val bcmolt_key_exchange_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_level_msg_count_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_level_per_file_id_string_table[];
extern const bcmolt_enum_val bcmolt_ngpon2_onu_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_ngpon2_pon_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_link_status_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_activation_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_power_management_configuration_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_tuning_configuration_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_upgrade_status_id_string_table[];
extern const bcmolt_enum_val bcmolt_operation_control_id_string_table[];
extern const bcmolt_enum_val bcmolt_pcie_conn_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_periodic_standby_pon_monitoring_id_string_table[];
extern const bcmolt_enum_val bcmolt_ploam_retransmission_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_alloc_sla_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_available_bandwidth_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_distance_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_drift_control_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_id_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_onu_upgrade_status_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_power_level_id_string_table[];
extern const bcmolt_enum_val bcmolt_power_consumption_channel_report_id_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_checker_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_generator_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_prbs_status_id_string_table[];
extern const bcmolt_enum_val bcmolt_request_registration_status_id_string_table[];
extern const bcmolt_enum_val bcmolt_serial_number_id_string_table[];
extern const bcmolt_enum_val bcmolt_service_discovery_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_soak_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_trigger_config_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_trigger_config_rate_threshold_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_trigger_config_rate_range_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_trigger_config_value_threshold_id_string_table[];
extern const bcmolt_enum_val bcmolt_stat_alarm_trigger_config_none_id_string_table[];
extern const bcmolt_enum_val bcmolt_sw_error_id_string_table[];
extern const bcmolt_enum_val bcmolt_system_profile_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_queue_ref_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_attachment_point_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_attachment_point_interface_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_attachment_point_tm_sched_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_param_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_param_priority_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_param_weight_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_ref_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_shaping_id_string_table[];
extern const bcmolt_enum_val bcmolt_topology_id_string_table[];
extern const bcmolt_enum_val bcmolt_topology_map_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_burst_profile_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_multicast_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_alarm_indication_control_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_alarm_state_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_alarms_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_alarms_thresholds_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_onu_registration_keys_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_pon_params_id_string_table[];
extern const bcmolt_enum_val bcmolt_xgpon_trx_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_connect_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_host_keep_alive_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_set_8021_as_tod_string_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_image_transfer_start_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_image_transfer_data_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_run_ddr_test_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_device_ready_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_device_keep_alive_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_connection_failure_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_connection_complete_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_sw_error_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_sw_exception_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_image_transfer_complete_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_ddr_test_complete_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_device_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_send_eth_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_receive_eth_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_flow_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpio_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_gpio_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_members_update_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_complete_members_update_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_group_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_status_changed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_internal_nni_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_configuration_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_get_stats_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_get_alloc_stats_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_set_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_alloc_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_configuration_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_set_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_itupon_gem_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_file_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_log_file_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_ngpon2_channel_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_ngpon2_channel_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_state_change_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_set_nni_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_nni_interface_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_disconnected_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_bal_failure_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_sw_error_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_reset_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_olt_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_set_onu_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_request_registration_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_change_power_levelling_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_adjust_tx_wavelength_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_secure_mutual_authentication_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_tuning_out_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_xgpon_alarm_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_gpon_alarm_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_dowi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_sfi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_sdi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_dfi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_pqsi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_sufi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_tiwi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_looci_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_loai_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_dgi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_pee_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_pst_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_ranging_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_activation_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_deactivation_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_enable_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_disable_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_rssi_measurement_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_invalid_dbru_report_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_key_exchange_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_key_exchange_key_mismatch_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_loki_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_memi_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_omci_port_id_configuration_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_ber_interval_configuration_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_err_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_password_authentication_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_key_exchange_unconsecutive_index_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_key_exchange_decrypt_required_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_activation_standby_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_power_management_state_change_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_possible_drift_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_registration_id_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_power_level_report_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_power_consumption_report_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_secure_mutual_authentication_failure_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_tuning_out_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_onu_tuning_in_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_tuning_response_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_ploam_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_cpu_packets_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_cpu_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_omci_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_rei_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_state_change_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_onu_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pbit_to_tc_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_pbit_to_tc_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_set_pon_interface_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_set_onu_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_disable_serial_number_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_run_special_bw_map_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_start_onu_upgrade_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_protection_switching_type_c_set_multiple_onu_state_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_protection_switching_apply_rerange_delta_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_cpu_packets_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_broadcast_ploam_packet_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_state_change_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_tod_request_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_los_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_protection_switching_traffic_resume_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_protection_switching_onus_ranged_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_protection_switching_switchover_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_standby_pon_monitoring_cycle_completed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_onu_discovered_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_cpu_packets_failure_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_onu_upgrade_complete_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_llid_quarantined_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_epon_link_created_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_epon_link_creation_failed_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_pon_interface_auto_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_software_error_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_software_error_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_tc_to_queue_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_tc_to_queue_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_queue_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_queue_cfg_data_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_key_id_string_table[];
extern const bcmolt_enum_val bcmolt_tm_sched_cfg_data_id_string_table[];


extern const bcmolt_type_descr type_descr_bcmolt_action;
extern const bcmolt_type_descr type_descr_bcmolt_action_cmd_id;
extern const bcmolt_type_descr type_descr_bcmolt_activation_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_activation_state;
extern const bcmolt_type_descr type_descr_bcmolt_additional_bw_eligibility;
extern const bcmolt_type_descr type_descr_bcmolt_aes_key;
#define type_descr_bcmolt_alloc_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_alloc_operation;
extern const bcmolt_type_descr type_descr_bcmolt_alloc_type;
extern const bcmolt_type_descr type_descr_bcmolt_arr_calibration_record_8;
extern const bcmolt_type_descr type_descr_bcmolt_arr_channel_profile_8;
extern const bcmolt_type_descr type_descr_bcmolt_arr_power_consumption_channel_report_8;
extern const bcmolt_type_descr type_descr_bcmolt_arr_tm_queue_ref_8;
extern const bcmolt_type_descr type_descr_bcmolt_arr_u16_2;
extern const bcmolt_type_descr type_descr_bcmolt_arr_xgpon_burst_profile_4;
extern const bcmolt_type_descr type_descr_bcmolt_automatic_onu_deactivation;
extern const bcmolt_type_descr type_descr_bcmolt_automatic_onu_deactivation_reason;
extern const bcmolt_type_descr type_descr_bcmolt_bal_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_bal_state;
#define type_descr_bcmolt_ber_interval type_descr_uint32_t
extern const bcmolt_type_descr type_descr_bcmolt_ber_monitor_params;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_10;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_13;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_16;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_36;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_4;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_40;
extern const bcmolt_type_descr type_descr_bcmolt_bin_str_8;
#define type_descr_bcmolt_burst_profile_index type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_calibration_record;
extern const bcmolt_type_descr type_descr_bcmolt_cbr_rt_allocation_profile;
extern const bcmolt_type_descr type_descr_bcmolt_channel_profile;
extern const bcmolt_type_descr type_descr_bcmolt_chip_family;
extern const bcmolt_type_descr type_descr_bcmolt_classifier;
extern const bcmolt_type_descr type_descr_bcmolt_comm_mode;
extern const bcmolt_type_descr type_descr_bcmolt_control_state;
#define type_descr_bcmolt_cookie type_descr_uint64_t
extern const bcmolt_type_descr type_descr_bcmolt_dba_mode;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_completed;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_result;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_status;
extern const bcmolt_type_descr type_descr_bcmolt_deactivation_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_debug_device_cfg;
extern const bcmolt_type_descr type_descr_bcmolt_debug_flow_config;
extern const bcmolt_type_descr type_descr_bcmolt_device_chip_revision;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_type;
extern const bcmolt_type_descr type_descr_bcmolt_disable_serial_number_control;
extern const bcmolt_type_descr type_descr_bcmolt_ds_frequency_offset;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos_type;
extern const bcmolt_type_descr type_descr_bcmolt_embedded_image_entry;
extern const bcmolt_type_descr type_descr_bcmolt_embedded_image_entry_list_u8_max_4;
extern const bcmolt_type_descr type_descr_bcmolt_embedded_image_transfer_status;
extern const bcmolt_type_descr type_descr_bcmolt_epon_link_create_error;
extern const bcmolt_type_descr type_descr_bcmolt_epon_link_rate;
#define type_descr_bcmolt_epon_llid type_descr_uint16_t
#define type_descr_bcmolt_epon_tunnel_id type_descr_uint32_t
extern const bcmolt_type_descr type_descr_bcmolt_epon_tunnel_id_range;
extern const bcmolt_type_descr type_descr_bcmolt_ext_irq;
extern const bcmolt_type_descr type_descr_bcmolt_firmware_sw_version;
#define type_descr_bcmolt_flow_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_flow_interface_type;
extern const bcmolt_type_descr type_descr_bcmolt_flow_intf_ref;
extern const bcmolt_type_descr type_descr_bcmolt_flow_state;
extern const bcmolt_type_descr type_descr_bcmolt_flow_type;
extern const bcmolt_type_descr type_descr_bcmolt_frequency_adjustment_direction;
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_configuration;
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_direction;
#define type_descr_bcmolt_gem_port_id type_descr_uint32_t
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_id_list_u8_max_16;
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_operation;
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_type;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_pin;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_pin_dir;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_value;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_key_exchange_mode;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarm_state;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarms;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarms_thresholds;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_params;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_pon_params;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_trx;
#define type_descr_bcmolt_group_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_group_member_info;
extern const bcmolt_type_descr type_descr_bcmolt_group_member_info_list_u8;
extern const bcmolt_type_descr type_descr_bcmolt_group_member_update_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_group_members_update_command;
extern const bcmolt_type_descr type_descr_bcmolt_group_state;
extern const bcmolt_type_descr type_descr_bcmolt_group_type;
extern const bcmolt_type_descr type_descr_bcmolt_host_connection_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_host_sw_version;
extern const bcmolt_type_descr type_descr_bcmolt_hw_pon_id;
extern const bcmolt_type_descr type_descr_bcmolt_ieee_8021_as_tod;
#define type_descr_bcmolt_ieee_link type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_image_transfer_status;
extern const bcmolt_type_descr type_descr_bcmolt_inband_conn_data;
extern const bcmolt_type_descr type_descr_bcmolt_indication_shaping;
extern const bcmolt_type_descr type_descr_bcmolt_inni_config;
extern const bcmolt_type_descr type_descr_bcmolt_inni_mode;
extern const bcmolt_type_descr type_descr_bcmolt_inni_mux;
#define type_descr_bcmolt_interface_id type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_interface_operation;
extern const bcmolt_type_descr type_descr_bcmolt_interface_state;
extern const bcmolt_type_descr type_descr_bcmolt_interface_type;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_redundancy;
extern const bcmolt_type_descr type_descr_bcmolt_intf_ref;
extern const bcmolt_type_descr type_descr_bcmolt_itu_onu_params;
extern const bcmolt_type_descr type_descr_bcmolt_itu_pon_params;
extern const bcmolt_type_descr type_descr_bcmolt_itu_tod;
extern const bcmolt_type_descr type_descr_bcmolt_ituonu_upgrade_params;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_onu_aes_key;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_onu_eqd;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_onu_eqd_list_u32;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_protection_switching;
extern const bcmolt_type_descr type_descr_bcmolt_key_exchange;
#define type_descr_bcmolt_ldid type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_link_type;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_level;
extern const bcmolt_type_descr type_descr_bcmolt_log_level_msg_count;
extern const bcmolt_type_descr type_descr_bcmolt_log_level_per_file;
extern const bcmolt_type_descr type_descr_bcmolt_log_style;
extern const bcmolt_type_descr type_descr_bcmolt_log_type;
extern const bcmolt_type_descr type_descr_bcmolt_members_update_command;
extern const bcmolt_type_descr type_descr_bcmolt_mpcp_discovery_info;
#define type_descr_bcmolt_mtu type_descr_uint32_t
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_onu_params;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_pon_params;
extern const bcmolt_type_descr type_descr_bcmolt_nni_connection;
#define type_descr_bcmolt_nni_id type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_nni_link_status;
extern const bcmolt_type_descr type_descr_bcmolt_nni_loopback_type;
#define type_descr_bcmolt_odid type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_odn_class;
extern const bcmolt_type_descr type_descr_bcmolt_olt_disconnect_reason;
extern const bcmolt_type_descr type_descr_bcmolt_omci_device_id;
extern const bcmolt_type_descr type_descr_bcmolt_omci_port_id_operation;
extern const bcmolt_type_descr type_descr_bcmolt_onu_activation;
#define type_descr_bcmolt_onu_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_onu_id_list_u32;
extern const bcmolt_type_descr type_descr_bcmolt_onu_operation;
extern const bcmolt_type_descr type_descr_bcmolt_onu_post_discovery_mode;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_management_configuration;
extern const bcmolt_type_descr type_descr_bcmolt_onu_rate;
extern const bcmolt_type_descr type_descr_bcmolt_onu_state;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_configuration;
extern const bcmolt_type_descr type_descr_bcmolt_onu_upgrade_status;
extern const bcmolt_type_descr type_descr_bcmolt_onu_upgrade_status_code;
extern const bcmolt_type_descr type_descr_bcmolt_onu_upgrade_status_list_u32_max_128;
extern const bcmolt_type_descr type_descr_bcmolt_operation_control;
extern const bcmolt_type_descr type_descr_bcmolt_packet_injection_error;
extern const bcmolt_type_descr type_descr_bcmolt_packet_type;
extern const bcmolt_type_descr type_descr_bcmolt_password_authentication_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_pcie_conn_data;
extern const bcmolt_type_descr type_descr_bcmolt_periodic_standby_pon_monitoring;
extern const bcmolt_type_descr type_descr_bcmolt_pkt_tag_type;
extern const bcmolt_type_descr type_descr_bcmolt_ploam_retransmission;
extern const bcmolt_type_descr type_descr_bcmolt_pon_alloc_sla;
extern const bcmolt_type_descr type_descr_bcmolt_pon_available_bandwidth;
extern const bcmolt_type_descr type_descr_bcmolt_pon_distance;
extern const bcmolt_type_descr type_descr_bcmolt_pon_drift_control;
extern const bcmolt_type_descr type_descr_bcmolt_pon_id;
#define type_descr_bcmolt_pon_ni type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_pon_ni_onu_upgrade_status_code;
extern const bcmolt_type_descr type_descr_bcmolt_pon_onu_upgrade_status;
extern const bcmolt_type_descr type_descr_bcmolt_pon_power_level;
extern const bcmolt_type_descr type_descr_bcmolt_pon_protection_switching_options;
extern const bcmolt_type_descr type_descr_bcmolt_power_consumption_channel_report;
extern const bcmolt_type_descr type_descr_bcmolt_power_levelling_control;
extern const bcmolt_type_descr type_descr_bcmolt_power_management_transition_reason;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_checker_config;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_checker_mode;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_generator_config;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_lock_state;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_polynomial;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_status;
extern const bcmolt_type_descr type_descr_bcmolt_ranging_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_request_registration_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_request_registration_status;
extern const bcmolt_type_descr type_descr_bcmolt_reset_mode;
extern const bcmolt_type_descr type_descr_bcmolt_result;
extern const bcmolt_type_descr type_descr_bcmolt_rssi_measurement_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_secure_mutual_authentication_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_serial_number;
extern const bcmolt_type_descr type_descr_bcmolt_service_discovery;
#define type_descr_bcmolt_service_port_id type_descr_uint32_t
extern const bcmolt_type_descr type_descr_bcmolt_shaper_mode;
extern const bcmolt_type_descr type_descr_bcmolt_sign;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_config;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_soak_config;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config;
extern const bcmolt_type_descr type_descr_bcmolt_stat_condition_type;
extern const bcmolt_type_descr type_descr_bcmolt_status;
extern const bcmolt_type_descr type_descr_bcmolt_str_100;
extern const bcmolt_type_descr type_descr_bcmolt_str_16;
extern const bcmolt_type_descr type_descr_bcmolt_str_2000;
extern const bcmolt_type_descr type_descr_bcmolt_str_2048;
extern const bcmolt_type_descr type_descr_bcmolt_str_256;
extern const bcmolt_type_descr type_descr_bcmolt_str_32;
extern const bcmolt_type_descr type_descr_bcmolt_str_64;
extern const bcmolt_type_descr type_descr_bcmolt_sw_error;
extern const bcmolt_type_descr type_descr_bcmolt_switch_over_type_c_onu_state;
extern const bcmolt_type_descr type_descr_bcmolt_system_mode;
extern const bcmolt_type_descr type_descr_bcmolt_system_profile;
extern const bcmolt_type_descr type_descr_bcmolt_tc_protocol;
#define type_descr_bcmolt_time_quanta type_descr_uint32_t
#define type_descr_bcmolt_tm_priority type_descr_uint8_t
#define type_descr_bcmolt_tm_queue_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_ref;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_state;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_attachment_point;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_dir;
#define type_descr_bcmolt_tm_sched_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_output_type;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_param;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_param_type;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_ref;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_type;
extern const bcmolt_type_descr type_descr_bcmolt_tm_shaping;
#define type_descr_bcmolt_tm_weight type_descr_uint8_t
extern const bcmolt_type_descr type_descr_bcmolt_topology;
extern const bcmolt_type_descr type_descr_bcmolt_topology_map;
extern const bcmolt_type_descr type_descr_bcmolt_topology_map_list_u32;
extern const bcmolt_type_descr type_descr_bcmolt_traffic_resume_result;
extern const bcmolt_type_descr type_descr_bcmolt_trivalent;
extern const bcmolt_type_descr type_descr_bcmolt_trx_type;
extern const bcmolt_type_descr type_descr_bcmolt_tune_in_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_tune_out_fail_reason;
extern const bcmolt_type_descr type_descr_bcmolt_uart_baudrate;
extern const bcmolt_type_descr type_descr_bcmolt_upstream_line_rate_capabilities;
extern const bcmolt_type_descr type_descr_bcmolt_us_gem_port_destination;
extern const bcmolt_type_descr type_descr_bcmolt_us_operating_wavelength_bands;
#define type_descr_bcmolt_vlan_id type_descr_uint16_t
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_burst_profile;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_multicast_key;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarm_indication_control;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarm_state;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarms;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarms_thresholds;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_params;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_registration_keys;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_pon_params;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_trx;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_trx_type;
extern const bcmolt_type_descr type_descr_bcmolt_device_key;
extern const bcmolt_type_descr type_descr_bcmolt_device_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_connect_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_host_keep_alive_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_set_8021_as_tod_string_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_start_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_data_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_run_ddr_test_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_device_ready_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_device_keep_alive_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_connection_failure_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_connection_complete_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_sw_error_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_sw_exception_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_complete_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_ddr_test_complete_data;
extern const bcmolt_type_descr type_descr_bcmolt_device_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_flow_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_flow_key;
extern const bcmolt_type_descr type_descr_bcmolt_flow_send_eth_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_flow_receive_eth_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_flow_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_key;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_group_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_group_key;
extern const bcmolt_type_descr type_descr_bcmolt_group_members_update_data;
extern const bcmolt_type_descr type_descr_bcmolt_group_complete_members_update_data;
extern const bcmolt_type_descr type_descr_bcmolt_group_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_key;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_status_changed_data;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_key;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_configuration_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_get_stats_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_get_alloc_stats_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_set_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_key;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_configuration_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_set_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_log_key;
extern const bcmolt_type_descr type_descr_bcmolt_log_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_key;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_channel_key;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_channel_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_key;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_state_change_data;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_set_nni_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_key;
extern const bcmolt_type_descr type_descr_bcmolt_olt_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_disconnected_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_bal_failure_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_sw_error_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_reset_data;
extern const bcmolt_type_descr type_descr_bcmolt_olt_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_set_onu_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_request_registration_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_change_power_levelling_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_adjust_tx_wavelength_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_secure_mutual_authentication_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_out_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_xgpon_alarm_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_gpon_alarm_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dowi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sfi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sdi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dfi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pqsi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sufi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tiwi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_looci_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_loai_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dgi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pee_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pst_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ranging_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_activation_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_deactivation_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_enable_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_disable_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_rssi_measurement_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_invalid_dbru_report_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_key_mismatch_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_loki_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_memi_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_omci_port_id_configuration_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ber_interval_configuration_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_err_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_password_authentication_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_unconsecutive_index_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_decrypt_required_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_activation_standby_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_management_state_change_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_possible_drift_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_registration_id_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_level_report_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_consumption_report_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_secure_mutual_authentication_failure_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_tuning_out_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_tuning_in_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_response_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ploam_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cpu_packets_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cpu_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_omci_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_rei_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_state_change_data;
extern const bcmolt_type_descr type_descr_bcmolt_onu_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_pbit_to_tc_key;
extern const bcmolt_type_descr type_descr_bcmolt_pbit_to_tc_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_key;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_set_pon_interface_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_set_onu_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_disable_serial_number_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_run_special_bw_map_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_start_onu_upgrade_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_type_c_set_multiple_onu_state_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_apply_rerange_delta_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cpu_packets_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_broadcast_ploam_packet_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_state_change_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_tod_request_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_los_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_traffic_resume_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_onus_ranged_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_switchover_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_standby_pon_monitoring_cycle_completed_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_onu_discovered_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cpu_packets_failure_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_onu_upgrade_complete_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_llid_quarantined_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_epon_link_created_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_epon_link_creation_failed_data;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_auto_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_software_error_key;
extern const bcmolt_type_descr type_descr_bcmolt_software_error_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_tc_to_queue_key;
extern const bcmolt_type_descr type_descr_bcmolt_tc_to_queue_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_key;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_key;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_cfg_data;
extern const bcmolt_type_descr type_descr_bcmolt_obj_id;
extern const bcmolt_type_descr type_descr_bcmolt_api_group_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_device_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_flow_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_flow_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_group_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_group_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_olt_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_olt_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_onu_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_onu_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_auto_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_oper_subgroup;
extern const bcmolt_type_descr type_descr_bcmolt_action_id;
extern const bcmolt_type_descr type_descr_bcmolt_aes_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_automatic_onu_deactivation_id;
extern const bcmolt_type_descr type_descr_bcmolt_ber_monitor_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_cbr_rt_allocation_profile_id;
extern const bcmolt_type_descr type_descr_bcmolt_channel_profile_id;
extern const bcmolt_type_descr type_descr_bcmolt_classifier_id;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_completed_id;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_completed_default_id;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_completed_completed_id;
extern const bcmolt_type_descr type_descr_bcmolt_ddr_test_completed_connection_failed_id;
extern const bcmolt_type_descr type_descr_bcmolt_debug_device_cfg_id;
extern const bcmolt_type_descr type_descr_bcmolt_debug_flow_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_ds_frequency_offset_id;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos_id;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos_fixed_queue_id;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos_tc_to_queue_id;
extern const bcmolt_type_descr type_descr_bcmolt_egress_qos_pbit_to_tc_id;
extern const bcmolt_type_descr type_descr_bcmolt_embedded_image_entry_id;
extern const bcmolt_type_descr type_descr_bcmolt_epon_tunnel_id_range_id;
extern const bcmolt_type_descr type_descr_bcmolt_firmware_sw_version_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_intf_ref_id;
extern const bcmolt_type_descr type_descr_bcmolt_gem_port_configuration_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarm_state_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarms_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_alarms_thresholds_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_onu_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_pon_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpon_trx_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_member_info_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_members_update_command_id;
extern const bcmolt_type_descr type_descr_bcmolt_host_sw_version_id;
extern const bcmolt_type_descr type_descr_bcmolt_hw_pon_id_id;
extern const bcmolt_type_descr type_descr_bcmolt_ieee_8021_as_tod_id;
extern const bcmolt_type_descr type_descr_bcmolt_inband_conn_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_indication_shaping_id;
extern const bcmolt_type_descr type_descr_bcmolt_inni_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_intf_ref_id;
extern const bcmolt_type_descr type_descr_bcmolt_itu_onu_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_itu_pon_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_itu_tod_id;
extern const bcmolt_type_descr type_descr_bcmolt_ituonu_upgrade_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_onu_aes_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_onu_eqd_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_protection_switching_id;
extern const bcmolt_type_descr type_descr_bcmolt_key_exchange_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_level_msg_count_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_level_per_file_id;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_onu_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_pon_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_link_status_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_activation_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_management_configuration_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_configuration_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_upgrade_status_id;
extern const bcmolt_type_descr type_descr_bcmolt_operation_control_id;
extern const bcmolt_type_descr type_descr_bcmolt_pcie_conn_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_periodic_standby_pon_monitoring_id;
extern const bcmolt_type_descr type_descr_bcmolt_ploam_retransmission_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_alloc_sla_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_available_bandwidth_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_distance_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_drift_control_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_id_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_onu_upgrade_status_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_power_level_id;
extern const bcmolt_type_descr type_descr_bcmolt_power_consumption_channel_report_id;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_checker_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_generator_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_prbs_status_id;
extern const bcmolt_type_descr type_descr_bcmolt_request_registration_status_id;
extern const bcmolt_type_descr type_descr_bcmolt_serial_number_id;
extern const bcmolt_type_descr type_descr_bcmolt_service_discovery_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_soak_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config_rate_threshold_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config_rate_range_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config_value_threshold_id;
extern const bcmolt_type_descr type_descr_bcmolt_stat_alarm_trigger_config_none_id;
extern const bcmolt_type_descr type_descr_bcmolt_sw_error_id;
extern const bcmolt_type_descr type_descr_bcmolt_system_profile_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_ref_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_attachment_point_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_attachment_point_interface_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_attachment_point_tm_sched_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_param_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_param_priority_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_param_weight_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_ref_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_shaping_id;
extern const bcmolt_type_descr type_descr_bcmolt_topology_id;
extern const bcmolt_type_descr type_descr_bcmolt_topology_map_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_burst_profile_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_multicast_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarm_indication_control_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarm_state_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarms_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_alarms_thresholds_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_onu_registration_keys_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_pon_params_id;
extern const bcmolt_type_descr type_descr_bcmolt_xgpon_trx_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_connect_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_host_keep_alive_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_set_8021_as_tod_string_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_start_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_data_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_run_ddr_test_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_device_ready_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_device_keep_alive_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_connection_failure_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_connection_complete_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_sw_error_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_sw_exception_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_image_transfer_complete_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_ddr_test_complete_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_device_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_send_eth_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_receive_eth_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_flow_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_gpio_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_members_update_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_complete_members_update_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_group_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_status_changed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_internal_nni_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_configuration_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_get_stats_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_get_alloc_stats_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_set_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_alloc_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_configuration_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_set_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_itupon_gem_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_log_file_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_channel_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_ngpon2_channel_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_state_change_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_set_nni_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_nni_interface_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_disconnected_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_bal_failure_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_sw_error_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_reset_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_olt_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_set_onu_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_request_registration_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_change_power_levelling_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_adjust_tx_wavelength_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_secure_mutual_authentication_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_out_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_xgpon_alarm_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_gpon_alarm_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dowi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sfi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sdi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dfi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pqsi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_sufi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tiwi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_looci_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_loai_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_dgi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pee_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_pst_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ranging_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_activation_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_deactivation_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_enable_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_disable_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_rssi_measurement_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_invalid_dbru_report_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_key_mismatch_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_loki_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_memi_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_omci_port_id_configuration_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ber_interval_configuration_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_err_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_password_authentication_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_unconsecutive_index_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_key_exchange_decrypt_required_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_activation_standby_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_management_state_change_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_possible_drift_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_registration_id_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_level_report_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_power_consumption_report_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_secure_mutual_authentication_failure_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_tuning_out_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_onu_tuning_in_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_tuning_response_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_ploam_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cpu_packets_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_cpu_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_omci_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_rei_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_state_change_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_onu_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pbit_to_tc_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_pbit_to_tc_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_set_pon_interface_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_set_onu_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_disable_serial_number_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_run_special_bw_map_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_start_onu_upgrade_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_type_c_set_multiple_onu_state_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_apply_rerange_delta_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cpu_packets_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_broadcast_ploam_packet_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_state_change_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_tod_request_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_los_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_traffic_resume_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_onus_ranged_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_protection_switching_switchover_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_standby_pon_monitoring_cycle_completed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_onu_discovered_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_cpu_packets_failure_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_onu_upgrade_complete_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_llid_quarantined_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_epon_link_created_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_epon_link_creation_failed_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_pon_interface_auto_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_software_error_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_software_error_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_tc_to_queue_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_tc_to_queue_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_queue_cfg_data_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_key_id;
extern const bcmolt_type_descr type_descr_bcmolt_tm_sched_cfg_data_id;

#endif
