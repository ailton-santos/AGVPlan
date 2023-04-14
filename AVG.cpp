#include <iostream>
#include <string>

using namespace std;

// Classe para o AGV
class AGV {
    private:
        int posX; // posição X do AGV
        int posY; // posição Y do AGV
        int direction; // direção do AGV (0 = para cima, 1 = para a direita, 2 = para baixo, 3 = para a esquerda)

    public:
        // Construtor
        AGV() {
            posX = 0;
            posY = 0;
            direction = 0;
        }

        // Função para mover o AGV para frente
        void moveForward() {
            switch (direction) {
                case 0:
                    posY--;
                    break;
                case 1:
                    posX++;
                    break;
                case 2:
                    posY++;
                    break;
                case 3:
                    posX--;
                    break;
            }
        }

        // Função para mover o AGV para trás
        void moveBackward() {
            switch (direction) {
                case 0:
                    posY++;
                    break;
                case 1:
                    posX--;
                    break;
                case 2:
                    posY--;
                    break;
                case 3:
                    posX++;
                    break;
            }
        }

        // Função para girar o AGV para a esquerda
        void turnLeft() {
            direction = (direction + 3) % 4;
        }

        // Função para girar o AGV para a direita
        void turnRight() {
            direction = (direction + 1) % 4;
        }

        // Função para obter a posição atual do AGV
        string getPosition() {
            string position = "(" + to_string(posX) + "," + to_string(posY) + ")";
            return position;
        }
};

// Função principal
int main() {
    AGV agv; // Cria um objeto AGV

    // Loop para receber os comandos do usuário
    while (true) {
        // Mostra a posição atual do AGV
        cout << "Posição atual: " << agv.getPosition() << endl;

        // Mostra as opções de comandos
        cout << "Comandos disponíveis:" << endl;
        cout << "  w: mover para frente" << endl;
        cout << "  s: mover para trás" << endl;
        cout << "  a: girar para a esquerda" << endl;
        cout << "  d: girar para a direita" << endl;
        cout << "  q: sair" << endl;

        // Recebe o comando do usuário
        char command;
        cout << "Digite o comando: ";
        cin >> command;

        // Executa o comando
        switch (command) {
            case 'w':
                agv.moveForward();
                break;
            case 's':
                agv.moveBackward();
                break;
            case 'a':
                agv.turnLeft();
                break;
            case 'd':
                agv.turnRight();
                break;
            case 'q':
                return 0;
            default:
                cout << "Comando inválido!" << endl;
        }
    }
    return 
