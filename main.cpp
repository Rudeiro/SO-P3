#include<pthread.h>
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
#include<ext/slist>
using namespace std;
using namespace __gnu_cxx;

slist<pair<int, int> > zarcie;
int dzien;
volatile int zwierz;
volatile int jedzenie;
volatile int dezerter;
volatile int dezerter2;
volatile int dezerter3;
volatile int warzywo;
volatile int zasadzone;
vector<pthread_mutex_t> mutexy;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex5 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex6 = PTHREAD_MUTEX_INITIALIZER;

void* polowanie(void* arg)
{
    int sl = rand()%6 + 1;
    int sz = rand()%6 + 1;
    if(sl > sz)
    {
        zwierz += 1;
    }




}
void* jedzenie_l(void* arg)
{
    int k = 0;
    if(zarcie.size() != 0)
    {
        slist<pair<int,int> >::iterator i = zarcie.begin();

        while(i != zarcie.end() && dzien - (*i).second != 2)
        {
            i++;
            k++;
        }
        if(i != zarcie.end())
        {
            while(i != zarcie.end())
            {
                if(pthread_mutex_trylock(&mutexy[k]) == false)
                {
                    i++;
                    k++;
                }
                else
                {
                    if((*i).first != 0)
                    {
                        (*i).first--;
                        pthread_mutex_unlock(&mutexy[k]);
                        break;
                    }
                    else
                    {
                        i++;
                        k++;
                        pthread_mutex_unlock(&mutexy[k]);
                    }
                }
            }
            if(i == zarcie.end())
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 1)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {
                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }
                    if(i == zarcie.end())
                    {
                        i = zarcie.begin();
                        k = 0;
                        while(i != zarcie.end() && dzien - (*i).second != 0)
                        {
                            i++;
                            k++;
                        }
                        if(i != zarcie.end())
                        {
                            while(i != zarcie.end())
                            {
                                if(pthread_mutex_trylock(&mutexy[k]) == false)
                                {
                                    i++;
                                    k++;
                                }
                                else
                                {
                                    if((*i).first != 0)
                                    {
                                        (*i).first--;
                                        pthread_mutex_unlock(&mutexy[k]);
                                        break;
                                    }
                                    else
                                    {
                                        i++;
                                        k++;
                                        pthread_mutex_unlock(&mutexy[k]);
                                    }
                                }
                            }
                            if(i == zarcie.end())
                            {
                                 dezerter++;

                            }
                        }
                        else
                        {

                            dezerter++;
                        }
                    }
                }
                else
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end())
                        {
                             dezerter++;

                        }
                    }
                    else
                    {
                        dezerter++;

                    }
                }
            }
        }
        else
        {
            i = zarcie.begin();
            k = 0;
            while(i != zarcie.end() && dzien - (*i).second != 1)
            {
                i++;
                k++;
            }
            if(i != zarcie.end())
            {
                while(i != zarcie.end())
                {
                    if(pthread_mutex_trylock(&mutexy[k]) == false)
                    {
                        i++;
                        k++;
                    }
                    else
                    {
                        if((*i).first != 0)
                        {
                            (*i).first--;
                            pthread_mutex_unlock(&mutexy[k]);
                            break;
                        }
                        else
                        {
                            i++;
                            k++;
                            pthread_mutex_unlock(&mutexy[k]);
                        }
                    }
                }
                if(i == zarcie.end())
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end())
                        {
                             dezerter++;

                        }
                    }
                    else
                    {
                        dezerter++;

                    }
                }
            }
            else
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 0)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {

                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }

                    if(i == zarcie.end()){
                        dezerter++;

                    }
                }
                else
                {
                    dezerter++;
                }
            }
        }
    }
    else
    {
       dezerter++;
    }
    //string p = to_string(k)+"\n";
    //cout << p;
}

void* pieczenie(void* arg)
{
    pthread_mutex_lock(&mutex2);
    if(zwierz != 0)
    {
        zwierz -= 1;
        int jedzonko = rand()%6 + 1;
        jedzenie += jedzonko;
    }
    pthread_mutex_unlock(&mutex2);
}
void* jedzenie_k(void* arg)
{
    if(zarcie.size() != 0)
    {
        slist<pair<int,int> >::iterator i = zarcie.begin();
        int k = 0;
        while(i != zarcie.end() && dzien - (*i).second != 2)
        {
            i++;
            k++;
        }
        if(i != zarcie.end())
        {
            while(i != zarcie.end())
            {
                if(pthread_mutex_trylock(&mutexy[k]) == false)
                {
                    i++;
                    k++;
                }
                else
                {
                    if((*i).first != 0)
                    {
                        (*i).first--;
                        pthread_mutex_unlock(&mutexy[k]);
                        break;
                    }
                    else
                    {
                        i++;
                        k++;
                        pthread_mutex_unlock(&mutexy[k]);
                    }
                }
            }
            if(i == zarcie.end())
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 1)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {
                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }
                    if(i == zarcie.end())
                    {
                        i = zarcie.begin();
                        k = 0;
                        while(i != zarcie.end() && dzien - (*i).second != 0)
                        {
                            i++;
                            k++;
                        }
                        if(i != zarcie.end())
                        {
                            while(i != zarcie.end())
                            {
                                if(pthread_mutex_trylock(&mutexy[k]) == false)
                                {
                                    i++;
                                    k++;
                                }
                                else
                                {
                                    if((*i).first != 0)
                                    {
                                        (*i).first--;
                                        pthread_mutex_unlock(&mutexy[k]);
                                        break;
                                    }
                                    else
                                    {
                                        i++;
                                        k++;
                                        pthread_mutex_unlock(&mutexy[k]);
                                    }
                                }
                            }
                            if(i == zarcie.end()) dezerter2++;
                        }
                        else
                        {
                            dezerter2++;
                        }
                    }
                }
                else
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end()) dezerter2++;
                    }
                    else
                    {
                        dezerter2++;
                    }
                }
            }
        }
        else
        {
            i = zarcie.begin();
            k = 0;
            while(i != zarcie.end() && dzien - (*i).second != 1)
            {
                i++;
                k++;
            }
            if(i != zarcie.end())
            {
                while(i != zarcie.end())
                {
                    if(pthread_mutex_trylock(&mutexy[k]) == false)
                    {
                        i++;
                        k++;
                    }
                    else
                    {
                        if((*i).first != 0)
                        {
                            (*i).first--;
                            pthread_mutex_unlock(&mutexy[k]);
                            break;
                        }
                        else
                        {
                            i++;
                            k++;
                            pthread_mutex_unlock(&mutexy[k]);
                        }
                    }
                }
                if(i == zarcie.end())
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end()) dezerter2++;
                    }
                    else
                    {
                        dezerter2++;
                    }
                }
            }
            else
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 0)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {
                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }
                    if(i == zarcie.end())
                    {

                         dezerter2++;
                    }
                }
                else
                {
                    dezerter2++;
                }
            }
        }
    }
    else
    {
        dezerter2++;
    }
}
void* jedzenie_o(void* arg)
{
    if(zarcie.size() != 0)
    {
        slist<pair<int,int> >::iterator i = zarcie.begin();
        int k = 0;
        while(i != zarcie.end() && dzien - (*i).second != 2)
        {
            i++;
            k++;
        }
        if(i != zarcie.end())
        {
            while(i != zarcie.end())
            {
                if(pthread_mutex_trylock(&mutexy[k]) == false)
                {
                    i++;
                    k++;
                }
                else
                {
                    if((*i).first != 0)
                    {
                        (*i).first--;
                        pthread_mutex_unlock(&mutexy[k]);
                        break;
                    }
                    else
                    {
                        i++;
                        k++;
                        pthread_mutex_unlock(&mutexy[k]);
                    }
                }
            }
            if(i == zarcie.end())
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 1)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {
                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }
                    if(i == zarcie.end())
                    {
                        i = zarcie.begin();
                        k = 0;
                        while(i != zarcie.end() && dzien - (*i).second != 0)
                        {
                            i++;
                            k++;
                        }
                        if(i != zarcie.end())
                        {
                            while(i != zarcie.end())
                            {
                                if(pthread_mutex_trylock(&mutexy[k]) == false)
                                {
                                    i++;
                                    k++;
                                }
                                else
                                {
                                    if((*i).first != 0)
                                    {
                                        (*i).first--;
                                        pthread_mutex_unlock(&mutexy[k]);
                                        break;
                                    }
                                    else
                                    {
                                        i++;
                                        k++;
                                        pthread_mutex_unlock(&mutexy[k]);
                                    }
                                }
                            }
                            if(i == zarcie.end()) dezerter3++;
                        }
                        else
                        {
                            dezerter3++;
                        }
                    }
                }
                else
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end()) dezerter3++;
                    }
                    else
                    {
                        dezerter3++;
                    }
                }
            }
        }
        else
        {
            i = zarcie.begin();
            k = 0;
            while(i != zarcie.end() && dzien - (*i).second != 1)
            {
                i++;
                k++;
            }
            if(i != zarcie.end())
            {
                while(i != zarcie.end())
                {
                    if(pthread_mutex_trylock(&mutexy[k]) == false)
                    {
                        i++;
                        k++;
                    }
                    else
                    {
                        if((*i).first != 0)
                        {
                            (*i).first--;
                            pthread_mutex_unlock(&mutexy[k]);
                            break;
                        }
                        else
                        {
                            i++;
                            k++;
                            pthread_mutex_unlock(&mutexy[k]);
                        }
                    }
                }
                if(i == zarcie.end())
                {
                    i = zarcie.begin();
                    k = 0;
                    while(i != zarcie.end() && dzien - (*i).second != 0)
                    {
                        i++;
                        k++;
                    }
                    if(i != zarcie.end())
                    {
                        while(i != zarcie.end())
                        {
                            if(pthread_mutex_trylock(&mutexy[k]) == false)
                            {
                                i++;
                                k++;
                            }
                            else
                            {
                                if((*i).first != 0)
                                {
                                    (*i).first--;
                                    pthread_mutex_unlock(&mutexy[k]);
                                    break;
                                }
                                else
                                {
                                    i++;
                                    k++;
                                    pthread_mutex_unlock(&mutexy[k]);
                                }
                            }
                        }
                        if(i == zarcie.end()) dezerter3++;
                    }
                    else
                    {
                        dezerter3++;
                    }
                }
            }
            else
            {
                i = zarcie.begin();
                k = 0;
                while(i != zarcie.end() && dzien - (*i).second != 0)
                {
                    i++;
                    k++;
                }
                if(i != zarcie.end())
                {
                    while(i != zarcie.end())
                    {
                        if(pthread_mutex_trylock(&mutexy[k]) == false)
                        {
                            i++;
                            k++;
                        }
                        else
                        {
                            if((*i).first != 0)
                            {
                                (*i).first--;
                                pthread_mutex_unlock(&mutexy[k]);
                                break;
                            }
                            else
                            {
                                i++;
                                k++;
                                pthread_mutex_unlock(&mutexy[k]);
                            }
                        }
                    }
                    if(i == zarcie.end()) dezerter3++;
                }
                else
                {
                    dezerter3++;
                }
            }
        }
    }
    else
    {
        dezerter3++;
    }
}
void* sadzenie(void* arg)
{
    pthread_mutex_lock(&mutex4);
    if(warzywo != 0)
    {
        warzywo--;
        zasadzone++;
    }
    pthread_mutex_unlock(&mutex4);
}

void* zbieranie(void* arg)
{
     pthread_mutex_lock(&mutex5);
     if(zasadzone != 0)
     {
         zasadzone--;
         warzywo += rand()%5 + 1;
     }
     pthread_mutex_unlock(&mutex5);

}
void* gotowanie(void* arg)
{
    pthread_mutex_lock(&mutex6);
    if(warzywo != 0 && zwierz != 0)
    {
        warzywo--;
        zwierz--;
        jedzenie += rand()%10 + 1;
    }
    pthread_mutex_unlock(&mutex6);
}
int main(int argc, char* argv[])
{
    srand(time(NULL));
    pthread_t lowca, kucharz, ogrodnik;
    vector<pthread_t> lowcy;
    vector<pthread_t> kucharze;
    vector<pthread_t> ogrodnicy;
    dzien = 1;
    for(int i = 0; i < atoi(argv[1]); i++) lowcy.push_back(lowca);
    for(int i = 0; i < atoi(argv[2]); i++) kucharze.push_back(kucharz);
    for(int i = 0; i < atoi(argv[5]); i++) ogrodnicy.push_back(ogrodnik);
    zwierz = atoi(argv[3]);
    warzywo = atoi(argv[6]);
    int l = atoi(argv[1]);
    jedzenie = atoi(argv[4]);
    for(int i = 0; i < atoi(argv[4]); i++)
    {
        zarcie.push_front(make_pair(1, 1));
        mutexy.push_back(PTHREAD_MUTEX_INITIALIZER);
    }



    cout << "Lowcy " << " Kucharze " << " Zwierzeta " << " Jedzenie " << "Warzywa " << "Ogrodnicy "<< "\n";
    for(int i = 0; i < 10; i++)
    {
        jedzenie = 0;

        int k = l - dezerter; // k - liczba lowcow
        int c = atoi(argv[2]) - dezerter2; // c - liczba kucharzy
        int ogr = atoi(argv[5]) - dezerter3; // ogr - liczba ogrodnikow

        for(int j = 0; j < ogr; j++) pthread_create(&ogrodnicy[j], NULL, zbieranie, NULL);
        for(int j = 0; j < ogr; j++) pthread_join(ogrodnicy[j], NULL);
        for(int j = 0; j < ogr; j++) pthread_create(&ogrodnicy[j], NULL, sadzenie, NULL);

        for(int j = 0; j < k; j++) pthread_create(&lowcy[j], NULL, polowanie, NULL);
        for(int j = 0; j < c; j++) pthread_create(&kucharze[j], NULL, pieczenie, NULL);

        for(int j = 0; j < c; j++) pthread_join(kucharze[j], NULL);
        for(int j = 0; j < k; j++) pthread_join(lowcy[j], NULL);

        for(int m = 0; m < jedzenie; m++)
        {
            zarcie.push_front(make_pair(1, dzien));
            if(zarcie.size() > mutexy.size()) mutexy.push_back(PTHREAD_MUTEX_INITIALIZER);
        }
        for(int j = 0; j < c; j++) pthread_create(&kucharze[j], NULL, jedzenie_k, NULL);
        for(int j = 0; j < k; j++) pthread_create(&lowcy[j], NULL, jedzenie_l, NULL);

        for(int j = 0; j < ogr; j++) pthread_create(&ogrodnicy[j], NULL, jedzenie_o, NULL);

        for(int j = 0; j < c; j++) pthread_join(kucharze[j], NULL);
        for(int j = 0; j < k; j++) pthread_join(lowcy[j], NULL);
        for(int j = 0; j < ogr; j++) pthread_join(ogrodnicy[j], NULL);

        cout << l - dezerter;
        for(int i = 0; i < 10 - (to_string(l-dezerter)).size(); i++) cout << " ";
        cout << atoi(argv[2]) - dezerter2;
        for(int i = 0; i < 10 - (to_string(atoi(argv[2]) - dezerter2)).size(); i++) cout << " ";
        cout << zwierz;
        for(int i = 0; i < 10 - (to_string(zwierz)).size(); i++) cout << " ";
        cout << jedzenie;
        for(int i = 0; i < 10 - (to_string(jedzenie)).size(); i++) cout << " ";
        cout << warzywo;
        for(int i = 0; i < 10 - (to_string(warzywo)).size(); i++) cout << " ";
        cout << atoi(argv[5]) - dezerter3;
        cout << "\n";
        if(zarcie.size() != 0)
        {
            slist<pair<int,int> >::iterator p = zarcie.begin();
            slist<pair<int,int> >::iterator prev = p;
            p++;
            while(p != zarcie.end())
            {
                if(p != zarcie.end() && (*p).first == 0)
                {
                    p = zarcie.erase_after(prev);

                }
                else
                {
                    prev++;
                    p++;
                }

            }
            if((*zarcie.begin()).first == 0) zarcie.pop_front();

        }
    }
    //for(slist<pair<int,int> >::iterator i = zarcie.begin(); i != zarcie.end(); i++) cout << (*i).first << " " << (*i).second << "\n";
    return 0;
}
