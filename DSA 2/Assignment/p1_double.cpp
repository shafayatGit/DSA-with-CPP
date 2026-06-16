#include<iostream>
using namespace std;


struct student{
    int id=-1;
    string name;
    float CGPA;
};
struct student hashtable[1000]; /// 1000 is the capacity
int capacity=1000;
int tracker[1000];
// 0 means that index is empty
// 1 means that index is full
// -1 means that index was deleted

const int m = 11;
int table[m]; 
int collision=0;
/// linear probing
// int _hash(int key, int i)
// {
//     int a = 7, b = 6;
//     int index= (a*key+b+i)%m;
//     return index;
// }

/// Quadratic Probing
// int _hash(int key, int i)
// {
//     int a = 7, b = 6, c1 = 3, c2 = 5;
//     return (a*key + b + c1*i + c2*i*i) % m;
// }

// /// Double Hashing
int _hash(int key, int i)
{
    int q = 7;
    int h1 = key%m;

    // Second hash function
    int h2 = q - (key % q);

    return (h1 + i * h2) % m;
}



/// insert student s
void _insert(int key)
{
    int i=0;
    while(1)
    {
        int index=_hash(key, i);
        if(table[index]==-1)
        {
            table[index] = key;
            //tracker[index]=1;
            break;
        }
        else
        {
            i++;
            collision++;
        }

    }
}

/// find student for id=key
struct student _search(int key)
{
    int i=0;
    while(1)
    {
        int index=_hash(key, i);
        if(hashtable[index].id==key) // if the student matches
        {
            return hashtable[index]; // return the student
        }
        else if(tracker[index]==0)
        {
            // not found, return the default student
            struct student s;
            return s;
        }
        else
        {
            // need to jump
            i++;
        }
    }
}


///delete student with id=key
void _delete(int key)
{
    int i=0;
    while(1)
    {
        int index=_hash(key, i);
        if(hashtable[index].id==key) // if the student matches
        {
            tracker[index]=-1; // deleted

        }
        else if(tracker[index]==0)
        {
            // not found, return the default student
            return;
        }
        else
        {
            // need to jump
            i++;
        }
    }

}



int main()
{
    for (int i = 0; i < m; i++)
        table[i] = -1;
    int keys[] = {19, 34, 47, 62, 75, 88, 11};
    for (int i = 0; i < 7; i++)
        _insert(keys[i]);

    cout << "Total Collisions = " << collision << endl;

}