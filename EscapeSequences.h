#ifndef ESCAPESEQUENCE_H
#define ESCAPESEQUENCE_H

#include <iostream>

/*
Generic file with ANSI and Unicode escape sequences for various scenarios
*/
/* Reset Generic- apparently the same for backgrounds and foregrounds*/
#define DEFAULT  "\x1B[0m"

//Colors
/* FOREGROUND */
#define BLACK "\u001b[30m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

/* BACKGROUND */
#define Black "\u001b[40m"
#define Red "\u001b[41m"
#define Green "\u001b[42m"
#define Yellow "\u001b[43m"
#define Blue "\u001b[44m"
#define Magenta "\u001b[45m"
#define Cyan "\u001b[46m"
#define White "\u001b[47m"

/* Shapes */
#define EmptyBOX "\u25A1"
#define FullBOX "\u25A0"
#define FullCIRCLE "\u25CF"


/* Cards */
const char spade[4] = "\xe2\x99\xa0";
const char club[4] = "\xe2\x99\xa3";
const char heart[4] = "\xe2\x99\xa5";
const char diamond[4] = "\xe2\x99\xa6";

/* Currencies */
#define USDollar "\u0024"
#define BritishPound "\u00A3"
#define ItalianLira "\u20A4"
#define Euro "\u20AC"	

/* Building Icons */
#define Church "\u26EA"
#define OfficeBuilding 	"\uD83C\uDFE2"

/* Cursor Directions */
#define UP "\u001b[1A"
#define DOWN "\u001b[1B"
#define RIGHT "\u001b[1C"
#define LEFT "\u001b[1D"

#define ERASELINE "\u001b[2K"


//#define UP2 "\033[F"

#endif  /* ESCAPESEQUENCE */

