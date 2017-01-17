#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include <iostream>
struct City{
    std::string cityName; // Name for the city
    std::string message; // Message from the city before, to the current city
    City *next; // Pointer to the next city
    City *previous; // Pointer to the city before

    City(){}; // default constructor

    // Constructing the City
    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage)
    {
        cityName = initName; // City name
        next = initNext; // City pointer
        previous = initNext; // City before pointer
        message = initMessage; // City message
    }

};

class CommunicationNetwork
{
    public:
        CommunicationNetwork(); // Default constructor
        ~CommunicationNetwork(); // Default destructor
        void addCity(std::string, std::string); // The addCity method
        void buildNetwork(); // The buildNetwork method
        void transmitMsg(char *); //The transmitMessage method (char*: this is like a string)
        void printNetwork(); // The printNetwork method
        void deleteCity(std::string);
        void clearNetwork();
    protected:
    private:
        // By doing this, memory is already allocated
        City *head; // Pointer for the head of the network
        City *tail; // Pointer for the tail of the network
};

#endif // COMMUNICATIONNETWORK_H



