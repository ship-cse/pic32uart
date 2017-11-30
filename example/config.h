/* 
 * File:   config.h
 * Author: tbriggs
 *
 * Created on October 9, 2013, 12:02 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GetSystemClock()       (80000000ul)
#define GetPeripheralClock()    (GetSystemClock()/4)


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

