// Naruto Senki

#include <iostream>
#include <conio.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27

// struct property
struct Karakter {
// parameter
	string nama;
    	int hp;
    	int atk;
    
	printHP() {
		cout << "HP " << nama << " saat ini adalah " << hp << "\n";
	}

	void attack(Karakter *heroObject) {
		int hpFrom = heroObject->hp;
		cout << nama << " attacking " << heroObject->nama << " ! \n";
		heroObject->hp = heroObject->hp - atk;
		cout << heroObject->nama << "'s hp drop from " << hpFrom << " to " << heroObject->hp << "\n";
	}
};

// function
int main(){
    
    Karakter k[] = {
        {"Naruto",
         550,
         20},
        {"Sasuke",
         500,
         25},
    };
    
    int panjangPeta = 49;		// x
    int lebarPeta = 7;			// y
    int posisiKarakterY = 3;
    int posisiKarakterX = 7;
    
// Matrix-2D
	/*Aturan menggerakkan karakter
	1. Jalan        (1 / " ")	:   - arrow key pindah posisi
	2. Healing Zone	(2 / "*")	:   - arrow key pindah posisi
	  								- dapat tambahan nyawa
	3. Tower A	(3 / "\")	:   - arrow key tidak bisa tembus
	4. Tower Gun A	(4 / "A")	:	- arrow key tidak bisa tembus
									- menghasilkan damage
	5. Tower B	(5 / "/")	:	- arrow key tidak bisa tembus
									- harus dihancurkan
	6. Tower Gun B	(6 / "B")	:	- arrow key tidak bisa tembus
									- menghasilkan damage
									- harus dihancurkan
	7. Rerumputan   (7 / "%")	:   - arrow key pindah posisi
	8. Tebing	(8 / "#")	:	- arrow key tidak bisa tembus
	*/
	
    // Map
    int peta[lebarPeta][panjangPeta] = {
        {8, 8, 8, 8, 8, 8, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 8, 8, 8, 8, 8, 8},	//01
        {8, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 8},	//02
        {8, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 2, 5, 2, 2, 2, 8},	//03
        {8, 2, 2, 3, 4, 3, 1, 1, 1, 1, 1, 3, 4, 3, 1, 1, 1, 1, 1, 3, 4, 3, 1, 1, 1, 1, 1, 5, 6, 5, 1, 1, 1, 1, 1, 5, 6, 5, 1, 1, 1, 1, 1, 5, 6, 5, 2, 2, 8},	//04
        {8, 2, 2, 2, 3, 2, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 2, 5, 2, 2, 2, 8},	//05
        {8, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 8},	//06
        {8, 8, 8, 8, 8, 8, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 1, 1, 1, 1, 7, 7, 7, 1, 8, 8, 8, 8, 8, 8},	//07
    };
//	01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
	
	// agar pas awal sudah langsung di playground    
    cout << "8 8 8 8 8 8 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 8 8 8 8 8 8\n"
    	 << "8 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 8\n"
         << "8 2 2 2 3 2 1 1 1 1 1 1 3 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 8 1 1 1 1 1 1 1 8 1 1 1 1 1 1 2 5 2 2 2 8\n"
         << "8 2 2 3 4 3 1 0 1 1 1 3 4 3 1 1 1 1 1 4 3 3 1 1 1 1 1 8 6 8 1 1 1 1 1 8 6 8 1 1 1 1 1 5 6 5 2 2 8\n"
         << "8 2 2 2 2 2 1 1 1 1 1 1 3 1 1 1 1 1 1 1 3 1 1 1 1 1 1 1 8 1 1 1 1 1 1 1 8 1 1 1 1 1 1 2 5 2 2 2 8\n"
         << "8 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 8\n"
         << "8 8 8 8 8 8 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 1 1 1 1 7 7 7 1 8 8 8 8 8 8\n";
	
	// Game akan dijalankan lewat keyboard
	int arrowKey = 0;
    
//Looping While
    while(1) {
    	
    	// menangkap ketikan keyboard
        arrowKey = getch();
        
        if(arrowKey == KEY_UP
		&& (peta[posisiKarakterY-1][posisiKarakterX] == 1
		||  peta[posisiKarakterY-1][posisiKarakterX] == 2
		||  peta[posisiKarakterY-1][posisiKarakterX] == 7)
		&& posisiKarakterY >= 0) {						
	// Gerakkan karakter ke atas
       		posisiKarakterY = posisiKarakterY-1;
        } else
        if(arrowKey == KEY_DOWN
		&& (peta[posisiKarakterY+1][posisiKarakterX] == 1			
		||  peta[posisiKarakterY+1][posisiKarakterX] == 2
		||  peta[posisiKarakterY+1][posisiKarakterX] == 7)
		&& posisiKarakterY < lebarPeta) {
            // Gerakkan karakter ke bawah
		posisiKarakterY = posisiKarakterY+1;
        } else
        if(arrowKey == KEY_LEFT 
		&& (peta[posisiKarakterY][posisiKarakterX-1] == 1
		||  peta[posisiKarakterY][posisiKarakterX-1] == 2
		||  peta[posisiKarakterY][posisiKarakterX-1] == 7) 
		&& posisiKarakterX >= 0) {
            // Gerakkan karakter ke kiri
         	posisiKarakterX = posisiKarakterX-1;
        } else
        if(arrowKey == KEY_RIGHT 
		&& (peta[posisiKarakterY][posisiKarakterX+1] == 1
		||  peta[posisiKarakterY][posisiKarakterX+1] == 2
		||  peta[posisiKarakterY][posisiKarakterX+1] == 7)
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
		// gerakan karakter
        for(int y = 0; y < lebarPeta; y++){
            for(int x = 0; x < panjangPeta; x++){
                if(posisiKarakterX == x && posisiKarakterY == y){
			cout << "0" << " ";
                } else {
              		cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
    }
    
    cout << "Exitted";
    return 0;
}
