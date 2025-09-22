#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <list>
#include <mutex>

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
std::mutex* consoleMutex;

#pragma endregion

void ThreadTutorialTest()
{
	consoleMutex = new std::mutex();

	startDate = std::chrono::system_clock::now();

	int exampleUsed = 3;//Change this variable for use diferents examples

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

	consoleMutex->lock();

	std::cout << "Thread: " << threadName << " - Elapsed Time: " << elapsedTime.count() << " seconds" << std::endl;

	consoleMutex->unlock();
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
	Couter3->join(); 
	
	//En este caso el codigo se parara hasta que no esten los 3 ejecutados.
/*
	std::thread* Couter1 = new std::thread(Count, totalCount, "1");
	Couter1->join();
	std::thread* Couter2 = new std::thread(Count, totalCount, "2");
	Couter2->join();
	std::thread* Couter3 = new std::thread(Count, totalCount, "3");
	Couter3->join();
	
	//Sin embargo, en este el codigo se parara hasta que el primero no este listo, luego creara el segundo y asi de forma consecutiva.
	
*/

	Count(totalCount, "0");
}

void Example02()
{
	unsigned long long totalCount = 1000000000ull;

	std::thread* Couter1 = new std::thread(Count, totalCount, "1");

	Couter1->join();

	std::thread* Couter2 = new std::thread(Count, totalCount, "2");
	std::thread* Couter3 = new std::thread(Count, totalCount, "3");

	Couter2->join();
	Couter3->join();

	Count(totalCount, "0");
}

void Example03()
{
	unsigned long long totalCount = 1000000000ull;

	std::thread* Couter1 = new std::thread(Count, totalCount, "1");
	std::thread* Couter2 = new std::thread(Count, totalCount, "2");
	std::thread* Couter3 = new std::thread(Count, totalCount, "3");

	Couter1->detach();
	Couter2->detach();
	Couter3->detach();

	Count(totalCount, "0");

}

void Example04()
{
	std::list<std::thread*>* threads = new std::list<std::thread*>();

	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i < 3; i++)
	{
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
		counterThread->join();
	}

	Count(totalCount, "0");
}

void Example05()
{
	std::list<std::thread*>* threads = new std::list<std::thread*>();

	unsigned long long totalCount = 1000000000ull;

	for (int i = 0; i < 3; i++)
	{
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
		counterThread->detach();
	}

	Count(totalCount, "0");
}

void Example06()
{
	unsigned int maxThreads = std::thread::hardware_concurrency();
	std::cout << maxThreads << " concurrent Threads are supported" << std::endl;

	int extraThreads = 0;

	unsigned long long totalCount = 1000000000ull;

	unsigned int totalThreads = maxThreads + extraThreads;

	std::list<std::thread*>* threads = new std::list<std::thread*>();

	for (int i = 0; i < totalThreads; i++)
	{
		std::thread* counterThread = new std::thread(Count, totalCount, std::to_string(i + 1));
		threads->push_back(counterThread);
	}

	for (std::thread* t : *threads)
	{
		t->join(); 
	}

	Count(totalCount, "0");
}

class ThreadTester
{
public:
	ThreadTester() {}
	~ThreadTester() {}

	void Example07();
private:

	void TestFunction(unsigned long long testInt);

};

void ThreadTester::Example07()
{
	std::thread* testThread = new std::thread(&ThreadTester::TestFunction, this, 14ull);
	testThread->join();
}

void ThreadTester::TestFunction(unsigned long long testInt)
{
	std::cout << "Number is: " << testInt << std::endl;
}

void Example07()
{
	ThreadTester* threadTester = new ThreadTester();
	threadTester->Example07();

}