#pragma once
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>

void run_ping(const dpp::slashcommand_t& event);

dpp::slashcommand register_ping(dpp::snowflake bot_id);
