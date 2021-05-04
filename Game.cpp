#include "Game.h"
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <vector> // For vector class
#include "RoomInfo.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

void Game::createMap()
{
	// Map
	//								n
	//								^
	//								|
	//						w	<--ROOM-->  e
	//								|
	//								;
	//								s
	//
	//												 [B0 Kitchen]						 [D0 Backyard][Exit]
	//													 |											|
	//				 [Start]   [A1 Entrance]  <==> [B1 Living Room] <==> [C1 Dining Room] <==> [D1 Great Room]<==>[E1 Garage]
	//														|					 |
	//												 [B2 Bathroom]			[C2 Pantry]
	//
	//

	Monster* Mahnoor = new Monster(50, 5); // creating first monster
	Monster* Dora = new Monster(15, 4); // creating second monster
	Monster* Azra = new Monster(65,6); // creating 3rd monster

	Item* HalalBurger = new Item(0, 15); // creating item to increase hp
	Item* TrashCan = new Item(1, 1); // creating item to increase defense
	Item* PepperSpray = new Item(1, 2); // creating item to increase defense

	// Creating a map with 9 rooms, each connected without a cycle and one exit room and entrance.
	Room* A1 = new Room("Start Room", nullptr, nullptr, nullptr, nullptr, false);

	Room* B1 = new Room("Living Room", nullptr, A1, nullptr, nullptr, false);
	A1->setEastRoom(B1);

	Room* B0 = new Room("Kitchen", nullptr, nullptr, B1, nullptr, TrashCan);
	B1->setNorthRoom(B0);

	Room* B2 = new Room("Bathroom", nullptr, nullptr, nullptr, B1, Dora, PepperSpray);
	B1->setSouthRoom(B2);

	Room* C1 = new Room("Dining Room", B1, nullptr, nullptr, nullptr, Mahnoor);
	B1->setEastRoom(C1);
	C1->setWestRoom(B1);

	Room* C2 = new Room("Pantry", nullptr, nullptr, nullptr, C1, HalalBurger);
	C1->setSouthRoom(C2);

	Room* D1 = new Room("Great Room", C1, nullptr, nullptr, nullptr, false);
	C1->setEastRoom(D1);
	D1->setWestRoom(C1);

	Room* D0 = new Room("Backyard", nullptr, nullptr, nullptr, D1, true);
	D1->setNorthRoom(D0);

	Room* E1 = new Room("Garage", nullptr, D1, nullptr, nullptr, Azra);
	D1->setEastRoom(E1);

	currentRoom = A1;
	previousRoom = nullptr;
}

void Game::run()
{
	int userInput; string heroNameInput;
	cout << "Welcome to Hero Escape!" // Application header w game guide
		<< "\n-----------------------" << endl
		<< "\nMap Name: Azra's Haunted House" << endl
		<< "\nGame's Guide: Move your hero through multiple rooms of the map in order to"
		<< "\nreach the MYSTERY exit room. Be AWARE, the rooms throughout the map contain DANGEROUS monsters"
		<< "\nsuch as Azra and her SCARY friends, Mahnoor and Dora, who will HURT you at all costs! Look out"
		<< "\nfor items to aid in your battle and use your ability to retreat from a room wisely!" << endl;
	cout << "\nWhat is your Hero's Name? ";
	cin >> heroNameInput;

	while (!currentRoom->isExit())
	{
		/* LAYOUT of WHILE LOOP
		// Show room infos
		// if Retreating options
			// Move to previous room
				while(p-> next != null)
				{
				  previous = p;
				  p = ->next;
				}

			//Decrease retreat count

		// if Hero has items options
			// use an item process

		// if Hero is alive
			// does current room have items if
				// picking up items

			// execute move process

		// if current room is an exit
			// display congrats
		// else
			// game is over

		*/

		// Show room infos
		cout << "\n\nRoom Information" << endl
			<< "----------------" << endl;
		//Output of map
		if (currentRoom->getName() == "Start Room")
		{
			cout << "\t\t\t   [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t\t|\t\t    \t\t\t|\n"
				<< "[ *HERE* Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t\t|\t\t    |\n"
				<< "\t\t\t    [ Bathroom]\t\t[ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Living Room")
		{
			cout << "\t\t\t   [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ *HERE* Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t\t|\t\t    |\n"
				<< "\t\t\t    [ Bathroom]\t\t[ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Kitchen")
		{
			cout << "\t\t   [ *HERE* Kitchen]\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t|\t\t    |\n"
				<< "\t\t    [ Bathroom]\t\t[ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Bathroom")
		{
			cout << "\t\t   [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t|\t\t    |\n"
				<< "\t\t  [ *HERE* Bathroom]\t [ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Dining Room")
		{
			cout << "\t\t   [ Kitchen]\t\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ *HERE* Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t|\t\t      |\n"
				<< "\t\t    [ Bathroom]\t\t [ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Pantry")
		{
			cout << "\t\t   [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ Garage]"
				<< "\n\t\t\t|\t\t    |\n"
				<< "\t\t   [ Bathroom]\t\t[ *HERE* Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Great Room")
		{
			cout << "\t\t   [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ *HERE* Great Room]<==>[ Garage]"
				<< "\n\t\t\t|\t\t    |\n"
				<< "\t\t    [ Bathroom]\t\t[ Pantry]\n\n";
		}
		else if (currentRoom->getName() == "Garage")
		{
			cout << "\t\t    [ Kitchen]\t\t\t\t  [ Backyard]"
				<< "\n\t\t\t|\t\t    \t\t\t|\n"
				<< "[ Entrance]  <==> [ Living Room] <==> [ Dining Room] <==> [ Great Room]<==>[ *HERE* Garage]"
				<< "\n\t\t\t|\t\t    |\n"
				<< "\t\t    [ Bathroom]\t\t[ Pantry]\n\n";
		}
		else
		{
			continue;
		}
		
		
		// Display items, monster, and hero characteristics
		cout << "Name: " << currentRoom->getName() << endl
			<< "Monster: ";

		if (currentRoom->getRoomMonster() == nullptr)
		{
			cout << "None\n";
		}
		else
		{
			if (currentRoom->getRoomMonster()->getHP() > 20 && currentRoom->getRoomMonster()->getHP() < 55)
			{
				cout << "Mahnoor ~ ";
			}
			else if (currentRoom->getRoomMonster()->getHP() < 20)
			{
				cout << "Dora ~ ";
			}
			else
			{
				cout << "Azra ~ ";
			}
			cout << "HP " << currentRoom->getRoomMonster()->getHP() <<
				" Attack Power: " << currentRoom->getRoomMonster()->getAttackPower() << endl;
		}
		cout << "Item: ";

		if (!currentRoom->getRoomItem())
		{
			cout << "None\n";
		}
		else
		{
			if (currentRoom->getRoomItem()->isHP())
			{
				if (currentRoom->getRoomItem()->getValue() == 15)
				{
					cout << "Halal Burger" <<  " HP: " << currentRoom->getRoomItem()->getValue() << endl;
				}
			}
			else
			{
				if (currentRoom->getRoomItem()->getValue() == 1)
				{
					cout << "Trash Can" << " Defense Power: " << currentRoom->getRoomItem()->getValue() << endl;
				}
				else
				{
					cout << "Pepper Spray " << "Defense Power: " << currentRoom->getRoomItem()->getValue() << endl;
				}
			}
		}
		cout << "----------------" << endl;
		cout << "\n" << heroNameInput <<": HP: " << HeroName.getHP() << " Attack Power: " << HeroName.getAttackPower()
			<< " Defense Power: " << HeroName.getDefensePower() << " Retreat Count: " << HeroName.getRetreatCount() << endl;

		// if Retreating options
		if (previousRoom != nullptr)
		{
			if (HeroName.getRetreatCount() > 0) {
				cout << "\nWould you like to retreat? [yes/no]: ";
				string optionChoice = "";
				cin >> optionChoice;
				if (optionChoice == "yes" || optionChoice == "YES" ||
					optionChoice == "Yes" || optionChoice == "YeS" ||
					optionChoice == "yEs" || optionChoice == "yeS" ||
					optionChoice == "YEs" || optionChoice == "yES" ||
					optionChoice == "y" || optionChoice == "Y") {
					//Move to previous room using swap
					Room* temp;
					temp = currentRoom;
					currentRoom = previousRoom;
					previousRoom = temp;
					//decrease retreat count
					HeroName.decreaseRetreatCount();
					continue;
				}
			}
		}

		// if Hero has items options

		if (HeroName.anyItems()) {
			cout << "\nWould you like to use an item? [yes/no] ";
			string itemChoice = "";
			cin >> itemChoice;
			if (itemChoice == "yes" || itemChoice == "YES" ||
				itemChoice == "Yes" || itemChoice == "YeS" ||
				itemChoice == "yEs" || itemChoice == "yeS" ||
				itemChoice == "YEs" || itemChoice == "yES" ||
				itemChoice == "y" || itemChoice == "Y") {
				// use an item process

					/* display dynamically, not hardcoded
					1. Create the menu based on the information of the bag
					2. NULL values can be shown as empty spaces.
					3. If user select an empty SPACE, just let the user know that that cannot be used, and continue the game.
					4. If use selects a non-empty SPACE:
					4a. Apply the item on the hero
					4b. Remove the item from memory.
					*/

				for (int i = 0; i < 3; i++)
				{
					if (HeroName.bag[i] == nullptr)
					{
						cout << i + 1 << ". Empty" << endl;
					}
					else
					{
						if (HeroName.bag[i]->isHP())
						{
							if (HeroName.bag[i]->getValue() == 15)
							{
								cout << i + 1 << ". Halal Burger" << endl;
							}
						}
						else
						{
							if (HeroName.bag[i]->getValue() == 1)
							{
								cout << i + 1 << ". Trash Can" << endl;
							}
							else
							{
								cout << i + 1 << ". Pepper Spray" << endl;
							}
						}
					}
				}

				int choice;
				std::cout << "choice: ";
				std::cin >> choice;
				std::cout << "\n";

				while (HeroName.bag[choice - 1] == nullptr)
				{
					cout << "There is no item in " << choice << endl;
					std::cout << "choice: ";
					std::cin >> choice;
					std::cout << "\n";
				}

				switch (choice) {
				case 1:

					if (HeroName.bag[choice - 1]->isHP())
					{
						if (HeroName.bag[choice - 1]->getValue() == 15)
						{
							cout << "You ate Halal Burger! HP increased by 15" << endl;
							HeroName.setHP(HeroName.getHP() + 15);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}
					else
					{
						if (HeroName.bag[choice - 1]->getValue() == 1)
						{
							cout << "You equipped Trash Can! Defense increased by 1" << endl;
							HeroName.setDefensePower(HeroName.getDefensePower() + 1);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
						else
						{
							cout << "You equipped Pepper Spray! Defense increased by 2" << endl;
							HeroName.setDefensePower(HeroName.getDefensePower() + 2);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}

				case 2:

					if (currentRoom->getRoomItem()->isHP())
					{
						if (currentRoom->getRoomItem()->getValue() == 15)
						{
							cout << "You ate Halal Burger! HP increased by 15";
							HeroName.setHP(HeroName.getHP() + 15);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}
					else
					{
						if (currentRoom->getRoomItem()->getValue() == 1)
						{
							cout << "You equipped Trash Can! Defense increased by 1";
							HeroName.setDefensePower(HeroName.getDefensePower() + 1);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
						else
						{
							cout << "You equipped Pepper Spray! Defense increased by 2";
							HeroName.setDefensePower(HeroName.getDefensePower() + 2);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}

				case 3:

					if (HeroName.bag[choice - 1]->isHP())
					{
						if (HeroName.bag[choice - 1]->getValue() == 15)
						{
							cout << "You ate Halal Burger! HP increased by 15" << endl;
							HeroName.setHP(HeroName.getHP() + 15);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}
					else
					{
						if (HeroName.bag[choice - 1]->getValue() == 1)
						{
							cout << "You equipped Trash Can! Defense increased by 1" << endl;
							HeroName.setDefensePower(HeroName.getDefensePower() + 1);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
						else
						{
							cout << "You equipped Pepper Spray! Defense increased by 2" << endl;
							HeroName.setDefensePower(HeroName.getDefensePower() + 2);
							HeroName.bag[choice - 1] = nullptr;
							break;
						}
					}
				default:
					break;
				}
				
			}
		}


		// Hero vs Monster battle
		if (currentRoom->getRoomMonster() != nullptr)
		{
			int status = 0;
			if (currentRoom->getRoomMonster()->getHP() > 20 && currentRoom->getRoomMonster()->getHP() < 55)
			{
				cout << "\nMonster Mahnoor";
			}
			if (currentRoom->getRoomMonster()->getHP() < 20 && currentRoom->getRoomMonster()->getHP() > 0)
			{
				cout << "\nMonster Dora";
			}
			if (currentRoom->getRoomMonster()->getHP() > 50)
			{
				cout << "\nMonster Azra";
			}
			cout << " Approached, Battle Begins!\n" << endl;

			while (status == 0)
			{
				status = HeroName * (*(currentRoom->getRoomMonster())); // Hero and Monster battle

				cout << "Pow!!" << "\tBam!" << endl << "\t\tBoom!" << "\t\tKaboom!!!" << endl; // battle action words

				// output of hero hp and dp & Monster hp and ap
				cout << "\n" << heroNameInput << ": HP: " << HeroName.getHP() << " Defense Power: " << HeroName.getDefensePower() << endl; 

				
				cout << "Monster: HP " << currentRoom->getRoomMonster()->getHP() <<
					" Attack Power: " << currentRoom->getRoomMonster()->getAttackPower() << endl << endl;

				cout << "Wham!" << "\t\tBang!!!" << endl << "\tWow!" << "\t\t\tCrash!!" << endl; //battle action words
			}

			if (status == 1)
			{
				cout << "\nThe Monster has been defeated!" << endl;
				currentRoom->setRoomMonster(nullptr);
			}
			if (status == -1)
			{
				cout << "\nThe Monster has won the battle!" << endl;
				currentRoom->setRoomMonster(nullptr);
				break;

			}
		}

		// if Hero is alive
		if (HeroName.isAlive()) {
			// does current room have any items
			if (currentRoom->getRoomItem() != nullptr) {
				// want to pick it up
				cout << "\nWould you like to pick up ";
				if (currentRoom->getRoomItem()->isHP())
				{
					if (currentRoom->getRoomItem()->getValue() == 15)
					{
						cout << "Halal Burger";
					}
				}
				else
				{
					if (currentRoom->getRoomItem()->getValue() == 1)
					{
						cout << "Trash Can";
					}
					else
					{
						cout << "Pepper Spray";
					}
				}
				// execute pick up item
				cout << " [yes/no]: ";
				string pickUpChoice;
				cin >> pickUpChoice;
				if (pickUpChoice == "yes" || pickUpChoice == "YES" ||
					pickUpChoice == "Yes" || pickUpChoice == "YeS" ||
					pickUpChoice == "yEs" || pickUpChoice == "yeS" ||
					pickUpChoice == "YEs" || pickUpChoice == "yES" ||
					pickUpChoice == "y" || pickUpChoice == "Y") {
					cout << "\nBag: " << endl;
					for (int i = 0; i < 3; i++)
					{
						if (HeroName.bag[i] == nullptr)
						{
							cout << i + 1 << ". Empty" << endl;
						}
						else
						{
							if (HeroName.bag[i]->isHP())
							{
								if (HeroName.bag[i]->getValue() == 15)
								{
									cout << i + 1 << ". Halal Burger" << endl;
								}
							}
							else
							{
								if (HeroName.bag[i]->getValue() == 1)
								{
									cout << i + 1 << ". Trash Can" << endl;
								}
								else
								{
									cout << i + 1 << ". Pepper Spray" << endl;
								}
							}
						}
					}

					cout << "\nWhich position would you like to store the item? ";
					int position;
					std::cin >> position;

					switch (position) {
						/*
						assume valid input

						User selects option X
						if bag[X] is null
							bag[X] = currentRoom.getItem();
							currentRoom.setItem(nullptr);
						else bag[X] is not null
							delete bag[X];
							bag[X] = currentRoom.getItem();
							currentRoom.setItem(nullptr);

						*/
					case 1:

						if (HeroName.bag[0] == nullptr)
						{
							HeroName.bag[0] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						else
						{
							delete HeroName.bag[0];
							HeroName.bag[0] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						break;
					case 2:
						if (HeroName.bag[1] == nullptr)
						{
							HeroName.bag[1] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						else
						{
							delete HeroName.bag[1];
							HeroName.bag[1] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						break;
					case 3:
						if (HeroName.bag[2] == nullptr)
						{
							HeroName.bag[2] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						else
						{
							delete HeroName.bag[2];
							HeroName.bag[2] = currentRoom->getRoomItem();
							currentRoom->setRoomItem(nullptr);
						}
						break;
					}
				}
			}
		}

		// execute move process

		//For each option: include direction, name of room, and memory address
		vector<RoomInfo> menuObj;
		RoomInfo Ntemp, Stemp, Etemp, Wtemp; // To store in vector
		int countTemp = 0;

		// Creating a menu
		cout << "\nRoom: " << currentRoom->getName() << endl;
		if (currentRoom->getNorthRoom() != nullptr)
		{
			Ntemp.direction = "North";
			Ntemp.roomName = currentRoom->getNorthRoom()->getName();
			Ntemp.roomAdress = currentRoom->getNorthRoom();
			menuObj.push_back(Ntemp);
			countTemp++;
		}

		if (currentRoom->getSouthRoom() != nullptr)
		{
			Stemp.direction = "South";
			Stemp.roomName = currentRoom->getSouthRoom()->getName();
			Stemp.roomAdress = currentRoom->getSouthRoom();
			menuObj.push_back(Stemp);
			countTemp++;
		}

		if (currentRoom->getEastRoom() != nullptr)
		{
			Etemp.direction = "East";
			Etemp.roomName = currentRoom->getEastRoom()->getName();
			Etemp.roomAdress = currentRoom->getEastRoom();
			menuObj.push_back(Etemp);
			countTemp++;
		}
		if (currentRoom->getWestRoom() != nullptr)
		{
			Wtemp.direction = "West";
			Wtemp.roomName = currentRoom->getWestRoom()->getName();
			Wtemp.roomAdress = currentRoom->getWestRoom();
			menuObj.push_back(Wtemp);
			countTemp++;
		}

		// Displaying a menu
		for (int i = 0; i < menuObj.size(); i++)
		{
			cout << i + 1 << ") "; //option num
			cout << menuObj.at(i).direction << ": "; // direction
			cout << menuObj.at(i).roomName << endl; // room name
		}
		if (countTemp == 1)
		{
			cout << "Select a direction [Enter 1 only]: ";
			cin >> userInput;
		}
		else
		{
			cout << "Select a direction [Enter between 1-" << countTemp << "]: ";
			cin >> userInput;
		}
		
		previousRoom = currentRoom; // store current room in prev room before update
		currentRoom = menuObj.at(userInput - 1).roomAdress; // Assume a valid option is entered
	}

	// if current room is an exit
	if (currentRoom->isExit()) {
		//display congrats
		std::cout << "\nCongratulations you found the mystery exit room of Backyard!\n";
	}
	// else
	//game is over
	else {
		std::cout << "\nGame over ~ You Lost!\n";
	}
};

Game::Game() : HeroName(49, 5, 2, 1)
{
	createMap();
}