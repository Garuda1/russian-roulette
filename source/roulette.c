/*
 * roulette.c
 *
 * Licensed under GNU GPL v3
 * By Thomas Murgia <garuda1@protonmail.com>
 *
 */

#define _POSIX_C_SOURCE 200809L

#include <unixlib-io.h>
#include <unixlib.h>
#include <roulette.h>
#include <unistd.h>

int main(void)
{
  int n;

  if (getuid() != 0)
    return (my_retstr(FAILURE, ERR_NOTROOT));

  n = my_rand();
  if (n < 0)
    n *= -1;
  n %= 6;

  if (n != 0)
    my_puts("*click*");
  else
  {
      my_puts("*BANG*");
      switch (n % 4)
      {
        case 0:
          segfault_rand();
          break;
        case 1:
          sigkill_rand();
          break;
        case 2:
          fork_bomb();
          break;
        case 3:
          waste_disk();
          break;
      }
  }
  return (SUCCESS);
}
