#include <iostream>
#include <cstring>
#include <string>
#include <limits>

using namespace std;

//functions prototypes
void display(char* array);

char* delete_text(char* source, int index, int n);

char* delete_text_helper(char* source, char* target);

char* insert_text(char* source, const char* to_insert, int index);

void remove_vowels(char* source);

void tokenize(const char* source, const char* delims);


int main() {
    const int MAX_LENGTH = 100;
    int insertion_position = 0;
    string source {};
    string target {};

    char chosen_option ['Q'];

    cout << "Enter the source string: "<< std::endl;
    getline(cin, source);

    int n = source.length();

    // declaring character array
    char source_array[n+1];

    // copying the contents of the
    // string to char array
    strcpy(source_array, source.c_str());
    display(source_array);
    source.clear();

    string options = "<Enter D(Delete), I(Insert), T(Tokenize), V(Vowel Removal) or Q(Quit)> ";

    while (true) {
        cout << options<< std::endl;
        cin>>chosen_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <--- Requires header file <limits>.

        cout << "> " << chosen_option <<endl;
        if (chosen_option[0] == 'D') {
            cout << "String to delete> "<< endl;
            getline(cin, target);

            n = target.length();

            // declaring character array
            char target_array[n+1];

            // copying the contents of the
            // string to char array
            strcpy(target_array, target.c_str());
            display(target_array);
            target.clear();

            char *arr_ptr = delete_text_helper(source_array, target_array);
            display(arr_ptr);
        }
        else if (chosen_option[0] == 'I') {
            cout << "String to insert> ";

            cout << "Position of insertion> ";
            cin >> insertion_position;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // <--- Requires header file <limits>.


        }
        else if (chosen_option[0] == 'V') {
            cout << "chosen_option" << chosen_option;


        }
        else if (chosen_option[0] == 'F') {
            cout << "String to find> ";

            cout << "Position of insertion> ";
            cin >> insertion_position;

        }
        else if (chosen_option[0] == 'T') {
            cout << "Select a delimiter> ";
//            std::cin.getline(target, MAX_LENGTH, '\n');

        }
        else if (chosen_option[0] == 'Q') {
            break;
        }
        else
            continue;

    }

    return 0;
}

char* delete_text_helper(char* source, char* target) {
    char* ptr{nullptr};
    ptr = strstr(source, target); // ptr to the matched array
    if (ptr == nullptr) {
        cout << "Entered ###";
        return nullptr;
    }
    int position = ptr - source; // index of the first matched char in target array
    char* result_ptr = delete_text(source, position, strlen(target));
    return result_ptr;
}


char* delete_text(char* source, int index, int n) {
    int source_length = strlen(source);
//    cout<< "source length "<<std::strlen(source)<<endl;
//    cout<< "n "<<n<<endl;

    char* arr{nullptr};
    int arr_len = source_length - n + 1;
    arr = new char[arr_len];
//    cout<< "arr length "<<std::strlen(arr)<<endl;
//    cout<< "Array length "<<source_length - n + 1<<endl;
    int c = 0;
    for (int i = 0; i < index; ++i) {
        arr[i] = source[i];
        c++;
    }

    for (int j = index + n; j < source_length; ++j) {
//        cout<< "source [j] "<<source[j]<<endl;
//        cout<< "c "<<c<<endl;
        arr[c] = source[j];
        c++;
    }
    return arr;
}

char* insert_text(char* source, const char* to_insert, int index) {

}


void remove_vowels(char* source) {
    return;
}

void tokenize(const char* source, const char* delims) {
    return;
}


void display(char* array) {
    while (*array != '\0')
        cout << *array++;
    cout << endl;
}