#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit beep=P2^5;
sbit key=P3^3;
uchar bR0H,bR0L,beat;

code uchar music[]={0, 0, 0, 1, 2, 3, 5, 4, 3, 2, 1, 3, 0, 5, 6, 1, 2, 3, 7, 1, 5, 6, 0, 0, 1, 2, 3, 5, 4, 3, 2, 1, 3, 0, 5, 6, 1, 2, 3, 7, 1, 5, 6,
        6, 0, 0, 1, 5, 1, 5, 1, 1, 5, 1, 5, 1, 1, 5, 1, 5, 1, 1, 2, 1, 3, 1, 1, 5, 1, 5, 1,
        1, 1, 5, 1, 5, 1, 1, 5, 1, 5, 1, 1, 1, 7, 5, 6, 3, 5, 7, 1, 5, 1, 5, 1, 1, 1, 5, 1, 5, 1, 1, 5, 1, 5, 1,
        1, 1, 2, 1, 3, 1, 1, 2, 1, 3, 1, 1, 2, 1, 3, 1, 1, 0, 0, 0, 5, 5, 1, 5,
        2, 5, 3, 5, 5, 0, 1, 0, 2, 0, 4, 3, 2, 1, 0, 5, 1, 5, 3, 5, 1, 5, 2, 5, 1, 5,
        3, 5, 1, 5, 5, 5, 1, 5, 2, 5, 3, 5, 5, 6, 1, 6, 2};

code uchar FREQH[]={

0xF2,0xF3,0xF5,0xF5,0xF6,0xF7,0xF8,

0xF9,0xF9,0xFA,0xFA,0xFB,0xFB,0xFC,

0xFC,0xFC,0xFD,0xFD,0xFD,0xFD,0xFE,

0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF} ;
//音符频率表,四个8度7阶,低8位
code uchar FREQL[]={

0x42,0xC1,0x17,0xB6,0xD0,0xD1,0xB6,

0x21,0xE1,0x8C,0xD8,0x68,0xE9,0x5B,

0x8F,0xEE,0x44,0x6B,0xB4,0xF4,0x2D,

0x47,0x77,0xA2,0xB6,0xDA,0xFA,0x16};

void delay(uchar t)
{
uchar t1;

unsigned long t2;

for(t1=0;t1<t;t1++)

{
for(t2=0;t2<3200;t2++);
}

TR0=0;
}

void delay(uchar t);
void play()
{
TH0=bR0H;
TL0=bR0L;
TR0=1;
delay(beat);
}

void play();
void main()
{
uchar J,K;
TMOD=1;
EA=1;
ET0=1;
EX0=1;

while(J<=300)
{
J=0; 
while(1)
{
K=music[J]+music[J+1]*7-1;
bR0H=FREQH[K];
bR0L=FREQL[K];
beat=music[J+2];
J=J+3; 
play();
}
}
}

void t0int() interrupt 1
{
TR0=0;

beep=~beep;

TH0=bR0H;

TL0=bR0L;

TR0=1;
}
//请仿照这个乐谱构成，帮我把乐谱修改为电影《你的名字》中的钢琴曲《约会》，要求效果明显