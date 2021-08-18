#include "food_chain.h"

namespace food_chain {

std::string verse(int n) {
  n -= 1;

  std::string animal[8] = {"fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"};

  std::map<std::string, std::string> animal_sentences;
  animal_sentences["fly"] = "I don't know why she swallowed the fly. Perhaps she'll die.\n";
  animal_sentences["spider"] = "It wriggled and jiggled and tickled inside her.\n";
  animal_sentences["bird"] = "How absurd to swallow a bird!\n";
  animal_sentences["cat"] = "Imagine that, to swallow a cat!\n";
  animal_sentences["dog"] = "What a hog, to swallow a dog!\n";
  animal_sentences["goat"] = "Just opened her throat and swallowed a goat!\n";
  animal_sentences["cow"] = "I don't know how she swallowed a cow!\n";
  animal_sentences["horse"] = "She's dead, of course!\n";

  std::string I_know = "I know an old lady who swallowed a ";
  std::string She_swallowed = "She swallowed the ";
  std::string to_catch = " to catch the ";

  std::string verse = I_know + animal[n] + ".\n";

  if ((n > 0) && (n < 7)) {
    verse += animal_sentences[animal[n]];
    while (n > 0) {
      verse += (She_swallowed + animal[n] + to_catch + animal[n - 1]);

      if (n == 2) {
        verse += " that wriggled and jiggled and tickled inside her";
      }
      verse += ".\n";
      --n;
    }
  }

  verse += animal_sentences[animal[n]];

  return verse;
}

std::string verses(int start, int end) {
  std::string verses = verse(start++) + "\n";
  while (start <= end) {
    verses += verse(start++) + "\n";
  }
  return verses;
}

std::string sing() {
  return verses(1, 8);
};

}  // namespace food_chain
