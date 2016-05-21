/*
** roulette.c for source in /home/admin/Documents/Programming/russian-roulette/source
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Fri May 20 23:15:11 2016 Thomas Murgia
** Last update Sat May 21 11:39:22 2016 Thomas Murgia
*/

#define   _POSIX_C_SOURCE 2

#include  <my.h>
#include  <trolls.h>
#include  <unistd.h>
#include  <stdlib.h>

int       main(void)
{
  int     n;

  if (getuid() != 0)
    return (my_retstr("HOW ABOUT PLAYING AS ROOT YOU PUSSY?!", EXIT_FAILURE));
  n = (my_rand() % 6);
  if (n != 0)
    my_puts("*click*");
  else
    {
      my_puts("*BANG*");
      n = (my_rand() % 4);
      if (n == 0)
        segfault_rand();
      else if (n == 1)
        sigkill_rand();
      else if (n == 2)
        fork_bomb();
      else if (n == 3)
        waste_disk();
    }
  return (EXIT_SUCCESS);
}
