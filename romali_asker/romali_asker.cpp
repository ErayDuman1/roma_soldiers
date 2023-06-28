#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct dugum
{
    int veri;
    struct dugum* sonraki;
};
struct dugum* ilkdugum = NULL, * sondugum = NULL;

void yazdir(int n)
{
    struct dugum* temp = ilkdugum;
    int sayac = 1;
    for (int i = 0;i < n;i++)
    {
        sayac++;
        if (sayac == 3)
        {
            struct dugum* temp2 = temp;
            struct dugum* temp3 = temp->sonraki->sonraki;
            delete temp->sonraki;
            temp2->sonraki = temp3;
            cout << temp->veri << endl;
            sayac = 0;
        }
        temp = temp->sonraki;
    }
    
}
int main()
{
    int n;
    cout << "Asker sayisini giriniz:";
    cin >> n;

    for (int i = n;1 <= i;i--)
    {
        if (ilkdugum == NULL)
        {
            ilkdugum = (struct dugum*)malloc(sizeof(struct dugum));
            ilkdugum->veri = i;
            ilkdugum->sonraki = ilkdugum;
        }
        else
        {
            struct dugum *temp= (struct dugum*)malloc(sizeof(struct dugum));
            struct dugum* sondugum = ilkdugum;
            temp->veri = i;
            while (sondugum->sonraki != ilkdugum)
            {
                sondugum = sondugum->sonraki;
            }
            temp->sonraki = ilkdugum;
            sondugum->sonraki = temp;
            ilkdugum = temp;
        }
    }
    yazdir(n);
    system("pause");
    return 0;
}