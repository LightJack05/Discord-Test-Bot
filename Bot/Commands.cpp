#include "Commands.hpp"
#include "../models/ServerEvent.hpp"
#include "../datamanagement/databaseInteraction.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
using namespace std;

void CreateServerEventHandler(const dpp::slashcommand_t &event) {
    string eventName = get<string>(event.get_parameter("name"));
    shared_ptr<ServerEvent> newEvent = make_shared<ServerEvent>(eventName);
    SaveEvent(newEvent);
    event.reply("Created event " + eventName);
    cout << eventName << endl;
}
