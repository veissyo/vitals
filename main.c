#include <stdio.h>
#include "vitals.h"

int main(void) {
    long long total, available = 0;
    int capacity = 0;
    char status[16];
    get_memory(&total, &available);
    get_battery(&capacity, status);
    printf("Total memory: %lld\nAvailable memory: %lld\n", total, available);
    printf("Battery precentage: %d%%\nBattery status: %s\n", capacity, status);
    return 0;
}
