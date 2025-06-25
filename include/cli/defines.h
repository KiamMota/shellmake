#include <stdio.h>
#define SET_GREEN()      printf("\033[32m")
#define SET_ORANGE()     printf("\033[38;5;208m")
#define SET_RED()        printf("\033[31m")
#define SET_WHITE()      printf("\033[0m")
#define SAVE_CURSOR()    printf("\033[s")
#define RESTORE_CURSOR() printf("\033[u")
