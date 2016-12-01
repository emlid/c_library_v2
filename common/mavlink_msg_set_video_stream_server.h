#pragma once
// MESSAGE SET_VIDEO_STREAM_SERVER PACKING

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER 273

MAVPACKED(
typedef struct __mavlink_set_video_stream_server_t {
 uint16_t port; /*< Video stream port on which the server will accept connections*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 char ip[45]; /*< Video stream server ip to accept connections on the given address*/
}) mavlink_set_video_stream_server_t;

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN 49
#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN 49
#define MAVLINK_MSG_ID_273_LEN 49
#define MAVLINK_MSG_ID_273_MIN_LEN 49

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC 221
#define MAVLINK_MSG_ID_273_CRC 221

#define MAVLINK_MSG_SET_VIDEO_STREAM_SERVER_FIELD_IP_LEN 45

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_VIDEO_STREAM_SERVER { \
    273, \
    "SET_VIDEO_STREAM_SERVER", \
    4, \
    {  { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_set_video_stream_server_t, port) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_video_stream_server_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_set_video_stream_server_t, target_component) }, \
         { "ip", NULL, MAVLINK_TYPE_CHAR, 45, 4, offsetof(mavlink_set_video_stream_server_t, ip) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_VIDEO_STREAM_SERVER { \
    "SET_VIDEO_STREAM_SERVER", \
    4, \
    {  { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_set_video_stream_server_t, port) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_set_video_stream_server_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_set_video_stream_server_t, target_component) }, \
         { "ip", NULL, MAVLINK_TYPE_CHAR, 45, 4, offsetof(mavlink_set_video_stream_server_t, ip) }, \
         } \
}
#endif

/**
 * @brief Pack a set_video_stream_server message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_video_stream_server_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, ip, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN);
#else
    mavlink_set_video_stream_server_t packet;
    packet.port = port;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
}

/**
 * @brief Pack a set_video_stream_server message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_video_stream_server_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,const char *ip,uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, ip, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN);
#else
    mavlink_set_video_stream_server_t packet;
    packet.port = port;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
}

/**
 * @brief Encode a set_video_stream_server struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_video_stream_server C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_video_stream_server_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_video_stream_server_t* set_video_stream_server)
{
    return mavlink_msg_set_video_stream_server_pack(system_id, component_id, msg, set_video_stream_server->target_system, set_video_stream_server->target_component, set_video_stream_server->ip, set_video_stream_server->port);
}

/**
 * @brief Encode a set_video_stream_server struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_video_stream_server C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_video_stream_server_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_video_stream_server_t* set_video_stream_server)
{
    return mavlink_msg_set_video_stream_server_pack_chan(system_id, component_id, chan, msg, set_video_stream_server->target_system, set_video_stream_server->target_component, set_video_stream_server->ip, set_video_stream_server->port);
}

/**
 * @brief Send a set_video_stream_server message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_video_stream_server_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, ip, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER, buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
#else
    mavlink_set_video_stream_server_t packet;
    packet.port = port;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER, (const char *)&packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
#endif
}

/**
 * @brief Send a set_video_stream_server message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_video_stream_server_send_struct(mavlink_channel_t chan, const mavlink_set_video_stream_server_t* set_video_stream_server)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_video_stream_server_send(chan, set_video_stream_server->target_system, set_video_stream_server->target_component, set_video_stream_server->ip, set_video_stream_server->port);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER, (const char *)set_video_stream_server, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_video_stream_server_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_uint8_t(buf, 2, target_system);
    _mav_put_uint8_t(buf, 3, target_component);
    _mav_put_char_array(buf, 4, ip, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER, buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
#else
    mavlink_set_video_stream_server_t *packet = (mavlink_set_video_stream_server_t *)msgbuf;
    packet->port = port;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->ip, ip, sizeof(char)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER, (const char *)packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_VIDEO_STREAM_SERVER UNPACKING


/**
 * @brief Get field target_system from set_video_stream_server message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_set_video_stream_server_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field target_component from set_video_stream_server message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_set_video_stream_server_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field ip from set_video_stream_server message
 *
 * @return Video stream server ip to accept connections on the given address
 */
static inline uint16_t mavlink_msg_set_video_stream_server_get_ip(const mavlink_message_t* msg, char *ip)
{
    return _MAV_RETURN_char_array(msg, ip, 45,  4);
}

/**
 * @brief Get field port from set_video_stream_server message
 *
 * @return Video stream port on which the server will accept connections
 */
static inline uint16_t mavlink_msg_set_video_stream_server_get_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a set_video_stream_server message into a struct
 *
 * @param msg The message to decode
 * @param set_video_stream_server C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_video_stream_server_decode(const mavlink_message_t* msg, mavlink_set_video_stream_server_t* set_video_stream_server)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_video_stream_server->port = mavlink_msg_set_video_stream_server_get_port(msg);
    set_video_stream_server->target_system = mavlink_msg_set_video_stream_server_get_target_system(msg);
    set_video_stream_server->target_component = mavlink_msg_set_video_stream_server_get_target_component(msg);
    mavlink_msg_set_video_stream_server_get_ip(msg, set_video_stream_server->ip);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN? msg->len : MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN;
        memset(set_video_stream_server, 0, MAVLINK_MSG_ID_SET_VIDEO_STREAM_SERVER_LEN);
    memcpy(set_video_stream_server, _MAV_PAYLOAD(msg), len);
#endif
}
