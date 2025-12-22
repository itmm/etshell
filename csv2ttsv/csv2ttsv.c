#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "log/log.h"
#include "csv/csv.h"

static void do_line(struct Csv_State* csv) {
    eat_csv_line(csv);
}

int main(void) {
    struct Csv_State* csv = alloc_csv_state(stdin);
    while (! is_csv_eof(csv)) {
        do_line(csv);
    }
}
