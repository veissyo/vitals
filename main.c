#include <stdio.h>
#include "vitals.h"
#include "visuals.h"
#include <limits.h>

int main(void) {
    // Declaring variables:
    long long total = 0, available = 0, used = 0;
    int capacity = 0;
    float usage = 0, temp = 0, uptime = 0;
    char hostname[HOST_NAME_MAX +1];
    char status[16], total_str[16], used_str[16];
    int days = 0, hours = 0, minutes = 0;

    // Fetching data:
    get_temp(&temp);
    get_uptime(&uptime);
    get_hostname(hostname);
    get_memory(&total, &available);
    get_battery(&capacity, status);
    get_cpu_usage(&usage);

    // Formatting and processing data:
    used = total - available;
    format_size(total, total_str);
    format_size(used, used_str);
    days = (int)uptime / 86400;
    hours = ((int)uptime % 86400) / 3600;
    minutes = ((int)uptime % 3600) / 60;

    // Printing and visualising:
    printf("HOSTNAME: %s\n", hostname);

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

    printf("UPTIME: %dd %dh %dm\n", days, hours, minutes);

    return 0;
}
