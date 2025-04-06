Music-player-application
Overview
A simple C++ console application to manage songs, albums, and playlists. Users can add songs, create playlists, shuffle, and search music easily.

Features:
- Add songs with title, artist, genre, and duration
- Create albums and playlists
- Display total durations
- Search songs by title or artist
- Shuffle and remove songs from playlists

Classes & Their Functions:
1. Song
- displaySong() — Displays the song's title, artist, genre, and duration

2. Album
- addSong(Song) — Adds a song to the album
- listSongs() — Lists all songs in the album
- totalDuration() — Returns total duration in seconds
- displayTotalDuration() — Prints duration in minutes and seconds

3. Playlist
- addSong(Song) — Adds a song to the playlist
- removeSong(string title) — Removes a song by title
- listSongs() — Lists all songs in the playlist
- shuffleSongs() — Randomly shuffles the playlist
- totalDuration() — Returns total duration in seconds
- displayTotalDuration() — Prints duration in minutes and seconds

 4. MusicPlayer
- addAlbum(Album) — Adds an album to the player
- addPlaylist(Playlist) — Adds a playlist to the player
- listAlbums() — Displays all albums and their details
- listPlaylists() — Displays all playlists and their details
- searchSongByTitle(string title) — Searches songs by title
- searchSongByArtist(string artist) — Searches songs by artist
