// *************************************************
// |      Function prototypes for displaying       |
// |           information on the screen           |
// *************************************************
#pragma once

#include <stdint.h>
#include "functions.h"

#ifndef MESSAGES_H_
#define MESSAGES_H_

void printIntroduction(void);

void printMessage(uint8_t);

void displaySet(Graph*, uint16_t*);

void printConclusion(void);

#endif