#include "win.h"

struct dwin* dwin_new(uint32_t len)
{
    struct dwin* win = malloc(sizeof(struct dwin));
    win->len = len;
    win->total = 0;
    win->val = 0;
    return win;
}

float dwin_push(struct dwin* win, float val)
{
    win->total += val;
    win->val = win->total / (win->len + 1);
    win->total -= win->val;
    return win->val;
}

void dwin_free(struct dwin* win)
{
    free(win);
}
