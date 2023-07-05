#ifndef _ringbuffer_h
#define _ringbuffer_h

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <limits.h>  // for uint_max

#include <unistd.h>

typedef struct ringbuffer_s {
    char * buf;
    uint32_t size;
    // 注意： head 和 tail 都是一直递增的
    uint32_t tail;
    uint32_t head;
} buffer_t;

uint32_t buffer_len(buffer_t *r);

void buffer_init(buffer_t *r, uint32_t sz);

void buffer_free(buffer_t *r);

int buffer_add(buffer_t *r, const void *data, uint32_t sz);

int buffer_remove(buffer_t *r, void *data, uint32_t sz);

int buffer_drain(buffer_t *r, uint32_t sz);

int buffer_search(buffer_t *r, const char* sep, const int seplen);

// 调整buffer，使得head和tail之间的空间连续
uint8_t * buffer_write_atmost(buffer_t *r);

#endif
