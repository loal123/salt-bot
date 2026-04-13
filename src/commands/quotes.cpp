#include "quotes.h"
#include <dpp/dpp.h>
#include <dpp/dispatcher.h>
#include <fstream> 
#include <random>
#include <vector>
#include <string> 
#include <iostream>


void say_quote(const dpp::slashcommand_t &event) {
    std::vector<std::string> quotes;
    std::string path = std::string(PROJECT_ROOT) + "/resources/quotes.txt";
    std::cerr << "Reading quotes from: " << path << std::endl;
    std::cerr << "Check if path exists? " << std::filesystem::exists(path) << std::endl;
    std::ifstream file(path);
    std::string quoteline;
    if (file.is_open()) 
    {
        while (std::getline(file,quoteline))
        {
            quotes.push_back(quoteline);
        }
    }
    int quotesize = quotes.size();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0,quotesize - 1);

    int index_chosen = distr(gen);
    std::string quote_chosen = quotes[index_chosen];
    event.reply(quote_chosen);



}

dpp::slashcommand register_say_quote(dpp::snowflake bot_id) {
    return dpp::slashcommand("Quote", "Outputs random inspirational quote", bot_id );
}

