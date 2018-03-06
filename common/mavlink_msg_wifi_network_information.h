#pragma once
// MESSAGE WIFI_NETWORK_INFORMATION PACKING

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION 400

MAVPACKED(
typedef struct __mavlink_wifi_network_information_t {
 char ssid[32]; /*< Name of Wi-Fi network*/
 uint8_t security_type; /*< See the WIFI_SECURITY_TYPE enum.*/
 uint8_t type; /*< Type of network (0: saved 1: scanned)*/
}) mavlink_wifi_network_information_t;

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN 34
#define MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN 34
#define MAVLINK_MSG_ID_400_LEN 34
#define MAVLINK_MSG_ID_400_MIN_LEN 34

#define MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC 45
#define MAVLINK_MSG_ID_400_CRC 45

#define MAVLINK_MSG_WIFI_NETWORK_INFORMATION_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_INFORMATION { \
    400, \
    "WIFI_NETWORK_INFORMATION", \
    3, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_information_t, ssid) }, \
         { "security_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wifi_network_information_t, security_type) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wifi_network_information_t, type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_INFORMATION { \
    "WIFI_NETWORK_INFORMATION", \
    3, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_information_t, ssid) }, \
         { "security_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wifi_network_information_t, security_type) }, \
         { "type", NULL, MAVLINK_TYPE_UINT8_T, 0, 33, offsetof(mavlink_wifi_network_information_t, type) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_network_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param type Type of network (0: saved 1: scanned)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid, uint8_t security_type, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_uint8_t(buf, 33, type);
    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN);
#else
    mavlink_wifi_network_information_t packet;
    packet.security_type = security_type;
    packet.type = type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
}

/**
 * @brief Pack a wifi_network_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param type Type of network (0: saved 1: scanned)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid,uint8_t security_type,uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_uint8_t(buf, 33, type);
    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN);
#else
    mavlink_wifi_network_information_t packet;
    packet.security_type = security_type;
    packet.type = type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
}

/**
 * @brief Encode a wifi_network_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_network_information_t* wifi_network_information)
{
    return mavlink_msg_wifi_network_information_pack(system_id, component_id, msg, wifi_network_information->ssid, wifi_network_information->security_type, wifi_network_information->type);
}

/**
 * @brief Encode a wifi_network_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_network_information_t* wifi_network_information)
{
    return mavlink_msg_wifi_network_information_pack_chan(system_id, component_id, chan, msg, wifi_network_information->ssid, wifi_network_information->security_type, wifi_network_information->type);
}

/**
 * @brief Send a wifi_network_information message
 * @param chan MAVLink channel to send the message
 *
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param type Type of network (0: saved 1: scanned)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_network_information_send(mavlink_channel_t chan, const char *ssid, uint8_t security_type, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_uint8_t(buf, 33, type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION, buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
#else
    mavlink_wifi_network_information_t packet;
    packet.security_type = security_type;
    packet.type = type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a wifi_network_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_network_information_send_struct(mavlink_channel_t chan, const mavlink_wifi_network_information_t* wifi_network_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_information_send(chan, wifi_network_information->ssid, wifi_network_information->security_type, wifi_network_information->type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION, (const char *)wifi_network_information, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_network_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ssid, uint8_t security_type, uint8_t type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_uint8_t(buf, 33, type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION, buf, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
#else
    mavlink_wifi_network_information_t *packet = (mavlink_wifi_network_information_t *)msgbuf;
    packet->security_type = security_type;
    packet->type = type;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_NETWORK_INFORMATION UNPACKING


/**
 * @brief Get field ssid from wifi_network_information message
 *
 * @return Name of Wi-Fi network
 */
static inline uint16_t mavlink_msg_wifi_network_information_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  0);
}

/**
 * @brief Get field security_type from wifi_network_information message
 *
 * @return See the WIFI_SECURITY_TYPE enum.
 */
static inline uint8_t mavlink_msg_wifi_network_information_get_security_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field type from wifi_network_information message
 *
 * @return Type of network (0: saved 1: scanned)
 */
static inline uint8_t mavlink_msg_wifi_network_information_get_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Decode a wifi_network_information message into a struct
 *
 * @param msg The message to decode
 * @param wifi_network_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_network_information_decode(const mavlink_message_t* msg, mavlink_wifi_network_information_t* wifi_network_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_information_get_ssid(msg, wifi_network_information->ssid);
    wifi_network_information->security_type = mavlink_msg_wifi_network_information_get_security_type(msg);
    wifi_network_information->type = mavlink_msg_wifi_network_information_get_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN;
        memset(wifi_network_information, 0, MAVLINK_MSG_ID_WIFI_NETWORK_INFORMATION_LEN);
    memcpy(wifi_network_information, _MAV_PAYLOAD(msg), len);
#endif
}
