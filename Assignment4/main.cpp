// Justin Alvey
// ID: 0578482
// CSCI 2270 - Homework 4
// Date Created: 2/12/16
// Date Modified: 2/13/16

#include <iostream>
#include <string>
#include "CommunicationNetwork.h"
#include <stdlib.h>

using namespace std;

int main()
{
    CommunicationNetwork cm1; // Create a new network
    int input = 0; // Input as an integer
    string temp_word;
    string cityNew = ""; // Empty string
    string cityPrevious = ""; // Empty string

    while (input != 7){ //As long as the user wants to continue, display the main menu
        cout << "======Main Menu======"	<< endl; // Main menu
        cout << "1. Build Network"	<< endl; // Build the network option
        cout << "2. Print Network Path"	<< endl; // Print the network path option
        cout << "3. Transmit Message Coast-To-Coast-To-Coast" << endl; // Transmit message option
        cout << "4. Add City" << endl; // Add a city option
        cout << "5. Delete City" << endl; // Quit the menu
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        cin >> input; // Take in the user's input

    if (input == 1){ // If the user chooses to build the network
        // Call the buildNetwork() method to build the network
        cm1.buildNetwork(); // Calls the build network method
    }
    else if (input == 2){ // If the user chooses to print the network
        // Call the printNetwork() method to print out the network
        cm1.printNetwork(); // Calls the print network method
    }
    else if (input == 3){ // If the user chooses to transmit a message across the network
        // Call the transmitMessage() method to transit a message across the network
        cm1.transmitMsg("messageIn.txt"); // Calls the transmit message method
    }
    else if (input == 4){ // If the user chooses to add a city to the network
        // Call the addCity() method to add a city
        cout << "Enter a city name: " << endl; // Enter a city name
        cin.ignore();
        getline(cin,cityNew); // Take the user input (current)
        cin.clear();

        cout << "Enter a previous city name: " << endl; // Enter the previous city

        getline(cin,cityPrevious); // Take the user input (previous)
        cin.clear();
        cm1.addCity(cityNew,cityPrevious); // Call the add city method for the class
    }
    else if (input == 5){
        string deletedCity;
        cout <<"Enter a city name: "<< endl;
        cin.ignore();
        getline(cin,deletedCity);
        cin.clear();

        cm1.deleteCity(deletedCity); // Call delete city method
    }
    else if (input == 6){
        cm1.clearNetwork(); // Clear Network
    }
    else if (input == 7){ // If the user chooses to quit the menu
        input = 7;
        return 0; // Returns 0 for the function return
    }
    }
}
