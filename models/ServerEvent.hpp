#ifndef EVENT_HPP
#define EVENT_HPP
#include <string>

class ServerEvent {
  private:
    std::string name;

  public:
    ServerEvent(std::string name);
    ~ServerEvent();
    std::string getName() const { return this->name; }
    void setName(std::string value) { this->name = value; }
};

#endif // EVENT_HPP
