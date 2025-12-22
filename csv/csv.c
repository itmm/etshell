#include "csv.h"

#include <stdlib.h>
#include "log/log.h"

#define CSV_SEPARATOR ';'

struct Csv_State {
    FILE* in;
    int next;
    bool quoting;
};

static void check_state(struct Csv_State* state) {
    if (! state) { log_fatal("null pointer", "check_state"); }
}

static int get_next_ch(struct Csv_State* state) {
    state->next = fgetc(state->in);
    if (state->next == EOF) {
        if (ferror(state->in)) {
            log_fatal_errno("Fehler beim Lesen");
        }
    }
    return state->next;
}

int next_char_in_csv_cell(struct Csv_State* state) {
    check_state(state);

    if (state->next == '"' && ! state->quoting) {
        get_next_ch(state);
        state->quoting = true;
    }

    if (state->next == '"' /* && state->quoting */) {
        get_next_ch(state);
        if (state->next != EOF && state->next != '"') {
            state->quoting = false;
        }
    }

    if (state->next == EOF) {
        if (state->quoting) { log_fatal("Offener String", ""); }
        return EOF;
    }

    if (! state->quoting) {
        if (state->next == '\n' || state->next == CSV_SEPARATOR) { return EOF; }
    }

    int ch = state->next;
    get_next_ch(state);
    return ch;
}

void next_csv_cell(struct Csv_State* state) {
    check_state(state);
    int ch = state->next;
    if (ch == EOF || ch == '\n') { return; }
    if (ch == CSV_SEPARATOR) { get_next_ch(state); return; }
    log_fatal("Unerwartetes Zeichen in next_cell", "");
}

void eat_csv_cell(struct Csv_State* state) {
    while (next_char_in_csv_cell(state) != EOF) { }
    next_csv_cell(state);
}

void next_csv_line(struct Csv_State* state) {
    check_state(state);
    int ch = state->next;
    if (ch == EOF) { return; }
    if (ch == '\n') { get_next_ch(state); return; }
    log_fatal("Unerwartetes Zeichen in next_line", "");
}

void eat_csv_line(struct Csv_State* state) {
    check_state(state);
    while (state->next != EOF && state->next != '\n') {
        eat_csv_cell(state);
    }
    next_csv_line(state);
}

struct Csv_State* alloc_csv_state(FILE* in) {
    struct Csv_State* state = malloc(sizeof(struct Csv_State));
    if (! state) { log_fatal("Speichermangel", "Kann Status nicht anlegen"); }
    state->in = in;
    state->next = ' ';
    state->quoting = false;
    get_next_ch(state);
    return state;
}

void free_csv_state(struct Csv_State* state) {
    check_state(state);
    free(state);
}

bool is_csv_eof(struct Csv_State* state) {
    check_state(state);
    return state->next == EOF;
}
