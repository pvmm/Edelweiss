#include <common.h>

#include <infobar/infobar_weapons.h>
USING_MODULE(infobar_weapons, PAGE_D);


static uint16_t oldMapDotWolfi;
static uint16_t oldMapDotTarget;

void infoBarInit() {

static const uint8_t hearts[5][8] = {
{	0b00000000,
	0b00110110,
	0b01001001,
	0b01000001,
	0b01000001,
	0b00100010,
	0b00010100,
	0b00001000, },
{	0b00000000,
	0b00110110,
	0b01111001,
	0b01111001,
	0b01111001,
	0b00111010,
	0b00011100,
	0b00001000, },
{	0b00000000,
	0b00110110,
	0b01111111,
	0b01111111,
	0b01111111,
	0b00111110,
	0b00011100,
	0b00001000, },
{	0b00000000,
	0b00000000,
	0b00110000,
	0b00111000,
	0b00111000,
	0b00011000,
	0b00001000,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b00110110,
	0b00111110,
	0b00111110,
	0b00011100,
	0b00001000,
	0b00000000, },};

static const uint8_t map[2][8] = {
{	0b00000000,
	0b00000000,
	0b10001011,
	0b11011010,
	0b11111011,
	0b10101010,
	0b10001010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b10111000,
	0b10101010,
	0b10111000,
	0b10100010,
	0b10100000,
	0b00000000, },};

static const uint8_t rupees[5][8] = {
{	0b00000000,
	0b00000000,
	0b11101010,
	0b10101010,
	0b11001010,
	0b10101010,
	0b10101110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101000,
	0b11101100,
	0b10001000,
	0b10001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11101110,
	0b10001000,
	0b11001110,
	0b10000010,
	0b11101110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000,
	0b00000000, },};
	
static const uint8_t lamp[2][8] = {
{	0b00000000,
	0b00000000,
	0b10011101,
	0b10010101,
	0b10011101,
	0b10010101,
	0b11010101,
	0b00000000, },
{	0b00000000,
	0b0000000,
	0b00010111,
	0b10110101,
	0b11110111,
	0b01010100,
	0b00010100,
	0b00000000, },};

static const uint8_t boots[3][8] = {
{	0b00000000,
	0b00000000,
	0b11001110,
	0b10101010,
	0b11001010,
	0b10101010,
	0b11001110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10100100,
	0b10100100,
	0b10100100,
	0b11100100,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },};

static const uint8_t coat[2][8] = {
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10001010,
	0b10001010,
	0b10001010,
	0b11101110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10100100,
	0b11100100,
	0b10100100,
	0b10100100,
	0b00000000, },};

static const uint8_t pear[2][8] = {
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101000,
	0b11101100,
	0b10001000,
	0b10001110,
	0b00000000, },
{	0b00000000,
	0b00000000,
	0b11101110,
	0b10101010,
	0b11101100,
	0b10101010,
	0b10101010,
	0b00000000, },};


	TMS99X8_memset(MODE2_ADDRESS_PN0 + 0x2C0, 0, 64);
	TMS99X8_memset(MODE2_ADDRESS_PN1 + 0x2C0, 0, 64);

	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x0A*8, &hearts[0][0], 5*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x0F*8, &map[0][0],    2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x11*8, &rupees[0][0], 5*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x16*8, &lamp[0][0],   2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x18*8, &boots[0][0],  3*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x1B*8, &coat[0][0],   2*8);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x1D*8, &pear[0][0],   2*8);

	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0A*8, FWhite + BBlack, (5+2+5+2+3+2+2)*8);

	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0D*8, FLightRed + BBlack, 8);
	TMS99X8_memset(MODE2_ADDRESS_CT + 0x1000 + 0x0E*8, FLightRed + BBlack, 8);


	{
		TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 0); // MAP
		TMS99X8_write(0x0F); NOP(); NOP();
		TMS99X8_write(0x10); NOP(); NOP();
		TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 14); // RUPEES
		TMS99X8_write(0x11); NOP(); NOP();
		TMS99X8_write(0x12); NOP(); NOP();
		TMS99X8_write(0x13); NOP(); NOP();
		TMS99X8_write(0x14); NOP(); NOP();
		TMS99X8_write(0x15); NOP(); NOP();
	}
	
	{
		TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 0); // MAP
		TMS99X8_write(0x0F); NOP(); NOP();
		TMS99X8_write(0x10); NOP(); NOP();
		TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 14); // RUPEES
		TMS99X8_write(0x11); NOP(); NOP();
		TMS99X8_write(0x12); NOP(); NOP();
		TMS99X8_write(0x13); NOP(); NOP();
		TMS99X8_write(0x14); NOP(); NOP();
		TMS99X8_write(0x15); NOP(); NOP();
	}


	for (int i=0; i<32; i++) {
		SA0[i].y = 209;
		SA1[i].y = 209;
	}	

	SA0[4].y = (uint8_t)(191-16);
	SA0[4].x = 0;
	SA0[4].pattern = 128;
	SA0[4].color = BMediumRed;

	SA0[5].y = (uint8_t)(191-16);
	SA0[5].x = 0;
	SA0[5].pattern = 132;
	SA0[5].color =  BWhite;

	SA0[6].y = (uint8_t)(191-16);
	SA0[6].x = 8*7;
	SA0[6].pattern = 136;
	SA0[6].color =  BWhite;

	SA0[7].y = (uint8_t)(191-16);
	SA0[7].x = 0;
	SA0[7].pattern = 144;
	SA0[7].color =  BWhite;

	SA1[4].y = (uint8_t)(191-16);
	SA1[4].x = 0;
	SA1[4].pattern = 128;
	SA1[4].color =  BMediumRed;

	SA1[5].y = (uint8_t)(191-16);
	SA1[5].x = 0;
	SA1[5].pattern = 132;
	SA1[5].color =  BWhite;

	SA1[6].y = (uint8_t)(191-16);
	SA1[6].x = 8*7;
	SA1[6].pattern = 140;
	SA1[6].color =  BWhite;

	SA1[7].y = (uint8_t)(191-16);
	SA1[7].x = 0;
	SA1[7].pattern = 144;
	SA1[7].color =  BWhite;


	oldMapDotWolfi = 0;
	oldMapDotTarget = 0;

	infoBarUpdateWeapon();
	infoBarUpdateLife();
	infoBarUpdateMap();
	infoBarUpdateRupees();
	infoBarUpdateItems();
	
}

void infoBarUpdateWeapon() {

	IN_MODULE(infobar_weapons, PAGE_D, 
		TMS99X8_setPtr(MODE2_ADDRESS_SG+(((uint16_t)136)<<3));
		switch (state.weapon) {
		case E_PAW:
			TMS99X8_memcpy32(weapons_0_1.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_1.sprite1Pattern);
			SA0[6].color  =  weapons_0_1.sprite0Color;
			SA1[6].color  =  weapons_0_1.sprite1Color;
			break;
		case E_CLAW:
			TMS99X8_memcpy32(weapons_0_0.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_0.sprite1Pattern);
			SA0[6].color  =  weapons_0_0.sprite0Color;
			SA1[6].color  =  weapons_0_0.sprite1Color;
			break;
		case E_SWORD:
			TMS99X8_memcpy32(weapons_0_2.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_2.sprite1Pattern);
			SA0[6].color  =  weapons_0_2.sprite0Color;
			SA1[6].color  =  weapons_0_2.sprite1Color;
			break;
		case E_AXE:
			TMS99X8_memcpy32(weapons_0_4.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_4.sprite1Pattern);
			SA0[6].color  =  weapons_0_4.sprite0Color;
			SA1[6].color  =  weapons_0_4.sprite1Color;
			break;
		case E_BOMB:
			TMS99X8_memcpy32(weapons_0_3.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_3.sprite1Pattern);
			SA0[6].color  =  weapons_0_3.sprite0Color;
			SA1[6].color  =  weapons_0_3.sprite1Color;
			break;
		case E_FIRE:
			TMS99X8_memcpy32(weapons_0_6.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_6.sprite1Pattern);
			SA0[6].color  =  weapons_0_6.sprite0Color;
			SA1[6].color  =  weapons_0_6.sprite1Color;
			break;
		case E_BOW:
			TMS99X8_memcpy32(weapons_0_7.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_7.sprite1Pattern);
			SA0[6].color  =  weapons_0_7.sprite0Color;
			SA1[6].color  =  weapons_0_7.sprite1Color;
			break;
		case E_BUTTER_KNIFE:
			TMS99X8_memcpy32(weapons_0_5.sprite0Pattern);
			TMS99X8_memcpy32(weapons_0_5.sprite1Pattern);
			SA0[6].color  =  weapons_0_5.sprite0Color;
			SA1[6].color  =  weapons_0_5.sprite1Color;
			break;
		}
	);

}

void infoBarUpdateLife() {
	
	TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 0 * 32 + 22);
	for (uint8_t i=0; i<state.entities[0].maximum_life; i+=10) {
		TMS99X8_write(0x0A);
		if (i==100)
			TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 1 * 32 + 22);
	}
	
	TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 0 * 32 + 22);
	for (uint8_t i=0; i<state.entities[0].life; i+=10) {
		if (i+5<=state.entities[0].life) {
			TMS99X8_write(0x0E);
		} else {
			TMS99X8_write(0x0D);
		}
		if (i==100)
			TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 1 * 32 + 22);		
	}
}

void infoBarUpdateMap() {

	SA0[4].x = SA1[4].x = 16 + (state.entities[0].pos.x >> 11);
	if (oldMapDotWolfi) {
		TMS99X8_setPtr(oldMapDotWolfi);
		TMS99X8_write(0x00);
		oldMapDotWolfi = 0;
	}
	oldMapDotWolfi = MODE2_ADDRESS_SG + (((uint16_t)128)<<3) + (state.entities[0].pos.y >> 11);
	TMS99X8_setPtr(oldMapDotWolfi);
	TMS99X8_write(0x80);

	SA0[5].x = SA1[5].x = 16 + (state.nextFlower.x >> 3);
	if (oldMapDotTarget) {
		TMS99X8_setPtr(oldMapDotTarget);
		TMS99X8_write(0x00);
		oldMapDotTarget = 0;
	}
	if (state.nextFlower.y<128) {
		oldMapDotTarget = MODE2_ADDRESS_SG + (((uint16_t)132)<<3) + (state.nextFlower.y >> 3);
		TMS99X8_setPtr(oldMapDotTarget);
		TMS99X8_write(0x80);
	}
}

void infoBarUpdateRupees() {
static const uint8_t cypherLeft[10][8] = {
{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b10100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b01100000,
	0b00100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b10000000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b11100000,
	0b10100000,
	0b11100000,
	0b00100000,
	0b11100000,
	0b00000000, },};

static const uint8_t cypherRight[10][8] = {
{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001010,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00000110,
	0b00000010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001000,
	0b00001010,
	0b00001110,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000010,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000000, },

{	0b00000000,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001110,
	0b00000010,
	0b00001110,
	0b00000000, },};	

uint8_t cypherRupees [8] = {
	0b00000000,
	0b00000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b10000000,
	0b00000000,
	0b00000000, };
	
	uint16_t rupees = state.rupees;
	
	if (rupees>999) rupees = 999;
	uint8_t n = 0;
	while (rupees>99) {rupees-=100; n++; }
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] += cypherRight[n][i]; }
	
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x14*8, &cypherRupees[0], 8);
	n = 0;
	while (rupees>9) {rupees-=10; n++;}
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] = cypherLeft[n][i]; }
	n = rupees;
	for (uint8_t i=0; i<8; i++) { cypherRupees[i] += cypherRight[n][i]; }
	
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x1000 + 0x15*8, &cypherRupees[0], 8);
}

void infoBarUpdateItems() {

	TMS99X8_setPtr(MODE2_ADDRESS_PN0 + 0x2C0 + 1 * 32 + 10);

	if (state.hasLamp) {
		TMS99X8_write(0x16); NOP(); NOP();
		TMS99X8_write(0x17); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasBoots) {
		TMS99X8_write(0x18); NOP(); NOP();
		TMS99X8_write(0x19); NOP(); NOP();
		TMS99X8_write(0x1A); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasCoat) {
		TMS99X8_write(0x1B); NOP(); NOP();
		TMS99X8_write(0x1C); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasPear) {
		TMS99X8_write(0x1D); NOP(); NOP();
		TMS99X8_write(0x1E); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}

	TMS99X8_setPtr(MODE2_ADDRESS_PN1 + 0x2C0 + 1 * 32 + 10);

	if (state.hasLamp) {
		TMS99X8_write(0x16); NOP(); NOP();
		TMS99X8_write(0x17); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasBoots) {
		TMS99X8_write(0x18); NOP(); NOP();
		TMS99X8_write(0x19); NOP(); NOP();
		TMS99X8_write(0x1A); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasCoat) {
		TMS99X8_write(0x1B); NOP(); NOP();
		TMS99X8_write(0x1C); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
	if (state.hasPear) {
		TMS99X8_write(0x1D); NOP(); NOP();
		TMS99X8_write(0x1E); NOP(); NOP();
	} else {
		TMS99X8_write(0x00); NOP(); NOP();
		TMS99X8_write(0x00); NOP(); NOP();
	}
}