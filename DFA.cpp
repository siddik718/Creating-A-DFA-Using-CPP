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
    cout << "Enter the states: ";
    char str[2],ch=' ';
    while(ch != '\n'){
        scanf("%s%c",str,&ch);
        states.push_back(str);
    }
    char c;ch=' ';
    cout<<"Enter the alphabet: ";
    while(ch != '\n'){
        scanf("%c%c",&c,&ch);
        alphabet.push_back(c);
    }
    cout<<"Enter the start_states: ";
    cin>>start_state;
    ch = ' ';
    cout<<"Enter the Final_states: ";
    while(ch != '\n'){
        scanf("%s%c",str,&ch);
        finalstates.insert(str);
    }
    cout<<"Fill the Transition Table: \n";
    for(auto state : states){
        for(auto alpha : alphabet){
            cout << "State "<<state<<" moves for alphabet " << alpha << " to State : ";
            string s;cin >> s;
            transistates[{state,alpha}] = s;
        }
    }
    while(true){
        cout<<"Enter the input string: ";
        cin>>input;
        string current_state = start_state;
        int f = 1;
        for(int i = 0;i<input.length();i++){
            char ch = input[i];
            if(transistates.find({current_state,ch}) == transistates.end()){ // when we can't move to any state.
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
