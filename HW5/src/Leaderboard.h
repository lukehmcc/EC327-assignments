#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Leaderboard {
public:
  // Adds a new player or updates the score if the player already exists.
  // If the player already exists, this function should properly update
  // the player with the correct score.
  void addOrUpdatePlayer(const std::string &username, int score);

  // Removes a player from the leaderboard
  void removePlayer(const std::string &username);

  // Returns the top N players sorted by highest score (descending order)
  std::vector<std::pair<std::string, int>> getTopN(int N) const;

private:
  // Choose appropriate STL container(s) for storage
  // Example: std::map<std::string, int> or std::unordered_map<std::string, int>
  std::unordered_map<std::string, int> scoreBoard;
};

#endif // LEADERBOARD_H
