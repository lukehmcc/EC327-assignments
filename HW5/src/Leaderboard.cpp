#include "Leaderboard.h"
#include <algorithm>

void Leaderboard::addOrUpdatePlayer(const std::string &username, int score) {
  // insert the new value for key
  scoreBoard[username] = score;
}

void Leaderboard::removePlayer(const std::string &username) {
  // delete entry in map
  scoreBoard.erase(username);
}

std::vector<std::pair<std::string, int>> Leaderboard::getTopN(int N) const {
  // if N <= 0, return empty vector
  if (N <= 0) {
    std::vector<std::pair<std::string, int>> empty;
    return empty;
  }
  // Copy map to vector
  std::vector<std::pair<std::string, int>> sortedPlayers(scoreBoard.begin(),
                                                         scoreBoard.end());
  // sort vector
  std::sort(sortedPlayers.begin(), sortedPlayers.end(),
            [](const auto &a, const auto &b) { return a.second > b.second; });
  // truncate it
  if (N > 0 && sortedPlayers.size() > N) {
    sortedPlayers.resize(N);
  }
  return sortedPlayers;
}
