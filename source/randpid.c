/*
 * randpid.c
 *
 * Licensed under GNU GPL v3
 * By Thomas Murgia <garuda1@protonmail.com>
 *
 */

#include <unixlib.h>
#include <unistd.h>

int randpid(void)
{
  int     pid;

  pid = my_rand();
  if (pid < 0)
    pid *= -1;
  return (pid % getpid());
}
