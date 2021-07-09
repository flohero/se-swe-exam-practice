//
// Created by florian on 09.07.21.
//

#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <set>

/**
 * Dump
 */
std::map<std::string, std::vector<int>> mapOf1(const std::multimap<std::string, int> &mm) {
  std::map<std::string, std::vector<int>> new_map;
  for (const auto &item : mm) {
    auto match = new_map.find(item.first);
    if (match != new_map.end()) {
      match->second.push_back(item.second);
    } else {
      new_map.insert({item.first, {item.second}});
    }
  }
  return new_map;
}

/**
 * Uses <code>push_back</code>
 * Works only with containers, which have a push_back method
 */
template<typename K, typename V, class C = std::vector<V>>
std::map<K, C> mapOf2(const std::multimap<K, V> &mm) {
  std::map<K, C> new_map;
  for (const auto &item : mm) {
    auto match = new_map.find(item.first);
    if (match != new_map.end()) {
      match->second.push_back(item.second);
    } else {
      new_map.insert({item.first, {item.second}});
    }
  }
  return new_map;
}

/**
 * Uses insert iterator
 * Works on nearly every container
 */
template<typename K, typename V, class C = std::vector<V>>
std::map<K, C> mapOf3(const std::multimap<K, V> &mm) {
  std::map<K, C> new_map;
  for (const auto &item : mm) {
    auto match = new_map.find(item.first);
    if (match != new_map.end()) {
      std::insert_iterator<C> it{match->second, match->second.end()};
      it = item.second;
    } else {
      new_map.insert({item.first, {item.second}});
    }
  }
  return new_map;
}

/**
 * Uses back insert iterator
 * Works on nearly every container
 */
template<typename K, typename V, class C = std::vector<V>>
std::map<K, C> mapOf4(const std::multimap<K, V> &mm) {
  std::map<K, C> new_map;
  for (const auto &item : mm) {
    auto match = new_map.find(item.first);
    if (match != new_map.end()) {
      std::back_insert_iterator<C> it{match->second};
      it = item.second;
    } else {
      new_map.insert({item.first, {item.second}});
    }
  }
  return new_map;
}

int main() {
  std::multimap<std::string, int> mm{
      {"1", 1},
      {"1", 2},
      {"1", 3},
      {"2", 10},
      {"2", 11},
      {"2", 12},
      {"3", 22},
  };

  auto map = mapOf2<std::string, int, std::list<int>>(mm);
  for (const auto &item : map) {
    std::cout << item.first << ": ";
    for (const auto &val : item.second) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
}
