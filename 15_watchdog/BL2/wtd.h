#ifndef _WTD_H_
#define _WTD_H_

void wtd_test();
void isr_wtd(void);
void wtd_operate(unsigned long uenreset, unsigned long uenint, unsigned long uselectclk, unsigned long uenwtd, unsigned long uprescaler,unsigned long uwtdat, unsigned long uwtcnt);

#endif //_WTD_H_