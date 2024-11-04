#ifndef TAMAGOCHI_H
#define TAMAGOCHI_H

class Tamagochi {
public:
    Tamagochi();
    void feed();
    void play();
    void update();
    void printStatus();
    bool needsAttention() const;
    void saveState() const; // Declaración del nuevo método

private:
    int hunger;
    int happiness;
    int health;
    void adjustHealth();
};

#endif // TAMAGOCHI_H
