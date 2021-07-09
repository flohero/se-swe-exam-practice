#include <iostream>
#include <set>
#include <map>
#include <stack>

class cct {
public:
  virtual void report_contact(const std::string &p1, const std::string &p2) = 0;
  virtual std::set<std::string> all_contacts_for(const std::string &p) = 0;
};

class contact_tracing : public cct {
private:
  std::map<std::string, std::set<std::string>> all_contacts;

  void add_single_contact(const std::string &p1, const std::string &p2) {
    auto match = all_contacts.find(p1);
    if(match != all_contacts.end()) {
      match->second.insert(p2);
    } else {
      all_contacts.insert({p1, std::set<std::string>{p2}});
    }
  }

  std::set<std::string> find_direct_contact(const std::string &p) {
    std::set<std::string> contacts;
    auto match = all_contacts.find(p);
    if(match != all_contacts.end()) {
      return match->second;
    }
    return std::set<std::string>();
  }
  
public:
  void report_contact(const std::string &p1, const std::string &p2) override {
    add_single_contact(p1, p2);
    add_single_contact(p2, p1);
  }

  std::set<std::string> all_contacts_for(const std::string &p) override {
    std::set<std::string> contacts = find_direct_contact(p);
    if(!contacts.empty()) {
      std::stack<std::string> to_visit;
      std::set<std::string> visited{p};
      for (const auto &item : contacts) {
        to_visit.push(item);
      }
      while(!to_visit.empty()) {
        std::string contact = to_visit.top();
        to_visit.pop();
        if(visited.find(contact) != visited.end()) {
          continue;
        }
        visited.insert(contact);
        auto direct_contacts = find_direct_contact(contact);
        direct_contacts.erase(p);
        contacts.insert(direct_contacts.begin(), direct_contacts.end());
        for (const auto &item : direct_contacts) {
          to_visit.push(item);
        }
      }
    }
    return contacts;
  }
};

int main() {
  contact_tracing ct;
  ct.report_contact("Flo", "Ramin");
  ct.report_contact("Flo", "Lea");
  ct.report_contact("Lea", "Andi");
  ct.report_contact("Andi", "Martin");
  ct.report_contact("Flo", "Andi");

  ct.report_contact("Leon", "Barbara");

  auto c = ct.all_contacts_for("Ramin");
  for (const auto &item : c) {
    std::cout << item << std::endl;
  }
  return 0;
}
