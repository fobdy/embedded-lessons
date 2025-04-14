#include "temp_functions.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool readline(FILE *file, char *buf, size_t bufsize, size_t *length) {
    if (file == NULL) {
        return false;
    }

    size_t len = 0;

    if (fgets(buf, bufsize, file) != NULL) {
        len = strlen(buf);

        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
            len -= 1;
        } else if (len > 1 && buf[len - 1] == '\n' && buf[len - 2] == '\r') {
            buf[len - 2] = '\0';
            len -= 2;
        }

        *length = len;
        return true;
    }

    return false;
}

bool parse_csv_sensor_data(const char *line, SensorData *data) {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temp;

    int result = sscanf(line, "%" SCNu16 ";%" SCNu8 ";%" SCNu8 ";%" SCNu8 ";%" SCNu8 ";%" SCNd8,
                        &year, &month, &day, &hour, &minute, &temp);

    if (result != 6) {
        return false;
    }

    if ((month < 1 || month > 12) || (day < 1 || day > 31) || (hour > 23) || (minute > 59)) {
        return false;
    }

    data->year = year;
    data->month = month;
    data->day = day;
    data->hour = hour;
    data->minute = minute;
    data->temp = temp;

    return true;
}

void debug_sensor_data(SensorData *data) {
    printf("SensorData { date = %" PRIu16 "-%02" PRIu8 "-%02" PRIu8 " %02" PRIu8 ":%02" PRIu8
           ", temp = %" PRId8 " }\n",
           data->year, data->month, data->day, data->hour, data->minute, data->temp);
}

void print_table_header() {
    printf("\n%6s%6s%6s%10s\n", "month", "min", "max", "avg");
    printf("============================\n");
}

void print_month_stats_row(uint8_t month, Stats *stats) {
    float avg = (float)stats->sum / stats->count;
    printf("%6" PRIu8 "%6" PRId8 "%6" PRId8 "%10.2f\n", month, stats->min, stats->max, avg);
}

void print_year_stats_row(uint16_t year, Stats *stats) {
    float avg = (float)stats->sum / stats->count;
    printf("----------------------------\n");
    printf("%6" PRIu16 "%6" PRId8 "%6" PRId8 "%10.2f\n", year, stats->min, stats->max, avg);
}

int8_t max(int8_t a, int8_t b) { return a > b ? a : b; }
int8_t min(int8_t a, int8_t b) { return a < b ? a : b; }

void collect_and_print_stats(Vector *data, int8_t month) {
    if (data->size < 1) {
        return;
    }

    SensorData *record = vector_get(data, 0);

    Stats month_s = {record->temp, record->temp, 1, record->temp};
    Stats year_s = {record->temp, record->temp, 1, record->temp};

    int8_t curr_month = record->month;
    int16_t curr_year = record->year;

    print_table_header();

    for (size_t i = 1; i < data->size; i++) {
        record = vector_get(data, i);

        if (record->year == curr_year && record->month == curr_month) {
            month_s.min = min(month_s.min, record->temp);
            month_s.max = max(month_s.max, record->temp);
            month_s.sum += record->temp;
            month_s.count++;

            year_s.min = min(year_s.min, record->temp);
            year_s.max = max(year_s.max, record->temp);
            year_s.sum += record->temp;
            year_s.count++;
        } else if (record->year == curr_year) {
            if (month < 0 || (month > 0 && curr_month == month)) {
                print_month_stats_row(curr_month, &month_s);
            }

            month_s.min = record->temp;
            month_s.max = record->temp;
            month_s.sum = record->temp;
            month_s.count = 1;

            year_s.min = min(year_s.min, record->temp);
            year_s.max = max(year_s.max, record->temp);
            year_s.sum += record->temp;
            year_s.count++;

            curr_month = record->month;
        } else {
            if (month < 0 || (month > 0 && curr_month == month)) {
                print_month_stats_row(curr_month, &month_s);
            }
            print_year_stats_row(curr_year, &year_s);
            print_table_header();

            month_s.min = record->temp;
            month_s.max = record->temp;
            month_s.sum = record->temp;
            month_s.count = 1;

            year_s.min = record->temp;
            year_s.max = record->temp;
            year_s.sum = record->temp;
            year_s.count = 1;

            curr_month = record->month;
            curr_year = record->year;
        }
    }

    if (month < 0 || (month > 0 && curr_month == month)) {
        print_month_stats_row(curr_month, &month_s);
    }
    print_year_stats_row(curr_year, &year_s);
}