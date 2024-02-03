// TestC++_v2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int playerNumber;
	cout << "Enter your Number(1-10): ";
	cin >> playerNumber;
	srand(static_cast<unsigned int>(time(0)));
	int answerComputer;
	while (true)
	{
		answerComputer = rand() % 10 + 1;
		if (answerComputer == playerNumber)
		{
			cout << "your number(I'm win!) " << answerComputer << endl;
			break;
		}
		cout << "your number(No?) " << answerComputer << endl;
	}
	return 0;
}