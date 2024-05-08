#include <iostream>
using namespace std;
class Hashing
{
private:
    int arr[10];

public:
    void initArr()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = -1;
        }
    }

    int hashcode(int num)
    {
        return (num % 10);
    }

    void insertionwithoutReplacement(int num)
    {
        int hash = hashcode(num);
        if (arr[hash] == -1)
        {
            arr[hash] = num;
        }
        else
        {
            while (arr[hash] != -1)
            {
                hash = (hash + 1) % 10;
            }
            arr[hash] = num;
        }
    }
    void insertWithReplacement(int num)
    {
        int hash = hashcode(num);
        if (arr[hash] == -1)
        {
            arr[hash] = num;
        }
        else
        {
            if (hash == hashcode(arr[hash]))
            {
                while (arr[hash] != -1)
                {
                    hash = (hash + 1) % 10;
                }
                arr[hash] = num;
            }
            else
            {
                int replace = arr[hash];
                arr[hash] = num;
                while (arr[hash] != -1)
                {
                    hash = (hash + 1) % 10;
                }
                arr[hash] = replace;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] != -1)
            {
                cout << i << ":" << arr[i] << endl;
            }
            else
            {
                cout << i << ":" << endl;
            }
        }
    }
    void Delete(int num)
    {
        int hash = hashcode(num);
        arr[hash]=-1;
        int duphash = (hash+1)%10;
        while(duphash!=hash)
        {
            if(hashcode(arr[duphash])==hash)
            {
                arr[hash] = arr[duphash];
                arr[duphash]= -1;
                break;
            }
            duphash = (duphash+1)%10;
        }
    }

} int main()
{
    Hashing obj;
    obj.initArr();
    obj.insertWithReplacement(3);
    obj.insertWithReplacement(33);
    obj.insertWithReplacement(4);
    obj.insertWithReplacement(6);
    obj.insertWithReplacement(43);

    return 0;
}