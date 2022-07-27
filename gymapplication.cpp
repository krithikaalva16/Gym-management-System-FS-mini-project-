#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct Gym {
    int id;
    string name;
    int age;
    float height;
    float weight;
};

void addMember() {
    Gym gym;
    cout<< "\n\tEnter Gym Member Details:\n";
    cout << "\n\tName : ";
    cin.get();
    getline(cin, gym.name);
    cout << "\n\tAge : ";
    cin >> gym.age;
    cout << "\n\tHeight : ";
    cin >> gym.height;
    cout << "\n\tWeight : ";
    cin >> gym.weight;
    ID++;

    ofstream write;
    write.open("gym.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << gym.name ;
    write << "\n" << gym.age ;

    write << "\n" << gym.height ;
    write << "\n" << gym.weight;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print(Gym s) {
    cout << "\n\t------Gym Member Data------";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tName is : " << s.name;
    cout << "\n\tAge is : " << s.age;
    cout << "\n\theight is : " << s.height;
    cout << "\n\tWeight is : " << s.weight;

}

void readData() {
    Gym gym;
    ifstream read;
    read.open("gym.txt");
    while (!read.eof()) {
        read >> gym.id;
        read.ignore();
        getline(read, gym.name);
        read >> gym.age;
        read >> gym.height;
        read >> gym.weight;
        print(gym);
    }
    read.close();
}

int searchData() {
    int id;
    cout << "\n\tEnter gym id want to search : ";
    cin >> id;
    Gym gym;
    ifstream read;
    read.open("gym.txt");
    while (!read.eof()) {
        read >> gym.id;
        read.ignore();
        getline(read, gym.name);
        read >> gym.age;
        read >> gym.height;
        read >> gym.weight;
        if (gym.id == id) {
            print(gym);
            return id;
        }
    }
}

 void deleteData() {
    int id = searchData();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Gym gym;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("gym.txt");
        while (!read.eof()) {
            read >> gym.id;
            read.ignore();
            getline(read, gym.name);
            read >> gym.age;
            read >> gym.height;
            read >> gym.weight;
            if (gym.id != id) {
                tempFile << "\n" << gym.id;
                tempFile << "\n" << gym.name;
                tempFile << "\n" << gym.age;
                tempFile << "\n" << gym.height;
                tempFile << "\n" << gym.weight;
            }
        }
        read.close();
        tempFile.close();
        remove("gym.txt");
        rename("temp.txt", "gym.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateData() {
    int id = searchData();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        Gym newData;
        cout << "\n\tEnter Member name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter Member age : ";
        cin >> newData.age;
        cout << "\n\tEnter Member height : ";
        cin >> newData.height;
        cout << "\n\tEnter Member weight : ";
        cin >> newData.weight;
        Gym gym;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("gym.txt");
        while (!read.eof()) {
            read >> gym.id;
            read.ignore();
            getline(read, gym.name);
            read >> gym.age;
            read >> gym.height;
            read >> gym.weight;
            if (gym.id != id) {
                tempFile << "\n" << gym.id;
                tempFile << "\n" << gym.name;
                tempFile << "\n" << gym.age;
                tempFile << "\n" << gym.height;
                tempFile << "\n" << gym.weight;
            }
            else {
                tempFile << "\n"<< gym.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.age;
                tempFile << "\n" << newData.height;
                tempFile << "\n"<< newData.weight;
            }
        }
        read.close();
        tempFile.close();
        remove("gym.txt");
        rename("temp.txt", "gym.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout<<" \n\n                                                                                                ||||||||||Fitness Centre||||||||||\n\n";
        cout<<"\n                                                                                                   ||||||||||MAIN MENU||||||||||\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n\t1.Add Member data";
        cout << "\n\t2.Display Member data";
        cout << "\n\t3.Search Member data";
        cout << "\n\t4.Delete Member data";
        cout << "\n\t5.Update Member data";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addMember();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        }
    }

}
