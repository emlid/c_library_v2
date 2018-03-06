#pragma once
// MESSAGE WIFI_STATUS PACKING

#define MAVLINK_MSG_ID_WIFI_STATUS 401

MAVPACKED(
typedef struct __mavlink_wifi_status_t {
 uint8_t state; /*< Current status of connection (0: Access Point 1: Client Mode)*/
 char ssid[32]; /*< SSID if device connected to network (Client Mode), otherwise undefined*/
}) mavlink_wifi_status_t;

#define MAVLINK_MSG_ID_WIFI_STATUS_LEN 33
#define MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN 33
#define MAVLINK_MSG_ID_401_LEN 33
#define MAVLINK_MSG_ID_401_MIN_LEN 33

#define MAVLINK_MSG_ID_WIFI_STATUS_CRC 237
#define MAVLINK_MSG_ID_401_CRC 237

#define MAVLINK_MSG_WIFI_STATUS_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_STATUS { \
    401, \
    "WIFI_STATUS", \
    2, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wifi_status_t, state) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_wifi_status_t, ssid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_STATUS { \
    "WIFI_STATUS", \
    2, \
    {  { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_wifi_status_t, state) }, \
         { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 1, offsetof(mavlink_wifi_status_t, ssid) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param state Current status of connection (0: Access Point 1: Client Mode)
 * @param ssid SSID if device connected to network (Client Mode), otherwise undefined
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t state, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, state);
    _mav_put_char_array(buf, 1, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_STATUS_LEN);
#else
    mavlink_wifi_status_t packet;
    packet.state = state;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
}

/**
 * @brief Pack a wifi_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state Current status of connection (0: Access Point 1: Client Mode)
 * @param ssid SSID if device connected to network (Client Mode), otherwise undefined
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t state,const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, state);
    _mav_put_char_array(buf, 1, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_STATUS_LEN);
#else
    mavlink_wifi_status_t packet;
    packet.state = state;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
}

/**
 * @brief Encode a wifi_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_status_t* wifi_status)
{
    return mavlink_msg_wifi_status_pack(system_id, component_id, msg, wifi_status->state, wifi_status->ssid);
}

/**
 * @brief Encode a wifi_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_status_t* wifi_status)
{
    return mavlink_msg_wifi_status_pack_chan(system_id, component_id, chan, msg, wifi_status->state, wifi_status->ssid);
}

/**
 * @brief Send a wifi_status message
 * @param chan MAVLink channel to send the message
 *
 * @param state Current status of connection (0: Access Point 1: Client Mode)
 * @param ssid SSID if device connected to network (Client Mode), otherwise undefined
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_status_send(mavlink_channel_t chan, uint8_t state, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_STATUS_LEN];
    _mav_put_uint8_t(buf, 0, state);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_STATUS, buf, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
#else
    mavlink_wifi_status_t packet;
    packet.state = state;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_STATUS, (const char *)&packet, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
#endif
}

/**
 * @brief Send a wifi_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_status_send_struct(mavlink_channel_t chan, const mavlink_wifi_status_t* wifi_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_status_send(chan, wifi_status->state, wifi_status->ssid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_STATUS, (const char *)wifi_status, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t state, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, state);
    _mav_put_char_array(buf, 1, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_STATUS, buf, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
#else
    mavlink_wifi_status_t *packet = (mavlink_wifi_status_t *)msgbuf;
    packet->state = state;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_STATUS, (const char *)packet, MAVLINK_MSG_ID_WIFI_STATUS_MIN_LEN, MAVLINK_MSG_ID_WIFI_STATUS_LEN, MAVLINK_MSG_ID_WIFI_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_STATUS UNPACKING


/**
 * @brief Get field state from wifi_status message
 *
 * @return Current status of connection (0: Access Point 1: Client Mode)
 */
static inline uint8_t mavlink_msg_wifi_status_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field ssid from wifi_status message
 *
 * @return SSID if device connected to network (Client Mode), otherwise undefined
 */
static inline uint16_t mavlink_msg_wifi_status_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  1);
}

/**
 * @brief Decode a wifi_status message into a struct
 *
 * @param msg The message to decode
 * @param wifi_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_status_decode(const mavlink_message_t* msg, mavlink_wifi_status_t* wifi_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    wifi_status->state = mavlink_msg_wifi_status_get_state(msg);
    mavlink_msg_wifi_status_get_ssid(msg, wifi_status->ssid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_STATUS_LEN? msg->len : MAVLINK_MSG_ID_WIFI_STATUS_LEN;
        memset(wifi_status, 0, MAVLINK_MSG_ID_WIFI_STATUS_LEN);
    memcpy(wifi_status, _MAV_PAYLOAD(msg), len);
#endif
}
