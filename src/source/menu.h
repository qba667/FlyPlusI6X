#ifndef MENU_H_
#define MENU_H_

#include <stdint.h>
#include <stddef.h>


typedef void (*menuMethodVoid)();


typedef struct menuMethods
{
	menuMethodVoid* mainDisplay;
    menuMethodVoid* closeEntry;
    menuMethodVoid* keyPress;
    menuMethodVoid* refreshValues;
    menuMethodVoid* beforeDisplay
} menuMethods;

typedef struct menuEntry
{
	char* name;
    menuMethods* menuMethods;
} menuEntry;


#endif
