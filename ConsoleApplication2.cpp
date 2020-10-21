#include <string.h>
#include <iostream>
using namespace std;
class String
{   public:
    char* s;
    int razmer;
    String();
    String(const char* str);
    String(const String& str1);
    friend String operator++(const String& str);
    friend String operator++(const String& str,int);
    ~String();
};

String::String()
{
    s = NULL;
    razmer = 0;
}

String::String(const char* str)
{
    razmer = strlen(str)+1;
    s = new char[razmer];
    strcpy_s(s, razmer, str);

}

String::String(const String& str1)
{
    razmer = str1.razmer;
    s = new char[razmer];
    strcpy_s(s, razmer, str1.s);
}





String::~String()
{    //delete[] s;
}



String operator++(const String& str)
{
    
    int i;
    int razmer = str.razmer;

    for (i = 0; i < razmer; i++)
    {
        str.s[i] = tolower(str.s[i]);
        cout << " " << str.s[i];
    }
    cout << endl;
    return str.s;
}



String operator++(const String& str, int)
{
    int i;
    int razmer = str.razmer;
    String up(str.s);
    for (i = 0; i < razmer; i++)
    {
        str.s[i] = toupper(str.s[i]);
        cout << " " << str.s[i];
    }
    cout << endl;
    return str.s;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    String strokalow("StrOkaToLoWerAndUppER");
    ++strokalow;
   
    String strokaup = strokalow;
  
  strokaup++;

}

