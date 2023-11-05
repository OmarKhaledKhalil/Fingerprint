/*
 * FingerPrint.c
 *
 *  Created on: Nov 4, 2023
 *      Author: Ezz_A
 */

#ifndef HAL_FINGERPRINT_C_
#define HAL_FINGERPRINT_C_

u8 buffer[25];
u8 byte_no = 0;

void clearBuffer()
{
	for(int i=0; i<25;i++)
	buffer[i]=0xFF;
	byte_no = 0;
}

void receiveCallback(u8 data){
	buffer[byte_no] = data;
	byte_no++;
}


u8 FingerPS_strTemplate(){
	
	u8 store[15]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x06, 0x06, 0x01, 0x00, 0x00, 0x00, 0x0E};
	
	for (u8 i = 0; i < 15; i++)
	{
		UART_sendByte(store[i]);
	}
	UART_receiveByteAsynchCallBack(receiveCallback);
	//_delay_ms(5);
	while(byte_no != 12);
	
	//calc checksum
	//buffer[9] == 0 return SUCESS else return error code
	//clearBuffer()
	
	return 0;

}


u8 FingerPS_searchFinger(){
	u8 search[17]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x08, 0x04, 0x01, 0x00, 0x00, 0x00, 0xFF, 0x01, 0x0D};
	for (u8 i = 0; i < 17; i++)
	{
		UART_sendByte(search[i]);
	}
	UART_receiveByteAsynchCallBack(receiveCallback);
	
	//_delay_ms(5);
	while(byte_no != 16);
	
	//calc checksum
	//buffer[9] == 0 return SUCESS else return error code
	//clearBuffer()
	
	return 0;
}

void FingerPS_LoadCharFile()
{
		
			u8 store[13]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x04, 0x02, 0x01, 0x00, 0x08};
			
			for (u8 i = 0; i < 13; i++)
			{
				USART_void_SendBlock( store[i] ); // Send byte by byte with BLock
			}
			
			UART_receiveByteAsynchCallBack(receiveCallback);
			//_delay_ms(5);
			while(byte_no != 12);
			
			// Check Sum()
			//Check ACK ()
			//clearBuffer()
	
		

	

}


u16 FingerPS_calcCheckSum(char*arr , u8 length)
{
	u16 sum = 0 ;
	
	for(int i = 6 ; i<length-2 ; i++)
	{
		sum = sum + arr[i];
	}
	return sum ;
}


void FingerPS_match()
{
	u8 store[12]={0xEF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x03, 0x03, 0x00, 0x07};
	
	for (u8 i = 0; i < 12; i++)
	{
		USART_void_SendBlock( store[i] ); // Send byte by byte with BLock
	}
	
	UART_receiveByteAsynchCallBack(receiveCallback);
	//_delay_ms(5);
	while(byte_no != 14);
	
	// Check Sum()
	//Check ACK ()
	//clearBuffer()
}
#endif /* HAL_FINGERPRINT_C_ */
