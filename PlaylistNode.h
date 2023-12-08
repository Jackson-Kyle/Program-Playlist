#ifndef PLAYLISTNODEH
#define PLAYLISTNODEH

#include <string>
using namespace std;

class PlaylistNode{
   public:
      PlaylistNode();
      
      PlaylistNode(string ID, string song, string artist, int length);

      string GetID() ;

      string GetSongName() ;

      string GetArtistName() ;

      int GetSongLength() ;
      
      PlaylistNode* GetNext();
      
      void InsertAfter(PlaylistNode* nodePtr);
      
      void SetNext(PlaylistNode* nodePtr);
      
      void PrintPlaylistNode();
      
      
   
   private:
      
   string uniqueID;
   string songName;
   string artistName;
   int songLength;
   PlaylistNode* nextNodePtr;
};

#endif
