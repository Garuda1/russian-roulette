/*
** randpid.c for source in /home/admin/Documents/Programming/russian-roulette/source
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Sat May 21 11:23:27 2016 Thomas Murgia
** Last update Sat May 21 11:23:27 2016 Thomas Murgia
*/

#include  <unistd.h>
#include  <randpid.h>
#include  <fcntl.h>
#include  <my.h>

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
