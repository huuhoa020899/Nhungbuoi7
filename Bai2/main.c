#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
long tg;
// Buoc2:
void Timer1IntHandler(void)
{
	//x= GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_0);
	//x^=GPIO_PIN_0;
	//PIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0,x);
	tg=tg-1;
	if(tg<=0)
	{
		tg=0;
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
	  GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
	}
  TimerIntClear(TIMER1_BASE,TIMER_TIMA_TIMEOUT); // 
}
int main(void)
{
	// Buoc3:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	//GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0);
   	GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_0);//thiet bi
	  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_2);// xanh
	  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_3);//vang
	  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_0);// UP
	  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_0);// DOWN
	  GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_0);// LEFT
	  GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_0,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	  GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_1,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	  GPIOPadConfigSet(GPIO_PORTE_BASE,GPIO_PIN_2,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	//GPIO_PORTE_BASE ,GPIO_PORTF_BASE
	// Buoc4:
	TimerConfigure(TIMER1_BASE,TIMER_CFG_32_BIT_PER);
	TimerLoadSet(TIMER1_BASE,TIMER_A,800000);
	TimerIntEnable(TIMER1_BASE,TIMER_TIMA_TIMEOUT);
	// Buoc5:
	IntEnable(INT_TIMER1A);
	IntMasterEnable();
	//buoc 6:
	TimerEnable(TIMER1_BASE,TIMER_A);
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
	GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
  while(1){
		       if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_0)==0)
					 {
						 tg =10;
						 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,1);// led thiet bi
	           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);// led xanh tat
	           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);// led vang sang
					 }
					 if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_1)==0)
					 {
						 tg=30;
						 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,1);// led thiet bi
	           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,0);// led xanh sang
	           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);// led vang tat
           }
					 if(GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_2)==0)
					 {
						 tg =0;
						 GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_0,0);
	           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2,4);
             GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,8);
					 }
          }
}