#include<LiquidCrystal.h> //header file for lcd
#include<Keypad.h>       //header file for keypad
const byte ROWS=4;      // four rows
const byte COLS=4;      //four columns
char keys[ROWS][COLS]={   //define keymap
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'} 
};
byte rowPins[ROWS]={7,6,5,4};  //connect keypad four rows to these arduino pins
byte colPins[COLS]={3,2,1,0};  //connect keypad four columns to these arduino pins
Keypad kpd = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);  //create the keypad
const int rs=9, en=8, d4=13 ,d5=12 ,d6=11 ,d7=10;       //arduino pins which connected to lcd
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int Num1,Num2,Number;
char key,action;
boolean result= false;
 
void setup() {
  lcd.begin(16,2);   //using 16*2 lcd display
  lcd.print("arduino"); // display a msg on lcd
  lcd.setCursor(0,1);    //set the cursor to column 0 and line 1 on lcd display
  lcd.print("calculator");  //then print this msg
  delay(1000);  //wait for display to show
  lcd.clear();  //then clear the msg
}
void loop() {
  key = kpd.getKey();//storing pressed key value
  if(key!=NO_KEY)
  DetectButtons();
  if(result==true)
  CalculateResult();
  DisplayResult();
}
void DetectButtons()
{
  lcd.clear();
  if(key=='C') //if cancle button is pressed
  {
    Serial.println("Button Cancle");
    Number=Num1=Num2=0;
    result=false;
  }

 
 if(key=='1')
  {
    Serial.println("Button 1");
    if(Number==0)
    Number=1;
    else
    Number=(Number*10)+1; //pressed twice
  }
   if(key=='4')
  {
    Serial.println("Button 4");
    if(Number==0)
    Number=4;
    else
    Number=(Number*10)+4; //pressed twice
  }
   if(key=='7')
  {
    Serial.println("Button 7");
    if(Number==0)
    Number=7;
    else
    Number=(Number*10)+7; //pressed twice
  }
   if(key=='0')
  {
    Serial.println("Button 0");
    if(Number==0)
    Number=0;
    else
    Number=(Number*10)+0; //pressed twice
  }
   if(key=='2')
  {
    Serial.println("Button 2");
    if(Number==0)
    Number=2;
    else
    Number=(Number*10)+2; //pressed twice
  }
   if(key=='5')
  {
    Serial.println("Button 5");
    if(Number==0)
    Number=5;
    else
    Number=(Number*10)+5; //pressed twice
  }
   if(key=='8')
  {
    Serial.println("Button 8");
    if(Number==0)
    Number=8;
    else
    Number=(Number*10)+8; //pressed twice
  }
   if(key=='=')
  {
    Serial.println("Button equal");
    Num2=Number;
    result=true;
  }
   if(key=='3')
  {
    Serial.println("Button 3");
    if(Number==0)
    Number=1;
    else
    Number=(Number*10)+3; //pressed twice
  }
   if(key=='6')
  {
    Serial.println("Button 6");
    if(Number==0)
    Number=6;
    else
    Number=(Number*10)+6; //pressed twice
  }
   if(key=='9')
  {
    Serial.println("Button 9");
    if(Number==0)
    Number=9;
    else
    Number=(Number*10)+9; //pressed twice
  }
  
  if (key=='+'||key=='-'||key=='*'||key=='/')
  {
    Num1=Number;
    Number=0;
    if(key=='+')
    {
      Serial.println("Addition");
      action='+';
    }
    if(key=='-')
    {
      Serial.println("Subtraction");
      action='-';
    }
     if(key=='*')
    {
      Serial.println("Multiplication");
      action='*';
    }
     if(key=='/')
    {
      Serial.println("division");
      action='/';
    }
    delay(100);
  }
}
void CalculateResult()
{
  if(action=='+')
    Number=Num1+Num2;
     if(action=='-')
    Number=Num1-Num2;
     if(action=='*')
    Number=Num1*Num2;
     if(action=='/')
    Number=Num1/Num2;
}
void DisplayResult()
{
  lcd.setCursor(0,0); //set the cursor to column 0 and line 1
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if(result==true)
  {
    lcd.print("=");
    lcd.print(Number); //display result
  }
  lcd.setCursor(0,1); //set the cursor to column 0 and line 2
  lcd.print(Number);  //display the result
}
