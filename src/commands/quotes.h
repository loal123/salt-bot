#pragma once
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <dpp/snowflake.h>

void say_quote(const dpp::slashcommand_t &event);

dpp::slashcommand register_say_quote(dpp::snowflake bot_id);




