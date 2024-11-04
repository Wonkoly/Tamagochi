#include "Notifier.h"
#include <cstdlib>

void Notifier::sendNotification(const std::string &message) {
    std::string command = "notify-send 'Tamagotchi' '" + message + "'";
    system(command.c_str());
}
