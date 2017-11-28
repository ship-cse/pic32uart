/* 
 * File:   circularbuff.h
 * Author: tbriggs
 *
 * Created on October 7, 2013, 12:45 PM
 */

#ifndef CIRCULARBUFF_H
#define	CIRCULARBUFF_H

#ifdef	__cplusplus
extern "C" {
#endif


typedef struct {
    char *buff;
    int count;
    int max_size;
    int rd_pos;
    int wr_pos;
} circbuff_t;

void circbuff_init(circbuff_t *buff, int buff_size);
int circbuff_addch(circbuff_t *buff, char ch);
int circbuff_getch(circbuff_t *buff);
int circbuff_isfull(circbuff_t *buff);
int circbuff_isempty(circbuff_t *buff);
int circbuff_hasdata(circbuff_t *buff);
int circbuff_almostfull(circbuff_t *buff);

#ifdef	__cplusplus
}
#endif

#endif	/* CIRCULARBUFF_H */

