#ifndef TANQUE_H
#define TANQUE_H

class Tanque {
private:
    float* capacidadRegular; // Arreglos dinámicos
    float* capacidadPremium;
    float* capacidadExtra;

public:
    Tanque();
    Tanque(float regular[], float premium[], float extra[]);
    ~Tanque(); // Destructor para liberar memoria
    float getCapacidadRegular() const;
    float getCapacidadPremium() const;
    float getCapacidadExtra() const;
    void setCapacidadRegular(float regular[]);
    void setCapacidadPremium(float premium[]);
    void setCapacidadExtra(float extra[]);
    float disponibleTanque() const;
};


#endif // TANQUE_H
