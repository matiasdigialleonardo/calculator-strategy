#include <iostream>
#include <functional>
#include <vector>

// Strategy Interface
class Operation {
public:
    virtual int execute(int a, int b) = 0;
};

// Concrete Strategy: Suma
class Addition : public Operation {
public:
    int execute(int a, int b) override {
        return a + b;
    }
};

// Concrete Strategy: Resta
class Subtraction : public Operation {
public:
    int execute(int a, int b) override {
        return a - b;
    }
};

// Concrete Strategy: Multiplicación
class Multiplication : public Operation {
public:
    int execute(int a, int b) override {
        return a * b;
    }
};

// Context
class Calculator {
private:
    Operation* operation;

public:
    void setOperation(Operation* op) {
        operation = op;
    }

    int calculate(int a, int b) {
        if (operation != nullptr) {
            return operation->execute(a, b);
        }
        return 0;
    }
};

int main() {
    Calculator calculator;
    Addition add;
    Subtraction subtract;
    Multiplication multiply;

    int choice;

    do {
        std::cout << "Seleccione una operacion:" << std::endl;
        std::cout << "1. Suma" << std::endl;
        std::cout << "2. Resta" << std::endl;
        std::cout << "3. Multiplicacion" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cin >> choice;

        int a, b;

        switch (choice) {
            case 1:
                calculator.setOperation(&add);
                break;
            case 2:
                calculator.setOperation(&subtract);
                break;
            case 3:
                calculator.setOperation(&multiply);
                break;
            case 0:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida. Intentelo de nuevo." << std::endl;
                continue;  // Vuelve al inicio del bucle
        }

        if (choice != 0) {
            std::cout << "Ingrese el primer numero: ";
            std::cin >> a;
            std::cout << "Ingrese el segundo numero: ";
            std::cin >> b;
            std::cout << "Resultado: " << calculator.calculate(a, b) << std::endl;
        }
    } while (choice != 0);

    return 0;
}