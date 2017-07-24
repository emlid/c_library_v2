#pragma once
// MESSAGE WIFI_NETWORK_CONNECT PACKING

#define MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT 401

MAVPACKED(
typedef struct __mavlink_wifi_network_connect_t {
 char ssid[32]; /*< Name of Wi-Fi network*/
}) mavlink_wifi_network_connect_t;

#define MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN 32
#define MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN 32
#define MAVLINK_MSG_ID_401_LEN 32
#define MAVLINK_MSG_ID_401_MIN_LEN 32

#define MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC 19
#define MAVLINK_MSG_ID_401_CRC 19

#define MAVLINK_MSG_WIFI_NETWORK_CONNECT_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_CONNECT { \
    401, \
    "WIFI_NETWORK_CONNECT", \
    1, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_connect_t, ssid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_CONNECT { \
    "WIFI_NETWORK_CONNECT", \
    1, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_connect_t, ssid) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_network_connect message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid Name of Wi-Fi network
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_connect_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN);
#else
    mavlink_wifi_network_connect_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
}

/**
 * @brief Pack a wifi_network_connect message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid Name of Wi-Fi network
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_connect_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN);
#else
    mavlink_wifi_network_connect_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
}

/**
 * @brief Encode a wifi_network_connect struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_connect C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_connect_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_network_connect_t* wifi_network_connect)
{
    return mavlink_msg_wifi_network_connect_pack(system_id, component_id, msg, wifi_network_connect->ssid);
}

/**
 * @brief Encode a wifi_network_connect struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_connect C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_connect_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_network_connect_t* wifi_network_connect)
{
    return mavlink_msg_wifi_network_connect_pack_chan(system_id, component_id, chan, msg, wifi_network_connect->ssid);
}

/**
 * @brief Send a wifi_network_connect message
 * @param chan MAVLink channel to send the message
 *
 * @param ssid Name of Wi-Fi network
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_network_connect_send(mavlink_channel_t chan, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT, buf, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
#else
    mavlink_wifi_network_connect_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT, (const char *)&packet, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
#endif
}

/**
 * @brief Send a wifi_network_connect message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_network_connect_send_struct(mavlink_channel_t chan, const mavlink_wifi_network_connect_t* wifi_network_connect)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_connect_send(chan, wifi_network_connect->ssid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT, (const char *)wifi_network_connect, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_network_connect_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT, buf, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
#else
    mavlink_wifi_network_connect_t *packet = (mavlink_wifi_network_connect_t *)msgbuf;

    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT, (const char *)packet, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_NETWORK_CONNECT UNPACKING


/**
 * @brief Get field ssid from wifi_network_connect message
 *
 * @return Name of Wi-Fi network
 */
static inline uint16_t mavlink_msg_wifi_network_connect_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  0);
}

/**
 * @brief Decode a wifi_network_connect message into a struct
 *
 * @param msg The message to decode
 * @param wifi_network_connect C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_network_connect_decode(const mavlink_message_t* msg, mavlink_wifi_network_connect_t* wifi_network_connect)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_connect_get_ssid(msg, wifi_network_connect->ssid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN? msg->len : MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN;
        memset(wifi_network_connect, 0, MAVLINK_MSG_ID_WIFI_NETWORK_CONNECT_LEN);
    memcpy(wifi_network_connect, _MAV_PAYLOAD(msg), len);
#endif
}
