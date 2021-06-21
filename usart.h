/*
 * IncFile1.h
 *
 * Created: 22-11-2017 14:48:14
 *  Author: hiteshpatel
 */ 


#ifndef USART_H_
#define USART_H_

void usart_init();
void usart_send_char(unsigned char);
void usart_send_string(unsigned char *);
unsigned char usart_receive();



#endif /* INCFILE1_H_ */