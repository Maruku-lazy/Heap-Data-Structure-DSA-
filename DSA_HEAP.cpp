/*
Pair: Marc Jysk E. Herato / Nathaniel O. Samson

Scenario: Leaderboard Keeper
You are the Keeper of the Leaderboards for the Grand Gaming Championship.
Your job is to maintain a dynamic leaderboard that ranks players based on their scores.
The leaderboard is managed using heaps to ensure the rankings are updated efficiently whenever scores are added or removed.

Learning Goals:
By completing this assessment, you will learn and demonstrate:

Dynamic Ranking: Inserting and removing player scores while maintaining a heap.
Heap Operations: Applying heapify to establish a ranking system from unsorted scores.
Heap Conversion: Switching between Max-Heap (top scores first) and Min-Heap (bottom scores first).

Task 1: Building the Leaderboard
Your first task is to rank players based on their scores.
Use a Max-Heap to ensure the highest scores are always at the top of the leaderboard.

Instruction:
Write a function to insert a player's name and score into the Max-Heap.
Print the heap after each insertion with a themed message (e.g., “Player 3 joined the leaderboard with 1200 points!”).

Input Example:
Scores: [Marc 1200, Asher 800, Nathan 1500, Alexa 950, Kelly 1350]

Output Example:

Current Leaderboard (Max-Heap by Score):
Nathan (Score: 1500)
Kelly (Score: 1350)
Marc (Score: 1200)
Alexa (Score: 950)
Asher (Score: 800)

Task 2: Convert the leaderboard to a Min-Heap
To showcase the underdog players, you are tasked with creating a leaderboard, where the lowest scores are prioritized.
Convert the Max-Heap into a Min-Heap to display the weakest players.

Input Example:
Scores: [Marc 1200, Asher 800, Nathan 1500, Alexa 950, Kelly 1350]

Output Example:

Current Leaderboard (Min-Heap by Score):
Asher (Score: 800)
Alexa (Score: 950)
Marc (Score: 1200)
Nathan (Score: 1500)
Kelly (Score: 1350)

*/

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Define a type alias for player entries: pair of score and name
using Player = pair<int, string>;

// Helper function to display the Max-Heap (Leaderboard)
void displayMaxHeap(const priority_queue<Player>& maxHeap) {
    // Make a copy of the heap to avoid modifying the original
    priority_queue<Player> heapCopy = maxHeap;
    cout << "Current Leaderboard (Max-Heap by Score):\n";
    while (!heapCopy.empty()) {
        Player topPlayer = heapCopy.top();
        cout << topPlayer.second << " (Score: " << topPlayer.first << ")\n";
        heapCopy.pop();
    }
}

// Helper function to display the Min-Heap (Leaderboard)
void displayMinHeap(const vector<Player>& minHeap) {
    cout << "Current Leaderboard (Min-Heap by Score):\n";
    for (const auto& player : minHeap) {
        cout << player.second << " (Score: " << player.first << ")\n";
    }
}

int main() {
    priority_queue<Player> maxHeap; // Max-Heap for players' scores
    vector<Player> minHeap;        // Min-Heap representation
    int choice;

    cout << "Welcome to the Gaming Leaderboard!\n";

    do {
        cout << "\nChoose an action:\n";
        cout << "1. Add a player's name and score\n";
        cout << "2. Remove the top player (highest score)\n";
        cout << "3. Convert the leaderboard to a Min-Heap\n";
        cout << "4. Display the current leaderboard (Max-Heap)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int score;
                cout << "Enter the player's name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);
                cout << "Enter the player's score: ";
                cin >> score;
                maxHeap.push({score, name});
                cout << name << " with score " << score << " added to the leaderboard.\n";
                break;
            }
            case 2: {
                if (!maxHeap.empty()) {
                    Player topPlayer = maxHeap.top();
                    cout << "Removed the top player: " << topPlayer.second << " with score " << topPlayer.first << endl;
                    maxHeap.pop();
                } else {
                    cout << "The leaderboard is empty! No players to remove.\n";
                }
                break;
            }
            case 3: {
                if (maxHeap.empty()) {
                    cout << "The leaderboard is empty! Cannot convert to Min-Heap.\n";
                } else {
                    cout << "Converting the leaderboard to a Min-Heap...\n";
                    // Transfer elements from Max-Heap to a vector
                    while (!maxHeap.empty()) {
                        minHeap.push_back(maxHeap.top());
                        maxHeap.pop();
                    }
                    // Transform vector into Min-Heap
                    make_heap(minHeap.begin(), minHeap.end(), greater<Player>());
                    displayMinHeap(minHeap);
                }
                break;
            }
            case 4: {
                if (maxHeap.empty()) {
                    cout << "The leaderboard is empty!\n";
                } else {
                    cout << "Displaying the current leaderboard:\n";
                    displayMaxHeap(maxHeap);
                }
                break;
            }
            case 5: {
                cout << "Exiting the program. Thank you for using the Gaming Leaderboard!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
