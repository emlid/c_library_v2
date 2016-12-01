#pragma once
// MESSAGE VIDEO_STREAM_URI PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_URI 274

MAVPACKED(
typedef struct __mavlink_video_stream_uri_t {
 uint8_t id; /*< Video device ID*/
 char uri[100]; /*< URI representing the stream*/
}) mavlink_video_stream_uri_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN 101
#define MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN 101
#define MAVLINK_MSG_ID_274_LEN 101
#define MAVLINK_MSG_ID_274_MIN_LEN 101

#define MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC 200
#define MAVLINK_MSG_ID_274_CRC 200

#define MAVLINK_MSG_VIDEO_STREAM_URI_FIELD_URI_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_URI { \
    274, \
    "VIDEO_STREAM_URI", \
    2, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_uri_t, id) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 100, 1, offsetof(mavlink_video_stream_uri_t, uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_URI { \
    "VIDEO_STREAM_URI", \
    2, \
    {  { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_uri_t, id) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 100, 1, offsetof(mavlink_video_stream_uri_t, uri) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_uri message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Video device ID
 * @param uri URI representing the stream
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_uri_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN];
    _mav_put_uint8_t(buf, 0, id);
    _mav_put_char_array(buf, 1, uri, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN);
#else
    mavlink_video_stream_uri_t packet;
    packet.id = id;
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_URI;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
}

/**
 * @brief Pack a video_stream_uri message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id Video device ID
 * @param uri URI representing the stream
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_uri_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN];
    _mav_put_uint8_t(buf, 0, id);
    _mav_put_char_array(buf, 1, uri, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN);
#else
    mavlink_video_stream_uri_t packet;
    packet.id = id;
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_URI;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
}

/**
 * @brief Encode a video_stream_uri struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_uri C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_uri_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_uri_t* video_stream_uri)
{
    return mavlink_msg_video_stream_uri_pack(system_id, component_id, msg, video_stream_uri->id, video_stream_uri->uri);
}

/**
 * @brief Encode a video_stream_uri struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_uri C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_uri_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_uri_t* video_stream_uri)
{
    return mavlink_msg_video_stream_uri_pack_chan(system_id, component_id, chan, msg, video_stream_uri->id, video_stream_uri->uri);
}

/**
 * @brief Send a video_stream_uri message
 * @param chan MAVLink channel to send the message
 *
 * @param id Video device ID
 * @param uri URI representing the stream
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_video_stream_uri_send(mavlink_channel_t chan, uint8_t id, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN];
    _mav_put_uint8_t(buf, 0, id);
    _mav_put_char_array(buf, 1, uri, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI, buf, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
#else
    mavlink_video_stream_uri_t packet;
    packet.id = id;
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI, (const char *)&packet, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
#endif
}

/**
 * @brief Send a video_stream_uri message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_video_stream_uri_send_struct(mavlink_channel_t chan, const mavlink_video_stream_uri_t* video_stream_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_video_stream_uri_send(chan, video_stream_uri->id, video_stream_uri->uri);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI, (const char *)video_stream_uri, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
#endif
}

#if MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_video_stream_uri_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, id);
    _mav_put_char_array(buf, 1, uri, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI, buf, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
#else
    mavlink_video_stream_uri_t *packet = (mavlink_video_stream_uri_t *)msgbuf;
    packet->id = id;
    mav_array_memcpy(packet->uri, uri, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_URI, (const char *)packet, MAVLINK_MSG_ID_VIDEO_STREAM_URI_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_URI_CRC);
#endif
}
#endif

#endif

// MESSAGE VIDEO_STREAM_URI UNPACKING


/**
 * @brief Get field id from video_stream_uri message
 *
 * @return Video device ID
 */
static inline uint8_t mavlink_msg_video_stream_uri_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field uri from video_stream_uri message
 *
 * @return URI representing the stream
 */
static inline uint16_t mavlink_msg_video_stream_uri_get_uri(const mavlink_message_t* msg, char *uri)
{
    return _MAV_RETURN_char_array(msg, uri, 100,  1);
}

/**
 * @brief Decode a video_stream_uri message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_uri C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_uri_decode(const mavlink_message_t* msg, mavlink_video_stream_uri_t* video_stream_uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    video_stream_uri->id = mavlink_msg_video_stream_uri_get_id(msg);
    mavlink_msg_video_stream_uri_get_uri(msg, video_stream_uri->uri);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN? msg->len : MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN;
        memset(video_stream_uri, 0, MAVLINK_MSG_ID_VIDEO_STREAM_URI_LEN);
    memcpy(video_stream_uri, _MAV_PAYLOAD(msg), len);
#endif
}
