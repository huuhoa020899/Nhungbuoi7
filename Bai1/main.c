#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "stdio.h"
void truyen_chuoi(char *str)
{
	while(*str)
	{
		 UARTCharPut(UART0_BASE,*str);
		 str++;
	}
}
void truyen_songuyen(char *n)
{
	while(*n)
	{
		//UARTCharPut(UART0_BASE,*n);
		//n++;
		//printf(n,"%d");
		//n++;
	}
}
int main(void)
{
	int dem;
	// Buoc 2:
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	// Buoc 3:
	GPIOPinTypeGPIOInput(GPIO_PORTD_BASE,GPIO_PIN_0);
	GPIOPinConfigure(GPIO_PA1_U0TX|GPIO_PA0_U0RX);
	GPIOPinTypeUART(GPIO_PORTA_BASE ,GPIO_PIN_1|GPIO_PIN_0);
	GPIOPadConfigSet(GPIO_PORTD_BASE,GPIO_PIN_0,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_STD_WPU);
	// Buoc 4:
	UARTConfigSetExpClk(UART0_BASE,SysCtlClockGet(),9600,UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_STOP_ONE);
	truyen_chuoi("Anh hoa dep trai");
	//truyen_songuyen("10.5");
while(1){
	       if(GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_0)==0)
				 {
					 while(GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_0)==0);
					 dem++;
	       // Buoc 5
	       /*UARTCharPut(UART0_BASE,'@');
	       UARTCharPut(UART0_BASE,'A');
	       UARTCharPut(UART0_BASE,'a');
	       UARTCharPut(UART0_BASE,'B');
	       UARTCharPut(UART0_BASE,'b');
	       UARTCharPut(UART0_BASE,0x0d);
				 SysCtlDelay(100000);
         //while(1);*/
				 }
				 if(dem==1)
				 {
					 UARTCharPut(UART0_BASE,0x0d);
					 truyen_chuoi("Nganh: Ki thuat may tinh");
					 SysCtlDelay(2333333);
					 //while(1);
				 }
				 else if(dem==2)
				 {
					 UARTCharPut(UART0_BASE,0x0d);
					 truyen_chuoi("Khoa: k12-Dai Hoc Cong Nghiep Ha Noi :2017-2021");
					 dem=0;
					 SysCtlDelay(2333333);
					 //while(1);
				 }
        }
}