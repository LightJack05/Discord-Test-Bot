#include "databaseInteraction.hpp"
#include <memory>
#include <vector>

std::vector<std::shared_ptr<ServerEvent>> events;

void SaveEvent(std::shared_ptr<ServerEvent> event) { events.push_back(event); }
void RemoveEvent(std::string name) {
    for (int i = 0; i < events.size(); i++) {
        if (events[i]->getName() == name) {
            events.erase(events.begin() + i);
        }
    }
}
