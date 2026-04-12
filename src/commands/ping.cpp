#include "ping.h"

void run_ping(const dpp::slashcommand_t &event) {
    event.reply("Pong!");
}

dpp::slashcommand register_ping(dpp::snowflake bot_id) {
    return dpp::slashcommand("ping", "Check if the bot is responsive", bot_id);
}
