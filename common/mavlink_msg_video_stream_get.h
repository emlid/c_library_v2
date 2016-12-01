#pragma once
// MESSAGE VIDEO_STREAM_GET PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_GET 271

MAVPACKED(
typedef struct __mavlink_video_stream_get_t {
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t id; /*< Video device ID*/
 uint8_t command; /*< Valid options are: VIDEO_STREAM_GET_CMD_SERVER = 1, VIDEO_STREAM_GET_CMD_STREAMS = 2, VIDEO_STREAM_GET_CMD_STREAM_ATTRIBUTES = 3*/
}) mavlink_video_stream_get_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN 4
#define MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN 4
#define MAVLINK_MSG_ID_271_LEN 4
#define MAVLINK_MSG_ID_271_MIN_LEN 4

#define MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC 81
#define MAVLINK_MSG_ID_271_CRC 81



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_GET { \
    271, \
    "VIDEO_STREAM_GET", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_get_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_video_stream_get_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_video_stream_get_t, id) }, \
         { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_video_stream_get_t, command) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_GET { \
    "VIDEO_STREAM_GET", \
    4, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_video_stream_get_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_video_stream_get_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_video_stream_get_t, id) }, \
         { "command", NULL, MAVLINK_TYPE_UINT8_T, 0, 3, offsetof(mavlink_video_stream_get_t, command) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_get message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param command Valid options are: VIDEO_STREAM_GET_CMD_SERVER = 1, VIDEO_STREAM_GET_CMD_STREAMS = 2, VIDEO_STREAM_GET_CMD_STREAM_ATTRIBUTES = 3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_get_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t id, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, id);
    _mav_put_uint8_t(buf, 3, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN);
#else
    mavlink_video_stream_get_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_GET;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
}

/**
 * @brief Pack a video_stream_get message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param command Valid options are: VIDEO_STREAM_GET_CMD_SERVER = 1, VIDEO_STREAM_GET_CMD_STREAMS = 2, VIDEO_STREAM_GET_CMD_STREAM_ATTRIBUTES = 3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_get_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t id,uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, id);
    _mav_put_uint8_t(buf, 3, command);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN);
#else
    mavlink_video_stream_get_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    packet.command = command;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_GET;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
}

/**
 * @brief Encode a video_stream_get struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_get C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_get_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_get_t* video_stream_get)
{
    return mavlink_msg_video_stream_get_pack(system_id, component_id, msg, video_stream_get->target_system, video_stream_get->target_component, video_stream_get->id, video_stream_get->command);
}

/**
 * @brief Encode a video_stream_get struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_get C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_get_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_get_t* video_stream_get)
{
    return mavlink_msg_video_stream_get_pack_chan(system_id, component_id, chan, msg, video_stream_get->target_system, video_stream_get->target_component, video_stream_get->id, video_stream_get->command);
}

/**
 * @brief Send a video_stream_get message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param command Valid options are: VIDEO_STREAM_GET_CMD_SERVER = 1, VIDEO_STREAM_GET_CMD_STREAMS = 2, VIDEO_STREAM_GET_CMD_STREAM_ATTRIBUTES = 3
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_video_stream_get_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t id, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN];
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, id);
    _mav_put_uint8_t(buf, 3, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET, buf, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
#else
    mavlink_video_stream_get_t packet;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    packet.command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET, (const char *)&packet, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
#endif
}

/**
 * @brief Send a video_stream_get message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_video_stream_get_send_struct(mavlink_channel_t chan, const mavlink_video_stream_get_t* video_stream_get)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_video_stream_get_send(chan, video_stream_get->target_system, video_stream_get->target_component, video_stream_get->id, video_stream_get->command);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET, (const char *)video_stream_get, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
#endif
}

#if MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_video_stream_get_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t id, uint8_t command)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);
    _mav_put_uint8_t(buf, 1, target_component);
    _mav_put_uint8_t(buf, 2, id);
    _mav_put_uint8_t(buf, 3, command);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET, buf, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
#else
    mavlink_video_stream_get_t *packet = (mavlink_video_stream_get_t *)msgbuf;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->id = id;
    packet->command = command;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_GET, (const char *)packet, MAVLINK_MSG_ID_VIDEO_STREAM_GET_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_GET_CRC);
#endif
}
#endif

#endif

// MESSAGE VIDEO_STREAM_GET UNPACKING


/**
 * @brief Get field target_system from video_stream_get message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_video_stream_get_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from video_stream_get message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_video_stream_get_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field id from video_stream_get message
 *
 * @return Video device ID
 */
static inline uint8_t mavlink_msg_video_stream_get_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field command from video_stream_get message
 *
 * @return Valid options are: VIDEO_STREAM_GET_CMD_SERVER = 1, VIDEO_STREAM_GET_CMD_STREAMS = 2, VIDEO_STREAM_GET_CMD_STREAM_ATTRIBUTES = 3
 */
static inline uint8_t mavlink_msg_video_stream_get_get_command(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Decode a video_stream_get message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_get C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_get_decode(const mavlink_message_t* msg, mavlink_video_stream_get_t* video_stream_get)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    video_stream_get->target_system = mavlink_msg_video_stream_get_get_target_system(msg);
    video_stream_get->target_component = mavlink_msg_video_stream_get_get_target_component(msg);
    video_stream_get->id = mavlink_msg_video_stream_get_get_id(msg);
    video_stream_get->command = mavlink_msg_video_stream_get_get_command(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN? msg->len : MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN;
        memset(video_stream_get, 0, MAVLINK_MSG_ID_VIDEO_STREAM_GET_LEN);
    memcpy(video_stream_get, _MAV_PAYLOAD(msg), len);
#endif
}
