#ifndef MENGER_H_
#define MENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menger(int level);
void remove_center(int size, char sponge[][size]);
void print_sponge(int size, char sponge[][size]);

#endif
