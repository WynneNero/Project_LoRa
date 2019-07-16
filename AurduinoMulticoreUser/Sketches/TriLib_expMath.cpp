/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

/* Required as TriLib in in C */

#include    "TriLib.h"



/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

sint32 volatile StopPoint;


/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:



}


void loop() {
  // put your main code for core 0 here, to run repeatedly:



}


/*** Core 1 ***/

/* CPU1 Uninitialised Data */
StartOfUninitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have no initial values here e.g. uint32 CPU1_var; */
EndOfUninitialised_CPU1_Variables

/* CPU1 Initialised Data */
StartOfInitialised_CPU1_Variables
/* Put your CPU1 fast access variables that have an initial value here e.g. uint32 CPU1_var_init = 1; */


//--------------------------------------------
//Sine Input: 3Q29 format
int  X_sin = 0x0C90FDAA;    //Input pi/8

//Sine value in 1Q15 format
DataS R_sin;                //output 0x30fb

//--------------------------------------------
//Cos Input: Radian Input in 3Q29 format

int  X_cos = 0x4B65F1FC;    //Input 3pi/4

//Cosine value in 1Q15 format
DataS R_cos;                //Output 0xa57d
//--------------------------------------------
//Arctan Input in 16Q16 format
int  X_arctan = 0x00018000; //Input 1.5

//arctan value
short R_arctan;              //output 0x3ee5
//--------------------------------------------
//Antiln Input in 4Q12 format
short X_antiln = 0x7DBE;    //Input:7.8593

//Output in 16Q16format     //Output:0x0a1cc5fe
int R_antiln;
//--------------------------------------------
//Expn_16 Input
DataS X_expn = 0x4000;      //Input 0.5
short R_expn;               //Output 0x34c2
//--------------------------------------------
//Ln_32 Input in 16Q16 format
int X_ln = 0x0014A26;       //Input:1.28965

//Output in 5Q11 format
short R_ln;                 //Output:0x0208
//--------------------------------------------
//Sqrt_32 Input in 16Q16 format
int X_sqrt = 0x1210000;     //Input:289

//Square root value in 8Q8 format
short R_sqrt;               //Output:0x1100
//--------------------------------------------
//XpowY_32 Input in 12Q20 format
int X_xpowy = 0x00FAD917;   //15.678

//Exponent in 1Q15 format
DataS Y_xpowy = 0x2a3d;     //0.33
//Output in 12Q20 format
int R_xpowy;                //0x27AD89

EndOfInitialised_CPU1_Variables

void setup1() {
  // put your setup code for core 1 here, to run once:

	X_sin = 0x0C90FDAA;    //Input pi/8
	X_cos = 0x4B65F1FC;    //Input 3pi/4
	X_arctan = 0x00018000; //Input 1.5
	X_antiln = 0x7DBE;    //Input:7.8593
	X_expn = 0x4000;      //Input 0.5
	X_ln = 0x0014A26;       //Input:1.28965
	X_sqrt = 0x1210000;     //Input:289
	X_xpowy = 0x00FAD917;   //15.678
	Y_xpowy = 0x2a3d;     //0.33

}


// Use core 1 as it is 18% faster than core0
void loop1() {
  // put your main code for core 1 here, to run repeatedly:

    //Sine function call
    R_sin = Sine_32(X_sin);

    //Cosine function call
    R_cos = Cos_32(X_cos);

    //Arctan function call
    R_arctan = Arctan_32(X_arctan);

    //AntiLn function call
    R_antiln = AntiLn_16(X_antiln);

    //Expn_16 function call
    R_expn =  Expn_16(X_expn);

    //Ln_32 function call
    R_ln = Ln_32(X_ln);

    //Sqrt_32 function call
    R_sqrt = Sqrt_32(X_sqrt);

    //XpowY_32 function call
    R_xpowy = XpowY_32(X_xpowy,Y_xpowy);

    StopPoint = 1;  //Only to set breakpoint

}



/*** Core 2 ***/

/* CPU2 Uninitialised Data */
StartOfUninitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have no initial values here e.g. uint32 CPU2_var; */
EndOfUninitialised_CPU2_Variables

/* CPU2 Initialised Data */
StartOfInitialised_CPU2_Variables
/* Put your CPU2 fast access variables that have an initial value here e.g. uint32 CPU2_var_init = 1; */
EndOfInitialised_CPU2_Variables


void setup2() {
  // put your setup code for core 2 here, to run once:


}


void loop2() {
  // put your main code for core 2 here, to run repeatedly:



}



