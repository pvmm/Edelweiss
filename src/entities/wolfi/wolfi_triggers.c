#include <common.h>

#include <entities/wolfi/entity_wolfi_sprite.h>

USING_MODULE(entity_wolfi_sprite, PAGE_D);


static void hole_warp_to(uint8_t i, uint8_t j) {
	
	Entity *wolfi = &state.entities[0]; 
	uint8_t spawn_idx = 0;

	wolfi->pos.j = (wolfi->pos.j+0x40) & 0xFF00;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	wolfi->orientation = E_UP;
	sprites[spawn_idx].spriteInfo = (wolfi->animation_counter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i -= 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}

	sprites[spawn_idx].enabled = 0;

	
	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = (((uint16_t)j)<<9)+0x100;
	sprites[spawn_idx].pos.i = wolfi->pos.i;
	sprites[spawn_idx].pos.j = wolfi->pos.j;

	do {
		
		wait_frame();

		int16_t i = (wolfi->pos.i>>8) - map.pos.i;
		if (i<8 && state.target_map_pos.i>0) state.target_map_pos.i =  map.pos.i-1;
		if (i>13 && state.target_map_pos.i<(uint8_t)(129-23)) state.target_map_pos.i = map.pos.i+1;
		
		int16_t j = (wolfi->pos.j>>8) - map.pos.j;
		if (j<10 && state.target_map_pos.j>0) state.target_map_pos.j = map.pos.j-1;
		if (j>20 && state.target_map_pos.j<(uint8_t)(255-31)) state.target_map_pos.j = map.pos.j+1;

		state.request_scroll_update |= (map.pos.j != state.target_map_pos.j);
		state.request_scroll_update |= (map.pos.i != state.target_map_pos.i);
	
	} while (state.request_scroll_update);

	wolfi->orientation = E_DOWN;
	sprites[spawn_idx].spriteInfo = (wolfi->animation_counter & 0x04? &wolfi_2_0 : &wolfi_2_1);
	sprites[spawn_idx].enabled = true;

	for (uint8_t k=0; k<6; k++) {
		wolfi->pos.i += 16;
		sprites[spawn_idx].pos.i = wolfi->pos.i;
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
	}
}



INLINE void door_warp_to(uint8_t i, uint8_t j) {

	Entity *wolfi = &state.entities[0]; 

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);

	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = (((uint16_t)j)<<9);
	sprites[0].pos.i = wolfi->pos.i;
	sprites[0].pos.j = wolfi->pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);
	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
}


static void well_warp_to(uint8_t i, uint8_t j) {

	Entity *wolfi = &state.entities[0]; 

	TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);

	if (state.times_fallen_in_the_well==0) {
		small_message("AAAAARGH!");
	} else if (state.times_fallen_in_the_well==1) {
		small_message("AGAIN?\nREALLY?\nAAAAARGH!");
	} else if (state.times_fallen_in_the_well<5) {
		small_message("HERE WE GO\nAGAIN!\nAAAAARGH!");
	}

	wolfi->pos.i = (((uint16_t)i)<<9)-16;
	wolfi->pos.j = ((uint16_t)j)<<9;
	sprites[0].pos.i = wolfi->pos.i;
	sprites[0].pos.j = wolfi->pos.j;

	TRAMPOLINE_PAGE_C(wolfi_door_warp_migrate);
	TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);

	if (state.times_fallen_in_the_well==0) {
		small_message("THERE WERE\nRATS!");
		state.times_fallen_in_the_well++;
	} else if (state.times_fallen_in_the_well<5) {
		small_message("THIS ISN'T\nFUN!");
		state.times_fallen_in_the_well++;
	}
}



void wolfi_triggers() {

	Entity *wolfi = &state.entities[0]; 

	uint8_t tile16 =  overworld_get_tile16(wolfi->pos.i+0x100, wolfi->pos.j+0x100);
	uint8_t ti = (wolfi->pos.i+0x100)>>9;
	uint8_t tj = (wolfi->pos.j+0x100)>>9;
	debug_printf("Tile: %d, pos (%d, %d)\n",tile16, ti, tj);

	// MOUNTAIN ENTRANCES
	if (wolfi->orientation == E_UP && (
		tile16==TILE_DOOR_MOUNTAIN)) { // Dark places!
		
		
		 
		if (!state.has_lamp) {
			TRAMPOLINE_PAGE_C(wolfi_door_warp_enter);
			small_message("IT'S TOO DARK!");
			TRAMPOLINE_PAGE_C(wolfi_door_warp_exit);
		} else if (ti==17 && tj==89) { // Mountain entrance
			door_warp_to(11,89);
		} else if (ti==11 && tj==89) { // Mountain entrance complement
			door_warp_to(17,89);
		} else if (ti==6 && tj==63) { // Mountain door by the stairs
			door_warp_to(6,56);
		} else if (ti==6 && tj==56) { // Mountain door ledge east
			door_warp_to(6,63);
		} else if (ti==6 && tj==50) { // Mountain door ledge west
			// CAVE
		} else if (ti==11 && tj==53) { // Mountain door to the top
			door_warp_to(2,53);
		} else if (ti==2 && tj==53) { // Mountain door top tower west
			door_warp_to(11,53);
		} else if (ti==2 && tj==88) { // Mountain door top tower east
			door_warp_to(6,88);
		} else if (ti==6 && tj==88) { // Mountain door under tower east
			door_warp_to(2,88);
		}
	}
		
	if (wolfi->orientation == E_UP && (
		tile16==TILE_WELL)) { // Dark places!
		if (ti==56 && tj==4) { // Well by the ghosts west
			well_warp_to(55,8);
		} else if (ti==55 && tj==8) { // Well by the ghosts east
			well_warp_to(56,4);		
		}
	}
	
	if (wolfi->orientation == E_UP && (
		tile16==TILE_HOLE_STAIRS_SAND_LEFT || tile16==TILE_HOLE_STAIRS_SAND_RIGHT)) {
		if (ti==32 && (tj==78 || tj==79)) { // Secret hole
			hole_warp_to(39,114);
		}
	}
	
	if (wolfi->orientation == E_UP && (
		tile16==TILE_HOLE_STAIRS_GRASS_LEFT || tile16==TILE_HOLE_STAIRS_GRASS_RIGHT)) {

		if (ti==39 && (tj==114 || tj==115)) { // Hole by the island
			hole_warp_to(32,78);
			
		} else if (ti==28 && (tj==2 || tj==3)) { // Hole by the islands southwest
			hole_warp_to(15,2);
		} else if (ti==15 && (tj==2 || tj==3)) { // Hole by the islands northwest
			hole_warp_to(28,2);
		} else if (ti==23 && (tj==12 || tj==13)) { // Hole by the islands center
			hole_warp_to(16,28);
		} else if (ti==16 && (tj==28 || tj==29)) { // Hole by the islands east
			hole_warp_to(23,12);
		}
	}

	// ROCKS HURT
	{

		uint16_t tpi = wolfi->pos.i + 14*32;
		uint16_t tpj1 = wolfi->pos.j + 4*32;
		uint16_t tpj2 = wolfi->pos.j + 11*32;

		uint8_t tile16Feet1 =  overworld_get_tile16(tpi, tpj1);
		uint8_t tile16Feet2 =  overworld_get_tile16(tpi, tpj2);
	//	debug_printf("TileFeet: %d %d, pos (%d, %d), flags %d\n",tile16Feet1, tile16Feet2, ti, tj, flags);

		if (tile16Feet1==TILE_ROCKS_SAND || tile16Feet1==TILE_ROCKS_GRAVE || tile16Feet1==TILE_ROCKS_GRASS ||
			tile16Feet2==TILE_ROCKS_SAND || tile16Feet2==TILE_ROCKS_GRAVE || tile16Feet2==TILE_ROCKS_GRASS ) {
			
			if (!state.has_boots) {
				small_message("THESE ROCKS\nHURT MY FEET!");
				//wolfi->pos = tmp.old_pos;
				// TODO: ROCKS
			}
		}
	}


	// TOWN ENTRANCES
	if (wolfi->orientation == E_UP && (
		tile16==TILE_DOOR_TOWN_BROWN || tile16==TILE_DOOR_TOWN_GRAY)) {
	
		TRAMPOLINE_PAGE_C(wolfi_in_town_door);
	}
	

	// INFO BOARDS
	if (wolfi->orientation == E_UP && (
		tile16==TILE_INFO_BOARD_GRASS ||
		tile16==TILE_INFO_BOARD_SAND)) {
	
		TRAMPOLINE_PAGE_C(wolfi_reads_info_boards);
	}
	
}
