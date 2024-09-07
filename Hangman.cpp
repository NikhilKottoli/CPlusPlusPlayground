#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
void drawHangman(int stage) {
    switch (stage) {
        case 0:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      " << endl;
            cout << " |      " << endl;
            cout << " |      " << endl;
            cout << "_|_" << endl;
            break;
        case 1:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |      " << endl;
            cout << " |      " << endl;
            cout << "_|_" << endl;
            break;
        case 2:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |      |" << endl;
            cout << " |      " << endl;
            cout << "_|_" << endl;
            break;
        case 3:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |     /|" << endl;
            cout << " |      " << endl;
            cout << "_|_" << endl;
            break;
        case 4:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\" << endl;
            cout << " |      " << endl;
            cout << "_|_" << endl;
            break;
        case 5:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\" << endl;
            cout << " |     / " << endl;
            cout << "_|_" << endl;
            break;
        case 6:
            cout << "  ______" << endl;
            cout << " |      |" << endl;
            cout << " |      O" << endl;
            cout << " |     /|\\" << endl;
            cout << " |     / \\" << endl;
            cout << "_|_" << endl;
            break;
    }
}
int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int x = rand() % 20 + 1;//0-20

    ifstream in("words.txt");
     
    string word;

    for (int i = 0; i < x; i++) {
        getline(in, word);
    }
    string copy;
    copy = word;
    string dash(word.length(),'_');
    //word selected
    int s;
    for(int i=0;i<6;){
      cout << "Enter your guess:\n";
      char temp;cin >> temp;
      s=1;
      for(int j=0;j<word.length();j++){
        if(temp==copy[j]){
          copy[j]='\0';
          dash[j]=temp;
          s=0;
        }
      }
      if(s){
        i++;
        drawHangman(i);
      }
      if(dash==word){
      cout << "CONTRATS NIGGA YOU WON\n";
      s=2;break;
    }
    cout << dash << endl;
    }
    s!=2 ? cout << "YOU LOST The word was " << word:cout << "";
    
    in.close();//file closed

    return 0;
}
