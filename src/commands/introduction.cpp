#include "introduction.h"

void introduce(const dpp::slashcommand_t& event) {
    const std::string SALT_EMOJI = "<:salt:1493267995139637398>";
    std::string intro_message = "Hello! I'm Salt!" + SALT_EMOJI + " from the hit rhythm game Maimai!";
    event.reply(intro_message);
}

dpp::slashcommand register_introduce(dpp::snowflake bot_id) {
    return dpp::slashcommand("introduction", "Salt's introduction", bot_id);
}
