﻿#include <strcpp.h>

void split_test() {
  std::string input = "We are the champions";     // input string
  std::vector<std::string> result;                // result vector

  result = strcpp::split(input, " ");             // result = ["We", "are", "the", "champions"]
  result = strcpp::split(input, " a");            // result = ["We", "re the champions"]
  result = strcpp::split(input, "ions");          // result = ["We are the champ"]

  input = "a,b,c,d,e";
  result = strcpp::split(input, ",");             // result = ["a", "b", "c", "d", "e"]

  input = "a, b, c, d, e";
  result = strcpp::split(input, ", ");            // result = ["a", "b", "c", "d", "e"]

  input = "LOGGER::ERROR::Error Message!";
  auto message = strcpp::split(input, "::")[2];   // message = "Error Message!"

  auto length = strcpp::length(message);          // length = 14
}

void slice_test() {
  std::string input = "Hello World";
  // End index is optional and defaults to end of string
  std::cout << strcpp::slice(input, 0) << std::endl;     // All but the first zero characters  - "Hello World"
  std::cout << strcpp::slice(input, 0, 1) << std::endl;  // Just the first character           - "H"
  std::cout << strcpp::slice(input, 3) << std::endl;     // All but the first three characters - "lo World"
  std::cout << strcpp::slice(input, 0, 5) << std::endl;  // Just the first five characters     - "Hello"
  std::cout << strcpp::slice(input, 3, 8) << std::endl;  // After third till eigth character   - "lo Wo"
  std::cout << strcpp::slice(input, -3) << std::endl;    // Just the last three characters     - "rld"
  std::cout << strcpp::slice(input, 0, -3) << std::endl; // All but the last three characters  - "Hello Wo"
}

void contains_test() {
  std::string input = "ERROR::Houston, we have a problem!";

  if (strcpp::contains(input, "ERROR")) {                               // containment check - case sensitive
    std::cout << "Input string contains \"ERROR\"" << std::endl;        // check returns true and prints message
  }

  if (strcpp::contains(input, "error::", true)) {                       // containment check - ignore case
    std::cout << "Input string contains \"error::\"" << std::endl;      // check returns true and prints message
  }

  if (strcpp::contains(input, "PROBLEM")) {                             // containment check - ignore case
    std::cout << "Input string contains \"PROBLEM\"\n";
  }
  else {
    std::cout << "Input string does not contain \"PROBLEM\"\n";         // check returns false and prints message
  }
}

void starts_ends_test() {
  std::string input = "What's up with the Quaithe?";

  if (strcpp::starts_with(input, 'W')) {
    std::cout << "Input string starts with 'W'\n";                     // check returns true and prints message
  }

  if (strcpp::starts_with(input, 'w', true)) {
    std::cout << "Input string starts with 'w' - Case is ignored\n";   // check returns true and prints message
  }

  if (strcpp::ends_with(input, '.')) {                                 // check returns false
    std::cout << "Input string ends with period\n";
  }

  if (strcpp::ends_with(input, '?')) {                                 // check returns true and prints message
    std::cout << "Input string is a question\n";
  }
}

void count_test() {
  std::string input = "Hello World!";
  std::cout << strcpp::count(input, "l") << std::endl;          // prints 3
  std::cout << strcpp::count(input, "llo") << std::endl;        // prints 1
  std::cout << strcpp::count(input, " W") << std::endl;         // prints 1
  std::cout << strcpp::count(input, " wo") << std::endl;        // prints 0
  std::cout << strcpp::count(input, " wo", true) << std::endl;  // prints 1 - ignores case

  std::string them_spaces = "Count, the number of          spaces";
  std::cout << strcpp::count(them_spaces, " ") << std::endl;    // prints 13
}

void repeat_test() {
  std::string input = "Ha";
  std::cout << strcpp::repeat(input, 5) << std::endl;           // "HaHaHaHaHa"
  std::cout << strcpp::repeat(input, 5, " ") << std::endl;      // "Ha Ha Ha Ha Ha"

  input = "Ch";
  auto result = strcpp::repeat(
                  strcpp::repeat(input, 2, "ooo!"), 
                3, " ");
  std::cout << result << std::endl;                             // "Chooo!Chooo! Chooo!Chooo! Chooo!Chooo!"
}

void case_change_test() {
  std::string input = "this is some lowercase string";
  std::cout << strcpp::upper(input) << std::endl;               // "THIS IS SOME LOWERCASE STRING"

  input = "ACCIDENTALLY ENABLED CAPS LOCK!!!";
  std::cout << strcpp::lower(input) << std::endl;               // "accidentally enabled caps lock!!!"
}

void replace_test() {
  std::string input = "This is a test string.";
  std::cout << strcpp::replace(input, "a test", "an example");    // "This is an example string."
  std::cout << std::endl <<
    strcpp::replace(input, "test", "") << std::endl;              // "This is a string"

  input = "This is a a test string";                              // replace the first occurrence of the letter 'a'
  std::cout << strcpp::replace(input, "a", "", 1) << std::endl;   // "This is a test string"

  input = "Peter Piper picked a peck of pickled peppers.";                            
  std::cout << strcpp::replace(input, "p", "T", 2) << std::endl;  // "Peter PiTer Ticked a peck of pickled peppers."

  input = "Peter Piper picked a peck of pickled peppers.";        // Find and replace does not ignore case
  std::cout << strcpp::replace(input, "P", "T", 2) << std::endl;  // "Teter Tiper picked a peck of pickled peppers."
}

void translation_test() {
  std::string input = "1X444 2X3AB *^$RB (F(QP.";
  std::map<std::string, std::string> translation_table = {
    { "1X444", "Appetite"},
    { "2X3AB", "comes" },
    { "*^$RB", "with" }, 
    { "(F(QP", "eating" }
  };
  std::string translated = strcpp::translate(input, translation_table);
  std::cout << translated << std::endl;                          // "Appetite comes with eating."
}

int main() {
  split_test();
  slice_test();
  contains_test();
  starts_ends_test();
  count_test();
  repeat_test();
  case_change_test();
  replace_test();
  translation_test();
  // TODO: strip, lstrip, rstrip
  system("PAUSE");
  return 0;
}