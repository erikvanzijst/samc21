#ifndef WIN_H_INCLUDED
#define WIN_H_INCLUDED
#include <stdlib.h>
#include <atmel_start.h>

/**
 * Describes a dampening window.
 */
struct dwin {
    uint32_t len;
    double total;
    float val;
};

/**
 * Allocates a new instance of dwin on the heap and returns
 * the pointer.
 */
struct dwin* dwin_new(uint32_t len);

/**
 * Pushes a new value onto the window and returns the new
 * dampened value.
 */
float dwin_push(struct dwin* win, float val);

/**
 * Frees the allocated memorty for the specified dwin struct.
 */
void dwin_free(struct dwin* win);
#endif
