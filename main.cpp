#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <stdio.h>

using namespace std;

//functions prototypes
void display(const char* array, size_t size);

char* delete_text(char* source, int index, int n);

char* delete_text_helper(char* source, char* target);

char* insert_text(char* source, const char* to_insert, int index);

void remove_vowels(char* source);

void tokenize(const char* source, const char* delims);


int main() {
//    const int MAX_LENGTH = 100;
    int insertion_position = 0;
    string source{};
    string target{};

    char chosen_option = 'Q';

    cout << "Enter the source string: " << std::endl;
    getline(cin, source);

    int str_size = source.length();

    // declaring character array
    char source_array[str_size + 1];

    // copying the contents of the
    // string to char array
    strcpy(source_array, source.c_str());
    char *source_array_ptr = source_array;

    display(source_array, str_size);
//    source.clear();

    string options = "<Enter D(Delete), I(Insert), F(Find), T(Tokenize), V(Vowel Removal) or Q(Quit)> ";

    while (true) {
        cout << options << std::endl;
        cin >> chosen_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "> " << chosen_option << endl;
        if (chosen_option == 'D') {
            cout << "String to delete> " << endl;
            getline(cin, target);

            size_t target_len = target.length();

            // declaring character array
            char target_array[target_len + 1];

            // copying the contents of the
            // string to char array
            strcpy(target_array, target.c_str());
            char *target_array_ptr = target_array;

            target.clear();

//            char* arr_ptr = delete_text_helper(source_array_ptr, target_array_ptr);
            source_array_ptr = delete_text_helper(source_array, target_array);
            str_size = strlen(source_array_ptr);
            display(source_array_ptr, str_size);

        } else if (chosen_option == 'I') {

            cout << "String to insert> " << endl;
            getline(cin, target);

            cout << "Position of insertion> ";
            cin >> insertion_position;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            size_t target_len = target.length();

            // declaring character array
            char target_array[target_len + 1];

            // copying the contents of the
            // string to char array
            strcpy(target_array, target.c_str());
            size_t target_size = strlen(target_array);
            char *target_array_ptr = target_array;

            target.clear();

            display(target_array_ptr, target_size);

            source_array_ptr = insert_text(source_array_ptr, target_array_ptr, insertion_position);

            display(source_array_ptr, str_size);

        } else if (chosen_option == 'V') {
            cout << "chosen_option" << chosen_option<<endl;

            remove_vowels(source_array);
            display(source_array, str_size);

        } else if (chosen_option == 'F') {
            cout << "String to find> ";
            getline(cin, target);

            // Find first occurrence of "geeks"
            size_t found = source.find(target);
            if (found != string::npos){
                size_t target_length = target.length();
                char result[target_length+1];
                for (int i = 0; i < target_length; ++i) {
                    result[i] = source.at(i+found);
                }
                display(result, target_length+1);

            }


        } else if (chosen_option == 'T') {
            cout << "Select a delimiter> ";
            getline(cin, target);

            size_t target_len = target.length();

            // declaring character array
            char target_array[target_len + 1];

            // copying the contents of the
            // string to char array
            strcpy(target_array, target.c_str());
            size_t target_size = strlen(target_array);
            char *target_array_ptr = target_array;

            target.clear();

            char *token;

            /* get the first token */
            token = strtok(source_array_ptr, target_array_ptr);

            /* walk through other tokens */
            while( token != nullptr ) {
//                printf( " %s\n", token );
                cout<<token<<endl;
                token = strtok(nullptr, target_array_ptr);
            }



        } else if (chosen_option == 'Q') {
            break;
        } else
            continue;

    }

    return 0;
}

char* delete_text_helper(char* source, char* target) {
    char *matched_ptr = strstr(source, target); // ptr to the matched array
    if (matched_ptr == nullptr) {
//        cout << "Entered ###";
        return source;
    }
    // index of the first matched char in target array
    int position = matched_ptr - source;
    char *result_ptr = delete_text(source, position, strlen(target));
    return result_ptr;
}


char* delete_text(char* source, int index, int n) {
    size_t source_length = strlen(source);
    size_t arr_len = source_length - n;
    string result_str (arr_len, 'a');
//    strcpy(result_str)
//    char* arr = new char[arr_len];

    int c = 0;
    for (int i = 0; i < index; ++i) {
        result_str.at(i) = source[i];
        c++;
    }

    for (int j = index + n; j < source_length; ++j) {
//        arr[c] = source[j];
        result_str.at(c) = source[j];
        c++;
    }

    // declaring character array
    char source_array[arr_len];


    strcpy(source_array, result_str.c_str());
    char *source_array_ptr = source_array;
    result_str.erase();

    return source_array_ptr;
}


char* insert_text(char* source, const char* to_insert, int index) {
    int size_of_source = strlen(source);
    int size_of_insert = strlen(to_insert);
    int new_source_length = size_of_source + size_of_insert;
    string result_str (new_source_length, 'a');
    int counter = 0;
    for (int i = 0; i < index; ++i) {
        result_str.at(counter) = source[i];
        counter++;
    }

    for (int i = 0; i < size_of_insert; ++i) {
        result_str.at(counter) = to_insert[i];
        counter++;
    }

    for (int i = index; i < size_of_source; ++i) {
        result_str.at(counter) = source[i];
        counter++;
    }

    // declaring character array
    char source_array[new_source_length];


    strcpy(source_array, result_str.c_str());
    char *source_array_ptr = source_array;
    result_str.erase();

    return source_array_ptr;
}


void remove_vowels(char* source) {
    int source_len = strlen(source);
//    string new_source {};
//    int counter{0};
    for (int i = 0; i < source_len; ++i) {
        if (source[i] == 'a' || source[i] == 'A' || source[i] == 'e' || source[i] == 'E' || source[i] == 'i'
            ||source[i] == 'I' || source[i] == 'o' || source[i] == 'O' || source[i] == 'u' || source[i] == 'U')
        {
            for(int j=i; j<source_len; j++)
            {
                source[j]=source[j+1];
            }
            --source_len;
            --i;
        }

    }
}

void tokenize(const char* source, const char* delims) {
    return;
}


void display(const char* array,  size_t size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i];
    }
    cout << endl;
}
