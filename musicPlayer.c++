#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Song {
public:
    string title, artist, genre;
    int duration; 

    Song(string t, string a, string g, int d) {
        title = t;
        artist = a;
        genre = g;
        duration = d;
    }

    void displaySong() {
        int min = duration / 60;
        int sec = duration % 60;
        cout << title << " by " << artist << " (" << genre << ", " << min << "m " << sec << "s)" << endl;
    }
};

class Album {
public:
    string name;
    vector<Song> songs;

    Album(string n) {
        name = n;
    }

    void addSong(Song s) {
        songs.push_back(s);
    }

    void listSongs() {
        cout << "Album: " << name << endl;
        for (Song &s : songs)
            s.displaySong();
    }

    int totalDuration() {
        int total = 0;
        for (Song &s : songs)
            total += s.duration;
        return total;
    }

    void displayTotalDuration() {
        int total = totalDuration();
        cout << "Total duration: " << total / 60 << " minutes " << total % 60 << " seconds\n";
    }
};

class Playlist {
public:
    string name;
    vector<Song> songs;

    Playlist(string n) {
        name = n;
    }

    void addSong(Song s) {
        songs.push_back(s);
    }

    void removeSong(string title) {
        auto it = remove_if(songs.begin(), songs.end(), [&](Song &s) {
            return s.title == title;
        });
        songs.erase(it, songs.end());
    }

    void listSongs() {
        cout << "Playlist: " << name << endl;
        for (Song &s : songs)
            s.displaySong();
    }

    void shuffleSongs() {
        random_shuffle(songs.begin(), songs.end());
    }

    int totalDuration() {
        int total = 0;
        for (Song &s : songs)
            total += s.duration;
        return total;
    }

    void displayTotalDuration() {
        int total = totalDuration();
        cout << "Total duration: " << total / 60 << " minutes " << total % 60 << " seconds\n";
    }
};

class MusicPlayer {
public:
    vector<Album> albums;
    vector<Playlist> playlists;

    void addAlbum(Album a) {
        albums.push_back(a);
    }

    void addPlaylist(Playlist p) {
        playlists.push_back(p);
    }

    void listAlbums() {
        for (Album &a : albums) {
            a.listSongs();
            a.displayTotalDuration();
            cout << endl;
        }
    }

    void listPlaylists() {
        for (Playlist &p : playlists) {
            p.listSongs();
            p.displayTotalDuration();
            cout << endl;
        }
    }

    void searchSongByTitle(string title) {
        cout << "Searching for song: " << title << endl;
        for (Album &a : albums) {
            for (Song &s : a.songs) {
                if (s.title == title)
                    s.displaySong();
            }
        }
        for (Playlist &p : playlists) {
            for (Song &s : p.songs) {
                if (s.title == title)
                    s.displaySong();
            }
        }
    }

    void searchSongByArtist(string artist) {
        cout << "Searching songs by artist: " << artist << endl;
        for (Album &a : albums) {
            for (Song &s : a.songs) {
                if (s.artist == artist)
                    s.displaySong();
            }
        }
        for (Playlist &p : playlists) {
            for (Song &s : p.songs) {
                if (s.artist == artist)
                    s.displaySong();
            }
        }
    }
};

int main() {
    MusicPlayer player;

    Song s1("Lost Stars", "Adam Levine", "Pop", 245);
    Song s2("Believer", "Imagine Dragons", "Rock", 204);
    Song s3("Perfect", "Ed Sheeran", "Romantic", 263);

    Album a1("Top Hits");
    a1.addSong(s1);
    a1.addSong(s2);
    player.addAlbum(a1);

    Playlist p1("Favorites");
    p1.addSong(s2);
    p1.addSong(s3);
    player.addPlaylist(p1);

    player.listAlbums();
    player.listPlaylists();

    player.searchSongByTitle("Believer");
    player.searchSongByArtist("Ed Sheeran");

    p1.removeSong("Perfect");
    p1.shuffleSongs();
    p1.listSongs();

    return 0;
}
