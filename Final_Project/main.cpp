#include "finalproject.h"

int main()
{
    ListMahasiswa M;
	ListDosen D;
	ListRelasi R;
	string namaMahasiswa,namaDosen,a;
	adrDosen pD;
	int p = 999;
	int n;

	createListMahasiswa(M);
	createListDosen(D);
	createListRelasi(R);

	while(p!=0){
        p=menu();
        switch(p)
        {
        case 0:
            cout<<"Program terhenti"<<endl;
            break;
        case 1:
            cout<<"Masukkan jumlah data mahasiswa yang akan ditambahkan: ";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Masukkan nama mahasiswa: ";
                cin>>namaMahasiswa;
                addMahasiswa(M,namaMahasiswa);
            }
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
        case 2:
            cout<<"Masukkan jumlah data dosen yang akan ditambahkan: ";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Masukkan nama dosen: ";
                cin>>namaDosen;
                addDosen(D,namaDosen);
            }
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
        case 3:
            cout<<"Masukkan jumlah relasi yang akan ditambahkan: ";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Masukkan nama dosen: ";
                cin>>namaDosen;
                cout<<"Masukkan nama mahasiswa: ";
                cin>>namaMahasiswa;
                addRelasi(R,M,D,namaDosen,namaMahasiswa);
            }
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 4:
            cout<<"Masukkan nama dosen yang akan dicari bimbingannya: ";
            cin>>namaDosen;
            cout<<endl;
            findMahasiswaByDosen(D,R,namaDosen);
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 5:
            cout<<"Masukkan jumlah dosen yang ingin dihapus: ";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Masukkan nama dosen yang ingin dihapus: ";
                cin>>namaDosen;
                deleteDosenAndRelasi(M,D,R,namaDosen,pD);
            }
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 6:
            cout<<"Masukkan jumlah relasi yang ingin dihapus: ";
            cin>>n;
            for(int i=0;i<n;i++){
                deleteRelasi(M,D,R);
            }
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 7:
            printlist(R,M);
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 8:
            maxBimbingan(D);
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        case 9:
            soloPembimbing(M);
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        default:
            cout<<"Pilihan tidak tersedia"<<endl;
            cout<<"Kembali ke menu? (Y/N): ";
            cin>>a;
            if(a=="Y"||a=="y"){
                system("CLS");
                break;
            }
            else{
                return 0;
            }
            break;
        }
	}
}
