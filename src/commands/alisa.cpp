#include "alisa.h"



void hate_alisa(const dpp::slashcommand_t &event) 
{
    event.reply("I hate Alisa Kujou");
}

dpp::slashcommand register_alisa(dpp::snowflake bot_id) {
    return dpp::slashcommand("alisa", "Ew Alisa", bot_id);
}

