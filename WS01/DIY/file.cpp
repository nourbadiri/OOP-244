#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace quizzer{
const char* filename = "quiz2.txt";

}

int main() {
    
int LoadQuiz(const char* filename);
   fstream filename;
    filename.open("quiz2.txt", ios::in);
    if(filename.is_open()){
        string line;
        while(getline(filename, line)){
            cout<<line<<endl;
        }
        filename.close();
    }
    
       if (line.Length == 0)
   return 0;
}