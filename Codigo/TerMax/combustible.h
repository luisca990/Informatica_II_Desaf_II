#ifndef COMBUSTIBLE_H
#define COMBUSTIBLE_H


#include <string>

class Combustible {
private:
    std::string tipoCombustible;
    float precioCombustible;

public:
    Combustible(std::string tipo, float precio);
    std::string getTipoCombustible() const;
    float getPrecioCombustible() const;
    void setTipoCombustible(std::string tipo);
    void setPrecioCombustible(float precio);
};


#endif // COMBUSTIBLE_H
