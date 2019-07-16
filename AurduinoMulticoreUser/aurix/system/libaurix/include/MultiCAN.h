

#ifndef MULTICAN_H
#define MULTICAN_H 1

#define CAN0_TxMsgObject   1  /* Object numbers must be unique */
#define CAN1_RxMsgObject   0

#define CAN1_TxMsgObject   3
#define CAN0_RxMsgObject   2



enum { MsgObject0, MsgObject1, MsgObject2, MsgObject3, MsgObject4, MsgObject5, MsgObject6, MsgObject7,
	   MsgObject8, MsgObject9, MsgObject10, MsgObject11, MsgObject12, MsgObject13, MsgObject14, MsgObject15, NO_OFAVAILABLECANMESSAGESLOTS } ;

typedef union { uint8 bytes[8]; uint32 dword[2]; } CANMessagePayloadType;


/** CAN information */
typedef struct
{
    struct
    {
        IfxMultican_Can        can;          /**< \brief CAN driver handle */
        IfxMultican_Can_Node   canNode0;   /**< \brief CAN Node 0 */
        IfxMultican_Can_Node   canNode1;   /**< \brief CAN Node 1 */
        IfxMultican_Can_Node   canNode3;   /**< \brief CAN Node 3 */
        IfxMultican_Can_MsgObj UserCanMessages[16]; /**< \brief CAN Destination Message object */
        uint32 UserCanTxIds[NO_OFAVAILABLECANMESSAGESLOTS];
        uint32 UserCanRxIds[NO_OFAVAILABLECANMESSAGESLOTS];

    }drivers;
} App_MulticanBasic;


extern App_MulticanBasic g_MulticanBasic;

extern void CAN0_Init(uint32 Baudrate);
extern void CAN1_Init(uint32 Baudrate);
extern void CAN1A_Init(uint32 Baudrate);
extern void CAN1_RxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN0_RxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN0_TxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN1_TxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN0_SendMessage(uint32 CAN_Id, uint32 Lowdata, uint32 Highdata, uint8 dlc);
extern void CAN1_SendMessage(uint32 CAN_Id, uint32 Lowdata, uint32 Highdata, uint8 dlc);
extern IfxMultican_Status CAN1_ReceiveMessage(uint32 CAN_Id, IfxMultican_Message *msg1, uint8 dlc);
extern IfxMultican_Status CAN0_ReceiveMessage(uint32 CAN_Id, IfxMultican_Message *msg1, uint8 dlc);

extern void CAN3_Init(uint32 Baudrate);
extern void CAN3_RxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN3_TxInit(uint32 CAN_Id, uint32 AcceptanceMask, uint8 dlc, uint32 ExtFrame, IfxMultican_MsgObjId MsgObj_Id);
extern void CAN3_SendMessage(uint32 CAN_Id, uint32 Lowdata, uint32 Highdata, uint8 dlc);
extern IfxMultican_Status CAN3_ReceiveMessage(uint32 CAN_Id, IfxMultican_Message *msg1, uint8 dlc);






#endif
