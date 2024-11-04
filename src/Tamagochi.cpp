#include "Tamagochi.h"
#include <fstream>
#include <iostream>

// Constructor que carga el estado desde el archivo (si existe)
Tamagochi::Tamagochi() {
    std::ifstream saveFile("tamagochi_save.txt");
    if (saveFile.is_open()) {
        saveFile >> hunger >> happiness >> health;
        saveFile.close();
        std::cout << "Estado cargado correctamente desde el archivo.\n";
    } else {
        // Valores iniciales por defecto si no se encuentra archivo
        hunger = 50;
        happiness = 50;
        health = 100;
        std::cout << "No se encontró archivo de guardado, inicializando con valores predeterminados.\n";
    }
}

// Alimentar al tamagotchi
void Tamagochi::feed() {
    hunger -= 20;
    if (hunger < 0) hunger = 0; // Evita que baje de 0
    adjustHealth();
    saveState(); // Guarda el estado tras alimentar
    std::cout << "¡Has alimentado a tu tamagotchi! Hambre: " << hunger << std::endl;
}

// Jugar con el tamagotchi
void Tamagochi::play() {
    happiness += 15;
    if (happiness > 100) happiness = 100; // Evita que supere 100
    hunger += 10; // Jugar incrementa un poco el hambre
    adjustHealth();
    saveState(); // Guarda el estado tras jugar
    std::cout << "¡Has jugado con tu tamagotchi! Felicidad: " << happiness << std::endl;
}

// Actualiza el estado del tamagotchi
void Tamagochi::update() {
    // Incrementa el hambre y reduce la felicidad con el tiempo
    hunger += 5;
    happiness -= 5;

    // Controla límites de valores
    if (hunger > 100) hunger = 100;
    if (happiness < 0) happiness = 0;

    adjustHealth(); // Ajusta salud según el estado actual
    saveState(); // Guarda el estado tras la actualización
}

// Muestra el estado actual del tamagotchi
void Tamagochi::printStatus() {
    std::cout << "Estado del Tamagochi:\n";
    std::cout << "  Hambre: " << hunger << "\n";
    std::cout << "  Felicidad: " << happiness << "\n";
    std::cout << "  Salud: " << health << "\n";
}

// Revisa si el tamagotchi necesita atención
bool Tamagochi::needsAttention() const {
    return (hunger >= 80 || happiness <= 20 || health <= 30);
}

// Ajusta la salud basada en el hambre y la felicidad
void Tamagochi::adjustHealth() {
    if (hunger >= 80) health -= 10; // Mucha hambre reduce la salud
    if (happiness <= 20) health -= 10; // Baja felicidad también reduce salud
    if (hunger < 80 && happiness > 20) health += 5; // Recupera salud si está en buen estado

    // Controla límites de salud
    if (health > 100) health = 100;
    if (health < 0) health = 0;
}

// Guarda el estado actual en un archivo
void Tamagochi::saveState() const {
    std::ofstream saveFile("tamagochi_save.txt");
    if (saveFile.is_open()) {
        saveFile << hunger << " " << happiness << " " << health;
        saveFile.close();
        std::cout << "Estado guardado en archivo.\n";
    } else {
        std::cerr << "Error al guardar el estado.\n";
    }
}
