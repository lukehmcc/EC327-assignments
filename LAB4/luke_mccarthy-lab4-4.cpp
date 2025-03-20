#include "lab4_problem4.h"

Person::Person(string inName) { name = inName; }

void Person::befriend(Person &thePerson) { friends.push_back(&thePerson); }

void Person::unfriend(Person &thePerson) {
  for (int i = 0; i < friends.size(); i++) {
    if (friends.at(i)->name == thePerson.name) {
      friends.erase(friends.begin() + i);
    }
  }
}

int Person::getFriendCount() { return friends.size(); }

string Person::getFriends() {
  string friendList = "";
  for (int i = 0; i < friends.size(); i++) {
    friendList += friends.at(i)->name;
    if (i != friends.size() - 1) {
      friendList += ", ";
    }
  }
  return friendList;
}

string Person::getFriendsOfFriends() {
  string friendsOfFriendsList = "";
  for (int i = 0; i < friends.size(); i++) {
    if (friends.at(i)->getFriends() != "") {
      friendsOfFriendsList += friends.at(i)->getFriends();
      friendsOfFriendsList += ", ";
    }
  }
  if (!friendsOfFriendsList.empty()) {
    friendsOfFriendsList.erase(friendsOfFriendsList.length() -
                               2); // Remove ", "
  }
  return friendsOfFriendsList;
}
