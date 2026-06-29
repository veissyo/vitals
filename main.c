#include <stdio.h>
#include "vitals.h"
#include "visuals.h"

int main(void) {
    long long total, available = 0;
    int capacity = 0;
    float usage = 0;
    char status[16];
    char total_str[16];
    char used_str[16];
    get_memory(&total, &available);
    long long used = (long long)total - (long long)available;
    format_size(total, total_str);
    format_size(used, used_str);
    get_battery(&capacity, status);
    get_cpu_usage(&usage);
    printf("%-8s", "RAM");
    print_ram_bar(total, used);
    printf("  %s / %s\n", used_str, total_str);
    printf("%-8s","BATTERY");
    print_bat_bar(capacity);
    printf("  %d%% | %s\n", capacity, status);
    printf("%-8s","CPU");
    print_cpu_bar(usage);
    printf("  %3.2f%%\n", usage);
    return 0;
}
