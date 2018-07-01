#include <stdint.h>

#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "M4MemMap.h"

#include "CAN.h"
#include "CAN_Cfg.h"


int main(void)
{
    uint8_t Data[4] = {
                            0x12,
                            0x11,
                            0xAB,
                            0x10
                       };
    uint16_t *DataPtr;

    uint16_t DataOut[4];
    uint16_t *DataPtrOut;
    DataPtrOut = &DataOut[0];

    DataPtr = &Data[0];

    GPIO_Init();
    CAN_Init();

    //EN_INT(39);
    CAN_TxData(0, DataPtr, 0);
    CAN_RxData(0, DataPtrOut, 0);

    while(1)
    {
        //CAN_TxData(0, DataPtr, 0);

        //CAN_RxData(0, DataPtrOut, 0);
        //CAN_GetStatus(0, 1);
    }
    return 0;
}

void ISR(void)
{
    GPIO_Write(2, 0xff);
}
