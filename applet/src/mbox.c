/*
 *  mbox.c
 * 
 */

#include "mbox.h"

#include "md380.h"

extern OS_EVENT *mbox_radio ; //= (OS_EVENT *)0x20017468 ;
extern OS_EVENT *mbox_beep  ; //= (OS_EVENT *)0x20017390 ;

#if defined(FW_D13_020)

uint8_t beep_msg ; // it cannot live on the stack.

void mb_send_beep( int beep )
{
    beep_msg = beep ;
    md380_OSMboxPost(mbox_beep, &beep_msg);    
}
#else
void mb_send_beep( int beep )
{
    // dummy. no implementation.
}
#endif
