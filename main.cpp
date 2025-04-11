#include "Bot/CommandRegistration.hpp"
#include "Bot/Commands.hpp"
#include "authentication/credentials.hpp"
#include <dpp/appcommand.h>
#include <dpp/cluster.h>
#include <dpp/dispatcher.h>
#include <dpp/dpp.h>
#include <dpp/intents.h>
#include <dpp/once.h>
#include <event2/event_struct.h>
#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char *argv[]) {
    dpp::cluster bot(BotToken, dpp::i_default_intents | dpp::i_message_content);
    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t &event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
            cout << "Ping request from: "
                 << event.command.get_issuing_user().global_name << endl;
        }
        else if(event.command.get_command_name() == "newevent"){
            CreateServerEventHandler(event);
        }
    });

    bot.on_message_create([](const dpp::message_create_t &event) {
        cout << event.msg.author.global_name << ": " << event.msg.content
             << endl;
    });

    bot.on_ready([&bot](const dpp::ready_t &event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            RegisterBotCommands(bot);
        }
    });

    bot.start(dpp::st_wait);
    return 0;
}
