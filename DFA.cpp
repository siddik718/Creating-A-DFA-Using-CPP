#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
// DFA Implementation
int main(){
    vector<string>states;
    vector<char>alphabet;
    map<pair<string,char>,string>transistates;
    string start_state;
    set<string>finalstates;
    string input;
    cout<<"Enter the number of states: ";
    int n;cin >> n;
    cout << "Enter the states: ";
    for(int i=0;i<n;i++){
        string s;cin>>s;
        states.push_back(s);
    }
    cout<<"Enter the number of alphabet: ";
    int m;cin>>m;
    cout<<"Enter the alphabet: ";
    for(int i=0;i<m;i++){
        char c;cin>>c;
        alphabet.push_back(c);
    }
    cout<<"Enter the startstates: ";
    cin>>start_state;
    cout<<"Enter the number of final states: ";
    int M;cin>>M;
    cout<<"Enter the final states: ";    
    for(int i=0;i<M;i++){
        string c;cin>>c;
        finalstates.insert(c);
    }
    cout<<"Fill the Transition Table: \n";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << "State "<<states[i]<<" moves for alphabet " << alphabet[j] << " to State : ";
            string s;cin >> s;
            transistates[{states[i],alphabet[j]}] = s;
        }
    }
    while(true){
        cout<<"Enter the input string: ";
        cin>>input;
        string current_state = start_state;
        int f = 1;
        for(int i = 0;i<input.length();i++){
            char ch = input[i];
            if(transistates.find({current_state,ch}) == transistates.end()){
                cout<<"No transition found for " << current_state << " " << ch << endl;
                f = 0;
                break;
            }
            current_state = transistates[{current_state,ch}];
        }
        if(f){
            if(finalstates.find(current_state) != finalstates.end())
                cout<<"The string is accepted"<<endl;
            else
                cout<<"The string is not accepted"<<endl;
        }
        cout << "Do you want to continue? (y/n)? : ";
        char s;cin>>s;
        if(s == 'n')break;
    }
    return 0;
}