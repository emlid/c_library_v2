#pragma once
// MESSAGE WIFI_NETWORK_ADD PACKING

#define MAVLINK_MSG_ID_WIFI_NETWORK_ADD 402

MAVPACKED(
typedef struct __mavlink_wifi_network_add_t {
 char ssid[32]; /*< Name of Wi-Fi network*/
 uint8_t security_type; /*< See the WIFI_SECURITY_TYPE enum.*/
 char password[64]; /*< Password*/
}) mavlink_wifi_network_add_t;

#define MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN 97
#define MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN 97
#define MAVLINK_MSG_ID_402_LEN 97
#define MAVLINK_MSG_ID_402_MIN_LEN 97

#define MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC 86
#define MAVLINK_MSG_ID_402_CRC 86

#define MAVLINK_MSG_WIFI_NETWORK_ADD_FIELD_SSID_LEN 32
#define MAVLINK_MSG_WIFI_NETWORK_ADD_FIELD_PASSWORD_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_ADD { \
    402, \
    "WIFI_NETWORK_ADD", \
    3, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_add_t, ssid) }, \
         { "security_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wifi_network_add_t, security_type) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_wifi_network_add_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_ADD { \
    "WIFI_NETWORK_ADD", \
    3, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_add_t, ssid) }, \
         { "security_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_wifi_network_add_t, security_type) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_wifi_network_add_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_network_add message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param password Password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_add_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid, uint8_t security_type, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN);
#else
    mavlink_wifi_network_add_t packet;
    packet.security_type = security_type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_ADD;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
}

/**
 * @brief Pack a wifi_network_add message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param password Password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_add_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid,uint8_t security_type,const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN);
#else
    mavlink_wifi_network_add_t packet;
    packet.security_type = security_type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_ADD;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
}

/**
 * @brief Encode a wifi_network_add struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_add C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_add_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_network_add_t* wifi_network_add)
{
    return mavlink_msg_wifi_network_add_pack(system_id, component_id, msg, wifi_network_add->ssid, wifi_network_add->security_type, wifi_network_add->password);
}

/**
 * @brief Encode a wifi_network_add struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_add C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_add_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_network_add_t* wifi_network_add)
{
    return mavlink_msg_wifi_network_add_pack_chan(system_id, component_id, chan, msg, wifi_network_add->ssid, wifi_network_add->security_type, wifi_network_add->password);
}

/**
 * @brief Send a wifi_network_add message
 * @param chan MAVLink channel to send the message
 *
 * @param ssid Name of Wi-Fi network
 * @param security_type See the WIFI_SECURITY_TYPE enum.
 * @param password Password
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_network_add_send(mavlink_channel_t chan, const char *ssid, uint8_t security_type, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN];
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD, buf, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
#else
    mavlink_wifi_network_add_t packet;
    packet.security_type = security_type;
    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD, (const char *)&packet, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
#endif
}

/**
 * @brief Send a wifi_network_add message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_network_add_send_struct(mavlink_channel_t chan, const mavlink_wifi_network_add_t* wifi_network_add)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_add_send(chan, wifi_network_add->ssid, wifi_network_add->security_type, wifi_network_add->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD, (const char *)wifi_network_add, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_network_add_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ssid, uint8_t security_type, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, security_type);
    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD, buf, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
#else
    mavlink_wifi_network_add_t *packet = (mavlink_wifi_network_add_t *)msgbuf;
    packet->security_type = security_type;
    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    mav_array_memcpy(packet->password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_ADD, (const char *)packet, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_NETWORK_ADD UNPACKING


/**
 * @brief Get field ssid from wifi_network_add message
 *
 * @return Name of Wi-Fi network
 */
static inline uint16_t mavlink_msg_wifi_network_add_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  0);
}

/**
 * @brief Get field security_type from wifi_network_add message
 *
 * @return See the WIFI_SECURITY_TYPE enum.
 */
static inline uint8_t mavlink_msg_wifi_network_add_get_security_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field password from wifi_network_add message
 *
 * @return Password
 */
static inline uint16_t mavlink_msg_wifi_network_add_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 64,  33);
}

/**
 * @brief Decode a wifi_network_add message into a struct
 *
 * @param msg The message to decode
 * @param wifi_network_add C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_network_add_decode(const mavlink_message_t* msg, mavlink_wifi_network_add_t* wifi_network_add)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_add_get_ssid(msg, wifi_network_add->ssid);
    wifi_network_add->security_type = mavlink_msg_wifi_network_add_get_security_type(msg);
    mavlink_msg_wifi_network_add_get_password(msg, wifi_network_add->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN? msg->len : MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN;
        memset(wifi_network_add, 0, MAVLINK_MSG_ID_WIFI_NETWORK_ADD_LEN);
    memcpy(wifi_network_add, _MAV_PAYLOAD(msg), len);
#endif
}
