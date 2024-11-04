#include "CommandHandler.h"
#include "Tamagochi.h"
#include <iostream>
#include <string>

void startCommandListener(Tamagochi &tamagochi) {
    std::string command;
    
    while (true) {
        std::cout << "Comando (alimentar, jugar, estado, salir): ";
        std::cin >> command;
        
        if (command == "alimentar") {
            tamagochi.feed();
            std::cout << "Has alimentado al tamagotchi.\n";
        }
        else if (command == "jugar") {
            tamagochi.play();
            std::cout << "Has jugado con el tamagotchi.\n";
        }
        else if (command == "estado") {
            tamagochi.printStatus();
        }
        else if (command == "salir") {
            std::cout << "Saliendo del programa...\n";
            break;
        }
        else {
            std::cout << "Comando no reconocido. Intenta nuevamente.\n";
        }
    }
}