#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "bici.h"

// Idle states
#define rectangulos 0
#define torreta 1
#define knight 2
#define lastidlestate torreta
#define firstidlestate rectangulos

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix2 = Adafruit_8x8matrix();
int8_t a = 0;
int8_t b = 0;
int switchstate = 0;
int ML = 0;
int MR = 0;
int MS = 0;
int MI = 0;
int vueltas = 0; //Vueltas en idle

int idlestate = rectangulos;



void setup() {
  Serial.begin(9600);
  Serial.println("Ch9FOD Pwns");
  
  pinMode(A0, INPUT);  
  digitalWrite(A0, HIGH);
  pinMode(A1, INPUT);  
  digitalWrite(A1, HIGH);  
  pinMode(A2, INPUT);  
  digitalWrite(A2, HIGH);    
  
  matrix.begin(0x70);  // pass in the address
  matrix.setRotation(3);
  matrix.setBrightness(0);
  matrix2.begin(0x71);  // pass in the address
  matrix2.setRotation(3);
  matrix2.setBrightness(0);  
}

void loop() 
{
  checkswitch();
  switch (switchstate) 
  {
    case 0:
      idle();
      break;
    case 1:
      left();
      break;
    case 2:
      right();
      break;
    case 3:
      straight();
      switchstate = 0;
      break;
  }
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void idle(void) {
  
  if(idlestate == rectangulos)
    animRect();
  else if (idlestate == torreta)
    animTorreta();
  else if (idlestate == knight)
    animKnight();
  else
    animRect();
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void animRect(void){
  switch (MI) {
    case 0:
      writeRect2matrix(3,3,2,2,3,3,2,2,200);
      MI = 1;
      break;  
  }
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void animTorreta(void){
  switch (MI) {
    case 0:  
      writeRect2matrix(0,0,8,4,0,4,8,4,100);
      MI = 1;
      break; 
  }
}  

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void animKnight(void){
  switch (MI) { 
    case 0:  
      writeRect2matrix(0,0,8,4,0,4,8,4,100);
      MI = 1;
      break;   
  }
}  
/* 
    case 1:
      if (idlestate == rectangulos){
        writeRect2matrix(2,2,4,4,2,2,4,4,200);
      }
//////////////////////
      if (idlestate == torreta){
        clearmatrix();
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);      
      }
      MI = 2;
      break;  
//------------------//         
    case 2:
      Serial.println("Caso 2");    
      if (idlestate == rectangulos){
        writeRect2matrix(1,1,6,6,1,1,6,6,200);
      }
//////////////////////
      if (idlestate == torreta){
        clearmatrix();
        matrix.fillRect(0,0,8,4, LED_ON);
        matrix2.fillRect(0,4,8,4, LED_ON);
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);      
      }
      MI = 3;
      break;         
//------------------//  
    case 3:
      Serial.println("Caso 3");    
      if (idlestate == rectangulos){
        writeRect2matrix(0,0,8,8,0,0,8,8,200);
        MI = 0;
        break;          
      }
//////////////////////
      if (idlestate == torreta){
        clearmatrix();
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);
        MI = 4;
        break;        
      }
//------------------//      
    case 4:
      Serial.println("Caso 4");    
      if (idlestate == torreta){
        clearmatrix();
        matrix.fillRect(0,4,8,4, LED_ON);
        matrix2.fillRect(0,0,8,4, LED_ON);        
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);
        MI = 5;
        break; 
      }
//------------------//           
    case 5:
      Serial.println("Caso 5");    
      if (idlestate == torreta){
        clearmatrix();
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);
        MI = 6;
        break;  
      }   
//------------------//       
    case 6:
      Serial.println("Caso 6");    
      if (idlestate == torreta){
        clearmatrix();
        matrix.fillRect(0,4,8,4, LED_ON);
        matrix2.fillRect(0,0,8,4, LED_ON);     
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);
        MI = 7;
        break;    
      }  
//------------------//       
    case 7:
      Serial.println("Caso 7");    
      if (idlestate == torreta){
        clearmatrix();
        matrix.writeDisplay();  
        matrix2.writeDisplay();  
        delay(100);
        MI = 0;
        break;    
      }  
//------------------//       
    }  
  //idlestate++;
 // if (idlestate > lastidlestate)
 //   idlestate = firstidlestate;
*/

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
 
void left (void) 
{
  if (ML == 0)
    {
      ML = 1;
      MS = 0;
      MR = 0;
      ///////
      a = 16;
      b = 8;
      clearmatrix();
      matrix.drawBitmap(a, 0, left_arrow, 8, 8, LED_ON);
      matrix.writeDisplay();
      matrix2.drawBitmap(b, 0, left_arrow, 8, 8, LED_ON);
      matrix2.writeDisplay();
    }
  else
  {
      a--;
      b--;
      clearmatrix();
      matrix.drawBitmap(a, 0, left_arrow, 8, 8, LED_ON);
      matrix.writeDisplay();
      matrix2.drawBitmap(b, 0, left_arrow, 8, 8, LED_ON);
      matrix2.writeDisplay();
      if (b == -8){
        b = 8;
      }
      if (a == -8)
        a = 8;    
      delay(100);
  }    
}  

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void right (void) 
{
  if (MR == 0)
    {
      ML = 0;
      MS = 0;
      MR = 1;
      ///////  
      a = -8;
      b = -16;
      clearmatrix();
      matrix.drawBitmap(a, 0, right_arrow, 8, 8, LED_ON);
      matrix.writeDisplay();
      matrix2.drawBitmap(b, 0, right_arrow, 8, 8, LED_ON);
      matrix2.writeDisplay();
    }
  else
  {
    a++;
    b++;
    clearmatrix();
    matrix.drawBitmap(a, 0, right_arrow, 8, 8, LED_ON);
    matrix.writeDisplay();
    matrix2.drawBitmap(b, 0, right_arrow, 8, 8, LED_ON);
    matrix2.writeDisplay();
    if (b == 8){
      b = -8;
    }
    if (a == 8)
      a = -8;    
    delay(100);
  }    
}  

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void straight (void) 
{
  ML = 0;
  MS = 1;
  MR = 0;
  a = 8;
  clearmatrix();
  matrix.drawBitmap(0, a, up_arrow, 8, 8, LED_ON);
  matrix.writeDisplay();
  matrix2.drawBitmap(0, a, up_arrow, 8, 8, LED_ON);
  matrix2.writeDisplay();
  for (int8_t x=0; x<48; x++) {
      a--;
      clearmatrix();
      matrix.drawBitmap(0, a, up_arrow, 8, 8, LED_ON);
      matrix.writeDisplay();
      matrix2.drawBitmap(0, a, up_arrow, 8, 8, LED_ON);
      matrix2.writeDisplay();
      if (a == -8)
        a = 8;    
      delay(100);
  }
  MI = 0;  
}  

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void clearmatrix (void)
{
  matrix.clear();
  matrix2.clear();
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void checkswitch (void)
{
  if(!digitalRead(A2))
  {
    while(!digitalRead(A2)) //While Brake
      {
        clearmatrix();
        matrix.setBrightness(15);
        matrix2.setBrightness(15);
        matrix.fillRect(0,0, 8,8, LED_ON);
        matrix2.fillRect(0,0, 8,8, LED_ON);
        matrix.writeDisplay();  
        matrix2.writeDisplay();          
      }
    matrix.setBrightness(0);
    matrix2.setBrightness(0);
    MI = 0;       //Reset idle state
    vueltas = 0;  //Reset vueltas en idle
  }
  if(!digitalRead(A0)) //Left
  {
    switchstate = 1; 
  }
  else if (!digitalRead(A1)) //Right
  {
    switchstate = 2;
  }
  else
  {
    if (switchstate == 1 || switchstate == 2)
      switchstate = 3;
    else
      switchstate = 0;
  }
}

void writeRect2matrix (byte m1x1, byte m1y1, byte m1x2, byte m1y2, byte m2x1, byte m2y1, byte m2x2, byte m2y2, byte Delay)
{
  clearmatrix();
  matrix.drawRect(m1x1, m1y1, m1x2, m1y2, LED_ON);
  matrix2.drawRect(m2x1, m2y1, m2x2, m2y2, LED_ON);
  matrix.writeDisplay();  
  matrix2.writeDisplay();  
  delay(Delay);
}
