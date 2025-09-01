# 01/09/2025: 4 leds run 



# preconditions| Подготовка

## Terms
| Term   | Description |
|--------|-------------|
| МК     | микроконтроллер / microcontroller (Arduino) |
| IRFZ44N  | Полевой транзистор N-типа (MOSFET)<br> <img src="..\img\Mosfet_IRFZ44N.png" alt="внешний вид N-MOSFET IRFZ44N"> |
| Breadboard | беспаечная макетная плата |


# компоненты | required parts
| Компоненты |
|------------|
| 4 полевых транзистора IRFZ44N |
| 4 резистора 220 Ом (используем как стягивающие резисторы на Gate, для разряда затвора и закрытия транзистора) |
| я на Breadboard использую резисторы в корпусе С1-4<br> <img src="..\img\resistor_С1-4.png" alt="внешний резистора в корпусе С1-4"> |
| 4 перемычки для активации защёлки на транзисторе |
| 4 перемычки для подключения транзистора (нога Source → общий GND) |
| 4 перемычки для подключения ноги GND светодиода к ноге Drain транзистора |
| 4 резистора 100 Ом для подключения питания 4 светодиодов |
| 4 перемычки для подключения питания 4 светодиодов |


# connections| подключение:
# UNO
	*	UNO 4 Gate Pins d1(TX),d2,d3,d4
	*	МК UNO 4 цифровых ноги для активации защелки на полевом транзисторе.
## Power -> Breadboard 
		*	GND:	 	UNO GND to Breadboard GND common rail
		*	GND:	 	UNO GND на общую шину GND на макетной плаате.
		*	Power:		UNO 5V to Breadboard Power rail
		*	Питаие:		UNO 5V на общую шину питания на макетной плаате.
# IRFZ44N
	*	jumper from GND common rail to IRFZ44N Source Pin 
	*	ставим перемычку от общей шины GND на макетной плаате к транзитосру нога источник
	*	Gate jumpers from UNO Gate pins to IRFZ44N  Gate pin
	* 	ставим перемычки от МК Gate пины (1,2,3,4) на соответствцющие IRFZ44N по порядку слева направо.
