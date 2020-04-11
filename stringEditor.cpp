// string_manipulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;


char* delete_text(char* source, int index, int n);
char* insert_text(char* source, const char* to_insert, int index);
void remove_vowels(char* source);
int find_text(char* source, char* to_find);
void tokenize(const char* source, char delims);



int main()
{
    const int MAX_LEN{ 100 };
    char source[100]{ 0 };
    char* source_ptr{ nullptr };
    source_ptr = source;
    cout << "Enter a string: ";
    cin.get(source_ptr, MAX_LEN);

    bool if_Quit{ false };
    char choice{ 0 };
    while (!if_Quit) {
        cout << "Enter D(Delete), I(Insert), F(Find), T(Tokenize), V(Vowel Removal) or Q(Quit) : ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'D') {
            //cin >> ws;
            char strToD[MAX_LEN]{ 0 };
            cout << "string to delete : ";
            cin.get(strToD, MAX_LEN);
            int index = find_text(source_ptr, strToD);
            source_ptr = delete_text(source_ptr, index, strlen(strToD));
            cout << "New String is : " << source_ptr << endl;
        }
        else if (choice == 'I') {
            cout << "String to insert : ";
            char strToI[MAX_LEN]{ 0 };
            char* to_insert_ptr{ strToI };
            cin.get(strToI, MAX_LEN);
            int index{ 0 };
            cout << "Position of insertion : ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            source_ptr = insert_text(source_ptr, to_insert_ptr, index);
            cout << "New String is : " << source_ptr << endl;

        }
        else if (choice == 'F') {
            char strToF[MAX_LEN]{ 0 };
            char* to_find_ptr{ strToF };
            cout << "string to find : ";
            cin.get(strToF, MAX_LEN);
            find_text(source_ptr, to_find_ptr);
        }
        else if (choice == 'T') {
            char delim = ' ';
            cout << "select a delimiter : ";
            cin >> delim;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            tokenize(source_ptr, delim);

        }
        else if (choice == 'V') {
            remove_vowels(source_ptr);
        }
        else if (choice == 'Q') {
            if_Quit = true;
            source_ptr = nullptr;
        }
        else {
            cout << "please try again" << endl;
        }

    }

    return 0;
}

char* delete_text(char* source, int index, int n) {
    for (auto i = index; i < strlen(source); i++) {
        source[i] = source[i + (n + 1)];
    }
    return source;
}
int find_text(char* source, char* to_find) {
    int key{ 0 };
    int CorrectInRow{ 0 };
    int index{ 0 };
    for (unsigned int i = 0; i < strlen(source); i++) {
        if (source[i] == to_find[key]) {
            CorrectInRow++;
            key++;
            index = i;
            if (CorrectInRow == strlen(to_find)) {
                std::cout << "found '" << to_find << "' At: " << (index - CorrectInRow) + 1 << std::endl;
                break;
            }
        }
        else {
            key = 0;
            CorrectInRow = 0;
        }
    }
    return (index - CorrectInRow) + 1;

}
char* insert_text(char* source, const char* to_insert, int index) {
    int sizeOfOriginalArray = strlen(source);
    int lenO = sizeOfOriginalArray + strlen(to_insert) + 1;
    int insertLen = strlen(to_insert);
    char* newArray{ new char[lenO] {} };

    for (auto i = 0; i <= sizeOfOriginalArray; ++i)
    {
        if (i < index)
        {
            newArray[i] = source[i];
        }

        if (i == index)
        {
            for (auto j = i; j < insertLen + i; j++) {
                int z = j - i;
                newArray[j] = to_insert[z];
            }

        }

        if (i > index)
        {
            newArray[i + insertLen - 1] = source[i - 1];
        }
    }
    return newArray;
}
void remove_vowels(char* source) {
    int len = strlen(source);

    for (auto i = 0; i < len; i++) {
        if (source[i] == 'a' || source[i] == 'e' || source[i] == 'i' ||
            source[i] == 'o' || source[i] == 'u' || source[i] == 'A' ||
            source[i] == 'E' || source[i] == 'I' || source[i] == 'O' ||
            source[i] == 'U') {
            for (int j = i; j < len; j++) {
                source[j] = source[j + 1];
            }
            len--;
            i--;
        }
    }

    cout << source << endl;

}
void tokenize(const char* source, char delims) {
    int count{ 0 };
    int c{ 0 };
    char* newarr{ new char[strlen(source)] {} };
    for (auto i = 0; i < strlen(source); i++) {
        if (source[i] == delims) {
            cout << "Token " << count << ":  ";
            cout << newarr << endl;
            count++;
            for (auto j = 0; j < strlen(source); j++) {
                newarr[j] = '\0';
            }
            c = 0;

        }
        else {
            newarr[c] = source[i];
            c++;
        }
        if (i == strlen(source) - 1) {

            cout << "Token " << count << ":  ";
            cout << newarr << endl;

        }
    }
    delete[] newarr;

}
