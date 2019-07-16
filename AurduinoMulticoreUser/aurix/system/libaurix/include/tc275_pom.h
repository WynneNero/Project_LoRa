
#ifndef _TC275_POM_
#define _TC275_POM_

typedef union { uint8 Bytes[16];
				uint32 Dwords[4];
				uint64 Qwords[2]; } TC275_POM_AcdType;
				
				
#ifdef __cplusplus
 extern "C" {
#endif


extern sint8 const ShieldBuddy_Version[];
extern sint8 const ShieldBuddy_Date[];

extern TC275_POM_AcdType volatile TC275_POM_Acd;

extern uint64 TC275_POM0(void);
extern uint64 TC275_POM1(void);

#ifdef __cplusplus
 	 }
#endif

#endif /* _TC275_POM_ */


