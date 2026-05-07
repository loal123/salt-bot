#include "alisa.h"



void hate_alisa(const dpp::slashcommand_t &event) 
{
    event.reply("I hate Alisa Kujou");
}

dpp::slashcommand register_alisa(dpp::snowflake bot_id) {
    dpp::slashcommand cmd("alisa", "Ew Alisa", bot_id);
     cmd.set_interaction_contexts({dpp::itc_guild, dpp::itc_bot_dm, dpp::itc_private_channel});
    return cmd;
}

