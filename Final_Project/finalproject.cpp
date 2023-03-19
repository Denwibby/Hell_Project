#include "finalproject.h"

void createListRelasi(ListRelasi &R){
	first(R) = nil;
	last(R) = nil;
}

void createListMahasiswa(ListMahasiswa &M){
	first(M) = nil;
	last(M) = nil;
}

void createListDosen(ListDosen &D){
	first(D) = nil;
	last(D) = nil;
}

void addMahasiswa(ListMahasiswa &M, string nama){
	adrMahasiswa pM = new mahasiswa;
	nama(pM) = nama;
	kapasitas(pM) = 0;
	next(pM) = nil;
	prev(pM) = nil;
	if(first(M)==nil){
		first(M) = pM;
		last(M) = pM;
	}
	else if (next(first(M))==nil){
		first(M) = pM;
		next(pM) = last(M);
		prev(last(M)) = first(M);
	}
	else {
		next(pM) = first(M);
		prev(first(M)) = pM;
		first(M) = pM;
	}
}

//Buat prosedur untuk menambahkan dosen
void addDosen(ListDosen &D, string nama){
	adrDosen pD = new dosen;	//Membuat kotak dosen baru dan ditunjuk oleh pD
	nama(pD) = nama;
	kapasitas(pD) = 0;	//nama dosen baru dimasukkan ke kotak
	next(pD) = nil;		//"next" dari kotak dosen di nil kan
	prev(pD) = nil;		//"next" dari kotak dosen di nil kan
	if(first(D)==nil){	//jika list kosong
		first(D) = pD;
		last(D) = pD;
	}
	else if (next(first(D))==nil){ //jika list ada 1 kotak
		first(D) = pD;
		next(pD) = last(D);
		prev(last(D)) = first(D);
	}
	else {	//jika list berisi 2 kotak atau lebih
		next(pD) = first(D);
		prev(first(D)) = pD;
		first(D) = pD;
	}
}

adrMahasiswa findMahasiswa(ListMahasiswa M, string nama){
	adrMahasiswa pM = first(M);
	if (first(M)==nil){
		cout<<"kosong kak"<<endl;
	}
	else{
		while(pM!=nil&&nama(pM)!=nama){
			pM=next(pM);
		}
	}
	return pM;
}

adrDosen findDosen(ListDosen D, string nama){
	adrDosen pD = first(D);
	if (first(D)==nil){
		cout<<"kosong kak"<<endl;
	}
	else{
		while(pD!=nil&&nama(pD)!=nama){
			pD=next(pD);
		}
	}
	return pD;
}

void addRelasi(ListRelasi &R, ListMahasiswa &M, ListDosen &D, string namaDosen, string namaMahasiswa){
	adrMahasiswa pM = findMahasiswa(M,namaMahasiswa);
	adrDosen pD = findDosen(D,namaDosen);
	if (pM!=nil&&pD!=nil){
        if(kapasitas(pM)<2&&kapasitas(pD)<8){
            adrRelasi pR = new relasi;
            next(pR) = nil;
            ptrDosen(pR) = pD;
            ptrMahasiswa(pR) = pM;
            if (first(R)==nil){
                first(R) = pR;
                last(R) = pR;
            }
            else{
                next(pR) = first(R);
                first(R) = pR;
            }
            kapasitas(pM)++;
            kapasitas(pD)++;
        }
        else{
            cout<<"Penuh!"<<endl;
        }
	}
	else {
		cout<<"ga ketemu nich"<<endl;
	}
}

void findMahasiswaByDosen(ListDosen D, ListRelasi R, string namaDosen)
{
    if(first(D)==nil){
        cout<<"Data dosen kosong!"<<endl;
        return;
    }
    adrDosen pD = findDosen(D,namaDosen);
    adrRelasi pR = first(R);
    cout<<"Mahasiswa yang dibimbing oleh dosen "<<nama(pD)<<" adalah:"<<endl;
    while(pR!=nil){
        if(ptrDosen(pR)==pD){
            cout<<"- "<<nama(ptrMahasiswa(pR))<<endl;
        }
        pR=next(pR);
    }
}

void deleteDosenAndRelasi(ListMahasiswa M, ListDosen &D, ListRelasi &R, string namaDosen, adrDosen &pD)
{
    if(first(M)==nil){
        cout<<"Data mahasiswa kosong!"<<endl;
        return;
    }
    if(first(D)==nil){
        cout<<"Data dosen kosong!"<<endl;
        return;
    }
    adrRelasi pR;
    pD = findDosen(D,namaDosen);
    if(pD!=nil){
        pR=first(R);
        if(pR!=nil){
            while(pR!=nil){
                if(ptrDosen(pR)==pD){
                    if(pR==first(R)){
                        if(first(R)==pR&&last(R)==pR){
                            first(R) = nil;
                            last(R) = nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                        else{
                            first(R) = next(pR);
                            next(pR) = nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                    }
                    else if(pR==last(R)){
                        if(first(R)==pR&&last(R)==pR){
                            first(R) = nil;
                            last(R) = nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                        else{
                            adrRelasi temp = first(R);
                            while(temp!=nil&&next(temp)!=pR){
                                temp=next(temp);
                            }
                            last(R)=temp;
                            next(temp)=nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                    }

                    else{
                        if(first(R)==pR&&last(R)==pR){
                            first(R) = nil;
                            last(R) = nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                        else{
                            adrRelasi temp = first(R);
                            while(temp!=nil&&next(temp)!=pR){
                                temp=next(temp);
                            }
                            next(temp)=next(pR);
                            next(pR)=nil;
                            kapasitas(ptrMahasiswa(pR))--;
                            ptrMahasiswa(pR)=nil;
                            ptrDosen(pR)=nil;
                        }
                    }
                    pR=first(R);
                }
                if(ptrDosen(pR)==pD){
                    cout<<"m"<<endl;
                    if(next(pR)==nil){
                        cout<<"m"<<endl;
                        first(R) = nil;
                        last(R) = nil;
                        kapasitas(ptrMahasiswa(pR))--;
                        ptrMahasiswa(pR)=nil;
                        ptrDosen(pR)=nil;
                    }
                }
                pR=next(pR);
            }
        }
        if (pD==first(D)){
            if(next(first(D))==nil){
                first(D)=nil;
                last(D)=nil;
            }
            else{
                first(D)=next(pD);
                next(pD) = nil;
                prev(first(D))=nil;
            }
        }
        else if(pD==last(D)){
            if(next(first(D))==nil){
                first(D)=nil;
                last(D)=nil;
            }
            else{
                last(D)=prev(pD);
                prev(pD) = nil;
                next(last(D))=nil;
            }
        }
        else{
            if(next(first(D))==nil){
                first(D)=nil;
                last(D)=nil;
            }
            else{
                next(prev(pD)) = next(pD);
                prev(next(pD)) = prev(pD);
                next(pD) = nil;
                prev(pD) = nil;
            }
        }
    }
    else{
        cout<<"Data tidak ditemukan"<<endl;
    }
}

void deleteRelasi(ListMahasiswa M, ListDosen D, ListRelasi &R)
{
    if(first(M)==nil){
        cout<<"Data mahasiswa kosong!"<<endl;
        return;
    }
    if(first(D)==nil){
        cout<<"Data dosen kosong!"<<endl;
        return;
    }
    adrDosen pD;
    adrMahasiswa pM;
    string namaMahasiswa;
    string namaDosen;
    cout<<"Masukkan nama mahasiswa: ";
    cin>>namaMahasiswa;
    pM=findMahasiswa(M,namaMahasiswa);
    if(pM==nil){
        cout<<"Mahasiswa tidak ditemukan"<<endl;
        return;
    }
    cout<<"Masukkan nama dosen: ";
    cin>>namaDosen;
    pD=findDosen(D,namaDosen);
    if(pD!=nil){
        adrRelasi pR = first(R);
        while(pR!=nil&&(ptrMahasiswa(pR)!=pM||ptrDosen(pR)!=pD)){
            pR=next(pR);
        }
        if(pR!=nil){
            if (pR == first(R))
            {
                if(next(first(R))==nil){


                    first(R) = nil;
                    last(R) = nil;
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
                else{
                    first(R)=next(pR);
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
            }
            else if (pR == last(R))
            {
                if(next(first(R))==nil){
                    first(R) = nil;
                    last(R) = nil;
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
                else{
                    adrRelasi temp=first(R);
                    while(temp!=nil&&next(temp)!=pR){
                        temp=next(temp);
                    }
                    last(R) = temp;
                    next(temp)=nil;
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
            }
            else
            {
                 if(next(first(R))==nil){
                    first(R) = nil;
                    last(R) = nil;
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
                else{
                    adrRelasi temp=first(R);
                    while(temp!=nil&&next(temp)!=pR){
                        temp=next(temp);
                    }
                    next(temp)=next(pR);
                    kapasitas(pM) -= 1;
                    kapasitas(pD) -= 1;
                    ptrMahasiswa(pR)=nil;
                    ptrDosen(pR)=nil;
                    delete pR;
                }
            }
        }
    }
    else{
        cout<<"Dosen tidak ketemu!"<<endl;
    }
}

void printlist(ListRelasi R, ListMahasiswa M)
{
    adrMahasiswa pM = first(M);
    adrRelasi pR;
    while(pM!=nil){
        pR=first(R);
        cout<<"Mahasiswa: "<<nama(pM)<<" (kapasitas: "<<kapasitas(pM)<<")"<<endl;
        cout<<"Dosen Pembimbing: ";
        while(pR!=nil){
            if(ptrMahasiswa(pR)==pM){
                cout<<nama(ptrDosen(pR))<<" ";
            }
            pR=next(pR);
        }
        cout<<endl;
        pM = next(pM);
    }
}
void maxBimbingan(ListDosen D)
{
    int temp = 0;
    string terbanyak;
    adrDosen pD = first(D);
    while(pD!=nil){
        if(kapasitas(pD)>temp){
            temp=kapasitas(pD);
            terbanyak=nama(pD);
        }
        pD=next(pD);
    }
    cout<<"Dosen dengan bimbingan terbanyak adalah dosen "<<terbanyak<<" dengan jumlah mahasiswa sebanyak "<<temp<<endl;
}
void soloPembimbing(ListMahasiswa M)
{
    adrMahasiswa pM = first(M);
    cout<<"Mahasiswa yang dibimbing oleh 1 dosen adalah: "<<endl;
    while(pM!=nil){
        if(kapasitas(pM)==1){
            cout<<"- "<<nama(pM)<<endl;
        }
        pM=next(pM);
    }
}

int menu()
{
    int n;
    cout<<"1. Menambahkan data mahasiswa"<<endl;
    cout<<"2. Menambahkan data dosen pembimbing"<<endl;
    cout<<"3. Menambahkan relasi"<<endl;
    cout<<"4. Mencari data mahasiswa yang dibimbing oleh dosen tertentu"<<endl;
    cout<<"5. Menghapus dosen beserta relasinya"<<endl;
    cout<<"6. Menghapus data dosen yang membimbing mahasiswa tertentu"<<endl;
    cout<<"7. Menampilkan seluruh data"<<endl;
    cout<<"8. Menampilkan data dosen dengan jumlah bimbingan terbanyak"<<endl;
    cout<<"9. Menampilkan data mahasiswa yang memiliki pembimbing tunggal"<<endl;
    cout<<"0. Keluar"<<endl;
    cout<<"Pilihan: ";
    cin>>n;
    cout<<endl;
    return n;
}
