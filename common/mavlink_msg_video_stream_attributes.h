#pragma once
// MESSAGE VIDEO_STREAM_ATTRIBUTES PACKING

#define MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES 275

MAVPACKED(
typedef struct __mavlink_video_stream_attributes_t {
 uint32_t capabilities; /*< Union of device capabilities flags*/
 uint32_t format; /*< Video format set in FourCC*/
 uint32_t available_formats[20]; /*< Video available formats*/
 uint16_t frame_size[2]; /*< Video frame size in pixels, array followed by width and height*/
 uint8_t id; /*< Video device ID*/
 char uri[100]; /*< Video stream URI*/
}) mavlink_video_stream_attributes_t;

#define MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN 193
#define MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN 193
#define MAVLINK_MSG_ID_275_LEN 193
#define MAVLINK_MSG_ID_275_MIN_LEN 193

#define MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC 121
#define MAVLINK_MSG_ID_275_CRC 121

#define MAVLINK_MSG_VIDEO_STREAM_ATTRIBUTES_FIELD_AVAILABLE_FORMATS_LEN 20
#define MAVLINK_MSG_VIDEO_STREAM_ATTRIBUTES_FIELD_FRAME_SIZE_LEN 2
#define MAVLINK_MSG_VIDEO_STREAM_ATTRIBUTES_FIELD_URI_LEN 100

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_ATTRIBUTES { \
    275, \
    "VIDEO_STREAM_ATTRIBUTES", \
    6, \
    {  { "capabilities", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_video_stream_attributes_t, capabilities) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_video_stream_attributes_t, format) }, \
         { "available_formats", NULL, MAVLINK_TYPE_UINT32_T, 20, 8, offsetof(mavlink_video_stream_attributes_t, available_formats) }, \
         { "frame_size", NULL, MAVLINK_TYPE_UINT16_T, 2, 88, offsetof(mavlink_video_stream_attributes_t, frame_size) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_video_stream_attributes_t, id) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 100, 93, offsetof(mavlink_video_stream_attributes_t, uri) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_VIDEO_STREAM_ATTRIBUTES { \
    "VIDEO_STREAM_ATTRIBUTES", \
    6, \
    {  { "capabilities", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_video_stream_attributes_t, capabilities) }, \
         { "format", NULL, MAVLINK_TYPE_UINT32_T, 0, 4, offsetof(mavlink_video_stream_attributes_t, format) }, \
         { "available_formats", NULL, MAVLINK_TYPE_UINT32_T, 20, 8, offsetof(mavlink_video_stream_attributes_t, available_formats) }, \
         { "frame_size", NULL, MAVLINK_TYPE_UINT16_T, 2, 88, offsetof(mavlink_video_stream_attributes_t, frame_size) }, \
         { "id", NULL, MAVLINK_TYPE_UINT8_T, 0, 92, offsetof(mavlink_video_stream_attributes_t, id) }, \
         { "uri", NULL, MAVLINK_TYPE_CHAR, 100, 93, offsetof(mavlink_video_stream_attributes_t, uri) }, \
         } \
}
#endif

/**
 * @brief Pack a video_stream_attributes message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param id Video device ID
 * @param capabilities Union of device capabilities flags
 * @param format Video format set in FourCC
 * @param available_formats Video available formats
 * @param frame_size Video frame size in pixels, array followed by width and height
 * @param uri Video stream URI
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_attributes_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t id, uint32_t capabilities, uint32_t format, const uint32_t *available_formats, const uint16_t *frame_size, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, capabilities);
    _mav_put_uint32_t(buf, 4, format);
    _mav_put_uint8_t(buf, 92, id);
    _mav_put_uint32_t_array(buf, 8, available_formats, 20);
    _mav_put_uint16_t_array(buf, 88, frame_size, 2);
    _mav_put_char_array(buf, 93, uri, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN);
#else
    mavlink_video_stream_attributes_t packet;
    packet.capabilities = capabilities;
    packet.format = format;
    packet.id = id;
    mav_array_memcpy(packet.available_formats, available_formats, sizeof(uint32_t)*20);
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
}

/**
 * @brief Pack a video_stream_attributes message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param id Video device ID
 * @param capabilities Union of device capabilities flags
 * @param format Video format set in FourCC
 * @param available_formats Video available formats
 * @param frame_size Video frame size in pixels, array followed by width and height
 * @param uri Video stream URI
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_video_stream_attributes_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t id,uint32_t capabilities,uint32_t format,const uint32_t *available_formats,const uint16_t *frame_size,const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, capabilities);
    _mav_put_uint32_t(buf, 4, format);
    _mav_put_uint8_t(buf, 92, id);
    _mav_put_uint32_t_array(buf, 8, available_formats, 20);
    _mav_put_uint16_t_array(buf, 88, frame_size, 2);
    _mav_put_char_array(buf, 93, uri, 100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN);
#else
    mavlink_video_stream_attributes_t packet;
    packet.capabilities = capabilities;
    packet.format = format;
    packet.id = id;
    mav_array_memcpy(packet.available_formats, available_formats, sizeof(uint32_t)*20);
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
}

/**
 * @brief Encode a video_stream_attributes struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_attributes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_attributes_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_video_stream_attributes_t* video_stream_attributes)
{
    return mavlink_msg_video_stream_attributes_pack(system_id, component_id, msg, video_stream_attributes->id, video_stream_attributes->capabilities, video_stream_attributes->format, video_stream_attributes->available_formats, video_stream_attributes->frame_size, video_stream_attributes->uri);
}

/**
 * @brief Encode a video_stream_attributes struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param video_stream_attributes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_video_stream_attributes_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_video_stream_attributes_t* video_stream_attributes)
{
    return mavlink_msg_video_stream_attributes_pack_chan(system_id, component_id, chan, msg, video_stream_attributes->id, video_stream_attributes->capabilities, video_stream_attributes->format, video_stream_attributes->available_formats, video_stream_attributes->frame_size, video_stream_attributes->uri);
}

/**
 * @brief Send a video_stream_attributes message
 * @param chan MAVLink channel to send the message
 *
 * @param id Video device ID
 * @param capabilities Union of device capabilities flags
 * @param format Video format set in FourCC
 * @param available_formats Video available formats
 * @param frame_size Video frame size in pixels, array followed by width and height
 * @param uri Video stream URI
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_video_stream_attributes_send(mavlink_channel_t chan, uint8_t id, uint32_t capabilities, uint32_t format, const uint32_t *available_formats, const uint16_t *frame_size, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN];
    _mav_put_uint32_t(buf, 0, capabilities);
    _mav_put_uint32_t(buf, 4, format);
    _mav_put_uint8_t(buf, 92, id);
    _mav_put_uint32_t_array(buf, 8, available_formats, 20);
    _mav_put_uint16_t_array(buf, 88, frame_size, 2);
    _mav_put_char_array(buf, 93, uri, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES, buf, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
#else
    mavlink_video_stream_attributes_t packet;
    packet.capabilities = capabilities;
    packet.format = format;
    packet.id = id;
    mav_array_memcpy(packet.available_formats, available_formats, sizeof(uint32_t)*20);
    mav_array_memcpy(packet.frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet.uri, uri, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES, (const char *)&packet, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}

/**
 * @brief Send a video_stream_attributes message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_video_stream_attributes_send_struct(mavlink_channel_t chan, const mavlink_video_stream_attributes_t* video_stream_attributes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_video_stream_attributes_send(chan, video_stream_attributes->id, video_stream_attributes->capabilities, video_stream_attributes->format, video_stream_attributes->available_formats, video_stream_attributes->frame_size, video_stream_attributes->uri);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES, (const char *)video_stream_attributes, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}

#if MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_video_stream_attributes_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t id, uint32_t capabilities, uint32_t format, const uint32_t *available_formats, const uint16_t *frame_size, const char *uri)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, capabilities);
    _mav_put_uint32_t(buf, 4, format);
    _mav_put_uint8_t(buf, 92, id);
    _mav_put_uint32_t_array(buf, 8, available_formats, 20);
    _mav_put_uint16_t_array(buf, 88, frame_size, 2);
    _mav_put_char_array(buf, 93, uri, 100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES, buf, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
#else
    mavlink_video_stream_attributes_t *packet = (mavlink_video_stream_attributes_t *)msgbuf;
    packet->capabilities = capabilities;
    packet->format = format;
    packet->id = id;
    mav_array_memcpy(packet->available_formats, available_formats, sizeof(uint32_t)*20);
    mav_array_memcpy(packet->frame_size, frame_size, sizeof(uint16_t)*2);
    mav_array_memcpy(packet->uri, uri, sizeof(char)*100);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES, (const char *)packet, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_MIN_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_CRC);
#endif
}
#endif

#endif

// MESSAGE VIDEO_STREAM_ATTRIBUTES UNPACKING


/**
 * @brief Get field id from video_stream_attributes message
 *
 * @return Video device ID
 */
static inline uint8_t mavlink_msg_video_stream_attributes_get_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  92);
}

/**
 * @brief Get field capabilities from video_stream_attributes message
 *
 * @return Union of device capabilities flags
 */
static inline uint32_t mavlink_msg_video_stream_attributes_get_capabilities(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field format from video_stream_attributes message
 *
 * @return Video format set in FourCC
 */
static inline uint32_t mavlink_msg_video_stream_attributes_get_format(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field available_formats from video_stream_attributes message
 *
 * @return Video available formats
 */
static inline uint16_t mavlink_msg_video_stream_attributes_get_available_formats(const mavlink_message_t* msg, uint32_t *available_formats)
{
    return _MAV_RETURN_uint32_t_array(msg, available_formats, 20,  8);
}

/**
 * @brief Get field frame_size from video_stream_attributes message
 *
 * @return Video frame size in pixels, array followed by width and height
 */
static inline uint16_t mavlink_msg_video_stream_attributes_get_frame_size(const mavlink_message_t* msg, uint16_t *frame_size)
{
    return _MAV_RETURN_uint16_t_array(msg, frame_size, 2,  88);
}

/**
 * @brief Get field uri from video_stream_attributes message
 *
 * @return Video stream URI
 */
static inline uint16_t mavlink_msg_video_stream_attributes_get_uri(const mavlink_message_t* msg, char *uri)
{
    return _MAV_RETURN_char_array(msg, uri, 100,  93);
}

/**
 * @brief Decode a video_stream_attributes message into a struct
 *
 * @param msg The message to decode
 * @param video_stream_attributes C-struct to decode the message contents into
 */
static inline void mavlink_msg_video_stream_attributes_decode(const mavlink_message_t* msg, mavlink_video_stream_attributes_t* video_stream_attributes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    video_stream_attributes->capabilities = mavlink_msg_video_stream_attributes_get_capabilities(msg);
    video_stream_attributes->format = mavlink_msg_video_stream_attributes_get_format(msg);
    mavlink_msg_video_stream_attributes_get_available_formats(msg, video_stream_attributes->available_formats);
    mavlink_msg_video_stream_attributes_get_frame_size(msg, video_stream_attributes->frame_size);
    video_stream_attributes->id = mavlink_msg_video_stream_attributes_get_id(msg);
    mavlink_msg_video_stream_attributes_get_uri(msg, video_stream_attributes->uri);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN? msg->len : MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN;
        memset(video_stream_attributes, 0, MAVLINK_MSG_ID_VIDEO_STREAM_ATTRIBUTES_LEN);
    memcpy(video_stream_attributes, _MAV_PAYLOAD(msg), len);
#endif
}
