/**
* [Suha Cho]
* [BookPile.cpp]
**/

#include "BookPile.h"

BookPile::BookPile(): topPtr(nullptr), itemCount(0)
{
} //end default constructor


BookPile::BookPile(const BookPile& bookPile)
{
    if (bookPile.itemCount == 0)
    {
        topPtr = nullptr; //original stack is empty
        itemCount = 0;
    }
    else
    {
        Book* curPtr = new Book;  //create a new node
        Book* curCopyPtr = bookPile.topPtr; //point to nodes in original chain
        topPtr = curPtr;
        itemCount = bookPile.itemCount; //copy the itemCount

        for (int i = 1; i <= itemCount; i++)
        {
            curPtr->setTitle(curCopyPtr->getTitle()); //copy the nodes
            if (curCopyPtr->getNext() == nullptr) //if the current copy pointer meets the end,
            {
                break; //ends the loop
            }
            curCopyPtr = curCopyPtr->getNext(); // Advance current copy pointer
            Book* newPtr = new Book; //create a new node
            curPtr-> setNext(newPtr); //link new node
            curPtr = newPtr;
        }
    }
} //end copy constructor


BookPile::~BookPile()
{
     clear();
} //end destructor


int BookPile::getTitleLength(std::string title)
{
    return title.length(); //returns the number of characters in the parameter
} //end getTitleLength

bool BookPile::removeBook(std::string entry)
{
  bool didRemove = false;

  if (findBook(entry) == -1)
  {
      return didRemove;
  }

  Book* delPtr = topPtr;
  if (topPtr->getTitle() == entry)
  {
      //when the book to be removed is the head node in the chain
      topPtr = delPtr->getNext();
      delete delPtr;
      didRemove = true;
  }
  else {
      Book* curPtr = topPtr;
      Book* delPtr = curPtr->getNext();
      for (int i = 1; i <= itemCount; i++)
      {

          //When the book to be removed isn’t the head node
          if (delPtr->getTitle() == entry)
          {
              curPtr->setNext(delPtr->getNext());
              delete delPtr;
              itemCount--;
              break;
          }
          else {
              curPtr =curPtr->getNext();
              delPtr = curPtr->getNext();
          }
      }
      didRemove = true;
  }

  return didRemove;
} //end removeBook


bool BookPile::removeBook(int position)
{
  bool didRemove = false;

  if (position >= 1 && position <= itemCount && itemCount > 0)
  {
    //when the book to be removed is the head node in the chain
    if (position == 1)
    {
      Book* delPtr = topPtr;
      topPtr = delPtr-> getNext();
      delete delPtr;
    }

    //When the book to be removed isn’t the head node
    else
    {
      Book* curPtr = getNodeAt(position - 1);
      Book* delPtr = curPtr -> getNext();

      curPtr ->setNext(delPtr-> getNext());

      delete delPtr;
    }

    didRemove = true;
    itemCount--;
  }

  return didRemove;
} //end removeBook


Book* BookPile::getNodeAt(int position)
{
  if (position > itemCount || position < 1)
  {
    return nullptr;
  }

  Book* curPtr = topPtr;
  for (int i = 1; i < position; i++)
  {
    curPtr = curPtr ->getNext();
  }

  return curPtr;
} //end getNodeAt


bool BookPile::addBook(std::string newEntry)
{
    bool didadd = false;
    string s = "";

    if (newEntry != s && findBook(newEntry) == -1)
    {
        Book* newNode = new Book(newEntry);

        if (itemCount == 0)
        {
            topPtr = newNode;
        }

    //adding a new head node
    else if (itemCount == 1)
      {
              if (getTitleLength(topPtr->getTitle()) >= getTitleLength(newEntry))
              {
                  topPtr->setNext(newNode);
              }
              else
              {
                  newNode->setNext(topPtr);
                  topPtr = newNode;
              }
      }
    //adding a node in any other position
    else
    {
              if (getTitleLength(newEntry) >= getTitleLength(topPtr->getTitle()))
              {
                  newNode->setNext(topPtr);
                  topPtr = newNode;
              }
              else
              {
                  Book* curPtr = topPtr;
                  Book* nextPtr = topPtr->getNext();

                  for (int i = 1; i <= itemCount; i++)
                  {
                      if (i == itemCount) //last node
                      {
                          curPtr->setNext(newNode);
                          break;
                      }
                      else if (getTitleLength(curPtr->getTitle()) >= getTitleLength(newEntry) && getTitleLength(nextPtr->getTitle()) <= getTitleLength(newEntry))
                      {
                          curPtr->setNext(newNode);
                          newNode->setNext(nextPtr);
                      }
                      else
                      {
                          curPtr = nextPtr;
                          nextPtr = curPtr->getNext();
                      }
                  }
              }
          }

      itemCount++;
      didadd = true;
    }
    return didadd;

} // end addBook


int BookPile::findBook(std::string entry)
{
    int position = -1;
    if (itemCount != 0) {
        Book* curPtr = topPtr;
        for (int i = 1; i <= itemCount; i++)
        {
            if (curPtr->getTitle() == entry)
            {
                position = i;
                break;
            }
            else
                curPtr = curPtr->getNext();
        }
    }
    return position;
} // end findBook


void BookPile::displayPile()
{
    if (topPtr == nullptr)
    {
        cout << "Book Pile is empty." << endl;
    }
    else
    {
        Book* curPtr = topPtr;
        for (int i = 1; i <= itemCount; i++)
        {
            cout << i << ". " << curPtr->getTitle() << "  "
            << "(" << getTitleLength(curPtr->getTitle()) << ")" << endl;

            curPtr = curPtr-> getNext();
        }
    }
} // end displayPile


string BookPile::getBook(int position)
{
    string s = "";
    Book* curPtr = topPtr;
    for (int i = 1; i <= itemCount; i++)
    {
        if (i == position)
        {
            return curPtr->getTitle();
        }
        else
            curPtr = curPtr->getNext();
    }
    return s;
} //end getBook


bool BookPile::renameBook(std::string oldName, std::string newName)
{
  bool didRename = false;
    string s = "";
    //doesn’t change if newName is empty string or if the book with oldName is not found
    if (newName == s || findBook(oldName) == -1)
    {
      return didRename;
    }

    else
    {
      Book* curPtr = topPtr;

      for (int i = 1; i <= itemCount; i++)
      {
          if (oldName == curPtr-> getTitle())
          {
              curPtr-> setTitle(newName); //replace the name
              didRename = true;
              break;
          }
          else
          {
              curPtr = curPtr-> getNext();
          }
      }
    }
    return didRename;

} //end renameBook


int BookPile::bookCount()
{
  return itemCount;
} //end bookCount


void BookPile::clear()
{
    if (itemCount != 0)
    {
        Book* curPtr = topPtr;
        Book* tempPtr;

         //removes books from the pile
        for (int i = 1; i <= itemCount; i++)
        {
            tempPtr = curPtr;
            curPtr = curPtr-> getNext();
            delete tempPtr;
            tempPtr = nullptr;
        }
        itemCount = 0;
    }
} //end clear
