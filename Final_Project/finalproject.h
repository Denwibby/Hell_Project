#ifndef finalproject_H_INCLUDED
#define finalproject_H_INCLUDED
#include <iostream>

using namespace std;
#define next(p) p->next
#define prev(p) p->prev
#define nama(p) p->nama
#define kapasitas(p) p->kapasitas
#define ptrDosen(p) p->ptrDosen
#define ptrMahasiswa(p) p->ptrMahasiswa
#define first(L) (L).first
#define last(L) (L).last
#define nil NULL

typedef struct mahasiswa *adrMahasiswa;
typedef struct dosen *adrDosen;
typedef struct relasi *adrRelasi;

struct mahasiswa{
	string nama;
	int kapasitas;
	adrMahasiswa next;
	adrMahasiswa prev;
};

struct dosen{
	string nama;
	int kapasitas;
	adrDosen next;
	adrDosen prev;
};

struct relasi{
	adrRelasi next;
	adrMahasiswa ptrMahasiswa;
	adrDosen ptrDosen;
};

struct ListMahasiswa{
	adrMahasiswa first;
	adrMahasiswa last;
};

struct ListDosen{
	adrDosen first;
	adrDosen last;
};

struct ListRelasi{
	adrRelasi first;
	adrRelasi last;
};

void createListMahasiswa(ListMahasiswa &M);
void createListDosen(ListDosen &D);
void createListRelasi(ListRelasi &R);
void addMahasiswa(ListMahasiswa &M,string nama);
void addDosen(ListDosen &D, string nama);
adrMahasiswa findMahasiswa(ListMahasiswa M, string nama);
void addRelasi(ListRelasi &R, ListMahasiswa &M, ListDosen &D, string namaDosen, string namaMahasiswa);
void findMahasiswaByDosen(ListDosen D, ListRelasi R, string namaDosen);
void deleteDosenAndRelasi(ListMahasiswa M, ListDosen &D, ListRelasi &R, string namaDosen, adrDosen &pD);
void deleteRelasi(ListMahasiswa M, ListDosen D, ListRelasi &R);
void printlist(ListRelasi R, ListMahasiswa M);
void maxBimbingan(ListDosen D);
void soloPembimbing(ListMahasiswa M);
int menu();

#endif // FINAL_H_INCLUDED

