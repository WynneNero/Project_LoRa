/*
 *    Default interrupt priority definitions for TriCore
 */

#ifndef __DEF_ISR_PRIO_H__
#define __DEF_ISR_PRIO_H__

/* default timer ISR priority */
#ifndef TIMER_ISR_PRIO
	#define TIMER_ISR_PRIO			1
#endif

/* default system timer ISR priority */
#ifndef SYSTIME_ISR_PRIO
	#define SYSTIME_ISR_PRIO		2
#endif

/* default external input ISR priority */
#ifndef EXTINT_ISR_PRIO
	#define EXTINT_ISR_PRIO			4
#endif

/* default ASC ISR priority */
#ifndef ASCIO_BUF_RXISR_PRIO
	#define ASCIO_BUF_RXISR_PRIO	5
#endif
#ifndef ASCIO_BUF_TXISR_PRIO
	#define ASCIO_BUF_TXISR_PRIO	6
#endif

/* default CAN ISR priority */
#ifndef CANIO_ISR_PRIO
	#define CANIO_ISR_PRIO			8
#endif

/* service monitor ISR priorities */
#define MONTRI_REC_ISR_PRIO			30
#define MONTRI_DBG_ISR_PRIO			31

#endif /* __DEF_ISR_PRIO_H__ */
