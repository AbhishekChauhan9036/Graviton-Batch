/*
    // Alphabet size (# of symbols) 
    static final int ALPHABET_SIZE = 26; 
  static class TrieNode 
    { 
        TrieNode[] children = new TrieNode[ALPHABET_SIZE]; 
       
        // isEndOfWord is true if the node represents 
        // end of a word 
        boolean isEndOfWord; 
          
        TrieNode(){ 
            isEndOfWord = false; 
            for (int i = 0; i < ALPHABET_SIZE; i++) 
                children[i] = null; 
        } 
    }; 
*/
 static void insert(TrieNode root,String key) 
{ 
    TrieNode temp=root;
        for (int i = 0; i < key.length(); i++) {
            int index = key.charAt(i) - 'a';
            if (temp.children[index] == null)
                temp.children[index] = new TrieNode();
            temp = temp.children[index];
        }
        temp.isEndOfWord = true;
}    
       
 static void removeElement(TrieNode root,String key)
{       
   TrieNode temp=root;
   for(int i =0;i<key.length();i++){

       int index=key.charAt(i)-'a';
    if(temp.children[index]==null){
        return;
    }
    temp=temp.children[index];
   }

    temp.isEndOfWord=false;

    }
   
   


static int search(TrieNode root,String key) 
{ 
    TrieNode temp=root;
    for (int i = 0; i < key.length(); i++) {
    int index = key.charAt(i) - 'a';
    if (temp.children[index] == null){
    return 0;
  }
    temp = temp.children[index];
  }
  if(temp.isEndOfWord){
      return 1;
  }
  return 0;

 }

   static boolean isEmpty(TrieNode root)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            if (root.children[i] != null)
                return false;
        return true;
    }