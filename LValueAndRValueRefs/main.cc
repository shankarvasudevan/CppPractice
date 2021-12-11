#include <iostream>
#include <iomanip>
#include <list>

struct Song
{
    friend std::ostream& operator<<(std::ostream& os, const Song& s);

    std::string name;
    std::string artist;
    int rating;

    bool operator<(const Song& rhs) const
    {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s)
{
    os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;

    return os;
}

std::string DisplayMenu()
{
    std::cout << "F - Play first song" << std::endl;
    std::cout << "N - Play next song" << std::endl;
    std::cout << "A - Add and play new song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "==============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): "; 

    std::string selection;
    std::cin >> selection;

    return selection;
}

void PlayCurrentSong(const Song& song)
{
    std::cout << "Playing:" << std::endl;
    std::cout << song.name << std::endl;
}

void DisplayPlaylist(const std::list<Song>& playlist, const Song& currentSong)
{
    for (const auto& it : playlist)
    {
        std::cout << it << std::endl; 
    }

    std::cout << currentSong << std::endl;
    DisplayMenu();
}

int main(int argc, char* argv[])
{
    std::list<Song> playlist
    {
        {"God's Plan", "Drake", 5},
        {"Never Be the Same", "Camila Cabello", 5},
        {"Pray for Me", "The Weekend and K.Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 4},
        {"Whateever It Takes", "Imagine Dragons", 3}
    };

    std::list<Song>::iterator currentSong = playlist.begin();

    std::string selection = DisplayMenu();

    while (selection != "Q")
    {
        if (selection == "F")
        {
            currentSong = playlist.begin();
            PlayCurrentSong(*currentSong);
        }
        else if (selection == "N")
        {
            ++currentSong;
            if (currentSong == playlist.end())
            {
                currentSong = playlist.begin();
            }
            PlayCurrentSong(*currentSong);
        }
        else if (selection == "P")
        {
            if (currentSong == playlist.begin())
            {
                currentSong = playlist.end();
            }
            --currentSong;
            PlayCurrentSong(*currentSong);
        }
        else if (selection == "A")
        {
            std::cout << "Adding and playing a new song" << std::endl;
            std::cout << "Enter song name:";

            std::string songName;
            getline(std::cin, songName);

            std::cout << "" << std::endl;

            std::cout << "Enter song artist:";

            std::string songArtist;
            getline(std::cin, songArtist);

            std::cout << "" << std::endl;

            std::cout << "Enter your rating (1-5):";

            int songRating;
            std::cin >> songRating;

            std::cout << "" << std::endl;

            Song song {songName, songArtist, songRating};

            playlist.insert(currentSong, song);
            PlayCurrentSong(song);
            ++currentSong;       
        }
        else if (selection == "L")
        {
            DisplayPlaylist(playlist, *currentSong);
        }
        else
        {
            std::cout << "Invalid selection" << std::endl;
        }

        selection = DisplayMenu();
    }

    return 0;
}