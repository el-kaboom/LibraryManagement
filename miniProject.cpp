#include<iostream>
#include<string>
#define size_b 100
#define maxMember 10
using namespace std;
class Member;
class Book{
    public : 
        static int bookCount;
   string book[size_b] ;
    Book() {
        book[0] = "To Kill a Mockingbird";
        book[1] = "1984";
        book[2] = "Pride and Prejudice";
        book[3] = "The Great Gatsby";
        book[4] = "Moby Dick";
        book[5] = "War and Peace";
        book[6] = "The Catcher in the Rye";
        book[7] = "The Lord of the Rings";
        book[8] = "The Chronicles of Narnia";
        book[9] = "Jane Eyre";
        bookCount = 10;
    }
 
   void displayBooks(){
      for(int i = 0 ; i <= bookCount - 1 ; i++){
        cout<<i+1<<" "<<book[i]<<endl;
      }
      cout << "" << endl;
    }
};
int Book::bookCount = 0;
class Admin : public Book{
    private :
     string adminUser = "admin";
     string adminPass = "admin";
    public :
    void addBook(Book& b);
    void removeBook(Book& b);
    void addUser(int memberCount,Member student[]);
    void removeUser(int memberCount,Member student[]);
    void displayUser(int memberCount,Member student[]);
    string  getAdminUserName() {
      return adminUser ;
    }
    string  getAdminPass(){
        return adminPass ; 
    }
    void  setAdminUserName() {
      string u ;
      cin>>u;
      adminUser = u;
    }
    void  setAdminPass(){
      string p ;
      cin>>p;
      adminPass = p ;
    }
};  
class Member{
    private : 
     string userName ;
     string pass ;
     string name ;
     string Dept;
     public :
      //int fine ;
     int flag = 1 ;
    string bookBorrowed[size_b] ;
      int bookCounter = 0 ;
    void  setUserName();
    void  setPass();
    string  getUserName();
    string  getPass();
    void  setName();
    void  setDept();
    string  getName();
    string  getDept();
    void displayUserDetails();
    int searchUser(string user,string passW,Member student[] ,int memberCount,Admin admin);
}; 
void Member :: displayUserDetails() {
        cout << "***** User Details *****" << endl;
        cout << "User Name: " << getName() << endl;
        cout << "Department: " <<getDept() << endl;
       // cout << "Fine: " <<fine << endl;
        cout << "" << endl;
    }
 void Member :: setUserName() {
      string u ;
      cin>>u;
      userName = u;
    }
 void Member :: setPass(){
      string p ;
      cin>>p;
      pass = p ;
     }
string Member :: getUserName() {
      return userName;
    }
string Member ::  getPass(){
        return pass ; 
    }
    void Member :: setName() {
      cout<<"Enter Name of User"<<endl;
      string n;
      cin>>n;
      name = n;
    }
 void Member :: setDept(){
     cout<<"Enter Department of User"<<endl;
      string d ;
      cin>>d;
      Dept = d;
     }
 string Member :: getName() {
      return name;
    }
string Member ::  getDept(){
        return Dept ; 
    }
    void Admin::removeUser(int memberCount,Member student[]){
    student[memberCount].flag = -1 ;
}
 void  Admin::displayUser(int memberCount,Member student[]){
    if(memberCount == 0){
        cout<<"No Active User"<<endl;
    }else{
        for(int i = 0 ; i < memberCount ; i++){
        student[i].displayUserDetails();
    }
    }
 }
void Admin :: addUser(int memberCount,Member student[]){
       student[memberCount].setName();
       student[memberCount].setDept();    
}
void Admin::removeBook(Book& b) {
    int num;
    cout << "Select Book to remove and Enter the Serial Number of that book" << endl;
    cin >> num;
    if (num > 0 && num <= bookCount) {
        for (int i = num - 1; i < bookCount - 1; i++) {
            b.book[i] = b.book[i + 1];
        }
        b.book[bookCount - 1]= " ";
        bookCount--;
        cout << "Book Successfully Removed" << endl;
    } else {
        cout << "Invalid book serial number." << endl;
    }
}
void Admin :: addBook(Book& b){
      string replaceBook;
      cout<<"Enter Name of book you want to add"<<endl;
      cin>>replaceBook;
      b.book[bookCount] = replaceBook;
      bookCount++ ;
      cout<<"Book Sucessfully Added"<<endl;
     }
int searchUser(string user, string passW,Member student[],int memberCount,Admin admin){
    if(user == admin.getAdminUserName() && passW == admin.getAdminPass()){
          return 150 ;
    }else{
        for(int  i = 0 ; i < memberCount ; i++){
       if(student[i].getUserName() == user && student[i].getPass() == passW && student[i].flag == 1){
            return i ;
       }
    }
    return -1 ;
    }
}
class UserFunction : public Member{
    public : 
    void displayUserDetails(int auth , Member student[]) {
        cout << "***** User Details *****" << endl;
        cout << "User Name: " << student[auth].getName() << endl;
        cout << "Department: " << student[auth].getDept() << endl;
        //cout << "Fine: " << student[auth].fine << endl;
        cout << "" << endl;
        borrowedBook();
    }
    void borrowBook(Book b);
    void returnBook();
    void borrowedBook();
};
void UserFunction :: borrowedBook(){
    cout<< "***** Borrowed Books *****"<<endl;
    for (int i = 0; i < bookCounter; ++i) {
        cout << i+1<< ". " << bookBorrowed[i] << endl;
    }
}
void UserFunction :: borrowBook(Book b){
    int borrowNum;
    cout<<"Enter the serial Number of Book to be borrowed"<<endl;
    cin>>borrowNum;
  if (borrowNum >= 1 && borrowNum <= size_b) {
        bookBorrowed[bookCounter] = b.book[borrowNum - 1];
        bookCounter++;
        cout << "Book \"" << b.book[borrowNum - 1] << "\" successfully borrowed." << endl;
    } else {
        cout << "Invalid book serial number." << endl;
    }
}
void UserFunction::returnBook() {
    if (bookCounter == 0) {
        cout << "You haven't borrowed any books." << endl;
        return;
    }
    cout<< "***** Borrowed Books *****"<<endl;
    for (int i = 0; i < bookCounter; ++i) {
        cout << i + 1 << ". " << bookBorrowed[i] << endl;
    }
    int returnNum;
    cout << "Enter the serial number of the book to return: ";
    cin >> returnNum;

    if (returnNum >= 1 && returnNum <= bookCounter) {
        cout << "Book \"" << bookBorrowed[returnNum - 1] << "\" successfully returned." << endl;
        for (int i = returnNum - 1; i < bookCounter - 1; ++i) {
            bookBorrowed[i] = bookBorrowed[i + 1];
        }
        --bookCounter;
    } else {
        cout << "Invalid serial number." << endl;
    }
}
int main(){
    Book b ;
    int choice , choice1 ,choice2 ;
    int auth = 0 ;
    int memberCount = 0 ; 
    bool  run = true ;
    bool  run1 = true ;
    bool  run2 = true ;
    string name;
    string dept;
    Admin admin; 
    UserFunction user;
    Member student[maxMember];
    string* tempUser = new string();
    string* tempPass = new string();
    cout << "" << endl;
    cout << "     LIBRARY MANAGEMENT     " << endl;
    cout << "           SYSTEM           " << endl;
    cout << "" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. User Login" << endl;
    cout << "3. Exit" << endl;
    while(run){
        cin>>choice;
        switch(choice){
        case 1: {
            cout << "" << endl;
            cout << "Enter Username: ";
            cin >> *tempUser;
            cout << "Enter Password: ";
            cin >> *tempPass;
            cout << "" << endl;
            auth =  searchUser(*tempUser,*tempPass,student,memberCount,admin);
              //delete tempUser;
              //delete tempPass;
              if(auth == 150){
                // Admin
                cout << "" << endl;
                cout << "         ADMIN PANEL        " << endl;
                cout << "" << endl;
              //  cout << "Available Books" << endl;
                cout<<"1. Add a Book"<<endl;
                cout<<"2. Remove a Book"<<endl;
                cout<<"3. Add new user"<<endl;
                cout<<"4. Remove a user"<<endl;
                cout<<"5. Display All Users" << endl;
                cout<<"6. Change Password"<<endl;
                cout<<"7. Change UserName"<<endl;
                cout<<"8. Display Available Books"<<endl;
                cout<<"9. Logout" << endl;
                 while(run2){
                     cin>>choice2;
                   switch(choice2){
                 case 1 : admin.addBook(b);
                     break;
                case 2 : admin.removeBook(b);
                     break;
                case 3 :
                      if (memberCount < maxMember) {
                                    cout << "Create Username: ";
                                    student[memberCount].setUserName();
                                    cout << "Create Password: ";
                                    student[memberCount].setPass();
                                    admin.addUser(memberCount, student);
                                    memberCount++;
                                } else {
                                    cout << "Maximum number of users reached." << endl;
                                
                               }
                               break;
                 case 4 : 
                                int userIndex;
                                cout << "Enter the index of the user to remove: ";
                                cin >> userIndex;
                                if (userIndex >= 0 && userIndex < memberCount) {
                                    admin.removeUser(userIndex, student);
                                    cout << "User successfully removed." << endl;
                                } else {
                                    cout << "Invalid user index." << endl;
                                }
                            
                 break;
                 case 5 : admin.displayUser(memberCount, student);
                         break;
                 case 6 : {
                         cout<<"Enter New Password"<<endl;
                         admin.setAdminPass();
                        break;
                     }  
                 case 7 : {
                         cout<<"Enter New UserName"<<endl;
                         admin.setAdminUserName();
                         break;
                     }   
                 case 8 :{
                   b.displayBooks();
                    break;
                     }        
                 case 9 :  {run2 = false;
                         break;
                 }
                default : 
                     cout<<"Invalid Choice"<<endl;
                       break;
                   }
                 }
              }else {
                 cout<<"Invalid User-Name and Password"<<endl;
              }
        }
              case 2 : 
              cout<<"Enter Username"<<endl;
              cin>> *tempUser;
              cout<<"Enter password"<<endl;
              cin>> *tempPass;
              auth =  searchUser(*tempUser,*tempPass,student,memberCount,admin);
             // delete tempUser;
              //delete tempPass;
              if(auth >= 0 && auth < 150){
                // user
                cout << "" << endl;
                cout << "         USER PANEL         " << endl;
                cout << "" << endl;
                user.displayUserDetails(auth,student);
                cout<<"Available Books"<<endl;
                b.displayBooks();
                cout<<"1. Borrow a Book"<<endl;
                cout<<"2. Return a Book"<<endl;
                cout<<"3. View Borrowed Books" << endl;
                cout<<"4. Display User Details" << endl;
                cout<<"5. Change Password"<<endl;
                cout<<"6. Change UserName"<<endl;
                cout<<"7. Logout" << endl;
                cout << "" << endl;
                while(run1){
                    cin>>choice1;
                   switch(choice1){
                    case 1 : {
                        user.borrowBook(b);
                        break ;
                       }
                    case 2 : {
                        user.returnBook();
                        break;
                     }
                     case 3 :{
                         user.borrowedBook();
                                break;
                     }
                     case 4: user.displayUserDetails(auth, student);
                                break;
                     case 5 : {
                         cout<<"Enter New Password"<<endl;
                         student[auth].setPass();
                        break;
                     }  
                      case 6 : {
                         cout<<"Enter New UserName"<<endl;
                         student[auth].setUserName();
                        break;
                     }           
                     case 7 : run1 = false;
                       break ;
                    default : 
                       cout<<"Invalid Choice"<<endl;
                       break;
                }
                }
              }else {
               cout<<"Invalid User-Name and Password"<<endl;
              }
     case 3 : run = false ;
      break;
     default : 
       cout<<"Invalid Choice"<<endl;
       break;
    }
     }
     delete tempUser;
     delete tempPass;
    }