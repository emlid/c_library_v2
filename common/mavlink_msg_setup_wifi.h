#pragma once
// MESSAGE SETUP_WIFI PACKING

#define MAVLINK_MSG_ID_SETUP_WIFI 255

MAVPACKED(
typedef struct __mavlink_setup_wifi_t {
 char name[32]; /*< name*/
 uint8_t protocol; /*< protocol id*/
 char password[64]; /*< password*/
}) mavlink_setup_wifi_t;

#define MAVLINK_MSG_ID_SETUP_WIFI_LEN 97
#define MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN 97
#define MAVLINK_MSG_ID_255_LEN 97
#define MAVLINK_MSG_ID_255_MIN_LEN 97

#define MAVLINK_MSG_ID_SETUP_WIFI_CRC 11
#define MAVLINK_MSG_ID_255_CRC 11

#define MAVLINK_MSG_SETUP_WIFI_FIELD_NAME_LEN 32
#define MAVLINK_MSG_SETUP_WIFI_FIELD_PASSWORD_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SETUP_WIFI { \
    255, \
    "SETUP_WIFI", \
    3, \
    {  { "name", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_setup_wifi_t, name) }, \
         { "protocol", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_setup_wifi_t, protocol) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_setup_wifi_t, password) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SETUP_WIFI { \
    "SETUP_WIFI", \
    3, \
    {  { "name", NULL, MAVLINK_TYPE_CHAR, 32, 0, offsetof(mavlink_setup_wifi_t, name) }, \
         { "protocol", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_setup_wifi_t, protocol) }, \
         { "password", NULL, MAVLINK_TYPE_CHAR, 64, 33, offsetof(mavlink_setup_wifi_t, password) }, \
         } \
}
#endif

/**
 * @brief Pack a setup_wifi message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param name name
 * @param protocol protocol id
 * @param password password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_wifi_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *name, uint8_t protocol, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETUP_WIFI_LEN];
    _mav_put_uint8_t(buf, 32, protocol);
    _mav_put_char_array(buf, 0, name, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETUP_WIFI_LEN);
#else
    mavlink_setup_wifi_t packet;
    packet.protocol = protocol;
    mav_array_memcpy(packet.name, name, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETUP_WIFI_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETUP_WIFI;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
}

/**
 * @brief Pack a setup_wifi message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param name name
 * @param protocol protocol id
 * @param password password
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_setup_wifi_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *name,uint8_t protocol,const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETUP_WIFI_LEN];
    _mav_put_uint8_t(buf, 32, protocol);
    _mav_put_char_array(buf, 0, name, 32);
    _mav_put_char_array(buf, 33, password, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SETUP_WIFI_LEN);
#else
    mavlink_setup_wifi_t packet;
    packet.protocol = protocol;
    mav_array_memcpy(packet.name, name, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SETUP_WIFI_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SETUP_WIFI;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
}

/**
 * @brief Encode a setup_wifi struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param setup_wifi C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setup_wifi_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_setup_wifi_t* setup_wifi)
{
    return mavlink_msg_setup_wifi_pack(system_id, component_id, msg, setup_wifi->name, setup_wifi->protocol, setup_wifi->password);
}

/**
 * @brief Encode a setup_wifi struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param setup_wifi C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_setup_wifi_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_setup_wifi_t* setup_wifi)
{
    return mavlink_msg_setup_wifi_pack_chan(system_id, component_id, chan, msg, setup_wifi->name, setup_wifi->protocol, setup_wifi->password);
}

/**
 * @brief Send a setup_wifi message
 * @param chan MAVLink channel to send the message
 *
 * @param name name
 * @param protocol protocol id
 * @param password password
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_setup_wifi_send(mavlink_channel_t chan, const char *name, uint8_t protocol, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SETUP_WIFI_LEN];
    _mav_put_uint8_t(buf, 32, protocol);
    _mav_put_char_array(buf, 0, name, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETUP_WIFI, buf, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
#else
    mavlink_setup_wifi_t packet;
    packet.protocol = protocol;
    mav_array_memcpy(packet.name, name, sizeof(char)*32);
    mav_array_memcpy(packet.password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETUP_WIFI, (const char *)&packet, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
#endif
}

/**
 * @brief Send a setup_wifi message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_setup_wifi_send_struct(mavlink_channel_t chan, const mavlink_setup_wifi_t* setup_wifi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_setup_wifi_send(chan, setup_wifi->name, setup_wifi->protocol, setup_wifi->password);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETUP_WIFI, (const char *)setup_wifi, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
#endif
}

#if MAVLINK_MSG_ID_SETUP_WIFI_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_setup_wifi_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *name, uint8_t protocol, const char *password)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 32, protocol);
    _mav_put_char_array(buf, 0, name, 32);
    _mav_put_char_array(buf, 33, password, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETUP_WIFI, buf, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
#else
    mavlink_setup_wifi_t *packet = (mavlink_setup_wifi_t *)msgbuf;
    packet->protocol = protocol;
    mav_array_memcpy(packet->name, name, sizeof(char)*32);
    mav_array_memcpy(packet->password, password, sizeof(char)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SETUP_WIFI, (const char *)packet, MAVLINK_MSG_ID_SETUP_WIFI_MIN_LEN, MAVLINK_MSG_ID_SETUP_WIFI_LEN, MAVLINK_MSG_ID_SETUP_WIFI_CRC);
#endif
}
#endif

#endif

// MESSAGE SETUP_WIFI UNPACKING


/**
 * @brief Get field name from setup_wifi message
 *
 * @return name
 */
static inline uint16_t mavlink_msg_setup_wifi_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 32,  0);
}

/**
 * @brief Get field protocol from setup_wifi message
 *
 * @return protocol id
 */
static inline uint8_t mavlink_msg_setup_wifi_get_protocol(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field password from setup_wifi message
 *
 * @return password
 */
static inline uint16_t mavlink_msg_setup_wifi_get_password(const mavlink_message_t* msg, char *password)
{
    return _MAV_RETURN_char_array(msg, password, 64,  33);
}

/**
 * @brief Decode a setup_wifi message into a struct
 *
 * @param msg The message to decode
 * @param setup_wifi C-struct to decode the message contents into
 */
static inline void mavlink_msg_setup_wifi_decode(const mavlink_message_t* msg, mavlink_setup_wifi_t* setup_wifi)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_setup_wifi_get_name(msg, setup_wifi->name);
    setup_wifi->protocol = mavlink_msg_setup_wifi_get_protocol(msg);
    mavlink_msg_setup_wifi_get_password(msg, setup_wifi->password);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SETUP_WIFI_LEN? msg->len : MAVLINK_MSG_ID_SETUP_WIFI_LEN;
        memset(setup_wifi, 0, MAVLINK_MSG_ID_SETUP_WIFI_LEN);
    memcpy(setup_wifi, _MAV_PAYLOAD(msg), len);
#endif
}
