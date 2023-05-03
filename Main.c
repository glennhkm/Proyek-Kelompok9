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

    }


    return 0;

}