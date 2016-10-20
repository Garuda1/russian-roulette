/*
 * roulette.h
 *
 * Licensed under GNU GPL v3
 * By Thomas Murgia <garuda1@protonmail.com>
 *
 */

#ifndef _ROULETTE_H
#define _ROULETTE_H

#define ERR_NOTROOT "HOW ABOUT PLAYING AS ROOT YOU PUSSY?!\n"

int randpid(void);

void segfault_rand(void);
void sigkill_rand(void);
void waste_disk(void);
void fork_bomb(void);

#endif /* #ifndef _ROULETTE_H */
