#ifndef DATABASEINTERACTION_HPP
#define DATABASEINTERACTION_HPP

#include "../models/ServerEvent.hpp"
#include <memory>
#include <string>
#include <vector>

void SaveEvent(std::shared_ptr<ServerEvent> event);
void RemoveEvent(std::string name);

#endif // DATABASEINTERACTION_HPP
