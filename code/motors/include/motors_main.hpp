#ifndef MAIN_H
#define MAIN_H

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

#define TIMER1_TOP 312

void motors_init();
void motors_run();

#endif
