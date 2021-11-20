#include "Tablero.h"

void Tablero::reservarMemoria(int diff)
{
    if (diff >= 0 && diff <= 3){
        liberar();
        switch (diff)
        {
        case 0:
            columnas = filas = EASY;
            n_bombas = EASY_B;
            break;
        case 1:
            columnas = filas = NORMAL;
            n_bombas = NORMAL_B;
            break;
        case 2:
            columnas = HARD;
            filas = NORMAL;
            n_bombas = HARD_B;
            break;
        }
        descubiertas = 0;

        oculto = new char* [filas];
        for (int i = 0; i < filas; i++)
            oculto[i] = new char[columnas];

        visible = new bool* [filas];
        for (int i = 0; i < filas; i++)
            visible[i] = new bool[columnas];

        //Ahora la inicializamos a un valor por defecto, '0' y 0.
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                oculto[i][j] = '0';
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                visible[i][j] = false;
    }
    else
    {
        oculto = nullptr;
        visible = nullptr;
        filas = columnas = descubiertas = n_bombas = 0;
    }
}

void Tablero::liberar()
{
    if (oculto != nullptr)
    {
        for (int i = 0; i < filas; i++)
            delete[] oculto[i];
        delete[] oculto;
    }

    if (visible != nullptr)
    {
        for (int i = 0; i < filas; i++)
            delete[] visible[i];
        delete[] visible;
    }

    oculto = nullptr; 
    visible = nullptr;
}

Tablero::Tablero(int diff)
{
    oculto = nullptr;
    visible = nullptr;
    reservarMemoria(diff);
}

Tablero::~Tablero()
{
    liberar();
    filas = columnas = descubiertas = n_bombas = 0;
}

void Tablero::rellenaBombas(int fila_inicial, int columna_inicial){

    int bombas_colocadas = 0;
    srand(time(NULL));
    while (bombas_colocadas < n_bombas){
        int f = rand() % filas;
        int c = rand() % columnas;
        bool fila_valida = f != fila_inicial - 1 && f != fila_inicial && f != fila_inicial + 1;
        bool columna_valida = c != columna_inicial - 1 && c != columna_inicial && c != columna_inicial + 1;

        if (fila_valida && columna_valida && oculto[f][c] != 'X') {
            oculto[f][c] = 'X';
            calcularBombas(f, c);
            bombas_colocadas++;
        }
        else {
            continue;
        }


    }
}

void Tablero::calcularBombas(int f, int c)
{
    for (int i = f - 1; i <= f + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if ((i >= 0 && i < filas) && (j >= 0 && j < columnas)) {
                if (oculto[i][j] != 'X') {
                    oculto[i][j]++;
                }
            }
        }
    }
}


void Tablero::mostrarTableroOculto() const {

    for (int i = 0; i < filas; i++) {
        if (i == 0) {
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
            std::cout << "\n\n";
        }
        for (int j = 0; j < columnas; j++) {
            if (j == 0)
                std::cout << "[" << i << "]\t";
            if (visible[i][j])
                std::cout << "[" << oculto[i][j] << "]";
            else
                std::cout << "[ ]";
            if (j == columnas - 1) 
                std::cout << "\t[" << i << "]";
        }
        if (i == filas-1) {
            std::cout << "\n\n";
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
        }
        std::cout << std::endl;
    }
}

void Tablero::mostrarTableroVisible() const {

    for (int i = 0; i < filas; i++) {
        if (i == 0) {
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << k << " ";
            std::cout << "\n\n";
        }
        for (int j = 0; j < columnas; j++) {
            if (j == 0)
                std::cout << i << "\t";
            std::cout << oculto[i][j] << " ";

            if (j == columnas - 1)
                std::cout << "\t" << i;
        }
        if (i == filas - 1) {
            std::cout << "\n\n";
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << k << " ";
        }
        std::cout << std::endl;
    }
}

void Tablero::mostrarBombas() const
{
    for (int i = 0; i < filas; i++) {
        if (i == 0) {
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
            std::cout << "\n\n";
        }
        for (int j = 0; j < columnas; j++) {
            if (j == 0)
                std::cout << "[" << i << "]\t";
            if (oculto[i][j] == 'X')
                std::cout << "[" << oculto[i][j] << "]";
            else
                std::cout << "[ ]";

            if (j == columnas - 1)
                std::cout << "\t[" << i << "]";
        }
        if (i == filas - 1) {
            std::cout << "\n\n";
            std::cout << "\t";
            for (int k = 0; k < filas; k++)
                std::cout << "[" << k << "]";
        }
        std::cout << std::endl;
    }
}

bool Tablero::desvelarCasilla(int f, int c)
{
    if (oculto[f][c] != 'X'){
        hacerVisible(f,c);
        if (oculto[f][c] == '0')
            revelarCeros(f,c);
    }
    return oculto[f][c] != 'X';
}

void Tablero::colocarBandera(int f, int c)
{
    BuscaMinas aux(f,c);
    banderas.add(aux);
}

void Tablero::quitarBandera(int f, int c){
    BuscaMinas aux(f,c);
    if (banderas.estaEnLista(aux) != -1)
        banderas.eliminar(aux);
}

void Tablero::revelarCeros(int f, int c)
{
    static CasillaBuscaMinas visitados;
    BuscaMinas aux;
    for (int i=f-1; i <= f+1 && i >= 0 && i < filas; i++){
        for (int j=c-1; j <= c+1 && j>= 0 && j < columnas; j++){
            hacerVisible(i,j);
            aux.setX(i);
            aux.setY(j);
            if (oculto[i][j] == '0' && visitados.estaEnLista(aux) == -1) {
                visitados.add(aux);
                revelarCeros(i, j);
            }
            
        }
    }
    
}

bool Tablero::haGanado()
{
    if (descubiertas == filas * columnas - n_bombas)
        return true;
    else
        return false;
}
void Tablero::hacerVisible(int f, int c){
    if (!visible[f][c]){
        visible[f][c] = true;
        descubiertas++;
    }
}