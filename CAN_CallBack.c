#include <stdint.h>
#include "CAN_CallBack.h"
#include "CAN.h"
#include "CAN_Cfg.h"

void CAN_TxDone(void)
{
    uint8_t LEDTx;
    LEDTx = 1;
    if(CAN_SelfTest == CAN_SelfTestEnaled)
    {
        CAN_SelfTest = CAN_SelfTestTxDone;
    }
    else
    {
        /* Write the call back you want after transmission is done */
    }
}

void CAN_RxDone(void)
{
    uint8_t LEDRx;
    LEDRx = 1;
    if(CAN_SelfTest == CAN_SelfTestTxDone)
    {
        CAN_SelfTest = CAN_SelfTestRxDone;
    }
    else
    {
        /* Write the call back you want after reception is done */
    }
}

void CAN_SelfTestDone(void)
{
    if(DataRxSelfTestPtr == 0xffff)
    {
        /* 0xffff means Yes I am ready */
        CAN_SelfTest = CAN_SelfTestOK;
    }
    else
    {
        CAN_SelfTest = CAN_SelfTestNOK;
    }
}
