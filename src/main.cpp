#include "Tamagochi.h"
#include "Notifier.h"
#include "CommandHandler.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Tamagochi tamagochi;
    Notifier notifier;

    std::cout << "¡Bienvenido al tamagotchi! Usa los comandos 'alimentar', 'jugar', 'estado' y 'salir'.\n";

    while (true) {
        std::string command;
        std::cout << "\nComando: ";
        std::cin >> command;

        if (command == "alimentar") {
            tamagochi.feed();
            std::cout << "Has alimentado al tamagotchi.\n";
        } else if (command == "jugar") {
            tamagochi.play();
            std::cout << "Has jugado con el tamagotchi.\n";
        } else if (command == "estado") {
            tamagochi.printStatus();
        } else if (command == "salir") {
            std::cout << "Guardando y saliendo...\n";
            tamagochi.saveState(); // Guarda el estado antes de salir
            break;
        } else {
            std::cout << "Comando no reconocido.\n";
        }

        // Actualizar estado periódicamente
        tamagochi.update();
        if (tamagochi.needsAttention()) {
            notifier.sendNotification("¡Tu tamagotchi necesita atención!");
        }

        // Pausa para simular el paso del tiempo (60 segundos en segundos reales)
        std::this_thread::sleep_for(std::chrono::seconds(10)); // Reducido a 10s para pruebas
    }

    return 0;
}
