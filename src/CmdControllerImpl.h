#pragma once
class CmdCoderImpl;
#include "ICmdConsumer.h"

class CmdControllerImpl: public ICmdConsumer
{
	//Implement the command 
	//translate the command into byte array
	//pass the array to encoder, the encoder append the cmd_id
public:
	CmdControllerImpl(void);
public:
	~CmdControllerImpl(void);
public:
	void SetMode (int Mode);//SYn Mode AsynMode
	int GetMode ();

	void SetCoder (CmdCoderImpl* coder);
	CmdCoderImpl* GetCoder ();

public:

	//ST
	//Integration time
	void SetIntTime (long time);
	long GetIntTime ();

	//SU
	//summation of lines
	void SetSumLine(long sumline); 
	long GetSumLine();

	//AC
	//Calibration  area
	void SetCalibrationArea (long start, long end);
	long GetCalibrationArea ();

	void SetStartChannel(long start);
	long GetStartChannel();

	void SetEndChannel(long end);
	long GetEndChannel();

	//BS
	//Baseline value
	void SetBaseline (long base);
	long GetBaseline ();

	//OC
	//init offset calibration
	void CalibrateOffset (); 

	//OS 
	// save of load offset load
	void SaveOffset();
	void LoadOffset(); 

	//GC
	//Init gain calibration
	void CalibrateGain (int target);


	//GS
	//Save or load gain value 
	//example: [GS,S,2], ///to save current gain value to set number 2
	void SaveGain(long position);// position [0,4]
	void LoadGain(long position);
	//IN
	//Initial detector information
	//long Initiallization(long value);
	void Initiallization(long bInit);

	//set or read gain value
	//gain is 32bits
	//offset is 16bits
	//SC
	//由于gain分高低值，这里我们就设他的长度为1，所以参数值了也为1 
	void SetGain(long start_channel,long length,long value_low,long value_high);
	long GetGain(long *channel);

	//SO
	// length is 2
	void SetOffset(long start_channel,long length,long value1);
	long GetOffset(long *channel);

	//RO
	void ResetOffset();

	//RG
	void ResetGain();

	//CS operation switch
	//operation: R and W, Type: 0)G-> gain, 1)O->Offset, 2)B->BaseLine
	//bEnable: 1 enable, 0 disable

	void SetOperationSwitch(long type,long enable);
	long GetOperationSwitch();

	void SetCalibrationSwitchType(long type);
	long GetCalibrationSwitchType();

	void SetCalibrationSwitchEnable(long enable);
	long GetCalibrationSwitchEnable();


	//SF
	//start or stop output
	void SetFrameOut (int out);
	int GetFrameOut ();




	/************************************************************************/
	/* 
	When send command,
	Synchronization mode:
	Cmd Controller need to wait until get the cmd return
	Asynchronism mode:
	Cmd Controller do not wait for return.                                                                     */
	/************************************************************************/
	

	//ED

	void SetDataPattern(long bEnable,long mode);
	long GetDataPattern();

	void SetDataPatternMode (long mode);
	long  GetDataPatternMode ();

	void SetDataPatternEnable(long enable);
	long GetDataPatternEnable();
	//////////////////////////////////////////////////////////////////////////


	

	

	//EL
	//Enable data pattern
	
	void SetExternalLineTrigger(long enableTrigger);
	long GetExternalLineTrigger();

	//EF
	//
	
	void  SetExternalFrameTrigger(long frameLength,long mode);
	long  GetbleExternalFrramTrigger();

	void SetExternalFrameLength(long len);
	long GetExternalFrameLength();

	void SetExternalFrameMode(long mode);
	long GetExternalFrameMode();

	//SB
	// set ang get the output scaling bits
	void SetOutputScalingBits(long value);
	long GetOutputScalingBits();


	// SS
	//Sensitivity lever
	void SetSensitivityLevel(long level);
	long GetSensitivityLevel();

	//SR
	//save current status
	void SaveCurrentState();

	//RI
	//Read system info

	void ReadSystemPropertyInfo();

	//WR
	//read the value in the  address of FPGA 
	void SetMemoryAddress(long address);
	long GetMemoryAddress();

	void On_CmdReady (BYTE CmdID, BYTE RT, WORD* param, int count);


private:
	CmdCoderImpl*	m_pCoder;
	int m_Mode;
	BYTE m_buf[CMD_BUF_SIZE];
	WORD m_RTValue [CMD_BUF_SIZE];
	HANDLE			m_SynEvent;
	BYTE m_CmdID;

   // long m_Time;
	//long m_Sumeline;
	long m_start;
	long m_end;
	//long m_Baseline;
	long m_Gain;

	long m_CalibrationSwitchType;
	long m_CalibrationSwitchEnable;

	long m_FrameOut;

	long m_DataPatternEnable;
	long m_DataPatternMode;

	//long m_ExternalLineTriggerEnable;

	long m_ExternalFrameTriggerMode;
	long m_FrameLength;
	//long m_OutputScalingBits;
	//long m_SensitivityLevel;
	//long m_MemoryAddress;
	long m_Offset;

	
	//long m_enableTrigger;

	//long m_DataPatternMode;

	
	

	
	

	


	 
};
