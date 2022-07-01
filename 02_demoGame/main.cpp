#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27

void delay(clock_t a){
    clock_t start;
    start  = clock();
    while(clock() - start < a){
	}
}

void pembukaan(){
	
	int i;
	char str[100] = "Nartoh: Brick Back Saskeh",
		 intro[100] = "Kejar, bertarung, dan bawa saskeh kembali ke desa";
    for(i = 0; i < 10; i++){
        cout << "\n";
    }
    for(i = 0; i < 30; i++){
        cout << " ";
    }
	for(i = 0; str[i] != 0; i++){
        cout << str[i];
        delay(60);
    };
    cout << "\n";
    for(i = 0; i < 30; i++){
        cout << " ";
    }
    for(i = 0; intro[i] != 0; i++){
        cout << intro[i];
        delay(60);
    };
    delay(1500);
    system("cls");

}

void ceramah(){
	
	int i;
	char crmh[1000] = "Saskeh, kau tidak tahu betapa orang-orang di desa sangat kecewa akan kepergianmu. Kekaseh-sensei, sakiri, dan semua ninja merasa kehilangan bila kau pergi. Jadi tolonglah, jangan pernah pergi meninggalkan desa! kau tidak tahu betapa sakitnya rasa kehilangan itu.";
    for(i = 0; i < 10; i++){
        cout << "\n";
    }
    for(i = 0; i < 30; i++){
        cout << " ";
    }
	for(i = 0; crmh[i] != 0; i++){
        cout << crmh[i];
        delay(60);
    };
    delay(1500);
    system("cls");

}


//// struct property
struct karakter {
// parameter
	string nama;
    int hp;
    int atk;
    int def;
	
	void attack(karakter *heroObject) {
		int hpFrom = heroObject->hp;
		
		cout << nama << " attacking " << heroObject->nama << " ! \n";
		heroObject->hp = heroObject->hp - (atk - heroObject->def);
		
		cout << heroObject->nama << "'s hp drop from " << hpFrom << " to " << heroObject->hp << "\n";
	}
    
};

// function 
int main(){
    
    karakter k1;
	k1.nama = "Nartoh";
	k1.hp = 50;
	k1.atk = 9;
	k1.def = 5;
	
	karakter k2;
	k2.nama = "Saskeh";
	k2.hp = 45;
	k2.atk = 10;
	k2.def = 4;
    
    int panjangPeta = 21;		// x
    int lebarPeta = 7;			// y
    int posisiKarakterY = 3;
    int posisiKarakterX = 2;
	
	// Map
    string peta[lebarPeta][panjangPeta] = {
        {"||", "%", "%", "%", "%", "%", "%", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "<", "<"},	//01
        {"||", " ", " ", " ", "%", "%", "%", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "<", "<", "<", "<"},	//02
        {"||", " ", " ", " ", " ", " ", "%", "*", "*", "*", "*", "*", "*", "*", " ", " ", "<", "<", "O", "<", "<"},	//03
        {"  ", "S", " ", " ", " ", " ", " ", "|", "*", "*", "*", "*", "$", " ", ">", "=", "<", "<", "<", "<", "<"},	//04
        {"||", " ", " ", " ", " ", " ", "%", "*", "*", "*", "*", "*", "*", "*", " ", " ", "<", "<", "O", "<", "<"},	//05
        {"||", " ", " ", " ", "%", "%", "%", "*", "*", "*", "*", "*", "*", "*", "*", "*", " ", "<", "<", "<", "<"},	//06
        {"||", "%", "%", "%", "%", "%", "%", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "=", "<", "<"}  //07
    };
//		  01   02   03   04   05   06   07   08   09   10   11   12   13   14   15   16   17   18   19   20   21
		
	pembukaan();
	
	// agar pas awal sudah langsung di playground
    cout << "|| % % % % % % = = = = = = = = = = = = < <\n"
         << "||       % % % * * * * * * * * *   < < < <\n"
         << "||           % * * * * * * *     < < O < <\n"
         << "   S N         | * * * * $   > = < < < < <\n"
         << "||           % * * * * * * *     < < O < <\n"
         << "||       % % % * * * * * * * * *   < < < <\n"
         << "|| % % % % % % = = = = = = = = = = = = < <\n";
	
	// Game akan dijalankan lewat keyboard
	int arrowKey = 0;
//Looping While
    while(1) {
    
    if (arrowKey == KEY_LEFT && peta[posisiKarakterY][posisiKarakterX-1] == "||"){
		cout << "\nNartoh: Ini adalah tembok perbatasan Konohuy, aku sudah membulatkan tekad untuk mencari Saskeh, aku tidak akan menarik kata-kataku!";
	} else
	if ((arrowKey == KEY_LEFT && peta[posisiKarakterY][posisiKarakterX-1] == "S") || (arrowKey == KEY_UP && peta[posisiKarakterY-1][posisiKarakterX] == "S") || (arrowKey == KEY_DOWN && peta[posisiKarakterY+1][posisiKarakterX] == "S")){
		cout << "\nSakiri: Naruto... tolong bawa kembali Saskeh~\n" << "Nartoh: Yosh...";
	} else
	if ((arrowKey == KEY_RIGHT && peta[posisiKarakterY][posisiKarakterX+1] == "%") || (arrowKey == KEY_LEFT && peta[posisiKarakterY][posisiKarakterX-1] == "%") || (arrowKey == KEY_UP && peta[posisiKarakterY-1][posisiKarakterX] == "%") || (arrowKey == KEY_DOWN && peta[posisiKarakterY+1][posisiKarakterX] == "%")){
		cout << "\nNartoh: Pohonnya sangat rimbun, akan sulit untuk bisa cepat menemukan Saskeh. Aku tidak akan melewatinya, dattebayo!";
	} else
    if (peta[posisiKarakterY][posisiKarakterX] == "|"){
		cout << "\nHati-Hati! kamu telah masuk ke markas Orochimadun\n" << "\nNartoh: Rumput yang hijau, akankah aku bertarung dengan Saskeh di rerumputan yang luas ini?";
	} else
	    if ((arrowKey == KEY_UP && peta[posisiKarakterY-1][posisiKarakterX] == "=") || (arrowKey == KEY_DOWN && peta[posisiKarakterY+1][posisiKarakterX] == "=")){
		cout << "\nNartoh: Tembok ini sangat keras";
	} else
	if ((arrowKey == KEY_RIGHT && peta[posisiKarakterY][posisiKarakterX+1] == ">")){
		cout << "\nNartoh: Orochimadun pasti mengunci pintu ini!";
	} else
	if ((arrowKey == KEY_RIGHT && peta[posisiKarakterY][posisiKarakterX+1] == "<") || (arrowKey == KEY_DOWN && peta[posisiKarakterY+1][posisiKarakterX] == "<")){
		cout << "\nNartoh: Orochimadun selalu membuat apapun mirip ular";
	} else
	if ((arrowKey == KEY_RIGHT && peta[posisiKarakterY][posisiKarakterX+1] == "$") || (arrowKey == KEY_LEFT && peta[posisiKarakterY][posisiKarakterX-1] == "$") || (arrowKey == KEY_UP && peta[posisiKarakterY-1][posisiKarakterX] == "$") || (arrowKey == KEY_DOWN && peta[posisiKarakterY+1][posisiKarakterX] == "$")){
		cout << "\nSaskeh: Aku tidak akan kembali ke desa! percuma saja kau membujukku!\n";
		
		int hitOrspeech;
		cout << "\nNartoh: Ngeyel kau!"
			 << "\n\nNartoh (dalam hati): enaknya gimana ya?"
			 << "\n1) pukul"
			 << "\n2) kasih ceramah"
			 << "\n\nKeputusan: ";
		cin >> hitOrspeech;
		system("CLS");
		
		if (hitOrspeech == 1) {
			for (int i = 0; i < 9; i++){
			k1.attack(&k2);		//1
			cout << "\n";
			k2.attack(&k1);
			}
		
			if (k2.hp == 0){
				cout << "\nNartoh: Saskeh sudah pingsan, sebaiknya cepat aku bawa ke desa!\n";
				exit(0);
			}
		} else
		if(hitOrspeech == 2){
			ceramah();
		
		} else {
			cout << "Ngaco";
		}
		
	}
		
	
    	
    	// menangkap ketikan keyboard
        arrowKey = getch();
        if(arrowKey == KEY_UP
			&& (peta[posisiKarakterY-1][posisiKarakterX] == " "
			||  peta[posisiKarakterY-1][posisiKarakterX] == "*"
			||  peta[posisiKarakterY-1][posisiKarakterX] == "|")
			&& posisiKarakterY >= 0) {						
			// Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        } else
        if(arrowKey == KEY_DOWN
			&& (peta[posisiKarakterY+1][posisiKarakterX] == " "			
			||  peta[posisiKarakterY+1][posisiKarakterX] == "*"
			||  peta[posisiKarakterY+1][posisiKarakterX] == "|")
			&& posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke bawah
			posisiKarakterY = posisiKarakterY+1;
        } else
        if(arrowKey == KEY_LEFT 
			&& (peta[posisiKarakterY][posisiKarakterX-1] == " "
			||  peta[posisiKarakterY][posisiKarakterX-1] == "*"
			||  peta[posisiKarakterY][posisiKarakterX-1] == "|") 
			&& posisiKarakterX >= 0) {
            // Gerakkan karakter ke kiri
            posisiKarakterX = posisiKarakterX-1;
        } else
        if(arrowKey == KEY_RIGHT 
			&& (peta[posisiKarakterY][posisiKarakterX+1] == " "
			||  peta[posisiKarakterY][posisiKarakterX+1] == "*"
			||  peta[posisiKarakterY][posisiKarakterX+1] == "|")
			&& posisiKarakterX < panjangPeta) {
            // Gerakkan karakter ke kanan
            posisiKarakterX = posisiKarakterX+1;
        } else
        if(arrowKey == ESC_KEY){
        	cout << "Exiting...\n";
        	break;
        	// ESC untuk menghentikan permainan
		};
        
        //pembersih output sebelumnya
        system("cls");
        
//Nested For Looping
    	for(int y = 0; y < lebarPeta; y++){
            for(int x = 0; x < panjangPeta; x++){
                if(posisiKarakterX == x && posisiKarakterY == y){
					cout << "N" << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
	};
    
    cout << "Exitted";
    return 0;
}
