#include "../Headers/Book.h"

int Book::count=0;

Book::Book(){
    title="";
    isbn="";
    count++;
    id=count;
    //cout << "b"<< id <<endl;
    category="";
    averageRating=0.0;
    numRates=0;
    sumRates=0.0;
    hasAuther=false;
    //User author;  
}
//////////////////////////////////////
Book::Book(string title, string isbn, string category){
    this->title=title;
    this->isbn = isbn;
    this->category = category;
    count++;
    id=count;
    averageRating = 0.0;
    //User author;
    hasAuther=false;
}
//////////////////////////////////////
Book::Book(const Book& book){
    title=book.title;
    isbn=book.isbn;
    id=book.id;
    category=book.category;
    if(book.hasAuther){
        User author;
        hasAuther= true;
        this->author=book.author;
    }
    
    averageRating=book.averageRating;
}
//////////////////////////////////////
void Book::setTitle(string a){
    title=a;
}
//////////////////////////////////////
string Book::getTitle() const {
    return title;
}
//////////////////////////////////////
void Book::setIsbn(string a){
    isbn=a;
}
//////////////////////////////////////
string Book::getIsbn() const{
    return isbn;
}
//////////////////////////////////////
void Book::setId(int a){
    id=a;
}
//////////////////////////////////////
int Book::getId() const{
    return id;
}
//////////////////////////////////////
void Book::setCategory(string a){
    category=a;
}
//////////////////////////////////////
string Book::getCategory()const{
    return category;
}
//////////////////////////////////////
void Book::setAuthor(const User & a){
    hasAuther=true;
    author = a ;
}
//////////////////////////////////////
User Book::getAuthor() const{
    return author;
}
//////////////////////////////////////
void Book::rateBook(double rating){
    static int numRates=0;
    static double sumRates=0.0;
    numRates++;
    sumRates += rating;
    averageRating = sumRates/numRates;
}
//////////////////////////////////////
double Book::getAverageRating () const{
    return averageRating;
}
//////////////////////////////////////
ostream &operator<<(ostream & output, const Book & book){
    output<<"============Book "<<book.id<<" info ============"<<endl;
    output<<"title : " << book.title;
    output<<" | isbn : "<<book.isbn;
    output<<" | Id : "<<book.id ;
    output<<" | category : "<<book.category<< endl;
    if(book.hasAuther == true){
        output << book.author;
    }
    cout<<"================================="<<endl;
    return output;
}
        
//////////////////////////////////////
istream &operator>>( istream & input, Book & book){
    cout<<"Enter the user information in the order"<< endl;
    cout<<"Title "<<" Isbn "<<" Category " << " Avg Rating melek";
    cout<<" (space separation)"<<endl;
    input>> book.title  >> book.isbn >> book.category ;
    return input;
}

////////////////////////////////////

////////////////////////////////////

////////////////////////////////////

////////////////////////////////////

////////////////////////////////////

////////////////////////////////////