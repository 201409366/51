#include <intrins.h>
#include "IR_Send.h"

sbit IR_LED=P1^4;

void Send_UPD6121(unsigned char syscode,unsigned char keydat);

void sendCode(unsigned char syscode,unsigned char keydat){
	Send_UPD6121(syscode,keydat);
}

//=======================================
void IrSendLow(int time)
{
   unsigned char h;
 
  for(;time>0;time-=26)	//对38K载波，26us为一个周期，
    {
     IR_LED=0;
     h=2;
	 _nop_();
     while(--h!=0) ;
     
     IR_LED=1;
    }	
}
//=======================================
void IrSendHigh(int time)
{
  unsigned char h;
  for(;time>0;time-=26)  //对38K载波，26us为一个周期，
    {
     IR_LED=1;
     h=2;
	 _nop_();
     while(--h!=0) ;
     
     IR_LED=1;
     
    }	
}
//=======================================
void IrSendByte6121(unsigned char n)
{
 char i;
 
 for(i=8;i!=0;i--)
  {
    IrSendLow(560);		//560us
    if(n&1) IrSendHigh(560*3-70);    //1: 560*3us
    else IrSendHigh(560-52);		//0: 560us
	n>>=1;
  }
}
//=======================================
void Send_UPD6121(unsigned char syscode,unsigned char keydat)
{
  IrSendLow(9000-30);		//引导脉冲低电平9ms
  IrSendHigh(4500-90);		//引导脉冲高电平4.5ms
  IrSendByte6121(syscode);		//发一个字节的用户码
  IrSendByte6121(~syscode);		//发一个字节的用户码的反码
  IrSendByte6121(keydat);		//发一个字节的功能码
  IrSendByte6121(~keydat);		//发一个字节的功能码的反码
  IrSendLow(560);			//发560us尾码
}