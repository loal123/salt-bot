#include <dpp/dpp.h>
#include <dpp/intents.h>
#include <iostream>
#include <cstdlib>

#include "commands/registry.h"

int main() {
    const char* token_env = std::getenv("DISCORD_TOKEN");
    if (!token_env) {
        std::cerr << "Error: DISCORD_TOKEN not set!" << std:: endl;
        return 1;
    }

    dpp::cluster bot(token_env, dpp::i_default_intents);
    bot.on_log(dpp::utility::cout_logger());
    std::map<std::string, std::function<void(const dpp::slashcommand_t&)>> command_map;

    command_map["ping"] = run_ping;
    command_map["alisa"] = hate_alisa;
    command_map["quote"] = say_quote; 
    // The Event Listener
    bot.on_slashcommand([&command_map](const dpp::slashcommand_t& event) {
            std::string cmd_name = event.command.get_command_name();

            auto it = command_map.find(cmd_name);
            if (it != command_map.end()) {
                it->second(event);
            }
            else {
                event.reply("Unknown Command!");
            }



    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
        std::vector<dpp::slashcommand> commands_to_register = {
            register_ping(bot.me.id),
            register_alisa(bot.me.id),
            register_say_quote(bot.me.id),
        };
        bot.global_bulk_command_create(commands_to_register);
            
        }
     });

    bot.start(dpp::st_wait);
    return 0;

}
