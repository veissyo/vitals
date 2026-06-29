#ifndef VITALS_VITALS_H
#define VITALS_VITALS_H

void get_memory(long long *total, long long *available);
void get_battery(int *capacity, char* status);
void get_cpu_usage(float *usage);

#endif //VITALS_VITALS_H
