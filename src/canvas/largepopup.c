#include <canvas/canvas.h>

/*static const uint16_t offset_y[256] = {
0x0000, 0x0001, 0x0002, 0x0003, 0x0004, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x000E, 0x000F, 
0x0010, 0x0011, 0x0012, 0x0013, 0x0014, 0x0015, 0x0016, 0x0017, 0x0018, 0x0019, 0x001A, 0x001B, 0x001C, 0x001D, 0x001E, 0x001F, 
0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F, 
0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F, 
0x0800, 0x0801, 0x0802, 0x0803, 0x0804, 0x0805, 0x0806, 0x0807, 0x0808, 0x0809, 0x080A, 0x080B, 0x080C, 0x080D, 0x080E, 0x080F, 
0x0810, 0x0811, 0x0812, 0x0813, 0x0814, 0x0815, 0x0816, 0x0817, 0x0818, 0x0819, 0x081A, 0x081B, 0x081C, 0x081D, 0x081E, 0x081F, 
0x0820, 0x0821, 0x0822, 0x0823, 0x0824, 0x0825, 0x0826, 0x0827, 0x0828, 0x0829, 0x082A, 0x082B, 0x082C, 0x082D, 0x082E, 0x082F, 
0x0830, 0x0831, 0x0832, 0x0833, 0x0834, 0x0835, 0x0836, 0x0837, 0x0838, 0x0839, 0x083A, 0x083B, 0x083C, 0x083D, 0x083E, 0x083F, 
0x1000, 0x1001, 0x1002, 0x1003, 0x1004, 0x1005, 0x1006, 0x1007, 0x1008, 0x1009, 0x100A, 0x100B, 0x100C, 0x100D, 0x100E, 0x100F, 
0x1010, 0x1011, 0x1012, 0x1013, 0x1014, 0x1015, 0x1016, 0x1017, 0x1018, 0x1019, 0x101A, 0x101B, 0x101C, 0x101D, 0x101E, 0x101F, 
0x1020, 0x1021, 0x1022, 0x1023, 0x1024, 0x1025, 0x1026, 0x1027, 0x1028, 0x1029, 0x102A, 0x102B, 0x102C, 0x102D, 0x102E, 0x102F, 
0x1030, 0x1031, 0x1032, 0x1033, 0x1034, 0x1035, 0x1036, 0x1037, 0x1038, 0x1039, 0x103A, 0x103B, 0x103C, 0x103D, 0x103E, 0x103F, 
0x1800, 0x1801, 0x1802, 0x1803, 0x1804, 0x1805, 0x1806, 0x1807, 0x1808, 0x1809, 0x180A, 0x180B, 0x180C, 0x180D, 0x180E, 0x180F, 
0x1810, 0x1811, 0x1812, 0x1813, 0x1814, 0x1815, 0x1816, 0x1817, 0x1818, 0x1819, 0x181A, 0x181B, 0x181C, 0x181D, 0x181E, 0x181F, 
0x1820, 0x1821, 0x1822, 0x1823, 0x1824, 0x1825, 0x1826, 0x1827, 0x1828, 0x1829, 0x182A, 0x182B, 0x182C, 0x182D, 0x182E, 0x182F, 
0x1830, 0x1831, 0x1832, 0x1833, 0x1834, 0x1835, 0x1836, 0x1837, 0x1838, 0x1839, 0x183A, 0x183B, 0x183C, 0x183D, 0x183E, 0x183F, 
};

static const uint16_t offset_x[256] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 0x0040, 
0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x0080, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 0x00C0, 
0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0100, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 0x0140, 
0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 0x01C0, 
0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0200, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 0x0240, 
0x0280, 0x0280, 0x0280, 0x0280, 0x0280, 0x0280, 0x0280, 0x0280, 0x02C0, 0x02C0, 0x02C0, 0x02C0, 0x02C0, 0x02C0, 0x02C0, 0x02C0, 
0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0300, 0x0340, 0x0340, 0x0340, 0x0340, 0x0340, 0x0340, 0x0340, 0x0340, 
0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x0380, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 0x03C0, 
0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0400, 0x0440, 0x0440, 0x0440, 0x0440, 0x0440, 0x0440, 0x0440, 0x0440, 
0x0480, 0x0480, 0x0480, 0x0480, 0x0480, 0x0480, 0x0480, 0x0480, 0x04C0, 0x04C0, 0x04C0, 0x04C0, 0x04C0, 0x04C0, 0x04C0, 0x04C0, 
0x0500, 0x0500, 0x0500, 0x0500, 0x0500, 0x0500, 0x0500, 0x0500, 0x0540, 0x0540, 0x0540, 0x0540, 0x0540, 0x0540, 0x0540, 0x0540, 
0x0580, 0x0580, 0x0580, 0x0580, 0x0580, 0x0580, 0x0580, 0x0580, 0x05C0, 0x05C0, 0x05C0, 0x05C0, 0x05C0, 0x05C0, 0x05C0, 0x05C0, 
0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0600, 0x0640, 0x0640, 0x0640, 0x0640, 0x0640, 0x0640, 0x0640, 0x0640, 
0x0680, 0x0680, 0x0680, 0x0680, 0x0680, 0x0680, 0x0680, 0x0680, 0x06C0, 0x06C0, 0x06C0, 0x06C0, 0x06C0, 0x06C0, 0x06C0, 0x06C0, 
0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0700, 0x0740, 0x0740, 0x0740, 0x0740, 0x0740, 0x0740, 0x0740, 0x0740, 
0x0780, 0x0780, 0x0780, 0x0780, 0x0780, 0x0780, 0x0780, 0x0780, 0x07C0, 0x07C0, 0x07C0, 0x07C0, 0x07C0, 0x07C0, 0x07C0, 0x07C0, 
};*/

static const uint8_t shift8[256] = {
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
};

TTextProperties largePopupTextProperties;
static uint8_t screen_copy[11*4*8];

void largePopupInitCanvas(uint8_t x) {

    memset(&largePopupTextProperties,0,sizeof(largePopupTextProperties));

	largePopupTextProperties.font_segment = MODULE_SEGMENT(font_tiny,PAGE_D);
    largePopupTextProperties.font_pts = font_tiny_pts;
    largePopupTextProperties.font_pos = font_tiny_pos;
    largePopupTextProperties.font_len = font_tiny_len;
    
    largePopupTextProperties.value = 1;
    largePopupTextProperties.color = FBlack + BWhite;
    largePopupTextProperties.sz = 1;
    largePopupTextProperties.space_between_lines = 7;
    
    memset(screen_copy,0x0,sizeof(screen_copy));
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x000 + 0x0A * 8, screen_copy, sizeof(screen_copy)/2);
	TMS99X8_memcpy(MODE2_ADDRESS_PG + 0x800 + 0x0A * 8, &screen_copy[sizeof(screen_copy)/2], sizeof(screen_copy)/2);
	TMS99X8_memset(MODE2_ADDRESS_CT + 0x000 + 0x0A * 8, FBlack + BWhite, sizeof(screen_copy)/2);
	TMS99X8_memset(MODE2_ADDRESS_CT + 0x800 + 0x0A * 8, FBlack + BWhite, sizeof(screen_copy)/2);
    
    largePopupTextProperties.x = 2;
    largePopupTextProperties.y = 2;
//  largePopupWriteText("PopUp!\nPopUp!\nPopUp!\nPopUp!");
    largePopupWriteText("I AM EDELWEISS,\n THANKS FOR SAVING\n ME!");
    
    for (uint8_t i=0; i<11*8; i++) largePopupSetPoint( i, 0,1,FBlack + BWhite);
    for (uint8_t i=0; i<11*8; i++) largePopupSetPoint( i,31,1,FBlack + BWhite);
    for (uint8_t i=0; i< 4*8; i++) largePopupSetPoint( 0, i,1,FBlack + BWhite);
    for (uint8_t i=0; i< 4*8; i++) largePopupSetPoint(87, i,1,FBlack + BWhite);

    largePopupSetPoint( 1, 1, 1, FBlack + BWhite);
    largePopupSetPoint( 1,30, 1, FBlack + BWhite);
    largePopupSetPoint(86, 1, 1, FBlack + BWhite);
    largePopupSetPoint(86,30, 1, FBlack + BWhite);

    // Places the tiles in a way that columns are consective tiles
    {
		
		static const uint8_t scratchpad[22] = {
			0x0A,0x0C,0x0E,0x10,0x12,0x14,0x16,0x18,0x1A,0x1C,0x1E,
			0x0B,0x0D,0x0F,0x11,0x13,0x15,0x17,0x19,0x1B,0x1D,0x1F
		};

			 
		TMS99X8_memcpy(MODE2_ADDRESS_PN0 + 0x000 + x + 0x20*6, (const uint8_t *)&scratchpad[ 0], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN0 + 0x000 + x + 0x20*7, (const uint8_t *)&scratchpad[11], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN0 + 0x100 + x + 0x20*0, (const uint8_t *)&scratchpad[ 0], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN0 + 0x100 + x + 0x20*1, (const uint8_t *)&scratchpad[11], 11);

		TMS99X8_memcpy(MODE2_ADDRESS_PN1 + 0x000 + x + 0x20*6, (const uint8_t *)&scratchpad[ 0], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN1 + 0x000 + x + 0x20*7, (const uint8_t *)&scratchpad[11], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN1 + 0x100 + x + 0x20*0, (const uint8_t *)&scratchpad[ 0], 11);
		TMS99X8_memcpy(MODE2_ADDRESS_PN1 + 0x100 + x + 0x20*1, (const uint8_t *)&scratchpad[11], 11);
    }
}


void largePopupSetPoint(uint8_t x, uint8_t y, uint8_t value, uint8_t color) {

    uint8_t shift = shift8[x];
    x = (x>>3)<<3;
    uint16_t offset = y + 4*x;
    uint16_t moffset = y + 2*x;
    if (y>15) moffset += 0x800 - 16;

    uint8_t v = screen_copy[offset];
    TMS99X8_setPtr(MODE2_ADDRESS_PG + 0x0A * 8 + moffset);
    if (value) {
        TMS99X8_write(screen_copy[offset] = (v |  shift));
    } else {
        TMS99X8_write(screen_copy[offset] = (v & ~shift));
    }

    TMS99X8_setPtr(MODE2_ADDRESS_CT + 0x0A * 8 + moffset);
    TMS99X8_write(color);
}


static void writeChar(char cr) {
    
    yield();

    IN_SEGMENT( largePopupTextProperties.font_segment, PAGE_D, {
		uint8_t c = cr-32;
		const uint16_t *begin = &largePopupTextProperties.font_pts[largePopupTextProperties.font_pos[c]];
		const uint16_t *end   = &largePopupTextProperties.font_pts[largePopupTextProperties.font_pos[c+1]];
		while (begin != end) {
			uint16_t xy0 = *begin++;
			uint16_t xy = 0; 
			for (uint8_t i=largePopupTextProperties.sz; i; i--) { xy += xy0; }
			
			uint8_t x = largePopupTextProperties.x + (xy>>8);
			uint8_t y = largePopupTextProperties.y + (xy&0xFF);
			largePopupSetPoint(x, y, largePopupTextProperties.value, largePopupTextProperties.color);
			if (largePopupTextProperties.dotCallback != nullptr) (*largePopupTextProperties.dotCallback)();
		}
		uint8_t len0 = largePopupTextProperties.font_len[c];
		uint8_t len  = 0;
		for (uint8_t i=largePopupTextProperties.sz; i; i--) { len += (int8_t)len0; }
		largePopupTextProperties.x += len;
   	});
}

void largePopupWriteText(const char *str) {
    

	uint16_t orig_x = largePopupTextProperties.x;
	uint16_t orig_y = largePopupTextProperties.y;

	while (*str) {
		if (*str == '\n') {
			largePopupTextProperties.x = orig_x;
			orig_y = largePopupTextProperties.y = orig_y + largePopupTextProperties.space_between_lines;
			str++;
			continue;
		}
		writeChar(*str++);
	}
}
