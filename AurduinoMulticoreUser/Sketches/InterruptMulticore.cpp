
/* Run this function in core0 when requested */
void Core0IntService(void)
{
	SerialASC.print("\n\rHello from Core "); SerialASC.print(GetCpuCoreID());
}

/* Run this function in core1 when requested */
void Core1IntService(void)
{
	SerialASC.print("\n\rHello from Core "); SerialASC.print(GetCpuCoreID());
}

/* Run this function in core2 when requested */
void Core2IntService(void)
{
	SerialASC.print("\n\rHello from Core "); SerialASC.print(GetCpuCoreID());
}


/*** Core 0 ***/
void setup() {
  // put your setup code for core 0 here, to run once:

	SerialASC.begin(9600);

	/* Create an interrupt in core 0 */
	CreateCore0Interrupt(Core0IntService);

	/* Create an interrupt in core 1 */
	CreateCore1Interrupt(Core1IntService);

	/* Create an interrupt in core 2 */
	CreateCore2Interrupt(Core2IntService);

}


void loop() {
  // put your main code for core 0 here, to run repeatedly:

	/* Trigger interrupt in Core0 now! */
	InterruptCore0();
	delay(500); /* Wait 500ms */

	/* Trigger interrupt in Core1 now! */
	InterruptCore1();
	delay(500); /* Wait 500ms */

	/* Trigger interrupt in Core2 now! */
	InterruptCore2();
	delay(500); /* Wait 500ms */

}


/*** Core 1 ***/
void setup1() {
  // put your setup code for core 1 here, to run once:



}

void loop1() {
  // put your main code for core 1 here, to run repeatedly:

}


/*** Core 2 ***/
void setup2() {
  // put your setup code for core 2 here, to run once:


}

void loop2() {
  // put your main code for core 2 here, to run repeatedly:


}




