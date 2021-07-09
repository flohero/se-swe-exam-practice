//
// Created by florian on 09.07.21.
//

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

bool is_char(char c) {
  int lower_c = tolower(c);
  return 'a' <= lower_c && lower_c <= 'z';
}

bool is_valid_mail(const std::string &mail) {
  if(mail.empty() || !is_char(mail[0])) {
    return false;
  }
  size_t at, dot = -1;
  for(size_t i = 1; i < mail.length(); i++) {
    if(mail[i] == '@') {
      at = i;
    } else if(mail[i] == '.') {
      dot = i;
    }
  }
  if(dot == -1 || at == -1 || dot < at) {
    return false;
  }
  return dot != (mail.length() - 1);
}

std::multimap<std::string, std::string> read_address_book(const std::string &filename) {
  std::ifstream stream{filename};
  std::multimap<std::string, std::string> mm{};

  if(stream.is_open()) {
    std::string name;
    while (stream.good()) {
      std::string str;
      getline(stream, str, ' ');
      if(!is_valid_mail(str)) {
        name = str;
      } else {
        mm.insert({name, str});
      }
    }
  }
  return mm;
}

std::vector<std::string> mail_for(const std::multimap<std::string, std::string> &mm, const std::string &name) {
  auto rng = mm.equal_range(name);
  std::vector<std::string> mails;
  for(auto it = rng.first; it != rng.second; it++) {
    mails.push_back(it->second);
  }
  return mails;
}

std::string name_for(const std::multimap<std::string, std::string> &mm, const std::string &mail) {
  for (const auto &item : mm) {
    if(item.second == mail) {
      return item.first;
    }
  }
  return "";
}

int main() {
  auto book = read_address_book("/home/florian/Projects/fh/semester4/swe/klausur/cpp/mail.txt");
  for (const auto &item : mail_for(book, "Susanne")) {
    std::cout << item << " " << std::endl;
  }
  std::cout << name_for(book, "se09001@fh-hagenberg.at");
}
