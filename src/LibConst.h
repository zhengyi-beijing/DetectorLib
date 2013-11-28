#pragma once 

#define LUT_SIZE 65536
#define MAX_GRAY 255
#define HEADER_LEN 4
#define  ENGINE_BUF_SIZE 1024
#define DECODE_BUF_SIZE 1024*10
#define CMD_BUF_SIZE 1000
#define WM_DISPLAY_REFRESH		0x10000


#define C_ST	0
#define C_SU	1
#define C_AC	2
#define C_BS	3
#define C_OC	4
#define C_OS	5
#define C_GC	6
#define C_GS	7
#define C_IN	8
#define C_SC	9
#define C_SO	10
#define C_RO	11
#define C_RG	12
#define C_CS	13
#define C_SF	14
#define C_ED	15
#define C_EL	16
#define C_EF	17
#define C_SB	18
#define C_SS	19
#define C_SR	20
#define C_RI	21
#define C_WR	22

#define SYN		0
#define ASYN    1