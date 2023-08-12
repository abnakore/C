#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


typedef struct tries
{
    bool is_word;
    struct tries * next[26];
    
}
tries;


tries* HEAD = NULL;

// Prototype
tries* create();
void insert(char * word);
int indx(char letter);
bool search(char * word);
void list_all(tries * cur, char * word);


int main(void)
{
    // Creating the head of the trie
    HEAD = create();
    
    // An array that stores the names to insert
    char* names[10] = {"abdul", "muhsin", "khadijah", "abdullahi", "walida", "hassana", "mummy", "yusuf"};
    
    // inserting the names
    for(int i = 0; i < 7; i++)
    {
        insert(names[i]);
    }
    // Searching to see if it exist
    if(search("abdul"))
    {
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    
    // list all the inserted strings(names)
    list_all(HEAD, "");
}

tries * create()
{
    // Malloc space for the new node
    tries * node = malloc(sizeof(tries));
    node -> is_word = false;
    for(int i = 0; i < 26; i++)
    {
        node -> next[i] = NULL;
    }
    return node;
    
}


void insert(char * word)
{

    tries* ptr = HEAD;
    int length = strlen(word);
    int index;
    for(int i = 0; i < length; i++)
    {
        index = indx(word[i]);
        if(ptr -> next[index] == NULL)
        {
            ptr -> next[index] = create();
        }
        if(i == length - 1)
        {
            ptr -> is_word = true;
        }
        ptr = ptr -> next[index];
        // printf("%c: %d\n", word[i], indx(word[i]));
    }

}

int indx(char letter)
{
    if(isupper(letter))
    {
        return (letter % 'A');
    }
    return letter % 'a';
}

bool search(char * word)
{

    tries * ptr = HEAD;
    int length = strlen(word);
    int index;
    int steps = 0;
    for(int i = 0; i < length; i++)
    {
        index = indx(word[i]);
        steps++;
        if(ptr -> next[index] == NULL)
        {
            return false;
        }
        if(i == length - 1 && ptr -> is_word == true)
        {
            printf("%i\n", steps);
            return true;
        }
        ptr = ptr -> next[index];
        // printf("%c: %d\n", word[i], indx(word[i]));
    }
    return false;

}

void list_all(tries * cur, char * word)
{
    
    // The new word
    char * new_word = malloc((strlen(word) + 1) * sizeof(char));
      
    
    // Looping trough the 26 letters of the node
    for(int i = 0; i < 26; i++)
    {        
        if(cur -> next[i] != NULL)
        {
             // Copy the content of word to the new word
            strcpy(new_word, word);
            // Get the current letter
            char letter = i + 'A';
            // Concatenate the letter to it
            strncat(new_word, &letter, 1);
            
            // Call the list all recoursively
            list_all(cur -> next[i], new_word);
        }
    }
    if(cur -> is_word == true)
    {
        printf("%s\n", new_word);
    }
    
}
