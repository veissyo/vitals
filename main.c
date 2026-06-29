#include <stdio.h>
#include "vitals.h"
#include "visuals.h"

int main(void) {
    long long total, available = 0;
    int capacity = 0;
    float usage = 0;
    float temp = 0;
    get_temp(&temp);
    float uptime = 0;
    get_uptime(&uptime);
    char hostname[128];
    get_hostname(hostname);
    printf("HOSTNAME: %s\n", hostname);
    char status[16];
    char total_str[16];
    char used_str[16];
    get_memory(&total, &available);
    long long used = total - available;
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
    if (temp > 0) printf("  %3.2f%% %.1f°C\n", usage, temp);
    else printf("  %3.2f%%\n", usage);
    int days = (int)uptime / 86400;
    int hours = ((int)uptime % 86400) / 3600;
    int minutes = ((int)uptime % 3600) / 60;
    printf("UPTIME: %dd %dh %dm\n", days, hours, minutes);
    return 0;
}
