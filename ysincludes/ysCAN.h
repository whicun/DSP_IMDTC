/******************************************************************************
| includes
|----------------------------------------------------------------------------*/
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

/******************************************************************************
| defines
|----------------------------------------------------------------------------*/

/******************************************************************************
| variables
|----------------------------------------------------------------------------*/

/******************************************************************************
| local functions prototypes
|----------------------------------------------------------------------------*/

/******************************************************************************
| exported functions
|----------------------------------------------------------------------------*/
extern void InitCANB();
extern void mailbox_read(int16 MBXnbr, Uint32* MDL32, Uint32* MDH32, Uint32* MBID);
