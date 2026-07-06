#include "../include/Library.h"
#include "../include/FileManager.h"

#include <iostream>

using namespace std;

int main()
{
    Library library;
    FileManager fileManager;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Display Books\n";
        cout << "2. Add Book\n";
        cout << "3. Delete Book\n";
        cout << "4. Search Book\n";

        cout << "5. Display Members\n";
        cout << "6. Register Member\n";
        cout << "7. Delete Member\n";
        cout << "8. Search Member\n";

        cout << "9. Issue Book\n";
        cout << "10. Return Book\n";

        cout << "11. Save Data\n";
        cout << "12. Load Data\n";
        cout << "13. Display Issued Books\n";
        cout << "14. Library Statistics\n";
        cout << "15. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {

        case 1:
        {
            library.displayBooks();
            break;
        }
case 2:
{
    int id;
    string title;
    string author;

    cout << "\nBook ID : ";
    cin >> id;

    cin.ignore();

    cout << "Title : ";
    getline(cin, title);

    cout << "Author : ";
    getline(cin, author);

    if(library.searchBook(id) != nullptr)
    {
        cout << "\nBook ID already exists.\n";
        break;
    }

    library.addBook(
        Book(id, title, author)
    );

    cout << "\nBook Added Successfully.\n";

    break;
}

        case 3:
        {
            int id;

            cout << "\nEnter Book ID : ";
            cin >> id;

            if(library.deleteBook(id))
                cout << "Book Deleted Successfully.\n";
            else
                cout << "Book Not Found.\n";

            break;
        }

        case 4:
        {
            int id;

            cout << "\nEnter Book ID : ";
            cin >> id;

            Book* book = library.searchBook(id);

            if(book)
                book->display();
            else
                cout << "Book Not Found.\n";

            break;
        }

        case 5:
        {
            library.displayMembers();
            break;
        }

        case 6:
{
    int id;
    string name;

    cout << "\nMember ID : ";
    cin >> id;

    cin.ignore();

    cout << "Name : ";
    getline(cin, name);

    if(library.searchMember(id) != nullptr)
    {
        cout << "\nMember ID already exists.\n";
        break;
    }

    library.addMember(
        Member(id, name)
    );

    cout << "\nMember Registered Successfully.\n";

    break;
}

        case 7:
        {
            int id;

            cout << "\nEnter Member ID : ";
            cin >> id;

            if(library.deleteMember(id))
                cout << "Member Deleted Successfully.\n";
            else
                cout << "Member Not Found.\n";

            break;
        }

        case 8:
        {
            int id;

            cout << "\nEnter Member ID : ";
            cin >> id;

            Member* member = library.searchMember(id);

            if(member)
                member->display();
            else
                cout << "Member Not Found.\n";

            break;
        }

        case 9:
{
    int bookId;
    int memberId;

    cout << "\nEnter Book ID : ";
    cin >> bookId;

    cout << "Enter Member ID : ";
    cin >> memberId;

    if(library.issueBook(bookId,
                         memberId))
    {
        cout << "\nBook Issued Successfully.\n";
    }
    else
    {
        cout << "\nIssue Failed.\n";
    }

    break;
}

        case 10:
        {
            int id;

            cout << "\nEnter Book ID : ";
            cin >> id;

            if(library.returnBook(id))
                cout << "Book Returned Successfully.\n";
            else
                cout << "Book Cannot Be Returned.\n";

            break;
        }

        case 11:
        {
            if(fileManager.saveData(
                    library,
                    "data/books.txt",
                    "data/members.txt"))
                cout << "\nData Saved Successfully.\n";
            else
                cout << "\nError Saving Data.\n";

            break;
        }

        case 12:
        {
            if(fileManager.loadData(
                    library,
                    "data/books.txt",
                    "data/members.txt"))
                cout << "\nData Loaded Successfully.\n";
            else
                cout << "\nError Loading Data.\n";

            break;
        }
        case 13:
{
    library.displayIssuedBooks();
    break;
}
case 14:
{
    library.displayStatistics();
    break;
}

        case 15:
        {
            cout << "\nThank You!\n";
            break;
        }

        default:
        {
            cout << "\nInvalid Choice.\n";
        }

        }

    } while(choice != 15);

    return 0;
}