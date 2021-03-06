EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "ATSAMC21N18A Dev"
Date "2020-01-18"
Rev "v01"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Author: Erik van Zijst"
$EndDescr
$Comp
L local_syms:ATSAMC21N18A-TQFP32 U1
U 1 1 5E23A334
P 6350 4700
F 0 "U1" H 5625 5575 50  0000 C CNN
F 1 "ATSAMC21N18A-TQFP32" H 6350 4800 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 7350 5600 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/SAM-C20C21-Family-Datasheet-DS60001479C.pdf" H 6350 4700 50  0001 C CNN
	1    6350 4700
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR03
U 1 1 5E23C422
P 6550 2200
F 0 "#PWR03" H 6550 2050 50  0001 C CNN
F 1 "VCC" H 6567 2373 50  0000 C CNN
F 2 "" H 6550 2200 50  0001 C CNN
F 3 "" H 6550 2200 50  0001 C CNN
	1    6550 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2200 6550 2250
Text Label 6325 2250 0    50   ~ 0
3.3v
$Comp
L Device:R R1
U 1 1 5E23DDA0
P 4375 3350
F 0 "R1" H 4445 3396 50  0000 L CNN
F 1 "1K" H 4445 3305 50  0000 L CNN
F 2 "" V 4305 3350 50  0001 C CNN
F 3 "~" H 4375 3350 50  0001 C CNN
	1    4375 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4375 5300 5350 5300
Connection ~ 6550 2775
Wire Wire Line
	6300 5750 6300 5850
Wire Wire Line
	6450 5750 6450 5850
Wire Wire Line
	6450 5850 6300 5850
Connection ~ 6300 5850
Wire Wire Line
	6300 5850 6300 5950
$Comp
L power:PWR_FLAG #FLG02
U 1 1 5E2407B9
P 6300 2775
F 0 "#FLG02" H 6300 2850 50  0001 C CNN
F 1 "PWR_FLAG" H 6300 2948 50  0000 C CNN
F 2 "" H 6300 2775 50  0001 C CNN
F 3 "~" H 6300 2775 50  0001 C CNN
	1    6300 2775
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5E240D20
P 6000 5850
F 0 "#FLG01" H 6000 5925 50  0001 C CNN
F 1 "PWR_FLAG" H 6000 6023 50  0000 C CNN
F 2 "" H 6000 5850 50  0001 C CNN
F 3 "~" H 6000 5850 50  0001 C CNN
	1    6000 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4375 3200 4375 2775
Wire Wire Line
	4375 3500 4375 5100
Wire Wire Line
	3850 4900 4050 4900
Wire Wire Line
	4050 4900 4050 5400
Wire Wire Line
	4050 5400 5350 5400
Wire Wire Line
	3850 5100 4375 5100
Connection ~ 4375 5100
Wire Wire Line
	4375 5100 4375 5300
NoConn ~ 3850 5300
NoConn ~ 3850 5400
$Comp
L local_syms:Conn_ARM_JTAG_SWD_10 J1
U 1 1 5E24CFFF
P 3350 5200
F 0 "J1" H 3400 5981 50  0000 C CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 3400 5890 50  0000 C CNN
F 2 "" H 3350 5200 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 3000 3950 50  0001 C CNN
	1    3350 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 5850 6000 5850
Wire Wire Line
	3250 5850 3250 5800
Wire Wire Line
	3350 5800 3350 5850
Connection ~ 3350 5850
Wire Wire Line
	3350 5850 3250 5850
Wire Wire Line
	3450 5800 3450 5850
Connection ~ 3450 5850
Wire Wire Line
	3450 5850 3350 5850
Connection ~ 6000 5850
Wire Wire Line
	6000 5850 5200 5850
$Comp
L Device:LED D1
U 1 1 5E250E9B
P 7825 5250
F 0 "D1" V 7864 5133 50  0000 R CNN
F 1 "LED" V 7773 5133 50  0000 R CNN
F 2 "" H 7825 5250 50  0001 C CNN
F 3 "~" H 7825 5250 50  0001 C CNN
	1    7825 5250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6550 2775 6550 3000
$Comp
L Device:R R2
U 1 1 5E25332D
P 7450 5850
F 0 "R2" V 7243 5850 50  0000 C CNN
F 1 "220R" V 7334 5850 50  0000 C CNN
F 2 "" V 7380 5850 50  0001 C CNN
F 3 "~" H 7450 5850 50  0001 C CNN
	1    7450 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 5850 6450 5850
Connection ~ 6450 5850
Wire Wire Line
	7600 5850 7825 5850
Wire Wire Line
	7825 5850 7825 5400
Connection ~ 6300 2775
Wire Wire Line
	6300 2775 5200 2775
Wire Wire Line
	6300 2775 6550 2775
$Comp
L Device:CP1 C2
U 1 1 5E2586D0
P 6050 3300
F 0 "C2" V 5950 3100 50  0000 C CNN
F 1 "10uF" V 6175 3300 50  0000 C CNN
F 2 "" H 6050 3300 50  0001 C CNN
F 3 "~" H 6050 3300 50  0001 C CNN
	1    6050 3300
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 5E25A9B6
P 6050 3000
F 0 "C1" V 5925 2800 50  0000 C CNN
F 1 "100nF" V 5889 3000 50  0000 C CNN
F 2 "" H 6088 2850 50  0001 C CNN
F 3 "~" H 6050 3000 50  0001 C CNN
	1    6050 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	5900 3300 5750 3300
Wire Wire Line
	5750 3300 5750 3000
Wire Wire Line
	5750 3000 5900 3000
Wire Wire Line
	6300 2775 6300 3000
Wire Wire Line
	6200 3000 6300 3000
Connection ~ 6300 3000
Wire Wire Line
	6300 3000 6300 3300
Wire Wire Line
	6200 3300 6300 3300
Connection ~ 6300 3300
Wire Wire Line
	6300 3300 6300 3700
$Comp
L Device:CP1 C3
U 1 1 5E2665BE
P 6700 3000
F 0 "C3" V 6600 2800 50  0000 C CNN
F 1 "10uF" V 6825 3000 50  0000 C CNN
F 2 "" H 6700 3000 50  0001 C CNN
F 3 "~" H 6700 3000 50  0001 C CNN
	1    6700 3000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C4
U 1 1 5E2665C8
P 6700 3300
F 0 "C4" V 6575 3100 50  0000 C CNN
F 1 "100nF" V 6539 3300 50  0000 C CNN
F 2 "" H 6738 3150 50  0001 C CNN
F 3 "~" H 6700 3300 50  0001 C CNN
	1    6700 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7200 3300 7100 3300
Wire Wire Line
	6850 3000 7100 3000
Wire Wire Line
	7100 3000 7100 3300
Connection ~ 7100 3300
Wire Wire Line
	7100 3300 6850 3300
Connection ~ 6550 3000
Wire Wire Line
	6550 3000 6550 3300
Connection ~ 6550 3300
Wire Wire Line
	6550 3300 6550 3700
Wire Wire Line
	3350 2775 4375 2775
Wire Wire Line
	3350 2775 3350 4600
Connection ~ 4375 2775
$Comp
L Device:C C5
U 1 1 5E271495
P 6825 3625
F 0 "C5" V 6700 3425 50  0000 C CNN
F 1 "100nF" V 6664 3625 50  0000 C CNN
F 2 "" H 6863 3475 50  0001 C CNN
F 3 "~" H 6825 3625 50  0001 C CNN
	1    6825 3625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6450 3700 6450 3625
Wire Wire Line
	6450 3625 6675 3625
Wire Wire Line
	6975 3625 7100 3625
Wire Wire Line
	7100 3625 7100 3300
NoConn ~ 5350 4200
NoConn ~ 5350 4500
NoConn ~ 5350 4700
NoConn ~ 5350 4800
NoConn ~ 5350 4900
NoConn ~ 5350 5000
NoConn ~ 7350 4100
NoConn ~ 7350 4200
NoConn ~ 7350 4300
NoConn ~ 7350 4600
NoConn ~ 7350 4700
NoConn ~ 7350 4800
NoConn ~ 7350 5000
NoConn ~ 7350 5100
NoConn ~ 7350 5200
NoConn ~ 7350 5300
NoConn ~ 7350 5400
NoConn ~ 7350 4900
Wire Wire Line
	3850 5200 5350 5200
$Comp
L Device:R_POT RV1
U 1 1 5E28D798
P 4850 4300
F 0 "RV1" H 4781 4346 50  0000 R CNN
F 1 "10K" H 4781 4255 50  0000 R CNN
F 2 "" H 4850 4300 50  0001 C CNN
F 3 "~" H 4850 4300 50  0001 C CNN
	1    4850 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4300 5350 4300
Wire Wire Line
	4850 4150 4850 2775
Connection ~ 4850 2775
Wire Wire Line
	4850 2775 4375 2775
Wire Wire Line
	4850 4450 4850 5850
Connection ~ 4850 5850
Wire Wire Line
	4850 5850 3450 5850
Wire Wire Line
	5350 4600 5200 4600
Wire Wire Line
	5200 4600 5200 5850
Connection ~ 5200 5850
Wire Wire Line
	5200 5850 4850 5850
Text Label 5200 5125 1    50   ~ 0
MUXNEG_AIN5
Wire Wire Line
	5350 4400 5200 4400
Wire Wire Line
	5200 4400 5200 2775
Connection ~ 5200 2775
Wire Wire Line
	5200 2775 4850 2775
Text Label 5200 4125 1    50   ~ 0
VREFP_AIN1
Wire Wire Line
	7825 4400 7350 4400
Wire Wire Line
	7825 4400 7825 5100
NoConn ~ 7350 4500
$Comp
L Isolator:4N35 U2
U 1 1 5E2F5471
P 4650 2250
F 0 "U2" H 4650 2575 50  0000 C CNN
F 1 "4N35" H 4650 2484 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 4450 2050 50  0001 L CIN
F 3 "https://www.vishay.com/docs/81181/4n35.pdf" H 4650 2250 50  0001 L CNN
	1    4650 2250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E2F8233
P 3650 1925
F 0 "R3" V 3575 2150 50  0000 C CNN
F 1 "100K" V 3575 1700 50  0000 C CNN
F 2 "" V 3580 1925 50  0001 C CNN
F 3 "~" H 3650 1925 50  0001 C CNN
	1    3650 1925
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5E2F9E36
P 3650 2075
F 0 "R4" V 3575 2300 50  0000 C CNN
F 1 "100K" V 3575 1850 50  0000 C CNN
F 2 "" V 3580 2075 50  0001 C CNN
F 3 "~" H 3650 2075 50  0001 C CNN
	1    3650 2075
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5E2FA495
P 3650 2225
F 0 "R5" V 3575 2450 50  0000 C CNN
F 1 "100K" V 3575 2000 50  0000 C CNN
F 2 "" V 3580 2225 50  0001 C CNN
F 3 "~" H 3650 2225 50  0001 C CNN
	1    3650 2225
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5E2FA8B5
P 3650 2375
F 0 "R6" V 3575 2600 50  0000 C CNN
F 1 "100K" V 3575 2150 50  0000 C CNN
F 2 "" V 3580 2375 50  0001 C CNN
F 3 "~" H 3650 2375 50  0001 C CNN
	1    3650 2375
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 1925 4100 1925
Wire Wire Line
	4100 1925 4100 2075
Wire Wire Line
	4100 2375 3800 2375
Wire Wire Line
	3800 2225 4100 2225
Connection ~ 4100 2225
Wire Wire Line
	4100 2225 4100 2375
Wire Wire Line
	3800 2075 4100 2075
Connection ~ 4100 2075
Wire Wire Line
	4100 2075 4100 2150
Wire Wire Line
	4350 2150 4100 2150
Connection ~ 4100 2150
Wire Wire Line
	4100 2150 4100 2225
Wire Wire Line
	3500 1925 3175 1925
Wire Wire Line
	3175 1925 3175 1975
Wire Wire Line
	3175 2375 3500 2375
Wire Wire Line
	3500 2225 3175 2225
Connection ~ 3175 2225
Wire Wire Line
	3175 2225 3175 2350
Wire Wire Line
	3500 2075 3175 2075
Connection ~ 3175 2075
$Comp
L Diode:1N4007 D4
U 1 1 5E309FF9
P 2900 1975
F 0 "D4" H 2900 1759 50  0000 C CNN
F 1 "1N4007" H 2900 1850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2900 1800 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2900 1975 50  0001 C CNN
	1    2900 1975
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4007 D2
U 1 1 5E30B12B
P 2400 1975
F 0 "D2" H 2400 1759 50  0000 C CNN
F 1 "1N4007" H 2400 1850 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2400 1800 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2400 1975 50  0001 C CNN
	1    2400 1975
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4007 D3
U 1 1 5E30C5DA
P 2400 2350
F 0 "D3" H 2400 2134 50  0000 C CNN
F 1 "1N4007" H 2400 2225 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2400 2175 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2400 2350 50  0001 C CNN
	1    2400 2350
	-1   0    0    1   
$EndComp
$Comp
L Diode:1N4007 D5
U 1 1 5E30D37B
P 2900 2350
F 0 "D5" H 2900 2134 50  0000 C CNN
F 1 "1N4007" H 2900 2225 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2900 2175 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2900 2350 50  0001 C CNN
	1    2900 2350
	-1   0    0    1   
$EndComp
Wire Wire Line
	2550 1975 2650 1975
Wire Wire Line
	2750 2350 2650 2350
Wire Wire Line
	2250 1975 2150 1975
Wire Wire Line
	2150 1975 2150 2350
Wire Wire Line
	2150 2350 2250 2350
Wire Wire Line
	3050 1975 3175 1975
Wire Wire Line
	3175 2350 3050 2350
$Comp
L power:VAC #PWR02
U 1 1 5E32CE2E
P 2275 1425
F 0 "#PWR02" H 2275 1325 50  0001 C CNN
F 1 "VAC" H 2275 1700 50  0000 C CNN
F 2 "" H 2275 1425 50  0001 C CNN
F 3 "" H 2275 1425 50  0001 C CNN
	1    2275 1425
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1450 2650 1975
Connection ~ 2650 1975
Wire Wire Line
	2650 1975 2750 1975
$Comp
L power:NEUT #PWR01
U 1 1 5E33198B
P 2025 1325
F 0 "#PWR01" H 2025 1175 50  0001 C CNN
F 1 "NEUT" H 2042 1498 50  0000 C CNN
F 2 "" H 2025 1325 50  0001 C CNN
F 3 "" H 2025 1325 50  0001 C CNN
	1    2025 1325
	1    0    0    -1  
$EndComp
Wire Wire Line
	2025 1325 2025 1450
Wire Wire Line
	1775 1450 1775 2800
Wire Wire Line
	1775 2800 2650 2800
Wire Wire Line
	2650 2800 2650 2350
Connection ~ 2650 2350
Wire Wire Line
	2650 2350 2550 2350
Wire Wire Line
	3175 1975 3175 2075
Wire Wire Line
	3175 2075 3175 2225
Connection ~ 3175 1975
Connection ~ 3175 2350
Wire Wire Line
	3175 2350 3175 2375
Wire Wire Line
	4250 2350 4250 2525
Wire Wire Line
	4250 2525 2150 2525
Wire Wire Line
	2150 2525 2150 2350
Wire Wire Line
	4250 2350 4350 2350
Connection ~ 2150 2350
Text GLabel 7200 3300 2    50   Input ~ 0
GND
Text GLabel 6300 5950 3    50   Input ~ 0
GND
Text GLabel 5500 2150 2    50   Input ~ 0
GND
$Comp
L Device:R R7
U 1 1 5E37475A
P 5225 2150
F 0 "R7" V 5018 2150 50  0000 C CNN
F 1 "100K" V 5109 2150 50  0000 C CNN
F 2 "" V 5155 2150 50  0001 C CNN
F 3 "~" H 5225 2150 50  0001 C CNN
	1    5225 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 2150 5075 2150
Wire Wire Line
	5375 2150 5500 2150
Wire Wire Line
	4950 2250 6550 2250
Connection ~ 6550 2250
Wire Wire Line
	6550 2250 6550 2775
Text GLabel 5750 3150 0    50   Input ~ 0
GND
Wire Wire Line
	5350 4100 5300 4100
Wire Wire Line
	5300 4100 5300 2350
Wire Wire Line
	5300 2350 4950 2350
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E399BBF
P 1775 1450
F 0 "#FLG0101" H 1775 1525 50  0001 C CNN
F 1 "PWR_FLAG" H 1775 1623 50  0000 C CNN
F 2 "" H 1775 1450 50  0001 C CNN
F 3 "~" H 1775 1450 50  0001 C CNN
	1    1775 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 1450 2275 1450
Wire Wire Line
	2275 1450 2275 1425
Wire Wire Line
	2025 1450 1775 1450
Connection ~ 1775 1450
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5E3B475B
P 2650 1450
F 0 "#FLG0102" H 2650 1525 50  0001 C CNN
F 1 "PWR_FLAG" H 2650 1623 50  0000 C CNN
F 2 "" H 2650 1450 50  0001 C CNN
F 3 "~" H 2650 1450 50  0001 C CNN
	1    2650 1450
	1    0    0    -1  
$EndComp
Connection ~ 2650 1450
Text Label 2375 1450 0    50   ~ 0
120v
$EndSCHEMATC
