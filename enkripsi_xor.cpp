// Enkripsi sembarang berkas dengan algoritma RC4.
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

main(int argc, char *argv[])
{
FILE *Fin, *Fout;
char p, c, u;
string K;
int S[256];
int i, j, t, count;
Fin = fopen(argv[1], "rb");
if (Fin == NULL) {
	cout << "Berkas " << argv[1] <<" tidak ada" << endl;
	exit(0);
}

Fout = fopen(argv[2], "wb");
cout << "Kata kunci : "; cin >> K;
cout <<"Enkripsi " << argv[1] << " menjadi " << argv[2] << "...";
for (i = 0; i<256; i++) {
	S[i] = i;
}

j = 0;
for (i = 0; i<256; i++) {
	j = (j + S[i] + K[i % K.length()]) % 256;
	swap(S[i], S[j]); // Pertukarkan nilai S[i] dan S[j]
}

i = 0; j = 0;
count = 0;
while (!feof(Fin)) {
	p = fgetc(Fin);
	count = count + 1; i = (i + 1) % 256;
	j = (j + S[i]) % 256;
	swap(S[i], S[j]); // Pertukarkan nilai S[i] dan S[j]
	t = (S[i] + S[j]) % 256;
	u = S[t]; // keystream
	c = u ^ p;
	fputc(c, Fout);
}
cout << "Count = "<< count;
fclose(Fin); fclose(Fout);
} 
