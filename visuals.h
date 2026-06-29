#ifndef VITALS_VISUALS_H
#define VITALS_VISUALS_H

void format_size(long long size, char *buf);
void print_cpu_bar(float usage);
void print_ram_bar(long long total, long long used);
void print_bat_bar(int capacity);

#endif //VITALS_VISUALS_H
