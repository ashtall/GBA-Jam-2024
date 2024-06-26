#include "bn_core.h"
#include "bn_date.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_optional.h"
#include "bn_seed_random.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "bn_time.h"


#include "br_game.h"
#include "br_globals.h"

#include "common_variable_8x16_sprite_font.h"

int main() {
    bn::core::init();

    bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
    bn::string<24> str = "";

    bn::optional<bn::time> time = bn::time::current();
    int seed = time->hour() * 10000 + time->minute() * 100 + time->second();
    BN_LOG("SEED: ", seed);
    rrand.set_seed(seed);

    while (true) {
        // Check if RTC is enabled
        if (!bn::time::active()) {
        BN_LOG(bn::time::active());
        str = "RTC is not enabled";
        bn::vector<bn::sprite_ptr, 32> text_sprites;
        text_generator.generate(0, 0, str, text_sprites);
        bn::core::update();
        while (true) {
        }
        }

        game(text_generator);
        bn::core::update();
    }
}
