#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace strcpp {

  // returns length of input string
  size_t length(const std::string input) {
    return input.size();
  }

  // returns true/false if input string contains search string
  bool contains(std::string input, std::string search_string, bool ignore_case = false) {
    bool result = false;
    if (ignore_case) { // if case is to be ignored, convert both input and search string to all upper case
      std::transform(input.begin(), input.end(), input.begin(), ::toupper);
      std::transform(search_string.begin(), search_string.end(), search_string.begin(), ::toupper);
    }
    if (input.find(search_string) != std::string::npos) { // search using find algorithm
      result = true;
    }
    return result;
  }

  // returns a sliced string
  std::string slice(std::string input, int start_index, int end_index = std::string::npos) {
    std::string result;
    if (end_index == std::string::npos) { // if end index is default, i.e., till end of string
      if (start_index < 0) { // if start index is negative, then start start_index characters from end of string
        for (int i = static_cast<int>(input.size() + start_index); i < input.size(); i++) {
          result += input[i];
        }
      }
      else { // start_index is not negative; iterate from start_index till end of string
        for (int i = static_cast<int>(start_index); i < input.size(); i++) {
          result += input[i];
        }
      }
    }
    else { // end_index is not std::string::npos
      if (end_index < 0) { // if end_index is negative, start from start_index and go till (end_of_string + end_index)
        for (int i = static_cast<int>(start_index); i < input.size() + end_index; i++) {
          result += input[i];
        }
      }
      else { // if end_index is not negative either, then this is the trivial case
        for (int i = start_index; i < end_index; i++) {
          result += input[i];
        }
      }
    }
    return result;
  }

  // split string based on a delimiter string
  // supports multi-character delimiter
  // returns a vector of substrings after split
  std::vector<std::string> split(std::string input, std::string delimiter, 
    std::vector<std::string>& result = std::vector<std::string>()) {
    size_t counter_position = 0;
    size_t delimiter_position = input.find(delimiter); // checkf if delimiter is in input string
    if (delimiter_position != std::string::npos) { // if delimiter position is not end_of_string
      std::string split_string = input.substr(counter_position, delimiter_position);
      delimiter_position += delimiter.size();
      std::string split_remaining = input.erase(counter_position, delimiter_position);
      result.push_back(split_string);
      // Recursion! Recursion everywhere!
      std::vector<std::string> result_remaining = split(split_remaining, delimiter, result);
    }
    else { // delimiter not in input string. Just add entire input string to result vector
      result.push_back(input);
    }
    return result;
  }

  // checks if a string start_with input character
  bool starts_with(std::string input, char c, bool ignore_case = false) {
    bool result = false;
    if (input.size() > 0) {
      char first_character = input[0];
      if (ignore_case) {
        first_character = toupper(first_character);
        c = toupper(c);
      }
      if (first_character == c)
        result = true;
    }
    return result;
  }

  // checks if a string ends_with input character
  bool ends_with(std::string input, char c, bool ignore_case = false) {
    bool result = false;
    if (input.size() > 0) {
      char last_character = input[input.size() - 1];
      if (ignore_case) {
        last_character = toupper(last_character);
        c = toupper(c);
      }
      if (last_character == c)
        result = true;
    }
    return result;
  }

  // count number of times a substring appears in input string
  size_t count(std::string input, std::string search_string, bool ignore_case = false) {
    size_t result = 0;
    if (contains(input, search_string, ignore_case)) {
      if (ignore_case) {
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        std::transform(search_string.begin(), search_string.end(), search_string.begin(), ::toupper);
      }
      auto split_vector = split(input, search_string);
      result = split_vector.size() - 1;
    }
    return result;
  }

}