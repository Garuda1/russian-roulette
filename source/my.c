/*
** my.c for source in /home/admin/Documents/Programming/russian-roulette/source
** 
** Made by Thomas Murgia
** Login   <garuda1@protonmail.com>
** 
** Started on  Sat May 21 11:19:41 2016 Thomas Murgia
** Last update Sat May 21 11:19:41 2016 Thomas Murgia
*/

#include  <my.h>
#include  <fcntl.h>
#include  <unistd.h>

uint8_t   my_rand(void)
{
  uint8_t value;
  int     fd;

  fd = open("/dev/urandom", O_RDONLY);
  read(fd, &value, 1);
  close(fd);
  return (value);
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

int       my_retstr(const char *str, const int error)
{
  my_puts(str);
  return (error);
}
