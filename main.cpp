//header files
#include <iostream> // input output stream
#include <iomanip> // manipulator width
#include <cstdio> // for gets & scanf
#include <cstdlib> // exit_success
#include <limits> // enter

using namespace std;

//struct book data
struct book
{
    int id, isbn, stock;
    char title[100];
    char category[50];
    
}book[100];


// prototyping
int getMenu();
void menuRefreshLogin();


// main
int main()
{
    system("cls");
    //enum for changing the numbers 
    enum option {SHOW = 1,
                INPUT,
                UPDATE,
                DELETE,
                EXIT};

    // array data user for login system
    string userlogin[8][3] = {  {"admin", "admin","Administrator"},
                                {"shan", "shan","Shandika"},
                                {"guido", "guido","Guido"},
                                {"radit","radit", "Radit"},
                                {"fanny", "fanny", "Fanny"},
                                {"windy", "windy", "Windy"},
                                {"hamzah", "hamzah", "Hamzah"},
                                {"niko", "niko", "Niko"}};

    //variable declaration
    string uname, pass;
    int loginAttempts = 0, choice, size = -1;
    char temp, is_continue;

    //Login System
    loginsystem:
    menuRefreshLogin();
    while (loginAttempts < 3) {
        cout << "Masukan Username kamu: ";
        cin >> uname;

        for (int i = 0; i <=8; i++) {
            //searching for valid username
            if (uname == userlogin[i][0]) {
                system("cls");
                menuRefreshLogin();
                cout << "Username ditemukan!" << endl;
                cout << "Silahkan masukan password: ";
                cin >> pass;
                cout << endl;
                //searching for valid password
                if (pass == userlogin[i][1]) {
                    system("cls");
                    menuRefreshLogin();
                    cout << "Login aplikasi berhasil\n";
                    cout << endl;
                    system("pause");
                    system("cls");
                    loginAttempts = 99;

                    //main menu after login successfull
                    mainmenu:
                    cout<<" ------- Aplikasi Sistem Perpustakaan --------\n";
                    cout<<" ------- \tKelompok 3 Alprog     --------\n";
                    cout<<" ------- \t22S1IF01\t      --------\n\n";
                    cout << "selamat datang " << userlogin[i][2] << "!" << endl;
                    cout << endl;
                    //show menu
                    choice = getMenu();
                    switch (choice)
                    {
                    //menu show data books;
                    case SHOW:
                        system("cls");
                        cout<< "\t=--------------=\n";
                        cout<< "\tmenu Daftar buku\n";
                        cout<< "\t=--------------=\n";
                        cout << endl;
                        cout<<"=-------------------------------------------------------------------=\n";
		                cout<<" No  Id Buku     Judul Buku      ISBN       Kategory     Jumlah Buku \n";
		                cout<<"=-------------------------------------------------------------------=\n";
                        for (int i = 0; i <= size; i++) {
                            cout<<setw(2)<<i+1<<setw(4)<<book[i].id<<setw(20)<<book[i].title<<setw(12)<<book[i].isbn<<setw(14)<<book[i].category<<setw(7)<<book[i].stock;
                            cout << endl;                
                        } 
                        cout << endl;
                        system("pause");
                        system("cls");
                        goto mainmenu;
                        break;
                    //menu input data books;
                    case INPUT:
                        system("cls");
                        inputmenu:
                        cout<< "\t=--------------=\n";
                        cout<< "\tmenu input buku\n";
                        cout<< "\t=--------------=\n";
                        cout << endl;
                        cout << "Apakah ingin menambahkan data Buku?[y/n]: ";
                        cin >> is_continue;
                        cout << endl;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (is_continue == 'y' || is_continue == 'Y') {
                            input_cont:
                            system("cls");
                            cout<< "\t=--------------=\n";
                            cout<< "\tmenu input buku\n";
                            cout<< "\t=--------------=\n";
                            cout << endl;
                            size++;
                            cout << "Data buku ke\t: " << size + 1 << endl;
                            cout <<"-------------------\n";
                            cout << endl;
                            book[size].id = size + 1;
                            cout <<"masukan judul buku\t\t: ";
                            gets(book[size].title);
                            cout << "masukan nomer isbn\t\t: ";
                            scanf("%d%c", &book[size].isbn, &temp);
                            cout << "masukan jenis kategori\t\t: ";
                            gets(book[size].category);
                            cout << "masukan jumlah buku\t\t: ";
                            scanf("%d%c", &book[size].stock, &temp);
                            system("cls");
                            cout<< "\t=--------------=\n";
                            cout<< "\tmenu input buku\n";
                            cout<< "\t=--------------=\n";
                            cout << endl;
                            cout << "data berhasil disimpan!" << endl;
                            cout << endl;
                            input_again:
                            cout << "Apakah ingin menambahkan data lagi[y/n]?: ";
                            cin >> is_continue;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            if (is_continue == 'y' || is_continue == 'Y') {
                                system("cls");
                                goto input_cont;
                            } else if (is_continue == 'n' || is_continue == 'N'){
                                system("cls");
                                goto mainmenu;
                            } else {
                            cout << "inputan yang anda masukkan tidak sesuai!" << endl;
                            system("pause");
                            system("cls");
                            goto input_again;
                            }
                        } else if (is_continue == 'n' || is_continue == 'N'){
                            system("cls");
                            goto mainmenu;
                        } else {
                            cout << "inputan yang anda masukkan tidak sesuai!" << endl;
                            system("pause");
                            system("cls");
                            goto inputmenu;
                        }
                        break;
                        //menu update data books
                    case UPDATE:
                        int c;
                        system("cls");
                        updatemenu:
                        cout<< "\t=--------------=\n";
                        cout<< "\tmenu Ubah buku\n";
                        cout<< "\t=--------------=\n";
                        cout << endl;
                        cout<<"=-------------------------------------------------------------------=\n";
		                cout<<" No  Id Buku     Judul Buku      ISBN       Kategory     Jumlah Buku \n";
		                cout<<"=-------------------------------------------------------------------=\n";
                        for (int i = 0; i <= size; i++) {
                            cout<<setw(2)<<i+1<<setw(4)<<book[i].id<<setw(20)<<book[i].title<<setw(12)<<book[i].isbn<<setw(14)<<book[i].category<<setw(7)<<book[i].stock;
                            cout << endl;                         
                        }
                        cout << endl;
                        cout << "apakah ingin mengubah data buku? [y/n]: ";
                        cin >> is_continue;
                        if (is_continue == 'y' || is_continue =='Y') {
                            cout << endl;
                            cout << "masukan Id buku yang ingin di ubah: ";
                            cin >> c;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            for (int j = 0 ; j <= size; j++) {
                                if (book[j].id == c) {
                                    system("cls");
                                    cout<< "\t=--------------=\n";
                                    cout<< "\tmenu Ubah buku\n";
                                    cout<< "\t=--------------=\n";
                                    cout << endl;
                                    cout <<"Data buku dengan Id ke: " << book[j].id << endl;
                                    cout <<"-------------------------\n";
                                    cout << endl;
                                    cout <<"masukan judul buku\t\t: ";
                                    gets(book[j].title);
                                    cout << "masukan nomer isbn\t\t: ";
                                    scanf("%d%c", &book[j].isbn, &temp);
                                    cout << "masukan jenis kategori\t\t: ";
                                    gets(book[j].category);
                                    cout << "masukan jumlah buku\t\t: ";
                                    scanf("%d%c", &book[j].stock, &temp);
                                    system("cls");
                                    cout<< "\t=--------------=\n";
                                    cout<< "\tmenu Ubah buku\n";
                                    cout<< "\t=--------------=\n";
                                    cout << endl;
                                    cout << "Data buku berhasil diubah!" << endl;
                                    cout << endl;
                                    cout << "Apakah ingin mengubah data lagi[y/n]?: ";
                                    cin >> is_continue;
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    if (is_continue == 'y' || is_continue == 'Y') {
                                        system("cls");
                                        goto updatemenu;
                                    } else if (is_continue == 'n' || is_continue == 'N'){
                                        system("cls");
                                        goto mainmenu;
                                    } else {
                                    cout << "Inputan yang anda masukkan tidak sesuai!" << endl;
                                    }

                                }
                            }
                        } else if(is_continue == 'n'|| is_continue == 'N') {
                            system("cls");
                            goto mainmenu;
                        } else {
                            cout << "inputan yang anda masukan tidak sesuai!" << endl;
                            system("pause");
                            system("cls");
                            goto updatemenu;
                        }     
                        cout << "Id buku tidak ditemukan!" << endl;
                        system("pause");
                        cout << endl;
                        system("cls");
                        goto updatemenu;
                        break;
                    //menu delete data books
                    case DELETE:
                        int b;
                        system("cls");
                        deletemenu:
                        cout<< "\t=--------------=\n";
                        cout<< "\tMenu Hapus buku\n";
                        cout<< "\t=--------------=\n";
                        cout << endl;
                        cout<<"=-------------------------------------------------------------------=\n";
		                cout<<" No  Id Buku     Judul Buku      ISBN       Kategory     Jumlah Buku \n";
		                cout<<"=-------------------------------------------------------------------=\n";
                        for (int i = 0; i <= size; i++) {
                            cout<<setw(2)<<i+1<<setw(4)<<book[i].id<<setw(20)<<book[i].title<<setw(12)<<book[i].isbn<<setw(14)<<book[i].category<<setw(7)<<book[i].stock;
                            cout << endl;                           
                        }
                        cout << endl;
                        cout << "apakah ingin menghapus data buku?[y/n]: ";
                        cin >> is_continue;
                        cout << endl;
                        if (is_continue == 'y' || is_continue == 'Y') {
                            delete_cont:
                            system("cls");
                            cout<< "\t=--------------=\n";
                            cout<< "\tMenu Hapus buku\n";
                            cout<< "\t=--------------=\n";
                            cout << endl;
                            cout<<"=-------------------------------------------------------------------=\n";
		                    cout<<" No  Id Buku     Judul Buku      ISBN       Kategory     Jumlah Buku \n";
		                    cout<<"=-------------------------------------------------------------------=\n";
                            for (int i = 0; i <= size; i++) {
                            cout<<setw(2)<<i+1<<setw(4)<<book[i].id<<setw(20)<<book[i].title<<setw(12)<<book[i].isbn<<setw(14)<<book[i].category<<setw(7)<<book[i].stock;
                            cout << endl;                           
                            }

                            cout << endl;
                            cout << "Masukan Id buku yang ingin di hapus: ";
                            cin >> b;
                            for (int j = 0 ; j <= size; j++) {
                                if (book[j].id == b) {
                                    system("cls");
                                    book[j] = book[j-1];
                                    j--;
                                    size--;
                                    cout<< "\t=--------------=\n";
                                    cout<< "\tMenu Hapus buku\n";
                                    cout<< "\t=--------------=\n";
                                    cout << endl;
                                    cout<<"=-------------------------------------------------------------------=\n";
		                            cout<<" No  Id Buku     Judul Buku      ISBN       Kategory     Jumlah Buku \n";
		                            cout<<"=-------------------------------------------------------------------=\n";
                                    for (int i = 0; i <= size; i++) {
                                    cout<<setw(2)<<i+1<<setw(4)<<book[i].id<<setw(20)<<book[i].title<<setw(12)<<book[i].isbn<<setw(14)<<book[i].category<<setw(7)<<book[i].stock;
                                    cout << endl;                           
                                    }
                                    cout << endl;
                                    cout << "Data berhasil dihapus!" << endl;
                                    delete_again:
                                    cout << endl;
                                    cout << "Apakah ingin menghapus data lagi[y/n]?: ";
                                    cin >> is_continue;
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //fixing enter bug
                                    if (is_continue == 'y' || is_continue == 'Y') {
                                        system("cls");
                                        goto deletemenu;
                                    } else if (is_continue == 'n' || is_continue == 'N'){
                                        system("cls");
                                        goto mainmenu;
                                    } else {
                                        cout << "inputan yang anda masukkan tidak sesuai!" << endl;
                                        system("pause");
                                        system("cls");
                                        goto delete_again;
                                        }
                                } 
                        
                            }
                            
                        } else if (is_continue == 'n' || is_continue == 'N') {
                            system("cls");
                            goto mainmenu;
                        } else {
                            cout << "inputan yang anda masukkan tidak sesuai!" << endl;
                            system("pause");
                            system("cls");
                            goto deletemenu;
                        }

                        cout << endl;
                        cout << "Data Id Buku tidak ditemukan!\n";
                        cout << endl;
                        system("pause");
                        system("cls");
                        goto delete_cont;
                        break;
                    case EXIT:
                        cout << "menutup aplikasi, terima kasih sudah menggunakan." << endl;
                        system("pause");
                        system("cls");
                        loginAttempts = 0;
                        goto loginsystem;
                        break;
                    
                    default:
                        cout << "inputan yang anda masukkan tidak sesuai!" << endl;
                        goto mainmenu;
                        break;
                    }
                } else {
                    system("cls");
                    menuRefreshLogin();
                    cout << endl;
                    cout << "Password salah, silahkan coba lagi!" << endl;
                    cout << endl;
                    system("pause");
                    system("cls");
                    loginAttempts++;
                    goto loginsystem;
                }
            }
        }   
    }

    //checking if user was failed login 3 times
    if (loginAttempts == 3) {
        system("cls");
        menuRefreshLogin();
        cout << endl;
        cout << "Kamu sudah login 3 kali, program akan ditutup!" << endl;
        cout << endl;
        system("pause");
        return EXIT_SUCCESS;
    }

}

//function

//main menu function
int getMenu() {
    int selectedOption;
    cout<<"-------- Menu ----------\n";
    cout<<" 1. Daftar Buku        \n";
    cout<<" 2. Input Data Buku       \n";
    cout<<" 3. Ubah Data Buku     \n";
    cout<<" 4. Hapus Data Buku    \n";
    cout<<" 5. Exit   \n";
    cout<<"----------------------\n";
    cout<<"Masukan Pilihan anda[1-5]: ";
    cin >> selectedOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // fixing enter bug
    return selectedOption;
}

//refresh menu login
void menuRefreshLogin() {
    cout<<"\n\n\n";
    cout<<"\t\t ------- Aplikasi Sistem Perpustakaan --------\n";
    cout<<"\t\t ------- \tKelompok 3 Alprog     --------\n";
    cout<<"\t\t ------- \t22S1IF01\t      --------\n\n";
    cout << "=---Login Aplikasi---=" << endl;
}


