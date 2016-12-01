#pragma once
// MESSAGE VIDEO_STREAM_SERVER PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_SERVER 272

MAVPACKED(
typedef struct __mavlink_video_stream_server_t {
 uint16_t port; /*< Video stream port on which the server will accept connections*/
 char ip[45]; /*< Video stream server ip to accept connections on the given address*/
}) mavlink_video_stream_server_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN 47
#define MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN 47
#define MAVLINK_MSG_ID_272_LEN 47
#define MAVLINK_MSG_ID_272_MIN_LEN 47

#define MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC 255
#define MAVLINK_MSG_ID_272_CRC 255

#define MAVLINK_MSG_VIDEO_STREAM_SERVER_FIELD_IP_LEN 45

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_SERVER { \
    272, \
    "VIDEO_STREAM_SERVER", \
    2, \
    {  { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_video_stream_server_t, port) }, \
         { "ip", NULL, MAVLINK_TYPE_CHAR, 45, 2, offsetof(mavlink_video_stream_server_t, ip) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_SERVER { \
    "VIDEO_STREAM_SERVER", \
    2, \
    {  { "port", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_video_stream_server_t, port) }, \
         { "ip", NULL, MAVLINK_TYPE_CHAR, 45, 2, offsetof(mavlink_video_stream_server_t, ip) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_server message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_server_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, ip, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN);
#else
    mavlink_video_stream_server_t packet;
    packet.port = port;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_SERVER;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
}

/**
 * @brief Pack a video_stream_server message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_server_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *ip,uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, ip, 45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN);
#else
    mavlink_video_stream_server_t packet;
    packet.port = port;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_SERVER;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
}

/**
 * @brief Encode a video_stream_server struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_server C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_server_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_server_t* video_stream_server)
{
    return mavlink_msg_video_stream_server_pack(system_id, component_id, msg, video_stream_server->ip, video_stream_server->port);
}

/**
 * @brief Encode a video_stream_server struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_server C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_server_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_server_t* video_stream_server)
{
    return mavlink_msg_video_stream_server_pack_chan(system_id, component_id, chan, msg, video_stream_server->ip, video_stream_server->port);
}

/**
 * @brief Send a video_stream_server message
 * @param chan MAVLink channel to send the message
 *
 * @param ip Video stream server ip to accept connections on the given address
 * @param port Video stream port on which the server will accept connections
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_video_stream_server_send(mavlink_channel_t chan, const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN];
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, ip, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER, buf, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
#else
    mavlink_video_stream_server_t packet;
    packet.port = port;
    mav_array_memcpy(packet.ip, ip, sizeof(char)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER, (const char *)&packet, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
#endif
}

/**
 * @brief Send a video_stream_server message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_video_stream_server_send_struct(mavlink_channel_t chan, const mavlink_video_stream_server_t* video_stream_server)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_video_stream_server_send(chan, video_stream_server->ip, video_stream_server->port);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER, (const char *)video_stream_server, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
#endif
}

#if MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_video_stream_server_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *ip, uint16_t port)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint16_t(buf, 0, port);
    _mav_put_char_array(buf, 2, ip, 45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER, buf, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
#else
    mavlink_video_stream_server_t *packet = (mavlink_video_stream_server_t *)msgbuf;
    packet->port = port;
    mav_array_memcpy(packet->ip, ip, sizeof(char)*45);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER, (const char *)packet, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_CRC);
#endif
}
#endif

#endif

// MESSAGE VIDEO_STREAM_SERVER UNPACKING


/**
 * @brief Get field ip from video_stream_server message
 *
 * @return Video stream server ip to accept connections on the given address
 */
static inline uint16_t mavlink_msg_video_stream_server_get_ip(const mavlink_message_t* msg, char *ip)
{
    return _MAV_RETURN_char_array(msg, ip, 45,  2);
}

/**
 * @brief Get field port from video_stream_server message
 *
 * @return Video stream port on which the server will accept connections
 */
static inline uint16_t mavlink_msg_video_stream_server_get_port(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Decode a video_stream_server message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_server C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_server_decode(const mavlink_message_t* msg, mavlink_video_stream_server_t* video_stream_server)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    video_stream_server->port = mavlink_msg_video_stream_server_get_port(msg);
    mavlink_msg_video_stream_server_get_ip(msg, video_stream_server->ip);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN? msg->len : MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN;
        memset(video_stream_server, 0, MAVLINK_MSG_ID_VIDEO_STREAM_SERVER_LEN);
    memcpy(video_stream_server, _MAV_PAYLOAD(msg), len);
#endif
}
