#include <iostream>
#include <string>
using namespace std;
//USER
class User {
    protected:
    string name;
    int ID;
    string email;
    int phoneNum;
    string lastBorrowedBook;
    public:
    // as user
    User(string name, int ID, string email, int phoneNum, string lastBorrowedBook) {
        this->name = name;
        this->ID = ID;
        this->email = email;
        this->phoneNum = phoneNum;
        this->lastBorrowedBook = lastBorrowedBook;
    
    }
    // as librarian
    User(string name, int ID){
        this->name = name;
        this->ID = ID;
    }
    virtual void introduce() = 0;
    };
//MEMBER
class Member : public User{
    public:
    Member(string name, int ID , string email, int phoneNum, string lastBorrowedBook) 
    : User(name, ID, email, phoneNum, lastBorrowedBook) {

    }

void introduce() override {
        cout <<"Name:" << name <<endl;
        cout <<"ID:" << ID <<endl;
        cout <<"Email:" << email <<endl;
        cout <<"Phone Number:" << phoneNum <<endl;
        cout <<"Last Borrowed Book:" << lastBorrowedBook <<endl;}

};

//LIBRARIAN
class Librarian : public User {
public:

    Librarian (string name, int ID)
    : User(name, ID){

    }
     void introduce () override{
        cout <<"Name:" << name <<endl;
        cout <<"ID:" << ID <<endl;
    }
};

//BOOK

class Book {
private:
    string title;
    string author;
    int price;

public:
    static int count;
    Book(string title, string author, int price) {
        this->title = title;
        this->author = author;
        this->price = price;
        count++;
    }

    static void showCount(){
        cout <<"Number of books:"<< count <<endl;
    }

    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    void setPrice(int p) {
        if (p >= 0) {
            price = p;
        } else {
            cout << "invalid price" << endl;
        }
    }

    int getPrice() {
        return price;
    }
};
int Book :: count =0;

//MAIN

int main(){
    Member user1("Nour Ali",1114,"nourelsali2006@gmail.com",1157548083,"1984");
    
    Librarian librarian1("Yassen Elsayed",2228);
    User* P1 =& user1;
    User* p2 =& librarian1;

    P1->introduce();
    cout<<endl;
    p2->introduce();

    Book book1("Harry Potter 1 ","J.K. Rowling",250);
    
    Book book2("Animal Farm","George Orwell",150);

    Book book3("1984", "George Orwell", 200);
   
    Book::showCount();

    book1.displayInfo();
    book2.displayInfo();
    book3.displayInfo();

    cout << endl;
    book1.setPrice(300);
    cout<<"Harry potter book new price:"<<book1.getPrice() <<endl;

    return 0;

}