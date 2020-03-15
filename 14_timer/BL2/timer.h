#ifndef _TIMER_H_
#define _TIMER_H_

void timer_request(void);
void pwm_stopall(void);
void timer_request(void);
void irq_handler(void);
void timer_init(unsigned long utimer,unsigned long uprescaler,unsigned long udivider,unsigned long utcntb,unsigned long utcmpb);
void irs_timer();

#endif //_TIMER_H_