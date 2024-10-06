#include <iostream>
#include <cstring>

class MyString {
  
public:
    char* str;
    MyString() {
        str = new char[80];
        str[0] = '\0';
    }
    MyString(const char* input) {
        size_t length = strlen(input) + 1;
        str = new char[length];
        strcpy_s(str, length, input);
    }
    ~MyString() {
        delete[] str;
    }
    void input() {
        std::cin.getline(str, 80);
    }

    void output() {
        std::cout << str << std::endl;
    }
    void MyStrcpy(MyString& obj) {
        delete[] obj.str;
        size_t length = strlen(str) + 1;
        obj.str = new char[length];
        strcpy_s(obj.str, length, str);
    }
    void MyStrCat(MyString& b) {
        size_t newSize = strlen(str) + strlen(b.str) + 1;
        char* newStr = new char[newSize];
        strcpy_s(newStr, newSize, str);
        strcat_s(newStr, newSize, b.str);
        delete[] str;
        str = newStr;
    }
};
int main() {
    MyString str1;
    str1.input();
    str1.output();
    MyString str2("HELLOW BROTHER");

    str2.output();
    str1.MyStrcpy(str2);
    str1.output();
    str1.MyStrCat(str2);
    str1.output();
 return 0;
}
