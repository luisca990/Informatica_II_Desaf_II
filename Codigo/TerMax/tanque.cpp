#include "tanque.h"

Tanque::Tanque(float regular[], float premium[], float extra[]) {
    capacidadRegular = new float[3];
    capacidadPremium = new float[3];
    capacidadExtra = new float[3];

    for (int i = 0; i < 3; ++i) {
        capacidadRegular[i] = regular[i];
        capacidadPremium[i] = premium[i];
        capacidadExtra[i] = extra[i];
    }
}

Tanque::~Tanque() {
    delete[] capacidadRegular;
    delete[] capacidadPremium;
    delete[] capacidadExtra;
}

float Tanque::getCapacidadRegular() const {
    float total = 0;
    for (int i = 0; i < 3; ++i) {
        total += capacidadRegular[i];
    }
    return total;
}

float Tanque::getCapacidadPremium() const {
    float total = 0;
    for (int i = 0; i < 3; ++i) {
        total += capacidadPremium[i];
    }
    return total;
}

float Tanque::getCapacidadExtra() const {
    float total = 0;
    for (int i = 0; i < 3; ++i) {
        total += capacidadExtra[i];
    }
    return total;
}

void Tanque::setCapacidadRegular(float regular[]) {
    for (int i = 0; i < 3; ++i) {
        capacidadRegular[i] = regular[i];
    }
}

void Tanque::setCapacidadPremium(float premium[]) {
    for (int i = 0; i < 3; ++i) {
        capacidadPremium[i] = premium[i];
    }
}

void Tanque::setCapacidadExtra(float extra[]) {
    for (int i = 0; i < 3; ++i) {
        capacidadExtra[i] = extra[i];
    }
}

float Tanque::disponibleTanque() const {
    return getCapacidadRegular() + getCapacidadPremium() + getCapacidadExtra();
}

