/******************************************************************************
| includes
|-------------------------------------------------------------------------------------------*/
#include "ysPWM.h"

/******************************************************************************
| variables
|--------------------------------------------------------------------------------------------*/

/******************************************************************************
| functions
|-------------------------------------------------------------------------------------------*/
void InitPWM()
{
/* Load Side */

	// ----------------EPwm4---------------------
	EPwm4Regs.TBPHS.half.TBPHS = 0;  // ʱ�����ڼĴ���
	EPwm4Regs.TBCTR = 0;  // ʱ�������Ĵ�������
	EPwm4Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm4Regs.TBCTL.bit.CLKDIV = prediv;  // ʱ��Ԥ��Ƶ
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = 0;
	EPwm4Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;
	EPwm4Regs.TBCTL.bit.PHSEN = TB_ENABLE;

	EPwm4Regs.CMPA.half.CMPA = halfperiod / 2; // duty_cycle = 0.5
	EPwm4Regs.CMPB = halfperiod / 2;
	EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // TBCTR = 0ʱװ��
	EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

	EPwm4Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm4Regs.AQCTLA.bit.CAD = AQ_CLEAR;

	EPwm4Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm4Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A����ת��B��ת
	EPwm4Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm4Regs.DBRED = DT; // Deadzone
	EPwm4Regs.DBFED = DT;

	EPwm4Regs.ETSEL.bit.INTEN = 1;  // ʹ��EPwm1�ж�
	EPwm4Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;  // TBCTR = 0�����ж�
	EPwm4Regs.ETPS.bit.INTPRD = ET_1ST;  // ÿ���ж϶���Ӧ

	// ----------------EPwm5---------------------
	EPwm5Regs.TBPHS.half.TBPHS = 0;  // ʱ�����ڼĴ���
	EPwm5Regs.TBCTR = 0;  // ʱ�������Ĵ�������
	EPwm5Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm5Regs.TBCTL.bit.CLKDIV = prediv;  // ʱ��Ԥ��Ƶ
	EPwm5Regs.TBCTL.bit.HSPCLKDIV = 0;
	EPwm5Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm5Regs.TBCTL.bit.PHSEN = TB_ENABLE;

	EPwm5Regs.CMPA.half.CMPA = halfperiod / 2; // duty_cycle = 0.5
	EPwm5Regs.CMPB = halfperiod / 2;
	EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // TBCTR = 0ʱװ��
	EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;  // TBCTR = 0ʱװ��

	EPwm5Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm5Regs.AQCTLA.bit.CAD = AQ_CLEAR;

	EPwm5Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm5Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A����ת��B��ת
	EPwm5Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm5Regs.DBRED = DT; // Deadzone
	EPwm5Regs.DBFED = DT;

	// ----------------EPwm6---------------------
	EPwm6Regs.TBPHS.half.TBPHS = 0;  // ʱ�����ڼĴ���
	EPwm6Regs.TBCTR = 0;  // ʱ�������Ĵ�������
	EPwm6Regs.TBCTL.bit.PHSDIR = TB_UP;
	EPwm6Regs.TBCTL.bit.CLKDIV = prediv;  // ʱ��Ԥ��Ƶ
	EPwm6Regs.TBCTL.bit.HSPCLKDIV = 0;
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;
	EPwm6Regs.TBCTL.bit.PHSEN = TB_ENABLE;

	EPwm6Regs.CMPA.half.CMPA = halfperiod / 2; // duty_cycle = 0.5
	EPwm6Regs.CMPB = halfperiod / 2;
	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;  // TBCTR = 0ʱװ��
	EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;  // TBCTR = 0ʱװ��

	EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;
	EPwm6Regs.AQCTLA.bit.CAD = AQ_CLEAR;

	EPwm6Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm6Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;  // A����ת��B��ת
	EPwm6Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm6Regs.DBRED = DT; // Deadzone
	EPwm6Regs.DBFED = DT;

	// ----------------��ʼ��ʱ---------------------
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN;

	EPwm4Regs.TBPRD = halfperiod;
	EPwm5Regs.TBPRD = halfperiod;
	EPwm6Regs.TBPRD = halfperiod;
}
