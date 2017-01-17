#include "CommunicationNetwork.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL; // Defining head pointer to null
    tail = NULL; // Defining tail pointer to null
}

CommunicationNetwork::~CommunicationNetwork()
{
    clearNetwork(); // Clear the network, when destructed
    cout << "Goodbye!" << endl; // Print goodbye to the user
}

void CommunicationNetwork::buildNetwork(){ // Method for building the network
    // An array of strings for the city names
    string cityNames[10] = {"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, D.C.","New York","Boston"};

    // Allocating memory, and defining each city by the name, and a pointer to the next city
    // Starting from the tail

    // A for loop could have been used for efficiency, but this worked for me
    City *last = new City("Boston",NULL,NULL,"");
    City *nine = new City(cityNames[8],last,NULL, "");
    last -> previous = nine;
    City *eight = new City(cityNames[7],nine,NULL, "");
    nine -> previous = eight;
    City *seven = new City(cityNames[6],eight,NULL, "");
    eight -> previous = seven;
    City *six = new City(cityNames[5],seven,NULL,"");
    seven ->previous = six;
    City *five = new City(cityNames[4],six,NULL, "");
    six ->previous = five;
    City *four = new City(cityNames[3],five,NULL, "");
    five ->previous = four;
    City *three = new City(cityNames[2],four,NULL, "");
    four ->previous = three;
    City *two = new City(cityNames[1],three,NULL,"");
    three -> previous = two;
    City *first = new City(cityNames[0],two,NULL, "");
    two -> previous = first;

    // Do not reallocate memory for head/tail
    head = first; // Allocating memory for the head pointer
    tail = last; // Allocating memory for the tail pointer
    // Printing the network, same algorithm as the printNetwork() method

    printNetwork(); // Print out the network

}

void CommunicationNetwork::printNetwork(){ // Method for printing the network
    City *temp = head; // A temporary pointer
    if (temp == NULL){ // If the network had not been built
        cout << "Empty List" << endl; // Print out Empty List to the user
    }else{ // If the network had been built
    cout	<< "===CURRENT PATH==="	<<	endl; // Formatting
    while (temp !=NULL){ // While the pointer is not pointing to null
            if (temp == head){ // If temp is at the head
                cout << "NULL" << " <- "; // Head->previous is NUL
                cout << head->cityName << " <-> "; // Print out the name of the first city in the linked list
                // The head of the linked list
                temp = temp->next; // Moving to the next city, as defined by the city's next private member
            }
            else if (temp->next != NULL){ // If the pointer is not at the end of the list
                cout << temp->cityName << " <-> "; // Print out the name of the current city
                temp = temp->next; // Go to the next city
            }
            else if (temp->next == NULL){ // If the pointer is at the end of the list (the last city)
                cout << temp->cityName << " -> "; // Print out the last city name
                cout << "NULL" << endl; // Print out null to signify the end of the linked list
                temp = temp->next; // Go to the next city
            }
    }
    cout << "==================" << endl; // Formatting
}

}

void CommunicationNetwork::transmitMsg(char* filename){
    if (head == NULL){ // If the network has not been built
        cout << "Empty list" << endl; // Print out Empty List to the user
    }
    else{ // If the network has been built
    City *temp = head; // A temporary pointer pointing to the memory at the head of the list

    string line; // String for each word
    ifstream infile; // Ifstream filename
	infile.open(filename); // Open the file
    //cout << "Now reading in: " << filename << endl;
    while (infile >> line){ // While each word is read from the file
        while (temp->next != NULL){ // While temp is not at the end of the list
                temp -> message = line; // Relay the message to the city
                cout << temp->cityName<<" received "<< temp->message << endl; // Display that the message was received for that city
                temp -> message = ""; // Erase the message from the city before
                temp = temp->next; // Move temp along in the linked list
        }
        temp = tail; // Set temp to the tail
        while (temp->next != NULL){
            temp = temp->next;
        }
        while (temp != head){ // While temp ascends the list, from the head to the tail
                temp -> message = line; // Relay the message to the city
                cout << temp->cityName<<" received "<< temp->message << endl; // Display that the message was received for that city
                temp -> message = ""; // Erase the message from the city before
                temp = temp->previous; // Move temp along in the linked list
        }
        temp -> message = line; // Relay the message to the city
        cout << temp->cityName<<" received "<< temp->message << endl; // Display that the message was received for that city (head)
        temp -> message = ""; // Erase the message from the city before
    }
    }
}

void CommunicationNetwork::addCity(string first, string second){ //Method for adding a new city
    City *temp = head; // Point temp to the head of the list
    bool check = true; // Check to see if the previous city entered exists in the list
if (temp == NULL){ // If the network had not yet been built, tell the user
    cout << "Empty List" << endl; // Print out Empty List to the user
}else{
    if (second == "First"){ // If the user wants to add a new head
        City *addedCity = new City(first,head,NULL,""); // Add a city to the front of the linked list
        head->previous = addedCity; // Connect head to the new head
        head = addedCity; // Point the head pointer to the new city
        check = false; // City was added, so check not needed
    }
    else if (second == (tail->cityName)){ // If the user wants to add a new tail
        City *addedCity = new City; // Allocate memory for a new city (first,NULL,tail,"")
        addedCity -> cityName = first;
        addedCity -> previous = tail;
        addedCity -> next = NULL;
        addedCity -> message = "";
        tail->next = addedCity; // Add the city to the end of the linked list
        tail = addedCity; // Point the tail to the new city
        check = false; // City added, so check not added
    }
    else{
        while (temp != NULL){ // While temp is not NULL
            if (second == temp->cityName){ // If the previous city name input is equal to temp
                City *addedCity = new City; // Allocate memory for a new city
                addedCity -> cityName = first;
                addedCity -> previous = temp;
                addedCity -> next = temp->next;
                addedCity -> message = "";
                (temp->next)->previous = addedCity; // Connect temp->nextg to new city
                temp -> next = addedCity; // Point the previous city to the new city
                check = false; // City added, so check not needed
                temp = NULL;
            }else{
                temp = temp->next; // Move temp along through the linked list
            }
        }if (check){ // Check if the city wasn't found in the network
            cout << second << " not found" << endl; // Print out city not found, if the city could not be found in the linked list
        }
    }
}
}

void CommunicationNetwork::clearNetwork(){
    City *temp = head; // Temporary variable pointing to the memory at the head of the list
    if (head == NULL){ // If network was already cleared
        cout << "Network is cleared" << endl; // Network is cleared already
    }
    else{ // If network wasn't already cleared
    while (head != NULL){ // While head is not at the end of the linked list
        cout <<"deleting "<< head->cityName<< endl; // Deleting the current city displayed to the user
        head = head->next; // Move head to the next location

        delete temp; // Clear temp, pointing at memory of head's old location
        temp = head; // Point temp to the new head
    }
        head = NULL; // Setting head to NULL, once the entire network has been cleared
    }
}

void CommunicationNetwork::deleteCity(string cityNameDelete){ // Method to delete an entered city, by searching the doubly linked list
    City *last = head; // Temporary variable
    City *temp = head; // Temporary variable
    bool check = true; // Boolean for checking if the city has been deleted
if (temp == NULL){ // If temp is NULL, then the network has not yet been built. Print out Empty List
    cout << "Empty List" << endl;
}else{ // If the network has been built, start searching the array
    if (cityNameDelete == head->cityName){ // If the city to be deleted is the head, treat it differently
        temp = head; // Set temporary var to head so the memory isn't lost
        head = head->next; // Move head to the next location
        head->previous = NULL; // Set head previous to NULL, disconnecting temp (the original head) from the chain
        check = false; // City was deleted from the linked list
        delete temp; // Delete the original head
    }else{ // If the city to be deleted is not the head, use this algorithm
        last = head; // Last is set at the head
        temp = head->next; // Temp is set at head->next
        while(temp != NULL){ // Until temp is not at the end of the doubly linked list, search through the list
            if (temp->cityName == cityNameDelete){ // If temp is the city to be deleted
                last->next = temp->next; // Link last-> next to temp->next, bypassing temp
                if (temp == tail){ // If the tail is to be deleted
                    last->next = NULL; // Set last next to NULL
                    tail = last; // Tail has been reset to the memory located at last
                    delete temp; // Delete the old tail
                    check = false; // City has been deleted
                }else{ // If the city is somewhere between head and tail
                    (last->next)->previous = last; // Set temp->next city previous to last, bypassing temp

                    delete temp; // Delete the city
                    check = false; // City was found and deleted from the list
                }
            }
            last = last->next; // Traverse the linked list
            temp = temp->next; // Traverse the linked list
        }
        if (check){ // If the city was not deleted, print out that the city could not be found to the user
            cout << cityNameDelete<< " not found" << endl; // Print out the city could not be found
            check = false; // Change check to opt out of the infinite loop
        }
    }
}
}
