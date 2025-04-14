#ifndef TEMP_H
#define TEMP_H
#include "vector.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/**
 * SensorData
 */

typedef struct __attribute__((packed)) SensorData {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temp;
} SensorData;

typedef struct Stats {
    int8_t min;
    int8_t max;
    uint32_t count;
    int32_t sum;
} Stats;

bool parse_csv_sensor_data(const char *line, SensorData *data);
void debug_sensor_data(SensorData *data);
void collect_and_print_stats(Vector *data, int8_t month);
void print_table_header();
void print_month_stats_row(uint8_t month, Stats *stats);
void print_year_stats_row(uint16_t year, Stats *stats);

/**
 * File utils
 */

bool readline(FILE *file, char *buf, size_t bufsize, size_t *length);

#endif