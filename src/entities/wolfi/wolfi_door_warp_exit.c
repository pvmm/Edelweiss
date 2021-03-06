#include <common.h>

#include <entities/wolfi/entity_wolfi_sprite.h>
USING_MODULE(entity_wolfi_sprite, PAGE_D);

void wolfi_door_warp_exit() {

	state.entities[0].orientation = E_DOWN;
	sprites[0].spriteInfo = (state.entities[0].animation_counter & 0x04? &wolfi_2_0 : &wolfi_2_1);
	sprites[0].enabled = true;

	for (uint8_t k=0; k<16; k++) {
		state.entities[0].pos.i += 16;
		sprites[0].pos.i = state.entities[0].pos.i;
		wait_frame();
		wait_frame();
	}
}
