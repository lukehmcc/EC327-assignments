#include "hw3_problem5.h"
#include <algorithm>

// Available coins in descending order
const Coin coins[] = {QUARTER, DIME, NICKEL, PENNY};
const int numCoins = sizeof(coins) / sizeof(coins[0]);

// Helper function to find all combinations
void findCombinations(int remaining, Coin *current, int currentSize,
                      CoinArrays &results, int startIndex) {
  if (remaining == 0) {
    // Valid combination found, store it
    Coin *combination = new Coin[currentSize];
    std::copy(current, current + currentSize, combination);
    results.arrays[results.size++] = {combination, currentSize};
    return;
  }

  for (int i = startIndex; i < numCoins; i++) {
    if (coins[i] <= remaining) {
      // Add the coin to the current combination
      current[currentSize] = coins[i];
      // Recurse with the remaining amount
      findCombinations(remaining - coins[i], current, currentSize + 1, results,
                       i);
    }
  }
}

CoinArrays possibleChangeAmounts(int totalCents) {
  if (totalCents <= 0) {
    return {nullptr, 0};
  }

  // not really the smartest way to do this, but it is literally impossible for
  // there to be more arryas than input cents so this should be "fine"
  // (This is why we keep needing more computer memory, lazy people like me :p)
  CoinArrays results = {new CoinArray[totalCents], 0};

  // Temporary array to store the current combination
  Coin *current = new Coin[totalCents]; // Worst case: all pennies

  // Start recursion
  findCombinations(totalCents, current, 0, results, 0);

  // Clean up temporary array
  delete[] current;

  return results;
}
