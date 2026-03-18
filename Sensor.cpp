#include <iostream>
#include <string>

using namespace std;

class SensorNivel {
private:
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

public:
    // Construtor simples (delegando)
    explicit SensorNivel(string novaTag)
        : SensorNivel(novaTag, 0.0, 0.0, 0.0) {}

    // Construtor principal
    SensorNivel(string novaTag, double novoMinimo, double novoMaximo, double novoValorAtual)
        : tag(novaTag), minimo(novoMinimo), maximo(novoMaximo), valorAtual(novoValorAtual) {}

    void exibirResumo() const {
        cout << "[SensorNivel] " << tag
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};

class BombaTeste {
private:
    string tag;
    double velocidade;

public:
    // Construtor simples (delegando)
    explicit BombaTeste(string novaTag)
        : BombaTeste(novaTag, 0.0) {}

    // Construtor principal
    BombaTeste(string novaTag, double novaVelocidade)
        : tag(novaTag), velocidade(novaVelocidade) {}

    void exibirResumo() const {
        cout << "[Bomba] " << tag
             << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque {
private:
    string tag;
    double setpoint;
    double kp;

public:
    // Construtor simples (delegando)
    explicit ControladorTanque(string novaTag)
        : ControladorTanque(novaTag, 0.0, 0.0) {}

    // Construtor principal
    ControladorTanque(string novaTag, double novoSetpoint, double novoKp)
        : tag(novaTag), setpoint(novoSetpoint), kp(novoKp) {}

    void exibirResumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    SensorNivel sensor1("LT-610");
    SensorNivel sensor2("LT-611", 0.0, 3509.0, 2290.0);

    BombaTeste bomba1("PB-010");
    BombaTeste bomba2("PB-007", 37.6);

    ControladorTanque controlador1("LC-001");
    ControladorTanque controlador2("LC-002", 20.0, 10.0);

    sensor1.exibirResumo();
    sensor2.exibirResumo();
    bomba1.exibirResumo();
    bomba2.exibirResumo();
    controlador1.exibirResumo();
    controlador2.exibirResumo();

    return 0;
}