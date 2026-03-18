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
    /* A sobrecarga de construtores, nessa situação foi utilizada para permitir que diferentes objetos acessem apenas os 
    parâmetros necessários em certas situações. Dentro dessa classe, por exemplo, diferentes sensores podem ser controlados.*/
    
   explicit SensorNivel(string novaTag)
        : SensorNivel(novaTag, 0.0, 0.0, 0.0) {}

    
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
    
/* Dentro da classe de Bombas, essa sobrecarga de construtores tem intuito semelhante a contruída dentro da classe de sensores. Entretanto,
aqui tem como objetivo o controle de diferentes bombas com variáveis específicas. */
    explicit BombaTeste(string novaTag)
        : BombaTeste(novaTag, 0.0) {}

    
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
    /* Nesta última classe, a sobrecarga de construtores tem objetivo idêntico aos últimos dois. Outrossim, esse tem como intuito o
    controle de diferentes objetos, nesse caso, os controladores de tanque. */
    explicit ControladorTanque(string novaTag)
        : ControladorTanque(novaTag, 0.0, 0.0) {}

    
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