#include <iostream>
using namespace std;

int main(){
	int no;
	string nama;
	
	cout << "Mau berapa yang main: ";
	cin >> no;
	cout << "\n==============================";
	
	//for loop
	cout << "\nMasukkan nama-nama pemain: \n";
	for(int i = 1; i <= no; i++){
		//continue
		if (i == 13){
			continue;
		}
		cout << "Pemain ke-" << i << ": ";
		cin >> nama;
		//break
		if (i == 20){
			break;
		}	
	}
	
	cout << "==============================\n";
	cout << "\nNB:\n";
	cout << "*Mohon maaf kami membatasi pemain karena keterbatasan server, hehe\n";
	
	//while
	int j;	
	j = 1;
	while (j > 0){
		cout << "*Nomor-nomor ganjil cenderung berbuat ganjil, kami akan mengeliminasi mereka";
		cout << "\n\n==============================";
		j--;
	}	
	
	cout << "\n\nPermainan akan segera dimulai, mari berhitung mundur dari 3 sampai 1\n\n";
	
	//do-while
	j = 3;
	do{
		cout << "| " << j << " |";
		j--;
	} while (j > 0);
	
	cout << "\n\n==============================";
}
