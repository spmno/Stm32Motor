#include "stm32f10x.h"

#define A1 (GPIOA->ODR)
#define Coil_A1 (A1 = 0x00000003)//A��ͨ�磬������ϵ�
#define Coil_B1 (A1 = 0x0000000c)//B��ͨ�磬������ϵ�
#define Coil_C1 (A1 = 0x00000030)//C��ͨ�磬������ϵ�
#define Coil_D1 (A1 = 0x000000c0)//D��ͨ�磬������ϵ�
#define Coil_AB1 (A1=0x0000000f)//AB��ͨ�磬������ϵ�
#define Coil_BC1 (A1=0x0000003c)//BC��ͨ�磬������ϵ�
#define Coil_CD1 (A1=0x000000f0)//CD��ͨ�磬������ϵ�
#define Coil_DA1 (A1=0x000000c3)//D��ͨ�磬������ϵ�
#define Coil_OFF (A1=0)//ȫ���ϵ�


void GPIO_Configuration(void)
{
		GPIO_InitTypeDef GPIO_InitStructure;


		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_7 | GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);



		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);
 
}
 

void RCC_Configuration(void)
{
       SystemInit(); 
       RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB
                           | RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD
                           | RCC_APB2Periph_GPIOE, ENABLE );
}
 
 

void Init_All_Periph(void)
{
       RCC_Configuration();  
       GPIO_Configuration();
}

void Delay(vu32 nCount)
{
  for(; nCount != 0; nCount--);
}

int main(void)
{ 
       Init_All_Periph();
			 
			 
			 
      while(1)
      {
        
					 GPIO_ResetBits(GPIOA, GPIO_Pin_6);
					 GPIO_ResetBits(GPIOA, GPIO_Pin_7);
					 GPIO_ResetBits(GPIOA, GPIO_Pin_8);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_9);
					 GPIO_SetBits(GPIOA, GPIO_Pin_10);
					 GPIO_SetBits(GPIOA, GPIO_Pin_11);
					 
					 Delay(0xEFFFFF);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_6);
					 GPIO_SetBits(GPIOA, GPIO_Pin_7);
					 GPIO_SetBits(GPIOA, GPIO_Pin_8);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_9);
					 GPIO_SetBits(GPIOA, GPIO_Pin_10);
					 GPIO_SetBits(GPIOA, GPIO_Pin_11);
					 
					 Delay(0xEFFFFF);
					 
					 GPIO_ResetBits(GPIOA, GPIO_Pin_9);
					 GPIO_ResetBits(GPIOA, GPIO_Pin_10);
					 GPIO_ResetBits(GPIOA, GPIO_Pin_11);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_6);
					 GPIO_SetBits(GPIOA, GPIO_Pin_7);
					 GPIO_SetBits(GPIOA, GPIO_Pin_8);
					 
					 Delay(0xEFFFFF);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_6);
					 GPIO_SetBits(GPIOA, GPIO_Pin_7);
					 GPIO_SetBits(GPIOA, GPIO_Pin_8);
					 
					 GPIO_SetBits(GPIOA, GPIO_Pin_9);
					 GPIO_SetBits(GPIOA, GPIO_Pin_10);
					 GPIO_SetBits(GPIOA, GPIO_Pin_11);
					 
					 Delay(0xEFFFFF);
					 
      }
}



//			int Speed = 100;
//	int i = 512;
	
//    Stm32_Clock_Init();//ϵͳʱ������
//		RCC->APB2ENR |= 0x00000001; //����afioʱ��
//    AFIO->MAPR = (0x00FFFFFF & AFIO->MAPR)|0x04000000;          //�ر�JTAG 
//				

//	RCC->APB2ENR|=0X0000001c;//��ʹ������IO PORTa,b,cʱ��
//	
//	GPIOA->CRH=0X000fffff;    //�������
//	GPIOA->CRL=0X000fffff;    //�������


           // Component selection
//		GPIO_InitTypeDef GPIO_InitStruct;
//		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
//		GPIO_StructInit(&GPIO_InitStruct);

//		GPIO_InitStruct.GPIO_Mode	=	GPIO_Mode_Out_PP;
//		GPIO_InitStruct.GPIO_Pin	=	GPIO_Pin_3;
//		GPIO_InitStruct.GPIO_Speed	=	GPIO_Speed_2MHz;
//		GPIO_Init(GPIOB,&GPIO_InitStruct);


//		GPIO_SetBits(GPIOB,GPIO_Pin_3);
//		GPIO_ResetBits(GPIOB,GPIO_Pin_3);
	
//	while(1)
//	{
//			GPIOA->ODR = 0x00000003;
//	}
// Coil_OFF;
// while(i--)  //����
//  {         
//     Coil_A1;               //����Coil_A1  ��{A1=1;B1=0;C1=0;D1=0;}����
//     DelayMs(Speed);         //�ı�����������Ե������ת�� ,
//                             //����ԽС��ת��Խ��,����ԽС
//     Coil_B1;
//     DelayMs(Speed);
//     Coil_C1;
//     DelayMs(Speed);
//     Coil_D1;
//     DelayMs(Speed);
//  }
// Coil_OFF;
// while(i--)  //����
//  {         
//     Coil_AB1;               //����Coil_A1  ��{A1=1;B1=0;C1=0;D1=0;}����
//     DelayMs(Speed);         //�ı�����������Ե������ת�� ,
//                             //����ԽС��ת��Խ��,����ԽС
//     Coil_BC1;
//     DelayMs(Speed);
//     Coil_CD1;
//     DelayMs(Speed);
//     Coil_DA1;
//     DelayMs(Speed);
//  }
//  Coil_OFF;
//  i=512;
//  while(i--)//����
//  {
//     Coil_DA1;                //����Coil_A1  ��{A1=1;B1=0;C1=0;D1=0;}����
//     DelayMs(Speed);         //�ı�����������Ե������ת�� ,
//	                         //����ԽС��ת��Խ��,����ԽС
//     Coil_CD1;
//     DelayMs(Speed);
//     Coil_BC1;
//     DelayMs(Speed);
//     Coil_AB1;
//     DelayMs(Speed);
//  }

