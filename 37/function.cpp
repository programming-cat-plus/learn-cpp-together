#include <string>
using namespace std;

string f1()
{
    return string("Hello");
}

string& f2()
{
    static string s = "Hello";
    return s;
}

string&& f3(string& s)
{
  return std::move(s);
}

int main(void)
{
    decltype(f1()) s1;
    decltype(f2()) s2 = s1;
    decltype(f3(s1)) s3 = "hello";
}

