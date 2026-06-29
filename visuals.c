#include <stdio.h>
#include <string.h>
#include "visuals.h"

void format_size(long long size, char *buf) {
    if (size < 1024) {
        sprintf(buf, "%lld KB", size);
    }
    else if (size < 1024 * 1024) {
        sprintf(buf, "%.2f MB", (float)size / 1024);
    }
    else {
        sprintf(buf, "%.2f GB", (float)size / (1024 * 1024));
    }
}

void print_bar(int filled, int color) {
    printf("\033[%dm", color);
    for (int j = 0; j < filled; j++) printf("▓");
    printf("\033[0m");
    for (int j = filled; j < 20; j++) printf("░");
}

void print_cpu_bar(float usage) {
    int color = 0;
    int filled = (int)(usage / 100 * 20);
    color = usage < 50 ? 32 : usage < 80 ? 33 : 31;
    print_bar(filled, color);
}
void print_ram_bar(long long total, long long used) {
    int color = 0;
    float ram_percent = (float)used / (float)total * 100;
    color = ram_percent < 50 ? 32 : ram_percent < 80 ? 33 : 31;
    int filled = (int)(ram_percent / 100 * 20);
    print_bar(filled,color);
}
void print_bat_bar(int capacity) {
    int color = 0;
    color = capacity > 50 ? 32 : capacity > 20 ? 33 : 31;
    int filled = (int)((float)capacity / 100 * 20);
    print_bar(filled,color);
}