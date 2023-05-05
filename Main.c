#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Kelompok 9
int main(int banyakArgumen, char *argumen[])
{
    if(banyakArgumen == 1){ //untuk melakukan registrasi
        printf("\n\n##\tSelamat bergabung di Game Quis.\t\t##\n");
        printf("Untuk menjawab kuis Anda harus melakukan registrasi terlebih dahulu.\n");
        printf("Silahkan melakukan registrasi!\n");
        struct data{
            char nama[50];
            char alamat[50];
            int umur;
            char username[20];
            char password[20];
        }reg;

        printf("\nNama : "); fgets(reg.nama, 50, stdin);
        printf("Alamat : "); fgets(reg.alamat, 50, stdin);
        printf("Umur : "); scanf("%d", &reg.umur);
        getchar();
        printf("Username: "); fgets(reg.username, 20, stdin);
        reg.username[strcspn(reg.username, "\n")] = '\0';
        printf("Password : "); fgets(reg.password, 20, stdin);
        reg.password[strcspn(reg.password, "\n")] = '\0';

        while (strchr(reg.username, ' ') != NULL || strchr(reg.password, ' ') != NULL)
        {
            printf("\nUsername atau password tidak boleh menggunakan spasi!\n");
            printf("Silahkan masukkan ulang!\n\n");
            printf("Username: "); fgets(reg.username, 20, stdin);
            reg.username[strcspn(reg.username, "\n")] = '\0';
            printf("Password : "); fgets(reg.password, 20, stdin);
            reg.password[strcspn(reg.password, "\n")] = '\0';
        }

        FILE *fpw = fopen("database/login.bin", "wb");
 
        char add[2] = "@";
        strcat(reg.username, add);
        strcat(reg.username, reg.password);

        fwrite(reg.username, sizeof(char), sizeof(reg.username)/sizeof(char), fpw);

        fclose(fpw);

        
        printf("\nSelamat, Anda berhasil melakukan registrasi!\n");
        printf("Silahkan login dengan cara berikut : ./FileAplikasiProgramUtama Username Password\n\n");
        
    }else if(banyakArgumen == 2 || banyakArgumen > 3){
        printf("Gagal login !");
        printf("\nSilahkan login dengan cara berikut : ./FileAplikasiProgramUtama Username Password\n");
        printf("Jika belum mempunyai akun silahkan lakukan registrasi dengan cara : ./FileAplikasiProgramUtama \n");

    }else if(banyakArgumen == 3){//untuk melakukan login

     char usernameinput[10],passwordinput[10];
    strcpy(usernameinput, argumen[1]);
    strcpy(passwordinput, argumen[2]);

    //membaca isi dalam file login
    FILE *fpr;
    if((fpr = fopen("database/login.bin", "rb")) == NULL){
        printf("gagal membuka file");
        return EXIT_FAILURE;
    }
    char akun[20];
    fread(akun,sizeof(char),sizeof(akun)/sizeof(char), fpr);

    fclose(fpr);

    char *string[3];
    char username[20], password[20];
    int ctrl = 0;

    string[0] = strtok(akun, "@");
    while(string[ctrl++] != NULL){
        string[ctrl] = strtok(NULL,"@");

    }
    strcpy(username, string[0]);
    strcpy(password, string[1]);

    if( (strcmp(usernameinput, username) == 0) &&(strcmp(passwordinput,password) == 0 )){
        printf("selamat anda berhasil login !");
    }
    else{
        printf("\nAnda gagal login!\n");
        printf("Username atau password anda salah!\n");
    }
    }


    //game
    char mulai[20], jawab1[20], jawab2[20], jawab3[20], jawab4[20], jawab5[20];
    int benar=0, salah=0, uang=0;
    printf("\n\nSELAMAT DATANG DI PERMAINAN \"ORANG KAYA!\"");
    printf("\nDalam permainan ini anda akan diberikan 5 pertanyaan dengan hadiah uang tunai \nyang akan terus bertambah setiap pertanyaannya");
    
    printf("\n\nTekan 1 untuk memulai permainan : ");
    gets(mulai);
     while(mulai[0]>'1' || mulai[0]<'0' || strlen(mulai)>1){
        printf("Tolong masukan pilihan yang tersedia (1), dan jangan menggunakan spasi!");        
        printf("\nTekan 1 untuk memulai permainan : ");
        gets(mulai);
        fflush(stdin);
    }

    if(mulai[0]=='1'){
        system("cls");
        printf("Bersiaplah menjadi ORANG KAYA!!!\n\n");
        for(int i=160000; i>2; i--){
                if(i/40000==0){
                    continue;
                }
                printf("\rGame akan di mulai dalam : %d", i/40000);
            }
        system("cls");
        //Soal no 1
        printf("Hadiah untuk soal ini = Rp500.000");
        printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
        printf("\n\n1. MinGW merupakan compiler yang biasa digunakan untuk bahasa pemrograman...?");
        printf("\n\tA. C\n");
        printf("\tB. Javascript\n");
        printf("\tC. Phyton\n");
        printf("Jawaban anda (A/B/C) : ");
        gets(jawab1);
        fflush(stdin); 
        while(jawab1[0]<'A' || jawab1[0]>'C' || strlen(jawab1)>1){
            printf("Tolong masukan pilihan yang tersedia (A/B/C), gunakan huruf kapital, dan jangan menggunakan spasi!");
            printf("\nJawaban anda (A/B/C) : ");
            gets(jawab1);
            fflush(stdin);
        }
        if(jawab1[0]== 'A'){
            printf("Selamat jawaban anda benar, bersiaplah menjawab soal selanjutnya\n\n");
            for(int i=160000; i>2; i--){
                if(i/40000==0){
                    continue;
                }
                printf("\r%d", i/40000);
            }
            uang+=500000;
            system("cls");
        }
        else{
            printf("\nJawaban anda salah, uang yang anda bawa pulang senilai Rp%d");
            printf("\nTerima kasih telah memainkan permainan ini, sampai jumpa dan jadilah ORANG KAYA!!!");
            uang+=0;
            exit(1);
        }

        //Soal 2
        printf("Hadiah untuk soal ini = Rp1.000.000");
        printf("\nUang yang telah anda kumpulkan = Rp%d", uang);
        printf("\n\n2. Tahun berapa bahasa C ditemukan?");
        printf("\n\tA. 1970\n");
        printf("\tB. 1972\n");
        printf("\tC. 1979\n");
        printf("Jawaban anda (A/B/C) : ");
        gets(jawab2);
        fflush(stdin); 
        while(jawab2[0]<'A' || jawab2[0]>'C' || strlen(jawab2)>1){
            printf("Tolong masukan pilihan yang tersedia (A/B/C), gunakan huruf kapital, dan jangan menggunakan spasi!");
            printf("\nJawaban anda (A/B/C) : ");
            gets(jawab2);
            fflush(stdin);
        }
        if(jawab2[0]== 'B'){
            printf("Selamat jawaban anda benar, bersiaplah menjawab soal selanjutnya\n\n");
            for(int i=160000; i>2; i--){
                if(i/40000==0){
                    continue;
                }
                printf("\r%d", i/40000);
            }
            uang+=1000000;
            system("cls");
        }
        else{
            printf("\nJawaban anda salah, uang yang anda bawa pulang senilai Rp%d");
            printf("\nTerima kasih telah memainkan permainan ini, sampai jumpa dan jadilah ORANG KAYA!!!");
            uang+=0;
            exit(1);
        }
    }

    
    return 0;

}