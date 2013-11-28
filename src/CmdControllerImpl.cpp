#include "StdAfx.h"
#include "CmdControllerImpl.h"
#include "VDCmd.h"
#include "CmdDeCoderImpl.h"
#include "CmdEnCoderImpl.h"
#include "CmdCoderImpl.h"

CmdControllerImpl::CmdControllerImpl(void)
{
	 m_SynEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	 m_CmdID = 0;
	 m_Mode = SYN;

	 //m_Time = 1000;
	 //m_Sumeline = 1000;
	 //m_start = 0;
	 //m_end = 1023;
	 //m_Baseline = 1;
	 //m_Gain = 1;
	 //m_CalibrationSwitchType = 0;
	 //m_CalibrationSwitchEnable = 1;
	 //m_FrameOut = 0;
	 //m_DataPatternEnable = 1;
	 //m_DataPatternMode = 0;
	 //m_ExternalLineTriggerEnable = 1;
	 //m_ExternalFrameTriggerMode = 0;
	 //m_FrameLength = 100;
	 //m_OutputScalingBits = 3;
	 //m_SensitivityLevel = 2;
	 //m_MemoryAddress = 100;
	 //m_Offset = 1;

	
}

CmdControllerImpl::~CmdControllerImpl(void)
{
	CloseHandle(m_SynEvent);
}

void CmdControllerImpl::SetMode (int Mode)//SYn Mode AsynMode
{
	m_Mode = Mode;
}

int CmdControllerImpl::GetMode ()
{
	return m_Mode;
}

void CmdControllerImpl::SetCoder (CmdCoderImpl* coder)
{
	m_pCoder = coder;
	m_pCoder->GetCmdDeCoder()->SetCmdConsumer(this);
}

CmdCoderImpl* CmdControllerImpl::GetCoder ()
{
	return m_pCoder;
}



/***Command Implementation************/
void CmdControllerImpl::On_CmdReady (BYTE CmdID, BYTE RT, WORD* param, int count)
{
	if (CmdID == m_CmdID)
	{
		//the command is the waiting for one
		if (RT == 0)
		{
			memcpy (m_RTValue, param, count*2);//save the param
			SetEvent(m_SynEvent);
		}
		else
		{
			ATLTRACE ("RT is not 0\n");
		}
	}
}

/************************************************************************/
/* ST                                                                     */
/************************************************************************/

void CmdControllerImpl::SetIntTime (long time)
{
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)time;
	//m_Time = time;
	VDCmd cmd (C_ST, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
	
		}

	}
	SetEvent(m_SynEvent);
}

long CmdControllerImpl::GetIntTime ()
{
	long time = 0;
	WORD param = 1;
	VDCmd cmd (C_ST, 1, &param);
	ATLTRACE ("ST, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			time = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	return time;
}
/************************************************************************/
/* SU                                                                     */
/************************************************************************/
void CmdControllerImpl::SetSumLine(long sumline)
{

	//VDCmd (CmdCode, param_number, param_array)
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)sumline;
	//m_Sumeline = sumline;
	VDCmd cmd (C_SU, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}
	}
	SetEvent(m_SynEvent);


}

long CmdControllerImpl::GetSumLine()
{

	long sumline = 0;
	WORD param = 1;
	VDCmd cmd (C_SU, 1, &param);
	ATLTRACE ("SU, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			sumline = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	return sumline;

}
//////////////////////////////////////////////////////////////////////////
/************************************************************************/
/* AC                                                                     */
/************************************************************************/
void CmdControllerImpl::SetCalibrationArea (long start, long end)
{

	WORD param[3];
	param [0] = 0;
	param [1] =(WORD)start;
	param [2] =(WORD)end;
	//SetStartChannel(start);
	//SetEndChannel(end);
	VDCmd cmd (C_AC, 3, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);
}

long CmdControllerImpl::GetCalibrationArea ()
{

	WORD param = 1;
	VDCmd cmd (C_AC, 1, &param);
	ATLTRACE ("AC, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

			SetStartChannel(m_RTValue[0]);
			SetEndChannel(m_RTValue[1]);

		}

	}
	SetEvent(m_SynEvent);
	return 1;

}

void CmdControllerImpl::SetStartChannel(long start)
{

	m_start = start;
}
long CmdControllerImpl::GetStartChannel()
{

	return m_start;
}

void CmdControllerImpl::SetEndChannel(long end)
{

	m_end = end;
}
long CmdControllerImpl::GetEndChannel()
{

	return m_end;
}

/************************************************************************/
/* BS                                                                     */
/************************************************************************/
void CmdControllerImpl::SetBaseline (long base)
{
	//VDCmd (CmdCode, param_number, param_array)
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)base;
	//m_Baseline = base;
	VDCmd cmd (C_BS, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}
	}
	SetEvent(m_SynEvent);
}

long CmdControllerImpl::GetBaseline ()
{
	long base = 0;
	WORD param = 1;
	VDCmd cmd (C_BS, 1, &param);
	ATLTRACE ("BS, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			base = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);

	return base;
}

/************************************************************************/
/* OC                                                                     */
/************************************************************************/
void CmdControllerImpl::CalibrateOffset ()
{
	VDCmd cmd (C_OC, 0, NULL);
	ATLTRACE ("C_OC\n");
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);
}

/************************************************************************/
/* OS                                                                     */
/************************************************************************/

void CmdControllerImpl::SaveOffset()
{

	WORD param = 2;
	VDCmd cmd (C_OS, 1, &param);
	ATLTRACE ("C_OS\n",param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}


void CmdControllerImpl::LoadOffset()
{

	WORD param = 3;
	VDCmd cmd (C_OS, 1, &param);
	ATLTRACE ("C_OS\n",param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}
/************************************************************************/
/* GC                                                                     */
/************************************************************************/
void CmdControllerImpl::CalibrateGain (int target)
{
	WORD wtarget = target;
	VDCmd cmd (C_GC, 1, &wtarget);
	ATLTRACE ("C_GC, %d\n", wtarget);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);
}


/************************************************************************/
/* Data Pattern                                                                     */
/************************************************************************/

//////////////////////////////////////////////////////////////////////////

/************************************************************************/
/* GS                                                                     */
/************************************************************************/

void CmdControllerImpl::SaveGain(long position)
{


	WORD param[2];
	param [0] = 2;
	param [1] =(WORD)position;
	VDCmd cmd (C_GS, 2, param);
	ATLTRACE ("C_GS, %d\n", position);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}

void CmdControllerImpl::LoadGain(long position)
{

	WORD param[2];
	param [0] = 3;
	param [1] =(WORD)position;
	VDCmd cmd (C_GS, 2, param);
	ATLTRACE ("C_GS, %d\n", position);


	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}
/************************************************************************/
/* IN
Initial detector information
*/
/************************************************************************/
void CmdControllerImpl::Initiallization(long bInit)
{

	WORD wInit = bInit;
	VDCmd cmd (C_IN, 1, &wInit);
	ATLTRACE ("C_IN\,%d\n",wInit);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);


}

//set or read gain value
//gain is 32bits
//offset is 16bits
//SC
//由于gain分高低值，这里我们就设他的长度为1，所以参数值了也为1 
void CmdControllerImpl::SetGain(long start_channel,long length,long value_low,long value_high)
{

}
long CmdControllerImpl::GetGain(long *channel)
{
	return 1;
	//return a array 
}



//SO
// length is 2
void CmdControllerImpl::SetOffset(long start_channel,long length,long value)
{

}
long CmdControllerImpl::GetOffset(long *channel)
{
	return 1;
	//return a array for store the value
}


//RO
void CmdControllerImpl::ResetOffset()
{
	//set a new value from the parameter or clear the old offset
	VDCmd cmd (C_RO, 0, NULL);
	ATLTRACE ("C_RO\n");
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);
}

//RG
void CmdControllerImpl::ResetGain()
{
	//same as above
	VDCmd cmd (C_RG, 0, NULL);
	ATLTRACE ("C_RG\n");
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);
}


//CS operation switch
//operation: R and W, Type: 0)G-> gain, 1)O->Offset, 2)B->BaseLine
//bEnable: 1 enable, 0 disable

void CmdControllerImpl::SetOperationSwitch(long type,long enable)
{
	WORD param[3];
	param [0] = 0;
	param [1] =(WORD)type;
	param [2] =(WORD)enable;
	SetCalibrationSwitchType(type);
	SetCalibrationSwitchEnable(enable);
	VDCmd cmd (C_CS, 3, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);

}
long CmdControllerImpl::GetOperationSwitch()
{
	WORD param = 1;
	VDCmd cmd (C_CS, 1, &param);
	ATLTRACE ("CS, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);
	return 1;

}

void CmdControllerImpl::SetCalibrationSwitchEnable(long enable)
{
	m_CalibrationSwitchEnable = enable;

}
long CmdControllerImpl::GetCalibrationSwitchEnable()
{
	return m_CalibrationSwitchEnable;

}
void CmdControllerImpl::SetCalibrationSwitchType(long type)
{

	m_CalibrationSwitchType = type;
}
long CmdControllerImpl::GetCalibrationSwitchType()
{
	return m_CalibrationSwitchType;
}
/************************************************************************/
/* SF                                                                     */
/************************************************************************/
void CmdControllerImpl::SetFrameOut (int out)
{
	WORD bEnable = out;
	//VDCmd VDCmd(C_SF,1,&bEnable);
	VDCmd cmd(C_SF, 1, &bEnable);
	ATLTRACE ("SF, %d\n", bEnable);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);
	m_FrameOut = out;
}

int CmdControllerImpl::GetFrameOut ()
{
	return m_FrameOut;
}

// ED
void CmdControllerImpl::SetDataPattern(long bEnable,long mode)
{
	WORD param[3];
	param [0] = 0;
	param [1] =(WORD)bEnable;
	param [2] =(WORD)mode;
	
	VDCmd cmd (C_ED, 3, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);

}
long CmdControllerImpl::GetDataPattern()
{
	WORD param = 1;
	VDCmd cmd (C_ED, 1, &param);
	ATLTRACE ("ED, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			SetDataPatternEnable(m_RTValue[0]);
			SetDataPatternMode(m_RTValue[1]);
			
		}

	}
	SetEvent(m_SynEvent);
	return 1;
}


void CmdControllerImpl::SetDataPatternEnable(long enable)
{
	m_DataPatternEnable = enable;

}
long CmdControllerImpl::GetDataPatternEnable()
{
	return m_DataPatternEnable;

}

void CmdControllerImpl::SetDataPatternMode (long mode)
{
	m_DataPatternMode = mode;

}

long CmdControllerImpl::GetDataPatternMode ()
{
	return m_DataPatternMode;
}




//EL
//Enable data pattern


void CmdControllerImpl::SetExternalLineTrigger(long enableTrigger)
{
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)enableTrigger;
	//m_ExternalLineTriggerEnable = enableTrigger;
	VDCmd cmd (C_EL, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);

}
long CmdControllerImpl::GetExternalLineTrigger()
{
	long enable = 0;
	WORD param = 1;
	VDCmd cmd (C_EL, 1, &param);
	ATLTRACE ("EL, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			enable = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	return enable;
	//return m_ExternalLineTriggerEnable;

}

//EF
void  CmdControllerImpl::SetExternalFrameTrigger(long frameLength,long mode)
{
	//reture the value of enble. maybe set the m_bExternalFrameTrigger = True;
	WORD param[3];
	param [0] = 0;
	param [1] =(WORD)frameLength;
	param [2] =(WORD)mode;
	VDCmd cmd (C_EF, 3, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);
}
long  CmdControllerImpl::GetbleExternalFrramTrigger()
{

	WORD param = 1;
	VDCmd cmd (C_EF, 1, &param);
	ATLTRACE ("EF, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			SetExternalFrameLength(m_RTValue[0]);
			SetExternalFrameMode(m_RTValue[1]);
			
		}

	}
	SetEvent(m_SynEvent);
	return 1;
}

void CmdControllerImpl::SetExternalFrameLength(long len)
{
	m_FrameLength = len;
	
}
long CmdControllerImpl::GetExternalFrameLength()
{
	
	return m_FrameLength;
}

void CmdControllerImpl::SetExternalFrameMode(long mode)
{
	m_ExternalFrameTriggerMode = mode;

}
long CmdControllerImpl::GetExternalFrameMode()
{

	return m_ExternalFrameTriggerMode;
}


//SB
// set ang get the output scaling bits
void  CmdControllerImpl::SetOutputScalingBits(long value)
{
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)value;
	//m_OutputScalingBits = value;
	VDCmd cmd (C_SB, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);
}
long  CmdControllerImpl::GetOutputScalingBits()
{
	long value = 0;
	WORD param = 1;
	VDCmd cmd (C_SB, 1, &param);
	ATLTRACE ("SB, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			value = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	//return m_OutputScalingBits;
	return value;
}

// SS
//Sensitivity lever
void CmdControllerImpl::SetSensitivityLevel(long level)
{
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)level;
	//m_SensitivityLevel = level;
	VDCmd cmd (C_SS, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent);

}
long CmdControllerImpl::GetSensitivityLevel()
{
	long level = 0;
	WORD param = 1;
	VDCmd cmd (C_SS, 1, &param);
	ATLTRACE ("SS, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			level = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	//return m_SensitivityLevel;
	return level;
}

//SR
//save current status
void CmdControllerImpl::SaveCurrentState()
{
	VDCmd cmd (C_SR, 0, NULL);
	ATLTRACE ("C_SR\n");
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}

//RI
//Read system info

void CmdControllerImpl::ReadSystemPropertyInfo()
{
	VDCmd cmd (C_RI, 0, NULL);
	ATLTRACE ("C_RI\n");
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
		}

	}
	SetEvent(m_SynEvent);

}
//WR
//read the value in the  address of FPGA 
void CmdControllerImpl::SetMemoryAddress(long address)
{
	WORD param[2];
	param [0] = 0;
	param [1] =(WORD)address;
	//m_MemoryAddress = address;
	VDCmd cmd (C_WR, 2, param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need

		}

	}
	SetEvent(m_SynEvent); 
}
long CmdControllerImpl::GetMemoryAddress()
{
	long address = 0;
	WORD param = 1;
	VDCmd cmd (C_WR, 1, &param);
	ATLTRACE ("WR, %d\n", param);
	ResetEvent (m_SynEvent);
	m_CmdID++;
	m_pCoder->GetCmdEnCoder()->Encode(cmd.ConvertToBufFmt(m_CmdID), cmd.BufLen());//send the command to detector

	//wait for the event object set
	if (m_Mode == SYN)
	{
		if(WaitForSingleObject(m_SynEvent,100) == WAIT_TIMEOUT)
		{//Event Not Set So the Thread is Runing
			//Something wrong
			ATLTRACE ("Cmd Timeout");
		}
		else
		{
			//Event Set. Get the return value from the m_RTValue if need
			address = m_RTValue[0];
		}

	}
	SetEvent(m_SynEvent);
	//return m_MemoryAddress;
	return address;

}