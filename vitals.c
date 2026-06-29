#include <stdio.h>
#include <string.h>
#include "vitals.h"
#include <unistd.h>

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

void get_cpu_usage(float *usage) {
    FILE* cpuusage = fopen("/proc/stat", "r");
    if (!cpuusage) return;
    char label[8];
    long long user, nice, system, idle, iowait, irq, softirq;
    fscanf(cpuusage, "%s %lld %lld %lld %lld %lld %lld %lld",label, &user, &nice, &system, &idle, &iowait, &irq, &softirq);
    float total1 = user + nice + system + idle + iowait + irq + softirq;
    long long idle1 = idle;
    fclose(cpuusage);
    usleep(100000);
    FILE* cpuusage2 = fopen("/proc/stat", "r");
    if (!cpuusage2) return;
    char label2[8];
    long long user2, nice2, system2, idle2, iowait2, irq2, softirq2;
    fscanf(cpuusage2, "%s %lld %lld %lld %lld %lld %lld %lld",label2, &user2, &nice2, &system2, &idle2, &iowait2, &irq2, &softirq2);
    float total2 = user2 + nice2 + system2 + idle2 + iowait2 + irq2 + softirq2;
    *usage = (1.0f - (float)(idle2 - idle1) / (float)(total2 - total1)) * 100;
    fclose(cpuusage2);
}

void get_hostname(char* hostname) {
    FILE* hostnamefile = fopen("/etc/hostname", "r");
    if (!hostnamefile) return;
    fscanf(hostnamefile, "%s", hostname);
    fclose(hostnamefile);
}

void get_temp(float *temp) {
    FILE* tempfile = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (!tempfile) return;
    float raw;
    fscanf(tempfile, "%f", &raw);
    *temp = raw / 1000.0f;
    fclose(tempfile);
}

void get_uptime(float *uptime) {
    FILE* uptimefile = fopen("/proc/uptime", "r");
    if (!uptimefile) return;
    fscanf(uptimefile, "%f", uptime);
    *uptime = (int)*uptime;
    fclose(uptimefile);
}
