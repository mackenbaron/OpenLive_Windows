#pragma once

#include "../../../SDK/include/IAgoraRtcEngine.h"
#include "AGEngineEventHandler.h"

#define AVC_VER _T("V1.7.0(Build229, 10/12/2016, SDK:1.7.0)")

// #define ENABLE_CODEC	1

using namespace agora::rtc;

// ������λ
#define AG_ENGFLAG_ENNETTEST	0x00000001
#define AG_ENGFLAG_ECHOTEST		0x00000002
#define AG_ENGFLAG_SPKPHTEST	0x00000004
#define AG_ENGFLAG_MICPHTEST	0x00000008
#define AG_ENGFLAG_VIDEOTEST	0x00000010


#define AG_CODEC_E264	0x00000000
#define AG_CODEC_EVP	0x00000001
#define AG_CODEC_VP8	0x00000002

#define APP_ID _T("")

class CAgoraObject
{
public:
	~CAgoraObject(void);

	void SetNetworkTestFlag(BOOL bEnable);
	BOOL GetNetworkTestFlag();

	void SetEchoTestFlag(BOOL bEnable);
	BOOL GetEchoTestFlag();

	void SetSpeakerphoneTestFlag(BOOL bEnable);
	BOOL GetSpeakerphoneTestFlag();

	void SetMicrophoneTestFlag(BOOL bEnable);
	BOOL GetMicrophoneTestFlag();

	void SetVideoTestFlag(BOOL bEnable);
	BOOL GetVideoTestFlag();

	void SetMsgHandlerWnd(HWND hWnd);
	HWND GetMsgHandlerWnd();

	BOOL SetLogFilePath(LPCTSTR lpLogPath = NULL);

	BOOL JoinChannel(LPCTSTR lpChannelName, UINT nUID = 0);
	BOOL LeaveCahnnel();
	CString GetChanelName();
	CString GetCallID();
	CString GetVendorKey() { return m_strVendorKey; };

	void SetSelfUID(UINT nUID) { m_nSelfUID = nUID; };
	UINT GetSelfUID() { return m_nSelfUID; };

	BOOL EnableVideo(BOOL bEnable = TRUE);
	BOOL IsVideoEnabled();


	BOOL MuteLocalAudio(BOOL bMuted = TRUE);
	BOOL IsLocalAudioMuted();

	BOOL MuteLocalVideo(BOOL bMuted = TRUE);
	BOOL IsLocalVideoMuted();

	BOOL SetClientRole(int nIndex);
	int GetClientRole() { return m_nRoleIndex; };
	 
	BOOL EnableAudioRecording(BOOL bEnable, LPCTSTR lpFilePath);

	BOOL EnableDauleStream(BOOL bEnable);

	BOOL EnableNetworkTest(BOOL bEnable);

	BOOL SetRemoteStreamType(UINT nUID, REMOTE_VIDEO_STREAM_TYPE nType);

	BOOL LocalVideoPreview(HWND hVideoWnd, BOOL bPreviewOn = TRUE);

	BOOL SetLogFilter(LOG_FILTER_TYPE logFilterType, LPCTSTR lpLogPath);

	static IRtcEngine *GetEngine();
	
	static CString GetSDKVersion();

protected:
	CAgoraObject(void);

private:
	DWORD	m_dwEngineFlag;
	static  CAgoraObject	*m_lpAgoraObject;
	static	IRtcEngine		*m_lpAgoraEngine;
	static	CString			m_strVendorKey;
	
	UINT		m_nSelfUID;
	CString		m_strChannelName;
	BOOL		m_bVideoEnable;

	BOOL		m_bLocalAudioMuted;
	BOOL		m_bLocalVideoMuted;
	BOOL		m_bScreenCapture;

	int			m_nCodecType;
	int			m_nRoleIndex;

public:
	static CAgoraObject *GetAgoraObject(LPCTSTR lpVendorKey = NULL);
	static void CloseAgoraObject();

	static CAGEngineEventHandler m_EngineEventHandler;
};
