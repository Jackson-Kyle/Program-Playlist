#include "PlaylistNode.h"
#include <iostream>
#include <string>
using namespace std;
      PlaylistNode::PlaylistNode(){
         uniqueID = "none";
         songName = "none";
         artistName = "none";
         songLength = 0;
         nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string ID, string song, string artist, int length){
         uniqueID = ID;
         songName = song;
         artistName = artist;
         songLength = length;
         nextNodePtr = 0;}
      string PlaylistNode::GetID() 
      {
            return uniqueID;
      }
      string PlaylistNode::GetSongName() {
         return songName;
      }

      string PlaylistNode::GetArtistName() {
         return artistName;
      }

      int PlaylistNode::GetSongLength() {
         return songLength;
      }
      
      PlaylistNode* PlaylistNode::GetNext(){
         return nextNodePtr;
      }
      
      void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
         PlaylistNode* tmpnext = nullptr;
         tmpnext = this->nextNodePtr;    
          this->nextNodePtr = nodePtr;    
         nodePtr->nextNodePtr = tmpnext;
      }
      
      void PlaylistNode::SetNext(PlaylistNode* nodePtr){
         nextNodePtr = nodePtr;
      }
      
      void PlaylistNode::PrintPlaylistNode(){
         cout << "Unique ID: " << uniqueID << endl;
         cout << "Song Name: " << songName << endl;
         cout << "Artist Name: " << artistName << endl;
         cout << "Song Length (in seconds): " << songLength << endl;
      }
   
         
