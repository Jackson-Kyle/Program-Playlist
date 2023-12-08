//https://github.com/Jackson-Kyle/Program-Playlist/tree/3484c36d8a4a53ac4efd1362ad8cd6c167ba52e6 - Kyle Jackson
#include <iostream>
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
cout << "a - Add song" << endl;
cout << "d - Remove song" << endl;
cout << "c - Change position of song" << endl;
cout << "s - Output songs by specific artist" << endl;
cout << "t - Output total time of playlist (in seconds)" << endl;
cout << "o - Output full playlist" << endl;
cout << "q - Quit" << endl;
cout << endl;
cout << "Choose an option:" << endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
  string playlist = playlistTitle;
  char input = option;
  PlaylistNode* lastNode = nullptr;
   while(true){
      PrintMenu(playlist);
      cin >> input;
    if(input == 'q'){
     break;}
    else if(input == 'a'){
      string id, song, artist;
      int length;
      
      
     
      
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      
      cout << "Enter song's name:" << endl;
      getline(cin, song);
      
      cout << "Enter artist's name:" << endl;
       getline(cin, artist);
       
      cout << "Enter song's length (in seconds):" << endl;
      cin >> length;
      
      PlaylistNode* temp = new PlaylistNode(id, song, artist, length);
      if(headNode == nullptr){
         headNode = temp;
         lastNode = temp;}
         else{lastNode->SetNext(temp);
         lastNode = temp;}
         
      cout << endl;
      
      }
     else if(input == 'd'){
         cout << "REMOVE SONG" << endl;
         cout << "Enter song's unique ID" << endl;
         string s;
         cin >> s;
         for(PlaylistNode* i = headNode; i != nullptr; i->GetNext()){
            if(i->GetNext()->GetID() == s){
               PlaylistNode* temp = i->GetNext();
               string songt;
               songt = i->GetNext()->GetSongName();
               i->SetNext(i->GetNext()->GetNext());
               delete temp;
               cout << "\"" << songt << "\"" << " removed. " << endl;
               break;}
               if(s == i->GetID()){
                  if(i==headNode){
                     PlaylistNode* temp = headNode->GetNext();
                     delete headNode;
                     headNode = temp;
                     break;}
               }
         }
        
      }
     else if(input == 's'){
         cout << "OUTPUT SPECIFIC SONGS BY ARTIST" << endl;
         cout << "Enter artist's name:" << endl;
         cout << endl;
         string name;
         getline(cin, name);
         int count = 1;
         for( PlaylistNode* i = headNode; i != nullptr; i->GetNext()){
            if(i->GetArtistName() == name){
               cout << count << "." << endl;
              
               i->PrintPlaylistNode();
               cout <<endl;}
                count++;
         }
      
      
      }
     else if(input == 't'){
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
         cout <<"Total time: ";
         if(headNode == nullptr){
            cout << "0" << endl;}
            else{int sum =0;
            for(PlaylistNode* i = headNode; i != nullptr; i->GetNext()){
               sum += i->GetSongLength();}
               cout << sum;}
            cout << " seconds" << endl;
            cout <<endl;
          }
     else if(input == 'o'){
        cout << playlist << " - OUTPUT FULL PLAYLIST" << endl;
      if(headNode == nullptr){
      cout << "Playlist is empty" << endl;}
      else{ 
     int count = 1;
     for(PlaylistNode* i = headNode; i != nullptr; i->GetNext()){
        cout << count << "." << endl;
        count++;
        i->PrintPlaylistNode();
        if(i->GetNext()!=nullptr){
           cout << endl;}
          
         }
      }
      cout <<endl;
         }
   }
   
   
     return nullptr;
   
}

int main() {
   string playlist;
   char input;
   cout << "Enter playlist's title:" << endl;
   cout << endl;
   getline(cin, playlist);
   
   PlaylistNode* headNode = nullptr;
   ExecuteMenu(input, playlist, headNode);
   
   return 0;
}

