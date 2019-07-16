/*** Don't worry, the normal Arduino setup() and loop() are below this block! ***/

/* LMU uninitialised data */
StartOfUninitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have no initial values here e.g. uint32 LMU_var; */
EndOfUninitialised_LMURam_Variables

/* LMU uninitialised data */
StartOfInitialised_LMURam_Variables
/* Put your LMU RAM fast access variables that have an initial value here e.g. uint32 LMU_var_init = 1; */
EndOfInitialised_LMURam_Variables

/* If you do not care where variables end up, declare them here! */

#include    <stdlib.h>
#include    "TriLib.h"
#include <math.h>

// Local prototypes for the conversion
extern "C" {
DataL _FloatTo1Q31(float);  // Defined in 'C'
}

CplxL* FFT_TF_32(CplxL *TF, int nX );

#define pi  3.14159265359

int StopPoint;

//*****************************************************************************
//                              MEMORY NOTE
// ____________________________________________________________________________
//
//  Pointer     Pointer     Variable                            Alignment
//              Type                                    IntMem or       ExtMem-
//                                                      ExtMem+Cache    NoCache
// ____________________________________________________________________________         
//
//   X                      X(n), X(n+1), X(n+2),..     
//  All         Lin                                     2-bytes         2-bytes
// ____________________________________________________________________________ 
//              
//   R                      R(n), R(n+1), R(n+2),..     
//  All         Lin                                     2-bytes         2-bytes
// ____________________________________________________________________________
//              
//   TF                      R(n), R(n+1), R(n+2),..     
//  All         Lin                                     2-bytes         2-bytes
// ____________________________________________________________________________


//****************** Main *****************************************************
// The main() function calls two examples which demonstrate following functions
// FFTReal_2_32() 
// IFFTReal_2_32() 

/*** Core 0 ***/

void setup() {
  // put your setup code for core 0 here, to run once:

	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);

	digitalWrite(1,LOW);
	digitalWrite(2,LOW);

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
// Data definitions to test 32 bit real FFT

#define     nX1     16                  //Number of Input Data

// Input Data in short with CplxS defined as MEM{Re16,Im16}
CplxL   X1[nX1] =
{
// Data of two different real sequences placed as real and imaginary parts
// of one complex sequence.
// Xa data     Xb data
{-11593,         17492},
{-18414,         27105},
{-18190,          1340},
{ 10811,         22554},
{-11703,        -19404},
{ 2472,          28464},
{-20715,        -13561},
{ 11741,        -14695},
{-7217,          22293},
{ 21360,         14079},
{ 20982,        -21566},
{ 5551,         -28969},
{-205,           23370},
{ 23718,        -17851},
{ 19082,        -11943},
{ 8597,           9578},
};

// Output Data-Buffer
CplxL  R1[2*nX1];

// Twiddle factor buffer
CplxL TF1[nX1];


// The structure definition of  CplxS is changed from {Im16,Re16} order in
// previous implementation to {Re16,Im16} order in present implementation. This
// change of order is done because the new order is predominantly followed in
// all the standard definitions.

#define     nX2     16                  //Number of Input Data
                                        // The data should be multiple of 2
//Input Data in 1Q15 with CplxS defined as MEM{Re16,Im16}
// The FFT of two input data needs to be placed.
// First FFT data of Xa is placed first followed by FFT data of Xb .
CplxL   X2[2*nX2] =
{
// Xa FFT
{ 10693,        0},
{ -4153,    -6483},
{   577,    -9220},
{ -4847,    11044},
{  5910,    -2880},
{ -6776,    -8110},
{ 12155,    -8626},
{ 12039,     2669},
{  1621,        0},
{ 12039,    -2669},
{ 12155,     8626},
{ -6776,     8110},
{  5910,     2880},
{ -4847,   -11044},
{   577,     9220},
{ -4153,     6483},
// Xb FFT
{ 10693,        0},
{ -4153,    -6483},
{   577,    -9220},
{ -4847,    11044},
{  5910,    -2880},
{ -6776,    -8110},
{ 12155,    -8626},
{ 12039,     2669},
{  1621,        0},
{ 12039,    -2669},
{ 12155,     8626},
{ -6776,     8110},
{  5910,     2880},
{ -4847,   -11044},
{   577,     9220},
{ -4153,     6483},
};

//Output Data-Buffer
CplxL  R2[nX2];

// Twiddle factor buffer
CplxL TF2[nX2];

EndOfInitialised_CPU1_Variables

void setup1() {
  // put your setup code for core 1 here, to run once:


}


void loop1() {
  // put your main code for core 1 here, to run repeatedly:

    short NF;

    // Generate the Twiddle factors
    FFT_TF_32( TF1,nX1 );

    // Real Fast Fourier Transform Forward with two real sequences
    // Xa and Xb in real and imaginary parts of X1 respectively.
    // Output will have first block FFT of Xa  results of length N
    // followed by second block FFT of Xb complex results of length N
    digitalWrite(1,HIGH);
    NF = FFTReal_2_32(R1, X1, TF1, nX1);  // 4.6us on core0, 3.8us on core1
    digitalWrite(1,LOW);

    // Generate the Twiddle factors
    FFT_TF_32( TF2, nX2 );

 
//  The input is is arranged in Xa[0],Xa[1]....Xa[n-1],Xb[0],
//  Xb[1]...Xbn-1] in a 2N length complex array and o/p is alternated
//  by Xa[0], Xb[0]..Xa[N-1], Xa[N-1] in a N length complex input array.

    digitalWrite(2,HIGH);
    NF = IFFTReal_2_32(R2, X2, TF2, nX2, 0); // 5.5us on core0, 4.2us on core1
    digitalWrite(2,LOW);

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




/*---------------------------------------------------------------
Function:	 TwiddleFactor
Description: Generate twiddle factor array for FFT algorithms.
Returns:	 A pointer to complex array of twiddle factors.
----------------------------------------------------------------*/

CplxL* FFT_TF_32(CplxL *TF, int nX )
{
	int i;
	float Theta;

	// prepare twiddle coefficients
	for( i = 0; i < nX/2; i++ )
	{
		Theta = 2 * pi * i / nX;

		TF[i].real =  _FloatTo1Q31(cos(Theta));

		TF[i].imag =  _FloatTo1Q31(-sin(Theta));

  	}

	return TF;
}

