
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title, artist;
    float duration;
    Node* next;

    Node(string t, string a, float d) {
        title = t;
        artist = a;
        duration = d;
        next = nullptr;
    }
};

class Playlist {
    Node* head;

public:
    Playlist() {
        head = nullptr;
    }

    ~Playlist() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addSong() {
        string title, artist;
        float duration;

        cin.ignore(10000, '\n');

        cout << "Enter song title: ";
        getline(cin, title);

        cout << "Enter artist name: ";
        getline(cin, artist);

        cout << "Enter song duration in minutes: ";
        cin >> duration;

        if (duration <= 0) {
            cout << "Invalid duration.\n";
            return;
        }

        Node* newNode = new Node(title, artist, duration);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Song added successfully!\n";
    }

    void removeSong() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        string title;
        cin.ignore(10000, '\n');

        cout << "Enter the title of the song to remove: ";
        getline(cin, title);

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->title != title) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Song not found.\n";
            return;
        }

        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Song removed successfully!\n";
    }

    void displayPlaylist() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        int count = 1;

        cout << "\n========== MUSIC PLAYLIST ==========\n";

        while (temp != nullptr) {
            cout << "\nSong " << count++ << '\n';
            cout << "Title: " << temp->title << '\n';
            cout << "Artist: " << temp->artist << '\n';
            cout << "Duration: " << temp->duration << " minutes\n";

            temp = temp->next;
        }

        cout << "\n====================================\n";
    }

    void playSong() {
        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        string title;
        cin.ignore(10000, '\n');

        cout << "Enter the title of the song to play: ";
        getline(cin, title);

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->title == title) {
                cout << "\nNow Playing...\n";
                cout << "Title: " << temp->title << '\n';
                cout << "Artist: " << temp->artist << '\n';
                cout << "Duration: " << temp->duration << " minutes\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Song not found in the playlist.\n";
    }
};

int main() {
    Playlist playlist;
    int choice;

    do {
        cout << "\n========== MUSIC PLAYER ==========\n";
        cout << "1. Add Song\n";
        cout << "2. Remove Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Play Specific Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            playlist.addSong();
            break;

        case 2:
            playlist.removeSong();
            break;

        case 3:
            playlist.displayPlaylist();
            break;

        case 4:
            playlist.playSong();
            break;

        case 5:
            cout << "Exiting music player. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
