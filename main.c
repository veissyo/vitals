#include <stdio.h>
#include "vitals.h"

int main(void) {
    long long total, available = 0;
    get_memory(&total, &available);
    printf("Total memory: %lld\nAvailable memory: %lld\n", total, available);
    return 0;
}
