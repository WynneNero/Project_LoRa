#ifndef EEPROM_TC275_h
#define EEPROM_TC275_h


#ifdef __cplusplus
extern "C"{
#endif


#define CRC32_Polynomial    	0xedb88320ul   // Polynomial used to seed CRC

#define EEPROM_CRCCHECKLENGTH 	SECTORVALID_CRC32_ADDR
#define SECTORVALID_MARKER  	0xAA55AA55ul
#define SECTORVALID_MARKER_ADDR 0x1FFCul
#define SECTORVALID_CRC32_ADDR  0x1FF8ul
#define LOGICAL_SECTORSIZE   	0x2000
#define EEPROM_MAX_USERADDRESS 	0xAF05DFFFul
#define DFLASH_PAGESIZE		 	8
#define DFLASH_BURST_PAGESIZE	32
#define NO_OF_SECTORS			47

typedef enum {UsingNormalPage, UsingBackupPage } EEPROM_StatusType;

typedef enum { EEPROM_Not_Initialised, EEPROM_Initialised } eepromInitType;

typedef union { uint32 dword[LOGICAL_SECTORSIZE/4]; uint8 bytes[LOGICAL_SECTORSIZE]; } LogicalSectorBufferType;

extern uint32 ValidSectorNo;

uint8_t eeprom_read_byte( uint8_t *index );
void eeprom_write_byte( uint8_t *index, uint8_t in );


void DFlash_Write(uint32 PageAddress, const uint32* pData, uint32 NumOfBytes);
void DFlash_Erase(uint32 SectorAddress, uint32 NumOfLogicalSectors);

extern eepromInitType eeprom_init(void);
extern void eeprom_writebuffer(void);
extern void CreateCrcError(uint32 Sector);

#ifdef __cplusplus
}
#endif


#endif /* EEPROM_TC275_h */
