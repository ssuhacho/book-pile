/**
* [Suha Cho]
* [BookPile.h]
**/


#ifndef BOOKFILE_H
#define BOOKFILE_H

#include <string>
#include "Book.h"
#include <iostream>
using namespace std;

class BookPile
{
private:
  	Book* topPtr; // Pointer to first node in the chain.
    int itemCount; // Current count of list items.

    /**
    * getTitleLength is a private method that returns the number of characters
      in the parameter including spaces and punctuation.
    * @param title is given book title.
    * @return the length of a title.
    * @pre this helper function should be used when other methods that need the length of a title.
    */
    int getTitleLength(std::string title);


public:
   BookPile(); //constructor
   BookPile(const BookPile& bookPile); //copy constructor that does a proper deep copy.
   ~BookPile(); //destructor

   /**
   * getNodeAt locates a specified node in this linked list.
   * @param position is the number of the node to locate.
   * @return A pointer to the node at the given position.
   * @pre position is the number of the desired node. Position >= 1 and position <= itemCount.
   */
   Book* getNodeAt(int position);

  /**
  * removeBook removes the book with title matching the parameter.
  * @param entry is the given book title.
  * @return true if book was removed, false if it was not.
  * @pre the book with title matching the parameter must be removed.
  */
   bool removeBook(std::string entry);

   /**
   * removeBook removes book at the parameter position where 1 is the top of the pile.
   * @param position is the given position.
   * @return true if book was removed, false if it was not.
   * @pre the book which is at the given position number must be removed.
   */
   bool removeBook(int position);

   /**
   * addBook adds book with the given title to the pile in the proper ordered location.
   * @param newEntry is the new book with the given title.
   * @return true if book was added, false if it was not.
   * @pre should not add the book to the pile if the title is empty string
   *      or the title already exists in the pile.
   */
   bool addBook(std::string newEntry);

   /**
   * findBook checks if the given title exists in the pile.
   * @param entry is the given book title.
   * @return the position of the book if it exists in the pile, -1 if it does not.
   */
   int findBook(std::string entry);

   /**
   * displayPile displays the books in the pile to the console.
   * @pre must be numbered and in order from the top of the pile to the bottom
      followed by the number of characters in their title.
      If there are no books in the pile display Book pile is empty.
   */
   void displayPile();

   /**
   * getBook gets the book title at the given position number.
   * @param position is the given position.
   * @return the book at the given position number and returns empty string if the position is invalid.
   */
   std::string getBook(int position);

   /**
   * renameBook changes the name of a book.
   * @param oldName is the old book title needs to be replaced.
   * @param newName is the new book title.
   * @return true if the book title was found and replaced, false otherwise.
   * @pre The pile doesn’t change if newName is empty string or if the book with oldName
      is not found in the pile.
   */
   bool renameBook(std::string oldName, std::string newName);

   /**
   * bookCount gets the number of books in the pile.
   * @return itemCount which is the number of books in the pile.
   */
   int bookCount();

   /**
   * clear removes all books from the pile.
   */
   void clear();


}; // end BookPile

#endif
