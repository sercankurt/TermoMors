#include <12F629.h>

#fuses INTRC_IO,NOMCLR,NOWDT,NOPROTECT
#use delay(internal=4M)

#define ONE_WIRE_PIN PIN_A5
#define BUZZER PIN_A2

#include <ds18b20.c>

float temp=0;
 
 int onlar,birler=0;
 
 int dit=325 , daa=725 , arabosluk=55, arabekleme=100;
 
void playDot() {
    output_high(BUZZER);
    delay_ms(dit);
    output_low(BUZZER);
    delay_ms(arabosluk);
}

void playDash() {
    output_high(BUZZER);
    delay_ms(daa);
    output_low(BUZZER);
    delay_ms(arabosluk);
}

 void morscozucu(aralik){

 onlar = (int)temp / 10;
 birler = (int)temp % 10;
 
 if(temp < 0) {        // derece 0'ın altına düştüğünde, -(eksi) işaretini yapmak için:  -....-
            playDash();
            playDot();
            playDot();
            playDot();
            playDot();
            playDash();
 }
 
 
if (temp >= 10) 
{

 switch (onlar) {
        case 0:
            playDash();
            playDash();
            playDash();
            playDash();
            playDash();
            break;
        case 1:
            playDot();
            playDash();
            playDash();
            playDash();
            playDash();
            break;
        case 2:
            playDot();
            playDot();
            playDash();
            playDash();
            playDash();
            break;
        case 3:
            playDot();
            playDot();
            playDot();
            playDash();
            playDash();
            break;
        case 4:
            playDot();
            playDot();
            playDot();
            playDot();
            playDash();
            break;
        case 5:
            playDot();
            playDot();
            playDot();
            playDot();
            playDot();
            break;
        case 6:
            playDash();
            playDot();
            playDot();
            playDot();
            playDot();
            break;
        case 7:
            playDash();
            playDash();
            playDot();
            playDot();
            playDot();
            break;
        case 8:
            playDash();
            playDash();
            playDash();
            playDot();
            playDot();
            break;
        case 9:
            playDash();
            playDash();
            playDash();
            playDash();
            playDot();
            break;
    }
}

   delay_ms(arabekleme);
   
   switch (birler) {
        case 0:
            playDash();
            playDash();
            playDash();
            playDash();
            playDash();
            break;
        case 1:
            playDot();
            playDash();
            playDash();
            playDash();
            playDash();
            break;
        case 2:
            playDot();
            playDot();
            playDash();
            playDash();
            playDash();
            break;
        case 3:
            playDot();
            playDot();
            playDot();
            playDash();
            playDash();
            break;
        case 4:
            playDot();
            playDot();
            playDot();
            playDot();
            playDash();
            break;
        case 5:
            playDot();
            playDot();
            playDot();
            playDot();
            playDot();
            break;
        case 6:
            playDash();
            playDot();
            playDot();
            playDot();
            playDot();
            break;
        case 7:
            playDash();
            playDash();
            playDot();
            playDot();
            playDot();
            break;
        case 8:
            playDash();
            playDash();
            playDash();
            playDot();
            playDot();
            break;
        case 9:
            playDash();
            playDash();
            playDash();
            playDash();
            playDot();
            break;
    }
 }
 
void main()
{
temp=ds1820_read();
delay_ms(10);
 morscozucu(arabosluk);    
}
