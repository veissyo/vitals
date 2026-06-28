#include <stdio.h>
#include <string.h>
#include "vitals.h"

void get_memory(long long *total, long long *available) {
    FILE* meminfo = fopen("/proc/meminfo", "r");
    char key[64];
    long long value;
    char unit[8];
    while (fscanf(meminfo, "%s %lld %s", key, &value, unit) == 3) {
        if (strcmp(key, "MemTotal:") == 0) {
            *total = value;
        } else if (strcmp(key, "MemAvailable:") == 0) {
            *available = value;
        }
        if (*total && *available) break;
    }
    fclose(meminfo);
}

void get_battery(int *capacity, char* status) {
    FILE* batterycap = fopen("/sys/class/power_supply/BAT1/capacity", "r");
    if (!batterycap) return;
    fscanf(batterycap, "%d", capacity);
    fclose(batterycap);
    FILE* batterystatus = fopen("/sys/class/power_supply/BAT1/status", "r");
    if (!batterystatus) return;
    fscanf(batterystatus, "%s", status);
    fclose(batterystatus);
}

void get_cpu_usage(double *usage) {

}