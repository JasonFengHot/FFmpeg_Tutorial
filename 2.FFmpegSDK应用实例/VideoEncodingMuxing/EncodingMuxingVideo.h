#ifndef _ENCODING_MUXING_VIDEO_H_
#define _ENCODING_MUXING_VIDEO_H_

#include "common.h"
#include "Stream.h"

typedef struct _VideoEncodingParam
{
	int frameWidth;
	int frameHeight;
	int bitRate;
	AVRational timeBase;
	int gopSize;
	int maxBFrames;
	int mbDecision;
} VideoEncodingParam;

typedef struct _IOParam IOParam;
void Open_video(AVFormatContext *oc, AVCodec *codec, OutputStream *ost, AVDictionary *opt_arg, IOParam &io);

int Write_video_frame(AVFormatContext *oc, OutputStream *ost);

/*************************************************
	Function:		Add_video_stream
	Description:	向打开文件中添加一路视频流
	Calls:			无
	Called By:		main
	Input:			(in/out)videoStream : 待添加的视频流
					(in/out)oc : 视频文件句柄
					(in/out)codec：编码器实例
					(in)codec_id：编码器ID
	Output:			无
	Return:			函数执行错误码
*************************************************/
int Add_video_stream(AVStream **videoStream, AVFormatContext *oc, AVCodec **codec, enum AVCodecID codec_id);

/*************************************************
	Function:		Set_video_stream
	Description:	设置视频码流的参数
	Calls:			无
	Called By:		main
	Input:			(in/out)codecCtx : 视频流的AVCodecContext
					(int)encParam : 视频编码参数
	Output:			无
	Return:			无
*************************************************/
void Set_video_stream(AVStream **videoStream, const VideoEncodingParam &encParam);

int Open_video_stream();

#endif