#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//functions prototypes
void display(char* array);
char* delete_text(char* source, int index, int n);
char* delete_text_helper(char* source, char* target);
void remove_vowels(char* source);
void tokenize(const char* source, const char* delims);



int main() {
    const int MAX_LENGTH = 100;
    const int MAX_LENGTH_OPTIONS = 1;
    char* source = new char[MAX_LENGTH];
    char* target = new char[MAX_LENGTH];
    char* chosen_option = new char[1];
    std::cout<<"Enter the source string:\n";
    std::cin.getline(source, MAX_LENGTH, '\n');
    string options_str = "<Enter D(Delete), I(Insert), T(Tokenize), V(Vowel Removal) or Q(Quit)> ";
    while(true){
        std::cout<<options_str;
        std::cin.getline(chosen_option, MAX_LENGTH_OPTIONS);
        std::cout<<"chosen_option"<<chosen_option;

        if (chosen_option[0] == 'D') {
            std::cout << "Enter your target: ";
            std::cin.getline(target, MAX_LENGTH, '\n');

            char* r = delete_text_helper(source, target);
            display(r);
        } else if (chosen_option[0] == 'I'){
            std::cout<<"chosen_option"<<chosen_option;

        } else if (chosen_option[0] == 'V'){
            std::cout<<"chosen_option"<<chosen_option;

        } else if (chosen_option[0] == 'Q'){
            break;
        } else{
            continue;
        }
    }

    return 0;
}

char* delete_text_helper(char* source, char* target) {
    char* ptr{nullptr};
    ptr = std::strstr(source, target); // ptr to the matched array
    if (ptr == nullptr) {
        cout << "Entered ###";
        return nullptr;
    }
    int position = ptr - source ; // index of the first matched char in target array

//    cout<<"display ptr"<<endl;
//    display(ptr);
//    cout<<"\nPostion of the first occurence "<<position<<endl;
//    cout<<"\n Target length "<<std::strlen(target)<<endl;
    char* result_ptr = delete_text(source, position, std::strlen(target));
    return result_ptr;
}


char* delete_text(char* source, int index, int n) {
    int source_length = std::strlen(source);
//    cout<< "source length "<<std::strlen(source)<<endl;
//    cout<< "n "<<n<<endl;

    char* arr {nullptr};
    int arr_len = source_length - n + 1;
    arr = new char[arr_len];
//    cout<< "arr length "<<std::strlen(arr)<<endl;
//    cout<< "Array length "<<source_length - n + 1<<endl;
    int c =0;
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


void remove_vowels(char* source){
    return;
}

void tokenize(const char* source, const char* delims){
    return;
}



void display(char* array) {
    while (*array != '\0')
        cout << *array++;
    cout << endl;
}