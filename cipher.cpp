#include<bits/stdc++.h>
using namespace std;
int numberOfBogus = -1;
string encrypt(string &Plaintext, vector<int> &key){ if(numberOfBogus == -1){
numberOfBogus = key.size() - Plaintext.size() % key.size(); char BogusChar = 'z';
for(int i=0; i<numberOfBogus; i++) Plaintext += BogusChar;
}
string cipherText = "";
for(int i=0; i<Plaintext.size(); i += key.size()){ /// per group string subCipher = "";
for(int j=0; j<key.size(); j++)
    string subCipher ;
string subCipher += Plaintext[i + key[j] - 1];
cipherText += subCipher;
}
return cipherText;
}
string decrypt(string &cipherText, vector<int> &key){ vector<pair<int, int> > keyWithPostion;
for(int i=1; i<=key.size(); i++){ keyWithPostion.push_back({key[i-1], i});
}
sort(keyWithPostion.begin(), keyWithPostion.end()); vector<int> key2;
for(int i=0; i<keyWithPostion.size(); i++) key2.push_back(keyWithPostion[i].second); string Plaintext = encrypt(cipherText, key2); //Bogus shoho

return Plaintext.substr(0, Plaintext.size()-numberOfBogus); //Remove Bogus.
}

string Capital(string str){
for(int i=0; i<str.size(); i++){ str[i] = (char)(str[i] - 32);
}
return str;
}
string validation(string &str){ string valid = "";
for(int i = 0; i<str.size(); i++){
if(str[i] >= 'a' && str[i] <= 'z') valid += str[i];
else if(str[i] >= 'A' && str[i] <= 'Z') valid += (str[i] + 32); else continue;
}
return valid;
}
int main(){
string Plaintext, cipherText, ResultPlaintext; cout<<"Input Your PlainText String: "; getline(cin, Plaintext);
Plaintext = validation(Plaintext);
cout<<endl<<"Your PlainText is: "<<Plaintext<<endl; vector<int>key {3, 1, 4, 5, 2}; cout<<endl<<"Encryption: ";
cipherText = encrypt(Plaintext, key); cout<<"(Done)"<<endl;
cout<<"CipherText (Encrypted Result) = "<<Capital(cipherText)<<endl<<endl; cout<<"Decryption: ";
ResultPlaintext = decrypt(cipherText, key); cout<<"(Done)"<<endl;
cout<<"Decryption Result Plaintext = "<<ResultPlaintext<<endl; return 0;
}

