#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();

int main()
{
	string playerName;
	int balance;
	int bettingAmount;
	int guess;
	int dice;
	char choice;
	srand(time(0));
	cout << "\n\t\t========WELCOME TO THE CASINO==========\n\n";
	cout << "\n\nWhat is your name: ";
	getline(cin, playerName);
	cout << "\n\nEnter the starting balance to play: $";
	cin >> balance;
	
	do 
	{
		system("cls");
		rules();
		cout << "\n\nYour current balance is $ " << balance << "\n";
		
		do 
		{
			cout << "Hey, " << playerName<<", enter amount to bet: $";
			cin >> bettingAmount;
			if(bettingAmount > balance)
				cout << "Betting amount can't be more than current balance!\n"
					<<"\nRe-Enter Balance\n ";
		} while(bettingAmount > balance);
		
		do 
		{
			cout << "Guess any number between 1 and 10: ";
			cin >> guess;
			if(guess <=0 || guess > 10)
				cout << "\n Number should be between 1 and 10\n"
					<<"Re-enter number: \n";
		}while(guess <=0 || guess > 10);
	
		dice = rand()%10 + 1;

		if(dice == guess)
		{
			cout << "\n\nYou are in Luck you have won $ " << bettingAmount * 10;
			balance = balance + bettingAmount * 10;
		}
		else
		{
			cout << "\n\nOops, better luck next time!! You lost $ " << bettingAmount <<"\n";
			balance = balance - bettingAmount;
		}
		cout << "\nThe winning number was: " << dice <<"\n";
		cout << "\n"<<playerName<<", You have a balance of $ " << balance << "\n";
		if (balance <= 0)
		{
			cout << "\nYou have no money left to play ";
			break;
		}
		cout << "\n\nDo you want to play again? (y/n)? ";
		cin >> choice;
	}while(choice == 'Y' || choice =='y');
	cout << "\n\n\n";
	cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";
	return 0;
}

void rules()
{
	system("cls");
	cout << "\t\t============CASINO RULES===========\n";
	cout << "\t1. Choose a number between 1 and 10\n";
	cout << "\t2. Winner gets 10 times their bet.\n";
	cout << "\t3. Wrong guesses lose their bets.\n\n";
}
