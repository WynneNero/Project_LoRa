#ifndef TONE_H
#define TONE_H

#ifdef __cplusplus
//extern "C"{
#endif

#define NoOfArduinoToneIoPins  54

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration);
void tone(uint8_t _pin, unsigned int frequency);
void noTone(uint8_t _pin);

#ifdef __cplusplus
//}
#endif

#endif /* TONE_H */
