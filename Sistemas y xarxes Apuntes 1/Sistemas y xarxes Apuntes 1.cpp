#include <iostream>
//#include "1TutorialThreads/ThreadTutorial.h"
#include "Utils/ConsoleControl.h"
#include <functional>
#include <string>
#include <list>

typedef std::function<int(int, int)> SumaFunction;
//En la linea siguiente se le pone un nombre a la lista de listas de ints, para que se mas legible
//typedef std::list<std::list<int>> listaDeListasDeInts;

void TestLambdasMolonas(std::function<int(int, int)> funcionMolona)
{
    std::cout << "Voy a ejecutar una funcion que estaba en una variable" << std::endl;

    int number = funcionMolona(5,7);

    std::cout << "Ya la he ejecutado" << std::endl;
}

//Las siguientes funciones muestran una forma de optimizar la visualizacion del codigo
/*
void Test1(listaDeListasDeInts listaDeListas)
{
    
}

void Test2(listaDeListasDeInts listaDeListas)
{

}

void Test3(listaDeListasDeInts listaDeListas)
{

}
*/

int main()
{
    //ThreadTutorialTest();
    //CC::SetColor(CC::WHITE, CC::CYAN);

    std::string name = "Tagopi";

    //std::list<std::list<int>> listaDeListas;

    std::function<int(int, int)> funcionQueHaceCosasPeroEsUnaVariable = [name](int a, int b)
        {
            std::cout << "Esto no se como pero funciona y me dice mi nombre --> " << name << std::endl;
            return a + b;
        };

    TestLambdasMolonas(funcionQueHaceCosasPeroEsUnaVariable);
}
