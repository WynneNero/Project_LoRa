
/* CPU0 Uninitialised Data */
StartOfUninitialised_CPU0_Variables
/* Put your CPU0 fast access variables that have no initial values here.
 * e.g. uint32 CPU0_var;
 *
 */
EndOfUninitialised_CPU0_Variables

/* CPU0 Initialised Data */
StartOfInitialised_CPU0_Variables
/* Put your CPU0 fast access variables that have an initial value here.
 * e.g. uint32 CPU0_var_init = 1;
 *
 */
EndOfInitialised_CPU0_Variables

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here.
 * e.g. uint32 CPU1_var;
 *
 */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here.
 * e.g. uint32 CPU1_var_init = 1;
 *
 */
EndOfInitialised_CPU1_Variables

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here.
 * e.g. uint32 CPU2_var;
 *
 */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here.
 * e.g. uint32 CPU2_var_init = 1;
 *
 */
EndOfInitialised_CPU2_Variables

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here.
 * e.g. uint32 LMU_var;
 *
 */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here.
 * e.g. uint32 LMU_var_init = 1;
 *
 */
EndOfInitialised_LMURam_Variables

/* Any variables here will be in the CPU0 DSPR0 RAM */






/*** Core 0 ***/
/* Lockstep, efficiency core */

void setup() {
  // put your setup code for core 0 here, to run once:


}


void loop() {
  // put your main code for core 0 here, to run repeatedly:


}


/*** Core 1 ***/
/* Lockstep, performance core */
void setup1() {
  // put your setup code for core 1 here, to run once:


}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:


}



/*** Core 2 ***/
/* Non-Lockstep, performance core */
void setup2() {
  // put your setup code for core 2 here, to run once:


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}



