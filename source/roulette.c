/*
** roulette.c for source in /home/admin/Documents/Programming/russian-roulette/source
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Fri May 20 23:15:11 2016 Thomas Murgia
** Last update Sat May 21 09:30:46 2016 Thomas Murgia
*/

#define   _POSIX_C_SOURCE 2

#include  <stdint.h>
#include  <signal.h>
#include  <unistd.h>
#include  <stdlib.h>
#include  <fcntl.h>

uint8_t   my_rand(void)
{
  uint8_t value;
  int     fd;

  fd = open("/dev/urandom", O_RDONLY);
  read(fd, &value, 1);
  close(fd);
  return (value);
}

int       randpid(void)
{
  int     pid;
  int     pid_max;
  int     fd;

  pid = my_rand();
  fd = open("/proc/sys/kernel/pid_max", O_RDONLY);
  read(fd, &pid_max, sizeof(int));
  close(fd);
  return (pid % pid_max);
}

void      my_puts(const char *str)
{
  int     i;

  i = 0;
  while (str[i] != '\0')
    {
      write(1, &(str[i]), 1);
      ++i;
    }
  i = 10;
  write(1, &i, 1);
}

int       main(void)
{
  int     n;

  if (getuid())
    {
      my_puts("HOW ABOUT PLAYING AS ROOT YOU PUSSY?");
      return (EXIT_FAILURE);
    }
  n = (my_rand() % 6);
  if (n != 0)
    my_puts("*click*");
  else
    {
      my_puts("*BOOM*");
      n = (my_rand() % 3);
      if (n == 0)
        {
          my_puts("Segfaulting a random PID!");
          kill(randpid(), SIGSEGV);
        }
      else if (n == 0)
        {
          my_puts("SIGKILLing a random PID!");
          kill(randpid(), SIGKILL);
        }
      else if (n == 0)
        {
          my_puts("Allocating 512MB of RAM!");
          n = 0;
          if (fork() == 0)
          {
            while (n != (1024 * 1024 * 512))
              {
                malloc(1);
                ++n;
              }
          }
        }
    }
  return (EXIT_SUCCESS);
}
