/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hallSensor.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguarrac <fguarrac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:21:12 by fguarrac          #+#    #+#             */
/*   Updated: 2025/06/15 01:06:44 by fguarrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hallSensor.hpp"
uint8_t g_pinToPort[] = {
	PE,	 // PE 0 ** 0 ** USART0_RX
	PE,	 // PE 1 ** 1 ** USART0_TX
	PE,	 // PE 4 ** 2 ** PWM2
	PE,	 // PE 5 ** 3 ** PWM3
	PG,	 // PG 5 ** 4 ** PWM4
	PE,	 // PE 3 ** 5 ** PWM5
	PH,	 // PH 3 ** 6 ** PWM6
	PH,	 // PH 4 ** 7 ** PWM7
	PH,	 // PH 5 ** 8 ** PWM8
	PH,	 // PH 6 ** 9 ** PWM9
	PB,	 // PB 4 ** 10 ** PWM10
	PB,	 // PB 5 ** 11 ** PWM11
	PB,	 // PB 6 ** 12 ** PWM12
	PB,	 // PB 7 ** 13 ** PWM13
	PJ,	 // PJ 1 ** 14 ** USART3_TX
	PJ,	 // PJ 0 ** 15 ** USART3_RX
	PH,	 // PH 1 ** 16 ** USART2_TX
	PH,	 // PH 0 ** 17 ** USART2_RX
	PD,	 // PD 3 ** 18 ** USART1_TX
	PD,	 // PD 2 ** 19 ** USART1_RX
	PD,	 // PD 1 ** 20 ** I2C_SDA
	PD,	 // PD 0 ** 21 ** I2C_SCL
	PA,	 // PA 0 ** 22 ** D22
	PA,	 // PA 1 ** 23 ** D23
	PA,	 // PA 2 ** 24 ** D24
	PA,	 // PA 3 ** 25 ** D25
	PA,	 // PA 4 ** 26 ** D26
	PA,	 // PA 5 ** 27 ** D27
	PA,	 // PA 6 ** 28 ** D28
	PA,	 // PA 7 ** 29 ** D29
	PC,	 // PC 7 ** 30 ** D30
	PC,	 // PC 6 ** 31 ** D31
	PC,	 // PC 5 ** 32 ** D32
	PC,	 // PC 4 ** 33 ** D33
	PC,	 // PC 3 ** 34 ** D34
	PC,	 // PC 2 ** 35 ** D35
	PC,	 // PC 1 ** 36 ** D36
	PC,	 // PC 0 ** 37 ** D37
	PD,	 // PD 7 ** 38 ** D38
	PG,	 // PG 2 ** 39 ** D39
	PG,	 // PG 1 ** 40 ** D40
	PG,	 // PG 0 ** 41 ** D41
	PL,	 // PL 7 ** 42 ** D42
	PL,	 // PL 6 ** 43 ** D43
	PL,	 // PL 5 ** 44 ** D44
	PL,	 // PL 4 ** 45 ** D45
	PL,	 // PL 3 ** 46 ** D46
	PL,	 // PL 2 ** 47 ** D47
	PL,	 // PL 1 ** 48 ** D48
	PL,	 // PL 0 ** 49 ** D49
	PB,	 // PB 3 ** 50 ** SPI_MISO
	PB,	 // PB 2 ** 51 ** SPI_MOSI
	PB,	 // PB 1 ** 52 ** SPI_SCK
	PB,	 // PB 0 ** 53 ** SPI_SS
	PF,	 // PF 0 ** 54 ** A0
	PF,	 // PF 1 ** 55 ** A1
	PF,	 // PF 2 ** 56 ** A2
	PF,	 // PF 3 ** 57 ** A3
	PF,	 // PF 4 ** 58 ** A4
	PF,	 // PF 5 ** 59 ** A5
	PF,	 // PF 6 ** 60 ** A6
	PF,	 // PF 7 ** 61 ** A7
	PK,	 // PK 0 ** 62 ** A8
	PK,	 // PK 1 ** 63 ** A9
	PK,	 // PK 2 ** 64 ** A10
	PK,	 // PK 3 ** 65 ** A11
	PK,	 // PK 4 ** 66 ** A12
	PK,	 // PK 5 ** 67 ** A13
	PK,	 // PK 6 ** 68 ** A14
	PK	 // PK 7 ** 69 ** A15
};
uint8_t g_pinToBit[] = {
	_BV(0),	 // PE 0 ** 0 ** USART0_RX
	_BV(1),	 // PE 1 ** 1 ** USART0_TX
	_BV(4),	 // PE 4 ** 2 ** PWM2
	_BV(5),	 // PE 5 ** 3 ** PWM3
	_BV(5),	 // PG 5 ** 4 ** PWM4
	_BV(3),	 // PE 3 ** 5 ** PWM5
	_BV(3),	 // PH 3 ** 6 ** PWM6
	_BV(4),	 // PH 4 ** 7 ** PWM7
	_BV(5),	 // PH 5 ** 8 ** PWM8
	_BV(6),	 // PH 6 ** 9 ** PWM9
	_BV(4),	 // PB 4 ** 10 ** PWM10
	_BV(5),	 // PB 5 ** 11 ** PWM11
	_BV(6),	 // PB 6 ** 12 ** PWM12
	_BV(7),	 // PB 7 ** 13 ** PWM13
	_BV(1),	 // PJ 1 ** 14 ** USART3_TX
	_BV(0),	 // PJ 0 ** 15 ** USART3_RX
	_BV(1),	 // PH 1 ** 16 ** USART2_TX
	_BV(0),	 // PH 0 ** 17 ** USART2_RX
	_BV(3),	 // PD 3 ** 18 ** USART1_TX
	_BV(2),	 // PD 2 ** 19 ** USART1_RX
	_BV(1),	 // PD 1 ** 20 ** I2C_SDA
	_BV(0),	 // PD 0 ** 21 ** I2C_SCL
	_BV(0),	 // PA 0 ** 22 ** D22
	_BV(1),	 // PA 1 ** 23 ** D23
	_BV(2),	 // PA 2 ** 24 ** D24
	_BV(3),	 // PA 3 ** 25 ** D25
	_BV(4),	 // PA 4 ** 26 ** D26
	_BV(5),	 // PA 5 ** 27 ** D27
	_BV(6),	 // PA 6 ** 28 ** D28
	_BV(7),	 // PA 7 ** 29 ** D29
	_BV(7),	 // PC 7 ** 30 ** D30
	_BV(6),	 // PC 6 ** 31 ** D31
	_BV(5),	 // PC 5 ** 32 ** D32
	_BV(4),	 // PC 4 ** 33 ** D33
	_BV(3),	 // PC 3 ** 34 ** D34
	_BV(2),	 // PC 2 ** 35 ** D35
	_BV(1),	 // PC 1 ** 36 ** D36
	_BV(0),	 // PC 0 ** 37 ** D37
	_BV(7),	 // PD 7 ** 38 ** D38
	_BV(2),	 // PG 2 ** 39 ** D39
	_BV(1),	 // PG 1 ** 40 ** D40
	_BV(0),	 // PG 0 ** 41 ** D41
	_BV(7),	 // PL 7 ** 42 ** D42
	_BV(6),	 // PL 6 ** 43 ** D43
	_BV(5),	 // PL 5 ** 44 ** D44
	_BV(4),	 // PL 4 ** 45 ** D45
	_BV(3),	 // PL 3 ** 46 ** D46
	_BV(2),	 // PL 2 ** 47 ** D47
	_BV(1),	 // PL 1 ** 48 ** D48
	_BV(0),	 // PL 0 ** 49 ** D49
	_BV(3),	 // PB 3 ** 50 ** SPI_MISO
	_BV(2),	 // PB 2 ** 51 ** SPI_MOSI
	_BV(1),	 // PB 1 ** 52 ** SPI_SCK
	_BV(0),	 // PB 0 ** 53 ** SPI_SS
	_BV(0),	 // PF 0 ** 54 ** A0
	_BV(1),	 // PF 1 ** 55 ** A1
	_BV(2),	 // PF 2 ** 56 ** A2
	_BV(3),	 // PF 3 ** 57 ** A3
	_BV(4),	 // PF 4 ** 58 ** A4
	_BV(5),	 // PF 5 ** 59 ** A5
	_BV(6),	 // PF 6 ** 60 ** A6
	_BV(7),	 // PF 7 ** 61 ** A7
	_BV(0),	 // PK 0 ** 62 ** A8
	_BV(1),	 // PK 1 ** 63 ** A9
	_BV(2),	 // PK 2 ** 64 ** A10
	_BV(3),	 // PK 3 ** 65 ** A11
	_BV(4),	 // PK 4 ** 66 ** A12
	_BV(5),	 // PK 5 ** 67 ** A13
	_BV(6),	 // PK 6 ** 68 ** A14
	_BV(7)	 // PK 7 ** 69 ** A15
};
uint16_t g_portToMode[] = {NOT_A_PORT,		(uint16_t)&DDRA, (uint16_t)&DDRB, (uint16_t)&DDRC, (uint16_t)&DDRD,
						   (uint16_t)&DDRE, (uint16_t)&DDRF, (uint16_t)&DDRG, (uint16_t)&DDRH, NOT_A_PORT,
						   (uint16_t)&DDRJ, (uint16_t)&DDRK, (uint16_t)&DDRL};

uint16_t g_portToOutput[] = {NOT_A_PORT,	   (uint16_t)&PORTA, (uint16_t)&PORTB, (uint16_t)&PORTC, (uint16_t)&PORTD,
							 (uint16_t)&PORTE, (uint16_t)&PORTF, (uint16_t)&PORTG, (uint16_t)&PORTH, NOT_A_PORT,
							 (uint16_t)&PORTJ, (uint16_t)&PORTK, (uint16_t)&PORTL};

Hall::Hall(uint8_t pin) : _pin(pin) {
	this->_init();
}

Hall::Hall(Hall const& src) : _pin(src.getPin()) {
	// this->_pin = src.getPin();
}

Hall& Hall::operator=(Hall const& src) {
	if (this != &src)
		this->_pin = src.getPin();
	return (*this);
}

Hall::~Hall(void) {}

uint8_t Hall::getPin(void) const {
	return (this->_pin);
}

void Hall::_init(void) {
	//	Set port
	uint8_t bit = *g_pinToBit + this->_pin;
	uint8_t port = *g_pinToPort + this->_pin;

	uint8_t* reg = (uint8_t*)(*g_portToMode + port);
	uint8_t* out = (uint8_t*)(*g_portToOutput + port);

	uint8_t oldSREG = SREG;
	cli();
	*reg &= ~bit;
	*out &= ~bit;
	SREG = oldSREG;

	//	Init ADC
	uint8_t pinTmp = this->_pin;
	if (pinTmp >= 54)
		pinTmp -= 54;

	//	//	Set port
	//	DDRF &= ~(1u << DDF0);	   //	Set pin A0 as input (Port F 0)
	//	PORTF &= ~(1u << PORTF0);  //	Disable pull up resistor

	//	Init ADC
	ADMUX |= (1u << REFS0);	  //	Set AVcc as reference
	ADCSRA |= (1u << ADPS0);  //	Set prescaler to 128
	ADCSRA |= (1u << ADPS1);  //	Set prescaler to 128
	ADCSRA |= (1u << ADPS2);  //	Set prescaler to 128
	ADCSRA |= (1u << ADEN);	  //	Enable ADC

	//	Dummy run for ADC initialisation
	ADCSRA |= (1u << ADSC);	 //	Start conversion
	_delay_ms(10);			 //	First conversion may take some time
	while (ADCSRA & (1u << ADSC))
		;		//	Wait for ADC to finish conversion
	(void)ADC;	//	Read conversion
}

uint16_t Hall::readValue(void) {
	//	Wait for some conversion to finish (ADIF in ADCSRA) or check ADSC in ADCSRA?	///	Some other finger already
	// may be reading the ADC
	while (!(ADCSRA & (1u << ADIF)))
		;  //	Wait for conversion to finish
		   //	while (ADCSRA & (1u << ADSC))
		   //		;  							//	Wait for conversion to finish
	//	Set ADC's input
	if (this->_pin > 7)			   //	If ADC input > ADC7
		ADCSRB |= (1u << MUX5);	   //	Set MUX5
	ADMUX &= 0xF8;				   //	Clear previous ADC input
	ADMUX |= (this->_pin & 0x07);  //	Select new ADC input
	//	Start converson
	ADCSRA |= (1u << ADSC);	 //	Start conversion
	//	Wait for conversion to finish
	while (ADCSRA & (1u << ADSC))
		;  //	Wait for conversion to finish
	//	Return read value
	return (ADC);
}
/*
static void ft_itoaptr(uint16_t conv, char* ptr) {
	uint16_t convTmp;
	uint8_t	 convLen;

	convLen = 1;
	convTmp = conv;
	while (convTmp /= 10)
		++convLen;
	ptr[convLen--] = '\0';
	if (conv == 0)
		ptr[convLen] = '0';
	while (conv > 0) {
		ptr[convLen--] = (conv % 10) + '0';
		conv /= 10;
	}
}

int main(void) {
	uint16_t	conv;
	char		digital[6];  //	Max value = 65535 + '\0'
	Uart		uart;
	Hall		hall(A0);

//	//	Init
//
//	//	Set port
//	DDRF &= ~(1u << DDF0);	   //	Set pin A0 as input (Port F 0)
//	PORTF &= ~(1u << PORTF0);  //	Disable pull up resistor
//
	uart.init();

	//	Init ADC
//	ADMUX |= (1u << REFS0);	  //	Set AVcc as reference
//	ADCSRA |= (1u << ADEN);	  //	Enable ADC
//	ADCSRA |= (1u << ADPS0);  //	Set prescaler to 128
//	ADCSRA |= (1u << ADPS1);  //	Set prescaler to 128
//	ADCSRA |= (1u << ADPS2);  //	Set prescaler to 128
//
//	DIDR0 |= (1u << ADC1D) | (1u << ADC2D) | (1u << ADC3D) | (1u << ADC4D) | (1u << ADC5D) | (1u << ADC6D) |
//			 (1u << ADC7D);	 //	Disable unused ADC inputs
//	DIDR1 |= (1u << ADC8D) | (1u << ADC9D) | (1u << ADC10D) | (1u << ADC11D) | (1u << ADC12D) | (1u << ADC13D) |
//			 (1u << ADC14D) | (1u << ADC14D);  //	Disable unused ADC inputs
//
//	//	Dummy run for ADC initialisation
//	ADCSRA |= (1u << ADSC);	 //	Start conversion
//	_delay_ms(10);			 //	First conversion may take some time
//	while (ADCSRA & (1u << ADSC))
//		;		 //	Wait for ADC to finish conversion
//	conv = ADC;	 //	Read conversion

	//	Loop

	for (;;) {
		//ADCSRA |= (1u << ADSC);	 //	Start conversion
		//while (ADCSRA & (1u << ADSC))
		//	;  //	Wait for conversion to finish
		//conv = ADC;
		conv = hall.readValue();
		ft_itoaptr(conv, digital);
		uart.printstrnl(digital);
		_delay_ms(20);
	}
}
*/
