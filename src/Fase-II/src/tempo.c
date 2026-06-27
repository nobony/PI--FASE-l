#include <stdio.h>
#include <time.h>

#include "tempo.h"
#include <time.h>

double obterTempo() {
    return ((double)clock() / CLOCKS_PER_SEC) * 1000.0;
}