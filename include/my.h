/*
** my.h for include in /home/admin/Documents/Programming/russian-roulette/include
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Sat May 21 11:18:24 2016 Thomas Murgia
** Last update Sat May 21 11:18:24 2016 Thomas Murgia
*/

#ifndef   MY_H_
#define   MY_H_

#include  <stdint.h>

uint8_t   my_rand(void);
void      my_puts(const char *str);
int       my_retstr(const char *str, const int error);

#endif    /* !MY_H_ */
