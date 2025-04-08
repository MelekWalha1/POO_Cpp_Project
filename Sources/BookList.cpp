#include "../Headers/BookList.h"

BookList::BookList(){
    capacity =0;
    booksCount=0;
}
/////////////////////////////////
BookList::BookList(int a){
    capacity =a;
    booksCount=0;
    books = new Book[capacity];
}
/////////////////////////////////
void BookList::addBook(const Book & book){
    if(booksCount<capacity){
        books[booksCount]=book;
        books[booksCount].setId(booksCount+1);
        booksCount++;
    }else{
        cout << " memory exceeded"<<endl;
    }
}

/////////////////////////////////
Book* BookList::searchBook(string name){
    for(int i=0; i<booksCount;i++){
        if(books[i].getTitle()==name){
            return &books[i];
        }
    }
    return nullptr;
}

/////////////////////////////////
Book* BookList::searchBook(int id){
    for(int i=0; i<booksCount;i++){
        if(books[i].getId()==id){
            return &books[i];
        }
    }
    return nullptr;
}

/////////////////////////////////
void BookList::deleteBook(int id){
    for(int i=0; i<booksCount;i++){
        if(books[i].getId()==id){
            while(i<booksCount-1){
                books[i]=books[i+1];
                books[i].setId(i+1);
                i++;
            }
            booksCount--;
            capacity--;
            break;
        }
    }
}

/////////////////////////////////
ostream& operator<<(ostream & output,const BookList & bookList){
    for(int i=0;i<bookList.booksCount;i++){
        output<<bookList.books[i];
    }
    return output;
}

/////////////////////////////////
BookList::~BookList(){
    delete []books;
}

/////////////////////////////////
Book BookList::getTheHighestRatedBook(){
    double highest_rate=-0.1;
    int index = 0;
    for(int i=0;i<booksCount;i++){
         if(books[i].getAverageRating()>highest_rate){
            highest_rate=books[i].getAverageRating();
            index=i;
         }
    }
    return books[index];
}
/////////////////////////////////
void BookList::getBooksForUser(const User & user){
    for(int i=0;i<booksCount;i++){
        if(books[i].getAuthor()==user){
            cout<<books[i];
        }
    }
}
/////////////////////////////////
Book& BookList::operator[] (int position){
    if(position<0 || position>booksCount){
        cout<<"position error"<<endl;
        exit(1);
    }
    return books[position];
}
/////////////////////////////////