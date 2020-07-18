#include <any>
#include <charconv>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum class TokenType { plus, minus, times, obelus, integer, open, close, end };

map<char, TokenType> charTokenMap = {
    {'+', TokenType::plus},   {'-', TokenType::minus}, {'*', TokenType::times},
    {'/', TokenType::obelus}, {'(', TokenType::open},  {')', TokenType::close},
};

class Tokenizer {
  vector<pair<TokenType, any>> tokens;
  size_t pointer;

public:
  Tokenizer(string s) {
    size_t i = 0;
    while (true) {
      while (i < s.length() && s[i] == ' ')
        i++;
      if (i >= s.length())
        break;
      if (charTokenMap.count(s[i])) {
        tokens.push_back(make_pair(charTokenMap[s[i]], nullptr));
        i++;
      } else if (isdigit(s[i])) {
        size_t j = i + 1;
        while (j < s.length() && isdigit(s[j]))
          j++;
        int value;
        from_chars(s.c_str() + i, s.c_str() + j, value);
        tokens.push_back(make_pair(TokenType::integer, value));
        i = j;
      } else {
        throw "invalid token: " + s.substr(i);
      }
    }
    tokens.push_back(make_pair(TokenType::end, nullptr));
    pointer = 0;
  }
  Tokenizer() = default;

  TokenType type() { return tokens[pointer].first; }

  int valueInteger() { return any_cast<int>(tokens[pointer].second); }

  void match(TokenType t) {
    if (tokens[pointer].first == t)
      pointer++;
    else
      throw "unmatched token!";
  }

  void forward() { pointer++; }
};

/**
 * expr -> term ( '+' term | '-' term ) *
 * term -> factor ( '*' factor | '/' factor ) *
 * factor -> integer
 * factor -> '(' expr ')'
 */
class Parser {
  Tokenizer tstream;

public:
  Parser(Tokenizer t) { tstream = t; }

  double factor() {
    if (tstream.type() == TokenType::integer) {
      double val = tstream.valueInteger();
      tstream.forward();
      return val;
    } else if (tstream.type() == TokenType::open) {
      tstream.forward();
      double val = expr();
      tstream.match(TokenType::close);
      return val;
    } else {
      throw "factor match failed!";
    }
  }

  double term() {
    double val = factor();
    while (true) {
      if (tstream.type() == TokenType::times) {
        tstream.forward();
        double rval = factor();
        val *= rval;
      } else if (tstream.type() == TokenType::obelus) {
        tstream.forward();
        double rval = factor();
        val /= rval;
      } else {
        return val;
      }
    }
  }

  double expr() {
    double val = term();
    while (true) {
      if (tstream.type() == TokenType::plus) {
        tstream.forward();
        double rval = term();
        val += rval;
      } else if (tstream.type() == TokenType::minus) {
        tstream.forward();
        double rval = term();
        val -= rval;
      } else {
        return val;
      }
    }
  }

  double eval() { return expr(); }
};

int main() {
  auto p = Parser(Tokenizer("1+2*(5+ (9 + 1 + 1))/2 + 100"));
  cout << p.eval() << endl;
  return 0;
}
