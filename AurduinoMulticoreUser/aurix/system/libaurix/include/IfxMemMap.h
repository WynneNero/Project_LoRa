/*
 * Hightec Aurix GCC Compiler section attributes
 *
 * a allocatable. This is always set
 * B uninitialized
 * w writable
 * x executable
 * s using small addressing
 * z using absolute addressing section
 *
 */

/* Macros to encapsulate #pragma section */
#define BEGIN_DATA_SECTION(sec, cflags) DATA_SECTION(section #sec  cflags)
#define DATA_SECTION(sec) _Pragma(#sec)
#define END_SECTION DATA_SECTION(section)

/* Macros for allowing easy placement of data in local data scratchpad RAM (DSPR) */
/* CPU0 */
#define StartOfUninitialised_CPU0_Variables BEGIN_DATA_SECTION(int_dsprcpu0.CPU0.bss, awBc0)
#define EndOfUninitialised_CPU0_Variables END_SECTION

#define StartOfInitialised_CPU0_Variables BEGIN_DATA_SECTION(int_dsprcpu0.CPU0.data, awc0)
#define EndOfInitialised_CPU0_Variables END_SECTION

/* CPU1 */
#define StartOfUninitialised_CPU1_Variables BEGIN_DATA_SECTION(int_dsprcpu1.CPU1.bss, awBc1)
#define EndOfUninitialised_CPU1_Variables END_SECTION

#define StartOfInitialised_CPU1_Variables BEGIN_DATA_SECTION(int_dsprcpu1.CPU1.data, awc1)
#define EndOfInitialised_CPU1_Variables END_SECTION

/* CPU2 */
#define StartOfUninitialised_CPU2_Variables BEGIN_DATA_SECTION(int_dsprcpu2.CPU2.bss, awBc2)
#define EndOfUninitialised_CPU2_Variables END_SECTION

#define StartOfInitialised_CPU2_Variables BEGIN_DATA_SECTION(int_dsprcpu2.CPU2.data, awc2)
#define EndOfInitialised_CPU2_Variables END_SECTION

/* LMU */
/* LMU uninitialised data */
#define StartOfUninitialised_LMURam_Variables BEGIN_DATA_SECTION(.zbss, awzB) /* Default flags from linker */
#define EndOfUninitialised_LMURam_Variables END_SECTION

/* LMU uninitialised data */
#define StartOfInitialised_LMURam_Variables BEGIN_DATA_SECTION(.zdata, awz)
#define EndOfInitialised_LMURam_Variables END_SECTION

/* Reduce optimisation to 0 for debugging purposes */
//#pragma GCC optimize "-O0"
