#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#pragma region Functions Declaration Header

void PrintElapsedTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName);
void Count(unsigned long long maxCounter, std::string threadName);

void Example01();
void Example02();
void Example03();
void Example04();
void Example05();
void Example06();
void Example07();

#pragma endregion

#pragma region Global Variables

std::chrono::system_clock::time_point startDate;


#pragma endregion

void ThreadTutorialTest()
{

	startDate = std::chrono::system_clock::now();

	int exampleUsed = 1;//Change this variable for use diferents examples

	switch (exampleUsed)
	{
	case 1:
		Example01();
		break;
	case 2:
		Example02();
		break;
	case 3:
		Example03();
		break;
	case 4:
		Example04();
		break;
	case 5:
		Example05();
		break;
	case 6:
		Example06();
		break;
	case 7:
		Example07();
		break;
	default:
		break;
	}

	std::cout << "Example 0" << exampleUsed << " finished" << std::endl;
	std::string text = " ";
	std::getline(std::cin, text);

}

void PrintElapsedTime(
	std::chrono::system_clock::time_point start,
	std::chrono::system_clock::time_point end,
	std::string threadName)
{
	std::chrono::duration<double> elapsedTime = end - start;

	std::cout << "Thread: " << threadName << " - Elapsed Time: " << elapsedTime.count() << " seconds" << std::endl;
}

void Count(unsigned long long maxCounter, std::string threadName)
{

	for (unsigned long long i = 0; i < maxCounter; i++)
	{

	}

	std::chrono::system_clock::time_point endDate = std::chrono::system_clock::now();
	PrintElapsedTime(startDate, endDate, threadName);

}

void Example01()
{

	unsigned long long totalCount = 1000000000ull;
	std::thread* Couter1 = new std::thread(Count, totalCount, "1");
	std::thread* Couter2 = new std::thread(Count, totalCount, "2");
	std::thread* Couter3 = new std::thread(Count, totalCount, "3");

	Couter1->join();
	Couter2->join();
	Couter3->join();//En este caso el codigo se parara hasta que no esten los 3 ejecutados.
/*
	std::thread* Couter1 = new std::thread(Count, totalCount, "1");
	Couter1->join();
	std::thread* Couter2 = new std::thread(Count, totalCount, "2");
	Couter2->join();
	std::thread* Couter3 = new std::thread(Count, totalCount, "3");
	Couter3->join();//Sin embargo, en este el codigo se parara hasta que el primero no este listo, luego creara el segundo y asi de forma consecutiva.
	
*/

	Count(totalCount, "0");
}

void Example02()
{



}

void Example03()
{



}

void Example04()
{



}

void Example05()
{



}

void Example06()
{



}

void Example07()
{



}