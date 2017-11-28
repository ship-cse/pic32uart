#include <stdlib.h>
#include "circularbuff.h"


void circbuff_init(circbuff_t *buff, int buff_size)
{
    buff->buff = (char *)malloc(buff_size+1);
    buff->count = 0;
    buff->max_size = buff_size;
    buff->rd_pos = 0;
    buff->wr_pos = 0;
}

int circbuff_addch(circbuff_t *buff, char ch)
{
    if (buff->count == buff->max_size)
        return -1;

    INTDisableInterrupts();

    buff->buff[buff->wr_pos++] = ch;
    buff->count++;
    buff->wr_pos %= buff->max_size;

    INTEnableInterrupts();

    return 0;
}

int circbuff_getch(circbuff_t *buff)
{

    if (buff->count == 0) return -1;

    INTDisableInterrupts();

    char ch = buff->buff[buff->rd_pos++];
    buff->count--;
    buff->rd_pos %= buff->max_size;
    
    INTEnableInterrupts();

    return ch;
}
int circbuff_isfull(circbuff_t *buff)
{
    return (buff->count == buff->max_size);
}

int circbuff_isempty(circbuff_t *buff)
{
    return (buff->count == 0);
}

int circbuff_hasdata(circbuff_t *buff)
{
    return (buff->count > 0);
}

int circbuff_almostfull(circbuff_t *buff)
{
    return (buff->max_size - buff->count) < 10;
}