#include <16F877A.H>
#device ADC=16
#FUSES nowdt
#fuses nobrownout
#fuses nolvp
#fuses xt
#use delay (crystal=4000000)
#byte port_a=5
#byte port_b=6
#byte port_c=7
#byte port_d=8
#include <lcd3.c>
int mode=0, estado=0;

void view();
void blink();
 
#INT_EXT              //Se va a realizar una interrupción externa
void EXT_isr(void)
{
   mode=1;
   estado=0;
   set_tris_b(0x0f);  //Habilita las 4 entradas en b
   set_tris_d(0x00);  //Habilita las 4 salidas en d
   port_d=0x00;
   lcd_putc("\fVIAJES_TURISTICOS\n");
   lcd_gotoxy(2,1);
   delay_ms(1000);
   lcd_putc("\noprima(SIG)o(ANT)\n");
   lcd_gotoxy(2,2);

}

void main(){
 
   enable_interrupts(INT_EXT);  //Se habilita interrupcion externa
   enable_interrupts(GLOBAL);   //Se habilita interrupcion global
   lcd_init();
   
   while(true){
      while(mode==1){
         if(input(pin_b1)==0){ 
            while(input(pin_b1)==0);
            estado++;
            if (estado>=8){
               estado=8;
            }
            view();
         }
         if(input(pin_b2)==0){ 
            while(input(pin_b2)==0);
            estado--;
            if (estado<=1){
               estado=1;
            }
            view();
         }
         
         if(input(pin_b3)==0){ 
            while(input(pin_b3)==0);
            /*mode==0;*/
            blink();
         }
      }
   }
}

void view(){
   if(estado==1){
         port_d=0x01;
         lcd_putc("\fComprar pasaje:");
         lcd_gotoxy(2,1);
         lcd_putc(")\n1.Cartagena\n");
         lcd_gotoxy(2,2);
   }
   if(estado==2){
         port_d=0x02;
         lcd_putc("\fComprar pasaje:");
         lcd_gotoxy(2,1);
         lcd_putc("\n2.Santa Marta\n");
         lcd_gotoxy(2,2);
   }
   if(estado==3){
         port_d=0x04;
         lcd_putc("\fComprar pasaje:");
         lcd_gotoxy(2,1);
         lcd_putc("\n3.Medellin\n");
         lcd_gotoxy(2,2);
   }
   if(estado==4){
         port_d=0x08;
         lcd_putc("\nComprar pasaje:");
         lcd_gotoxy(2,1);
         lcd_putc("\n4.Bogota\n");
         lcd_gotoxy(2,2);
   }
   if(estado==5){
          port_d=0x10;
          lcd_putc("\nComprar pasaje:");
            lcd_gotoxy(2,1);
          lcd_putc("\n5.Cali\n"),
          lcd_gotoxy(2,2);
   }
   if(estado==6){
          port_d=0x20;
          lcd_putc("\nComprar pasaje:");
          lcd_gotoxy(2,1);
          lcd_putc("\n6.Melgar\n");
          lcd_gotoxy(2,2);
   }
   if(estado==7){
          port_d=0x40;
          lcd_putc("\nComprar pasaje:");
          lcd_gotoxy(2,1);
          lcd_putc("\n7.Villeta\n");
          lcd_gotoxy(2,2);
   }
   if(estado==8){
          port_d=0x80;
          lcd_putc("\nComprar pasaje:");
          lcd_gotoxy(2,1);
          lcd_putc("\n8.San Andres\n");
          lcd_gotoxy(2,2);
   }
}

 void blink(){
   while(estado==1){
      port_d=0x01;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
 
  
   }
   while(estado==2){
      port_d=0x02;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
  
   }
   while(estado==3){
      port_d=0x04;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
   while(estado==4){
      port_d=0x08;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
   while(estado==5){
      port_d=0x10;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
   while(estado==6){
      port_d=0x20;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
   while(estado==7){
      port_d=0x40;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
   while(estado==8){
      port_d=0x80;
      delay_ms(500);
      port_d=0x00;
      delay_ms(500);
      lcd_putc("\fCOMPRADO");
      lcd_gotoxy(2,1);
      lcd_putc("\n Buen viaje");
      lcd_gotoxy(2,2);
      delay_ms(2000);
      lcd_putc("\n Oprima adquirir");
      lcd_gotoxy(2,1);
   }
}
  
