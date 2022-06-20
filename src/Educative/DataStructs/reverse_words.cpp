#include <iostream>
#include <string>
#include <vector>

using namespace std;

void ReverseWords(string str) {
	//TODO: Write - Your - Code
	string output_str;
    size_t p;

    while(!str.empty()) {
        p = str.find_last_of(" ");
        cout << p << endl;

        if(p == string::npos) {
            output_str.append(str);
            str.clear();
        }
            
        else {
            output_str.append(str.substr(p+1, str.size()));
            str.erase(p+1, str.size());
        }
        
        cout << output_str;
    }
    
    
	
	
}

int main(int argc, char const *argv[])
{
    string s("Hello World");
    ReverseWords(s);
    return 0;
}
