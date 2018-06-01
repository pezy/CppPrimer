#ifndef CP5_EX16_22_TEXTQUERY_H_
#define CP5_EX16_22_TEXTQUERY_H_

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <fstream>
#include <iostream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    QueryResult(const string& s, shared_ptr<std::set<TextQuery::LineNo>> set,
                shared_ptr<vector<string>> v)
        : word(s), nos(set), input(v)
    {
    }

private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif // CP5_EX16_22_TEXTQUERY_H_