#pragma once
// MESSAGE WIFI_NETWORK_DELETE PACKING

#define MAVLINK_MSG_ID_WIFI_NETWORK_DELETE 404

MAVPACKED(
typedef struct __mavlink_wifi_network_delete_t {
 char ssid[32]; /*< Name of Wi-Fi network*/
}) mavlink_wifi_network_delete_t;

#define MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN 32
#define MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN 32
#define MAVLINK_MSG_ID_404_LEN 32
#define MAVLINK_MSG_ID_404_MIN_LEN 32

#define MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC 247
#define MAVLINK_MSG_ID_404_CRC 247

#define MAVLINK_MSG_WIFI_NETWORK_DELETE_FIELD_SSID_LEN 32

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_DELETE { \
    404, \
    "WIFI_NETWORK_DELETE", \
    1, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_delete_t, ssid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_WIFI_NETWORK_DELETE { \
    "WIFI_NETWORK_DELETE", \
    1, \
    {  { "ssid", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_wifi_network_delete_t, ssid) }, \
         } \
}
#endif

/**
 * @brief Pack a wifi_network_delete message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ssid Name of Wi-Fi network
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_delete_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN);
#else
    mavlink_wifi_network_delete_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_DELETE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
}

/**
 * @brief Pack a wifi_network_delete message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ssid Name of Wi-Fi network
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_wifi_network_delete_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN);
#else
    mavlink_wifi_network_delete_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_WIFI_NETWORK_DELETE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
}

/**
 * @brief Encode a wifi_network_delete struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_delete C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_delete_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_wifi_network_delete_t* wifi_network_delete)
{
    return mavlink_msg_wifi_network_delete_pack(system_id, component_id, msg, wifi_network_delete->ssid);
}

/**
 * @brief Encode a wifi_network_delete struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param wifi_network_delete C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_wifi_network_delete_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_wifi_network_delete_t* wifi_network_delete)
{
    return mavlink_msg_wifi_network_delete_pack_chan(system_id, component_id, chan, msg, wifi_network_delete->ssid);
}

/**
 * @brief Send a wifi_network_delete message
 * @param chan MAVLink channel to send the message
 *
 * @param ssid Name of Wi-Fi network
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_wifi_network_delete_send(mavlink_channel_t chan, const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN];

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE, buf, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
#else
    mavlink_wifi_network_delete_t packet;

    mav_array_memcpy(packet.ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE, (const char *)&packet, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
#endif
}

/**
 * @brief Send a wifi_network_delete message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_wifi_network_delete_send_struct(mavlink_channel_t chan, const mavlink_wifi_network_delete_t* wifi_network_delete)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_delete_send(chan, wifi_network_delete->ssid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE, (const char *)wifi_network_delete, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
#endif
}

#if MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_wifi_network_delete_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ssid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_char_array(buf, 0, ssid, 32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE, buf, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
#else
    mavlink_wifi_network_delete_t *packet = (mavlink_wifi_network_delete_t *)msgbuf;

    mav_array_memcpy(packet->ssid, ssid, sizeof(char)*32);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE, (const char *)packet, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_MIN_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_CRC);
#endif
}
#endif

#endif

// MESSAGE WIFI_NETWORK_DELETE UNPACKING


/**
 * @brief Get field ssid from wifi_network_delete message
 *
 * @return Name of Wi-Fi network
 */
static inline uint16_t mavlink_msg_wifi_network_delete_get_ssid(const mavlink_message_t* msg, char *ssid)
{
    return _MAV_RETURN_char_array(msg, ssid, 32,  0);
}

/**
 * @brief Decode a wifi_network_delete message into a struct
 *
 * @param msg The message to decode
 * @param wifi_network_delete C-struct to decode the message contents into
 */
static inline void mavlink_msg_wifi_network_delete_decode(const mavlink_message_t* msg, mavlink_wifi_network_delete_t* wifi_network_delete)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_wifi_network_delete_get_ssid(msg, wifi_network_delete->ssid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN? msg->len : MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN;
        memset(wifi_network_delete, 0, MAVLINK_MSG_ID_WIFI_NETWORK_DELETE_LEN);
    memcpy(wifi_network_delete, _MAV_PAYLOAD(msg), len);
#endif
}
