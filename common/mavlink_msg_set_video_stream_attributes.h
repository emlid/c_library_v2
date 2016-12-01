#pragma once
// MESSAGE SET_VIDEO_STREAM_ATTRIBUTES PACKING

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES 276

MAVPACKED(
typedef struct __mavlink_set_video_stream_attributes_t {
 uint32_t format; /*< Video format*/
 uint16_t frame_size[2]; /*< Video frame size, array followed by width and height*/
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
 uint8_t id; /*< Video device ID*/
 char mount_path[55]; /*< Video stream mount path to build the URI*/
}) mavlink_set_video_stream_attributes_t;

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN 66
#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN 66
#define MAVLINK_MSG_ID_276_LEN 66
#define MAVLINK_MSG_ID_276_MIN_LEN 66

#define MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC 19
#define MAVLINK_MSG_ID_276_CRC 19

#define MAVLINK_MSG_SET_VIDEO_STREAM_ATTRIBUTES_FIELD_FRAME_SIZE_LEN 2
#define MAVLINK_MSG_SET_VIDEO_STREAM_ATTRIBUTES_FIELD_MOUNT_PATH_LEN 55

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SET_VIDEO_STREAM_ATTRIBUTES { \
    276, \
    "SET_VIDEO_STREAM_ATTRIBUTES", \
    6, \
    {  { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_video_stream_attributes_t, format) }, \
         { "frame_size", NULL, MAVLINK_TYPE_UINT16_T, 2, 4, offsetof(mavlink_set_video_stream_attributes_t, frame_size) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_set_video_stream_attributes_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_set_video_stream_attributes_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_set_video_stream_attributes_t, id) }, \
         { "mount_path", NULL, MAVLINK_TYPE_CHAR, 55, 11, offsetof(mavlink_set_video_stream_attributes_t, mount_path) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SET_VIDEO_STREAM_ATTRIBUTES { \
    "SET_VIDEO_STREAM_ATTRIBUTES", \
    6, \
    {  { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_set_video_stream_attributes_t, format) }, \
         { "frame_size", NULL, MAVLINK_TYPE_UINT16_T, 2, 4, offsetof(mavlink_set_video_stream_attributes_t, frame_size) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_set_video_stream_attributes_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_set_video_stream_attributes_t, target_component) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_set_video_stream_attributes_t, id) }, \
         { "mount_path", NULL, MAVLINK_TYPE_CHAR, 55, 11, offsetof(mavlink_set_video_stream_attributes_t, mount_path) }, \
         } \
}
#endif

/**
 * @brief Pack a set_video_stream_attributes message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param format Video format
 * @param frame_size Video frame size, array followed by width and height
 * @param mount_path Video stream mount path to build the URI
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system, uint8_t target_component, uint8_t id, uint32_t format, const uint16_t *frame_size, const char *mount_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, format);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, id);
    _mav_put_uint16_t_array(buf, 4, frame_size, 2);
    _mav_put_char_array(buf, 11, mount_path, 55);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN);
#else
    mavlink_set_video_stream_attributes_t packet;
    packet.format = format;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.mount_path, mount_path, sizeof(char)*55);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
}

/**
 * @brief Pack a set_video_stream_attributes message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param format Video format
 * @param frame_size Video frame size, array followed by width and height
 * @param mount_path Video stream mount path to build the URI
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system,uint8_t target_component,uint8_t id,uint32_t format,const uint16_t *frame_size,const char *mount_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, format);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, id);
    _mav_put_uint16_t_array(buf, 4, frame_size, 2);
    _mav_put_char_array(buf, 11, mount_path, 55);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN);
#else
    mavlink_set_video_stream_attributes_t packet;
    packet.format = format;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.mount_path, mount_path, sizeof(char)*55);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
}

/**
 * @brief Encode a set_video_stream_attributes struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param set_video_stream_attributes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_set_video_stream_attributes_t* set_video_stream_attributes)
{
    return mavlink_msg_set_video_stream_attributes_pack(system_id, component_id, msg, set_video_stream_attributes->target_system, set_video_stream_attributes->target_component, set_video_stream_attributes->id, set_video_stream_attributes->format, set_video_stream_attributes->frame_size, set_video_stream_attributes->mount_path);
}

/**
 * @brief Encode a set_video_stream_attributes struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param set_video_stream_attributes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_set_video_stream_attributes_t* set_video_stream_attributes)
{
    return mavlink_msg_set_video_stream_attributes_pack_chan(system_id, component_id, chan, msg, set_video_stream_attributes->target_system, set_video_stream_attributes->target_component, set_video_stream_attributes->id, set_video_stream_attributes->format, set_video_stream_attributes->frame_size, set_video_stream_attributes->mount_path);
}

/**
 * @brief Send a set_video_stream_attributes message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param id Video device ID
 * @param format Video format
 * @param frame_size Video frame size, array followed by width and height
 * @param mount_path Video stream mount path to build the URI
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_set_video_stream_attributes_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint8_t id, uint32_t format, const uint16_t *frame_size, const char *mount_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, format);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, id);
    _mav_put_uint16_t_array(buf, 4, frame_size, 2);
    _mav_put_char_array(buf, 11, mount_path, 55);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES, buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
#else
    mavlink_set_video_stream_attributes_t packet;
    packet.format = format;
    packet.target_system = target_system;
    packet.target_component = target_component;
    packet.id = id;
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.mount_path, mount_path, sizeof(char)*55);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES, (const char *)&packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}

/**
 * @brief Send a set_video_stream_attributes message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_set_video_stream_attributes_send_struct(mavlink_channel_t chan, const mavlink_set_video_stream_attributes_t* set_video_stream_attributes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_set_video_stream_attributes_send(chan, set_video_stream_attributes->target_system, set_video_stream_attributes->target_component, set_video_stream_attributes->id, set_video_stream_attributes->format, set_video_stream_attributes->frame_size, set_video_stream_attributes->mount_path);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES, (const char *)set_video_stream_attributes, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}

#if MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_set_video_stream_attributes_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system, uint8_t target_component, uint8_t id, uint32_t format, const uint16_t *frame_size, const char *mount_path)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, format);
    _mav_put_uint8_t(buf, 8, target_system);
    _mav_put_uint8_t(buf, 9, target_component);
    _mav_put_uint8_t(buf, 10, id);
    _mav_put_uint16_t_array(buf, 4, frame_size, 2);
    _mav_put_char_array(buf, 11, mount_path, 55);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES, buf, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
#else
    mavlink_set_video_stream_attributes_t *packet = (mavlink_set_video_stream_attributes_t *)msgbuf;
    packet->format = format;
    packet->target_system = target_system;
    packet->target_component = target_component;
    packet->id = id;
    mav_array_memcpy(packet->frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet->mount_path, mount_path, sizeof(char)*55);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES, (const char *)packet, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}
#endif

#endif

// MESSAGE SET_VIDEO_STREAM_ATTRIBUTES UNPACKING


/**
 * @brief Get field target_system from set_video_stream_attributes message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_set_video_stream_attributes_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field target_component from set_video_stream_attributes message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_set_video_stream_attributes_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field id from set_video_stream_attributes message
 *
 * @return Video device ID
 */
static inline uint8_t mavlink_msg_set_video_stream_attributes_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field format from set_video_stream_attributes message
 *
 * @return Video format
 */
static inline uint32_t mavlink_msg_set_video_stream_attributes_get_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field frame_size from set_video_stream_attributes message
 *
 * @return Video frame size, array followed by width and height
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_get_frame_size(const mavlink_message_t* msg, uint16_t *frame_size)
{
    return _MAV_RETURN_uint16_t_array(msg, frame_size, 2,  4);
}

/**
 * @brief Get field mount_path from set_video_stream_attributes message
 *
 * @return Video stream mount path to build the URI
 */
static inline uint16_t mavlink_msg_set_video_stream_attributes_get_mount_path(const mavlink_message_t* msg, char *mount_path)
{
    return _MAV_RETURN_char_array(msg, mount_path, 55,  11);
}

/**
 * @brief Decode a set_video_stream_attributes message into a struct
 *
 * @param msg The message to decode
 * @param set_video_stream_attributes C-struct to decode the message contents into
 */
static inline void mavlink_msg_set_video_stream_attributes_decode(const mavlink_message_t* msg, mavlink_set_video_stream_attributes_t* set_video_stream_attributes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    set_video_stream_attributes->format = mavlink_msg_set_video_stream_attributes_get_format(msg);
    mavlink_msg_set_video_stream_attributes_get_frame_size(msg, set_video_stream_attributes->frame_size);
    set_video_stream_attributes->target_system = mavlink_msg_set_video_stream_attributes_get_target_system(msg);
    set_video_stream_attributes->target_component = mavlink_msg_set_video_stream_attributes_get_target_component(msg);
    set_video_stream_attributes->id = mavlink_msg_set_video_stream_attributes_get_id(msg);
    mavlink_msg_set_video_stream_attributes_get_mount_path(msg, set_video_stream_attributes->mount_path);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN? msg->len : MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN;
        memset(set_video_stream_attributes, 0, MAVLINK_MSG_ID_SET_VIDEO_STREAM_ATTRIBUTES_LEN);
    memcpy(set_video_stream_attributes, _MAV_PAYLOAD(msg), len);
#endif
}
