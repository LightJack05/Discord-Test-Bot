#include "CommandRegistration.hpp"
#include <dpp/appcommand.h>

void RegisterBotCommands(dpp::cluster &bot) {
    bot.global_command_create(
        dpp::slashcommand("ping", "Ping Pong Command!", bot.me.id));

    dpp::slashcommand registerServerEventCommand(
        "newevent", "Creates a new event", bot.me.id);
    registerServerEventCommand.add_option(dpp::command_option(
        dpp::co_string, "name", "The name of the event to create", true));
    bot.global_command_create(registerServerEventCommand);
}
