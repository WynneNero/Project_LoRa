#ifndef __BOARD_H__
#define __BOARD_H__

#define BOARD_TITLE "TC275C TriBoard"

#ifndef DEFAULT_PLL_VALUE
  #define DEFAULT_PLL_VALUE  PLL_VALUE_200_100
#endif


/* default ASCLIN device */
#ifndef ASCIO_ASCLIN_BASE
//#define ASCIO_ASCLIN_BASE		ASCLIN0_ADDRESS_BASE
#define ASCIO_ASCLIN_BASE		ASCLIN2_ADDRESS_BASE
#endif /* ASCIO_ASCLIN_BASE */

#endif /* __BOARD_H__ */
