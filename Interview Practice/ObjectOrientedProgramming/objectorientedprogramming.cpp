

/*
class Deck // implemented as a circular linked list
{
private:
CircularLinkedList deckOfCards;

public:
void Shuffle();
Card* DrawACard();
Card* getCard(int value, char suit)
};

// O(n)
Deck::Shuffle()
{
   for(int i =0; i < 52; i++)
   {
       // Generate random number between i to N;
       // swap(i,j)
   }
}
//--------------------------------------------------------
class Employee
{
    char type;
};


class Fresher : public Employee
{

};

class TechnicalLead: public Employee
{
private:
    static TechnicalLead* uniqueTL;
    TechnicalLead() : Employee()
    {
        // do nothing
    }
public:
    TechnicalLead* getInstance()
    {
        if(uniqueTL == NULL)
        {
            uniqueTL = new TechnicalLead();
        }
        return uniqueTL;
    }
};

TechnicalLead* TechnicalLead::uniqueTL = NULL;



class ProductManager: public Employee
{
private:
    static ProductManager* uniquePM;
    ProductManager() : Employee()
    {
        // do nothing
    }
public:
    ProductManager* getInstance()
    {
        if(uniquePM == NULL)
        {
            uniquePM = new ProductManager();
        }
        return uniquePM;
    }
};

ProductManager* ProductManager::uniquePM = NULL;

class CallHandler
{
private:
    int numAvailable;
public:
    Employee* getCallHandler()
    {
        Employee* nextCallHandler;
        if(numAvailable > 0)
        {
            numAvailable--;
            nextCallHandler = new Fresher();
        }
        else
        {
            nextCallHandler = TechnicalLead::getInstance();
            if (!nextCallHandler->available())
            {
                nextCallHandler = ProductManager::getInstance();
                if (!nextCallHandler->available())
                {
                    nextCallHandler = NULL;
                }
            }
        }
        return nextCallHandler;
    }
};

//--------------------------------------------------------

#include <queue>
#include <vector>
#include <string>

class MP3Player
{
private:
    Playlist* playlists; // hashTable/BST
    unsigned int totalNumSongs;
    unsigned int numPlaylist;
public:
    void createNewPlaylist;
};

class Playlist
{
private:
    string nameOfPlaylist; // key to the playlist
    unsigned int numSongs;
    vector<Song> songs;
    queue<Song> currPlaying;
public:
    void queueSong(Song* songName);
    void addSong(Song* songName);
    void deleteSong(Song* songName);
    void shuffleSongs();
};

void Playlist::queueSong(Song* songName)
{
    // TODO: Check that song is in playlist
}
// */

#include <iostream>
using namespace std;
int main(void)
{
    return 0;
}
