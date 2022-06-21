#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main(){
    // Game pokemon
    /*
    1. Jalan        :   - arrow key pindah posisi
    2. Rumput pendek:   - arrow key pindah posisi
    3. Semak belukar:   - arrow key pindah posisi
                        - akan muncul pokemon secara random (random 0.0 - 1.0, < 0.3)
    4. Pohon        :   - arrow key tidak bisa pindah ke area ini
    5. Batu         :   - arrow key tidak bisa pindah ke area ini
    6. Genangan air :   - arrow key pindah posisi
    7. Perairan     :   - arrow key pindah posisi (asal perahu = true) 
                        - akan muncul pokemon tipe water / flying Ukuran environment (random 0.0 - 1.0, < 0.3)
    */
    
    int panjangPeta = 20;	// x
    int lebarPeta = 16;		// y
    
    int posisiKarakterY = 15;
    int posisiKarakterX = 0;
    
    cout << "Karakter ada di y:" << posisiKarakterY << ", x:" << posisiKarakterX << "\n";
    
    int peta[lebarPeta][panjangPeta] = {
        {7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1},
        {7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1},
        {7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 7, 7, 7, 7, 7, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1},
        {1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1},
        {1, 1, 1, 4, 4, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5},
        {1, 1, 4, 4, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1},
        {1, 1, 4, 4, 1, 1, 1, 1, 3, 3, 3, 1, 1, 3, 3, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    
    int arrowKey = 0;
    
    while(1) {
        // Input Keyboard
        cout << "Masukan arrow key ";
        cin >> arrowKey;
        cout << "Arrow key yang dimasukan " << arrowKey << "\n";
        
        // Aturan menggerakkan karakter ke atas
        if(arrowKey == 72 && (peta[posisiKarakterY-1][posisiKarakterX] == 1
			||  peta[posisiKarakterY-1][posisiKarakterX] == 2
			||  peta[posisiKarakterY-1][posisiKarakterX] == 3
			||  peta[posisiKarakterY-1][posisiKarakterX] == 6)
			&& posisiKarakterY >= 0) {
			// Gerakkan karakter ke atas
            posisiKarakterY = posisiKarakterY-1;
        }
        
        // Aturan menggerakkan karakter ke bawah
        if(arrowKey == 80									//Ke bawah kalau input angka 80
			&& (peta[posisiKarakterY+1][posisiKarakterX] == 1			
			||  peta[posisiKarakterY+1][posisiKarakterX] == 2
			||  peta[posisiKarakterY+1][posisiKarakterX] == 3
			||  peta[posisiKarakterY+1][posisiKarakterX] == 6)
			&& posisiKarakterY < lebarPeta) {					//Border peta bagian bawah
            // Gerakkan karakter ke atas
			posisiKarakterY = posisiKarakterY+1;
        }
        
        // Aturan menggerakkan karakter ke kiri
        if(arrowKey == 75 
			&& (peta[posisiKarakterY][posisiKarakterX-1] == 1
			||  peta[posisiKarakterY][posisiKarakterX-1] == 2
			||  peta[posisiKarakterY][posisiKarakterX-1] == 3
			||  peta[posisiKarakterY][posisiKarakterX-1] == 6) 
			&& posisiKarakterX >= 0) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX-1;
        }
        
        // Aturan menggerakkan karakter ke kanan
        if(arrowKey == 77 
			&& (peta[posisiKarakterY][posisiKarakterX+1] == 1
			||  peta[posisiKarakterY][posisiKarakterX+1] == 2
			||  peta[posisiKarakterY][posisiKarakterX+1] == 3
			||  peta[posisiKarakterY][posisiKarakterX+1] == 6)
			&& posisiKarakterX < panjangPeta) {
            // Gerakkan karakter ke atas
            posisiKarakterX = posisiKarakterX+1;
        }
        
        // Border Peta
        for(int y=0; y<lebarPeta; y++) {
            for(int x=0; x<panjangPeta; x++) {
                if(posisiKarakterX == x && posisiKarakterY == y) {
                    cout << 0 << " ";
                } else {
                    cout << peta[y][x] << " ";
                }
            }
            cout << "\n";
        }
    }
    
    return 0;
}
