#include <common.h>
#define MAP_NAME overworld
#include <map_interface.h>
#define NUM_ANIMATED_TILES 4
#define NUM_ANIMATED_FRAMES 4
#define NUM_MAPS 4
#define MAP16_Y 64
#define MAP16_X 128
#define MAP_ANIMATED overworld_animated
USING_MODULE(overworld_animated, PAGE_C);
extern const uint8_t overworld_animated[4][2][64];
#define MAP_MAP16 overworld_map0_map16
#define MAP0_MAP16 overworld_map0_map16
USING_MODULE(overworld_map0_map16, PAGE_D);
extern const uint8_t overworld_map0_map16[64][128];
#define MAP1_MAP16 overworld_map1_map16
USING_MODULE(overworld_map1_map16, PAGE_D);
extern const uint8_t overworld_map1_map16[64][128];
#define MAP2_MAP16 overworld_map2_map16
USING_MODULE(overworld_map2_map16, PAGE_D);
extern const uint8_t overworld_map2_map16[64][128];
#define MAP3_MAP16 overworld_map3_map16
USING_MODULE(overworld_map3_map16, PAGE_D);
extern const uint8_t overworld_map3_map16[64][128];
#define MAP_TILES16 overworld_tiles16
USING_MODULE(overworld_tiles16, PAGE_C);
extern const uint8_t overworld_tiles16[256][2][2];
#define MAP_TILES16_TRAV overworld_tiles16_flag_traversability
USING_MODULE(overworld_tiles16_flag_traversability, PAGE_C);
extern const uint8_t overworld_tiles16_flag_traversability[256][2][2][8];
#define MAP_TILES16_TRIG overworld_tiles16_flag_trigger
USING_MODULE(overworld_tiles16_flag_trigger, PAGE_C);
extern const uint8_t overworld_tiles16_flag_trigger[256][2][2][8];
#define MAP_TILES16_DAMG overworld_tiles16_flag_damage
USING_MODULE(overworld_tiles16_flag_damage, PAGE_C);
extern const uint8_t overworld_tiles16_flag_damage[256][2][2][8];
#define MAP_TILES8L overworld_tiles8L
USING_MODULE(overworld_tiles8L, PAGE_C);
extern const uint8_t overworld_tiles8L[256][2][16];
#define MAP_TILES8R overworld_tiles8R
USING_MODULE(overworld_tiles8R, PAGE_C);
extern const uint8_t overworld_tiles8R[256][2][16];
#include <map_implementation.h>